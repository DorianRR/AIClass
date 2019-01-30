#pragma once

#include "ofMain.h"

//GUI
#include "ofxGui.h"

//Kinematic
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Kinematic.h"

//Helpers
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\ofAppHelpers.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\SetupHelpers.h"

//Modes
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Seek.h"


class ofApp : public ofBaseApp {

public:

	enum Configuration
	{
		DefaultMode, DynamicSeekMode
	};


	std::vector<Kinematic> MobileBoids;
	std::vector<Kinematic> StationaryKinematics;


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


	void RunDynamicSeek();

	ofxPanel GUI;


	ofxButton DynamicSeek;

private:
	
	Configuration Mode;

	void Clear();

	
};

