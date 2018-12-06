#include "src/player.h"

Player::Player()
{
	
}

Player::~Player()
{
}


void Player::setup(World* world)
{
	world_ptr = world;

	hitbox = HitBox({ kSpawnPt.x,kSpawnPt.y,kHeight / 2 }, kHitboxDims.x, kHitboxDims.y, kHitboxDims.z);
	
	camera.setGlobalPosition(kSpawnPt);
	camera.setOrientation(kSpawnDir);
	camera.setFov(kFov);
	camera.setNearClip(kNearClip);
	camera.setFarClip(kFarClip);

	ofHideCursor();
	SetCursorPos(ofGetScreenWidth() / 2, ofGetScreenHeight() / 2);
}

void Player::update(float frames)
{
	if (is_jumping)
	{
		float z_diff = 0.5*kGravity*frames*frames + frames * speed.z;
		speed.z += frames * kGravity;
		move({ kJumpSpeedMultiplier*frames*speed.x, kJumpSpeedMultiplier*frames*speed.y, z_diff });
	}
	else
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
			move({ frames*speed.x,frames*speed.y,0 });
		}

		speed.x = x_diff;
		speed.y = y_diff;
	}


	if (camera.getGlobalPosition().z < kHeight)
	{
		is_jumping = false;
		move({ 0,0,kHeight - camera.getGlobalPosition().z });
		speed.z = 0;
	}

	is_zoomed = mouse[2];
}


void Player::begin()
{
	if (is_zoomed)
		camera.setFov(kZoomFov);
	camera.begin();
}

void Player::end()
{
	camera.end();
	camera.setFov(kFov);
}


void Player::move(ofVec3f displacement)
{
	hitbox.move(displacement.x, 0,0);
	bool can_move_x = world_ptr->current_room->isValidPosition(hitbox);
	if (!can_move_x)
		hitbox.move(-displacement.x, 0, 0);

	hitbox.move(0, displacement.y, 0);
	bool can_move_y = world_ptr->current_room->isValidPosition(hitbox);
	if (!can_move_y)
		hitbox.move(0, -displacement.y, 0);

	if (can_move_x)
		camera.move({ displacement.x,0,0 });
	if (can_move_y)
		camera.move({ 0,displacement.y,0 });

	hitbox.move(0, 0, displacement.z);
	camera.move({ 0,0,displacement.z });
}

void Player::draw()
{
	glm::quat heading = camera.getGlobalOrientation();
	printf("cam: %3.3f, %3.3f, %3.3f, %3.3f\n", heading.w, heading.x, heading.y, heading.z);
	ofVec3f pos = camera.getGlobalPosition();
	printf("%3.3f, %3.3f, %3.3f\n\n", pos.x, pos.y, pos.z);
}


void Player::keyPressed(int key)
{
	keyDown[key] = true;

	if (keyDown[' '] && speed.length()!=0 && !is_jumping)
	{
		is_jumping = true;
		speed.z = kJumpPower;
	}
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

	SetCursorPos(ofGetScreenWidth() / 2, ofGetScreenHeight() / 2);
}

void Player::mousePressed(int button)
{
	mouse[button] = true;
}

void Player::mouseReleased(int button)
{
	mouse[button] = false;
}


ofVec3f Player::getPosition()
{
	return camera.getPosition();
}
