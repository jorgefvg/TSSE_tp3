/*
 * delay.h
 *
 *  Created on: 02/10/2024
 *      Author: Jorge
 */

#ifndef DELAY_H
#define DELAY_H

#include "stdint.h"  // Para incluir el tipo uint32_t
#include "stdbool.h" // Para incluir el tipo bool_t

typedef uint32_t tick_t;
typedef bool bool_t;

// estructura para retardos no bloqueantes
typedef struct {
    tick_t startTime; // Marca de tiempo inicial
    tick_t duration;  // Duración del retardo
    bool_t running;   // Estado del retardo (en ejecución o no)
} delay_t;

/**
 * @brief Funcion que inicializa la estructura de retardo con la duración especificada
 *
 * @param delay estructura
 * @param duration valor de duracion del retardo
 *
 */
void delayInit(delay_t * delay, tick_t duration);

/**
 * @brief Funcion que lee el estado del retardo
 *
 * @param delay estructura
 * @return true si el retardo ha terminado
 * @return false si no ha terminado
 *
 */
bool_t delayRead(delay_t * delay);

/**
 * @brief Funcion que actualiza la duración del retardo con el valor especificado
 *
 * @param delay estructura
 * @param duration valor de duracion del retardo
 *
 */
void delayWrite(delay_t * delay, tick_t duration);
/* ========== ============================ ========== */

/**
 * @brief  Funcion que se ejecuta en caso de error
 *
 */
void ErrorHandler(void);

#endif /* DELAY_H */