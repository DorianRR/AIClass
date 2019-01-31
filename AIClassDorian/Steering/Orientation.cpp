#include "Orientation.h"



float Orientation::GetDynamicFace(Kinematic MyObject, Kinematic Target, float MaxAccel, float DeltaTime)
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
	/*else if(UnsignedOrientationDelta > PI)
	{
		SignedOrientationDelta = AngleToTarget - OrientationCopy;
		UnsignedOrientationDelta = (2*PI) - abs(AngleToTarget) - abs(OrientationCopy);

		float FinalAddedRot = UnsignedOrientationDelta * DeltaTime * (SignedOrientationDelta/UnsignedOrientationDelta);
		return(OrientationCopy + FinalAddedRot);
	}*/
	else
	{
		float FinalAddedRot = UnsignedOrientationDelta * DeltaTime * (SignedOrientationDelta / UnsignedOrientationDelta);
		return(OrientationCopy + FinalAddedRot);
	}
}

float Orientation::GetAllignAngle(ofVec2f VecToAllignTo)
{
	return ofWrapRadians(glm::atan(VecToAllignTo.y, VecToAllignTo.x));
}



