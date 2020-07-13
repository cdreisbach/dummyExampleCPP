#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <cmath>

class Track
{
	public:
		Track(double x = 0, double y = 0, double e = 0);
		~Track();

		inline double getPosX()   { return positionX; };
		inline double getPosY()   { return positionY; };
		inline double getEnergy() { return energy; };

		inline void setPositionX( double posX ) { positionX = posX; };
		inline void setPositionY( double posY ) { positionY = posY; };
		inline void setEnergy   ( double e    ) { energy    = e;    };

		// overloaded method
		void setEnergy( double mass, double momentum);

	private:
		double positionX;
		double positionY;
		double energy;
};

#endif