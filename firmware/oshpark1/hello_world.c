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

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "clock.h"
#include "leds.h"
#include "keys.h"
#include "lcd.h"

uint16_t a_keys, b_keys, c_keys, d_keys, e_keys;

static void clock_setup(void)
{
  /* Set STM32 to 24 MHz. */
  //rcc_clock_setup_in_hse_8mhz_out_24mhz();
  clock_init();

  /* Enable clocks for all ports. */
  rcc_periph_clock_enable(RCC_GPIOA);
  rcc_periph_clock_enable(RCC_GPIOB);
  rcc_periph_clock_enable(RCC_GPIOC);
  rcc_periph_clock_enable(RCC_GPIOD);
  rcc_periph_clock_enable(RCC_GPIOE);
}

static void leds_blink(uint32_t n)
{
  while (n--) {
    leds_on();
    delay(1000);
    leds_off();
    delay(500);
  }
}

static uint32_t test_key(void) {
  uint16_t a_state, b_state, c_state, d_state, e_state;

  /* Upon any key press, blink more slowly. */
  a_state = gpio_get(GPIOA, PORT_A_KEYS);
  b_state = gpio_get(GPIOB, PORT_B_KEYS);
  c_state = gpio_get(GPIOC, PORT_C_KEYS);
  d_state = gpio_get(GPIOD, PORT_D_KEYS);
  e_state = gpio_get(GPIOE, PORT_E_KEYS);
  if ((a_state != PORT_A_KEYS) ||
      (b_state != PORT_B_KEYS) ||
      (c_state != PORT_C_KEYS) ||
      (d_state != PORT_D_KEYS) ||
      (e_state != PORT_E_KEYS)) {
    return 1;
  }
  return 0;
}

static void test_lcd(void)
{
  char *line1 = "Hello, world!   ";
  char *line2 = "Meet Stenosaurus";
  lcd_set_brightness(0x60);
  lcd_write_string(line1, LCD_LINE_1);
  lcd_write_string(line2, LCD_LINE_2);
}

int main(void)
{
  clock_setup();
  leds_setup();
  keys_setup();
  lcd_setup();

  test_lcd();
  while (1) {
    leds_blink(test_key());
  }

  return 0;
}
