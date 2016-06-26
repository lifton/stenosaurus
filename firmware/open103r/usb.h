// This file is part of the stenosaurus project.
//
// Copyright (C) 2013 Hesky Fisher <hesky.fisher@gmail.com>
//
// This library is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation, either version 3 of the License, or (at your option) any later
// version.
//
// This library is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this library.  If not, see <http://www.gnu.org/licenses/>.
//
// This file defines the USB interface for the firmware.
//
// See the .c file for implementation details.
//
// The caller should first call init_usb. Then it should either call poll_usb in
// a loop or set it as the interrupt handler for low priority USB events.

#ifndef STENOSAURUS_FIRMWARE_USB_H
#define STENOSAURUS_FIRMWARE_USB_H

#include <stdbool.h>
#include <stdint.h>

extern uint8_t nkro_key_report[32];

void usb_init(bool (*)(uint8_t*));

uint32_t usb_send_serial_data(void *buf, int len);

void usb_keyboard_keys_up(void);

void usb_keyboard_key_up(uint8_t usb_keycode);

void usb_keyboard_key_down(uint8_t usb_keycode);

uint32_t usb_send_keyboard_report(void);

uint32_t usb_send_keys_if_changed(void);

#endif // STENOSAURUS_FIRMWARE_USB_H
