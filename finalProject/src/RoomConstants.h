#pragma once
#include "Room.h"
#include "ofMain.h"
#include "Constants.h"

const float kBuffer = 0;
const float doorSize = 20;

Room startRoom = Room({ -480, -480 }, { -380, -380 }, {}, {}, {}, {});
Room hallway1 = Room({ -380, -405 }, { -300, -380 }, {}, {}, {}, {});

Door door1({ -405, -380, 0 }, { -380, -375, 2*kHeight }, &hallway1);

Room room1 = Room({ -480,-300 }, { -380,-200 }, {}, {}, {}, {});

Door door2({ 0,0,0 }, { 5,5,2 * kHeight }, &room1);