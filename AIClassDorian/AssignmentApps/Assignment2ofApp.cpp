#include "Assignment2ofApp.h"



//--------------------------------------------------------------
void Assignment2ofApp::setup()
{
	Mode = MenuMode;
	SEAMapImage.load("SEAMap.jpg");


	SEAMap.addListener(this, &Assignment2ofApp::SetupSEAsianMap);
	Clear.addListener(this, &Assignment2ofApp::ClearMode);
	GUI.setup();

	GUI.add(SEAMap.setup("Southeast Asian Test Map"));
	GUI.add(Clear.setup("Clear Mode"));

}

void Assignment2ofApp::SetupSEAsianMap()
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


	Graph.Edges.push_back(DirectedWeightedEdge(Chengdu, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Hanoi, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Okinawa, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Taiwan, Hanoi, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Viet, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Rangoon, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Bangkok, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Manila, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Phnom, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Koror, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Bandar, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(KualaLampur, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Jakarta, Shanghai, 10));
	Graph.Edges.push_back(DirectedWeightedEdge(Kandari, Shanghai, 10));


}

//--------------------------------------------------------------
void Assignment2ofApp::update() {}

//--------------------------------------------------------------
void Assignment2ofApp::draw()
{
	SEAMapImage.draw(0, 0);

	GUI.draw();
#ifdef _DEBUG
	if (Graph.Edges.size() > 0)
	{
		ofAppHelpers::DrawGraph(Graph);
	}
#endif
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
void Assignment2ofApp::mousePressed(int x, int y, int button) {}

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
	Graph.Clear();
}
