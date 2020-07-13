#include "Hit.h"

#include "Track.h"
#include "Detector.h"

Hit::Hit(double posX, double posY, Detector* det, Track* tr)
	: positionX(posX),
	  positionY(posY),
	  detector(det),
	  track(tr)
{}

Hit::~Hit() { }
