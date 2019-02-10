#pragma once
#include <vector>
#include "ofVec2f.h"
#include "ofColor.h"

//Steering types
#include "Steering\DynamicSteering.h"
#include "Steering\KinematicSteering.h"


struct Crumb
{
public:
	ofVec2f Position;
	float Radius;
	ofColor Color;
	
	bool InUse;

	Crumb();
	
	void Update(float DeltaTime);
};