# This file is part of the stenosaurus project.
#
# Copyright (C) 2013 Hesky Fisher <hesky.fisher@gmail.com>
#
# This library is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# This library is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this library.  If not, see <http://www.gnu.org/licenses/>.
#
# This makefile builds the firmware for the stenosaurus.

LDSCRIPT := firmware.ld

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c)) ../common/leds.o \
  ../common/user_button.o

all: firmware.bin

.PHONEY: clean

include ../Makefile.include
