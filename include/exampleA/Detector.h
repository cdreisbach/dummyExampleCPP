#ifndef DETECTOR_H
#define DETECTOR_H

#include <string>
#include <vector>

#include <TRandom3.h>

class Hit;
class Track;

class Detector
{
	public:
		Detector(std::string name, double dimX, double dimY, double resX, double resY);
		~Detector();

		inline void addTrack(Track* track) { tracks.push_back( track); };
		inline void setRandom( TRandom3* rnd ) { random = rnd; }

		std::vector<Hit*> generateHits(Track* track);


	private:
		std::string name;
		TRandom3* random = new TRandom3();
		std::vector<Track*> tracks;
		double sizeX;
		double sizeY;
		double resolutionX;
		double resolutionY;
};

#endif
