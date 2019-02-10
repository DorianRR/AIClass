#pragma once

//Steering Classes
#include "Steering\DynamicSteering.h"
#include "Steering\Orientation.h"

//Data structures
#include "DataStructs\Kinematic.h"

//Helpers
#include "ofMath.h"
#include "ofVec2f.h"
#include "Helpers\ofAppHelpers.h"


class Wander
{

public:

	static DynamicSteering GetDynamicSteering(Kinematic MyObject, float WanderVariance);
};