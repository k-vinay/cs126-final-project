#pragma once
#include "Enemy.h"
#include <vector>
#include "Hitbox.h"

class Room
{
	ofVec2f small_corner;
	ofVec2f big_corner;
	std::vector<ofVec2f> doors;
	
	std::vector<Enemy> enemies;
	std::vector<ofVec2f> enemy_spawns;
	std::vector<HitBox> walls;
	std::vector<HitBox> pits;

public:
	Room(ofVec2f small, ofVec2f big, std::vector<ofVec2f> doorList, std::vector<Enemy> enemyList, std::vector<ofVec2f> enemySpawnList, std::vector<HitBox> walls, std::vector<HitBox> pits);
	~Room();

	ofVec2f get_small_corner();
	ofVec2f get_big_corner();
	std::vector<ofVec2f> get_doors();

};

