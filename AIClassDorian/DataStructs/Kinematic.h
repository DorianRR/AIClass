#pragma once
#include <vector>
#include "ofVec2f.h"
#include "ofMath.h"
#include "ofColor.h"

//Steering types
#include "Steering\DynamicSteering.h"
#include "Steering\KinematicSteering.h"


struct Kinematic
{
public:
	//Public members
	ofVec2f Position;
	ofVec2f Velocity;
	float Orientation;
	float Rotation;

	float Drag;
	float Radius;
	ofColor Color;

	bool GetDrawn;
	bool LeaveTrail;

	//Constructors
	Kinematic();
	Kinematic(ofVec2f position);
	Kinematic(ofVec2f position, ofVec2f velocity);
	Kinematic(ofVec2f position, ofVec2f velocity, float orientation, float rotation);


	void ProcessSteering(DynamicSteering DynStr, float MaxAccel, float MaxSpeed, float DeltaTime);
};