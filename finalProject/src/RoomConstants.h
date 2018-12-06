#pragma once
#include "Room.h"
#include "ofMain.h"
#include "Constants.h"

const float kBuffer = 0;
const float doorSize = 20;

Room startRoom = Room({ -480 + kBuffer,-480 + kBuffer }, { -380 - kBuffer,-380 - kBuffer }, {}, {}, {}, {});
Room hallway1 = Room({ -380 + kBuffer,-405 + kBuffer }, { -300,-380 }, {}, {}, {}, {});

Door door1({ -405, -380, 0 }, { -380, -375, 2*kHeight }, &hallway1);