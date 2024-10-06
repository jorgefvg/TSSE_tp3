
/** @file test_debounce.c
 ** @brief Conjunto de tests para la API del boton.
 **/

/* === Headers files inclusions ===================================== */

#include "unity.h"
#include "debounce.h"
#include "mock_hal.h"
#include "mock_delay.h"

#define DEBOUNCE_PERIOD 40

typedef enum {
    BUTTON_UP,
    BUTTON_FALLING,
    BUTTON_DOWN,
    BUTTON_RAISING,
} debounceState_t;

extern delay_t delayDebounceFSM;
extern debounceState_t actualState;
extern bool_t pressed;

/**
 * @brief Funcion que se ejecuta antes de cada prueba
 *
 */
void setUp(void) {
}

/**
 * @brief Funcion que se ejecuta despues de cada prueba
 *
 */
void tearDown(void) {
}

/**
 * @brief Test 1: Al inicializar la maquina de estados actualState debe ser BUTTON_UP
 *
 */
void test_de_inicializacion_del_antirrebote(void) {

    BSP_PB_Init_Expect(BUTTON_USER, BUTTON_MODE_GPIO);
    delayInit_Expect(&delayDebounceFSM, DEBOUNCE_PERIOD);

    debounceFSM_init();
    // Se inicializa la FSM - variable actualState = BUTTON_UP
    TEST_ASSERT_EQUAL_INT(BUTTON_UP, actualState);
}

/**
 * @brief Test 2: Al presionar el boton, el estado actual debe cambiar a BUTTON_FALLING
 *
 */
void test_cambiar_a_estado_BUTTON_FALLING_del_antirrebote(void) {

    BSP_PB_Init_Expect(BUTTON_USER, BUTTON_MODE_GPIO);
    delayInit_Expect(&delayDebounceFSM, DEBOUNCE_PERIOD);

    debounceFSM_init();
    // Se inicializa la FSM - variable actualState = BUTTON_UP

    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, true);
    delayRead_ExpectAndReturn(&delayDebounceFSM, true);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_FALLING

    TEST_ASSERT_EQUAL_INT(BUTTON_FALLING, actualState);
}

/**
 * @brief Test 3: Al seguir presionado el boton, el estado actual debe cambiar a BUTTON_DOWN
 *
 */
void test_cambiar_a_estado_BUTTON_DOWN_del_antirrebote(void) {

    BSP_PB_Init_Expect(BUTTON_USER, BUTTON_MODE_GPIO);
    delayInit_Expect(&delayDebounceFSM, DEBOUNCE_PERIOD);

    debounceFSM_init();
    // Se inicializa la FSM - variable actualState = BUTTON_UP

    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, true);
    delayRead_ExpectAndReturn(&delayDebounceFSM, true);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_FALLING

    delayRead_ExpectAndReturn(&delayDebounceFSM, true);
    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, true);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_DOWN

    TEST_ASSERT_EQUAL_INT(BUTTON_DOWN, actualState);
}

/**
 * @brief Test 4: Al liberar el boton, el estado actual debe cambiar a BUTTON_RAISING
 *
 */
void test_cambiar_a_estado_BUTTON_RAISING_del_antirrebote(void) {

    BSP_PB_Init_Expect(BUTTON_USER, BUTTON_MODE_GPIO);
    delayInit_Expect(&delayDebounceFSM, DEBOUNCE_PERIOD);

    debounceFSM_init();
    // Se inicializa la FSM - variable actualState = BUTTON_UP

    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, true);
    delayRead_ExpectAndReturn(&delayDebounceFSM, true);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_FALLING

    delayRead_ExpectAndReturn(&delayDebounceFSM, true);
    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, true);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_DOWN

    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, false);
    delayRead_ExpectAndReturn(&delayDebounceFSM, false);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_RAISING

    TEST_ASSERT_EQUAL_INT(BUTTON_RAISING, actualState);
}

/**
 * @brief Test 5: Al liberar el boton, el estado actual debe cambiar a BUTTON_UP
 *
 */
void test_cambiar_a_estado_BUTTON_UP_apartir_del_estado_BUTTON_RAISING(void) {

    BSP_PB_Init_Expect(BUTTON_USER, BUTTON_MODE_GPIO);
    delayInit_Expect(&delayDebounceFSM, DEBOUNCE_PERIOD);

    debounceFSM_init();
    // Se inicializa la FSM - variable actualState = BUTTON_UP

    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, true);
    delayRead_ExpectAndReturn(&delayDebounceFSM, true);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_FALLING

    delayRead_ExpectAndReturn(&delayDebounceFSM, true);
    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, true);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_DOWN

    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, false);
    delayRead_ExpectAndReturn(&delayDebounceFSM, false);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_RAISING

    delayRead_ExpectAndReturn(&delayDebounceFSM, true);
    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, false);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_UP

    TEST_ASSERT_EQUAL_INT(BUTTON_UP, actualState);
}

/**
 * @brief Test 6: Al presionar el boton, el estado actual debe cambiar a BUTTON_FALLING
 *
 */
void test_Button_Pressed_del_antirrebote(void) {

    BSP_PB_Init_Expect(BUTTON_USER, BUTTON_MODE_GPIO);
    delayInit_Expect(&delayDebounceFSM, DEBOUNCE_PERIOD);

    debounceFSM_init();
    // Se inicializa la FSM - variable actualState = BUTTON_UP

    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, true);
    delayRead_ExpectAndReturn(&delayDebounceFSM, true);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_FALLING

    delayRead_ExpectAndReturn(&delayDebounceFSM, true);
    BSP_PB_GetState_ExpectAndReturn(BUTTON_USER, true);

    debounceFSM_update();
    // Se actualiza la FSM - variable actualState = BUTTON_DOWN

    TEST_ASSERT_EQUAL_INT(1, pressed);
}