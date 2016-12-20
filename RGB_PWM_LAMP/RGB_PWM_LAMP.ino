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


//typedef struct {
	//
	//uint8_t mode;
	//unsigned long s;
	//uint8_t step;
	//
//} t_animation;

//void Set_HSV_Color(uint16_t h,uint16_t s,uint16_t v);
//void Set_RGB_Color(uint8_t r, uint8_t g, uint8_t b);
//void Command_Line(String str, t_animation * anim);
//void Animation_Circuit_of_Color(unsigned long speed, uint8_t step);
//void Animation_Switching_Colors(unsigned long speed);
//void Animation_Array_of_Colors(unsigned long speed);

String receive_string = " ";
bool check_if_string_is_complete;
unsigned long current_millis;
//unsigned long previous_millis;



//t_animation animation;

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

//void Set_RGB_Color(uint8_t r, uint8_t g, uint8_t b){
	//
	//
	//analogWrite(R,r);
	//analogWrite(G,g);
	//analogWrite(B,b);
	//
	//
//}


/** MODIFIED FUNCTION FROM ws2812b library (http://mikrocontroller.bplaced.net/wordpress/?page_id=3665)**/


//void Set_HSV_Color(uint16_t h,uint16_t s,uint16_t v)
//{
	//uint8_t diff;
	//
	//byte red,green,blue;
//
	//if(h>359) h=359;
	//if(s>100) s=100;
	//if(v>100) v=100;
//
	//if(h < 61) {
			//red = 255;
			//green = (425 * h) / 100;
			//blue = 0;
		//}else if(h < 121){
			//red = 255 - ((425 * (h-60))/100);
			//green = 255;
			//blue = 0;
		//}else if(h < 181){
			//red = 0;
			//green = 255;
			//blue = (425 * (h-120))/100;
		//}else if(h < 241){
			//red = 0;
			//green = 255 - ((425 * (h-180))/100);
			//blue = 255;
		//}else if(h < 301){
			//red = (425 * (h-240))/100;
			//green = 0;
			//blue = 255;
		//}else {
			//red = 255;
			//green = 0;
			//blue = 255 - ((425 * (h-300))/100);
	//}
//
	//s = 100 - s;
	//diff = ((255 - red) * s)/100;
	//red =	red + diff;
	//diff = ((255 - green) * s)/100;
	//green = green + diff;
	//diff = ((255 - blue) * s)/100;
	//blue = blue + diff;
//
	//red = (red * v)/100;
	//green = (green * v)/100;
	//blue = (blue * v)/100;
	//
	//analogWrite(R,red);
	//analogWrite(G,green);
	//analogWrite(B,blue);
//
//}
//
//

//
//
//void Animation_Display_Mode(uint8_t mode,unsigned long speed,uint8_t step){
	//
	//if(mode==3){
		//
		//Animation_Circuit_of_Color(speed,step);				
		//
	//}
	//else if(mode==4){
		//
		//Animation_Switching_Colors(speed);
	//}
	//else if(mode==5){
		//
		//Animation_Array_of_Colors(speed);
		//
	//}
	//
//}
//
//void Animation_Circuit_of_Color(unsigned long speed, uint8_t step){
	//
		//static int hue = 0;
		//if(hue<360){
			//if(current_millis-previous_millis>=speed){
			//previous_millis = current_millis;
			//Set_HSV_Color(hue,100,100);
			//hue += step;
		//
		//
			//}
		//}else{
			//
			//hue = 0;
		//}
	//
//}
//
//
//void Animation_Switching_Colors(unsigned long speed){
	//
	//
	//
	//if(current_millis-previous_millis>=speed){
		//
		//previous_millis = current_millis;
		//
		//int r = random(256);
		//int g = random(256);
		//int b = random(256);
		//Set_RGB_Color(r,g,b);
		//
	//}
	//
	//
//}




void serialEvent(){
	
	while(Serial.available()){
		
		char c = (char)(Serial.read());
		receive_string += c;
		
		if(c == '\n'){
			
			check_if_string_is_complete = true;
			
		}
		
	}
	
	
}






		
		
		
	
	
	 
	 
	
	

