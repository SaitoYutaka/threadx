
CC = arm-none-eabi-gcc

CFLAGS = -mcpu=cortex-m0 -mthumb -mabi=aapcs \
-Wall -O0 -g -mfloat-abi=soft -ffunction-sections -fdata-sections -fno-strict-aliasing -fomit-frame-pointer \
-fno-builtin --short-enums -c

INCDIR =-I../../common/inc \
-I../inc

OBJS = \
tx_thread_stack_build.o \
tx_thread_schedule.o \
tx_thread_system_return.o \
tx_thread_context_save.o \
tx_thread_context_restore.o \
tx_timer_interrupt.o \
tx_thread_interrupt_control.o \
tx_thread_interrupt_control.o \
tx_block_allocate.o \
tx_block_pool_cleanup.o \
tx_block_pool_create.o \
tx_block_pool_delete.o \
tx_block_pool_info_get.o \
tx_block_pool_initialize.o \
tx_block_pool_performance_info_get.o \
tx_block_pool_performance_system_info_get.o \
tx_block_pool_prioritize.o \
tx_block_release.o \
tx_byte_allocate.o \
tx_byte_pool_cleanup.o \
tx_byte_pool_create.o \
tx_byte_pool_delete.o \
tx_byte_pool_info_get.o \
tx_byte_pool_initialize.o \
tx_byte_pool_performance_info_get.o \
tx_byte_pool_performance_system_info_get.o \
tx_byte_pool_prioritize.o \
tx_byte_pool_search.o \
tx_byte_release.o \
tx_event_flags_cleanup.o \
tx_event_flags_create.o \
tx_event_flags_delete.o \
tx_event_flags_get.o \
tx_event_flags_info_get.o \
tx_event_flags_initialize.o \
tx_event_flags_performance_info_get.o \
tx_event_flags_performance_system_info_get.o \
tx_event_flags_set.o \
tx_event_flags_set_notify.o \
tx_initialize_high_level.o \
tx_initialize_kernel_enter.o \
tx_initialize_kernel_setup.o \
tx_mutex_cleanup.o \
tx_mutex_create.o \
tx_mutex_delete.o \
tx_mutex_get.o \
tx_mutex_info_get.o \
tx_mutex_initialize.o \
tx_mutex_performance_info_get.o \
tx_mutex_performance_system_info_get.o \
tx_mutex_prioritize.o \
tx_mutex_priority_change.o \
tx_mutex_put.o \
tx_queue_cleanup.o \
tx_queue_create.o \
tx_queue_delete.o \
tx_queue_flush.o \
tx_queue_front_send.o \
tx_queue_info_get.o \
tx_queue_initialize.o \
tx_queue_performance_info_get.o \
tx_queue_performance_system_info_get.o \
tx_queue_prioritize.o \
tx_queue_receive.o \
tx_queue_send.o \
tx_queue_send_notify.o \
tx_semaphore_ceiling_put.o \
tx_semaphore_cleanup.o \
tx_semaphore_create.o \
tx_semaphore_delete.o \
tx_semaphore_get.o \
tx_semaphore_info_get.o \
tx_semaphore_initialize.o \
tx_semaphore_performance_info_get.o \
tx_semaphore_performance_system_info_get.o \
tx_semaphore_prioritize.o \
tx_semaphore_put.o \
tx_semaphore_put_notify.o \
tx_thread_create.o \
tx_thread_delete.o \
tx_thread_entry_exit_notify.o \
tx_thread_identify.o \
tx_thread_info_get.o \
tx_thread_initialize.o \
tx_thread_performance_info_get.o \
tx_thread_performance_system_info_get.o \
tx_thread_preemption_change.o \
tx_thread_priority_change.o \
tx_thread_relinquish.o \
tx_thread_reset.o \
tx_thread_resume.o \
tx_thread_shell_entry.o \
tx_thread_sleep.o \
tx_thread_stack_analyze.o \
tx_thread_stack_error_handler.o \
tx_thread_stack_error_notify.o \
tx_thread_suspend.o \
tx_thread_system_preempt_check.o \
tx_thread_system_resume.o \
tx_thread_system_suspend.o \
tx_thread_terminate.o \
tx_thread_time_slice.o \
tx_thread_time_slice_change.o \
tx_thread_timeout.o \
tx_thread_wait_abort.o \
tx_time_get.o \
tx_time_set.o \
tx_timer_activate.o \
tx_timer_change.o \
tx_timer_create.o \
tx_timer_deactivate.o \
tx_timer_delete.o \
tx_timer_expiration_process.o \
tx_timer_info_get.o \
tx_timer_initialize.o \
tx_timer_performance_info_get.o \
tx_timer_performance_system_info_get.o \
tx_timer_system_activate.o \
tx_timer_system_deactivate.o \
tx_timer_thread_entry.o \
tx_trace_enable.o \
tx_trace_disable.o \
tx_trace_initialize.o \
tx_trace_interrupt_control.o \
tx_trace_isr_enter_insert.o \
tx_trace_isr_exit_insert.o \
tx_trace_object_register.o \
tx_trace_object_unregister.o \
tx_trace_user_event_insert.o \
tx_trace_buffer_full_notify.o \
tx_trace_event_filter.o \
tx_trace_event_unfilter.o \
txe_block_allocate.o \
txe_block_pool_create.o \
txe_block_pool_delete.o \
txe_block_pool_info_get.o \
txe_block_pool_prioritize.o \
txe_block_release.o \
txe_byte_allocate.o \
txe_byte_pool_create.o \
txe_byte_pool_delete.o \
txe_byte_pool_info_get.o \
txe_byte_pool_prioritize.o \
txe_byte_release.o \
txe_event_flags_create.o \
txe_event_flags_delete.o \
txe_event_flags_get.o \
txe_event_flags_info_get.o \
txe_event_flags_set.o \
txe_event_flags_set_notify.o \
txe_mutex_create.o \
txe_mutex_delete.o \
txe_mutex_get.o \
txe_mutex_info_get.o \
txe_mutex_prioritize.o \
txe_mutex_put.o \
txe_queue_create.o \
txe_queue_delete.o \
txe_queue_flush.o \
txe_queue_front_send.o \
txe_queue_info_get.o \
txe_queue_prioritize.o \
txe_queue_receive.o \
txe_queue_send.o \
txe_queue_send_notify.o \
txe_semaphore_ceiling_put.o \
txe_semaphore_create.o \
txe_semaphore_delete.o \
txe_semaphore_get.o \
txe_semaphore_info_get.o \
txe_semaphore_prioritize.o \
txe_semaphore_put.o \
txe_semaphore_put_notify.o \
txe_thread_create.o \
txe_thread_delete.o \
txe_thread_entry_exit_notify.o \
txe_thread_info_get.o \
txe_thread_preemption_change.o \
txe_thread_priority_change.o \
txe_thread_relinquish.o \
txe_thread_reset.o \
txe_thread_resume.o \
txe_thread_suspend.o \
txe_thread_terminate.o \
txe_thread_time_slice_change.o \
txe_thread_wait_abort.o \
txe_timer_activate.o \
txe_timer_change.o \
txe_timer_create.o \
txe_timer_deactivate.o \
txe_timer_delete.o \
txe_timer_info_get.o

all : main.hex

tx_vectors.o : tx_vectors.s
	arm-none-eabi-gcc -c -g -mcpu=cortex-m0 -mthumb -o $@ -c $<

cortexm0_crt0.o : cortexm0_crt0.s
	arm-none-eabi-gcc -c -g -mcpu=cortex-m0 -mthumb -o $@ -c $<

tx_initialize_low_level.o : tx_initialize_low_level.S
	arm-none-eabi-gcc -c -g -mcpu=cortex-m0 -mthumb -o $@ -c $<

sample_threadx.o: sample_threadx.c
	$(CC) $(TARGET_ARCH) $(INCDIR) $(CFLAGS) -o $@ -c $<

main.out : tx_vectors.o cortexm0_crt0.o tx_initialize_low_level.o sample_threadx.o tx.a libgcc.a
	arm-none-eabi-gcc -mthumb -mabi=aapcs -Wl,--gc-sections --specs=nano.specs -lc -lnosys -nostdlib -mcpu=cortex-m0 -ereset_handler -T sample_threadx.ld tx_vectors.o cortexm0_crt0.o tx_initialize_low_level.o sample_threadx.o tx.a libgcc.a -o $@

main.hex : main.out
	arm-none-eabi-objcopy $< $@ -O ihex

tx.a : $(OBJS)
	arm-none-eabi-ar -r tx.a $(OBJS)

%.o:../src/%.S
	arm-none-eabi-gcc -c -g -mcpu=cortex-m0 -mthumb -o $@ -c $<

%.o:../../common/src/%.c
	$(CC) $(TARGET_ARCH) $(INCDIR) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.hex
	rm -f *.o
	rm -f *.out
	rm tx.a

