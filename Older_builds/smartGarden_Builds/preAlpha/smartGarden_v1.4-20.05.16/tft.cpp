#include "tft.hpp"
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

//-- TFT LCD screen declarations
int LCD_RESET = A4;  // A4, Can alternately just connect to Arduino's reset pin
int LCD_CS = A3; // Chip Select goes to A3
int LCD_CD = A2; // Command/Data goes to A2
int LCD_WR = A1; // LCD Write goes to A1
int LCD_RD = A0; // LCD Read goes to A0
//-- Assign human-readable names to some common 16-bit color values:
int BLACK   =   0xFFFF;
int RED     =   0x001F;
int BLUE    =   0xF800;
int GREEN   =   0x07E0;
int CYAN    =   0xFFE0;
int MAGENTA =   0xF81F;
int YELLOW  =   0x07FF;
int WHITE   =   0x0000;

void initLCD(void)
{
tft.reset();
tft.begin(0x9341);
uint8_t rotation=0;
tft.setRotation(1);
tft.fillScreen(BLACK);
}

void printLCD(char text[], int size, int color)
{
  tft.setTextColor(color);
  tft.setTextSize(size);
  tft.println("text");
}
