#pragma once
#include <vector>
#include "ofVec2f.h"
#include "ofColor.h"

//using namespace std;


struct Kinematic
{
public:
	//Public members
	ofVec2f Position;
	ofVec2f Velocity;
	float Orientation;
	float Rotation;
	float Radius;
	ofColor Color;



	//Constructors
	Kinematic();
	Kinematic(ofVec2f position);
	Kinematic(ofVec2f position, ofVec2f velocity);
	Kinematic(ofVec2f position, ofVec2f velocity, float orientation, float rotation);

};