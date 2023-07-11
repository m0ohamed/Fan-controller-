################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DC_motor.c \
../LCD.c \
../My_GPIO.c \
../PWM.c \
../fancontroller.c \
../lm35_sensor.c 

OBJS += \
./ADC.o \
./DC_motor.o \
./LCD.o \
./My_GPIO.o \
./PWM.o \
./fancontroller.o \
./lm35_sensor.o 

C_DEPS += \
./ADC.d \
./DC_motor.d \
./LCD.d \
./My_GPIO.d \
./PWM.d \
./fancontroller.d \
./lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


