#pragma once
#include <iostream>

//Steering Classes
#include "Steering\DynamicSteering.h"
#include "Steering\KinematicSteering.h"

//Data structures
#include "DataStructs\Kinematic.h"

//Helpers
#include "ofVec2f.h"
#include "Helpers\ofAppHelpers.h"
#include "ofMath.h"


class Orientation
{

public:
	static float GetAllignAngle(ofVec2f VecToAllignTo);

	static float GetDynamicFace(Kinematic MyObject, Kinematic Target);

};