/*
 * Created by keen
 * Modified by keen 
 * Compiling: gcc -Wall -o watersensor watersensor.c -lwiringPi
 * Run: sudo ./watersensor
 * Date: 12/04/2017
 */
#include <wiringPi.h>
#include <pcf8591.h>
#include <stdio.h>

#define Address 0x48
#define BASE 64
#define A0 BASE+0
#define A1 BASE+1
#define A2 BASE+2
#define A3 BASE+3

int main(void)
{
    printf( "Welcome to Elecrow...\n");
    printf( "Raspberry Pi water_sensor test program...\n" );
    printf( "Press Ctrl+C to exit\n..." );
    int value;
    wiringPiSetup();
    pcf8591Setup(BASE,Address);

    while(1)
    {   
        value = (long)analogRead(A0);
       // printf("Current Water level: %dcm\n",value);
        printf("Print Water sensor value: %d\n",value);
        delay(1000);
    }   
}
