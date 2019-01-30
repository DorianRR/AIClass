#include "SetupHelpers.h"



void SetupHelpers::DynamicSeekSetup(std::vector<Kinematic> * boidsToDraw)
{
	Kinematic temp1;
	temp1.Position = ofVec2f(std::rand() % (1042 + 1), std::rand() % 720 + 1);
	Kinematic temp2;
	temp2.Position = ofVec2f(std::rand() % (1042 + 1), std::rand() % 720 + 1);
	Kinematic temp3;
	temp3.Position = ofVec2f(std::rand() % (1042 + 1), std::rand() % 720 + 1);

	boidsToDraw->push_back(temp1);
	boidsToDraw->push_back(temp2);
	boidsToDraw->push_back(temp3);
}