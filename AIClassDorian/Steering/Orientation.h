#pragma once
#include <iostream>

#include "ofMath.h"

//Steering Classes
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\DynamicSteering.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\KinematicSteering.h"

//Data structures
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\DataStructs\Kinematic.h"

//Helpers
#include "ofVec2f.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Helpers\ofAppHelpers.h"


class Orientation
{

public:
	static float GetAllignAngle(ofVec2f VecToAllignTo);

	static float GetDynamicFace(Kinematic MyObject, Kinematic Target, float MaxAccel, float DeltaTime);

};