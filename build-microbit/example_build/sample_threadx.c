/* This is a small demo of the high-performance ThreadX kernel.  It includes examples of eight
   threads of different priorities, using a message queue, semaphore, mutex, event flags group, 
   byte pool, and block pool.  */

#include "tx_api.h"
#include <nrfx.h>
#include <nrfx_rtc.h>
#include <nrfx_clock.h>
#include <nrfx_gpiote.h>
#include <nrf_gpio.h>
#include <system_nrf51.h>

extern void getledchar(char c, uint32_t * led1, uint32_t * led2, uint32_t * led3);
extern void make_animation(char c, uint32_t n, uint32_t dir, uint32_t * led1, uint32_t * led2, uint32_t * led3);

#define DEMO_STACK_SIZE         1024
#define DEMO_BYTE_POOL_SIZE     12000
#define DEMO_BLOCK_POOL_SIZE    100
#define DEMO_QUEUE_SIZE         100


UCHAR   memory_area[DEMO_BYTE_POOL_SIZE];


/* Define the ThreadX object control blocks...  */

TX_THREAD               thread_0;
TX_THREAD               thread_5;
TX_QUEUE                queue_0;
TX_SEMAPHORE            semaphore_0;
TX_MUTEX                mutex_0;
TX_EVENT_FLAGS_GROUP    event_flags_0;
TX_BYTE_POOL            byte_pool_0;
TX_BLOCK_POOL           block_pool_0;


/* Define the counters used in the demo application...  */

ULONG                   thread_0_counter;
ULONG                   thread_5_counter;

/* Define thread prototypes.  */

void    thread_0_entry(ULONG thread_input);
void    thread_5_entry(ULONG thread_input);

extern void SysTick_Handler(void);

const nrfx_rtc_t m_rtc = NRFX_RTC_INSTANCE(0);
static void rtc_handler(nrfx_rtc_int_type_t int_type)
{
    if(int_type == NRFX_RTC_INT_TICK)
        SysTick_Handler();
}

void clock_handler(nrfx_clock_evt_type_t event){}

typedef enum {
    SCROLL_H = 0,
    SCROLL_V,
} led_scroll_t;
static led_scroll_t dir;

void in_pinA_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    dir = SCROLL_H;
    tx_queue_send(&queue_0, &dir, TX_NO_WAIT);
}
void in_pinB_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    dir = SCROLL_V;
    tx_queue_send(&queue_0, &dir, TX_NO_WAIT);
}
int main()
{
    SystemInit();

    nrfx_clock_init(clock_handler);
    nrfx_clock_start(NRF_CLOCK_DOMAIN_LFCLK);
    nrfx_rtc_config_t config = NRFX_RTC_DEFAULT_CONFIG;
    nrfx_rtc_init(&m_rtc, &config, rtc_handler);
    nrfx_rtc_tick_enable(&m_rtc, true);
    nrfx_rtc_enable(&m_rtc);

    nrfx_err_t ret = NRFX_SUCCESS;
    ret = nrfx_gpiote_init(NRFX_GPIOTE_DEFAULT_CONFIG_IRQ_PRIORITY);
    if(ret != NRFX_SUCCESS) {
        while(1);
    }
    nrfx_gpiote_in_config_t in_config = NRFX_GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
    in_config.pull = NRF_GPIO_PIN_PULLUP;
#define BUTTON_A 17
#define BUTTON_B 26
    nrf_gpio_pin_dir_set(BUTTON_A, NRF_GPIO_PIN_DIR_INPUT);
    nrf_gpio_pin_dir_set(BUTTON_B, NRF_GPIO_PIN_DIR_INPUT);
    ret = nrfx_gpiote_in_init(BUTTON_A, &in_config, in_pinA_handler);
    ret = nrfx_gpiote_in_init(BUTTON_B, &in_config, in_pinB_handler);
    if(ret != NRFX_SUCCESS) {
        while(1);
    }
    nrfx_gpiote_in_event_enable(BUTTON_A, true);
    nrfx_gpiote_in_event_enable(BUTTON_B, true);

    /* Enter the ThreadX kernel.  */
    tx_kernel_enter();
}


/* Define what the initial system looks like.  */

void    tx_application_define(void *first_unused_memory)
{

CHAR    *pointer = TX_NULL;


    /* Create a byte memory pool from which to allocate the thread stacks.  */
    tx_byte_pool_create(&byte_pool_0, "byte pool 0", &memory_area[0], DEMO_BYTE_POOL_SIZE);

    /* Put system definition stuff in here, e.g. thread creates and other assorted
       create information.  */

    /* Allocate the stack for thread 0.  */
    tx_byte_allocate(&byte_pool_0, (VOID **) &pointer, DEMO_STACK_SIZE, TX_NO_WAIT);

    /* Create the main thread.  */
    tx_thread_create(&thread_0, "thread 0", thread_0_entry, 0,  
            pointer, DEMO_STACK_SIZE, 
            1, 1, TX_NO_TIME_SLICE, TX_AUTO_START);

    /* Allocate the stack for thread 5.  */
    tx_byte_allocate(&byte_pool_0, (VOID **) &pointer, DEMO_STACK_SIZE, TX_NO_WAIT);

    /* Create thread 5.  This thread simply pends on an event flag which will be set
       by thread_0.  */
    tx_thread_create(&thread_5, "thread 5", thread_5_entry, 5,  
            pointer, DEMO_STACK_SIZE, 
            4, 4, TX_NO_TIME_SLICE, TX_AUTO_START);

    /* Allocate the message queue.  */
    tx_byte_allocate(&byte_pool_0, (VOID **) &pointer, DEMO_QUEUE_SIZE*sizeof(ULONG), TX_NO_WAIT);

    /* Create the message queue shared by threads 1 and 2.  */
    tx_queue_create(&queue_0, "queue 0", TX_1_ULONG, pointer, DEMO_QUEUE_SIZE*sizeof(ULONG));

    /* Create the semaphore used by threads 3 and 4.  */
    tx_semaphore_create(&semaphore_0, "semaphore 0", 1);

    /* Create the event flags group used by threads 1 and 5.  */
    tx_event_flags_create(&event_flags_0, "event flags 0");

    /* Create the mutex used by thread 6 and 7 without priority inheritance.  */
    tx_mutex_create(&mutex_0, "mutex 0", TX_NO_INHERIT);

    /* Allocate the memory for a small block pool.  */
    tx_byte_allocate(&byte_pool_0, (VOID **) &pointer, DEMO_BLOCK_POOL_SIZE, TX_NO_WAIT);

    /* Create a block memory pool to allocate a message buffer from.  */
    tx_block_pool_create(&block_pool_0, "block pool 0", sizeof(ULONG), pointer, DEMO_BLOCK_POOL_SIZE);

    /* Allocate a block and release the block memory.  */
    tx_block_allocate(&block_pool_0, (VOID **) &pointer, TX_NO_WAIT);

    /* Release the block back to the pool.  */
    tx_block_release(pointer);
}



/* Define the test threads.  */

void    thread_0_entry(ULONG thread_input)
{

    UINT status;


    /* This thread simply sits in while-forever-sleep loop.  */
    while(1)
    {

        /* Increment the thread counter.  */
        thread_0_counter++;

        /* Sleep for 10 ticks.  */
        tx_thread_sleep(100);

        /* Set event flag 0 to wakeup thread 5.  */
        status =  tx_event_flags_set(&event_flags_0, 0x1, TX_OR);

        /* Check status.  */
        if (status != TX_SUCCESS)
            break;
    }
}

void flashled(int n, uint32_t * led1, uint32_t * led2, uint32_t * led3){
    NRF_P0->DIRCLR = 0xFFF0;
    NRF_P0->OUTCLR = 0xFFF0;
    switch(n)
    {
        case 0:
            NRF_P0->DIRSET = *led1;
            NRF_P0->OUTSET = 0x2000;
            break;
        case 1:
            NRF_P0->DIRSET = *led2;
            NRF_P0->OUTSET = 0x4000;
            break;
        case 2:
            NRF_P0->DIRSET = *led3;
            NRF_P0->OUTSET = 0x8000;
            break;
    }
}

void thread_5_entry(ULONG thread_input)
{
    UINT    status;
    ULONG   actual_flags;
    ULONG   received_message;
    char hello[] = "Hello!\0";
    static int i = 0;
    static int j = 0;
    static int k = 0;
    static int l = 0;

    static uint32_t mled_row1 = 0x0;
    static uint32_t mled_row2 = 0x0;
    static uint32_t mled_row3 = 0x0;

    /* This thread simply waits for an event in a forever loop.  */
    while(1)
    {
        /* Increment the thread counter.  */
        thread_5_counter++;

        /* Wait for event flag 0.  */
        status =  tx_event_flags_get(&event_flags_0, 0x1, TX_OR_CLEAR, 
                                                &actual_flags, TX_WAIT_FOREVER);

        /* Check status.  */
        if ((status != TX_SUCCESS) || (actual_flags != 0x1))
            break;

        status = tx_queue_receive(&queue_0, &received_message, TX_NO_WAIT);
        if(status == TX_SUCCESS) {
            j = k = l = 0;
        }
        flashled(i++, &mled_row1, &mled_row2, &mled_row3);
        if(i >= 3)
            i = 0;

        if(++j == 30){
            j = 0;
            make_animation(hello[l], k++, received_message, &mled_row1, &mled_row2, &mled_row3);
            if(k > 8) {
                k = 0;
                l++;
                if(hello[l] == '\0') l = 0;
            }
        }
    }
}
