#include "ofAppHelpers.h"


void ofAppHelpers::DrawBoids(std::vector<Kinematic> boidsToDraw)
{
		for (std::vector<Kinematic>::size_type i = 0; i != boidsToDraw.size(); i++)
		{
			ofSetColor(boidsToDraw[i].Color);
			ofDrawCircle(boidsToDraw[i].Position, boidsToDraw[i].Radius);
			ofVec2f x1 = boidsToDraw[i].Position + ofVec2f(boidsToDraw[i].Velocity.y, boidsToDraw[i].Velocity.x *-1) * 10;
			ofVec2f x2 = boidsToDraw[i].Position + ofVec2f(-boidsToDraw[i].Velocity.y, boidsToDraw[i].Velocity.x) * 10;
			ofVec2f x3 = boidsToDraw[i].Position + boidsToDraw[i].Velocity.normalized() * 20;
			ofDrawTriangle(x1, x2, x3);
			ofSetColor(ofColor::floralWhite);
		}
}
