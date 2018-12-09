#pragma once
#include "ofxAssimpModelLoader.h"
#include "Gun.h"
#include "ofMain.h"
#include "Constants.h"
#include "Hitbox.h"
#include "World.h"

class Player
{
	World* world_ptr;

	HitBox hitbox;
	int health;
	std::vector<Gun> guns;

	bool keyDown[255];
	bool mouse[3];

	bool is_zoomed;
	bool is_jumping;
	bool pitfall;
	
	ofVec3f speed;
	ofVec3f last_ground;
public:

	ofCamera camera;

	Player();
	~Player();

	void setup(World* world);
	void update(float frames);

	void begin();
	void end();

	void move(ofVec3f displacement);
	void setPosition(ofVec3f pos);

	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mousePressed(int button);
	void mouseReleased(int button);

	ofVec3f getPosition();
};

