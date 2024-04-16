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
 * This class follows the character designations on the following Wikipedia page:
 * https://en.wikipedia.org/wiki/Seven-segment_display_character_representations#
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

#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

// DP is handled seperately by the encoder for increased simplicity.

// Map for uppercase letters of the English alphabet.
// 0b00000000
//  DPgfedcba
constexpr byte alphaUppercaseMap[26] {
 0b01110111, // A
 0b01111111, // B, same as 8
 0b01111001, // C
 0b00011111, // D
 0b01111001, // E
 0b01110001, // F
 0b00111101, // G
 0b01110110, // H
 0b00110000, // I, same as i
 0b00001110, // J
 0b01110101, // K
 0b00111000, // L
 0b00101011, // M
 0b00110111, // N
 0b00111111, // O, same as 0 (zero)
 0b01110011, // P, same as p
 0b01011011, // Q
 0b01111011, // R
 0b01100101, // S, same as 5
 0b00110001, // T
 0b00111110, // U
 0b00101110, // V
 0b00011101, // W
 0b01001001, // X
 0b01101010, // Y
 0b01011011  // Z, same as 2
};

// Map for lowercase letters of the English alphabet.
// 0b00000000
//  DPgfedcba
constexpr byte alphaLowercaseMap[26] {
 0b01001100, // a
 0b01111100, // b
 0b01110000, // c
 0b01011110, // d
 0b00011000, // e
 0b01110000, // f
 0b01011001, // g
 0b01110100, // h
 0b00011001, // i
 0b00001101, // j
 0b01100101, // k
 0b00110000, // l, same as I
 0b01010101, // m
 0b01010100, // n
 0b01011100, // o
 0b01110011, // p, same as P
 0b01100111, // q
 0b01010000, // r
 0b00001100, // s
 0b01111000, // t
 0b00011100, // u
 0b00001100, // v
 0b00011101, // w
 0b01001000, // x, same as Z
 0b01101110, // y
 0b01001000  // z, same as X
};

// Map for numbers.
// 0b00000000
//  DPgfedcba
constexpr byte numbersMap[10] {
 0b00111111, // 0
 0b00000110, // 1
 0b01011011, // 2, same as Z
 0b01001111, // 3
 0b01100110, // 4
 0b01100101, // 5, same as S
 0b01111101, // 6
 0b01100001, // 7
 0b01111111, // 8, same as B
 0b01101111  // 9
};

// Map for special characters.
// 0b00000000
//  DPgfedcba
constexpr byte specialCharactersMap[6] {
 0b01001000, // =
 0b01000000, // -
 0b00001000, // _
 0b00100000, // '
 0b00100010, // "
 0b00000000, //   (space/off)
};

class ENCODER {
 public:
  byte getByteFromChar(char character);                  // DP disabled
  byte getByteFromChar(char character, bool dpEnabled);  // DP enabled if true
  byte getByteFromAscii(int ascii);                      // DP disabled
  byte getByteFromAscii(int ascii, bool dpEnabled);      // DP enabled if true
};

#endif //ENCODER_H
