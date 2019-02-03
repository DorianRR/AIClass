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


class Seek {

public:
	static KinematicSteering GetKinematicSteering(Kinematic MyObject, Kinematic Target, float MaxVel, float StopRadius);

	static DynamicSteering GetDynamicSteering(Kinematic MyObject, Kinematic Target, float StopRadius, float DeltaTime);
	static DynamicSteering GetDynamicSteering(Kinematic MyObject, Kinematic Target, float SlowRadius, float StopRadius, float DeltaTime);

};
