# Mastermind
Arduino implementation of the classic board game "Mastermind"

## General info
Mastermind is a code-breaking game for two players, but in this interpretation of the game you play against a computer.

[More about the original game](https://en.wikipedia.org/wiki/Mastermind_(board_game)).

## Setup

### Hardware
  - Arduio UNO R3
  - I2C LCD (16 x 2)
  - 4 red LEDs
  - 4 blue LEDs
  - 4 68 Ω resistors
  - 4 128 Ω resistors
  - 5 10 kΩ resistors
  - 5 pushbuttons
### Software
  - Arduino IDE
  - LiquidCrystal_I2C.h library
### Schematics

## Rules
The computer becomes the codemaker, you become the codebreaker. 

The codemaker randomly generates a code of 4 digits. 

The codebreaker tries to guess the code within ten turns. Each guess is made by individually entering each digit using a corresponding button and pressing the "enter" button on the decoding board. 

Once the guess is made, the codemaker provides feedback by lighting LEDs (key pegs) on the decoding board. 

A red LED is lit for each digit from the guess which is correct and in the correct position. A blue LED indicates the existence of a correct digit placed in the wrong position. 

Once feedback is provided, another guess is made; guesses and feedback continue to alternate until either the codebreaker guesses correctly, runs out of attempts.


