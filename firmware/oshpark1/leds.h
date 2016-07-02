/*
 * This file is part of the Stenosaurus project.
 *
 * Copyright (C) 2016 Joshua Harlan Lifton
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STENOSAURUS_LEDS_H
#define STENOSAURUS_LEDS_H

#include <libopencm3/stm32/gpio.h>

/* Pin definitions for LEDs. */
#define LED1_PORT GPIOA
#define LED1_PINS (GPIO0 | GPIO1 | GPIO12)
#define LED2_PORT GPIOA
#define LED2_PINS (GPIO8 | GPIO9 | GPIO10)
#define LED3_PORT GPIOB
#define LED3_PINS (GPIO6 | GPIO7 | GPIO8)

/* Must be called once before any other function here. */
void leds_setup(void);

/* Turn all LEDs off if on, on if off. */
void leds_toggle(void);

/* Turn on all LEDs. */
void leds_on(void);

/* Turn off all LEDs. */
void leds_off(void);

/* Blink all LEDs the indicated number of times. */
void leds_blink(uint32_t n);

#endif
