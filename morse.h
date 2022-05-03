/*
 * PARIS = 50 elements
 *  delay() precision = 1 ms
 *  60 s = 60,000 ms
 *
 *  60000 / (50 * WPM) => (6000 / 5) / WPM
 *  6000 / 5 = 1200
 *
 *  .: Time of 1 element = 1200 / WPM == ARRL standard with standard spacing
 */

#ifndef _MORSE_H_
#define _MORSE_H_

#include <Arduino.h>

#define WPM 15














const static unsigned int morseTable[] = {
  0b1010111110000000,
  0b1011101011100000,
  0b1011101010000000,
  0b1010101110101100,
  0b1110101011101100,
  0b1010101110110000,
  0b1011111111100000, // ' - CHECK
  0b1110111110000000,
  0b1110111110110000,
  0b1010101110000000,
  0b1011101110000000,
  0b1111101011110000,
  0b1110101010110000,
  0b1011101110110000,
  0b1110101110000000,
  0b1111111111000000,
  0b1011111111000000,
  0b1010111111000000,
  0b1010101111000000,
  0b1010101011000000,
  0b1010101010000000,
  0b1110101010000000,
  0b1111101010000000,
  0b1111111010000000,
  0b1111111110000000,
  0b1111111010100000,
  0b1110111011100000,
  0b0000000000000000, // < - NULL
  0b1110101011000000,
  0b0000000000000000, // > - NULL
  0b1010111110100000,
  0b1011111011100000,
  0b1011000000000000,
  0b1110101000000000,
  0b1110111000000000,
  0b1110100000000000,
  0b1000000000000000,
  0b1010111000000000,
  0b1111100000000000,
  0b1010101000000000,
  0b1010000000000000,
  0b1011111100000000,
  0b1110110000000000,
  0b1011101000000000,
  0b1111000000000000,
  0b1110000000000000,
  0b1111110000000000,
  0b1011111000000000,
  0b1111101100000000,
  0b1011100000000000,
  0b1010100000000000,
  0b1100000000000000,
  0b1010110000000000,
  0b1010101100000000,
  0b1011110000000000,
  0b1110101100000000,
  0b1110111100000000,
  0b1111101000000000,
  0b1110111110000000, // [ - CHECK
  0b0000000000000000, // \ - NULL
  0b1110111110110000, // ] - CHECK
  0b0000000000000000, // ^ - NULL
  0b1010111110110000, // _ - CHECK
  0b0000000000000000, // ` - NULL
  0b1011000000000000,
  0b1110101000000000,
  0b1110111000000000,
  0b1110100000000000,
  0b1000000000000000,
  0b1010111000000000,
  0b1111100000000000,
  0b1010101000000000,
  0b1010000000000000,
  0b1011111100000000,
  0b1110110000000000,
  0b1011101000000000,
  0b1111000000000000,
  0b1110000000000000,
  0b1111110000000000,
  0b1011111000000000,
  0b1111101100000000,
  0b1011100000000000,
  0b1010100000000000,
  0b1100000000000000,
  0b1010110000000000,
  0b1010101100000000,
  0b1011110000000000,
  0b1110101100000000,
  0b1110111100000000,
  0b1111101000000000 };

void morse(unsigned char ch, uint8_t port) {

  // Pause between words = 7 elements
  if (ch == 32)

    delay((1200 / WPM) * 7);

  else if ((ch > 32) && (ch < 123)) {

    unsigned int mc = morseTable[ch - 33];

    while (mc & 0b1000000000000000) {

      // DAH = 3 elements
      if (mc & 0b0100000000000000) {

        digitalWrite(port, HIGH);
        delay((1200 / WPM) * 3);
        digitalWrite(port, LOW);

      // DIT = 1 element
      } else {

        digitalWrite(port, HIGH);
        delay(1200 / WPM);
        digitalWrite(port, LOW);

      }

      mc = mc << 2;

      // Pause between elements = 1 element
      delay(1200 / WPM);

    }

  }

  // Pause between letters = 3 elements - 1 element already paused
  delay((1200 / WPM) * 2);

}
  
#endif
