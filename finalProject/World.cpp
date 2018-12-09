#include "src/World.h"
#include "src/RoomConstants.h"

World::World()
{
	current_room = new Room();
}

World::~World()
{
}


void World::setup()
{
	map.loadModel("map.dae");
	map.setPosition(0, 0, 0);
	map.setRotation(0, 90, 1, 0, 0);
	map.setScale(kMapScale, kMapScale, kMapScale);

	initializeRooms();
}

void World::update(float frames)
{
	current_room->update(frames);
}

void World::draw()
{
	map.drawFaces();
}

void World::initializeRooms()
{
	startRoom.addDoor(&door1);

	current_room = &startRoom;
}
