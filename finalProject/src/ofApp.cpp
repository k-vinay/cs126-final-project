#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	//player.setup(&world);
	world.setup();
	ofEnableLighting();
}

//--------------------------------------------------------------
void ofApp::update()
{
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
	player.camera.begin();
	player.draw();
	world.draw();
	player.camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	player.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	player.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
	player.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

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