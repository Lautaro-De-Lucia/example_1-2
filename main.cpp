#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2);
    DigitalIn overTempDetector(D3);

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