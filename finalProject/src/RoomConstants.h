#pragma once
#include "Room.h"
#include "ofMain.h"
#include "Constants.h"

//this file probably wont make sense unless you refer to
//"bin/data/map.png" - a labelled drawing of the map

Room startRoom({ -480, -480 }, { -380, -380 }, {}, {}, {}, {});

Room room1({ -480,-282 }, { -308,-37 }, {}, {}, {},{
		HitBox({ -480,-209,0 }, { -455,-184,kPitBoxHeight }),
		HitBox({ -480,-135,0 }, { -455,-110,kPitBoxHeight }),
		HitBox({ -333,-209,0 }, { -308,-184,kPitBoxHeight }),
		HitBox({ -333,-135,0 }, { -308,-110,kPitBoxHeight }),
		HitBox({ -432,-234,0 }, { -408,-86,kPitBoxHeight }),
		HitBox({ -380,-234,0 }, { -357,-86,kPitBoxHeight }),
	});
Room hallway1({ -408, -380 }, { -380, -280 }, {}, {}, {}, {});
Door door1({ -408 + kHitboxDims.x, -380 - kHitboxDims.y, 0 }, { -380 - kHitboxDims.x, -380 + kHitboxDims.y, 2 * kHeight }, &startRoom, &hallway1);
Door door2({ -408 + kHitboxDims.x, -282 - kHitboxDims.y, 0 }, { -380 - kHitboxDims.x, -282 + kHitboxDims.y, 2 * kHeight }, &hallway1, &room1);

Room room2({ -184,-234 }, { -37,-160 }, {}, {}, {}, {});
Room hallway2({ -308,-184 }, { -184,-160 }, {}, {}, {}, {});
Door door3({ -308 - kHitboxDims.x, -184 + kHitboxDims.y, 0 }, { -308 + kHitboxDims.x, -160 - kHitboxDims.y, 2 * kHeight }, &room1, &hallway2);
Door door4({ -184 - kHitboxDims.x, -184 + kHitboxDims.y, 0 }, { -184 + kHitboxDims.x, -160 - kHitboxDims.y, 2 * kHeight }, &hallway2, &room2);

Room room3({ -357,-480 }, { -85,-307 }, {}, {}, {}, { 
	HitBox({ -283,-480,0 },{ -258,-307,kPitBoxHeight }),
	HitBox({ -184,-480,0 },{ -160,-307,kPitBoxHeight })
	});
Room hallway3({ -110,-307 }, { -85,-234 }, {}, {}, {}, {});
Door door5({ -110 + kHitboxDims.x, -234 - kHitboxDims.y, 0 }, { -85 - kHitboxDims.x, -234 + kHitboxDims.y, 2 * kHeight }, &room2, &hallway3);
Door door6({ -110 + kHitboxDims.x, -307 - kHitboxDims.y, 0 }, { -85 - kHitboxDims.x, -307 + kHitboxDims.y, 2 * kHeight }, &hallway3, &room3);

Room room4({ 12,-480 }, { 185,-283 }, {}, {}, {
	HitBox({37,-357,0},{160,-308,kWallHeight})
	}, {});
Room hallway4({ -85,-380 }, { 12,-357 }, {}, {}, {}, {});
Door door7({ -85 - kHitboxDims.x, -381 + kHitboxDims.y, 0 }, { -85 + kHitboxDims.x, -357 - kHitboxDims.y, 2 * kHeight }, &room3, &hallway4);
Door door8({ 12 - kHitboxDims.x, -381 + kHitboxDims.y, 0 }, { 12 + kHitboxDims.x, -357 - kHitboxDims.y, 2 * kHeight }, &hallway4, &room4);

Room room5({ -258,-61 }, { -86,283 }, {}, {}, {}, {
	HitBox({ -209,-12,0 },{ -135,36,kPitBoxHeight }),
	HitBox({ -209,86,0 },{ -135,136,kPitBoxHeight }),
	HitBox({ -209,185,0 },{ -135,234,kPitBoxHeight })
	});
Room hallway5({ -405,-37 }, { -258,86 }, {}, {}, { 
	HitBox({-380,-37,0},{-258,61,kWallHeight})
	}, {});
Door door9({ -405 + kHitboxDims.x, -37 - kHitboxDims.y, 0 }, { -380 - kHitboxDims.x, -37 + kHitboxDims.y, 2 * kHeight }, &room1, &hallway5);
Door door10({ -258 - kHitboxDims.x, 61 + kHitboxDims.y, 0 }, { -258 + kHitboxDims.x, 86 - kHitboxDims.y, 2 * kHeight }, &hallway5, &room5);
Room hallway6({ -184,-160 }, { -160,-61 }, {}, {}, {}, {});
Door door11({ -184 + kHitboxDims.x, -160 - kHitboxDims.y, 0 }, { -160 - kHitboxDims.x, -160 + kHitboxDims.y, 2 * kHeight }, &room2, &hallway6);
Door door12({ -184 + kHitboxDims.x, -61 - kHitboxDims.y, 0 }, { -160 - kHitboxDims.x, -61 + kHitboxDims.y, 2 * kHeight }, &hallway6, &room5);

Room room6({ 61,-259 }, { 185,-135 }, {}, {}, {
	HitBox({ 86,-209,0 },{ 160,-184,kWallHeight }),
	HitBox({ 110,-233,0 },{ 135,-160,kWallHeight })
	}, {});
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

Room room8({ 37,61 }, { 185,209 }, {}, {}, {
	HitBox({ 85,160,0 },{ 135,209,kWallHeight })
	}, {
	HitBox({ 135,61,0 },{ 185,209,kPitBoxHeight }),
	HitBox({ 37,61,0 }, { 85,136,kPitBoxHeight }),
	HitBox({ 60,61,0 }, { 85,209,kPitBoxHeight }),
	HitBox({ 37,85,0 }, { 185,110,kPitBoxHeight })
	});
Room hallway10({ 86,37 }, { 110,61 }, {}, {}, {}, {});
Door door19({ 86 + kHitboxDims.x, 37 - kHitboxDims.y, 0 }, { 110 - kHitboxDims.x, 37 + kHitboxDims.y, 2 * kHeight }, &room7, &hallway10);
Door door20({ 86 + kHitboxDims.x, 61 - kHitboxDims.y, 0 }, { 110 - kHitboxDims.x, 61 + kHitboxDims.y, 2 * kHeight }, &hallway10, &room8);

Room room9({ 37,234 }, { 135,332 }, {}, {}, {}, {});
Room hallway11({ -12,136 }, { 37, 307 }, {}, {}, {
	HitBox({ 12,160,0 },{ 37,283,kWallHeight })
	}, {});
Door door21({ 37 - kHitboxDims.x, 136 + kHitboxDims.y, 0 }, { 37 + kHitboxDims.x, 160 - kHitboxDims.y, 2 * kHeight }, &room8, &hallway11);
Door door22({ 37 - kHitboxDims.x, 283 + kHitboxDims.y, 0 }, { 37 + kHitboxDims.x, 307 - kHitboxDims.y, 2 * kHeight }, &hallway11, &room9);

Room room10({ 209,258 }, { 332,332 }, {}, {}, {}, {});
Room hallway12({ 135,283 }, { 209,307 }, {}, {}, {}, {});
Door door23({ 135 - kHitboxDims.x, 283 + kHitboxDims.y, 0 }, { 135 + kHitboxDims.x, 307 - kHitboxDims.y, 2 * kHeight }, &room9, &hallway12);
Door door24({ 209 - kHitboxDims.x, 283 + kHitboxDims.y, 0 }, { 209 + kHitboxDims.x, 307 - kHitboxDims.y, 2 * kHeight }, &hallway12, &room10);

Room room11({ 209,-259 }, { 480,209 }, {}, {}, {}, {});
Room hallway13({ 234,209 }, { 283,258 }, {}, {}, {}, {});
Door door25({ 234 + kHitboxDims.x, 258 - kHitboxDims.y, 0 }, { 283 - kHitboxDims.x, 258 + kHitboxDims.y, 2 * kHeight }, &room10, &hallway13);
Door door26({ 234 + kHitboxDims.x, 209 - kHitboxDims.y, 0 }, { 283 - kHitboxDims.x, 209 + kHitboxDims.y, 2 * kHeight }, &hallway13, &room11);

Room room12({ 357,283 }, { 480,480 }, {}, {}, {
	HitBox({ 430,332,0 },{ 480,357,kWallHeight }),
	HitBox({ 430,406,0 },{ 480,431,kWallHeight })
	}, {});
Room hallway14({ 430,209 }, { 455,283 }, {}, {}, {}, {});
Door door27({ 430 + kHitboxDims.x, 209 - kHitboxDims.y, 0 }, { 455 - kHitboxDims.x, 209 + kHitboxDims.y, 2 * kHeight }, &room11, &hallway14);
Door door28({ 430 + kHitboxDims.x, 283 - kHitboxDims.y, 0 }, { 455 - kHitboxDims.x, 283 + kHitboxDims.y, 2 * kHeight }, &hallway14, &room12);

Room room13({ 86,357 }, { 234,480 }, {}, {}, {
	HitBox({160,381,0},{234,480,kWallHeight})
	}, {});
Room hallway15({ 37,332 }, { 86,430 }, {}, {}, {
	HitBox({61,332,0},{86,406,kWallHeight})
	}, {});
Door door29({ 37 + kHitboxDims.x, 332 - kHitboxDims.y, 0 }, { 61 - kHitboxDims.x, 332 + kHitboxDims.y, 2 * kHeight }, &room9, &hallway15);
Door door30({ 86 - kHitboxDims.x, 406 + kHitboxDims.y, 0 }, { 86 + kHitboxDims.x, 430 - kHitboxDims.y, 2 * kHeight }, &hallway15, &room13);

Room room14({ 209,-480 }, { 357,-332 }, {}, {}, {}, {});
Room hallway18({ 185,-455 }, { 209,-430 }, {}, {}, {}, {});
Door door31({ 185 - kHitboxDims.x, -455 + kHitboxDims.y, 0 }, { 185 + kHitboxDims.x, -430 - kHitboxDims.y, 2 * kHeight }, &room4, &hallway18);
Door door32({ 209 - kHitboxDims.x, -455 + kHitboxDims.y, 0 }, { 209 + kHitboxDims.x, -430 - kHitboxDims.y, 2 * kHeight }, &hallway18, &room14);

Room room15({ 406,-430 }, { 480,-357 }, {}, {}, {}, {});
Room hallway19({ 357,-405 }, { 406,-380 }, {}, {}, {}, {});
Door door33({ 357 - kHitboxDims.x, -405 + kHitboxDims.y, 0 }, { 357 + kHitboxDims.x, -380 - kHitboxDims.y, 2 * kHeight }, &room14, &hallway19);
Door door34({ 406 - kHitboxDims.x, -405 + kHitboxDims.y, 0 }, { 406 + kHitboxDims.x, -380 - kHitboxDims.y, 2 * kHeight }, &hallway19, &room15);

Room room16({ -432,160 }, { -357,234 }, {}, {}, {}, {});
Room hallway16({ -357,185 }, { -258,209 }, {}, {}, {}, {});
Door door35({ -258 - kHitboxDims.x, 185 + kHitboxDims.y, 0 }, { -258 + kHitboxDims.x, 209 - kHitboxDims.y, 2 * kHeight }, &room5, &hallway16);
Door door36({ -357 - kHitboxDims.x, 185 + kHitboxDims.y, 0 }, { -357 + kHitboxDims.x, 209 - kHitboxDims.y, 2 * kHeight }, &hallway16, &room16);

Room room17({ -356,308 }, { -135, 480 }, {}, {}, {
	HitBox({ -333,332,0 },{ -283,381,kWallHeight }),
	HitBox({ -209,332,0 }, {-160,381,kWallHeight }),
	HitBox({ -333,406,0 }, {-283,455,kWallHeight }),
	HitBox({ -209,332,0 }, {-160,455,kWallHeight })
	}, {});
Room hallway17({ -258,283 }, { -233,308 }, {}, {}, {}, {});
Door door37({ -258 + kHitboxDims.x, 283 - kHitboxDims.y, 0 }, { -233 - kHitboxDims.x, 283 + kHitboxDims.y, 2 * kHeight }, &room5, &hallway17);
Door door38({ -258 + kHitboxDims.x, 308 - kHitboxDims.y, 0 }, { -233 - kHitboxDims.x, 308 + kHitboxDims.y, 2 * kHeight }, &hallway17, &room17);
