/*
 * Created by keen
 * Modified by keen 
 * Compiling: gcc -Wall -o IR-LED IR-LED.c -lwiringPi -llirc_client
 * Run: sudo ./IR-LED
 * Date: 8/4/2017
 */

#include <wiringPi.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>
#include <time.h>
#define led_pin 22
/*
char *keymap[21] ={
	
" KEY_CHANNELDOWN ",
" KEY_CHANNEL ",
" KEY_CHANNELUP ",
" KEY_PREVIOUS ",
" KEY_NEXT ",
" KEY_PLAYPAUSE ",
" KEY_VOLUMEDOWN ",
" KEY_VOLUMEUP ",
" KEY_EQUAL ",
" KEY_NUMERIC_0 ",
" BTN_0 ",
" BTN_1 ",
" KEY_NUMERIC_1 ",
" KEY_NUMERIC_2 ",
" KEY_NUMERIC_3 ",
" KEY_NUMERIC_4 ",
" KEY_NUMERIC_5 ",
" KEY_NUMERIC_6 ",
" KEY_NUMERIC_7 ",
" KEY_NUMERIC_8 ",
" KEY_NUMERIC_9 "

};
*/
char *key1 = "KEY_CHANNELDOWN";
char *key2 = "KEY_CHANNELUP";
int keydata=0;

void key_switch(char *keycode){
  if (strstr(keycode, key1)){
      keydata = 1;
    }
  if (strstr(keycode, key2)){
	  keydata = 2;
    }
}

void control_led(int key){
	switch(key){
	  case 1: digitalWrite(led_pin, HIGH); printf("LED ON\n"); break;
	  case 2: digitalWrite(led_pin,  LOW); printf("LED OFF\n"); break;
	}
}
int main(void)
{
  printf( "Welcome to Elecrow...\n");
  printf( "Raspberry Pi IR remote control LED program...\n" );
  printf( "Press Ctrl+C to exit\n..." );
  
  struct lirc_config *config;
  int buttonTimer = millis();
  char *code;
  
  pinMode(led_pin,OUTPUT); 
  
  if(wiringPiSetup() == -1){
    printf("setup wiringPi failed !");
    return 1;
  }

  if(lirc_init("lirc",1)==-1)
    exit(EXIT_FAILURE);

  if(lirc_readconfig(NULL,&config,NULL)==0){
    while(lirc_nextcode(&code)==0){
      if(code==NULL) continue;{
        if (millis() - buttonTimer > 400){
          printf("the code=%s\n",code);
		  control_led(code);
        }
      }
      free(code);
    }
    lirc_freeconfig(config);
  }
  lirc_deinit();
  exit(EXIT_SUCCESS);
  return 0;
}
