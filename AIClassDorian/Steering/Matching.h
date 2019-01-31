#pragma once
#include <iostream>

//Steering Classes
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\DynamicSteering.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\KinematicSteering.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Steering\Orientation.h"

//Data structures
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\DataStructs\Kinematic.h"

//Helpers
#include "ofVec2f.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\Helpers\ofAppHelpers.h"


class Matching
{
public:

	static DynamicSteering MatchVelocity(Kinematic MyObject, Kinematic Target, float MaxAccel, float MatchThreshold, float DeltaTime);
	static DynamicSteering MatchOrientation(Kinematic MyObject, Kinematic Target, float MaxAccel, float MatchThreshold, float DeltaTime);

};