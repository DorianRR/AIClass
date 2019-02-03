#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup() {
	timer = 0;
	Mode = default;
	DynamicSeek1.addListener(this, &ofApp::RunDynamicSeek1);
	WanderButton1.addListener(this, &ofApp::RunWander1);
	FlockButton.addListener(this, &ofApp::RunFlock);
	Clear.addListener(this, &ofApp::ClearMode);


	GUI.setup();
	GUI.add(DynamicSeek1.setup("Dynamic Seek Mode 1"));
	GUI.add(WanderButton1.setup("Wander Mode 1"));
	GUI.add(FlockButton.setup("Flock Mode"));
	GUI.add(SpeedSlider.setup("Max Boid Speed", 100, 5, 150));
	GUI.add(AccelSlider.setup("Max Boid Acceleration", 100, 5, 150));

	GUI.add(Clear.setup("Clear Mode"));
}



void ofApp::RunDynamicSeek1()

{
	Mode = DynamicSeekMode1;
	SetupHelpers::DynamicSeekSetup(&MobileBoids);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}


void ofApp::RunWander1()
{
	Mode = WanderMode1;
	SetupHelpers::WanderSetup(&MobileBoids, 5);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}


void ofApp::RunFlock()
{
	Mode = FlockMode;
	FlockLeader.Radius = 15;
	FlockLeader.Position = ofVec2f(500, 360);
	FlockLeader.Color = ofColor::green;

	SetupHelpers::FlockSetup(&MobileBoids, 8);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}

//--------------------------------------------------------------
void ofApp::update()
{
	float FrameTime = ofGetLastFrameTime()*25;
	MaxSpeed = SpeedSlider;
	MaxAccel = AccelSlider;

	switch (Mode)
	{
	case DefaultMode:
		break;


	case DynamicSeekMode1:
		SeekTarget.Position = ofVec2f(ofApp::mouseX, ofApp::mouseY);
		//MobileBoids[0].ProcessSteering(Seek::GetDynamicSteering(MobileBoids[0], SeekTarget, 100, 10, FrameTime), MaxAccel, MaxSpeed, FrameTime);
		MobileBoids[0].ProcessSteering(Flee::GetDynamicSteering(MobileBoids[0], SeekTarget, 100, FrameTime), MaxAccel, MaxSpeed, FrameTime);
		break;


	case WanderMode1:
		for (int i = 0; i != MobileBoids.size(); i++)
		{
			ofAppHelpers::CheckForOnScreen(&MobileBoids);
			MobileBoids[i].ProcessSteering(Wander::GetDynamicSteering(MobileBoids[i], .65, FrameTime), MaxAccel, MaxSpeed, FrameTime);
		}
		break;


	case FlockMode:
		
		break;


	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	GUI.draw();

	float temp = ofGetLastFrameTime();
	timer += temp;


	switch (Mode)
	{
	case DefaultMode:
		break;


	case DynamicSeekMode1:
		ofAppHelpers::DrawBoids(MobileBoids);
		if (timer > .33)
		{
			ofAppHelpers::LeaveCrumbs(MobileBoids, &Crumbs);
			timer = 0;
		}
		ofAppHelpers::UpdateAndDrawCrumbs(&Crumbs, temp);
		break;


	case WanderMode1:
		ofAppHelpers::DrawBoids(MobileBoids);
		if (timer > .33)
		{
			ofAppHelpers::LeaveCrumbs(MobileBoids, &Crumbs);
			timer = 0;
		}
		ofAppHelpers::UpdateAndDrawCrumbs(&Crumbs, temp);
		break;


	case FlockMode:
		ofAppHelpers::DrawBoid(FlockLeader);
		ofAppHelpers::DrawBoids(MobileBoids);
		if (timer > .33)
		{
			ofAppHelpers::LeaveCrumbs(MobileBoids, &Crumbs);
			timer = 0;
		}
		//ofAppHelpers::UpdateAndDrawCrumbs(&Crumbs, temp);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

void ofApp::ClearMode()
{
	Mode = DefaultMode;
	MobileBoids.clear();
	StationaryKinematics.clear();
	Crumbs.clear();
}
