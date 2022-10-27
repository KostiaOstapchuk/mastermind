#include "mastermind.hh"
#include "lcd_utils.hh"

void setup() {
    lcd_init();
    init_pins();
    turn_off_leds();
    Serial.begin(9600);
}

void loop() {
    char* code = generate_code(false, 4);
    turn_off_leds();
    play_game(code);
    free(code);
}
