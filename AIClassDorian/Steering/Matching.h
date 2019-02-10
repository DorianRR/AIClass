#pragma once
#include <iostream>

//Steering Classes
#include "Steering\DynamicSteering.h"
#include "Steering\KinematicSteering.h"
#include "Steering\Orientation.h"

//Data structures
#include "DataStructs\Kinematic.h"

//Helpers
#include "ofVec2f.h"
#include "Helpers\ofAppHelpers.h"


class Matching
{
public:

	static DynamicSteering MatchVelocity(Kinematic MyObject, Kinematic Target, float MatchThreshold);

};