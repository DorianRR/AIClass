#pragma once

#include "ofVec2f.h"

//Graph
#include "DataStructs/Graph/GraphStructs.h"

//Priority Queue
#include "DataStructs/PriorityQueue.h"

class Assignment2ofApp; 

namespace Navigation
{
	static const Assignment2ofApp * Context;

	ofVec2f Localize(int Node);
	int Quantize(ofVec2f InputPoint);

	//Not implemented
	bool Validate(const DirectedWeightedGraph * GraphToValidate);

	void Init(const Assignment2ofApp * WorldContext);

	class NavMesh
	{
	public:
		static void GenerateNavMesh();
	};

	class AStar
	{
	public:
		static std::vector<DirectedWeightedEdge> GetPath(ofVec2f StartingWorldPoint, ofVec2f TargetWorldPoint);
	};


	class Dijstra
	{
	public:
		//Not implemented
		static std::vector<DirectedWeightedEdge> GetPath(ofVec2f StartingWorldPoint, ofVec2f TargetWorldPoint);
	};

	namespace Heuristics
	{
		float GetBirdsPath(Node Start, Node Goal);

		//Not Implemented
		float GetManhattanDistance(Node Start, Node Goal);
	}
}