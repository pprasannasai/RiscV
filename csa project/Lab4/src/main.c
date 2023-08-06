#include <stdio.h>
#include <header1.h>
#include <stdlib.h>
#include<stdbool.h>

// LED_1,
//  LED_2,
//  LED_3,
//  OPEN_LED,
//  CLOSE_LED,
//  MOVING_LED,
//  OPEN_BTN,
//  CLOSE_BTN,
//  GO_BTN,
//  FLR1_BTN,
//  FLR2_BTN,
//  FLR3_BTN
int current_flr = 1;
bool led1=false;
bool led2=false;
bool led3=false;
bool openled=false;
bool closeled=false;
bool movingled=false;

void close_state()
{
   //the system is waiting on the user to press close button
   while (1)
   {
      if(!checkBot(CLOSE_BTN)){
         break;
      }
          
   }
   if(!closeled){
      setLED(CLOSE_LED, ON);
      closeled=true;
   }
   
   //while close led is on i.e door is closing then open button is disabled as delay is being run
   delay(15000);

   if(closeled){
      setLED(CLOSE_LED, OFF);
      closeled=false;
   }
   
}

void open_state()
{
   //the system is waiting on the user to press open button
   while (1)
   {
      if(!checkBot(OPEN_BTN)) break;
   }


  if(!openled){
      setLED(OPEN_LED, ON);
      openled=true;
   }
   
   //while open led is on i.e door is opening then close button is disabled as delay is being run
   delay(15000);

   if(openled){
      setLED(OPEN_LED, OFF);
      openled=false;
   }
}

void moving_state(int curr_flr, int dest_flr)
{
   if (curr_flr == dest_flr)
      return;
   
   //the system is waiting on pressing go button 
   while (1)
   {
      if(!checkBot(GO_BTN)) break;
   }

   if(!movingled){
      setLED(MOVING_LED, ON);
      movingled=true;
   }
   // while moving led is on the other buttons as disabled due to delay function
   delay(5000 * abs(dest_flr - curr_flr));

   if(movingled){
      setLED(MOVING_LED, OFF);
      movingled=false;
   }
   
   current_flr = dest_flr;
   open_state();
   close_state();
}

//this function is used to switch off LED
void switch_off_led(int flr){
   if (flr == 1)
      {
         if(led1){
            setLED(LED_1, OFF);
            led1=false;
         }
         
      }
      else if (flr == 2)
      {
         if(led2){
            setLED(LED_2, OFF);
            led2=false;
         }
      }
      else if (flr == 3)
      {
         if(led3){
            setLED(LED_3, OFF);
            led3=false;
         }
      }

}

//this function is used to switch on LED
void switch_on_led(int flr){
   if (flr == 1)
      {
         if(!led1){
            setLED(LED_1, ON);
            led1=true;
         }
      }
      else if (flr == 2)
      {
         if(!led2){
            setLED(LED_2, ON);
            led2=true;
         }
      }
      else if (flr == 3)
      {
         if(!led3){
            setLED(LED_3, ON);
            led3=true;
         }
      }

}

int main()
{

   int error = 0;
   int dest_flr = current_flr;
   setupGPIO();
   
   while (1)
   { // idle state
      switch_on_led(current_flr);
      
      //check if the desired floor is pressed by User
      if (!checkBot(FLR1_BTN))
      {

         dest_flr = 1;
      }
      else if (!checkBot(FLR2_BTN))
      {
         dest_flr = 2;
      }
      else if (!checkBot(FLR3_BTN))
      {
         dest_flr = 3;
      }

      //if desired floor is pressed other than current floor go to moving state to wait on GO button
      if(current_flr!=dest_flr){
         switch_off_led(current_flr);
         switch_on_led(dest_flr);
         moving_state(current_flr, dest_flr);
      }
      
      
      dest_flr = current_flr;
   }
   return 0;
}