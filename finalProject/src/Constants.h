#pragma once
#include "ofMain.h"

const int kStartHealth = 6; //do not go above 6

const float kDefaultFramerate = 60.0;
const float iframes = 180;

const float kGundeadScale = 0.03;
const float kMapScale = 1;
const float kGunScale = 0.05;

const float kBulletSpeed = 5;
const float kBulletBoxSize = 4;
const float kBulletScale = 0.006;

const float kFov = 90;
const float kZoomFov = 60;
const float kNearClip = 0.1;
const float kFarClip = 1000;
const float kMoveSpeed = 1.3;
const float kSensitivity = 0.15;
const float kZoomedMultiplier = 0.6;

const float kMaxTilt = 88;

const float kHeight = 15;
const float kCamDip = -1;
const ofVec3f kSpawnPt = { -420, -420, kHeight/2 + 0.1 };
const ofVec3f kHitboxDims = { kHeight/2, kHeight/2, kHeight };
const glm::quat kSpawnDir = { 0.654, 0.654, -0.26, -0.26 };

const float kAimSpeedMultiplier = 0.6;
const float kJumpSpeedMultiplier = 2.0;
const float kJumpPower = 2;
const float kGravity = -0.2;

const float kWallHeight = 20 * kHeight;
const float kPitBoxHeight = kHeight + 2.5;
const float kPitDepth = -120;

struct EnemyData
{
	std::string filename;
	int health;
	Gun gun;
	ofVec3f hitbox_dims;
};

const int kEnemyTypes = 2;
const EnemyData kEnemyData[kEnemyTypes] = {
		{
			"bullet-kin.dae",
			3,
			Gun(),
			{ kHeight/2,kHeight/2,kHeight }
		},
		{
			"shotgun-kin.dae",
			6,
			Gun(),
			{ kHeight/2,kHeight/2,kHeight*1.5 }
		}
};