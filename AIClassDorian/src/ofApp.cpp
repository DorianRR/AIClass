#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup() {

	Mode = DefaultMode;
	DynamicSeek.addListener(this, &ofApp::RunDynamicSeek);


	GUI.setup();
	GUI.add(DynamicSeek.setup("Dynamic Seek"));

}

void ofApp::RunDynamicSeek()
{
	Mode = DynamicSeekMode;
	SetupHelpers::DynamicSeekSetup(&MobileBoids);
}

//--------------------------------------------------------------
void ofApp::update() 
{
	switch (Mode)
	{
	case DefaultMode:

		break;


	case DynamicSeekMode:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	GUI.draw();
	
	
	switch (Mode)
	{
	case DefaultMode:

		break;


	case DynamicSeekMode:
		ofAppHelpers::DrawBoids(MobileBoids);

		break;
	}
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::Clear()
{

}