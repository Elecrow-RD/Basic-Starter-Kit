/*
 * Created by keen
 * Modified by keen 
 * Compiling: gcc -Wall -o flame flame.c -lwiringPi
 * Run: sudo ./flame
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
    printf( "Raspberry Pi flame test program...\n" );
    printf( "Press Ctrl+C to exit\n..." );
    int value;
    wiringPiSetup();
    pcf8591Setup(BASE,Address);

    while(1)
    {   
        value = analogRead(A0);
        printf("Scanning: %dmv\n",value*5000/255);
        delay(1000);
    }   
}
