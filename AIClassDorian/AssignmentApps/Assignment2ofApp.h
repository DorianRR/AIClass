#pragma once

#include "ofMain.h"

//GUI
#include "ofxGui.h"

//Helpers
#include "Helpers\ofAppHelpers.h"
#include "Helpers\Assignment2Helpers.h"
#include "Helpers\SetupHelpers.h"
#include "DataStructs\PriorityQueue.h"

//Math
#include "ofVec2f.h"


//Graph
#include "DataStructs\Graph\GraphStructs.h"
#include "Pathfinding\Pathfinding.h"





class Assignment2ofApp : public ofBaseApp {
public:
	~Assignment2ofApp();


	enum Mode
	{
		MenuMode, SEAMapMode, StressTestMode
	};

	Mode AppMode;
	DirectedWeightedGraph * pAppGraph;// = new DirectedWeightedGraph(0);
	//std::vector<DirectedWeightedGraph> DrawGraphs;


	ofImage SEAMapImage;


	void SetupSEAsianMap();
	void SetupStressMap();


	int AppScreenWidth, AppScreenHeight;

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
	ofxButton HeavyMapTest;
	//ofxButton FlockButton;

	

};

