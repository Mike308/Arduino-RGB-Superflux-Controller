// 
// 
// 

#include "RgbController.h"


RgbController::RgbController(uint8_t r_pin, uint8_t g_pin, uint8_t b_pin){
	
	r_ch = r_pin;
	g_ch = g_pin;
	b_ch = b_pin;
	
	
	
}

void RgbController::Set_RGB_Color(uint8_t r, uint8_t g, uint8_t b){

	analogWrite(r_ch,r);
	analogWrite(g_ch,g);
	analogWrite(b_ch,b);
		
}

void RgbController::Set_HSV_Color(uint16_t h,uint16_t s,uint16_t v){
	
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
	
	analogWrite(r_ch,red);
	analogWrite(g_ch,green);
	analogWrite(b_ch,blue);
	
}

void RgbController::Animation_Circuit_of_Color(unsigned long speed, uint8_t step, unsigned long current_millis){
	
	static int hue = 0;
	static unsigned long previous_millis = 0;
	if(hue<360){
		if(current_millis-previous_millis>=speed){
			previous_millis = current_millis;
			Set_HSV_Color(hue,100,100);
			hue += step;
			
			
		}
		}else{
		
		hue = 0;
	}
	
}

void RgbController::Animation_Switching_Colors(unsigned long speed, unsigned long current_millis){
	
	static unsigned long previous_millis = 0;
	if(current_millis-previous_millis>=speed){
		
		previous_millis = current_millis;
		
		int r = random(256);
		int g = random(256);
		int b = random(256);
		Set_RGB_Color(r,g,b);
		
	}
	
}

void RgbController::Animation_Display_Mode(uint8_t mode,unsigned long speed,uint8_t step, unsigned long current_millis){
	
	if(mode==3){
		
		Animation_Circuit_of_Color(speed,step,current_millis);
		
	}
	else if(mode==4){
		
		Animation_Switching_Colors(speed,current_millis);
	}
	
	
}

void RgbController::Command_Line(String str, t_animation * anim){
	
	char buf[200];
	str.toCharArray(buf,str.length());
		
	char *id = strtok(buf,"^");
	

	
	
	if(atoi(id)==1){
		char *h = strtok(NULL,"^");
		char *s = strtok(NULL,"^");
		char *v = strtok(NULL,"^");
		float	hF = atof(h);
		float	sF = atof(s);
		float	vF = atof(v);
		Set_HSV_Color(hF,sF,vF);
		
		
	}
	
	else if(atoi(id)==2){
		
		char * r = strtok(NULL,"^");
		char * g = strtok(NULL,"^");
		char * b = strtok(NULL,"^");
		uint8_t r_val = atoi(r);
		uint8_t g_val = atoi(g);
		uint8_t b_val = atoi(b);
		Set_RGB_Color(r_val,g_val,b_val);
		anim->mode = 0;
		
		
		
	}
	else if(atoi(id)==3){
		
		char *speed = strtok(NULL,"^");
		char *step = strtok(NULL,"^");
		uint8_t step_val = atoi(step);
		unsigned long speed_val = atol(speed);
		anim->mode = 3;
		anim->s = speed_val;
		anim->step = step_val;
		
	}
	else if(atol(id)==4){
		
		char *speed = strtok(NULL,"^");
		unsigned long speed_val = atol(speed);
		char *step = strtok(NULL,"^");
		uint8_t step_val = atoi(step);
		anim->mode = 4;
		anim->s = speed_val;
		
		
	}
	else if(atoi(id)==5){
		
		char *speed = strtok(NULL,"^");
		unsigned long speed_val = atol(speed);
		anim->mode = 5;
		anim->s = speed_val;
		
	}
	
}

