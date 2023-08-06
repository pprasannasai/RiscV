#include <stdio.h>
#include <stdbool.h>
#include "header1.h"

// intitialize in gpio.inc.... use those offset in setupgpio.inc.... same offset values use in header.h with req variable names used in main.c
//NS = north south intersection EW = east west intersection
int stateA = 1; //EW:RED NS:RED, BOTH INTERSECTIONS RED
int stateB = 0; //EW:RED NS:GREEN
int stateC = 0; //EW:RED NS:YELLOW
int stateD = 0; //EW:GREEN NS:RED
int stateE = 0; //EW:YELLOW NS:RED
int stateF = 0; //EW:YELLOW NS:RED, PEDESTRIAN MODE
int stateG = 0; //EW:RED NS:RED, PEDESTRIAN MODE
int stateH = 0; //EW:RED NS:YELLOW, PEDESTRIAN MODE
int stateI = 0; //EW:RED NS:RED, PEDESTRIAN MODE
bool red_ns=false;
bool red_ew=false;
bool yellow_ns=false;
bool yellow_ew=false;
bool green_ns=false;
bool green_ew=false;
bool ped_red=false;
bool ped_green=false;
bool prev_state=false;

int saved_state=0;

//To save the state before going to the pedestrian mode
void save_state(){
   if(stateA==1){
      saved_state=1;
   }
   else if(stateB==1){
      saved_state=2;
   }
   else if(stateC==1){
      saved_state=3;
   }
   else if(stateD==1){
      saved_state=4;
   }
   else if(stateE==1){
      saved_state=5;
   }

}

//function to go to previous state after the pedestrian mode is executed
void goto_prev_state(){
   prev_state=true;

   switch(saved_state){
      case 1:
      stateA=1;
      break;
      case 2:
      stateB=1;
      break;
      case 3:
      stateC=1;
      break;
      case 4:
      stateD=1;
      break;
      case 5:
      stateE=1;
      break;
      default:
      stateA=1;
      break;
   }
} 

// check if push button is pushed on the East west intersection i.e if pedestrain wants to cross from north to south or vice versa direction
int ped_NS()
{
   if (!checkBot(PUSH_NS))
   {
      save_state();
      if (stateD)
      {
         stateF = 1;
         stateG = 0;
         stateD = 0;
      }
      else
      {
         stateG = 1;
         stateA = 0;
         stateB = 0;
         stateC = 0;
         stateD = 0;
         stateE = 0;
         stateF = 0;
         stateH = 0;
         stateI = 0;
      }
      return 1;
   }
   return 0;
}

// check if push button is pushed on the north south intersection i.e if pedestrain wants to cross from  East west or vice versa direction
int ped_EW()
{
   if (!checkBot(PUSH_EW))
   {
      save_state();
      if (stateB)
      {
         stateH = 1;
         stateI = 0;
         stateB = 0;
      }
      else
      {
         stateI = 1;
         stateA = 0;
         stateB = 0;
         stateC = 0;
         stateD = 0;
         stateE = 0;
         stateF = 0;
         stateH = 0;
         stateG = 0;
      }
      return 1;
   }
   return 0;
}

int main()
{

   int err = 0;
   setupGPIO();
   while (1)
   {
      while (stateA && !err)
      {
         //switch on ped_red in the initial stage
         if(!ped_red)
         {
            setLED(PED_RED,ON);
            ped_red=true;

         }
         
         //all the reds on on both the intersection
         if(!red_ns){
            setLED(RED_NS, ON);
            red_ns=true;
         }

         if(!red_ew){
            setLED(RED_EW, ON);
            red_ew=true;
         }

         delay(10000);

         //marking state A as 0 and going to next state by marking next state as 1
         stateA = 0;
         stateB = 1;

         prev_state=false;
      }
      while (stateB && !err)
      {
         //pedmode variable is used to check if the pedmestrian mode is turned on from intersections and then the state is saved and then we mode to pedestrian mode states
         int ped_mode = 0;

         if(!red_ew){
            setLED(RED_EW, ON);
            red_ew=true;
         }

         if(!green_ns){
            setLED(GREEN_NS, ON);
            green_ns=true;
         }
         
         if(red_ns){
            setLED(RED_NS, OFF);
            red_ns=false;
         }
         

         for (int time = 1; time <= 20; time++)
         {
            delay(1000);
            ped_mode = ped_NS() || ped_EW();
            //check after every second if the pedestrian mode has been triggered
            if (ped_mode)
            {
               break;
            }
         }
         if (ped_mode)
         {
            break;
         }
         stateB = 0;
         stateC = 1;
         prev_state=false;
      }
      while (stateC && !err)
      {
         //as mentioned above same functionality of using pedmode variable
         int ped_mode = 0;

         if(!red_ew){
            setLED(RED_EW, ON);
            red_ew=true;
         }

         if(!yellow_ns){
            setLED(YELLOW_NS, ON);
            yellow_ns=true;
         }
         
         if(green_ns){
            setLED(GREEN_NS, OFF);
            green_ns=false;
         }
         
         delay(3000);
         //below code was written to enable checking of pedestrian mode trigger when at intersection light is yellow other is red
         // for (int time = 1; time <= 3; time++)
         // {
         //    //same functionality to check if ped_mode is triggered after every second
         //    delay(1000);
         //    ped_mode = ped_NS() || ped_EW();
         //    if (ped_mode)
         //    {
         //       break;
         //    }
         // }
         // if (ped_mode)
         // {
         //    break;
         // }

         stateC = 0;
         stateD = 1;
         prev_state=false;
      }
      while (stateD && !err)
      {
         int ped_mode = 0;
         if(yellow_ns){
            setLED(YELLOW_NS, OFF);
            yellow_ns=false;
         }
         
         if(!red_ns){
             setLED(RED_NS, ON);
             red_ns=true;
            
         }
        
          if(!prev_state){
            delay(5000);
          }
          
          

         if(!green_ew){
            setLED(GREEN_EW, ON);
            green_ew=true;
         }
         
         if(red_ew){
             setLED(RED_EW, OFF);
             red_ew=false;
         }
        
         //same functionality to check if ped_mode is triggered after every second
         for (int time = 1; time <= 20; time++)
         {
            delay(1000);
            ped_mode = ped_NS() || ped_EW();
            if (ped_mode)
            {
               break;
            }
         }
         if (ped_mode)
         {
            break;
         }
         stateD = 0;
         stateE = 1;
         prev_state=false;
      }
      while (stateE && !err)
      { 

         if(green_ew){
            setLED(GREEN_EW, OFF);
            green_ew=false;
         }
         
         if(!yellow_ew){
            setLED(YELLOW_EW, ON);
            yellow_ew=true;
         }
         
         delay(3000);

         if(yellow_ew){
            setLED(YELLOW_EW, OFF);
            yellow_ew=false;
         }
         
         if(!red_ew){
            setLED(RED_EW, ON);
            red_ew=true;
         }

         if(!red_ns){
            setLED(RED_NS, ON);
            red_ns=true;
         }
         
         delay(5000);
         stateE = 0;
         stateA = 1;
         prev_state=false;
      }

      while (stateF && !err)
      {//ped_mode where the intersection green light turns to flashing yellow at East west intersection
         if(green_ew){
            setLED(GREEN_EW,OFF);
            green_ew=false;
         }
         
         for (int time = 1; time <= 20; time++)
         {
            if(!yellow_ew){
               setLED(YELLOW_EW, ON);
               yellow_ew=true;
            }
            
            delay(250);
            if(yellow_ew){
               setLED(YELLOW_EW, OFF);
               yellow_ew=false;
            }
            delay(250);
         }
         stateF = 0;
         stateG = 1;
      }

      while (stateG && !err)
      {// ped_mode where after flashing yellow at East west intersection it turns red and pedeestrian light turn green
         if(!red_ew){
            setLED(RED_EW, ON);
            red_ew=true;
         }
         
         if(ped_red){
            setLED(PED_RED,OFF);
            ped_red=false;
         }
         
         if(!ped_green){
            setLED(PED_GREEN,ON);
            ped_green=true;
         }
         
         delay(15000);

         if(!ped_red){
            setLED(PED_RED,ON);
            ped_red=true;
         }
         
         if(ped_green){
            setLED(PED_GREEN,OFF);
            ped_green=false;
         }


         if(red_ew){
            setLED(RED_EW, OFF);
            red_ew=false;
         }
         
         stateG = 0;
         goto_prev_state();

      }

      while (stateH && !err)
      {//ped_mode where the intersection green light turns to flashing yellow at north south intersection

         if(green_ns){
            setLED(GREEN_NS,OFF);
            green_ns=false;
         }
         
         for (int time = 1; time <= 20; time++)
         {
            if(!yellow_ns){
               setLED(YELLOW_NS, ON);
               yellow_ns=true;
            }
            
            delay(250);

            if(yellow_ns){
               setLED(YELLOW_NS, OFF);
               yellow_ns=false;
            }
            delay(250);
         }
         stateH = 0;
         stateI = 1;
      }

      while (stateI && !err)
      {// ped_mode where after flashing yellow at north south intersection it turns red and pedeestrian light turn green
         if(!red_ns){
            setLED(RED_NS, ON);
            red_ns=true;
         }
         
         if(ped_red){
            setLED(PED_RED,OFF);
            ped_red=false;
         }
         
         if(!ped_green){
            setLED(PED_GREEN,ON);
            ped_green=true;
         }

         delay(15000);
         if(!ped_red){
            setLED(PED_RED,ON);
            ped_red=true;
         }
         
         if(ped_green){
            setLED(PED_GREEN,OFF);
            ped_green=false;
         }


         if(red_ns){
            setLED(RED_NS, OFF);
            red_ns=false;
         }

         stateI = 0;
         goto_prev_state();

      }
   }
   return 0;
}