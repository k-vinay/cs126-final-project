#pragma once
#include "Room.h"
#include "ofxAssimpModelLoader.h"

class World
{
	std::vector<Room> rooms;
	ofxAssimpModelLoader map;

public:
	Room* current_room;

	World();
	~World();

	void setup();
	void update(float frames);

	void draw();
};

