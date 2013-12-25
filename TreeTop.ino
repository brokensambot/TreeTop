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
  growAnimation();
  paintAnimation();
  warpAnimation(200);
  zipUnzipAnimation();
}

void growAnimation() {
  DiodeState state[] = { OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState };
  
  // Turn center ring on.
  for ( byte i = 3; i < diodeCount; i += 6 )
    state[i] = OnState;
  
  displayStateForDuration(state, 100);
  
  // Turn first ring on.
  for ( byte i = 2; i < diodeCount; i += 2 ) {
    if ( i % 6 != 0 )
      state[i] = OnState;
  }
  
  displayStateForDuration(state, 100);
  
  // Turn second ring on.
  for ( byte i = 1; i < diodeCount; i += 2 ) {
    if ( i % 3 != 0 )
      state[i] = OnState;
  }
  
  displayStateForDuration(state, 100);
  
  // Turn outter ring on.
  for ( byte i = 0; i < diodeCount; i += 6)
    state[i] = OnState;
  
  displayStateForDuration(state, 100);
}

void paintAnimation() {
  DiodeState state[] = { OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState };
  
  // Turn top center light on.
  state[0] = OnState;
  displayStateForDuration(state, 60);
  
  for ( int i = 1; i < (diodeCount / 2); ++i ) {
    state[i] = OnState;
    state[diodeCount - i] = OnState;
    displayStateForDuration(state, 60);
  }
  
  // Turn bottom center light on.
  state[15] = OnState;
  displayStateForDuration(state, 60);
}

void warpAnimation(unsigned long duration) {
  DiodeState state[] = { OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState };
  
  // Turn center ring on.
  for ( byte i = 3; i < diodeCount; i += 6 )
    state[i] = OnState;
  
  displayStateForDuration(state, duration);
  
  // Turn center ring off.
  for ( byte i = 3; i < diodeCount; i += 6 )
    state[i] = OffState;
  
  // Turn first ring on.
  for ( byte i = 2; i < diodeCount; i += 2 ) {
    if ( i % 6 != 0 )
      state[i] = OnState;
  }
  
  displayStateForDuration(state, duration);
  
  // Turn first ring off.
  for ( byte i = 2; i < diodeCount; i += 2 ) {
    if ( i % 6 != 0 )
      state[i] = OffState;
  }
  
  // Turn second ring on.
  for ( byte i = 1; i < diodeCount; i += 2 ) {
    if ( i % 3 != 0 )
      state[i] = OnState;
  }
  
  displayStateForDuration(state, duration);
  
  // Turn second ring off.
  for ( byte i = 1; i < diodeCount; i += 2 ) {
    if ( i % 3 != 0 )
      state[i] = OffState;
  }
  
  // Turn tips on.
  for ( byte i = 0; i < diodeCount; i += 6)
    state[i] = OnState;
  
  displayStateForDuration(state, duration);
  
  // Turn tips off.
  for ( byte i = 0; i < diodeCount; i += 6)
    state[i] = OffState;
  
  // Repeat or end animation.
  if ( duration > 10 ) {
    warpAnimation(duration - 10);
  } else {
    // Turn everything on.
    for ( byte i = 0; i < diodeCount; ++i )
      state[i] = OnState;
    
    displayStateForDuration(state, 100);
  }
}

void zipUnzipAnimation() {
  DiodeState state[] = { OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState,
                         OffState, OffState, OffState, OffState, OffState };
  
  // Turn top light on.
  state[0] = OnState;
  displayStateForDuration(state, 60);
  
  // Zip clockwise.
  for ( int i = 1; i < diodeCount; ++i ) {
    state[i] = OnState;
    displayStateForDuration(state, 60);
  }
  // Unzip clockwise.
  for ( int i = diodeCount - 1; i > 0; --i ) {
    state[i] = OffState;
    displayStateForDuration(state, 60);
  }
  // Zip counterclockwise.
  for ( int i = diodeCount - 1; i > 0; --i ) {
    state[i] = OnState;
    displayStateForDuration(state, 60);
  }
  // Unzip counterclockwise.
  for ( int i = 1; i < diodeCount; ++i ) {
    state[i] = OffState;
    displayStateForDuration(state, 60);
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

