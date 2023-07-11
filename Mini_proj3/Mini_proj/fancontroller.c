#include "LCD.h"
#include "ADC.h"
#include "lm35_sensor.h"
#include "DC_motor.h"
#include "My_GPIO.h"
#include "std_types.h"
#include "common_macros.h"
int main(void)
{
	uint8 Temp;
	ADC_ConfigType ADC_configuration={internal_v,F_CPU_8};
	SetupPinDirection(PORTD_ID,PIN1_ID,OUTPUT_PIN);
	Write_Pin(PORTD_ID,PIN1_ID,LOGIC_LOW);
	LCD_init();
	ADC_init(&ADC_configuration);
	DcMotor_Init();
	LCD_displayStringRowColumn(0,4,"Fan is    ");
	LCD_displayStringRowColumn(1,4,"Temp=     C");
	while(1)
	{
		Temp =LM35_getTemperature();

		//less than 30c
		if(Temp<30)
		{
			DcMotor_Rotate(OFF,0);
			LCD_displayStringRowColumn(0,11,"OFF ");
			LCD_moveCursor(1,10);
			if(Temp >= 1000)
			{
				LCD_intgerToString(Temp);
			}
			else
			{
				LCD_intgerToString(Temp);
				LCD_sendCharacter(' ');
			}
		}

		//equal or greater then 30c or and less then 60c
		if((Temp>=30) && (Temp<60))
		{
			DcMotor_Rotate(CW,64);
			LCD_displayStringRowColumn(0,11,"ON   ");
			LCD_moveCursor(1,10);
			if(Temp >= 1000)
			{
				LCD_intgerToString(Temp);
			}
			else
			{
				LCD_intgerToString(Temp);
				LCD_sendCharacter(' ');
			}}


		//equal or greater then 60c or and less then 90c
		if((Temp>=60) && (Temp<90))
		{
			DcMotor_Rotate(CW,128);
			LCD_displayStringRowColumn(0,11,"ON   ");
			LCD_moveCursor(1,10);
			if(Temp >= 1000)
			{
				LCD_intgerToString(Temp);
			}
			else
			{
				LCD_intgerToString(Temp);
				LCD_sendCharacter(' ');
			}
		}

		//equal or greater then 90c or and less then 120c
		if((Temp>=90) && (Temp<120))
		{
			DcMotor_Rotate(CW,192);
			LCD_displayStringRowColumn(0,11,"ON   ");
			LCD_moveCursor(1,10);
			if(Temp >= 1000)
			{
				LCD_intgerToString(Temp);
			}
			else
			{
				LCD_intgerToString(Temp);
				LCD_sendCharacter(' ');
			}
		}

		//equal or greater then 120c
		if((Temp>=120))
		{
			DcMotor_Rotate(CW,255);
			LCD_displayStringRowColumn(0,11,"ON   ");
			LCD_moveCursor(1,10);
			if(Temp >= 1000)
			{
				LCD_intgerToString(Temp);
			}
			else
			{
				LCD_intgerToString(Temp);
				LCD_sendCharacter(' ');
			}
		}
	}
}

