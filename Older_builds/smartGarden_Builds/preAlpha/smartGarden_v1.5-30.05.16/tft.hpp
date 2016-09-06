/* This file declares variables, constants 
and functions related to the TFT LCD screen */
#ifndef TFT_HPP
#define TFT_HPP
//-- Constants:
//extern const int LCD_RESET;  // A4, Can alternately just connect to Arduino's reset pin
extern const int LCD_CS; // Chip Select goes to A3
extern const int LCD_CD; // Command/Data goes to A2
extern const int LCD_WR; // LCD Write goes to A1
extern const int LCD_RD; // LCD Read goes to A0
//-- Assign human-readable names to some common 16-bit color values:
extern const int BLACK;
extern const int RED;
extern const int BLUE;
extern const int GREEN;
extern const int CYAN;
extern const int MAGENTA;
extern const int YELLOW;
extern const int WHITE;
//-- Fuctions:
extern void init_display(void);
extern void print_display(char text[], int size, int color, int x, int y);
extern void println_display(char text[], int size, int color);
extern void printint_display(int text, int size, int color, int x, int y);
extern void print_fillRect(int x, int y, int width, int height, int color);
extern void printStatus_display(char text[], int size);
#endif
