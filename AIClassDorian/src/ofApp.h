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
#include "ofVec2f.h"

//Modes
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\Seek.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\Wander.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\Flee.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\Matching.h"





class ofApp : public ofBaseApp {

public:

	enum Configuration
	{
		DefaultMode, DynamicSeekMode1, DynamicSeekMode2, WanderMode1, WanderMode2, FlockMode, default
	};
	float MaxSpeed;

	std::vector<Kinematic> MobileBoids;
	std::vector<Kinematic> StationaryKinematics;
	std::vector<Crumb> Crumbs;

	Kinematic FlockLeader;
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


	void RunKinematic();
	void RunDynamicSeek1();
	void RunDynamicSeek2();
	void RunWander1();
	void RunWander2();
	

	void RunFlock();



	ofxPanel GUI;

	ofxButton Clear;
	ofxButton KinematicMove;
	ofxButton DynamicSeek1;
	ofxButton DynamicSeek2;
	ofxButton WanderButton1;
	ofxButton WanderButton2;
	ofxButton FlockButton;

	ofxFloatSlider SpeedSlider;


private:
	float timer;
	Configuration Mode;
	
};

