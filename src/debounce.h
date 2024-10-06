/*
 * debounce.h
 *
 *  Created on: 02/10/2024
 *      Author: Jorge
 */

#ifndef DEBOUNCE_H
#define DEBOUNCE_H

#include "stdint.h"
#include "stdbool.h"

/**
 * @brief Funcion para cargar el estado inicial de la MEF debounce
 *
 */
void debounceFSM_init(void);

/**
 * @brief Funcion que se encarga de leer las entradas, resolver la logica de transicion de estados y
 * actualizar las salidas de la MEF debounce
 *
 * @return int
 */
int debounceFSM_update(void);

/**
 * @brief La función readKey debe leer una variable interna del módulo
 *
 * @return true Si devuelve true, se debe resetear (poner en false) el estado de la variable
 * @return false
 *
 */
bool readKey(void);

#endif /* DEBOUNCE_H */