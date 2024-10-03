#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Funcion de inicializacion de los leds, se inicializan todos apagados
 *
 * @param direccion Puntero a la direccion del puerto
 *
 */
void LedsCreate(uint16_t * direccion);

/**
 * @brief Funcion que enciende el led pasado como parametro
 *
 * @param led numero de led que se quiere encender
 *
 */
void LedsSetOn(int led);

/**
 * @brief Funcion que apaga el led pasado como parametro
 *
 * @param led numero de led que se quiere apagar
 *
 */
void LedsSetOff(int led);

/**
 * @brief Funcion para encender todos los leds
 *
 */
void LedsSetAllOn(void);

/**
 * @brief Funcion para apagar todos los leds
 *
 */
void LedsSetAllOff(void);

/**
 * @brief Funcion que verificar que el led pasado como parametro esta encendido
 *
 * @param led numero de led que se quiere verificar
 * @return true Si el led esta encendido
 * @return false Si el led esta apagado
 *
 */
bool LedIsOn(int led);

#endif /* LEDS_H */
