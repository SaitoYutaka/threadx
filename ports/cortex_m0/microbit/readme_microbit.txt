* Status
  At the moment, I only confirmed that the process comes to the main function on qemu.

* build
  $ cd example_build
  $ ./build_threadx.sh && ./build_threadx_sample.sh

* run qemu
  $ qemu-system-arm -M microbit -device loader,file=main.hex -serial stdio -s -S

* Run debug on Visual Studio code
  Run "start debugging".
