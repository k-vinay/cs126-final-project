#include "src/Room.h"

Room::Room(ofVec2f small, ofVec2f big, std::vector<Door> doorList, std::vector<Enemy> enemyList, std::vector<ofVec2f> enemySpawnList, std::vector<HitBox> wallList, std::vector<HitBox> pitList)
{
	small_corner = small;
	big_corner = big;
	doors = doorList;
	enemies = enemyList;
	enemy_positions = enemySpawnList;
	walls = wallList;
	pits = pitList;
}

Room::~Room()
{
}

void Room::update(float frames)
{
}

ofVec2f Room::get_small_corner()
{
	return ofVec2f();
}

ofVec2f Room::get_big_corner()
{
	return ofVec2f();
}

std::vector<ofVec2f> Room::get_doors()
{
	return std::vector<ofVec2f>();
}
