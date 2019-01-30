#pragma once
#include "ofVec2f.h"

struct DynamicSteering
{
public:
	ofVec2f Acceleration = ofVec2f::zero();
	float AngularAcceleration = 0.0f;
};