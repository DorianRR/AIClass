#include "Assignment2ofApp.h"



//--------------------------------------------------------------
void Assignment2ofApp::setup() 
{
	Mode = MenuMode;


	SEAMap.addListener(this, &Assignment2ofApp::SetupSEAsianMap);
	Clear.addListener(this, &Assignment2ofApp::ClearMode);
	GUI.setup();

	GUI.add(SEAMap.setup("Southeast Asian Test Map"));
	GUI.add(Clear.setup("Clear Mode"));

}

void Assignment2ofApp::SetupSEAsianMap()
{
	SEAMapImage.load("SEAMap.jpg");

}

//--------------------------------------------------------------
void Assignment2ofApp::update(){}

//--------------------------------------------------------------
void Assignment2ofApp::draw() 
{
	SEAMapImage.draw(0,0);
	if (Graph.Edges.size() > 0)
	{
		ofAppHelpers::DrawGraph(Graph);
	}
	GUI.draw();

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
