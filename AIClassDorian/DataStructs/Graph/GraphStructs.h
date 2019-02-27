#pragma once
#include <vector>
#include <map>
#include "ofVec2f.h"
#include "ofColor.h"


struct Node
{
public:
	Node() { ID = 0; };

	Node(int InitID) { ID = InitID; };

	Node(int InitID, ofVec2f InitPostion)
	{
		ID = InitID;
		Position = InitPostion;
	}

	Node(int InitID, ofVec2f InitPostion, int SetRadius)
	{
		ID = InitID;
		Position = InitPostion;
		Radius = SetRadius;
	}

	int GetID();


private:
	int ID;

public:
	//Visual information, for drawing and debugging
#ifdef _DEBUG
	ofVec2f Position;
	float Radius = 6;
	ofColor Color;
#endif
};

/*
* Negative weights mean they're an invalid edge 
*/
struct DirectedWeightedEdge
{
public:

	DirectedWeightedEdge()
	{
		Source = Node(-1);
		Sink = Node(-1);
		Cost = 0;
#ifdef _DEBUG 
		StartPosition = ofVec2f::zero();
		EndPosition = ofVec2f::zero();
		Color = ofColor::black;
#endif
	}

	DirectedWeightedEdge(float InitCost)
	{
		Source = Node(-1);
		Sink = Node(-1);
		Cost = InitCost;
#ifdef _DEBUG 
		StartPosition = ofVec2f::zero();
		EndPosition = ofVec2f::zero();
		Color = ofColor::black;
#endif
	}

	DirectedWeightedEdge(Node InitSource, Node InitSink, float InitCost)
	{
		Source = InitSource;
		Sink = InitSink;
		Cost = InitCost;
#ifdef _DEBUG 
		StartPosition = InitSource.Position;
		EndPosition = InitSink.Position;
		Color = ofColor::black;
#endif
	}

	float GetCost();
	Node GetNodeSource();
	Node GetNodeSink();

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


	DirectedWeightedGraph(int NumberOfEdges)
	{
		Edges.reserve(NumberOfEdges);
	}
	
	void Clear()
	{
		Edges.clear();
		Edges.shrink_to_fit();
		GraphMap.clear();
	}

	std::vector<Node> Nodes;
	std::vector<DirectedWeightedEdge> Edges;
	std::map<int, std::vector<DirectedWeightedEdge>> GraphMap;

};

inline float DirectedWeightedEdge::GetCost()
{
	return Cost;
}

inline Node DirectedWeightedEdge::GetNodeSource()
{
	return Source;
}

inline Node DirectedWeightedEdge::GetNodeSink()
{
	return Sink;
}

inline int Node::GetID()
{
	return ID;
}