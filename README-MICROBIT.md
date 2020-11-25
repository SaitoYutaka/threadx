# Azure RTOS ThreadX on micro:bit

## build

```
$ git clone --recursive https://github.com/SaitoYutaka/threadx.git
$ cd threadx/build-microbit/example_build/
$ make
```

## run qemu

```
$ qemu-system-arm -M microbit -device loader,file=main.hex -serial stdio -s -S
```

## Run debug on Visual Studio code
  Run "start debugging".

