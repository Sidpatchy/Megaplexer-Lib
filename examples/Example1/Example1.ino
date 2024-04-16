/*
 * Megaplexer-Lib - Communication Library for Megaplexer
 * a general purpose component of PrecisionClock-1
 * Copyright (C) 2024-04 Sidpatchy
 *
 * This code has been specifically designed to be used on
 * the ATmega8515. It will likely work on other similar MCUs,
 * however, I have not tested this with anything else.
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

#include <Arduino.h>
#include <Wire.h>
#include <Megaplexer.h>
#include <SevenSegmentEncoder.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                    BEGIN CONFIG                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This is intended to act as a test suite for the library.

// The technical limit for display count, following the Megaplexer communication protocol, is 255 displays.
// The practical limit is far lower. Probably not much higher than 9 displays (though this too approaches impractical).

// Used for assisting with animations.
#define NUMBER_OF_DISPLAYS 6

/*
 * I2C config
 *
 * You may want to change this depending on the layout of your project.
 * Adafruit has a good guide on which addresses given devices use:
 * https://learn.adafruit.com/i2c-addresses/the-list
 */
#define I2C_ADDRESS 0x08

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                     END CONFIG                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Declare display groups as pointers -> initialize in setup().
MEGAPLEXER* displayGroup0;
MEGAPLEXER* displayGroup1;
MEGAPLEXER* displayGroup2;

void setup() {
 // Wire must be configured uniformly across all devices.
 TWAR = I2C_ADDRESS;
 Wire.begin();
 Wire.setClock(400000);

 // Initialize all display drivers
 displayGroup0 = new MEGAPLEXER(0x09);
 displayGroup1 = new MEGAPLEXER(0x0A);
 displayGroup2 = new MEGAPLEXER(0x0B);

 // Start by showing '-' on all displays
 for (uint8_t i = 0; i < NUMBER_OF_DISPLAYS; i++) {
  displayGroup0->updateDigit(i, '-');
  displayGroup1->updateDigit(i, '-');
  displayGroup2->updateDigit(i, '-');
 }

 // Pause for 5 seconds to allow for visual validation of displays. **Not required**. Drivers will hold display value
 // until another command to update them is recieved.
 delay(5000);
}

// The amount of time to pause for after displaying each character. **Not required**.
int testingDelayMillis = 1000;

void loop() {

 // Test numbers on all displays
 for (unsigned const char charEncoding : numbersMap) {
  for (uint8_t digitIndex = 0; digitIndex < NUMBER_OF_DISPLAYS; digitIndex++) {
   displayGroup0->updateDigitWithByte(digitIndex, charEncoding);
   displayGroup1->updateDigitWithByte(digitIndex, charEncoding);
   displayGroup2->updateDigitWithByte(digitIndex, charEncoding);
  }
  delay(testingDelayMillis);
 }

 // Test uppercase alphabet on all displays
 for (unsigned const char charEncoding : alphaUppercaseMap) {
  for (uint8_t digitIndex = 0; digitIndex < NUMBER_OF_DISPLAYS; digitIndex++) {
   displayGroup0->updateDigitWithByte(digitIndex, charEncoding);
   displayGroup1->updateDigitWithByte(digitIndex, charEncoding);
   displayGroup2->updateDigitWithByte(digitIndex, charEncoding);
  }
  delay(testingDelayMillis);
 }

 // Test lowercase alphabet on all displays
 for (unsigned const char charEncoding : alphaLowercaseMap) {
  for (uint8_t digitIndex = 0; digitIndex < NUMBER_OF_DISPLAYS; digitIndex++) {
   displayGroup0->updateDigitWithByte(digitIndex, charEncoding);
   displayGroup1->updateDigitWithByte(digitIndex, charEncoding);
   displayGroup2->updateDigitWithByte(digitIndex, charEncoding);
  }
  delay(testingDelayMillis);
 }

 // Test special characters on all displays
 for (unsigned const char charEncoding : specialCharactersMap) {
  for (uint8_t digitIndex = 0; digitIndex < NUMBER_OF_DISPLAYS; digitIndex++) {
   displayGroup0->updateDigitWithByte(digitIndex, charEncoding);
   displayGroup1->updateDigitWithByte(digitIndex, charEncoding);
   displayGroup2->updateDigitWithByte(digitIndex, charEncoding);
  }
  delay(testingDelayMillis);
 }
}