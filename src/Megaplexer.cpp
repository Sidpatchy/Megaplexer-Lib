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

#include "Megaplexer.h"
#include "SevenSegmentEncoder.h"
#include <Arduino.h>
#include <Wire.h>

ENCODER encoder;

/**
 * 
 * @param address 
 */
MEGAPLEXER::MEGAPLEXER(uint8_t address) {
  i2c_address = address;
  encoder = new ENCODER();
}

/**
 * 
 */
MEGAPLEXER::~MEGAPLEXER() {
  delete encoder;
}

/**
 * Method to handle communication with the Megaplexer. Allows for transmitting custom character definitions vs using
 * the predefined ones. This is ultimately called by all other signatures of this method.
 *
 * @param digitIndex Which digit to update, will cause an error on the slave MCU if greater than the number of digits.
 * @param segmentEncoding The pre-encoded data to display on the seven segment. DPgfedcba -> 0b00000000
 */
void MEGAPLEXER::updateDigit(int digitIndex, byte segmentEncoding) {

}

/**
 * Method for handling communication with the Megaplexer. Takes a char and translates it to a display representation.
 * 
 * @param digitIndex Which digit to update, will cause an error on the slave MCU if greater than the number of digits.
 * @param character The char to encode for.
 */
void MEGAPLEXER::updateDigit(int digitIndex, char character) {
 updateDigit(digitIndex, character, false);
}

/**
 * Method to handle communication with the Megaplexer. Takes a char and translates it to a display representation.
 * 
 * @param digitIndex Which digit to update, will cause an error on the slave MCU if greater than the number of digits.
 * @param character The char to encode for.
 * @param dpEnabled Whether the dot (assuming display is equiped) should be enabled.
 */
void MEGAPLEXER::updateDigit(int digitIndex, char character, bool dpEnabled) {
 byte segmentEncoding = encoder->getByteFromChar(character, dpEnabled);
 updateDigit(digitIndex, segmentEncoding);
}

/**
 * Method to handle communication with the Megaplexer. Takes an ASCII character value and translates it to a
 * display representation.
 * 
 * @param digitIndex Which digit to update, will cause an error on the slave MCU if greater than the number of digits.
 * @param ascii The ASCII value of the character to be displayed. Example: 65 would display A.
 */
void MEGAPLEXER::updateDigit(int digitIndex, int ascii) {
 updateDigit(digitIndex, ascii, false);
}

/**
 * Method to handle communication with the Megaplexer. Takes an ASCII character value and translates it to a
 * display representation.
 * 
 * @param digitIndex Which digit to update, will cause an error on the slave MCU if greater than the number of digits.
 * @param ascii The ASCII value of the character to be displayed. Example: 65 would display A.
 * @param dpEnabled Whether the dot (assuming display is equiped) should be enabled.
 */
void MEGAPLEXER::updateDigit(int digitIndex, int ascii, bool dpEnabled) {
 byte segmentEncoding = encoder->getByteFromAscii(ascii, dpEnabled);
 updateDigit(digitIndex, segmentEncoding);
}