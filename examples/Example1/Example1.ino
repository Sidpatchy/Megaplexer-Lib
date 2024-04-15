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
#include <SevenSegmentEncoder.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                    BEGIN CONFIG                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// This class is intended to be a test suite for the library.

// The technical limit for display count, following the Megaplexer communication protocol, is 255 displays.
// The practical limit is far lower. Probably not much higher than 9 displays (though this too approaches impractical).

// Used for assisting with animations.
#define NUMBER_OF_DISPLAYS 6

/*
 * I2C config
 *
 * You may want to change this depending on the layout of your project.
 */
#define I2C_ADDRESS 0x02

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                     END CONFIG                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
// write your initialization code here
}

void loop() {
// write your code here
}