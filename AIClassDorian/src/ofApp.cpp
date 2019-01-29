#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	Kinematic temp1;
	temp1.Position = ofVec2f(std::rand() % (1042 + 1), std::rand() % 720 + 1);
	Kinematic temp2;
	temp2.Position = ofVec2f(std::rand() % (1042 + 1), std::rand() % 720 + 1);
	Kinematic temp3;
	temp3.Position = ofVec2f(std::rand() % (1042 + 1), std::rand() % 720 + 1);

	MobileBoids.push_back(temp1);
	MobileBoids.push_back(temp2);
	MobileBoids.push_back(temp3);


}

//--------------------------------------------------------------
void ofApp::update() {



}

//--------------------------------------------------------------
void ofApp::draw() {

	ofAppHelpers::DrawBoids(MobileBoids);
	
	
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

