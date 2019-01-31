#include "Wander.h"


DynamicSteering Wander::GetDynamicSteering(Kinematic MyObject, float WanderVariance, float WanderSpeed, float DeltaTime)
{
	DynamicSteering DynSteer;
	DynSteer.Orientation = WanderVariance * (ofRandom(0,1) - ofRandom(0,1)) + MyObject.Orientation;
	DynSteer.Velocity = ofVec2f(cos(DynSteer.Orientation), sin(DynSteer.Orientation)).normalized() * WanderSpeed;
	return DynSteer;
}

