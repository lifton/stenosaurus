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

#include "leds.h"

void leds_setup(void)
{
  /* Set LED1 pins to 'output push-pull'. */
  gpio_set_mode(LED1_PORT, GPIO_MODE_OUTPUT_50_MHZ,
		GPIO_CNF_OUTPUT_PUSHPULL,
		LED1_PINS);

  /* Set LED2 pins to 'output push-pull'. */
  gpio_set_mode(LED2_PORT, GPIO_MODE_OUTPUT_50_MHZ,
		GPIO_CNF_OUTPUT_PUSHPULL,
		LED2_PINS);

  /* Set LED3 pins to 'output push-pull'. */
  gpio_set_mode(LED3_PORT, GPIO_MODE_OUTPUT_50_MHZ,
		GPIO_CNF_OUTPUT_PUSHPULL,
		LED3_PINS);
}

void leds_toggle(void)
{
  gpio_toggle(LED1_PORT, LED1_PINS);
  gpio_toggle(LED2_PORT, LED2_PINS);
  gpio_toggle(LED3_PORT, LED3_PINS);
}

void leds_on(void)
{
  gpio_set(LED1_PORT, LED1_PINS);
  gpio_set(LED2_PORT, LED2_PINS);
  gpio_set(LED3_PORT, LED3_PINS);
}

void leds_off(void)
{
  gpio_clear(LED1_PORT, LED1_PINS);
  gpio_clear(LED2_PORT, LED2_PINS);
  gpio_clear(LED3_PORT, LED3_PINS);
}
