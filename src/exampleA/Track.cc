#include "Track.h"

void Track::setEnergy( double mass, double momentum )
{
	energy = sqrt(pow(mass,2) + pow(momentum,2));
}

Track::Track( double x, double y, double e )
	: positionX(x),
	  positionY(y),
	  energy(e)
{

}

Track::~Track() { }
