#include "DataStructs/Graph/GraphStructs.h"



inline float DirectedWeightedEdge::GetCost()
{
	return Cost;
}

inline Node DirectedWeightedEdge::GetSource()
{
	return Source;
}

inline Node DirectedWeightedEdge::GetSink()
{
	return Sink;
}

inline int Node::GetID()
{
	return ID;
}