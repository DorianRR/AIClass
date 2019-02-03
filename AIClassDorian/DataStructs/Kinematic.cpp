#include "Kinematic.h"


Kinematic::Kinematic()
{
	Position = ofVec2f::zero();
	Velocity = ofVec2f::zero();
	Orientation = 0;
	Rotation = 0;
	Radius = 10;
	Color = ofColor::blueViolet;
	Drag = 0.93;
	GetDrawn = true;
	LeaveTrail = true;
}

Kinematic::Kinematic(ofVec2f position)
{
	Position = position;
	Velocity = ofVec2f::zero();
	Orientation = 0;
	Rotation = 0;
	Radius = 10;
	Color = ofColor::blueViolet;
	Drag = 0.93;
	GetDrawn = true;
	LeaveTrail = true;

}

Kinematic::Kinematic(ofVec2f position, ofVec2f velocity)
{
	Position = position;
	Velocity = velocity;
	Orientation = 0;
	Rotation = 0;
	Radius = 10;
	Color = ofColor::blueViolet;
	Drag = 0.93;
	GetDrawn = true;
	LeaveTrail = true;

}


Kinematic::Kinematic(ofVec2f position, ofVec2f velocity, float orientation, float rotation)
{
	Position = position;
	Velocity = velocity;
	Orientation = orientation;
	Rotation = rotation;
	Radius = 10;
	Color = ofColor::blueViolet;
	Drag = 0.93;
	GetDrawn = true;
	LeaveTrail = true;


}

void Kinematic::ProcessSteering(DynamicSteering DynamSteer, float MaxAccel, float MaxSpeed, float DeltaTime)
{
	this->Velocity *= this->Drag;
	this->Velocity = ((DynamSteer.LinearAcceleration* DeltaTime *DynamSteer.DistanceScale)+ this->Velocity);

	if (this->Velocity.length() > MaxSpeed)
	{
		this->Velocity = this->Velocity.getNormalized() * MaxSpeed;
	}
	this->Position = Position += this->Velocity * DeltaTime;
	this->Orientation = this->Orientation + ofWrapRadians(DynamSteer.TargetOrientation - this->Orientation) *MaxAccel/360;
}





