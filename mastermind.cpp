#include "mastermind.hh"
#include "lcd_utils.hh"

char* generate_code(bool repeat, int length) {
    char* code;
    code = (char*)malloc(sizeof(char) * (length+1));

    randomSeed(analogRead(0));

    for (int i = 0; i < length; i++) {
        code[i] = random(0, 10) + 48;
        if (!repeat && i > 0) {
            for (int j = 0; j < i; j++) {
                if (code[i] == code[j]) {
                    i--;
                }
            }
        }
    }

    code[length] = '\0';
    Serial.println(code);
    return code;
}



void init_pins(){
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

void render_leds(const int peg_a, const int peg_b) {

    if((peg_a + peg_b) > 4){
        return;
    }

    int j = 0;
    turn_off_leds();

    for (int i = 0; i < peg_a; i++) {
        digitalWrite(LED_RED_1 + (i * 2), HIGH);
        j++;
    }
    for (int i = 0; i < peg_b; i++) {
        digitalWrite(LED_BLUE_1 + (i * 2) + (j * 2), HIGH);
    }
}

void turn_off_leds() {
    for(int i = 6; i <= 13; i++){
        digitalWrite(i, LOW);
    }
}

void get_score(const char* secret, const char* guess, int* peg_a, int* peg_b) {
    *peg_a = 0;
    *peg_b = 0;
    for (int i = 0; i < strlen(secret); i++) {
        if (guess[i] == secret[i]) {
            (*peg_a)++;
        } else {
            for (int j = 0; j < strlen(secret); j++) {
                if (guess[i] == secret[j] && i != j) {
                    (*peg_b)++;
                }
            }
        }
    }
}

void readButtons(int* buttons) {
    int states[5];
    for(int i = 0; i < 4; i++) {
        states[i] = digitalRead(BTN_1_PIN+i);
    }
    states[4] = digitalRead(BTN_ENTER_PIN);

    for(int i = 0; i < 5; i++) {
        if (states[i] == HIGH && buttons[i] == 0) {
            buttons[i] = 1;
        }
    }
}

void play_game(const char* secret) {
    char guess[5] = "0000";
    int buttons[5] = { 0, 0, 0, 0, 0 };
    int attempt = 0, win = 0, peg_a = 0, peg_b = 0;
    lcd_print_at(3, 0, "MasterMind");

    while(attempt < ATTEMPTS && !win){
        readButtons(buttons);
        
        for(int i = 0; i < 4; i++){
            if(buttons[i] == 1){
                guess[i]++;
                if(guess[i] > '9'){
                    guess[i] = '0';
                }
                buttons[i]=0;
            }
        }
        if(buttons[4] == 1){
            buttons[4] = 0;
            win = 1;
            char whole_str[20];
            get_score(secret, guess, &peg_a, &peg_b);
            
            sprintf(whole_str, "%02d: %s - %cA%cB", attempt + 1, guess, (char)(peg_a + 48), (char)(peg_b + 48));
            render_leds(peg_a, peg_b);
            lcd_print_at(0, 0, whole_str);
            for(int i = 0; i < 4; i++){
                if(secret[i] != guess[i]){
                    win = 0;
                    break;
                }
            }
            for(int i = 0; i < 4; ++i){
                guess[i] = '0';
            }

            attempt++;
        }
        delay(100);
        lcd_print_at(0, 1, "Your guess: ");
        lcd_print_at(12, 1, guess);
    }

    lcd_clear();
    lcd_set_cursor(4, 1);
    if(win){    
        lcd_print("You win");
    }else{
        lcd_print("You lose");
    }
    delay(3000);
    lcd_clear();
    turn_off_leds();
    return;
}


