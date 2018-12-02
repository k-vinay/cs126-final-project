#pragma once
class Player
{
	const float kDefaultFramerate = 60.0;
	const float kMoveSpeed = 0.46;
	const float kSensitivity = 0.1;

public:
	Player();
	~Player();

	void update();
};

