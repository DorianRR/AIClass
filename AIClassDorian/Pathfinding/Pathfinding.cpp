#include "Pathfinding.h"


#include "AssignmentApps/Assignment2ofApp.h"

using namespace Navigation;

void Navigation::Init(const Assignment2ofApp * WorldContext)
{
	Context = WorldContext;
}

// This assumes we have a square navmesh, needs to be generalized
ofVec2f Navigation::Localize(const int Node)
{
	int SqRt = sqrt(Context->pAppGraph->Nodes.size());
	float x = ((SqRt-1) - (Node % (SqRt - 1))) * Context->AppScreenWidth / (SqRt - 1);
	int ScaleValue = ((SqRt - 1) - (Node % (SqRt - 1)));
	float y = (Node - ScaleValue) / (SqRt - 1) * Context->AppScreenHeight / (SqRt - 1);

	return ofVec2f(x, y);
}

int Navigation::Quantize(const ofVec2f InputPoint)
{
	int SqRt = sqrt(Context->pAppGraph->Nodes.size());
	int ColumnNode = round(InputPoint.x / Context->AppScreenWidth * (SqRt - 1));
	int RowNode = round(InputPoint.y / Context->AppScreenHeight *SqRt)*SqRt;
	return(ColumnNode + RowNode);
}

void NavMesh::GenerateNavMesh()
{

	DirectedWeightedGraph * pAppGraph = Context->pAppGraph;
	int SqRt = sqrt(1000);
	float XScale = Context->AppScreenWidth / SqRt;
	float YScale = Context->AppScreenHeight / SqRt;
	float DiagonalScale = sqrt((XScale*XScale)+(YScale*YScale));

	Node LastNode = Node(-1, ofVec2f(0, 0), 2);
	int count = 0;
	for (int i = 0; i < SqRt; i++)
	{
		for (int j = 0; j < SqRt; j++)
		{

			LastNode = Node(count, ofVec2f(j*XScale, i*YScale), 3);
			pAppGraph->GraphMap[count] = std::vector<DirectedWeightedEdge>(8);
			pAppGraph->Nodes.push_back(LastNode);
			count++;
		}
	}
	count = 0;
	for (int i = 0; i < SqRt; i++)
	{
		for (int j = 0; j < SqRt; j++)
		{
			bool rightEdge = ((count) % SqRt == SqRt - 1);
			bool leftEdge = ((count) % SqRt == 0 || count == 0);

			//Vertical
			pAppGraph->GraphMap[count][5] = DirectedWeightedEdge(pAppGraph->Nodes[count], pAppGraph->Nodes[ofClamp(count + SqRt, 0, SqRt*SqRt - 1)], YScale);
			pAppGraph->Edges.push_back(pAppGraph->GraphMap[count][5]);

			pAppGraph->GraphMap[count][3] = DirectedWeightedEdge(pAppGraph->Nodes[count], pAppGraph->Nodes[ofClamp(count - SqRt, 0, SqRt*SqRt - 1)], YScale);
			pAppGraph->Edges.push_back(pAppGraph->GraphMap[count][3]);


			////Horizontal
			if (!leftEdge)
			{
				pAppGraph->GraphMap[count][1] = DirectedWeightedEdge(pAppGraph->Nodes[count], pAppGraph->Nodes[ofClamp(count - 1, 0, SqRt*SqRt - 1)], XScale);
				pAppGraph->Edges.push_back(pAppGraph->GraphMap[count][1]);
			}
			if (!rightEdge)
			{
				pAppGraph->GraphMap[count][7] = DirectedWeightedEdge(pAppGraph->Nodes[count], pAppGraph->Nodes[ofClamp(count + 1, 0, SqRt*SqRt - 1)], XScale);
				pAppGraph->Edges.push_back(pAppGraph->GraphMap[count][7]);
			}


			//Diagonal
			if (!leftEdge)
			{
				pAppGraph->GraphMap[count][0] = DirectedWeightedEdge(pAppGraph->Nodes[count], pAppGraph->Nodes[ofClamp(count - (SqRt + 1), 0, SqRt*SqRt - 1)], DiagonalScale);
				pAppGraph->Edges.push_back(pAppGraph->GraphMap[count][0]);

				pAppGraph->GraphMap[count][2] = DirectedWeightedEdge(pAppGraph->Nodes[count], pAppGraph->Nodes[ofClamp(count + (SqRt - 1), 0, SqRt*SqRt - 1)], DiagonalScale);
				pAppGraph->Edges.push_back(pAppGraph->GraphMap[count][2]);

			}
			if (!rightEdge)
			{
				pAppGraph->GraphMap[count][4] = DirectedWeightedEdge(pAppGraph->Nodes[count], pAppGraph->Nodes[ofClamp(count - (SqRt - 1), 0, SqRt*SqRt - 1)], DiagonalScale);
				pAppGraph->Edges.push_back(pAppGraph->GraphMap[count][4]);

				pAppGraph->GraphMap[count][6] = DirectedWeightedEdge(pAppGraph->Nodes[count], pAppGraph->Nodes[ofClamp(count + (SqRt + 1), 0, SqRt*SqRt - 1)], DiagonalScale);
				pAppGraph->Edges.push_back(pAppGraph->GraphMap[count][6]);
			}
			count++;
		}
	}
}

//Currently working in visual debug mode, where it highlights edges for the path but doesn't return a valid path for agent navigation
std::vector<DirectedWeightedEdge> AStar::GetPath(ofVec2f StartingWorldPoint, ofVec2f TargetWorldPoint)
{
	Node GoalNode = Context->pAppGraph->Nodes[Quantize(TargetWorldPoint)];

	PriorityQueue<Node> Fringe;
	Fringe.Push(Context->pAppGraph->Nodes[Quantize(StartingWorldPoint)]);

	std::vector<int> ClosedList;
	std::vector<int> StdFringe;
	StdFringe.push_back(Context->pAppGraph->Nodes[Quantize(StartingWorldPoint)].GetID());

	while (Fringe.Size() > 0)
	{
		Node CurrentNode = Fringe.Pop().Element;
		if (CurrentNode.GetID() == GoalNode.GetID())
		{
			ClosedList.push_back(CurrentNode.GetID());
			break;
		}
		for (int i = 0; i < Context->pAppGraph->GraphMap[CurrentNode.GetID()].size(); i++)
		{
			QueueElement<Node> temp = Context->pAppGraph->GraphMap[CurrentNode.GetID()][i].GetNodeSink();
			if (temp.Element.GetID() == -1) continue;
			if (!(std::find(ClosedList.begin(), ClosedList.end(), temp.Element.GetID()) != ClosedList.end() || std::find(StdFringe.begin(), StdFringe.end(), temp.Element.GetID()) != StdFringe.end()))
			{
				temp.mPriority = Heuristics::GetBirdsPath(temp.Element, GoalNode) + Context->pAppGraph->GraphMap[CurrentNode.GetID()][i].GetCost();
				StdFringe.push_back(temp.Element.GetID());
				Fringe.Push(temp);
			}
		}
		if (!(std::find(ClosedList.begin(), ClosedList.end(), CurrentNode.GetID()) != ClosedList.end()))
		{
			ClosedList.push_back(CurrentNode.GetID());
		}
	}



	for (int i = 0; i < ClosedList.size()-1; i++)
	{
		DirectedWeightedEdge PathEdge = DirectedWeightedEdge(Context->pAppGraph->Nodes[ClosedList[i]], Context->pAppGraph->Nodes[ClosedList[i+1]], 1);
		PathEdge.Color = ofColor::green;
		Context->pAppGraph->Edges.push_back(PathEdge);
	
	}

	//Not Implemented
	std::vector<DirectedWeightedEdge> FIXME;
	return FIXME;
}

std::vector<DirectedWeightedEdge> Dijstra::GetPath(ofVec2f StartingWorldPoint, ofVec2f TargetWorldPoint)
{
	return std::vector<DirectedWeightedEdge>(0);
}

float Heuristics::GetBirdsPath(Node Start, Node Goal)
{
	return((Start.Position).distance(Goal.Position));
}
