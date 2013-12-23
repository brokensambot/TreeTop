//
// TreeTop.ino
// TreeTop
//
// Created by Samuel White on 12/21/13.
//

#include "TreeTopTypes.h"

static const byte controllerPins[] = { 7, 8, 9, 10, 11, 12 };

static const byte diodeCount = 30;

static const Diode diodes[] = { { 1, 3 }, { 0, 3 }, { 4, 3 }, { 4, 2 }, { 3, 4 },
                                { 5, 4 }, { 1, 4 }, { 0, 4 }, { 2, 4 }, { 3, 2 },
                                { 3, 5 }, { 2, 5 }, { 1, 5 }, { 0, 5 }, { 4, 5 },
                                { 5, 2 }, { 3, 0 }, { 5, 0 }, { 1, 0 }, { 2, 0 },
                                { 4, 0 }, { 0, 2 }, { 3, 1 }, { 5, 1 }, { 2, 1 },
                                { 0, 1 }, { 4, 1 }, { 1, 2 }, { 2, 3 }, { 5, 3 } };

void setup() {
  initializeDiodes();
}

void loop() {
  knightRiderShow();
}

void knightRiderShow() {
  DiodeState state[] = { OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState };
  
  for ( int i = 0; i < diodeCount; ++i ) {
    state[i] = OnState;
    displayStateForDuration(state, 50);
    state[i] = OffState;
  }
  for ( int i = diodeCount - 1; i >= 0; --i ) {
    state[i] = OnState;
    displayStateForDuration(state, 50);
    state[i] = OffState;
  }
}

void initializeDiodes() {
  for ( byte i = 0; i < diodeCount; ++i ) {
    diodeWrite(i, OffState);
  }
}

void displayStateForDuration(DiodeState state[], unsigned long duration) {
  unsigned long time = millis();
  while ( millis() < time + duration ) {
    for ( byte i = 0; i < diodeCount; ++i ) {
      if ( state[i] == OnState ) {
        diodeWrite(i, OnState);
      }
      diodeWrite(i, OffState);
    }
  }
}

void diodeWrite(byte diode, DiodeState state) {
  byte controllerAnodePin = controllerPins[diodes[diode].anode];
  byte controllerCathodePin = controllerPins[diodes[diode].cathode];
  
  pinMode(controllerAnodePin, ( state == OnState ) ? OUTPUT : INPUT);
  pinMode(controllerCathodePin, ( state == OnState ) ? OUTPUT : INPUT);
  
  digitalWrite(controllerAnodePin, ( state == OnState ) ? HIGH : LOW);
  digitalWrite(controllerCathodePin, LOW);
}

