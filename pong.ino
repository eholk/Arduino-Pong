// -*- c++ -*-

/*
  A simple Pong game, using hardware SPI instead of software SPI.
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const unsigned long BALL_RATE = 16;

// On MEGA, MOSI is 51, CLK is 52
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
// MOSI is Data pin on display breakout

Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

void drawCourt();

uint8_t ball_x = 64, ball_y = 32;
uint8_t ball_dir_x = 1, ball_dir_y = 1;
unsigned long ball_update;

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC);

    // Display the splash screen (we're legally required to do so)
    display.display();
    delay(2000);

    display.clearDisplay();
    drawCourt();
    display.display();

    ball_update = millis();
}

void loop() {
    bool update = false;
    unsigned long time = millis();
    
    if(time > ball_update) {
        uint8_t new_x = ball_x + ball_dir_x;
        uint8_t new_y = ball_y + ball_dir_y;

        if(new_x == 0 || new_x == 127) {
            ball_dir_x = -ball_dir_x;
            new_x += ball_dir_x + ball_dir_x;
        }

        if(new_y == 0 || new_y == 63) {
            ball_dir_y = -ball_dir_y;
            new_y += ball_dir_y + ball_dir_y;
        }

        display.drawPixel(ball_x, ball_y, BLACK);
        display.drawPixel(new_x, new_y, WHITE);
        ball_x = new_x;
        ball_y = new_y;

        ball_update += BALL_RATE;

        update = true;
    }

    if(update)
        display.display();
}


void drawCourt() {
    display.drawRect(0, 0, 128, 64, WHITE);
}
