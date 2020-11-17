#!/bin/bash

arm-none-eabi-gcc -c -g -mcpu=cortex-m0 -mthumb -o tx_vectors.o tx_vectors.s
arm-none-eabi-gcc -c -g -mcpu=cortex-m0 -mthumb -o cortexm0_crt0.o cortexm0_crt0.s
arm-none-eabi-gcc -c -g -mcpu=cortex-m0 -mthumb -o tx_initialize_low_level.o tx_initialize_low_level.S
arm-none-eabi-gcc -c -g -mcpu=cortex-m0 -mthumb -I../../../../common/inc -I../inc sample_threadx.c
arm-none-eabi-gcc -mthumb -mabi=aapcs -Wl,--gc-sections --specs=nano.specs -lc -lnosys -nostdlib -mcpu=cortex-m0 -ereset_handler -T sample_threadx.ld tx_vectors.o cortexm0_crt0.o tx_initialize_low_level.o sample_threadx.o tx.a  libgcc.a -o sample_threadx.out
arm-none-eabi-objcopy sample_threadx.out main.hex -O ihex

