//
// TreeTopTypes.h
// TreeTop
//
// Created by Samuel White on 12/21/13.
//

#include "Arduino.h"

typedef struct {
  byte anode;
  byte cathode;
} Diode;

typedef enum {
  OffState,
  OnState
} DiodeState;

