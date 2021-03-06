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

	health = kStartHealth;

	setPosition(kSpawnPt);

	camera.setOrientation(kSpawnDir);
	camera.setFov(kFov);
	camera.setNearClip(kNearClip);
	camera.setFarClip(kFarClip);
	cam_tilt = 0;

	ofHideCursor();
	SetCursorPos(ofGetScreenWidth() / 2, ofGetScreenHeight() / 2);

	is_jumping = false;
	pitfall = false;

	world_ptr->player_hitbox = &hitbox;

	normal_hud.loadImage("hud.png");
	zoomed_hud.loadImage("hud-zoomed.png");

	health_bar[0].loadImage("healthbar/0.png");
	health_bar[1].loadImage("healthbar/1.png");
	health_bar[2].loadImage("healthbar/2.png");
	health_bar[3].loadImage("healthbar/3.png");
	health_bar[4].loadImage("healthbar/4.png");
	health_bar[5].loadImage("healthbar/5.png");
	health_bar[6].loadImage("healthbar/6.png");
}

void Player::update(float frames)
{
	is_zoomed = mouse[2];

	frames_since_last_shot += frames;
	can_shoot = frames_since_last_shot > shoot_delay_frames;
	frames_since_last_damage += frames;

	if (is_jumping)
	{
		float z_diff = 0.5*kGravity*frames*frames + frames * speed.z;
		speed.z += frames * kGravity;
		move({ kJumpSpeedMultiplier*frames*speed.x, kJumpSpeedMultiplier*frames*speed.y, z_diff });
		
		if (camera.getGlobalPosition().z < kCamDip + kHeight)
		{
			is_jumping = false;
			setPosition({ getPosition().x,getPosition().y,kSpawnPt.z });
			speed.z = 0;
			if (world_ptr->current_room->getState(hitbox) != -1)
			{
				last_ground = getPosition();
				pitfall = false;
			}
			else
				pitfall = true;
		}

		is_zoomed = false;
	}
	else if (pitfall)
	{
		float z_diff = 0.5*kGravity*frames*frames + frames * speed.z;
		speed.z += frames * kGravity;
		move({ 0,0, z_diff });

		if (camera.getGlobalPosition().z < kPitDepth+kHeight+kCamDip)
		{
			pitfall = false;
			setPosition(last_ground);
			speed.z = 0;
			health--;
			frames_since_last_damage = 0;
		}

		is_zoomed = false;
	}	
	else
	{
		last_ground = getPosition();
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

		if (mouse[0] && can_shoot)
		{
			ofVec3f pos = camera.getGlobalPosition();
			camera.dolly(-kBulletSpeed);
			float bullet_x = camera.getGlobalPosition().x - pos.x;
			float bullet_y = camera.getGlobalPosition().y - pos.y;
			float bullet_z = camera.getGlobalPosition().z - pos.z;

			world_ptr->current_room->addBullet(Bullet(HitBox({ camera.getGlobalPosition(),kBulletBoxSize,kBulletBoxSize,kBulletBoxSize }), { bullet_x,bullet_y,bullet_z }));

			can_shoot = false;
			frames_since_last_shot = 0;

		}

		camera.setPosition(player_pos);

		if (!(x_diff == 0 && y_diff == 0))
		{
			float scale = kMoveSpeed / sqrtf((x_diff*x_diff) + (y_diff*y_diff));
			if (is_zoomed)
				scale *= kAimSpeedMultiplier;
			x_diff *= scale;
			y_diff *= scale;
			move({ frames*speed.x,frames*speed.y,0 });
		}

		speed.x = x_diff;
		speed.y = y_diff;

		

	}

	

	int state = world_ptr->current_room->getState(hitbox);
	if (state == 1) //door
	{
		world_ptr->current_room = world_ptr->current_room->isInDoor(hitbox)->useDoor(world_ptr->current_room, hitbox);
	}
	else if (state == -1) //pit
	{
		pitfall = true;
		cout << "pit\n";
	}
	else if (state == -2) //bullet
	{
		if (frames_since_last_damage > iframes)
		{
			health--;
			frames_since_last_damage = 0;
		}
	}

	if (health <= 0)
	{
		//end the game
		ofExit();
	}
}


void Player::begin()
{
	if (is_zoomed)
	{
		camera.setFov(kZoomFov);
	}
	else
	{
		camera.setFov(kFov);
	}
	camera.begin();
}

void Player::end()
{
	camera.end();
	camera.setFov(kFov);
	
	if(frames_since_last_damage>iframes)
		health_bar[health].draw(0, 0);
	else
	{
		int f = (int)(frames_since_last_damage/kFlashFrames);
		if (f%2 == 1)
			health_bar[health].draw(0, 0);
	}
	
	if (is_zoomed)
		zoomed_hud.draw(0, 0);
	else
		normal_hud.draw(0, 0);
}

void Player::draw()
{
	glm::quat heading = camera.getGlobalOrientation();
	printf("cam: %3.3f, %3.3f, %3.3f, %3.3f\n", heading.w, heading.x, heading.y, heading.z);
	ofVec3f pos = getPosition();
	printf("%3.3f, %3.3f, %3.3f\n\n", pos.x, pos.y, pos.z);
}


void Player::move(ofVec3f displacement)
{
	hitbox.move(displacement.x, 0, 0);
	int can_move_x = world_ptr->current_room->isValidPosition(hitbox);
	if (can_move_x != 1)
		hitbox.move(-displacement.x, 0, 0);

	hitbox.move(0, displacement.y, 0);
	int can_move_y = world_ptr->current_room->isValidPosition(hitbox);
	if (can_move_y != 1)
		hitbox.move(0, -displacement.y, 0);

	if (can_move_x == 1)
		camera.move({ displacement.x,0,0 });
	if (can_move_y == 1)
		camera.move({ 0,displacement.y,0 });

	if ((can_move_x == -1 || can_move_y == -1) && frames_since_last_damage > iframes)
	{
		health--;
		frames_since_last_damage = 0;
	}

	hitbox.move(0, 0, displacement.z);
	camera.move({ 0,0,displacement.z });
}

void Player::setPosition(ofVec3f pos)
{
	hitbox.redefine(pos, kHitboxDims.x, kHitboxDims.y, kHitboxDims.z);
	camera.setGlobalPosition(pos);
	camera.move({ 0, 0, kCamDip + kHeight/2 });
}


void Player::keyPressed(int key)
{
	keyDown[key] = true;
	bool canJump = (speed.length() != 0) && !is_jumping && !pitfall && !(world_ptr->current_room->getState(hitbox) == -1);
	if (keyDown[' '] && canJump)
	{
		is_jumping = true;
		speed.z = kJumpPower;
	}

	if (key == OF_KEY_BACKSPACE)
	{
		return keyReleased(OF_KEY_BACKSPACE);
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

	x_diff *= kSensitivity;
	y_diff *= kSensitivity;
	
	if (is_zoomed)
	{
		x_diff *= kZoomedMultiplier;
		y_diff *= kZoomedMultiplier;
	}

	if (abs(cam_tilt + y_diff) < kMaxTilt)
	{
		camera.rotate(x_diff, { 0,0,1 });
		camera.tilt(y_diff);
		cam_tilt += y_diff;
	}
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
	return hitbox.get_position();
}
