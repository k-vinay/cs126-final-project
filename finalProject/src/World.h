#pragma once
#include "Room.h"
#include "ofxAssimpModelLoader.h"

class World
{
	std::vector<Room> rooms;
	ofxAssimpModelLoader map;

	Room *current_room;

public:
	World();
	~World();

	void setup();
	void update(float frames);

	void draw();
};

