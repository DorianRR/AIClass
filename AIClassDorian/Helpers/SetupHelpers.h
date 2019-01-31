#pragma once
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\DataStructs\Kinematic.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\DataStructs\Crumb.h"

#include <vector>
#include "ofMath.h"


class SetupHelpers
{
public:
	static void DynamicSeekSetup(std::vector<Kinematic> * boidsToDraw);
	static void WanderSetup(std::vector<Kinematic> * boidsToDraw, int NumberOfWanderers);
	static void InitializeCrumbs(std::vector<Crumb> * crumbs, int numberOfCrumbs);
};