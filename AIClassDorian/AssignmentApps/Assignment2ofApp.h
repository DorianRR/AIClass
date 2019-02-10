#pragma once

#include "ofMain.h"

//GUI
#include "ofxGui.h"

//Helpers
#include "Helpers\ofAppHelpers.h"
#include "Helpers\SetupHelpers.h"
#include "ofVec2f.h"

//Graph
#include "DataStructs\Graph\GraphStructs.h"






class Assignment2ofApp : public ofBaseApp {

public:

	enum Mode
	{
		MenuMode, SEAMapMode, StressTestMode
	};

	Mode Mode;
	DirectedWeightedGraph Graph;

	ofImage SEAMapImage;


	void SetupSEAsianMap();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void ClearMode();



	ofxPanel GUI;

	ofxButton Clear;
	ofxButton SEAMap;
	ofxButton WanderButton1;
	ofxButton FlockButton;

	

};
