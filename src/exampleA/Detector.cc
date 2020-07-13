#include "Detector.h"

#include "Hit.h"
#include "Track.h"


Detector::Detector( std::string title, double dimX, double dimY, double resX, double resY )
	: name(title),
	  sizeX(dimX),
	  sizeY(dimY),
	  resolutionX(resX),
	  resolutionY(resY)
{ }

std::vector<Hit*> Detector::generateHits( Track* track )
{
	std::vector<Hit*> hits;
	int numberHits = random->Poisson(2);

	for( int iHit = 0; iHit < numberHits; ++iHit )
	{
		double hitX = random->Gaus(track->getPosX(), resolutionX);
		double hitY = random->Gaus(track->getPosY(), resolutionY);

		Hit* hit = new Hit(hitX, hitY, this, track);
		hits.push_back(hit);
	}
	return hits;
}

Detector::~Detector() {}
