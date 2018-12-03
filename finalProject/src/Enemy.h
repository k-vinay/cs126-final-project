#pragma once
#include "Hitbox.h"
#include "ofxAssimpModelLoader.h"

class Enemy
{
	HitBox hitbox;

	std::string model_file;
	ofxAssimpModelLoader model;

public:
	Enemy();
	~Enemy();

	void update(float frames);

	virtual std::string getType() = 0;
};

