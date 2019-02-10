#pragma once
#include "DataStructs\Kinematic.h"
#include "DataStructs\Crumb.h"

#include <vector>
#include "ofMath.h"


class SetupHelpers
{
public:
	static void DynamicSeekSetup(std::vector<Kinematic> * boidsToDraw);
	static void WanderSetup(std::vector<Kinematic> * boidsToDraw, int NumberOfWanderers);
	static void FlockSetup(std::vector<Kinematic> * boidsToDraw, int NumberInFlock);
	static void InitializeCrumbs(std::vector<Crumb> * crumbs, int numberOfCrumbs);
};