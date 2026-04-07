# Cross-compiling for Raspberry Pi Pico
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# specify the cross compiler
set(CMAKE_C_COMPILER "D:/Program Files/gcc-arm-none-eabi/bin/arm-none-eabi-gcc.exe")
set(CMAKE_CXX_COMPILER "D:/Program Files/gcc-arm-none-eabi/bin/arm-none-eabi-g++.exe")

# optional: tell CMake where to find linker and objcopy
set(CMAKE_OBJCOPY "D:/Program Files/gcc-arm-none-eabi/bin/arm-none-eabi-objcopy.exe")
set(CMAKE_AR "D:/Program Files/gcc-arm-none-eabi/bin/arm-none-eabi-ar.exe")
