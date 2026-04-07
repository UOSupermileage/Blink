/*
Pico Blinker Project
Author: Dan Shan
Date: 2025-10-09

Introductory project for the UOSM team:
The goal of this project is to simulate the car’s turn signals (blinkers)

The Circuit:


Switches:
From Pico 3.3V out the switch runs to Pin 2 of the switch. Pin 1 and Pin 3 are connected back to the Pico in a GPIO pins.

LEDs:
From a GPIO pin on the Pico the current goes into a resistor, and from the resistor the LED Anode (long leg)
to Cathode (short leg). From there it runs down the negative rail of the breadboard and to Pico’s Ground.
*/
#include <stdio.h>
#include "pico/stdlib.h"

// Include if pico W detected
#ifdef CYW43_WL_GPIO_LED_PIN
#include "pico/cyw43_arch.h"
#endif

// Blink on / off time: 500ms each
const uint LED_DELAY_MS = 500;
// Switch left input pin: 19 -> GPIO 14
const uint SWITCH_LEFT = 14;
// Switch right input pin: 20 -> GPIO 15
const uint SWITCH_RIGHT = 15;
// Left blinker output pin: 21 -> GPIO 16
const uint LED_LEFT = 16;
// Right blinker output pin: 22 -> GPIO 17
const uint LED_RIGHT = 17;


// Initialize input and output pins
void init_pins() {
    // initialize the pins
    gpio_init(SWITCH_LEFT);
    gpio_init(SWITCH_RIGHT);
    gpio_init(LED_LEFT);
    gpio_init(LED_RIGHT);

    // Set I/O direction
    gpio_set_dir(SWITCH_LEFT, GPIO_IN);
    gpio_set_dir(SWITCH_RIGHT, GPIO_IN);
    gpio_set_dir(LED_LEFT, GPIO_OUT);
    gpio_set_dir(LED_RIGHT, GPIO_OUT);
}
// Run the left blinker
void blink_left(){
    gpio_put(LED_LEFT, 1);
    sleep_ms(LED_DELAY_MS);
    gpio_put(LED_LEFT, 0);
    sleep_ms(LED_DELAY_MS);
}
// Run the right blinker
void blink_right(){
    gpio_put(LED_RIGHT, 1);
    sleep_ms(LED_DELAY_MS);
    gpio_put(LED_RIGHT, 0);
    sleep_ms(LED_DELAY_MS);
}
int main() {
    init_pins();
    while(true) {
        if (gpio_get(SWITCH_LEFT)) blink_left();
        else if (gpio_get(SWITCH_RIGHT)) blink_right();
        else sleep_ms(200); // short pause between checks
    }
}