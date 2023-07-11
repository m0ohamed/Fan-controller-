
#include <util/delay.h>
#include "lm35_sensor.h"
#include "ADC.h"


uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;
#if(ADC_MODE==ADC_pooling_mode)

		uint16 adc_value=0;
	adc_value=ADC_readChannel(SENSOR_CHANNEL_ID);
#endif
#if(ADC_MODE==ADC_interrupt_mode)

	ADC_readChannel(SENSOR_CHANNEL_ID);
#endif
	_delay_ms(5);
#if(ADC_MODE==ADC_interrupt_mode)

	temp_value = (uint8)(((uint32)data*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
#endif

#if(ADC_MODE==ADC_pooling_mode)
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
#endif

	return temp_value;
}

