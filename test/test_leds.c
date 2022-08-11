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


void test_primer_test_que_falla(void){ 
    TEST_FAIL_MESSAGE("EMPEZAMOS")  ; 
}