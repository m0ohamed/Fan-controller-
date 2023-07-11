#include <avr/io.h>
#include <util/delay.h>
#include "common_macros.h"
#include "ADC.h"
//if interrupt mode --->>ISR+Global variable
#if(ADC_MODE==ADC_interrupt_mode)
#include <avr/interrupt.h>

volatile uint16  data=0;

ISR(ADC_vect)
{
	data=ADC;
}
#endif



//if pooling mode
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);//set the voltage
ADCSRA =(1<<ADEN);
ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr->prescaler);
}

#if(ADC_MODE==ADC_interrupt_mode)

void ADC_readChannel(uint8 channel)
{
	channel &= 0x07;
		ADMUX &= 0xE0;
		ADMUX = ADMUX | channel;
		SET_BIT(ADCSRA,6);


}
#endif

#if(ADC_MODE==ADC_pooling_mode)

uint16 ADC_readChannel(uint8 channel)
{
	channel &= 0x07;
		ADMUX &= 0xE0;
		ADMUX = ADMUX | channel;
		SET_BIT(ADCSRA,6);
	while(BIT_IS_CLEAR(ADCSRA,4));
	SET_BIT(ADCSRA,4);
	return ADC;
}
#endif
