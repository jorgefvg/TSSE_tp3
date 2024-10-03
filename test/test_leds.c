#include "unity.h"
#include "leds.h"

static uint16_t puerto_virtual;

/**
 * @brief Funcion que se ejecuta antes de cada prueba
 *
 */
void setUp(void) {
    LedsCreate(&puerto_virtual);
}

/**
 * @brief Funcion que se ejecuta despues de cada prueba
 *
 */
void tearDown(void) {
}

/**
 * @brief Test 1: AL arrancar el sistema, todos los leds se quedan apagados
 *
 */
void test_todos_los_leds_inician_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF;

    LedsCreate(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Test 2: Prender un LED individual
 *
 */
void test_prender_un_led_individual(void) {
    LedsSetOn(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

/**
 * @brief Test 3: Prender y apagar un LED individual
 *
 */
void test_prender_y_apagar_un_led_individual(void) {
    LedsSetOn(3);
    LedsSetOff(3);

    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Test 4: Prender y apagar múltiples LED’s
 *
 */
void test_prender_y_apagar_varios_leds(void) {
    LedsSetOn(7);
    LedsSetOn(5);
    LedsSetOff(2);
    LedsSetOff(7);

    TEST_ASSERT_EQUAL_HEX16(1 << 4, puerto_virtual);
}

/**
 * @brief Test 5: Prender todos los LEDs de una vez
 *
 */
void test_prender_todos_los_leds_juntos(void) {
    LedsSetAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

/**
 * @brief Test 6: Apagar todos los LEDs de una vez
 *
 */
void test_apagar_todos_los_leds_juntos(void) {
    LedsSetAllOff();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Test 7: Consultar el estado de un LED que está encendido
 *
 */
void test_consultar_estado_led_encendido(void) {
    LedsSetOn(10);
    TEST_ASSERT_TRUE(LedIsOn(10));
}

/**
 * @brief Test 8: Consultar el estado de un LED que esta apagado
 *
 */
void test_consultar_estado_led_apagado(void) {
    TEST_ASSERT_FALSE(LedIsOn(14));
}
