#include "src/Gun.h"

Gun::Gun(std::string n, int m_a, int aps, int ms, std::string model_name)
{
	name = n;
	max_ammo = m_a;
	ammo = max_ammo;
	ammo_per_shot = aps;
	mag_size = ms;
	model_file = model_name;

	//model.loadModel(model_file);
}

Gun::~Gun()
{
}

void Gun::setPosition(ofVec3f pos)
{
	//model.setPosition(pos.x, pos.y, pos.z);
}

void Gun::reload()
{
	current_mag = mag_size;
	time_since_last_reload = 0;
}

void Gun::shoot()
{
	current_mag--;
}

std::string Gun::get_name()
{
	return name;
}

int Gun::get_ammo()
{
	return ammo;
}

int Gun::get_ammo_per_shot()
{
	return ammo_per_shot;
}

int Gun::get_mag_size()
{
	return mag_size;
}

int Gun::get_current_mag()
{
	return current_mag;
}

//ofxAssimpModelLoader Gun::get_model()
//{
//	return model;
//}
