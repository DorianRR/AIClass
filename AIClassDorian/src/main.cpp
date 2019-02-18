#pragma once

#include "ofMain.h"
#include "AssignmentApps\ofApp.h"
#include "AssignmentApps\Assignment2ofApp.h"


//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context




	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	
	//Assignment 1
	//ofRunApp(new ofApp());
	
	//Assignment 2
	ofRunApp(new Assignment2ofApp());

}

