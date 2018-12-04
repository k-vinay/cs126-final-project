#include "src/player.h"

Player::Player()
{
	
}


Player::~Player()
{
}

void Player::setup()
{
	camera.setGlobalPosition(spawn);
	ofHideCursor();
}

void Player::update(float frames)
{
	ofVec3f player_pos = camera.getGlobalPosition();
	float x = player_pos.x;
	float y = player_pos.y;
	float z = player_pos.z;

	if (keyDown['w'])
		camera.dolly(-kMoveSpeed);
	if (keyDown['s'])
		camera.dolly(kMoveSpeed);
	if (keyDown['a'])
		camera.truck(-kMoveSpeed);
	if (keyDown['d'])
		camera.truck(kMoveSpeed);

	float x_diff = camera.getGlobalPosition().x - x;
	float y_diff = camera.getGlobalPosition().y - y;
	float z_diff = camera.getGlobalPosition().z - z;

	camera.setPosition(player_pos);

	if (!(x_diff == 0 && y_diff == 0))
	{
		float scale = kMoveSpeed / sqrtf((x_diff*x_diff) + (y_diff*y_diff));
		x_diff *= scale;
		y_diff *= scale;
	}
	z_diff = 0;
	
	move({ frames*x_diff,frames*y_diff,0 });
}

void Player::move(ofVec3f displacement)
{
	camera.move(displacement);
	hitbox.move(displacement.x, displacement.y, displacement.z);
}

void Player::draw()
{
}

void Player::keyPressed(int key)
{
	keyDown[key] = true;
}

void Player::keyReleased(int key)
{
	keyDown[key] = false;
}

void Player::mouseMoved(int x, int y)
{
	int x_diff = (ofGetScreenWidth() / 2) - x;
	int y_diff = (ofGetScreenHeight() / 2) - y;

	camera.rotate(kSensitivity*x_diff, { 0,0,1 });
	camera.tilt(kSensitivity*y_diff);
	//ofVec3f heading = player.getOrientationEuler();
	//std::cout << "camera orientation: " << player.getOrientationEuler() << std::endl;
	//printf("cam: %3.3f, %3.3f, %3.3f\n", heading.x, heading.y, heading.z);

	SetCursorPos(ofGetScreenWidth() / 2, ofGetScreenHeight() / 2);
}

ofVec3f Player::getPosition()
{
	return camera.getPosition();
}
