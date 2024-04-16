/*
 * Megaplexer-Lib - Communication Library for Megaplexer
 * a general purpose component of PrecisionClock-1
 * Copyright (C) 2024-04 Sidpatchy
 *
 * This code has been specifically designed to be used on
 * the ATmega8515. It will likely work on other similar MCUs,
 * however, I have not tested this with anything else.
 *
 * A class for managing sending updates to seven segment displays
 * being driven by the Megaplexer project.
 *
 * ///////////////////////////////////////////////////////////////////////////
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MEGAPLEXER_H
#define MEGAPLEXER_H

#include "SevenSegmentEncoder.h"
#include <Arduino.h>
#include <Wire.h>

class MEGAPLEXER {
 private:
  uint8_t i2c_address;
  ENCODER* encoder;

 public:
  explicit MEGAPLEXER(uint8_t address);
  ~MEGAPLEXER();

  void updateDigitWithByte(uint8_t digitIndex, byte segmentEncoding) const;
  void updateDigit(uint8_t digitIndex, char character) const;                 // DP disabled
  void updateDigit(uint8_t digitIndex, char character, bool dpEnabled) const; // DP enabled if true
  void updateDigit(uint8_t digitIndex, int ascii) const;                      // DP disabled
  void updateDigit(uint8_t digitIndex, int ascii, bool dpEnabled) const;      // DP enabled if true
};

#endif //DISPLAY_H
