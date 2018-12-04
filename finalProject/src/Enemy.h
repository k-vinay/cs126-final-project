#pragma once
#include "Hitbox.h"
#include "ofxAssimpModelLoader.h"
#include "Gun.h"

class Enemy
{
	HitBox hitbox;

	std::string model_file;
	ofxAssimpModelLoader model;
	std::string type;
	Gun gun;

public:
	Enemy();
	~Enemy();

	void update(float frames);

	std::string get_type();
};

