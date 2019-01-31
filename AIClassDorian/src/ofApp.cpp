#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup() {
	timer = 0;
	Mode = DefaultMode;
	DynamicSeek.addListener(this, &ofApp::RunDynamicSeek);
	WanderButton.addListener(this, &ofApp::RunWander);
	FlockButton.addListener(this, &ofApp::RunFlock);

	GUI.setup();
	GUI.add(DynamicSeek.setup("Dynamic Seek Mode"));
	GUI.add(WanderButton.setup("Wander Mode"));
	GUI.add(FlockButton.setup("Flock Mode"));

	
//	SeekTarget = Kinematic();
	
}

void ofApp::RunDynamicSeek()
{
	Mode = DynamicSeekMode;
	SetupHelpers::DynamicSeekSetup(&MobileBoids);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}

void ofApp::RunWander()
{
	Mode = WanderMode;
	SetupHelpers::WanderSetup(&MobileBoids, 5);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);

}

void ofApp::RunFlock()
{
	Mode = FlockMode;
	FlockLeader.Radius = 15;
	FlockLeader.Position = ofVec2f(500,360);
	FlockLeader.Color = ofColor::green;

	SetupHelpers::FlockSetup(&MobileBoids, 8);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}

//--------------------------------------------------------------
void ofApp::update()
{
	float temp = ofGetLastFrameTime()*10;


	switch (Mode)
	{
	case DefaultMode:

		break;


	case DynamicSeekMode:
		
		SeekTarget.Position = ofVec2f(ofApp::mouseX, ofApp::mouseY);
		//MobileBoids[0].ProcessSteering(Seek::GetDynamicSteering(MobileBoids[0], SeekTarget, 100, 200, 5, temp), temp);
		MobileBoids[0].ProcessSteering(Seek::GetDynamicSteering(MobileBoids[0], SeekTarget, 100, 200, 100, 5, temp), temp);
		

		break;
	case WanderMode:
		for (int i = 0; i != MobileBoids.size(); i++)
		{
			ofAppHelpers::CheckForOnScreen(&MobileBoids);
			MobileBoids[i].ProcessSteering(Wander::GetDynamicSteering(MobileBoids[i], .5, 25, temp), temp);
		}
		

		break;
	case FlockMode:

		SeekTarget.Position = ofVec2f(ofApp::mouseX, ofApp::mouseY);

		FlockLeader.ProcessSteering(Seek::GetDynamicSteering(FlockLeader, SeekTarget, 100, 200, 100, 5, temp), temp);

		for (int i = 0; i != MobileBoids.size(); i++)
		{
			ofAppHelpers::CheckForOnScreen(&MobileBoids);
			DynamicSteering Avoid = Flee::GetDynamicSteering(MobileBoids[i], MobileBoids, 100, 200, 50, temp);
			DynamicSteering VelocityMatch = Matching::MatchVelocity(MobileBoids[i], FlockLeader, 100, 10, temp);
			DynamicSteering SeekLeader = Seek::GetDynamicSteering(MobileBoids[i], FlockLeader, 100, 200, 100, 5, temp);
			DynamicSteering Final;
			Final.Velocity = (Avoid.Velocity*3 + SeekLeader.Velocity/5 + VelocityMatch.Velocity).normalized() * 50;
			//Final.Orientation = Orientation::GetAllignAngle(Final.Velocity);
			MobileBoids[i].ProcessSteering(Final, temp);
		}

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


	case DynamicSeekMode:
		ofAppHelpers::DrawBoids(MobileBoids);
		if (timer > .33)
		{
			ofAppHelpers::LeaveCrumbs(MobileBoids, &Crumbs);
			timer = 0;
		}
		ofAppHelpers::UpdateAndDrawCrumbs(&Crumbs, temp);
		break;


	case WanderMode:
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
		ofAppHelpers::UpdateAndDrawCrumbs(&Crumbs, temp);

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

