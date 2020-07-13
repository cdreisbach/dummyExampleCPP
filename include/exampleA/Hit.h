#ifndef HIT_H
#define HIT_H

#include <string>

class Detector;
class Track;

class Hit
{
	public:
		Hit(double posX, double posY, Detector* det, Track* tr);
		~Hit();

		inline double getX()     { return positionX; }
		inline double getY()     { return positionY; }
		inline Track* getTrack() { return track;     }

	private:
		double positionX;
		double positionY;

		Detector* detector;

		Track* track;
};

#endif