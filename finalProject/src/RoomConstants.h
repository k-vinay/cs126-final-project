#pragma once
#include "Room.h"
#include "ofMain.h"
#include "Constants.h"

//this file probably wont make sense unless you refer to
//"bin/data/map.png" - a labelled drawing of the map

Room startRoom({ -480, -480 }, { -380, -380 }, {}, {}, {}, {});

Room room1({ -480,-282 }, { -308,-37 }, {}, {}, {}, {});
Room hallway1({ -408, -380 }, { -380, -280 }, {}, {}, {}, {});
Door door1({ -408 + kHitboxDims.x, -380 - kHitboxDims.y, 0 }, { -380 - kHitboxDims.x, -380 + kHitboxDims.y, 2 * kHeight }, &startRoom, &hallway1);
Door door2({ -408 + kHitboxDims.x, -282 - kHitboxDims.y, 0 }, { -380 - kHitboxDims.x, -282 + kHitboxDims.y, 2 * kHeight }, &hallway1, &room1);

Room room2({ -184,-234 }, { -37,-160 }, {}, {}, {}, {});
Room hallway2({ -308,-184 }, { -184,-160 }, {}, {}, {}, {});
Door door3({ -308 - kHitboxDims.x, -184 + kHitboxDims.y, 0 }, { -308 + kHitboxDims.x, -160 - kHitboxDims.y, 2 * kHeight }, &room1, &hallway2);
Door door4({ -184 - kHitboxDims.x, -184 + kHitboxDims.y, 0 }, { -184 + kHitboxDims.x, -160 - kHitboxDims.y, 2 * kHeight }, &hallway2, &room2);

Room room3({ -357,-480 }, { -85,-307 }, {}, {}, {}, {});
Room hallway3({ -110,-307 }, { -85,-234 }, {}, {}, {}, {});
Door door5({ -110 + kHitboxDims.x, -234 - kHitboxDims.y, 0 }, { -85 - kHitboxDims.x, -234 + kHitboxDims.y, 2 * kHeight }, &room2, &hallway3);
Door door6({ -110 + kHitboxDims.x, -307 - kHitboxDims.y, 0 }, { -85 - kHitboxDims.x, -307 + kHitboxDims.y, 2 * kHeight }, &hallway3, &room3);

Room room4({ 12,-480 }, { 185,-283 }, {}, {}, { HitBox({37,-357,0},{160,-308,kWallHeight}) }, {});
Room hallway4({ -85,-380 }, { 12,-357 }, {}, {}, {}, {});
Door door7({ -85 - kHitboxDims.x, -381 + kHitboxDims.y, 0 }, { -85 + kHitboxDims.x, -357 - kHitboxDims.y, 2 * kHeight }, &room3, &hallway4);
Door door8({ 12 - kHitboxDims.x, -381 + kHitboxDims.y, 0 }, { 12 + kHitboxDims.x, -357 - kHitboxDims.y, 2 * kHeight }, &hallway4, &room4);

Room room5({ -258,-61 }, { -86,283 }, {}, {}, {}, {});
Room hallway5({ -408,-37 }, { -258,86 }, {}, {}, { HitBox({-380,-37,0},{-258,61,kWallHeight}) }, {});
Door door9({ -408 + kHitboxDims.x, -37 - kHitboxDims.y, 0 }, { -380 - kHitboxDims.x, -37 + kHitboxDims.y, 2 * kHeight }, &room1, &hallway5);
Door door10({ -258 - kHitboxDims.x, 61 + kHitboxDims.y, 0 }, { -258 + kHitboxDims.x, 86 - kHitboxDims.y, 2 * kHeight }, &hallway5, &room5);
Room hallway6({ -184,-160 }, { -160,-61 }, {}, {}, {}, {});
Door door11({ -184 + kHitboxDims.x, -160 - kHitboxDims.y, 0 }, { -160 - kHitboxDims.x, -160 + kHitboxDims.y, 2 * kHeight }, &room2, &hallway6);
Door door12({ -184 + kHitboxDims.x, -61 - kHitboxDims.y, 0 }, { -160 - kHitboxDims.x, -61 + kHitboxDims.y, 2 * kHeight }, &hallway6, &room5);

Room room6({ 61,-259 }, { 185,-135 }, {}, {}, { HitBox({ 86,-209,0 },{ 160,-184,kWallHeight }), HitBox({ 110,-233,0 },{ 135,-160,kWallHeight }) }, {});
Room hallway7({ 160,-283 }, { 185,-259 }, {}, {}, {}, {});
Door door13({ 160 + kHitboxDims.x, -283 - kHitboxDims.y, 0 }, { 185 - kHitboxDims.x, -283 + kHitboxDims.y, 2 * kHeight }, &room4, &hallway7);
Door door14({ 160 + kHitboxDims.x, -259 - kHitboxDims.y, 0 }, { 185 - kHitboxDims.x, -259 + kHitboxDims.y, 2 * kHeight }, &hallway7, &room6);

Room room7({ 37,-61 }, { 185,37 }, {}, {}, {}, {});
Room hallway8({ 110,-135 }, { 135,-61 }, {}, {}, {}, {});
Door door15({ 110 + kHitboxDims.x, -135 - kHitboxDims.y, 0 }, { 135 - kHitboxDims.x, -135 + kHitboxDims.y, 2 * kHeight }, &room6, &hallway8);
Door door16({ 110 + kHitboxDims.x, -61 - kHitboxDims.y, 0 }, { 135 - kHitboxDims.x, -61 + kHitboxDims.y, 2 * kHeight }, &hallway8, &room7);
Room hallway9({ -86,-37 }, { 37,-12 }, {}, {}, {}, {});
Door door17({ -86 - kHitboxDims.x, -37 + kHitboxDims.y, 0 }, { -86 + kHitboxDims.x, -12 - kHitboxDims.y, 2 * kHeight }, &room5, &hallway9);
Door door18({ 37 - kHitboxDims.x, -37 + kHitboxDims.y, 0 }, { 37 + kHitboxDims.x, -12 - kHitboxDims.y, 2 * kHeight }, &hallway9, &room7);

