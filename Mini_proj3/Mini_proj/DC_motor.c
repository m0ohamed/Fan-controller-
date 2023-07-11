#include "DC_motor.h"
#include "PWM.h"

void DcMotor_Init(void)
{
	//make Motor pins output
	SetupPinDirection(DC_MOTOR_FIRST_PORT_ID,DC_MOTOR_FIRST_PIN_ID,OUTPUT_PIN);
	SetupPinDirection(DC_MOTOR_SECOND_PORT_ID,DC_MOTOR_SECOND_PIN_ID,OUTPUT_PIN);

//write the motor LOW to turn off it
	Write_Pin(DC_MOTOR_FIRST_PORT_ID,DC_MOTOR_FIRST_PIN_ID,LOGIC_LOW);
	Write_Pin(DC_MOTOR_SECOND_PORT_ID,DC_MOTOR_SECOND_PIN_ID,LOGIC_LOW);


}


void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
switch(state)
{
case OFF:
	// case Off mean that pins is low and pwm duty cycle 0
	Write_Pin(DC_MOTOR_FIRST_PORT_ID,DC_MOTOR_FIRST_PIN_ID,LOGIC_LOW);
		Write_Pin(DC_MOTOR_SECOND_PORT_ID,DC_MOTOR_SECOND_PIN_ID,LOGIC_LOW);
		PWM_Timer0_START(speed);
		break;
case CW:
	// case CW mean that one pin is high and pwm as you want

	Write_Pin(DC_MOTOR_FIRST_PORT_ID,DC_MOTOR_FIRST_PIN_ID,LOGIC_LOW);
		Write_Pin(DC_MOTOR_SECOND_PORT_ID,DC_MOTOR_SECOND_PIN_ID,LOGIC_HIGH);
		PWM_Timer0_START(speed);
		break;
case A_CW:
	// case CW mean that one pin is high and pwm as you want

	Write_Pin(DC_MOTOR_FIRST_PORT_ID,DC_MOTOR_FIRST_PIN_ID,LOGIC_HIGH);
		Write_Pin(DC_MOTOR_SECOND_PORT_ID,DC_MOTOR_SECOND_PIN_ID,LOGIC_LOW);
		PWM_Timer0_START(speed);
		break;
}
}

