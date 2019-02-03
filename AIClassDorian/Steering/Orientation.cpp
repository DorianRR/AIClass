#include "Orientation.h"


//Deprecated?
float Orientation::GetDynamicFace(Kinematic MyObject, Kinematic Target)
{
	float OrientationCopy = ofWrapRadians(MyObject.Orientation);
	ofVec2f Direction = (Target.Position - MyObject.Position).getNormalized();
	float AngleToTarget = GetAllignAngle(Direction);
	float SignedOrientationDelta = AngleToTarget - OrientationCopy;
	float UnsignedOrientationDelta = abs(AngleToTarget - OrientationCopy);

	if (UnsignedOrientationDelta < 0.3)
	{
		return MyObject.Orientation;
	}
	else
	{
		//float FinalAddedRot = UnsignedOrientationDelta * DeltaTime * (SignedOrientationDelta / UnsignedOrientationDelta);
		//return(OrientationCopy + FinalAddedRot);
	}
}

float Orientation::GetAllignAngle(ofVec2f VecToAllignTo)
{
	return ofWrapRadians(glm::atan(VecToAllignTo.y, VecToAllignTo.x));
}



