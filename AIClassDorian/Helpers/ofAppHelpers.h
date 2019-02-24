#pragma once
#include <vector>

//Boids
#include "DataStructs\Kinematic.h"
#include "DataStructs\Crumb.h"

//Graphs
//#include "DataStructs\Graph\GraphStructs.h"

#include "ofMain.h"


class ofAppHelpers
{
public:

	//Boid
	static void DrawBoids(std::vector<Kinematic> boidsToDraw);
	static void DrawBoid(Kinematic boidToDraw);
	static void LeaveCrumbs(std::vector<Kinematic> boidsToDraw, std::vector<Crumb> * crumbs);
	static void UpdateAndDrawCrumbs(std::vector<Crumb> * crumbs, float DeltaTime);
	static void CheckForOnScreen(std::vector<Kinematic> * boidsToDraw);



};