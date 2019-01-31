#include "Flee.h"


DynamicSteering Flee::GetDynamicSteering(Kinematic MyObject, Kinematic Target, float MaxAccel, float MaxSpeed, float MaxDistance, float DeltaTime)
{
	DynamicSteering DynStr = DynamicSteering();
	float DistanceBtwKin = Target.Position.distance(MyObject.Position);
	if (DistanceBtwKin >= MaxDistance || DistanceBtwKin < 1)
	{
		return DynStr;
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
		DynStr.Velocity = -Direction;
		DynStr.Orientation = -Orientation::GetDynamicFace(MyObject, Target, MaxAccel, DeltaTime);

	}
	return DynStr;

}

DynamicSteering Flee::GetDynamicSteering(Kinematic MyObject, std::vector<Kinematic> Targets, float MaxAccel, float MaxSpeed, float MaxDistance, float DeltaTime)
{
	DynamicSteering DynStr = DynamicSteering();
	ofVec2f Direction;
	for (int i = 0; i != Targets.size(); i++)
	{
		float DistanceBtwKin = Targets[i].Position.distance(MyObject.Position);
		if (DistanceBtwKin >= MaxDistance)
		{
			continue;
		}
		else
		{
			Direction += (Targets[i].Position - MyObject.Position).getNormalized() * MaxDistance/(Targets[i].Position - MyObject.Position).length();	

		}
	}
	Direction *= MaxAccel * DeltaTime ;
	Direction += MyObject.Velocity / 3.5;
	if (Direction.length() > MaxSpeed)
	{
		Direction /= (Direction.length() / MaxSpeed);
	}
	DynStr.Velocity = -Direction;
	DynStr.Orientation = Orientation::GetAllignAngle(DynStr.Velocity);
	return DynStr;

}

//
//
//DynamicSteering Flee::GetDynamicSteering(Kinematic MyObject, Kinematic Target, float MaxAccel, float MaxSpeed, float SlowRadius, float MaxDistance, float DeltaTime)
//{
//	DynamicSteering DynStr = DynamicSteering();
//	float DistanceBtwKin = Target.Position.distance(MyObject.Position);
//	if (DistanceBtwKin >= MaxDistance)
//	{
//		return DynStr;
//	}
//	else
//	{
//		if (DistanceBtwKin <= SlowRadius)
//		{
//			ofVec2f Direction = (Target.Position - MyObject.Position).getNormalized();
//			Direction *= MaxAccel * DeltaTime;
//			Direction += MyObject.Velocity / 3.5;
//			if (Direction.length() > MaxSpeed)
//			{
//				Direction /= (Direction.length() / MaxSpeed);
//			}
//			DynStr.Velocity = Direction;
//			DynStr.Velocity /= (SlowRadius / DistanceBtwKin);
//			DynStr.Orientation = Orientation::GetDynamicFace(MyObject, Target, MaxAccel, DeltaTime);
//		}
//		else
//		{
//			ofVec2f Direction = (Target.Position - MyObject.Position).getNormalized();
//			Direction *= MaxAccel * DeltaTime;
//			Direction += MyObject.Velocity / 3.5;
//			if (Direction.length() > MaxSpeed)
//			{
//				Direction /= (Direction.length() / MaxSpeed);
//			}
//			DynStr.Velocity = Direction;
//			DynStr.Orientation = Orientation::GetDynamicFace(MyObject, Target, MaxAccel, DeltaTime);
//		}
//
//
//	}
//	return DynStr;
//
//}

