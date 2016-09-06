//-- TFT LCD screen declarations
extern int LCD_RESET;  // A4, Can alternately just connect to Arduino's reset pin
extern int LCD_CS; // Chip Select goes to A3
extern int LCD_CD; // Command/Data goes to A2
extern int LCD_WR; // LCD Write goes to A1
extern int LCD_RD; // LCD Read goes to A0
//-- Assign human-readable names to some common 16-bit color values:
extern int BLACK;
extern int RED;
extern int BLUE;
extern int GREEN;
extern int CYAN;
extern int MAGENTA;
extern int YELLOW;
extern int WHITE;

extern void initLCD(void);
extern void printLCD(char text[], int size, int color);
