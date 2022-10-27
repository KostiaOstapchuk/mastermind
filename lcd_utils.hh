#include <LiquidCrystal_I2C.h>

/**
 * Initialize LCD
 */
void lcd_init();

/**
 * Clears the LCD display
 */
void lcd_clear();


/**
 * Sets cursor to given position based on y and x coordinates.
 * @param y the row
 * @param x the column
 */
void lcd_set_cursor(int x, int y);


/**
 * Prints the givent text on the display on the current
 * cursor position.
 * @param text the text to print
 */
void lcd_print(char* text);


/**
 * Sets the cursor to given position based on y and x coorindates
 * and then prints the given text.
 * @param y the row
 * @param x the column
 * @param text the text to print
 */
void lcd_print_at(int x, int y, char* text);