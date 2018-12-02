#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	const float kGundeadScale = 0.01;
	const float kMapScale = 0.3;
	
	const float kHeight = 5.8;
	const ofVec3f spawn = { 0,0,0 };

	const float kJumpSpeedMultiplier = 2.0;
	const float kJumpPower = 1.87;
	const float kGravity = -0.17;

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};