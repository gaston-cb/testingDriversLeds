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

/*  Requisitos 
 1)Maneja 16 leds de dos estados (encendido y apagado).
 2) Se puede cambiar el estado de un led sin afectar a los otros.
 3) Se puede cambiar el estado de todos los led’s en una sola operación.
 4) Se puede recuperar el estado actual de un led.
 5) Los led’s están mapeados en una palabra de 16 bits en memoria en una dirección a determinar.
 6) Para encender el led se debe escribir un “1” en el bit y para apagarlo se debe escribir un “0”.
 7) El led 1 corresponde al lsb y el led 16 al msb.
 8) El reset de hardware no define un estado conocido de los led’s, estos deben ser apagados por software.
*/ 