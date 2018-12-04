#pragma once
#include "Enemy.h"
#include <vector>
#include "Hitbox.h"
#include "player.h"

class Room;

struct Door
{
	ofVec2f position;
	Room* next;
};

class Room
{
	ofVec2f small_corner;
	ofVec2f big_corner;
	std::vector<Door> doors;
	
	std::vector<Enemy> enemies;
	std::vector<ofVec2f> enemy_positions;
	std::vector<HitBox> walls;
	std::vector<HitBox> pits;

public:
	Room(ofVec2f small, ofVec2f big, std::vector<Door> doorList, std::vector<Enemy> enemyList, std::vector<ofVec2f> enemySpawnList, std::vector<HitBox> walls, std::vector<HitBox> pits);
	~Room();

	void update(float frames);

	ofVec2f get_small_corner();
	ofVec2f get_big_corner();
	std::vector<ofVec2f> get_doors();

};

