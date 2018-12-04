#pragma once
#include "ofxAssimpModelLoader.h"
#include "Gun.h"
#include "ofMain.h"
#include "Constants.h"
#include "Hitbox.h"
#include "World.h"

class Player
{
	HitBox hitbox;
	int health;
	std::vector<Gun> guns;

	bool keyDown[255];
public:

	ofCamera camera;

	Player();
	~Player();

	void setup();
	void update(float frames);

	void move(ofVec3f displacement);

	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);

	ofVec3f getPosition();
};

