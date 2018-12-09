#pragma once
#include "Room.h"
#include "ofMain.h"
#include "Constants.h"

const float kBuffer = 0;
const float doorSize = 20;

Room startRoom = Room({ -480, -480 }, { -380, -380 }, {}, {}, {}, {});
Room hallway1 = Room({ -408, -380 }, { -380, -280 }, {}, {}, {}, {});

Door door1({ -408+kHitboxDims.x, -380-kHitboxDims.y, 0 }, { -380-kHitboxDims.x, -380+kHitboxDims.y, 2*kHeight }, &startRoom, &hallway1);

Room room1 = Room({ -480,-282 }, { -308,-37 }, {}, {}, {}, {});

Door door2({ -408+kHitboxDims.x, -282-kHitboxDims.y, 0 }, { -380-kHitboxDims.x, -282+kHitboxDims.y, 2*kHeight }, &hallway1, &room1);