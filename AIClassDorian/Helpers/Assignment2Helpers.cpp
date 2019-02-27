#include "Assignment2Helpers.h"


void Assignment2Helpers::ConstructSEAMap(DirectedWeightedGraph * pAppGraph)
{
	float radius = 5;
	Node Chengdu(0, ofVec2f(300, 60));
	Node Shanghai(1, ofVec2f(500, 20));
	Node Hanoi(2, ofVec2f(270, 180));
	Node Okinawa(3, ofVec2f(620, 80));
	Node Taiwan(4, ofVec2f(515, 135));
	Node Viet(5, ofVec2f(225, 240));
	Node Rangoon(6, ofVec2f(130, 255));
	Node Bangkok(7, ofVec2f(195, 310));
	Node Manila(8, ofVec2f(515, 285));
	Node Phnom(9, ofVec2f(250, 360));
	Node Koror(10, ofVec2f(735, 430));
	Node Bandar(11, ofVec2f(415, 480));
	Node KualaLampur(12, ofVec2f(225, 520));
	Node Jakarta(13, ofVec2f(300, 675));
	Node Kandari(14, ofVec2f(540, 630));


	pAppGraph->Edges.push_back(DirectedWeightedEdge(Chengdu, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Hanoi, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Okinawa, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Taiwan, Hanoi, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Viet, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Rangoon, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Bangkok, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Manila, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Phnom, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Koror, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Bandar, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(KualaLampur, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Jakarta, Shanghai, 10));
	pAppGraph->Edges.push_back(DirectedWeightedEdge(Kandari, Shanghai, 10));
}


//Uses a localized map, then quantizes to graph space
void Assignment2Helpers::ConstructStressMap(DirectedWeightedGraph * pAppGraph, int ApproxNumberOfNodes, int Width, int Height, int Connectivity)
{
	int SqRt = sqrt(ApproxNumberOfNodes);
	float XScale = Width / SqRt;
	float YScale = Height / SqRt;

	Node LastNode = Node(-1, ofVec2f(0, 0), 2);
	int count = 0;
	for (int i = 0; i < SqRt; i++)
	{
		for (int j = 0; j < SqRt; j++)
		{
			
			LastNode = Node(count, ofVec2f(j*XScale, i*YScale), 3);
			pAppGraph->GraphMap[count] = std::vector<DirectedWeightedEdge>(Connectivity);
			pAppGraph->Nodes.push_back(LastNode);
			count++;
		}
	}
	count = 0;
	for (int i = 0; i < SqRt; i++)
	{
		for (int j = 0; j < SqRt; j++)
		{
			int randomY;
			int randomX;
			for (int k = 0; k < Connectivity; k++)
			{
				randomY = (((int)ofRandom(-2, 2))) * SqRt;
				randomX = ((int)ofRandom(-2, 2));
				if ((count % SqRt == 0 && randomX + randomY <= 0) || (count % SqRt == SqRt-1 && randomX + randomY >= 0))
				{
					continue;
				}
				pAppGraph->GraphMap[count][k] = DirectedWeightedEdge(pAppGraph->Nodes[count], pAppGraph->Nodes[ofClamp(count + randomX + randomY, 0, SqRt*SqRt - 1)], rand() % 10);
				pAppGraph->Edges.push_back(pAppGraph->GraphMap[count][k]);
			}
			count++;
		}
	}
}



void Assignment2Helpers::DrawGraph(DirectedWeightedGraph * pAppGraph)
{
	ofSetColor(ofColor::black);
	if (pAppGraph->Edges.size() > 0)
	{
		for (int i = 0; i != (pAppGraph->Edges.size()); i++)
		{
			if (pAppGraph->Edges[i].GetCost() > 0)
			{
				//ofSetColor(pAppGraph->Edges[i].Color == ofColor::black ? ofColor::black : ofColor(25.5 * pAppGraph->Edges[i].GetCost() / 10.0f, 255 / pAppGraph->Edges[i].GetCost(), 0));
				//ofSetLineWidth(5/pAppGraph->Edges[i].GetCost());
				if (pAppGraph->Edges[i].Color != ofColor::black)
				{
					ofSetColor(ofColor::green);
					ofSetLineWidth(3);
				}
				else
				{
					ofSetColor(ofColor::black);
					ofSetLineWidth(1);
				}
				ofDrawLine(pAppGraph->Edges[i].StartPosition, pAppGraph->Edges[i].EndPosition);
			}
		}
	}
	ofSetColor(ofColor::black);

	if (pAppGraph->Nodes.size() > 0)
	{
		for (int j = 0; j < pAppGraph->Nodes.size(); j++)
		{
			if (pAppGraph->Nodes[j].GetID() > 0)
			{
				ofDrawCircle(pAppGraph->Nodes[j].Position, pAppGraph->Nodes[j].Radius);
			}
		}

	}
	ofSetColor(ofColor::white);
}