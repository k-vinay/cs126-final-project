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

	doors.loadModel("map-with-doors.dae");
	doors.setPosition(0, 0, 0);
	doors.setRotation(0, 90, 1, 0, 0);
	doors.setScale(kMapScale, kMapScale, kMapScale);

	bullet_model.loadModel("bullet.dae");
	bullet_model.setScale(kBulletScale, kBulletScale, kBulletScale);
	
	current_room = &startRoom;
}

void World::update(float frames)
{
	loaded_enemies = current_room->get_enemies();
	if (loaded_room != current_room)
		loadRoom();

	bullets = current_room->get_bullets();

	enemies_alive = loaded_enemies.size();
	for (int i = 0; i < loaded_enemies.size(); i++)
	{
		loaded_enemies[i].update(frames, player_hitbox->get_position(), loaded_enemy_models[i]);
		if (loaded_enemies[i].get_health() <= 0)
			enemies_alive--;
	}
	room_is_cleared = (enemies_alive == 0);
	current_room->update(frames, room_is_cleared);
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

	if (!room_is_cleared)
		doors.drawFaces();
	else
		map.drawFaces();

	current_room->draw();

	for (Bullet bullet : bullets)
	{
		if (bullet.is_active)
		{
			ofVec3f pos = bullet.hitbox.get_position();
			bullet_model.setPosition(pos.x, pos.y, pos.z);
			bullet_model.drawVertices();
		}
	}

	ofLight enemy_light;
	enemy_light.enable();
	for (int i = 0; i < loaded_enemy_models.size(); i++)
	{
		ofxAssimpModelLoader model = loaded_enemy_models[i];
		Enemy enemy = loaded_enemies[i];

		enemy_light.setPosition(model.getPosition());
		enemy_light.move({ 0,0,5 });
		if (enemy.get_health() > 0)
			model.drawFaces();
	}
	enemy_light.disable();

}
