#include <leds.h>
#define MIN_VALUE_LED     1
#define MAX_VALUE_LED     16

#define LEDS_INIT       0x0000
#define LEDS_ALL_ON     0xFFFF 
#define LEDS_ALL_OFF (LEDS_INIT)
#define LEDS_NUMBER_OFFSET 1
#define FIRST_BIT_ON       1 

static uint16_t *puerto ; 

static bool isValidNumberLed(uint8_t number_led){ 
    bool response ; 
    if (number_led<MIN_VALUE_LED | number_led>MAX_VALUE_LED){
        response = false ; 
    }else{ 
         response = true ; 
    }
    return response ; 
}

static uint16_t LedsToMask(uint8_t number_led) { 
    return (FIRST_BIT_ON<<(number_led-LEDS_NUMBER_OFFSET)) ; 
}


void LedsCreate(uint16_t *address){ 
    puerto = address ; 
    *puerto = LEDS_INIT ; 
}

void LedsSingleTurnOn(uint8_t number_led){   
    if(isValidNumberLed(number_led) == false){
        return   ; 
    }
    *puerto |= LedsToMask(number_led) ; 
}

void LedsSingleTurnOff(uint8_t number_led){ 
    if(isValidNumberLed(number_led) == false) return ; 
    *puerto &= ~LedsToMask(number_led) ; 
}


void LedsTurnOffAll(){ 
    *puerto = LEDS_ALL_OFF ; 
}

void LedsTurnOnAll(){ 
    *puerto = LEDS_ALL_ON ; 
}

uint8_t LedsState(uint8_t number_led) { 
   if(isValidNumberLed(number_led) == false){
       return -1; 
   }
   uint16_t LedsState = (*puerto) & LedsToMask(number_led) ;
   return LedsState ? 1 : 0; 
}