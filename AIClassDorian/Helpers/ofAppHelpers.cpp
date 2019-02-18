#include "ofAppHelpers.h"


//========================================================================================================
//Drawing Boids
//========================================================================================================
void ofAppHelpers::DrawBoids(std::vector<Kinematic> boidsToDraw)
{
	for (std::vector<Kinematic>::size_type i = 0; i != boidsToDraw.size(); i++)
	{
		if (boidsToDraw[i].GetDrawn)
		{
			ofSetColor(boidsToDraw[i].Color);
			ofDrawCircle(boidsToDraw[i].Position, boidsToDraw[i].Radius);

			ofVec2f temp = ofVec2f(cos(boidsToDraw[i].Orientation), sin(boidsToDraw[i].Orientation));
			ofVec2f x1 = boidsToDraw[i].Position + ofVec2f(temp.y, temp.x *-1).getNormalized() * 10;
			ofVec2f x2 = boidsToDraw[i].Position + ofVec2f(-temp.y, temp.x).getNormalized() * 10;
			ofVec2f x3 = boidsToDraw[i].Position + temp.getNormalized() * 20;

			ofDrawTriangle(x1, x2, x3);
		}
	}
}

void ofAppHelpers::DrawBoid(Kinematic boidToDraw)
{
	
	if (boidToDraw.GetDrawn)
	{
		ofSetColor(boidToDraw.Color);
		ofDrawCircle(boidToDraw.Position, boidToDraw.Radius);

		ofVec2f temp = ofVec2f(cos(boidToDraw.Orientation), sin(boidToDraw.Orientation));
		ofVec2f x1 = boidToDraw.Position + ofVec2f(temp.y, temp.x *-1).getNormalized() * 10;
		ofVec2f x2 = boidToDraw.Position + ofVec2f(-temp.y, temp.x).getNormalized() * 10;
		ofVec2f x3 = boidToDraw.Position + temp.getNormalized() * 20;

		ofDrawTriangle(x1, x2, x3);
	}
}

void ofAppHelpers::LeaveCrumbs(std::vector<Kinematic> boidsToDraw, std::vector<Crumb> * crumbs)
{
	bool DoOnce = true;
	for (int i = 0; i != boidsToDraw.size(); i++)
	{
		if (boidsToDraw[i].LeaveTrail && boidsToDraw[i].GetDrawn)
		{

			for (unsigned int j = 0; j < (*crumbs).size(); j++)
			{
				if (!(*crumbs)[j].InUse && DoOnce)
				{

					(*crumbs)[j].Position = boidsToDraw[i].Position;
					(*crumbs)[j].Radius = 7.5;
					(*crumbs)[j].InUse = true;
					(*crumbs)[j].Color = boidsToDraw[i].Color;
					DoOnce = false;
				}
			}
			DoOnce = true;
		}
	}
}

void ofAppHelpers::UpdateAndDrawCrumbs(std::vector<Crumb> * crumbs, float DeltaTime)
{
	for (int i = 0; i != (*crumbs).size(); i++)
	{
		(*crumbs)[i].Update(DeltaTime);
		if ((*crumbs)[i].InUse)
		{
			ofSetColor((*crumbs)[i].Color);
			ofDrawCircle((*crumbs)[i].Position, (*crumbs)[i].Radius);
		}
	}
}

void ofAppHelpers::CheckForOnScreen(std::vector<Kinematic> * boidsToDraw)
{
	for (int i = 0; i != (*boidsToDraw).size(); i++)
	{
		if ((*boidsToDraw)[i].Position.x > 1024 || (*boidsToDraw)[i].Position.x < 0 || (*boidsToDraw)[i].Position.y > 768 || (*boidsToDraw)[i].Position.y < 0)
		{
			(*boidsToDraw)[i].GetDrawn = false;
		}
	}
}

//=========================================================================================================
//Draw Graph
//=========================================================================================================
void ofAppHelpers::DrawGraph(DirectedWeightedGraph Graph)
{
	ofSetColor(ofColor::black);
	ofSetLineWidth(2);
	for (int i = 0; i != (Graph.Edges.size()); i++)
	{

		//unresolved external
		ofDrawCircle(Graph.Edges[i].GetNodeSource().Position, Graph.Edges[i].GetNodeSource().Radius);
		ofDrawLine(Graph.Edges[i].StartPosition, Graph.Edges[i].EndPosition);
	}

	ofSetColor(ofColor::white);
}