#include "leds.h"

#define LSB          0x0001 // bit numero 1 en 1, bit menos significactivo
#define LED_OFFSET   1      // Define la numeracion de los bits
#define ALL_LEDS_OFF 0x0000 // Define el apagado de todos los leds
#define ALL_LEDS_ON  0xFFFF // Define el encendido de todos los leds

static uint16_t * puerto; // Variable privada para almacenar el puerto

/**
 * @brief Se genera la mascara para la posicion de los leds
 *
 * @param led numero de led
 *
 * @return uint16_t
 *
 */
static uint16_t LedToMask(int led) {
    return LSB << (led - LED_OFFSET);
}

void LedsCreate(uint16_t * direccion) {
              puerto = direccion;
                *puerto = ALL_LEDS_OFF;
}

void LedsSetOn(int led) {
    *puerto |= LedToMask(led);
}

void LedsSetOff(int led) {
    *puerto &= ~LedToMask(led);
}

void LedsSetAllOn(void) {
    *puerto = ALL_LEDS_ON;
}

void LedsSetAllOff(void) {
    *puerto = ALL_LEDS_OFF;
}

bool LedIsOn(int led) {
    return (LedToMask(led) & *puerto) ? true : false;
}
