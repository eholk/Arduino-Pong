// -*- c++ -*-

/*
  A simple Pong game, using hardware SPI instead of software SPI.
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// On MEGA, MOSI is 51, CLK is 52
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
// MOSI is Data pin on display breakout

Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC);

    display.display();
}

void loop() {

}
