#pragma onc

//Debugging
#include "assert.h"

//Math
#include "ofMath.h"
#include <cmath>

//Graph
#include "DataStructs\Graph\GraphStructs.h"

//Draw
#include "ofGraphics.h"
#include "ofColor.h"

class Assignment2Helpers
{

public:

	static void ConstructSEAMap(DirectedWeightedGraph * pAppGraph);
	
	static void ConstructStressMap(DirectedWeightedGraph * pAppGraph, int ApproxNumberOfNodes, int Width, int Height, int Connectivity);
	


	//Draw
	static void DrawGraph(DirectedWeightedGraph * pAppGraph);

};