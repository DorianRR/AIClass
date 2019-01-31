#pragma once
#include <vector>
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\DataStructs\Kinematic.h"
#include "..\apps\myApps\AiClassDorian\AIClass\AIClassDorian\DataStructs\Crumb.h"

#include "ofMain.h"


class ofAppHelpers
{

public:

	static void DrawBoids(std::vector<Kinematic> boidsToDraw);

	static void LeaveCrumbs(std::vector<Kinematic> boidsToDraw, std::vector<Crumb> * crumbs);
	static void UpdateAndDrawCrumbs(std::vector<Crumb> * crumbs, float DeltaTime);

	static void CheckForOnScreen(std::vector<Kinematic> * boidsToDraw);


};