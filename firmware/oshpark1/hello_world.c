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

#include <libopencm3/stm32/gpio.h>
#include "clock.h"
#include "leds.h"
#include "keys.h"
#include "lcd.h"
#include "sdio.h"

uint16_t a_keys, b_keys, c_keys, d_keys, e_keys;

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

int main(void)
{
  clock_setup();
  leds_setup();
  keys_setup();
  lcd_setup();
  sdio_setup();

  bool card_initialized = false;
  bool prev_present = false;
  bool now_present = false;
  delay(500);
  lcd_set_brightness(0x60);
  lcd_write_string("Insert card.    ", LCD_LINE_1);

  while (1) {

    // Detect and react to changes in card presence.
    now_present = sdio_card_present();
    if (now_present && !prev_present) {
      lcd_write_string("Card inserted.  ", LCD_LINE_1);
    }
    else if (!now_present && prev_present) {
      lcd_write_string("Card removed.   ", LCD_LINE_1);
      lcd_write_string("                ", LCD_LINE_2);
    }
    prev_present = now_present;

    // Detect and react to changes in card initialization.
    if (now_present && !card_initialized) {
      if (!sdio_card_init()) {
	lcd_write_string("Not initialized.", LCD_LINE_2);
      }
      else {
	lcd_write_string("Initialized.    ", LCD_LINE_2);
	card_initialized = true;
      }
    }
    else if (!now_present && card_initialized) {
      lcd_write_string("                ", LCD_LINE_2);
      card_initialized = false;
    }
  }

  return 0;
}
