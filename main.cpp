#include "mbed.h"
#include "arm_book_lib.h"

// **Mbed OS**, un sistema operativo de código abierto diseñado por ARM para aplicaciones embebidas en microcontroladores.
// Mbed OS es software, su rol es el de proporcionar una API de alto nivel para gestionar 
// el dispositivo (entradas/salidas digitales, comunicación serial, temporizadores, etc.)
// En este archivo, se utilizan clases provistas por Mbed OS como `DigitalIn` y `DigitalOut`
// para acceder y controlar pines de entrada y salida digital sin necesidad de manipular
// directamente registros del hardware. 

int main()
{
    // Configuramos D2 y D3 como inputs GPIO
        // gasDetector es un **objeto** de la **clase** DigitalIn.
        // Se construye usando el **constructor** que recibe un PinName (D2).
        // Este objeto encapsula un pin configurado como entrada digital.
        // Utiliza el **método** `mode()` para definir el tipo de resistencia (PullDown).
        // El **método operador** `operator int()` está sobrecargado para poder evaluarlo directamente en un `if`.
        // Esta clase proporciona una **interfaz** para leer entradas digitales, oculta los detalles del hardware.
    DigitalIn gasDetector(D2);
    DigitalIn overTempDetector(D3);
    // Configuramos LED1 como output GPIO 
        // alarmLed es un **objeto** de la **clase** DigitalOut.
        // Se instancia con un **constructor** que recibe un PinName (LED1).
        // Usa el **método operador** `operator=` sobrecargado para asignar valores directamente como `alarmLed = ON`.
        // Internamente se llama al **método** `write()`, que cambia el estado lógico del pin.
        // Esta clase también implementa una **interfaz** para escribir salidas digitales.
    DigitalOut alarmLed(LED1);
    // Ponemos ambos inputs en modo PullDown
    gasDetector.mode(PullDown);   
    overTempDetector.mode(PullDown);

    while (true) {
        // Si se detecta gas o sobre-temperatura, se enciende la alarma y se imprime en pantalla
        if ( gasDetector || overTempDetector ) {
            printf("%s\n", "Sobre-temperatura o escape de gas detectado.");
            alarmLed = ON;
        } else {
        // Si no hay ninguna detección, se apaga la alarma
            printf("%s\n", "Todo bien.");
            alarmLed = OFF;
        }
    }
}