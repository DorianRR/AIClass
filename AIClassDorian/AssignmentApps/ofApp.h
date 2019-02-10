#pragma once

#include "ofMain.h"

//GUI
#include "ofxGui.h"

//Kinematic
#include "DataStructs\Kinematic.h"
#include "DataStructs\Crumb.h"


//Helpers
#include "Helpers\ofAppHelpers.h"
#include "Helpers\SetupHelpers.h"
#include "ofVec2f.h"

//Modes
#include "Steering\Seek.h"
#include "Steering\Wander.h"
#include "Steering\Flee.h"
#include "Steering\Matching.h"





class ofApp : public ofBaseApp {

public:

	enum Configuration
	{
		DefaultMode, DynamicSeekMode1, WanderMode1, FlockMode, default
	};
	float MaxSpeed;
	float MaxAccel;


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
	void ClearMode();

	void RunDynamicSeek1();
	void RunWander1();
	

	void RunFlock();



	ofxPanel GUI;

	ofxButton Clear;
	ofxButton DynamicSeek1;
	ofxButton WanderButton1;
	ofxButton FlockButton;

	ofxFloatSlider SpeedSlider;
	ofxFloatSlider AccelSlider;


private:
	float timer;
	Configuration Mode;
};

