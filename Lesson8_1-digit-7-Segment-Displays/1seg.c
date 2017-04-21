
/*
 * Created by keen
 * Modified by keen 
 * Compiling: g++ -Wall -o 1seg 1seg.c -lwiringPi
 * Run: sudo ./1seg
 * Date: 12/04/2017
 */
#include <wiringPi.h>
#include <stdio.h>

#define  ASeg  6
#define  BSeg  5
#define  CSeg  1
#define  DSeg  16
#define  ESeg  15
#define  FSeg  10
#define  GSeg  11
#define  PSeg  4

int seg[8]={ASeg,BSeg,CSeg,DSeg,ESeg,FSeg,GSeg,PSeg};

int a[10][7]={
               {1,1,1,1,1,1,0},  //0
               {0,1,1,0,0,0,0},  //1
               {1,1,0,1,1,0,1},  //2
               {1,1,1,1,0,0,1},  //3
               {0,1,1,0,0,1,1},  //4
               {1,0,1,1,0,1,1},  //5
               {1,0,1,1,1,1,1},  //6
               {1,1,1,0,0,0,0},  //7
               {1,1,1,1,1,1,1},  //8
               {1,1,1,1,0,1,1},};//9

void setup(){
  for (int i=0;i<8;i++) {
    pinMode(seg[i],OUTPUT);
  }
  digitalWrite(PSeg, HIGH);
}

void printf(int v){
  for (int i=0;i<=6;i++){
    digitalWrite(seg[i],a[v][i]);
  }
}

void loop(){
  for (int i=0;i<=9;i++){
    printf(i);
    delay(3000);
  }
}

int main(void){
  printf( "Welcome to Elecrow...\n");
  printf( "Raspberry Pi 1 digital 7 Segment Displays program...\n" );
  printf( "Press Ctrl+C to exit\n..." );
  wiringPiSetup();
  setup();
  while(1){
    loop();
  }
}

