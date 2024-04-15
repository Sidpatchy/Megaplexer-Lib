/*
 * Megaplexer-Lib - Communication Library for Megaplexer
 * a general purpose component of PrecisionClock-1
 * Copyright (C) 2024-04 Sidpatchy
 *
 * This code has been specifically designed to be used on
 * the ATmega8515. It will likely work on other similar MCUs,
 * however, I have not tested this with anything else.
 *
 * A class for encoding characters -> bytes before for sending them
 * to slave MCUs for display multiplexing.
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

#include "SevenSegmentEncoder.h"
#include <Arduino.h>

/**
 * Method for encoding characters into displayable bytes.
 *
 * @param character The char to encode for.
 * @return An encoded byte for the Megaplexer MCU to process.
 */
byte ENCODER::getByteFromChar(char character) {
 if (character >= 'A' && character <= 'Z') {
  return alphaUppercaseMap[character - 'A'];
 }
 else if (character >= 'a' && character <= 'z') {
  return alphaLowercaseMap[character - 'a'];
 }
 else if (character >= '0' && character <= '9') {
  return numbersMap[character - '0'];
 }
 else {
  // Handle special characters
  switch (character) {
   case '=': return specialCharactersMap[0];
   case '-': return specialCharactersMap[1];
   case '_': return specialCharactersMap[2];
   case '\'': return specialCharactersMap[3];
   case '"': return specialCharactersMap[4];
   case ' ': return specialCharactersMap[5];
   default: return 0b00000000; // return all segments off if character is not recognized
  }
 }
}

/**
 * Method for encoding characters into displayable bytes while toggling the "dot" on/off.
 *
 * @param character The char to encode for.
 * @param dpEnabled Whether the dot (assuming display is equiped) should be enabled.
 * @return An encoded byte for the Megaplexer MCU to process.
 */
byte ENCODER::getByteFromChar(const char character, const bool dpEnabled) {
 return getByteFromChar(character) | (dpEnabled ? 0b10000000 : 0b00000000);
}

/**
 *
 * @param ascii The ASCII value of the character to be displayed. Example: 65 would display A.
 * @return An encoded byte for the Megaplexer MCU to process.
 */
byte ENCODER::getByteFromAscii(const int ascii) {
 return getByteFromChar(static_cast<char>(ascii));
}

/**
 *
 * @param ascii The ASCII value of the character to be displayed. Example: 65 would display A.
 * @param dpEnabled Whether the dot (assuming display is equiped) should be enabled.
 * @return An encoded byte for the Megaplexer MCU to process.
 */
byte ENCODER::getByteFromAscii(const int ascii, const bool dpEnabled) {
 return getByteFromChar(static_cast<char>(ascii), dpEnabled);
}