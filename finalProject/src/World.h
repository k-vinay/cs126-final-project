#pragma once
#include "Room.h"
#include "ofxAssimpModelLoader.h"

class World
{
	std::vector<Room> rooms;

	ofxAssimpModelLoader map;

public:
	World();
	~World();

	void setup();
	void update(float frames);
};

