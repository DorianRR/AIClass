#pragma once

//Graph
#include "DataStructs/Graph/GraphStructs.h"

class AStar
{
	static std::vector<DirectedWeightedEdge> GetPath(DirectedWeightedGraph * pAppGraph, Node Start, Node Target);



};


class Dijstra
{
	static std::vector<DirectedWeightedEdge> GetPath(DirectedWeightedGraph * pAppGraph, Node Start, Node Target);


};