#pragma once
#include "Enemy.h"
#include <vector>
#include "Hitbox.h"
#include "Constants.h"

class Room;

class Door
{
public:
	HitBox doorway;
	Room* next;

	Door(ofVec3f small, ofVec3f big, Room* nextRoom)
		:doorway(small, big)
	{
		next = nextRoom;
	}

};

class Room
{
	ofVec2f small_corner;
	ofVec2f big_corner;
	HitBox room;
	std::vector<Door*> doors;
	
	std::vector<Enemy> enemies;
	std::vector<ofVec2f> enemy_positions;
	std::vector<HitBox> walls;
	std::vector<HitBox> pits;

public:
	Room();
	Room(ofVec2f small, ofVec2f big, std::vector<Enemy> enemyList, std::vector<ofVec2f> enemySpawnList, std::vector<HitBox> walls, std::vector<HitBox> pits);
	~Room();

	void addDoor(Door* door);

	void update(float frames);

	bool isValidPosition(HitBox player);

	ofVec2f get_small_corner();
	ofVec2f get_big_corner();
	std::vector<ofVec2f> get_doors();
};

