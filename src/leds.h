#include <stdint.h>
#include <stdbool.h>
void LedsCreate(uint16_t *address) ; 
void LedsSingleTurnOn(uint8_t number_led) ; 

void LedsSingleTurnOff(uint8_t number_led) ; 
void LedsTurnOffAll()  ; 
void LedsTurnOnAll()   ; 
/**
 * @brief mira el estado de un led 
 * 
 * @param number_led 
 * @return uint8_t -1 -> number_led fuera de rango 
 *                  0 o 1 estado del led consultado 
 */                
uint8_t LedsState(uint8_t number_led) ; 