add_executable(blink-c blink.c) 

add_avrdude_programming_targets(
    blink-c
    BAUD_RATE 115200
    PART atmega328p
    PORT ${AVRDUDE_PORT}
    PROGRAMMER arduino
    VERBOSITY VERBOSE
)
