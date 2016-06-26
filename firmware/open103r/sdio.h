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
// This file defines the SDIO interface for the firmware.
//
// See the .c file for implementation details.

#ifndef STENOSAURUS_FIRMWARE_SDIO_H
#define STENOSAURUS_FIRMWARE_SDIO_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    SDIO_ESUCCESS = 1,
    SDIO_EINPROGRESS = 2,
    SDIO_ECTIMEOUT = 3,
    SDIO_ECCRCFAIL = 4,
    SDIO_EUNKNOWN = 5,
} sdio_error_t;

void sdio_init(void);

bool sdio_card_present(void);

bool sdio_card_init(void);

bool sdio_read_block(uint32_t address, uint32_t *buffer);

bool sdio_write_block(uint32_t address, uint32_t *buffer);

#endif // STENOSAURUS_FIRMWARE_SDIO_H
