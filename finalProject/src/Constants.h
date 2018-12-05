#pragma once
#include "ofMain.h"


const float kGunScale = 0.05;

const float kDefaultFramerate = 60.0;

const float kGundeadScale = 0.03;
const float kMapScale = 1;

const float kFov = 90;
const float kZoomFov = 60;
const float kMoveSpeed = 1.3;
const float kSensitivity = 0.1;
const float kZoom = -20;

const float kHeight = 15;
const ofVec3f kSpawnPt = { -450,-450,kHeight };
const glm::quat kSpawnDir = { 0.654, 0.654, -0.26, -0.26 };

const float kJumpSpeedMultiplier = 2.0;
const float kJumpPower = 2;
const float kGravity = -0.2;