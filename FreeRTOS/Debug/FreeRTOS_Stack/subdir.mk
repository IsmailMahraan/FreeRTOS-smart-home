################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Stack/croutine.c \
../FreeRTOS_Stack/heap_1.c \
../FreeRTOS_Stack/list.c \
../FreeRTOS_Stack/port.c \
../FreeRTOS_Stack/queue.c \
../FreeRTOS_Stack/tasks.c \
../FreeRTOS_Stack/timers.c 

OBJS += \
./FreeRTOS_Stack/croutine.o \
./FreeRTOS_Stack/heap_1.o \
./FreeRTOS_Stack/list.o \
./FreeRTOS_Stack/port.o \
./FreeRTOS_Stack/queue.o \
./FreeRTOS_Stack/tasks.o \
./FreeRTOS_Stack/timers.o 

C_DEPS += \
./FreeRTOS_Stack/croutine.d \
./FreeRTOS_Stack/heap_1.d \
./FreeRTOS_Stack/list.d \
./FreeRTOS_Stack/port.d \
./FreeRTOS_Stack/queue.d \
./FreeRTOS_Stack/tasks.d \
./FreeRTOS_Stack/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Stack/%.o: ../FreeRTOS_Stack/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


