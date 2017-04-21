/*
 * Created by keen
 * Modified by keen 
 * Compiling: gcc -Wall -o 4seg 4seg.c -lwiringPi
 * Run: sudo ./4seg
 * Date: 28/03/2017
 */

#include <wiringPi.h>
#include <stdio.h>
#include <time.h>

#define  ASeg  11 //9
#define  BSeg  28 //13
#define  CSeg  1 //4
#define  DSeg  5 //6
#define  ESeg  6 //7
#define  FSeg  31 //10
#define  GSeg  16 //3

#define  a1  10//8
#define  a2  26//11
#define  a3  27//12
#define  a4  15 //2

// set variable
long n = 0;
int x = 100;
int del = 54; // fine adjustment for clock

//
int pickDigit(int x);
int pickNumber(int x);
int clearLEDS(void); 
int zero(void);
int one(void);
int two(void);
int three();
int four();
int five();
int six();
int seven();
int eight();
void nine();

// Select display position
int pickDigit(int x) {
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(a4, LOW);

  switch(x)
  {
  case 1:
    digitalWrite(a1, HIGH);
    break;
  case 2:
    digitalWrite(a2, HIGH);
    break;
  case 3:
    digitalWrite(a3, HIGH);
    break;
  case 4:
    digitalWrite(a4, HIGH);
    break;  
  }
  return 0;
}
// select display number 
int pickNumber(int x) {
   switch(x) {
   case 1: one(); break;
   case 2: two(); break;
   case 3: three(); break;
   case 4: four(); break;
   case 5: five(); break;
   case 6: six(); break;
   case 7: seven(); break;
   case 8: eight(); break;
   case 9: nine(); break;
   default: zero(); break;
   }
  return 0;
}

int clearLEDS(void)  // clear the screen
{
   digitalWrite(ASeg, HIGH);
   digitalWrite(BSeg, HIGH);
   digitalWrite(CSeg, HIGH);
   digitalWrite(DSeg, HIGH);
   digitalWrite(ESeg, HIGH);
   digitalWrite(FSeg, HIGH);
   digitalWrite(GSeg, HIGH);
  return 0;
}

//Display function ‘0-9’
int zero(void) {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, LOW);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, HIGH);
  return 0;
}

int one(void) { 
  digitalWrite(ASeg, HIGH);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, HIGH);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, HIGH);
  digitalWrite(GSeg, HIGH);
  return 0;
}

int two(void) {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, HIGH);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, LOW);
  digitalWrite(FSeg, HIGH);
  digitalWrite(GSeg, LOW);
  return 0;
}

int three(void) {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, HIGH);
  digitalWrite(GSeg, LOW);
  return 0;
}
int four(void) {
  digitalWrite(ASeg, HIGH);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, HIGH);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, LOW);
  return 0;
}
int five(void) {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, HIGH);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, LOW);
  return 0;
}
int six(void) {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, HIGH);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, LOW);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, LOW);
  return 0;
}

int seven(void) {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, HIGH);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, HIGH);
  digitalWrite(GSeg, HIGH);
  return 0;
}

int eight(void) {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, LOW);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, LOW);
  return 0;
}

void nine() {
  digitalWrite(ASeg, LOW);
  digitalWrite(BSeg, LOW);
  digitalWrite(CSeg, LOW);
  digitalWrite(DSeg, LOW);
  digitalWrite(ESeg, HIGH);
  digitalWrite(FSeg, LOW);
  digitalWrite(GSeg, LOW);
}

int setup(void)
{
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(a4, OUTPUT);
  pinMode(ASeg, OUTPUT);
  pinMode(BSeg, OUTPUT);
  pinMode(CSeg, OUTPUT);
  pinMode(DSeg, OUTPUT);
  pinMode(ESeg, OUTPUT);
  pinMode(FSeg, OUTPUT);
  pinMode(GSeg, OUTPUT);
  return 0;
}


int main(void){

  printf( "Welcome to Elecrow...\n");
  printf( "Raspberry Pi blink program...\n" );
  printf( "Press Ctrl+C to exit\n..." );
  wiringPiSetup();
  setup();
  while(1){
   clearLEDS();  // Eliminating ghost
   pickDigit(1);  // Display position 1
   pickNumber((n/x/1000)%10); // Display number
   delayMicroseconds(del);  // Time adjustment
   
   clearLEDS();
   pickDigit(2);
   pickNumber((n/x/100)%10);
   delayMicroseconds(del);
     
   clearLEDS();
   pickDigit(3);
   pickNumber((n/x/10)%10);
   delayMicroseconds(del);
     
   clearLEDS();
   pickDigit(4);
   pickNumber(n/x%10);
   delayMicroseconds(del); 
   n++;
  }
  return 0;
}


