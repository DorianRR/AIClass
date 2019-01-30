#pragma once
#pragma once
#include "ofVec2f.h"

struct KinematicSteering
{
public:
	ofVec2f Velocity = ofVec2f::zero();
	float Orientation = 0.0f;
};