#include "RgbController.h"
/*
 * RGB_PWM_LAMP.ino
 *
 * Created: 12/17/2016 2:48:00 PM
 * Author: Mike
 */ 


#define R 5
#define G 6
#define B 3




String receive_string = " ";
bool check_if_string_is_complete;
unsigned long current_millis;
//unsigned long previous_millis;





RgbController rgb_controller(R,G,B);



void setup()
{

	  /* add setup code here, setup code runs once when the processor starts */
	  pinMode(R,OUTPUT);
	  pinMode(G,OUTPUT);
	  pinMode(B,OUTPUT);
	  Serial.begin(9600);
	  receive_string.reserve(200);
	  

}

void loop()
{

	  /* add main program code here, this code starts again each time it ends */
	  
	 current_millis = millis();
	  
	  
	  
	  if(check_if_string_is_complete==true){
		  
		 // Serial.print(receive_string);
		  rgb_controller.Command_Line(receive_string,&rgb_controller.animation);
		    
		    	  
		  receive_string = "";
		  check_if_string_is_complete = false;
		  
		  
		  
		  
	  }
	  
	  rgb_controller.Animation_Display_Mode(rgb_controller.animation.mode,rgb_controller.animation.s,rgb_controller.animation.step,current_millis);
	  
	  

	  
	  
	  
	  

}





void serialEvent(){
	
	while(Serial.available()){
		
		char c = (char)(Serial.read());
		receive_string += c;
		
		if(c == '\n'){
			
			check_if_string_is_complete = true;
			
		}
		
	}
	
	
}






		
		
		
	
	
	 
	 
	
	

