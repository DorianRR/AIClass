#include "SetupHelpers.h"



void SetupHelpers::DynamicSeekSetup(std::vector<Kinematic> * boidsToDraw)
{
	Kinematic SeekBoid;
	SeekBoid.Position = ofVec2f(std::rand() % (1042 + 1), std::rand() % 720 + 1);
	boidsToDraw->push_back(SeekBoid);
}


void SetupHelpers::WanderSetup(std::vector<Kinematic> * boidsToDraw, int NumberOfWanderers)
{
	for (int i = 0; i < NumberOfWanderers; i++)
	{
		Kinematic temp1;
		temp1.Color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
		temp1.Position = ofVec2f(std::rand() % (1042 + 1), std::rand() % 720 + 1);
		boidsToDraw->push_back(temp1);
	}
}

void SetupHelpers::FlockSetup(std::vector<Kinematic> * boidsToDraw, int NumberInFlock)
{
	for (int i = 0; i < NumberInFlock; i++)
	{
		Kinematic temp1;
		temp1.Color = ofColor::black;
		temp1.Position = ofVec2f(std::rand() % (1042 + 1), std::rand() % 720 + 1);
		boidsToDraw->push_back(temp1);
	}
}


void SetupHelpers::InitializeCrumbs(std::vector<Crumb> * crumbs, int numberOfCrumbs)
{
	for (int i = 0; i < numberOfCrumbs; i++)
	{
		Crumb temp1;
		crumbs->push_back(temp1);
	}
}
