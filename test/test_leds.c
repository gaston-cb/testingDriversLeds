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
 *  1) Con la inicialización todos los leds quedan apagados  [v]
 *  2) Prender un led individual                             [v]
 *  3) Apagar un led individual                              [v]
 *  4) Prender y apagar multiples leds                       [v]
 *  5) Prender todos los leds de una vez                     [v]
 *  6) Apagar todos los leds de una vez                      [v]   
 *  7) Consultar el estado de un led que esta encendido 
 *  8) Consultar el estado de un led que esta apagado
 *  9) Revisar limites de los parámetros 
 *  10) Revisar parámetros fuera de los parámetros 
 *  
 * */ 

#include "unity.h" 
#include "leds.h"


#define LEDS_ALL_OFF            0x0000 
#define LEDS_ALL_ON             0xFFFF 
#define LEDS_ONE_TURN_ON_SELECT 3 


uint16_t leds_virtuales = LEDS_ALL_ON ; 
void setUp(void){ 
    LedsCreate(&leds_virtuales) ; 

}


 //1) Con la inicialización todos los leds quedan apagados 
void test_todos_los_leds_inician_apagados(void){ 
    uint16_t leds_virtuales = 0xFFFF ; 
    LedsCreate(&leds_virtuales) ; 
    TEST_ASSERT_EQUAL(LEDS_ALL_OFF,leds_virtuales) ; 
}

//  2) Prender un led individual 

void test_prender_led_individual(void){ 
    LedsSingleTurnOn(LEDS_ONE_TURN_ON_SELECT) ; 
    TEST_ASSERT_EQUAL(1<<(LEDS_ONE_TURN_ON_SELECT-1),leds_virtuales) ; 
}


//3) Apagar led individual 
void test_apagar_led_individual(void){ 
   
    LedsSingleTurnOn(LEDS_ONE_TURN_ON_SELECT) ; 
    LedsSingleTurnOff(LEDS_ONE_TURN_ON_SELECT) ; 
    TEST_ASSERT_EQUAL(0x00,leds_virtuales) ; 
}


//4 prender y apagar multiples leds 
void test_apagar_multiples_leds(void){ 
  
    LedsSingleTurnOn(LEDS_ONE_TURN_ON_SELECT) ; 
    LedsSingleTurnOn(7) ; 

    LedsSingleTurnOff(7) ;    
    TEST_ASSERT_EQUAL(1<<2,leds_virtuales) ; 
}

//5 Prender todos los leds de una vez
void test_prender_todos_los_leds(void){ 
    LedsSingleTurnOn(7) ; 
    LedsSingleTurnOn(8) ; 
    LedsTurnOffAll() ; 
    TEST_ASSERT_EQUAL(0,leds_virtuales) ; 
}


//6 A pagar todos los leds de una vez  
void test_apagar_todos_los_leds(void){ 
    LedsSingleTurnOn(1)   ; 
    LedsSingleTurnOn(15)  ; 
    LedsTurnOnAll()       ; 
    TEST_ASSERT_EQUAL(0xFFFF,leds_virtuales) ;
    
}

//7) Consultar el estado de un led que esta encendido 
void test_consultar_estado_led_encendido(void){ 
    
}