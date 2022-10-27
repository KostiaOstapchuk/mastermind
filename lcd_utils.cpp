#include "lcd_utils.hh"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void lcd_init() {
    lcd.init();
    lcd.backlight();
}

void lcd_clear() {
    lcd.clear();
}

void lcd_set_cursor(int x, int y) {
    lcd.setCursor(x, y);
}


void lcd_print(char* text) {
    lcd.print(text);
}


void lcd_print_at(int x, int y, char* text) {
    lcd.setCursor(x, y);
    lcd.print(text);
}