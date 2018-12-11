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

	current_room = &startRoom;
}

void World::update(float frames)
{
	if (loaded_room != current_room)
		loadRoom();
	for (int i = 0; i < loaded_enemies.size(); i++)
	{
		loaded_enemies[i].update(frames, player_hitbox->get_position(), loaded_enemy_models[i]);
	}
}

void World::loadRoom()
{
	loaded_enemies = current_room->get_enemies();
	loaded_enemy_models = std::vector<ofxAssimpModelLoader>();
	
	for (Enemy enemy : loaded_enemies)
	{
		ofxAssimpModelLoader model;
		model.loadModel(enemy.get_file());
		model.setRotation(0, 90, 1, 0, 0);
		
		if (enemy.get_type() == 0)  //bullet
			model.setRotation(1, 180, 0, 1, 0);
		else if (enemy.get_type() == 1)  //shotgun
			model.setRotation(1, 90, 0, 1, 0);
		
		model.setScale(kGundeadScale, kGundeadScale, kGundeadScale);
		loaded_enemy_models.push_back(model);
	}

	loaded_room = current_room;
}

void World::draw()
{
	map.drawFaces();
	current_room->draw();

	ofLight enemy_light;
	enemy_light.enable();
	for (ofxAssimpModelLoader model : loaded_enemy_models)
	{
		enemy_light.setPosition(model.getPosition());
		enemy_light.move({ 0,0,5 });
		model.drawFaces();
	}
	enemy_light.disable();
}
