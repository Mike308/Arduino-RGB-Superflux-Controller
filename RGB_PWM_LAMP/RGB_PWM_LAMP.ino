/*
 * RGB_PWM_LAMP.ino
 *
 * Created: 12/17/2016 2:48:00 PM
 * Author: Mike
 */ 


#define R 5
#define G 6
#define B 3



void HSVtoRGB(float h,float s,float v);




void setup()
{

	  /* add setup code here, setup code runs once when the processor starts */
	  pinMode(R,OUTPUT);
	  pinMode(G,OUTPUT);
	  pinMode(B,OUTPUT);
	  Serial.begin(9600);

}

void loop()
{

	  /* add main program code here, this code starts again each time it ends */
	HSVtoRGB(221,100,100);
	  

}


/** MODIFIED FUNCTION FROM ws2812b (http://mikrocontroller.bplaced.net/wordpress/?page_id=3665)**/


void HSVtoRGB(float h,float s,float v)
{
	uint8_t diff;
	
	byte red,green,blue;

	
	if(h>359) h=359;
	if(s>100) s=100;
	if(v>100) v=100;

	if(h < 61) {
			red = 255;
			green = (425 * h) / 100;
			blue = 0;
		}else if(h < 121){
			red = 255 - ((425 * (h-60))/100);
			green = 255;
			blue = 0;
		}else if(h < 181){
			red = 0;
			green = 255;
			blue = (425 * (h-120))/100;
		}else if(h < 241){
			red = 0;
			green = 255 - ((425 * (h-180))/100);
			blue = 255;
		}else if(h < 301){
			red = (425 * (h-240))/100;
			green = 0;
			blue = 255;
		}else {
			red = 255;
			green = 0;
			blue = 255 - ((425 * (h-300))/100);
	}

	s = 100 - s;
	diff = ((255 - red) * s)/100;
	red =	red + diff;
	diff = ((255 - green) * s)/100;
	green = green + diff;
	diff = ((255 - blue) * s)/100;
	blue = blue + diff;

	red = (red * v)/100;
	green = (green * v)/100;
	blue = (blue * v)/100;
	
	analogWrite(R,red);
	analogWrite(G,green);
	analogWrite(B,blue);
	Serial.print(red);
	Serial.print(",");
	Serial.print(green);
	Serial.print(",");
	Serial.println(blue);
}






		
		
		
	
	
	 
	 
	
	

