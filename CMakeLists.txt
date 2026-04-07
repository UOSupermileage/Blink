cmake_minimum_required(VERSION 3.25.2)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(blink C CXX ASM)
pico_sdk_init()

set(CMAKE_C_STANDARD 11)

add_executable(blink main.c)

# Link with Pico SDK libraries
target_link_libraries(blink pico_stdlib)

# (Optional) Create UF2, ELF, BIN files
pico_add_extra_outputs(blink)


