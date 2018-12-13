#include "src/Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(float dir, int t, ofVec2f spawn)
{
	type = (t - 1) % kEnemyTypes;
	direction = dir;

	model_file = kEnemyData[type].filename;
	health = kEnemyData[type].health;
	//gun = kEnemyData[type].gun;
	ofVec3f hitbox_dims = kEnemyData[type].hitbox_dims;
	hitbox = HitBox({ spawn.x,spawn.y,(hitbox_dims.z+(float)0.1)/2 }, hitbox_dims.x, hitbox_dims.y, hitbox_dims.z);

	/*model.loadModel("bullet-kin.dae");

	model.setRotation(0, 90, 1, 0, 0);
	model.setScale(kGundeadScale, kGundeadScale, kGundeadScale);
	model.setPosition(spawn.x, spawn.y, 0);*/

}

Enemy::~Enemy()
{
}

void Enemy::update(float frames, ofVec3f player, ofxAssimpModelLoader& model)
{
	time_since_hit += frames;
	is_i_frame = (time_since_hit > iframes);
	//model.setRotation(model.getNumRotations(), 5, 0, 1, 0);
	model.setPosition(hitbox.get_position().x, hitbox.get_position().y, 0);
}

void Enemy::draw()
{
	//model.drawFaces();
}

void Enemy::get_hit()
{
	health--;
}


std::string Enemy::get_file()
{
	return model_file;
}

ofVec2f Enemy::get_position()
{
	return { hitbox.get_position().x, hitbox.get_position().y };
}

float Enemy::get_direction()
{
	return direction;
}

int Enemy::get_health()
{
	return health;
}

int Enemy::get_type()
{
	return type;
}

HitBox Enemy::get_box()
{
	return hitbox;
}


