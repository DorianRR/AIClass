#pragma once
#include "ofVec2f.h"

struct DynamicSteering
{
public:
	ofVec2f LinearAcceleration = ofVec2f::zero();
	float TargetOrientation = 0.0f;
	float DistanceScale = 1;
};