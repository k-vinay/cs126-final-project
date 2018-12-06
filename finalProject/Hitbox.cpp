#include "src/Hitbox.h"

HitBox::HitBox()
{
	redefine({ 0,0,0 }, { 1,1,1 });
}

HitBox::HitBox(ofVec3f small, ofVec3f large)
{
	redefine(small, large);
}

HitBox::HitBox(float x1, float y1, float z1, float x2, float y2, float z2)
{
	redefine(x1, y1, z1, x2, y2, z2);
}

HitBox::HitBox(ofVec3f centerPt, float dimX, float dimY, float dimZ)
{
	redefine(centerPt, dimX, dimY, dimZ);
}

HitBox::~HitBox()
{
}


void HitBox::move(float x, float y, float z)
{
	redefine(smallest.x+x, smallest.y+y, smallest.z+z, largest.x+x, largest.y+y, largest.z+z );
}

void HitBox::resize(float x, float y, float z)
{
	redefine(center, x, y, z);
}


void HitBox::redefine(ofVec3f small, ofVec3f large)
{
	smallest = small;
	largest = large;
	center = small.getMiddle(large);
}

void HitBox::redefine(float x1, float y1, float z1, float x2, float y2, float z2)
{
	redefine({ x1,y1,z1 }, { x2,y2,z2 });
}

void HitBox::redefine(ofVec3f centerPt, float dimX, float dimY, float dimZ)
{
	center = centerPt;

	float x = abs(dimX);
	float y = abs(dimY);
	float z = abs(dimZ);

	smallest = { center.x - (x / 2), center.y - (y / 2), center.z - (z / 2) };
	largest = { center.x + (x / 2), center.y + (y / 2), center.z + (z / 2) };
}


bool HitBox::intersects(ofVec3f point)
{
	if ((smallest.x < point.x) && (smallest.y < point.y) && (smallest.z < point.z))
		if ((largest.x > point.x) && (largest.y > point.y) && (largest.z > point.z))
			return true;
	return false;
}

bool HitBox::IsHitting(HitBox & other)
{
	if ((other.smallest.x > largest.x) || (other.largest.x < smallest.x))
		return false;
	if ((other.smallest.y > largest.y) || (other.largest.y < smallest.y))
		return false;
	if ((other.smallest.z > largest.z) || (other.largest.z < smallest.z))
		return false;
	return true;
}

bool HitBox::contains(HitBox & other)
{
	return ((smallest.x < other.smallest.x) && (largest.x > other.largest.x)
		&& (smallest.y < other.smallest.y) && (largest.y > other.largest.y)
		&& (smallest.z < other.smallest.z) && (largest.z > other.largest.z));
}
