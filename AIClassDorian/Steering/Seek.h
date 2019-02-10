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


class Seek {

public:
	static KinematicSteering GetKinematicSteering(Kinematic MyObject, Kinematic Target, float MaxVel, float StopRadius);

	static DynamicSteering GetDynamicSteering(Kinematic MyObject, Kinematic Target, float StopRadius);
	static DynamicSteering GetDynamicSteering(Kinematic MyObject, Kinematic Target, float SlowRadius, float StopRadius);

};
