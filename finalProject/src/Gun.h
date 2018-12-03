#pragma once
#include "ofxAssimpModelLoader.h"

class Gun
{
	std::string name;
	int max_ammo;
	int ammo;
	int ammo_per_shot;
	int mag_size;
	int current_mag;
	float reload_time;
	float time_since_last_reload;

	std::string model_file;
	ofxAssimpModelLoader model;

public:
	Gun(std::string n, int m_a, int aps, int ms, std::string model_name);
	~Gun();

	void setPosition(ofVec3f pos);
	void reload();
	void shoot();

	void update(float frames);

	std::string get_name();
	int get_ammo();
	int get_ammo_per_shot();
	int get_mag_size();
	int get_current_mag();
	//ofxAssimpModelLoader get_model();
};

