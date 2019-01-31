#include "Matching.h"

DynamicSteering Matching::MatchVelocity(Kinematic MyObject, Kinematic Target, float MaxAccel, float MatchThreshold, float DeltaTime)
{
	DynamicSteering DynSteer;
	if (abs(atan((MyObject.Velocity.y - Target.Velocity.y)/(MyObject.Velocity.x/Target.Velocity.x))) < MatchThreshold)
	{
		return DynSteer;
	}
	DynSteer.Velocity = (Target.Velocity - MyObject.Velocity).getNormalized() * MaxAccel * DeltaTime;

	return DynSteer;
}

DynamicSteering Matching::MatchOrientation(Kinematic MyObject, Kinematic Target, float MaxAccel, float MatchThreshold, float DeltaTime)
{
	return DynamicSteering();
}
