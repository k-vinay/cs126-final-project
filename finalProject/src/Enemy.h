#pragma once
#include "Hitbox.h"
#include "ofxAssimpModelLoader.h"
#include "Gun.h"
#include "Constants.h"

//use type = 1 for bullet kin
//use type = 2 for shotgun kin


class Enemy
{
	HitBox hitbox;
	std::string model_file;
	//ofxAssimpModelLoader model;
	int type;
	int health;
	//Gun gun;

	bool is_i_frame;
	float time_since_hit;

	float direction;

public:
	Enemy();
	Enemy(float dir, int type, ofVec2f spawn);
	~Enemy();

	void update(float frames, ofVec3f player, ofxAssimpModelLoader& model);

	void draw();
	void get_hit();

	std::string get_file();
	ofVec2f get_position();
	float get_direction();
	int get_health();
	int get_type();
	HitBox get_box();
};

