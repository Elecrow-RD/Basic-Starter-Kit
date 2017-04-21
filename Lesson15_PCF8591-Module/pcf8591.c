/*
 * Created by keen
 * Modified by keen 
 * Compiling :gcc -Wall -o pcf8591 pcf8591.c -lwiringPi
 * Run : sudo ./pcf8591 
 * Date: 28/03/2017
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
    int value;
    wiringPiSetup();
	printf( "Welcome to Elecrow\n");
	printf( "Raspberry Pi PCF8591 Module test program\n" );
    pcf8591Setup(BASE,Address);

    while(1)
    {   
        value = analogRead(A0);
        printf("Analoge: %d\n",value);
        printf("Analoge: %dmv\n",value*5000/255);
        delay(1000);
    }   
}
