#include "Assignment2ofApp.h"



//--------------------------------------------------------------
void Assignment2ofApp::setup() 
{
	Mode = MenuMode;
	SEAMapImage.load("Data\SEAMap.jpg");


	SEAMap.addListener(this, &Assignment2ofApp::SetupSEAsianMap);
	Clear.addListener(this, &Assignment2ofApp::ClearMode);
	GUI.setup();

	GUI.add(SEAMap.setup("Southeast Asian Test Map"));
	GUI.add(Clear.setup("Clear Mode"));

}

void Assignment2ofApp::SetupSEAsianMap()
{

}

//--------------------------------------------------------------
void Assignment2ofApp::update(){}

//--------------------------------------------------------------
void Assignment2ofApp::draw() 
{
	ofAppHelpers::DrawGraph(Graph);
}

//--------------------------------------------------------------
void Assignment2ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void Assignment2ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void Assignment2ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void Assignment2ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void Assignment2ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void Assignment2ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void Assignment2ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void Assignment2ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void Assignment2ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void Assignment2ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void Assignment2ofApp::dragEvent(ofDragInfo dragInfo) {}

//--------------------------------------------------------------
void Assignment2ofApp::ClearMode(){}
