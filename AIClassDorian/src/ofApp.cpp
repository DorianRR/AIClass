#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup() {
	timer = 0;
	timer2 = 0;
	Mode = default;
	DynamicSeek1.addListener(this, &ofApp::RunDynamicSeek1);
	DynamicSeek2.addListener(this, &ofApp::RunDynamicSeek2);
	WanderButton1.addListener(this, &ofApp::RunWander1);
	WanderButton2.addListener(this, &ofApp::RunWander2);
	FlockButton.addListener(this, &ofApp::RunFlock);
	KinematicMove.addListener(this, &ofApp::RunKinematic);

	GUI.setup();
	GUI.add(KinematicMove.setup("Kinematic Move"));
	GUI.add(DynamicSeek1.setup("Dynamic Seek Mode 1"));
	GUI.add(DynamicSeek2.setup("Dynamic Seek Mode 2"));
	GUI.add(WanderButton1.setup("Wander Mode 1"));
	GUI.add(WanderButton2.setup("Wander Mode 2"));
	GUI.add(FlockButton.setup("Flock Mode"));
	GUI.add(SpeedSlider.setup("Max Boid Speed", 30, 5, 50));
}


void ofApp::RunKinematic()
{
	Mode = DefaultMode;
	SetupHelpers::DynamicSeekSetup(&MobileBoids);
	MobileBoids[0].Position = ofVec2f(50, 50);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}

void ofApp::RunDynamicSeek1()

{
	Mode = DynamicSeekMode1;
	SetupHelpers::DynamicSeekSetup(&MobileBoids);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}

void ofApp::RunDynamicSeek2()

{
	Mode = DynamicSeekMode2;
	SetupHelpers::DynamicSeekSetup(&MobileBoids);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}


void ofApp::RunWander1()
{
	Mode = WanderMode1;
	SetupHelpers::WanderSetup(&MobileBoids, 5);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}

void ofApp::RunWander2()
{
	Mode = WanderMode2;
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
	float FrameTime = ofGetLastFrameTime() * 10;
	MaxSpeed = SpeedSlider;

	switch (Mode)
	{
	case DefaultMode:
		SeekTarget.Position = ofVec2f(700,700);
		MobileBoids[0].ProcessSteering(Seek::GetDynamicSteering(MobileBoids[0], SeekTarget, 100, 200, 100, 30, FrameTime), MaxSpeed, FrameTime);
		break;


	case DynamicSeekMode1:
		SeekTarget.Position = ofVec2f(ofApp::mouseX, ofApp::mouseY);
		MobileBoids[0].ProcessSteering(Seek::GetDynamicSteering(MobileBoids[0], SeekTarget, 100, 200, 30, FrameTime), MaxSpeed, FrameTime);
		break;


	case DynamicSeekMode2:
		SeekTarget.Position = ofVec2f(ofApp::mouseX, ofApp::mouseY);
		MobileBoids[0].ProcessSteering(Seek::GetDynamicSteering(MobileBoids[0], SeekTarget, 100, 200, 100, 10, FrameTime), MaxSpeed, FrameTime);
		break;


	case WanderMode1:
		for (int i = 0; i != MobileBoids.size(); i++)
		{
			ofAppHelpers::CheckForOnScreen(&MobileBoids);
			MobileBoids[i].ProcessSteering(Wander::GetDynamicSteering(MobileBoids[i], .5, 25, FrameTime), MaxSpeed, true, FrameTime);
		}
		break;


	case WanderMode2:
		for (int i = 0; i != MobileBoids.size(); i++)
		{
			ofAppHelpers::CheckForOnScreen(&MobileBoids);
			MobileBoids[i].ProcessSteering(Wander::GetDynamicSteering(MobileBoids[i], .25, 25, FrameTime), MaxSpeed, true, FrameTime);
		}
		break;


	case FlockMode:
		timer2 += FrameTime/10;
		SeekTarget.Position = ofVec2f(ofApp::mouseX, ofApp::mouseY);
		FlockLeader.ProcessSteering(Seek::GetDynamicSteering(FlockLeader, SeekTarget, 100, 200, 100, 5, FrameTime), MaxSpeed, FrameTime);
		//FlockLeader.ProcessSteering(Wander::GetDynamicSteering(FlockLeader, .5, 25, temp), MaxSpeed, temp);

		for (int i = 0; i != MobileBoids.size(); i++)
		{
			DynamicSteering Avoid; 
			DynamicSteering Final;

			if (timer2 > 2.25)
			{
				if (timer2 > ofRandom(2.35,2.55) )
				{
					timer2 = 0;
				}
				Avoid = Flee::GetDynamicSteering(MobileBoids[i], MobileBoids, ofRandom(150, 250), ofRandom(150, 250), ofRandom(150, 250), FrameTime);
				Final.Velocity = Avoid.Velocity;
				
			}
			else
			{
				DynamicSteering VelocityMatch = Matching::MatchVelocity(MobileBoids[i], FlockLeader, ofRandom(100, 250), 10, FrameTime);
				DynamicSteering SeekLeader = Seek::GetDynamicSteering(MobileBoids[i], FlockLeader, ofRandom(100, 250), ofRandom(100, 250), 100, 5, FrameTime);
				Final.Velocity = (VelocityMatch.Velocity + SeekLeader.Velocity*7.5).getNormalized() * MaxSpeed;

			}
			ofAppHelpers::CheckForOnScreen(&MobileBoids);
			

			Final.Orientation = Orientation::GetAllignAngle(Final.Velocity);
			MobileBoids[i].ProcessSteering(Final, MaxSpeed, FrameTime);
		}
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
		ofAppHelpers::DrawBoids(MobileBoids);
		if (timer > .33)
		{
			ofAppHelpers::LeaveCrumbs(MobileBoids, &Crumbs);
			timer = 0;
		}
		ofAppHelpers::UpdateAndDrawCrumbs(&Crumbs, temp);
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


	case DynamicSeekMode2:
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

	case WanderMode2:
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
	//delete(SeekTarget);
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

