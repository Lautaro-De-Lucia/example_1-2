#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    // Inicialización de los Inputs por medio de la clase DigitalIn de la biblioteca mbed.h
    // Código en /mbed-os/drivers/source/DigitalIn.cpp
    // El código es esencialmente un Wrapper sobre la clase PinMode de la bliblioteca mbed_critical.h
    // El código fuente se encuentra en /mbed-os/platform/source/mbed_critical.c
    // Evidentemente, es código C y no C++
        // DigitalOut.h
    DigitalIn gasDetector(D2);
    DigitalIn overTempDetector(D3);
    // Alternativamente, se puede utilizar step-into en el debugger
    // Para DigitalOut:
    // main.cpp ~> DigitalOut.h ~> mbed_gpio.c ~> gpio_api.c ~> pinmap.c ~> stm32f4xx_ll_gp.h
    // El call-stack tiene la siguiente jerarquía de llamados
    // DigitalOut()
        // gpio_init_out()
            // gpio_init_out_ex()
                // _gpio_init_out()
                    // gpio_init()
                        // STM_PORT();
                        // Set_GPIO_Clock();
    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);   
    overTempDetector.mode(PullDown);

    while (true) {
        
        if ( gasDetector || overTempDetector ) {
            printf("%s\n", "Sobre-temperatura o escape de gas detectado.");
            alarmLed = ON;
        } else {
            printf("%s\n", "Todo bien.");
            alarmLed = OFF;
        }
    }
}