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

#include "lcd.h"
#include "clock.h"
#include <libopencm3/stm32/dac.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void lcd_set_data(uint8_t value)
{
  gpio_port_write(LCD_PORT, (gpio_port_read(LCD_PORT) & 0xFF00) | value);
}

static void lcd_send_command(uint8_t command)
{
  lcd_set_data(command);
  gpio_clear(LCD_PORT, LCD_READ_WRITE_PIN);
  gpio_clear(LCD_PORT, LCD_REGISTER_SELECT_PIN);
  gpio_set(LCD_PORT, LCD_ENABLE_PIN);
  delay(1);
  gpio_clear(LCD_PORT, LCD_ENABLE_PIN);
  delay(50);
}

static void lcd_send_character(char character)
{
  lcd_set_data(character);
  gpio_clear(LCD_PORT, LCD_READ_WRITE_PIN);
  gpio_set(LCD_PORT, LCD_REGISTER_SELECT_PIN);
  gpio_set(LCD_PORT, LCD_ENABLE_PIN);
  delay(1);
  gpio_clear(LCD_PORT, LCD_ENABLE_PIN);
  delay(50);
}

void lcd_setup(void)
{
  /* Enable digital to analog converter clock. */
  rcc_periph_clock_enable(RCC_DAC);
  
  /* Set LCD pins to 'output push-pull'. */
  gpio_set_mode(LCD_PORT,
		GPIO_MODE_OUTPUT_50_MHZ,
		GPIO_CNF_OUTPUT_PUSHPULL,
		LCD_PINS);

  /* Setup DAC pin for controlling LCD brightness. */
  gpio_set_mode(BRIGHTNESS_DAC_PORT,
		GPIO_MODE_OUTPUT_50_MHZ,
		GPIO_CNF_OUTPUT_ALTFN_PUSHPULL,
		BRIGHTNESS_DAC_PIN);
  dac_disable(BRIGHTNESS_DAC_CHANNEL);
  dac_disable_waveform_generation(BRIGHTNESS_DAC_CHANNEL);
  dac_set_trigger_source(DAC_CR_TSEL1_SW);
  dac_enable(BRIGHTNESS_DAC_CHANNEL);

  /* Supply voltage to display anode. */
  gpio_set(LCD_PORT, LCD_POWER_PIN);
  
  /* Configure the LCD's initial display state. */
  lcd_set_brightness(0);
  lcd_send_command(LCD_CMD_8_BIT_MODE);
  lcd_send_command(LCD_CMD_CLEAR);
  lcd_send_command(LCD_CMD_DISPLAY_ON);
  lcd_send_command(LCD_CMD_CURSOR_SHIFT);
  lcd_send_command(LCD_CMD_RETURN_HOME_LINE_1);
}

void lcd_set_brightness(uint8_t value)
{
  dac_load_data_buffer_single(value, RIGHT8, BRIGHTNESS_DAC_CHANNEL);
  dac_software_trigger(BRIGHTNESS_DAC_CHANNEL);
}

void lcd_write_string(char *str, lcd_line line)
{
  switch (line) {
  case LCD_LINE_1:
    lcd_send_command(LCD_CMD_RETURN_HOME_LINE_1);    
    break;
  case LCD_LINE_2:
    lcd_send_command(LCD_CMD_RETURN_HOME_LINE_2);
    break;
  }
  int i=0;
  while (str[i] != 0) {
    lcd_send_character(str[i++]);
  }
}
