#pragma once
#include "ofxAssimpModelLoader.h"
#include "Gun.h"
#include "ofMain.h"
#include "Constants.h"
#include "Hitbox.h"
#include "World.h"

class Player
{
	ofImage health_bar[7];

	World* world_ptr;

	HitBox hitbox;
	int health;

	bool keyDown[255];
	bool mouse[3];

	ofImage normal_hud;
	ofImage zoomed_hud;

	bool is_zoomed;
	bool is_jumping;
	bool pitfall;

	bool can_shoot;
	float shoot_delay_frames = 15;
	float frames_since_last_shot;

	float frames_since_last_damage;

	ofVec3f speed;
	ofVec3f last_ground;

	float cam_tilt;
public:

	ofCamera camera;

	Player();
	~Player();

	void setup(World* world);
	void update(float frames);

	void begin();
	void end();
	void draw();

	void move(ofVec3f displacement);
	void setPosition(ofVec3f pos);

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mousePressed(int button);
	void mouseReleased(int button);

	ofVec3f getPosition();
};

