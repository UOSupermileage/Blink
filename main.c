/*
Pico Blinker Project
Author: Dan Shan
Date: 2026-10-09

template blink code for raspberry pi pico
*/
#include <stdio.h>
#include "pico/stdlib.h"

// Include if pico W detected
#ifdef CYW43_WL_GPIO_LED_PIN
#include "pico/cyw43_arch.h"
#endif

// Blink on / off time: 500ms each
const uint LED_DELAY_MS = 500;

// Regular Pico: GPIO 25 (otherwise, W: use CYW43_WL_GPIO_LED_PIN)
const uint LED_PIN = 25;

// Initialize pin
void init_pins() {
    // initialize the pins
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}
int main() {
    init_pins();
    while (1) {
        gpio_put(LED_PIN, 1);
        sleep_ms(LED_DELAY_MS);
        gpio_put(LED_PIN, 0);
        sleep_ms(LED_DELAY_MS);
    }
}
