#pragma once
#include <vector>
#include "ofVec2f.h"
#include "ofColor.h"

//Steering types
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\DynamicSteering.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\KinematicSteering.h"


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