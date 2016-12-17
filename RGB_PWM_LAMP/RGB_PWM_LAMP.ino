/*
 * RGB_PWM_LAMP.ino
 *
 * Created: 12/17/2016 2:48:00 PM
 * Author: Mike
 */ 


#define R 5
#define G 6
#define B 3

void setup()
{

	  /* add setup code here, setup code runs once when the processor starts */
	  pinMode(R,OUTPUT);
	  pinMode(G,OUTPUT);
	  pinMode(B,OUTPUT);

}

void loop()
{

	  /* add main program code here, this code starts again each time it ends */
	  analogWrite(B,255);
	  analogWrite(R,128);
	  analogWrite(G,120);

}
