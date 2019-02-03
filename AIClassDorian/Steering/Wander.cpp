#include "Wander.h"


DynamicSteering Wander::GetDynamicSteering(Kinematic MyObject, float WanderVariance, float DeltaTime)
{
	DynamicSteering DynSteer;
	DynSteer.TargetOrientation = WanderVariance * (ofRandom(0,1) - ofRandom(0,1)) + MyObject.Orientation;
	DynSteer.LinearAcceleration = ofVec2f(cos(DynSteer.TargetOrientation), sin(DynSteer.TargetOrientation)).getNormalized();
	return DynSteer;
}

 