// RgbController.h

#ifndef _RGBCONTROLLER_h
#define _RGBCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class RgbController{
	
	public:
	
		RgbController(uint8_t r_pin, uint8_t g_pin, uint8_t b_bin);
			typedef struct {
				
				uint8_t mode;
				unsigned long s;
				uint8_t step;
				
			} t_animation;
		t_animation animation;
		void Animation_Display_Mode(uint8_t mode,unsigned long speed,uint8_t step, unsigned long current_time);
		void Set_HSV_Color(uint16_t h,uint16_t s,uint16_t v);
		void Set_RGB_Color(uint8_t r, uint8_t g, uint8_t b);
		void Command_Line(String str, t_animation * anim);
	
	private:
		uint8_t r_ch,g_ch,b_ch;
		
		
		void Animation_Circuit_of_Color(unsigned long speed, uint8_t step, unsigned long current_millis);
		void Animation_Switching_Colors(unsigned long speed, unsigned long current_millis);
		
	
	
	
	
	
	
};



	

	

