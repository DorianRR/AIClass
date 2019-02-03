#include "Matching.h"

DynamicSteering Matching::MatchVelocity(Kinematic MyObject, Kinematic Target, float MatchThreshold)
{
	DynamicSteering DynSteer;
	float OrientationDelta = abs(Orientation::GetAllignAngle(Target.Velocity) - MyObject.Orientation);
	if (OrientationDelta < MatchThreshold)
	{
		DynSteer.DistanceScale = 0;
		return DynSteer;
	}
	DynSteer.DistanceScale = OrientationDelta / MatchThreshold;
	DynSteer.LinearAcceleration = (Target.Velocity - MyObject.Velocity).getNormalized();
	return DynSteer;
}
