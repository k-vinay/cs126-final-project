#include "src/Room.h"

Room::Room()
{
}

Room::Room(ofVec2f small, ofVec2f big, std::vector<Enemy> enemyList, std::vector<ofVec2f> enemySpawnList, std::vector<HitBox> wallList, std::vector<HitBox> pitList)
{
	small_corner = small;
	big_corner = big;
	enemies = enemyList;
	enemy_positions = enemySpawnList;
	walls = wallList;
	pits = pitList;
	room = HitBox(small.x, small.y, 0, big.x, big.y, kHeight*20);
}

Room::~Room()
{
}

void Room::addDoor(Door* door)
{
	doors.push_back(door);
}

void Room::update(float frames)
{
}

bool Room::isValidPosition(HitBox player)
{
	if (!room.contains(player))
		return false;
	for (HitBox wall : walls)
	{
		if (wall.IsHitting(player))
			return false;
	}
	return true;
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
