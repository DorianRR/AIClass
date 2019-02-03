#pragma once

//Steering Classes
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\DynamicSteering.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\Orientation.h"

//Data structures
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\DataStructs\Kinematic.h"

//Helpers
#include "ofMath.h"
#include "ofVec2f.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Helpers\ofAppHelpers.h"


class Wander
{

public:

	static DynamicSteering GetDynamicSteering(Kinematic MyObject, float WanderVariance, float DeltaTime);
};