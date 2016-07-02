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

#ifndef STENOSAURUS_LCD_H
#define STENOSAURUS_LCD_H

#include <libopencm3/stm32/gpio.h>

/* Pin definitions for LCD. */
#define LCD_PORT GPIOE
#define LCD_DATA_0_PIN GPIO0
#define LCD_DATA_1_PIN GPIO1
#define LCD_DATA_2_PIN GPIO2
#define LCD_DATA_3_PIN GPIO3
#define LCD_DATA_4_PIN GPIO4
#define LCD_DATA_5_PIN GPIO5
#define LCD_DATA_6_PIN GPIO6
#define LCD_DATA_7_PIN GPIO7
#define LCD_ENABLE_PIN GPIO8
#define LCD_READ_WRITE_PIN GPIO9
#define LCD_REGISTER_SELECT_PIN GPIO10
#define LCD_POWER_PIN GPIO11
#define LCD_PINS (LCD_DATA_0_PIN | \
		  LCD_DATA_1_PIN | \
		  LCD_DATA_2_PIN | \
		  LCD_DATA_3_PIN | \
		  LCD_DATA_4_PIN | \
		  LCD_DATA_5_PIN | \
		  LCD_DATA_6_PIN | \
		  LCD_DATA_7_PIN | \
		  LCD_ENABLE_PIN | \
		  LCD_READ_WRITE_PIN | \
		  LCD_REGISTER_SELECT_PIN | \
		  LCD_POWER_PIN)
#define BRIGHTNESS_DAC_PORT GPIOA
#define BRIGHTNESS_DAC_PIN GPIO4
#define BRIGHTNESS_DAC_CHANNEL CHANNEL_1

#define LCD_CMD_8_BIT_MODE 0x38
#define LCD_CMD_CLEAR 0x01
#define LCD_CMD_DISPLAY_ON 0x0F
#define LCD_CMD_CURSOR_SHIFT 0x06
#define LCD_CMD_RETURN_HOME_LINE_1 0x80
#define LCD_CMD_RETURN_HOME_LINE_2 0xC0

typedef enum {
  LCD_LINE_1,
  LCD_LINE_2
} lcd_line;  

/* Must be called once before any other function here. */
void lcd_setup(void);

/* Set the brightness of the LCD.
 * Observed effects of different brightness values:
 * 0xFF: solid screen
 * 0x7F: solid screen
 * 0x3F: top row has white boxes (5x8 pixels) where the characters would be
 * 0x1F: both rows have white boxes (5x8 pixels) where the characters would be
 * 0x00: both rows have white boxes (5x8 pixels) where the characters would be
 */
void lcd_set_brightness(uint8_t value);

/* Display a null-terminated string on the LCD. */
void lcd_write_string(char *str, lcd_line line);

#endif
