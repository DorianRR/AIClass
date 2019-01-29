#include "Kinematic.h"


Kinematic::Kinematic()
{
	Position = ofVec2f::zero();
	Velocity = ofVec2f::zero();
	Orientation = 0;
	Rotation = 0;
	Radius = 10;
	Color = ofColor::blueViolet;
}

Kinematic::Kinematic(ofVec2f position)
{
	Position = position;
	Velocity = ofVec2f::zero();
	Orientation = 0;
	Rotation = 0;
	Radius = 10;
	Color = ofColor::blueViolet;
}

Kinematic::Kinematic(ofVec2f position, ofVec2f velocity)
{
	Position = position;
	Velocity = velocity;
	Orientation = 0;
	Rotation = 0;
	Radius = 10;
	Color = ofColor::blueViolet;
}


Kinematic::Kinematic(ofVec2f position, ofVec2f velocity, float orientation, float rotation)
{
	Position = position;
	Velocity = velocity;
	Orientation = orientation;
	Rotation = rotation;
	Radius = 10;
	Color = ofColor::blueViolet;
}
