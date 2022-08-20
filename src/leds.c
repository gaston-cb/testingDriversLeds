#include <leds.h>
#define LEDS_INIT       0x0000
#define LEDS_ALL_ON     0xFFFF 
#define LEDS_ALL_OFF (LEDS_INIT)
#define LEDS_NUMBER_OFFSET 1
#define FIRST_BIT_ON       1 

static int16_t *puerto ; 



static uint16_t LedsToMask(uint8_t number_led) { 
    return (FIRST_BIT_ON<<(number_led-LEDS_NUMBER_OFFSET)) ; 
}


void LedsCreate(uint16_t *address){ 
    puerto = address ; 
    *puerto = LEDS_INIT ; 
}

void LedsSingleTurnOn(uint8_t number_led){   
    *puerto |= LedsToMask(number_led) ; 
}

void LedsSingleTurnOff(uint8_t number_led){ 
    *puerto &= ~LedsToMask(number_led) ; 
}


void LedsTurnOffAll(){ 
    *puerto = LEDS_ALL_OFF ; 
}

void LedsTurnOnAll(){ 
    *puerto = LEDS_ALL_ON ; 
}