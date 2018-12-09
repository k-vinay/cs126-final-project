#pragma once

#include "ofMain.h"

class HitBox
{
	ofVec3f smallest;
	ofVec3f center;
	ofVec3f largest;

public:
	HitBox();
	HitBox(ofVec3f smallest, ofVec3f largest);
	HitBox(float x1, float y1, float z1, float x2, float y2, float z2);
	HitBox(ofVec3f center, float dimX, float dimY, float dimZ);
	~HitBox();

	void move(float x, float y, float z);
	void resize(float x, float y, float z);
	void redefine(ofVec3f small, ofVec3f large);
	void redefine(float x1, float y1, float z1, float x2, float y2, float z2);
	void redefine(ofVec3f center, float dimX, float dimY, float dimZ);
	
	bool intersects(ofVec3f point);
	bool IsHitting(HitBox &other);
	bool contains(HitBox &other);

	ofVec3f get_position();
};