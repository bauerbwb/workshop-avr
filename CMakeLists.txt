cmake_minimum_required( VERSION 3.16.3)

project(
    workshop-avr
    LANGUAGES C CXX

    )

set( AVRDUDE_PORT "" CACHE STRING "avrdude: port" )

set( CMAKE_BUILD_TYPE "MinSizeRel" CACHE STRING "" FORCE )

mark_as_advanced( CMAKE_BUILD_TYPE )

# configure compilation and linking
set(
    CMAKE_C_FLAGS
    "${CMAKE_C_FLAGS} \
    -std=c17 \
    -Werror -Wall -Wextra \
    -Wcast-align=strict \
    -Wcast-qual \
    -Wduplicated-cond \
    -Wfloat-equal \
    -Wimplicit-fallthrough=5 \
    -Wlogical-op \
    -Wmissing-field-initializers \
    -Wmissing-include-dirs \
    -Wpointer-arith \
    -Wshadow \
    -Wstrict-prototypes \
    -Wunsafe-loop-optimizations \
    -mmcu=atmega328p \
    -DF_CPU=16000000UL \
    "
)
set( CMAKE_CXX_STANDARD 17 )
set(
    CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} \
    -Werror -Wall -Wextra \
    -Wcast-align=strict \
    -Wcast-qual \
    -Wduplicated-cond \
    -Wextra-semi \
    -Wfloat-equal \
    -Wimplicit-fallthrough=5 \
    -Wlogical-op \
    -Wmissing-field-initializers \
    -Wmissing-include-dirs \
    -Wold-style-cast \
    -Wplacement-new=2 \
    -Wpointer-arith \
    -Wshadow \
    -Wunsafe-loop-optimizations \
    -mmcu=atmega328p \
    -DF_CPU=16000000UL \
    "
)

add_subdirectory(blink)
