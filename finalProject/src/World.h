#pragma once
#include "Room.h"
#include "ofxAssimpModelLoader.h"
#include "Constants.h"

class World
{
	std::vector<Room> rooms;
	ofxAssimpModelLoader map;
	ofxAssimpModelLoader doors;
	std::vector<Enemy> loaded_enemies;
	std::vector<ofxAssimpModelLoader> loaded_enemy_models;
	
	Room* loaded_room;
	int enemies_alive;
	bool room_is_cleared;

public:
	Room* current_room;
	HitBox* player_hitbox;

	World();
	~World();

	void setup();
	void update(float frames);

	void loadRoom();

	void draw();
};

