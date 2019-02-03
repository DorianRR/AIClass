#include "Seek.h"


KinematicSteering Seek::GetKinematicSteering(Kinematic MyObject, Kinematic Target, float MaxVel, float StopRadius)
{
	cout << "Get Seek Kinematic Steering not implemented.";
	assert(false);
	return KinematicSteering();
}


DynamicSteering Seek::GetDynamicSteering(Kinematic MyObject, Kinematic Target, float StopRadius)
{
	DynamicSteering DynStr = DynamicSteering();
	float DistanceBtwKin = Target.Position.distance(MyObject.Position);
	if (DistanceBtwKin <= StopRadius)
	{
		return DynStr;
	}
	else
	{
		ofVec2f Direction = (Target.Position - MyObject.Position).getNormalized();
		DynStr.LinearAcceleration = Direction;
		DynStr.TargetOrientation = Orientation::GetAllignAngle(Direction);
	}
	return DynStr;
}


DynamicSteering Seek::GetDynamicSteering(Kinematic MyObject, Kinematic Target, float SlowRadius, float StopRadius)
{
	DynamicSteering DynStr = DynamicSteering();
	float DistanceBtwKin = Target.Position.distance(MyObject.Position);
	if (DistanceBtwKin <= StopRadius)
	{
		return DynStr;
	}
	else
	{
		if (DistanceBtwKin <= SlowRadius)
		{
			ofVec2f Direction = (Target.Position - MyObject.Position).getNormalized();
			DynStr.LinearAcceleration = Direction;
			DynStr.DistanceScale = DistanceBtwKin / SlowRadius;
			DynStr.TargetOrientation = Orientation::GetAllignAngle(Direction);
		}
		else
		{
			ofVec2f Direction = (Target.Position - MyObject.Position).getNormalized();
			DynStr.LinearAcceleration = Direction;
			DynStr.TargetOrientation = Orientation::GetAllignAngle(Direction);
		}
	}
	return DynStr;
}

