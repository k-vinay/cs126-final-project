#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	player.setup(&world);
	world.setup();
	ofEnableLighting();
	camera.setNearClip(0.01);
	camera.rotate(-90, { 0,0,1 });
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (free_roam)
	{
		float speed = kMoveSpeed;
		if (keyDown['m'])
			speed /= 20.0;
		if (keyDown['w'])
			camera.move({ speed,0,0 });
		if (keyDown['s'])
			camera.move({ -speed,0,0 });
		if (keyDown['a'])
			camera.move({ 0,speed,0 });
		if (keyDown['d'])
			camera.move({ 0,-speed,0 });
		if (keyDown[' '])
			camera.move({ 0,0,speed });
		if (keyDown['c'])
			camera.move({ 0,0,-speed });
		return;
	}

	float frames = 1;
	if (ofGetFrameRate() > 0)
		frames = kDefaultFramerate / ofGetFrameRate();

	player.update(frames);
	world.update(frames);
	light.setPosition(player.getPosition());
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofEnableDepthTest();
	ofSetVerticalSync(false);
	ofSetBackgroundColorHex(0);

	light.enable();
	
	if (free_roam)
	{
		camera.begin();
		world.draw();
		camera.end();
		ofVec3f pos = camera.getPosition();
		printf("position %3.3f, %3.3f, %3.3f\n\n", pos.x, pos.y, pos.z);
	}
	else
	{
		player.begin();
		player.draw();
		world.draw();
		player.end();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	keyDown[key] = true;
	if (key == OF_KEY_ALT)
	{
		free_roam = !free_roam;
		camera.setGlobalPosition(player.getPosition());
		if (free_roam)
			ofShowCursor();
		else
			ofHideCursor();
	}
	if (!free_roam)
		player.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	keyDown[key] = false;
	if (!free_roam)
		player.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
	if (!free_roam)
		player.mouseMoved(x, y);

	int x_diff = (ofGetScreenWidth() / 2) - x;
	int y_diff = (ofGetScreenHeight() / 2) - y;

	//camera.rotate(kSensitivity*x_diff, { 0,0,1 });
	//camera.tilt(kSensitivity*y_diff);

	SetCursorPos(ofGetScreenWidth() / 2, ofGetScreenHeight() / 2);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	if (free_roam)
		return;
	mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	if (!free_roam)
		player.mousePressed(button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	if (!free_roam)
		player.mouseReleased(button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}