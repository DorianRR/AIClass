#pragma once

#include "ofMain.h"

//GUI
#include "ofxGui.h"

//Kinematic
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\DataStructs\Kinematic.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\DataStructs\Crumb.h"


//Helpers
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Helpers\ofAppHelpers.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Helpers\SetupHelpers.h"

//Modes
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\Seek.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\Wander.h"




class ofApp : public ofBaseApp {

public:

	enum Configuration
	{
		DefaultMode, DynamicSeekMode, WanderMode, FlockMode
	};


	std::vector<Kinematic> MobileBoids;
	std::vector<Kinematic> StationaryKinematics;
	std::vector<Crumb> Crumbs;

	Kinematic SeekTarget;

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
	void RunWander();
	void RunFlock();


	ofxPanel GUI;

	ofxButton Clear;
	ofxButton DynamicSeek;
	ofxButton WanderButton;
	ofxButton FlockButton;




private:
	float timer;
	Configuration Mode;
	
};

