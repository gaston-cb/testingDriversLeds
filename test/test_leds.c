/**
 * @file test_leds.c
 * @author gaston valdez (gaston.cb.90@gmail.com)
 * @brief  Test de drivers de leds para la catedra testing de software 
 * @version 1.0
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/**
 * ---- Test realizados en el siguiente orden --------------- 
 *  1) Con la inicialización todos los leds quedan apagados 
 *  2) Prender un led individual 
 *  3) Prender y apagar multiples leds 
 *  4) Consultar el estado de un led que esta encendido 
 *  5) Consultar el estado de un led que esta apagado
 *  6) Revisar limites de los parámetros 
 *  7) Revisar parámetros fuera de los parámetros 
 *  
 * */ 

#include "unity.h" 
#include "leds.h"


#define LEDS_ALL_OFF 0x0000 
#define LEDS_ALL_ON 0xFFFF 
#define LEDS_ONE_TURN_ON_SELECT 3 

 //1) Con la inicialización todos los leds quedan apagados 
void test_todos_los_leds_inician_apagados(void){ 
    uint16_t leds_virtuales = LEDS_ALL_ON ; 
    LedsCreate(&leds_virtuales) ; 
    TEST_ASSERT_EQUAL(LEDS_ALL_OFF,leds_virtuales) ; 
}

//  2) Prender un led individual 

void test_prender_led_individual(void){ 
    uint16_t leds_virtuales ; 
    LedsCreate(&leds_virtuales) ; 
    LedsSingleTurnOn(LEDS_ONE_TURN_ON_SELECT) ; 

    TEST_ASSERT_EQUAL(1<<(LEDS_ONE_TURN_ON_SELECT-1),leds_virtuales) ; 
}