#include "src/Room.h"

Room::Room()
{
}

Room::Room(ofVec2f small, ofVec2f big, std::vector<Enemy> enemyList, std::vector<HitBox> wallList, std::vector<HitBox> pitList)
{
	small_corner = small;
	big_corner = big;
	enemies = enemyList;
	walls = wallList;
	pits = pitList;
	room = HitBox(small.x, small.y, 0, big.x, big.y, kWallHeight);
	is_cleared = false;
}

Room::~Room()
{
}

void Room::unload()
{
	bullets.clear();
	enemies.clear();
}

void Room::addDoor(Door* door)
{
	doors.push_back(door);
}

void Room::addBullet(Bullet bullet)
{
	bullets.push_back(bullet);
}

void Room::update(float frames, bool cleared)
{
	for (Bullet& bullet : bullets)
	{
		bullet.hitbox.move(bullet.velocity.x, bullet.velocity.y, bullet.velocity.z);
		if (!room.contains(bullet.hitbox))
			bullet.is_active = false;
		else
		{
			for (Enemy& enemy : enemies)
			{
				if (bullet.is_active && enemy.get_health()>0 && bullet.hitbox.IsHitting(enemy.get_box()))
				{
					bullet.is_active = false;
					enemy.get_hit();
				}
			}
		}
		
	}
	is_cleared = cleared;
}

void Room::draw()
{
}

int Room::isValidPosition(HitBox player)
{
	if (!room.contains(player) && !(isInDoor(player) && is_cleared))
		return 0;
	for (HitBox wall : walls)
	{
		if (wall.IsHitting(player))
			return 0;
	}
	for (Enemy enemy : enemies)
	{
		if (enemy.get_box().IsHitting(player) && enemy.get_health() > 0)
			return -1;
	}
	return 1;
}

int Room::getState(HitBox player)
{
	if (isInDoor(player))
		return 1;
	for (HitBox pit : pits)
	{
		if (pit.contains(player))
			return -1;
	}
	for (Enemy enemy : enemies)
	{
		if (enemy.get_box().IsHitting(player))
			return -2;
	}
	return 0;
}

Door* Room::isInDoor(HitBox player)
{
	for (Door* door : doors)
	{
		if (player.IsHitting(door->doorway))
			return door;
	}
	return nullptr;
}

ofVec2f Room::get_small_corner()
{
	return ofVec2f();
}

ofVec2f Room::get_big_corner()
{
	return ofVec2f();
}

std::vector<Bullet> Room::get_bullets()
{
	return bullets;
}

std::vector<ofVec2f> Room::get_doors()
{
	return std::vector<ofVec2f>();
}

std::vector<Enemy> Room::get_enemies()
{
	return enemies;
}

HitBox Room::get_box()
{
	return room;
}

Door::Door(ofVec3f small, ofVec3f big, Room * firstRoom, Room * secondRoom)
	:doorway(small, big)
{
	room1 = firstRoom;
	room2 = secondRoom;

	room1->addDoor(this);
	room2->addDoor(this);
}

Room * Door::useDoor(Room * current_room, HitBox player)
{
	if (player.IsHitting(current_room->get_box()))
		return current_room;

	current_room->unload();

	if (current_room == room1)
		return room2;
	if (current_room == room2)
		return room1;
	return nullptr;
}
