#include "Menu.h"



//--------------------------------------------------------------
void Menu::setup() {
	timer = 0;
	Mode = default;
	DynamicSeek1.addListener(this, &Menu::RunDynamicSeek1);
	WanderButton1.addListener(this, &Menu::RunWander1);
	FlockButton.addListener(this, &Menu::RunFlock);
	Clear.addListener(this, &Menu::ClearMode);


	GUI.setup();
	GUI.add(DynamicSeek1.setup("Dynamic Seek Mode 1"));
	GUI.add(WanderButton1.setup("Wander Mode 1"));
	GUI.add(FlockButton.setup("Flock Mode"));
	GUI.add(SpeedSlider.setup("Max Boid Speed", 100, 5, 150));
	GUI.add(AccelSlider.setup("Max Boid Acceleration", 100, 5, 150));

	GUI.add(Clear.setup("Clear Mode"));
}



void Menu::RunDynamicSeek1()

{
	/*
	Mode = DynamicSeekMode1;
	SetupHelpers::DynamicSeekSetup(&MobileBoids);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);*/
}


void Menu::RunWander1()
{
	Mode = WanderMode1;
	SetupHelpers::WanderSetup(&MobileBoids, 5);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}


void Menu::RunFlock()
{
	Mode = FlockMode;
	FlockLeader.Radius = 15;
	FlockLeader.Position = ofVec2f(500, 360);
	FlockLeader.Color = ofColor::green;

	SetupHelpers::FlockSetup(&MobileBoids, 8);
	SetupHelpers::InitializeCrumbs(&Crumbs, 1000);
}

//--------------------------------------------------------------
void Menu::update()
{
	float FrameTime = ofGetLastFrameTime() * 25;
	MaxSpeed = SpeedSlider;
	MaxAccel = AccelSlider;

	switch (Mode)
	{
	case DefaultMode:
		break;


	case DynamicSeekMode1:
		SeekTarget.Position = ofVec2f(Menu::mouseX, Menu::mouseY);
		MobileBoids[0].ProcessSteering(Seek::GetDynamicSteering(MobileBoids[0], SeekTarget, 100, 10), MaxAccel, MaxSpeed, FrameTime);

		break;


	case WanderMode1:
		for (int i = 0; i != MobileBoids.size(); i++)
		{
			ofAppHelpers::CheckForOnScreen(&MobileBoids);
			MobileBoids[i].ProcessSteering(Wander::GetDynamicSteering(MobileBoids[i], .65), MaxAccel, MaxSpeed, FrameTime);
		}
		break;


	case FlockMode:
		SeekTarget.Position = ofVec2f(Menu::mouseX, Menu::mouseY);
		FlockLeader.ProcessSteering(Seek::GetDynamicSteering(FlockLeader, SeekTarget, 100, 5), MaxAccel, MaxSpeed, FrameTime);
		//FlockLeader.ProcessSteering(Wander::GetDynamicSteering(FlockLeader, .5, 25, temp), MaxSpeed, temp);
		DynamicSteering Avoid;

		for (int i = 0; i != MobileBoids.size(); i++)
		{
			if (timer > ofRandom(0.07, 0.13))
			{
				if (ofRandom(0, 1) > 0.75) {}
				else
				{
					Avoid = Flee::GetDynamicSteering(MobileBoids[i], MobileBoids, 150);

				}
			}
			DynamicSteering Final;
			ofAppHelpers::CheckForOnScreen(&MobileBoids);
			DynamicSteering VelocityMatch = Matching::MatchVelocity(MobileBoids[i], FlockLeader, .15);
			DynamicSteering SeekLeader = Seek::GetDynamicSteering(MobileBoids[i], FlockLeader, 100, 5);

			Final.LinearAcceleration = (Avoid.LinearAcceleration * 3 + VelocityMatch.LinearAcceleration / 1.5 + SeekLeader.LinearAcceleration).getNormalized();
			Final.TargetOrientation = Orientation::GetAllignAngle(Final.LinearAcceleration);

			MobileBoids[i].ProcessSteering(Final, MaxAccel, MaxSpeed, FrameTime);
		}
		break;

	}
}

//--------------------------------------------------------------
void Menu::draw() {
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
void Menu::keyPressed(int key) {}

//--------------------------------------------------------------
void Menu::keyReleased(int key) {}

//--------------------------------------------------------------
void Menu::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void Menu::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void Menu::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void Menu::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void Menu::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void Menu::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void Menu::windowResized(int w, int h) {}

//--------------------------------------------------------------
void Menu::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void Menu::dragEvent(ofDragInfo dragInfo) {}

void Menu::ClearMode()
{
	Mode = DefaultMode;
	MobileBoids.clear();
	StationaryKinematics.clear();
	Crumbs.clear();
}
