/*
 * debounce.c
 *
 *  Created on: 02/10/2024
 *      Author: Jorge
 */

#include "hal.h"
#include "delay.h"
#include "debounce.h"

#define DEBOUNCE_PERIOD 40

// estructura para los estados del boton
typedef enum {
    BUTTON_UP,      // Botón suelto
    BUTTON_FALLING, // Apretando botón
    BUTTON_DOWN,    // Boton precionado
    BUTTON_RAISING, // Soltando botón
} debounceState_t;

bool_t pressed;
delay_t delayDebounceFSM;    // Estructura para control de tiempos
debounceState_t actualState; // Variable de estado (global) interna de Maquina de Estados

void debounceFSM_init(void) {
    actualState = BUTTON_UP;
    BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
    delayInit(&delayDebounceFSM, DEBOUNCE_PERIOD); // control de tiempos para debounce
}

int debounceFSM_update(void) {
    switch (actualState) {
    case BUTTON_UP:
        if (BSP_PB_GetState(BUTTON_USER)) {
            actualState = BUTTON_FALLING; // estado siguiente
            delayRead(&delayDebounceFSM); // inicia la cuenta de antirrebote
        }
        return (actualState);
        break;
    case BUTTON_FALLING:
        if (delayRead(&delayDebounceFSM)) // control de tiempo de antirrebote
        { // pasado el tiempo de antirebote se controla el estado del pulsador
            if (BSP_PB_GetState(BUTTON_USER)) { // si sigue presionado se pasa al siguinte estado
                actualState = BUTTON_DOWN;
                pressed = true; // estado presionado
            } else              // si se detecta estado inestable del pulsador
            {
                actualState = BUTTON_UP; // regreso al estado previo
            }
        }
        return (actualState);
        break;
    case BUTTON_DOWN:
        if (!BSP_PB_GetState(
                BUTTON_USER)) { // si el pulsador se libera se regresa al estado anterior
            actualState = BUTTON_RAISING;
            delayRead(&delayDebounceFSM);
        }
        return (actualState);
        break;
    case BUTTON_RAISING:
        if (delayRead(&delayDebounceFSM)) // control de tiempo de antirrebote
        { // pasado el tiempo de antirebote se controla el estado del pulsador
            if (!BSP_PB_GetState(BUTTON_USER)) { //  si se libera se pasa al siguiente estado
                actualState = BUTTON_UP;
                pressed = false; // NO presionado
            } else               // si se detecta estado inestable del pulsador
            {
                actualState = BUTTON_DOWN; // regreso al estado previo
            }
        }
        return (actualState);
        break;
    default:
        // si se carga algun valor no contemplado, se regresa al estado inicial
        actualState = BUTTON_UP;
        break;
    }
}

const bool_t readKey() {
    bool_t flag = false;
    if (pressed) {
        flag = true;
        pressed = false;
    }
    return flag;
}