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

#ifndef STENOSAURUS_KEYS_H
#define STENOSAURUS_KEYS_H

#include <libopencm3/stm32/gpio.h>

/* Keys on port A */
#define KEY_NUM_2 GPIO3
#define KEY_LEFT_P GPIO5
#define KEY_LEFT_A GPIO6
#define KEY_NUM_3 GPIO7
#define PORT_A_KEYS (GPIO3 | GPIO5 | GPIO6 | GPIO7)

/* Keys on port B */
#define KEY_LEFT_O GPIO0
#define KEY_NUM_4 GPIO1
#define KEY_ASTERISK_0 GPIO2
#define KEY_RIGHT_R GPIO10
#define KEY_RIGHT_U GPIO11
#define KEY_NUM_6 GPIO12
#define KEY_RIGHT_P GPIO13
#define KEY_RIGHT_B GPIO14
#define KEY_NUM_7 GPIO15
#define PORT_B_KEYS (GPIO0 | GPIO1 | GPIO2 | GPIO10 | GPIO11 | GPIO12 | \
		     GPIO13 | GPIO14 | GPIO15)

/* Keys on port C */
#define KEY_NUM_1 GPIO0
#define KEY_LEFT_S_1 GPIO1
#define KEY_LEFT_S_0 GPIO2
#define KEY_NUM_0 GPIO3
#define KEY_LEFT_H GPIO4
#define KEY_LEFT_R GPIO5
#define KEY_LEFT_W GPIO13
#define KEY_LEFT_K GPIO14
#define KEY_LEFT_T GPIO15
#define PORT_C_KEYS (GPIO0 | GPIO1 | GPIO2 | GPIO3 | GPIO4 | GPIO5 | \
		     GPIO13 | GPIO14 | GPIO15)

/* Keys on port D */
#define KEY_RIGHT_L GPIO8
#define KEY_RIGHT_G GPIO9
#define KEY_NUM_8 GPIO10
#define KEY_RIGHT_T GPI11
#define KEY_RIGHT_S GPI12
#define KEY_NUM_9 GPIO13
#define KEY_RIGHT_D GPIO14
#define KEY_RIGHT_Z GPIO15
#define PORT_D_KEYS (GPIO8 | GPIO9 | GPIO10 | GPIO11 | GPIO12 | GPIO13 | \
		     GPIO14 | GPIO15)

/* Keys on port E */
#define KEY_ASTERISK_1 GPIO12
#define KEY__RIGHT_E GPIO13
#define KEY_NUM_5 GPIO14
#define KEY_RIGHT_F GPIO15
#define PORT_E_KEYS (GPIO12 | GPIO13 | GPIO14 | GPIO15)

void keys_setup(void);

#endif
