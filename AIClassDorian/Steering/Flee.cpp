#include "Flee.h"


DynamicSteering Flee::GetDynamicSteering(Kinematic MyObject, Kinematic Target, float MaxDistance)
{
	DynamicSteering DynStr = DynamicSteering();
	float DistanceBtwKin = Target.Position.distance(MyObject.Position);
	if (DistanceBtwKin >= MaxDistance || DistanceBtwKin < 1)
	{
		DynStr.DistanceScale = 0;
		return DynStr;
	}
	else
	{
		ofVec2f Direction = (Target.Position - MyObject.Position).getNormalized() * (MaxDistance/3) / (Target.Position - MyObject.Position).length();
		DynStr.DistanceScale = MaxDistance/DistanceBtwKin;
		DynStr.LinearAcceleration = -Direction.getNormalized();
		DynStr.TargetOrientation = -Orientation::GetDynamicFace(MyObject, Target);
	}
	return DynStr;
}

DynamicSteering Flee::GetDynamicSteering(Kinematic MyObject, std::vector<Kinematic> Targets, float MaxDistance)
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
			Direction += (Targets[i].Position - MyObject.Position).getNormalized() * (MaxDistance/3)/(Targets[i].Position - MyObject.Position).length();	

		}
	}
	DynStr.LinearAcceleration = -Direction.getNormalized();
	DynStr.TargetOrientation = Orientation::GetAllignAngle(DynStr.LinearAcceleration);
	return DynStr;

}
