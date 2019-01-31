#include "Crumb.h"


Crumb::Crumb()
{
	Radius = 7.5;
	Color = ofColor::blueViolet;
	InUse = false;
}


void Crumb::Update(float DeltaTime)
{
	Radius -= DeltaTime * 2.5;
	if (Radius < .5)
	{
		InUse = false;
		Radius = 7.5;
	}
}
