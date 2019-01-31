#include "Kinematic.h"


Kinematic::Kinematic()
{
	Position = ofVec2f::zero();
	Velocity = ofVec2f::zero();
	Orientation = 0;
	Rotation = 0;
	Radius = 10;
	Color = ofColor::blueViolet;
	Drag = 1;
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
	Drag = 1;
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
	Drag = 1;
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
	Drag = 1;
	GetDrawn = true;
	LeaveTrail = true;
	

}

void Kinematic::ProcessSteering(DynamicSteering DynamSteer, float DeltaTime)
{
	this->Position = Position += DynamSteer.Velocity * DeltaTime;
	this->Orientation = DynamSteer.Orientation;
	this->Velocity = DynamSteer.Velocity;
	this->Velocity *= this->Drag;
}
