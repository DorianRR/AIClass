#include "Seek.h"


KinematicSteering Seek::GetKinematicSteering(Kinematic MyObject, Kinematic Target, float MaxVel, float StopRadius)
{

	/*
	DynamicSteering DynStr = DynamicSteering();
	float DistanceBtwKin = Target.Position.distance(MyObject.Position);
	if (DistanceBtwKin <= StopRadius)
	{
		return DynStr;
	}
	else
	{
		ofVec2f Direction = (Target.Position - MyObject.Position).getNormalized();
		Direction *= MaxAccel;
		if (Direction.length() > MaxSpeed)
		{
			Direction /= (Direction.length() / MaxSpeed);
		}
		DynStr.Acceleration = Direction;
		DynStr.AngularAcceleration = Seek::GetDynamicAngularAccel(MyObject, Target, MaxAccel);

	}
	return DynStr;
	*/
	cout << "Get Seek Kinematic Steering not implemented.";
	assert(false);
	return KinematicSteering();
}

DynamicSteering Seek::GetDynamicSteering(Kinematic MyObject, Kinematic Target, float MaxAccel, float MaxSpeed, float StopRadius, float DeltaTime)
{
	DynamicSteering DynStr = DynamicSteering();
	float DistanceBtwKin = Target.Position.distance(MyObject.Position);
	if (DistanceBtwKin <= StopRadius)
	{
		MyObject.Velocity = ofVec2f::zero();
		return DynStr;
	}
	else
	{
		ofVec2f Direction = (Target.Position - MyObject.Position).getNormalized();
		Direction *= MaxAccel * DeltaTime;
		Direction += MyObject.Velocity/3.5;
		if (Direction.length() > MaxSpeed)
		{
			Direction /= (Direction.length() / MaxSpeed);
		}
		DynStr.Velocity = Direction;
		DynStr.Orientation = Orientation::GetDynamicFace(MyObject, Target, MaxAccel, DeltaTime);

	}
	return DynStr;
	
}


DynamicSteering Seek::GetDynamicSteering(Kinematic MyObject, Kinematic Target, float MaxAccel, float MaxSpeed, float SlowRadius, float StopRadius, float DeltaTime)
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
			Direction *= MaxAccel * DeltaTime;
			Direction += MyObject.Velocity / 3.5;
			if (Direction.length() > MaxSpeed)
			{
				Direction /= (Direction.length() / MaxSpeed);
			}
			DynStr.Velocity = Direction;
			DynStr.Velocity /= (SlowRadius / DistanceBtwKin);
			DynStr.Orientation = Orientation::GetDynamicFace(MyObject, Target, MaxAccel, DeltaTime);
		}
		else
		{
			ofVec2f Direction = (Target.Position - MyObject.Position).getNormalized();
			Direction *= MaxAccel * DeltaTime;
			Direction += MyObject.Velocity / 3.5;
			if (Direction.length() > MaxSpeed)
			{
				Direction /= (Direction.length() / MaxSpeed);
			}
			DynStr.Velocity = Direction;
			DynStr.Orientation = Orientation::GetDynamicFace(MyObject, Target, MaxAccel, DeltaTime);
		}
		

	}
	return DynStr;

}

