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

#include "keys.h"

void keys_setup(void)
{
  /* Set keys on port A to be inputs with pull-ups enabled. */
  gpio_set_mode(GPIOA, GPIO_MODE_INPUT,
		GPIO_CNF_INPUT_PULL_UPDOWN,
		PORT_A_KEYS);
  gpio_set(GPIOA, PORT_A_KEYS);
    
  /* Set keys on port B to be inputs with pull-ups enabled. */
  gpio_set_mode(GPIOB, GPIO_MODE_INPUT,
		GPIO_CNF_INPUT_PULL_UPDOWN,
		PORT_B_KEYS);
  gpio_set(GPIOB, PORT_B_KEYS);

  /* Set keys on port C to be inputs with pull-ups enabled. */
  gpio_set_mode(GPIOC, GPIO_MODE_INPUT,
		GPIO_CNF_INPUT_PULL_UPDOWN,
		PORT_C_KEYS);
  gpio_set(GPIOC, PORT_C_KEYS);

  /* Set keys on port D to be inputs with pull-ups enabled. */
  gpio_set_mode(GPIOD, GPIO_MODE_INPUT,
		GPIO_CNF_INPUT_PULL_UPDOWN,
		PORT_D_KEYS);
  gpio_set(GPIOD, PORT_D_KEYS);

  /* Set keys on port E to be inputs with pull-ups enabled. */
  gpio_set_mode(GPIOE, GPIO_MODE_INPUT,
		GPIO_CNF_INPUT_PULL_UPDOWN,
		PORT_E_KEYS);
  gpio_set(GPIOE, PORT_E_KEYS);
}
