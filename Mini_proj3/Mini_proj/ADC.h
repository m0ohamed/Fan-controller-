
#ifndef ADC_H
#define ADC_H
#include "std_types.h"
//configuration of ADC
#define ADC_interrupt_mode  0
#define ADC_pooling_mode    1

#define ADC_REF_VOLT_VALUE  2.56
#define ADC_MAXIMUM_VALUE   1023



#define ADC_MODE            ADC_pooling_mode


//enum for reference voltage 0 AREF.... 1 AVCC .......... 3   INternal 2.5v
typedef enum{
	AREF,AVCC,internal_v=3
}ADC_ReferenceVolatge;

//enum for prescaler
typedef enum{
	F_CPU_4=2,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

//struct passing to ADC init
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


//Interrupt mode
#if(ADC_MODE==ADC_interrupt_mode)
extern volatile uint16  data;
#endif

void ADC_init(const ADC_ConfigType * Config_Ptr);

#if (ADC_MODE==ADC_interrupt_mode)
void ADC_readChannel(uint8 channel);
#endif


#if (ADC_MODE==ADC_pooling_mode)
uint16 ADC_readChannel(uint8 channel);
#endif


#endif
