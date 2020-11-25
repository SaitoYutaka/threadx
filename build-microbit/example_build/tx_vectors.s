

  .global reset_handler

  .global __tx_NMIHandler
  .global __tx_BadHandler
  .global __tx_SVCallHandler
  .global __tx_DBGHandler
  .global __tx_PendSVHandler 
  .global __tx_SysTickHandler 
  .global __tx_BadHandler
  .global __tx_HardfaultHandler
  .global POWER_CLOCK_IRQHandler
  .global GPIOTE_IRQHandler
  .global RTC0_IRQHandler

  .syntax unified
  .section .vectors, "ax"
  .code 16
  .align 0
  .global _vectors

_vectors:
  .word __stack_end__ 
  .word reset_handler 
  .word __tx_NMIHandler 
  .word __tx_HardfaultHandler
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  .word __tx_SVCallHandler //_SVC_Handler - used by Threadx scheduler //
  .word 0 // Reserved
  .word 0 // Reserved
  .word __tx_PendSVHandler 
  .word __tx_SysTickHandler   // Used by Threadx timer functionality

  .word POWER_CLOCK_IRQHandler // POWER_CLOCK_IRQHandler
  .word RADIO_IRQHandler
  .word UART0_IRQHandler
  .word SPI0_TWI0_IRQHandler
  .word SPI1_TWI1_IRQHandler
  .word 0 // Reserved
  .word GPIOTE_IRQHandler // GPIOTE_IRQHandler
  .word ADC_IRQHandler
  .word TIMER0_IRQHandler
  .word TIMER1_IRQHandler
  .word TIMER2_IRQHandler
  .word RTC0_IRQHandler // RTC0_IRQHandler
  .word TEMP_IRQHandler
  .word RNG_IRQHandler
  .word ECB_IRQHandler
  .word CCM_AAR_IRQHandler
  .word WDT_IRQHandler
  .word RTC1_IRQHandler
  .word QDEC_IRQHandler
  .word LPCOMP_IRQHandler
  .word SWI0_IRQHandler
  .word SWI1_IRQHandler
  .word SWI2_IRQHandler
  .word SWI3_IRQHandler
  .word SWI4_IRQHandler
  .word SWI5_IRQHandler
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  .word 0 // Reserved
  @ .word 0 // Reserved
  @ .word 0 // Reserved
  @ .word 0 // Reserved



    .section .init, "ax"
    .thumb_func
reset_handler:

// low level hardware config, such as PLL setup goes here
  .equ    NRF_POWER_RAMON_ADDRESS,             0x40000524
  .equ    NRF_POWER_RAMONB_ADDRESS,            0x40000554
  .equ    NRF_POWER_RAMONx_RAMxON_ONMODE_Msk,  0x3
  MOVS    R1, #NRF_POWER_RAMONx_RAMxON_ONMODE_Msk

  LDR     R0, =NRF_POWER_RAMON_ADDRESS
  LDR     R2, [R0]
  ORRS    R2, R1
  STR     R2, [R0]

  LDR     R0, =NRF_POWER_RAMONB_ADDRESS
  LDR     R2, [R0]
  ORRS    R2, R1
  STR     R2, [R0]
  b _start



    .text 32
    .align 4
    .syntax unified


__tx_NMIHandler:
    b   __tx_NMIHandler

__tx_BadHandler:
    b   __tx_BadHandler

__tx_DBGHandler:
    b   __tx_DBGHandler

__tx_HardfaultHandler:
    b   __tx_HardfaultHandler

RADIO_IRQHandler:
    b  RADIO_IRQHandler
    
UART0_IRQHandler:
    b  UART0_IRQHandler
    
SPI0_TWI0_IRQHandler:
    b  SPI0_TWI0_IRQHandler
    
SPI1_TWI1_IRQHandler:
    b  SPI1_TWI1_IRQHandler
    
ADC_IRQHandler:
    b  ADC_IRQHandler
    
TIMER0_IRQHandler:
    b  TIMER0_IRQHandler
    
TIMER1_IRQHandler:
    b  TIMER1_IRQHandler
    
TIMER2_IRQHandler:
    b  TIMER2_IRQHandler
    
TEMP_IRQHandler:
    b  TEMP_IRQHandler
    
RNG_IRQHandler:
    b  RNG_IRQHandler
    
ECB_IRQHandler:
    b  ECB_IRQHandler
    
CCM_AAR_IRQHandler:
    b  CCM_AAR_IRQHandler
    
WDT_IRQHandler:
    b  WDT_IRQHandler
    
RTC1_IRQHandler:
    b  RTC1_IRQHandler
    
QDEC_IRQHandler:
    b  QDEC_IRQHandler
    
LPCOMP_IRQHandler:
    b  LPCOMP_IRQHandler
    
SWI0_IRQHandler:
    b  SWI0_IRQHandler
    
SWI1_IRQHandler:
    b  SWI1_IRQHandler
    
SWI2_IRQHandler:
    b  SWI2_IRQHandler
    
SWI3_IRQHandler:
    b  SWI3_IRQHandler
    
SWI4_IRQHandler:
    b  SWI4_IRQHandler
    
SWI5_IRQHandler:
    b  SWI5_IRQHandler
    