add_executable(Hello-World-c Hello-World.c) 

add_avrdude_programming_targets(
    Hello-World-c
    BAUD_RATE 115200
    PART atmega328p
    PORT ${AVRDUDE_PORT}
    PROGRAMMER arduino
    VERBOSITY VERBOSE
)
