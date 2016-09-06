/* This file defines variables, constants 
and functions related to the TFT LCD screen */
#include "tft.hpp"
#include "Arduino.h"
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library

//-- Constants:
//const int LCD_RESET = A4;  // A4, Can alternately just connect to Arduino's reset pin
const int LCD_CS = A3; // Chip Select goes to A3
const int LCD_CD = A2; // Command/Data goes to A2
const int LCD_WR = A1; // LCD Write goes to A1
const int LCD_RD = A0; // LCD Read goes to A0

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD);

//-- Assign human-readable names to some common 16-bit color values:
const int BLACK   =   0xFFFF;
const int YELLOW  =   0x001F;
const int AQUA    =   0xF800;
const int MAGENTA =   0x07E0;
const int BLUE    =   0xFFE0;
const int GREEN   =   0xF81F;
const int RED     =   0x07FF;
const int WHITE   =   0x0000;

void printStatus_display(char text[], int size)
{
  print_fillRect(6 ,203, 308, 33, BLUE);
  print_display(text, size, YELLOW, 7, 210);
}

void println_display(char text[], int size, int color)
{
  tft.setTextColor(color);
  tft.setTextSize(size);
  tft.println(text);
}

void print_display(char text[], int size, int color, int x, int y)
{
  tft.setCursor(x,y);
  tft.setTextColor(color);
  tft.setTextSize(size);
  tft.print(text);
}

void printint_display(int text, int size, int color, int x, int y)
{
  tft.setCursor(x,y);
  tft.setTextColor(color);
  tft.setTextSize(size);
  tft.print(text);
}
void init_display(void)
{
  tft.reset();
  tft.begin(0x9341);
  uint8_t rotation=3;
  tft.setRotation(1);
  tft.fillScreen(BLUE);
  print_display("Smart Irrigation System", 2, WHITE, 18, 5);
  print_display("-----------------", 3, WHITE, 6, 15);
  tft.drawRect(5, 85, 100, 40, WHITE);
  tft.drawRect(5, 130, 100, 70, WHITE);
  tft.drawRect(110, 85, 100, 40, WHITE);
  tft.drawRect(110, 130, 100, 70, WHITE);
  tft.drawRect(215, 85, 100, 40, WHITE);
  tft.drawRect(215, 130, 100, 70, WHITE);
  tft.drawRect(5, 202, 310, 35, WHITE);
}

void print_fillRect(int x, int y, int width, int height, int color)
{
    tft.fillRect(x, y, width, height, color);
}

