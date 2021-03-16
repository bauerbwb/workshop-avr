add_executable(blink-c blink.c) 

add_avrdude_programming_targets(
    blink-c
    BAUD_RATE 115200
    PART atmega328p
    PORT ${AVRDUDE_PORT}
    PROGRAMMER arduino
    VERBOSITY VERBOSE
)

add_executable(blink-cc blink.cc) 

add_avrdude_programming_targets(
    blink-cc
    BAUD_RATE 115200
    PART atmega328p
    PORT ${AVRDUDE_PORT}
    PROGRAMMER arduino
    VERBOSITY VERBOSE
)
