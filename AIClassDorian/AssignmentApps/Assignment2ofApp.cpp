#include "Assignment2ofApp.h"



//--------------------------------------------------------------
void Assignment2ofApp::setup()
{
	AppScreenHeight = 768;
	AppScreenWidth = 1024;
	AppMode = MenuMode;
	SEAMapImage.load("SEAMap.jpg");


	HeavyMapTest.addListener(this, &Assignment2ofApp::SetupStressMap);
	FlatNavmesh.addListener(this, &Assignment2ofApp::SetupFlatNavmesh);
	Clear.addListener(this, &Assignment2ofApp::ClearMode);
	GUI.setup();

	GUI.add(HeavyMapTest.setup("Heavy Map Test"));
	GUI.add(FlatNavmesh.setup("FlatNavMesh"));
	GUI.add(Clear.setup("Clear Mode"));


	Navigation::Init(this);
}

void Assignment2ofApp::SetupSEAsianMap()
{
	pAppGraph = new DirectedWeightedGraph(0);

	AppMode = SEAMapMode;
	Assignment2Helpers::ConstructSEAMap(pAppGraph);
}

void Assignment2ofApp::SetupStressMap()
{
	pAppGraph = new DirectedWeightedGraph(1000);

	AppMode = StressTestMode;
	Assignment2Helpers::ConstructStressMap(pAppGraph, 1000, AppScreenWidth, AppScreenHeight, 5);

}

void Assignment2ofApp::SetupFlatNavmesh()
{
	pAppGraph = new DirectedWeightedGraph(1000);

	AppMode = StressTestMode;
	//Assignment2Helpers::ConstructStressMap(pAppGraph, 1000, AppScreenWidth, AppScreenHeight, 5);
	Navigation::NavMesh::GenerateNavMesh();

}


//--------------------------------------------------------------
void Assignment2ofApp::update() {}

//--------------------------------------------------------------
void Assignment2ofApp::draw()
{

	switch (AppMode)
	{
	case MenuMode:
		break;
	case SEAMapMode:
		SEAMapImage.draw(0, 0);
#ifdef _DEBUG
		if (pAppGraph->Edges.size() > 0)
		{
			Assignment2Helpers::DrawGraph(pAppGraph);
		}
#endif
	case StressTestMode:
#ifdef _DEBUG
		if (pAppGraph->Edges.size() > 0)
		{
			Assignment2Helpers::DrawGraph(pAppGraph);
		}
#endif
		break;
	}
	GUI.draw();

}

//--------------------------------------------------------------
void Assignment2ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void Assignment2ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void Assignment2ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void Assignment2ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void Assignment2ofApp::mousePressed(int x, int y, int button) 
{
	if (pAppGraph && AppMode == StressTestMode)
	{
		Navigation::AStar::GetPath(ofVec2f::zero(), ofVec2f(x, y));
	}
}

//--------------------------------------------------------------
void Assignment2ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void Assignment2ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void Assignment2ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void Assignment2ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void Assignment2ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void Assignment2ofApp::dragEvent(ofDragInfo dragInfo) {}

//--------------------------------------------------------------
void Assignment2ofApp::ClearMode()
{
	AppMode = MenuMode;
	pAppGraph->Clear();
}

//--------------------------------------------------------------
Assignment2ofApp::~Assignment2ofApp()
{
	if (pAppGraph) { delete(pAppGraph); }
}



