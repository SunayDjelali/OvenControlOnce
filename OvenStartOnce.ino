//!!!!Atttencion Relay BOAR whit 4 Blue relay work reverse logic LOW=HIGH !!!!
//Includes
#include <Arduino.h>
#include <Wire.h>

//Set pin inputs for relay in Array (Digital Pins)
int RelayPins[] = { 2, 3, 4, 5};

//Set pin outputs in Array (Digital Pins)
int InputPinsButton[] = { 6, 7};
//Set variable for take information state Oven Cotntrole what made now warm up or not 
int LastControlerState = HIGH;
int CurrentControlerState = HIGH;
//Set variable for take information state begin Warming oven
int ButtonState = LOW;

void setup() {
  //Set pins mode OUTPUT, INPUT
  //OUTPUT mode for relays
  for (int i = 0; i < 4; i++) {
    pinMode(RelayPins[i], OUTPUT);
    //initialize relays to be off (reverse logic)
    digitalWrite(RelayPins[i], HIGH);
  }
  //INPUT Generaly General ordinary
  for (int i = 0; i < 1; i++) {
    pinMode(InputPinsButton[i], INPUT);
  }
}

void loop() {
//read statment of inputs
  ButtonState = digitalRead(InputPinsButton[0]);
  CurrentControlerState = digitalRead(InputPinsButton[1]);
//Logic for operation of (relay0) to ONCE time after HIGH at (input0)  depending on the current state of the controler(input1)=HIGH,
//however to turn off after it has become LOW and before that it has become HIGH     
//|| CurrentControlerState == LOW,(CurrentControlerState == HIGH || CurrentControlerState == LOW)
  if  (ButtonState == HIGH && CurrentControlerState == HIGH){
      digitalWrite(RelayPins[0], LOW);
      digitalWrite(RelayPins[1], LOW);
      digitalWrite(RelayPins[2], LOW);
      digitalWrite(RelayPins[3], LOW);
  } 
  else {
      //Turn off RelayPins[0] when CurrentControlerState changes from HIGH to LOW
      //!!!!!Attentione revers Logic relay otput !!!!
      if (digitalRead(RelayPins[0]) == LOW && LastControlerState == HIGH && CurrentControlerState == LOW){
      digitalWrite(RelayPins[0], HIGH);
      digitalWrite(RelayPins[1], HIGH);
      digitalWrite(RelayPins[2], HIGH);
      digitalWrite(RelayPins[3], HIGH);
      } 
    }
// Update LastControlerState
LastControlerState = CurrentControlerState;
  
//this delay is for jast resting CPU  
delay(300);
}
