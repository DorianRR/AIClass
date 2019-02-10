#pragma once
#include <vector>
#include "ofVec2f.h"
#include "ofColor.h"


struct Node
{
public:
	int GetID();


private:
	int ID;

public:
	//Visual information, for drawing and debugging
#ifdef _DEBUG
	ofVec2f Position;
	float Radius;
	ofColor Color;
#endif
};


struct DirectedWeightedEdge
{
public:
	float GetCost();
	Node GetSource();
	Node GetSink();

private:
	Node Source;
	Node Sink;
	float Cost;

public:
//Visual information, for drawing and debugging
#ifdef _DEBUG 
	ofVec2f StartPosition, EndPosition;
	ofColor Color;
#endif
};



struct NodeRecord
{


};

class DirectedWeightedGraph
{
public:

	std::vector<DirectedWeightedEdge> Edges;


};


