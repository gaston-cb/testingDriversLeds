#include <leds.h>
#define LEDS_INIT 0x0000

uint16_t *puerto ; 

void LedsCreate(uint16_t *address){ 
    puerto = address ; 
    *puerto = LEDS_INIT ; 
}

void LedsSingleTurnOn(uint8_t number_led){ 
    
    *puerto = 4 ; 
}