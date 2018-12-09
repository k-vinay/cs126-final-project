#pragma once
#include "Room.h"
#include "ofMain.h"
#include "Constants.h"

//this file probably wont make sense unless you refer to
//"bin/data/map.png" - a labelled drawing of the map

Room startRoom = Room({ -480, -480 }, { -380, -380 }, {}, {}, {}, {});
Room hallway1 = Room({ -408, -380 }, { -380, -280 }, {}, {}, {}, {});
Room room1 = Room({ -480,-282 }, { -308,-37 }, {}, {}, {}, {});
Room hallway2 = Room({ -308,-184 }, { -184,-160 }, {}, {}, {}, {});
Room room2 = Room({ -184,-234 }, { -37,-160 }, {}, {}, {}, {});
Room hallway3 = Room({ -110,-307 }, { -85,-234 }, {}, {}, {}, {});
Room room3 = Room({ -357,-480 }, { -85,-307 }, {}, {}, {}, {});
Room hallway4 = Room({ -85,-380 }, { 12,-357 }, {}, {}, {}, {});
Room room4 = Room({ 12,-480 }, { 185,-283 }, {}, {}, { HitBox({37,-357,0},{160,-308,kWallHeight}) }, {});
Room hallway5 = Room({ -408,-37 }, { -258,86 }, {}, {}, { HitBox({-380,-37,0},{-258,61,kWallHeight}) }, {});
Room hallway6 = Room({ -184,-160 }, { -160,-61 }, {}, {}, {}, {});
Room room5 = Room({ -258,-61 }, { -86,283 }, {}, {}, {}, {});

Door door1({ -408+kHitboxDims.x, -380-kHitboxDims.y, 0 }, { -380-kHitboxDims.x, -380+kHitboxDims.y, 2*kHeight }, &startRoom, &hallway1);
Door door2({ -408+kHitboxDims.x, -282-kHitboxDims.y, 0 }, { -380-kHitboxDims.x, -282+kHitboxDims.y, 2*kHeight }, &hallway1, &room1);

Door door3({ -308-kHitboxDims.x, -184+kHitboxDims.y, 0 }, { -308+kHitboxDims.x, -160-kHitboxDims.y, 2*kHeight }, &room1, &hallway2);
Door door4({ -184-kHitboxDims.x, -184+kHitboxDims.y, 0 }, { -184+kHitboxDims.x, -160-kHitboxDims.y, 2*kHeight }, &hallway2, &room2);

Door door5({ -110 + kHitboxDims.x, -234 - kHitboxDims.y, 0 }, { -85 - kHitboxDims.x, -234 + kHitboxDims.y, 2 * kHeight }, &room2, &hallway3);
Door door6({ -110 + kHitboxDims.x, -307 - kHitboxDims.y, 0 }, { -85 - kHitboxDims.x, -307 + kHitboxDims.y, 2 * kHeight }, &hallway3, &room3);

Door door7({ -85 - kHitboxDims.x, -381 + kHitboxDims.y, 0 }, { -85 + kHitboxDims.x, -357 - kHitboxDims.y, 2 * kHeight }, &room3, &hallway4);
Door door8({ 12 - kHitboxDims.x, -381 + kHitboxDims.y, 0 }, { 12 + kHitboxDims.x, -357 - kHitboxDims.y, 2 * kHeight }, &hallway4, &room4);

Door door9({ -408 + kHitboxDims.x, -37 - kHitboxDims.y, 0 }, { -380 - kHitboxDims.x, -37 + kHitboxDims.y, 2 * kHeight }, &room1, &hallway5);
Door door10({ -258 - kHitboxDims.x, 61 + kHitboxDims.y, 0 }, { -258 + kHitboxDims.x, 86 - kHitboxDims.y, 2 * kHeight }, &hallway5, &room5);

Door door11({ -184 + kHitboxDims.x, -160 - kHitboxDims.y, 0 }, { -160 - kHitboxDims.x, -160 + kHitboxDims.y, 2 * kHeight }, &room2, &hallway6);
Door door12({ -184 + kHitboxDims.x, -61 - kHitboxDims.y, 0 }, { -160 - kHitboxDims.x, -61 + kHitboxDims.y, 2 * kHeight }, &hallway6, &room5);