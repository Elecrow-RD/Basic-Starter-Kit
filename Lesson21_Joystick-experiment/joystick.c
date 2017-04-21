/*
 * Created by keen
 * Modified by keen 
 * Compiling: gcc -Wall -o joystick joystick.c -lwiringPi
 * Run: sudo ./joystick
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
    printf( "Raspberry Pi joystick test program...\n" );
    printf( "Press Ctrl+C to exit\n..." );
    int x_value,y_value,bt_value;
    wiringPiSetup();
    pcf8591Setup(BASE,Address);

    while(1)
    {   
        x_value = analogRead(A0);
        y_value = analogRead(A1);
	bt_value = analogRead(A2);
        printf("Current x-axis data: %d\n",x_value*5000/255*2);
        printf("Current y-axis data: %d\n",y_value*5000/255*2);
        printf("Current button data: %d\n",bt_value*5000/255*2);
/*
	if(bt_value){
          printf("Pressed the button...");
	}
*/
        delay(500);
    }   
}
