//Includes
#include <Arduino.h>
#include <Wire.h>

//Set pin inputs for relay in Array (Digital Pins)
int RelayPins[] = { 2, 3 };

//Set pin outputs in Array (Digital Pins)
int InputPinsButton[] = { 4, 5};
//Set variable for take information state Oven Cotntrole what made now warm up or not 
int LastControlerState = LOW;
int CurrentControlerState = LOW;
//Set variable for take information state begin Warming oven
int ButtonState = LOW;


void setup() {
  //Set pins mode OUTPUT, INPUT
  //OUTPUT mode for relays
  for (int i = 0; i < 2; i++) {
    pinMode(RelayPins[i], OUTPUT);
    digitalWrite(RelayPins[i], LOW);//initialize relays to be off
  }
  //INPUT Generaly General ordinary
  for (int i = 0; i < 2; i++) {
    pinMode(InputPinsButton[i], INPUT);
  }

}

void loop() {

//read statment of inputs
ButtonState = digitalRead(InputPinsButton[0]);
CurrentControlerState = digitalRead(InputPinsButton[1]);
//Logic for operation of (relay0) to ONCE time after HIGH at (input0) but not depending on the current state of the controler(input1),
//however to turn off after it has become LOW and before that it has become HIGH     
//here
if(ButtonState == HIGH && (CurrentControlerState == HIGH || CurrentControlerState == LOW)){
  digitalWrite(RelayPins[0], HIGH);
  //digitalWrite(RelayPins[1], HIGH);
  } else {
    //Turn off RelayPins[0] when CurrentControlerState changes from HIGH to LOW
      if (digitalRead(RelayPins[0]) == HIGH && LastControlerState == HIGH && CurrentControlerState == LOW) 
      {
      digitalWrite(RelayPins[0], LOW);
      }    
    }
// Update LastControlerState
LastControlerState = CurrentControlerState;
  
//this delay is for jast resting CPU  
delay(500);

}
