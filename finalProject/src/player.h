#pragma once
#include "ofxAssimpModelLoader.h"
#include "Gun.h"
#include "ofMain.h"

class Player
{
	
	int health;
	std::vector<Gun> guns;

	bool keyDown[255];
public:

	ofCamera camera;

	Player();
	~Player();

	void setup();
	void update(float frames);

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
};

