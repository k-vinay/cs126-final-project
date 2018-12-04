#include "src/World.h"

World::World()
{
}


World::~World()
{
}

void World::setup()
{
	map.loadModel("map.dae");
	map.setPosition(0, 0, 0);
	map.setRotation(0, 90, 1, 0, 0);
}

void World::update(float frames)
{
	current_room->update(frames);
}

void World::draw()
{
	map.drawFaces();
}
