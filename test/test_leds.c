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
 *  7) Consultar el estado de un led que esta encendido      [v]
 *  8) Consultar el estado de un led que esta apagado        [v]
 *  9) Revisar limites de los parámetros                     [v]
 *  10) Revisar parámetros fuera de los parámetros           [v]   
 *  
 * */ 

#include "unity.h" 
#include "leds.h"

// valores generales para los tests 
#define LEDS_ALL_OFF            0x0000 
#define LEDS_ALL_ON             0xFFFF 
#define LEDS_ONE_TURN_ON_SELECT 3 
#define LEDS_VALUE_LED_ON       1 
///valores para test 4 
#define LEDS_ON_AND_OFF_TEST_4 7 
///valores para test 5 
#define LEDS_1_ALL_ON_TEST_5 7 
#define LEDS_2_ALL_ON_TEST_5 8 
///valores para test 6 

#define LEDS_1_ALL_OFF_TEST_6 1 
#define LEDS_2_ALL_OFF_TEST_6 15 

///valores para test 7 

#define LEDS_STATE_ON_LED_NUMBER_TEST_7 10 
#define LEDS_STATE_OFF_LED_NUMBER_TEST_7 10 

///valores para test 9 

#define LEDS_MIN_NUMBER_TEST_9 16 
#define LEDS_MAX_NUMBER_TEST_9 1 

///valores para test 10 
#define LEDS_OUT_OF_RANGE_1_TEST_10 221
#define LEDS_OUT_OF_RANGE_2_TEST_10 -5


uint16_t leds_virtuales = LEDS_ALL_ON ; 
void setUp(void){ 
    LedsCreate(&leds_virtuales) ; 

}


 //1) Con la inicialización todos los leds quedan apagados 
void test_todos_los_leds_inician_apagados(void){ 
    uint16_t leds_virtuales = LEDS_ALL_ON ; 
    LedsCreate(&leds_virtuales) ; 
    TEST_ASSERT_EQUAL(LEDS_ALL_OFF,leds_virtuales) ; 
}

//  2) Prender un led individual 

void test_prender_led_individual(void){ 
    LedsSingleTurnOn(LEDS_ONE_TURN_ON_SELECT) ; 
    TEST_ASSERT_EQUAL(LEDS_VALUE_LED_ON<<(LEDS_ONE_TURN_ON_SELECT-1),leds_virtuales) ; 
}


//3) Apagar led individual 
void test_apagar_led_individual(void){ 
   
    LedsSingleTurnOn(LEDS_ONE_TURN_ON_SELECT) ; 
    LedsSingleTurnOff(LEDS_ONE_TURN_ON_SELECT) ; 
    TEST_ASSERT_EQUAL(LEDS_ALL_OFF,leds_virtuales) ; 
}

//4 prender y apagar multiples leds 
void test_apagar_multiples_leds(void){ 
  
    LedsSingleTurnOn(LEDS_ONE_TURN_ON_SELECT) ; 
    LedsSingleTurnOn(LEDS_ON_AND_OFF_TEST_4) ; 

    LedsSingleTurnOff(LEDS_ON_AND_OFF_TEST_4) ;    
    TEST_ASSERT_EQUAL(LEDS_VALUE_LED_ON<<(LEDS_ONE_TURN_ON_SELECT-1),leds_virtuales) ; 
}



//5 Prender todos los leds de una vez
void test_prender_todos_los_leds(void){ 
    LedsSingleTurnOn(LEDS_1_ALL_ON_TEST_5) ; 
    LedsSingleTurnOn(LEDS_2_ALL_ON_TEST_5) ; 
    LedsTurnOnAll()                          ;     

    TEST_ASSERT_EQUAL(LEDS_ALL_ON,leds_virtuales) ; 
}


//6 Apagar todos los leds de una vez  
void test_apagar_todos_los_leds(void){ 
    LedsSingleTurnOn(LEDS_1_ALL_OFF_TEST_6)   ; 
    LedsSingleTurnOn(LEDS_2_ALL_OFF_TEST_6)  ; 
    LedsTurnOffAll()      ; 
    TEST_ASSERT_EQUAL(LEDS_ALL_OFF,leds_virtuales) ;
    
}

//7) Consultar el estado de un led que esta encendido 
void test_consultar_estado_led_encendido(void){ 
    uint8_t led_on =  0   ; 
    LedsSingleTurnOn(LEDS_STATE_ON_LED_NUMBER_TEST_7)  ; 
    led_on = LedsState(LEDS_STATE_ON_LED_NUMBER_TEST_7) ; 
    TEST_ASSERT_EQUAL(1,led_on) ; 
}


//7) Consultar el estado de un led que esta encendido 
void test_consultar_estado_led_apagado(void){ 
    uint8_t led_on =  1    ; 
    LedsTurnOnAll()        ;  
    LedsSingleTurnOff(LEDS_STATE_OFF_LED_NUMBER_TEST_7)  ; 
    led_on = LedsState(LEDS_STATE_OFF_LED_NUMBER_TEST_7) ; 
    TEST_ASSERT_EQUAL(0,led_on) ; 
}

// 9) Revisar limites de los parámetros 


void test_limites_de_parametros_leds_prendidos(void){ 
    LedsSingleTurnOn(LEDS_MIN_NUMBER_TEST_9) ; 
    LedsSingleTurnOn(LEDS_MAX_NUMBER_TEST_9) ; 
    TEST_ASSERT_EQUAL( 1<<0| 1<<15,leds_virtuales) ; 
}

void test_limites_de_parametros_leds_apagados(void){ 

    LedsSingleTurnOn(LEDS_MIN_NUMBER_TEST_9) ; 
    LedsSingleTurnOn(LEDS_MAX_NUMBER_TEST_9) ; 
    LedsSingleTurnOff(LEDS_MIN_NUMBER_TEST_9) ; 
    LedsSingleTurnOff(LEDS_MAX_NUMBER_TEST_9) ; 
    TEST_ASSERT_EQUAL( 0<<0 | 0<<15,leds_virtuales) ; 
}


// 10) Revisar parámetros fuera de los parámetros           [v]   

void test_limites_de_fuera_rango(void){ 
    uint16_t leds_copy_virtuales = leds_virtuales  ; ///copia para ver que no se haya modificado nada 
    LedsSingleTurnOn(LEDS_OUT_OF_RANGE_1_TEST_10) ; 
    LedsSingleTurnOn(LEDS_OUT_OF_RANGE_2_TEST_10) ; 
    TEST_ASSERT_EQUAL(leds_copy_virtuales,leds_virtuales) ;  
}