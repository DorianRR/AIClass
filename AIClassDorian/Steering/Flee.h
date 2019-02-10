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


class Flee {

public:
	static DynamicSteering GetDynamicSteering(Kinematic MyObject, Kinematic Target, float MaxDistance);
	
	static DynamicSteering GetDynamicSteering(Kinematic MyObject, std::vector<Kinematic> Targets, float MaxDistance);

};
