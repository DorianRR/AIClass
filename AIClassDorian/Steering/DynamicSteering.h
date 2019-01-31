#pragma once
#include "ofVec2f.h"

struct DynamicSteering
{
public:
	ofVec2f Velocity = ofVec2f::zero();
	float Orientation = 0.0f;
};