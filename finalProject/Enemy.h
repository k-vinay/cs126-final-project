#pragma once
#include "Hitbox.h"

class Enemy
{
	HitBox hitbox;

public:
	Enemy();
	~Enemy();

	virtual void update();

	virtual int getType();
};

