// This file is part of the stenosaurus project.
//
// Copyright (C) 2013 Hesky Fisher <hesky.fisher@gmail.com>
// Copyright (C) 2016 Joshua Harlan Lifton
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
// This file defines the clock interface for the Stenosaurus firmware.
//
// See the .c file for implementation details.

#ifndef STENOSAURUS_FIRMWARE_CLOCK_H
#define STENOSAURUS_FIRMWARE_CLOCK_H

#include <stdint.h>

extern volatile uint32_t system_millis;

void clock_setup(void);

void delay(uint32_t millis);

#endif // STENOSAURUS_FIRMWARE_CLOCK_H