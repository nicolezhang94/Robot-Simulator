/*! \file ObstacleClass.cpp
 *
 * \author Nicholas Inman
 * \author Rachel Soble
 * \author Nicole Zhang
 *
 * \brief contains ObstacleClass class definitions
 *
 * 
 */

#include "ObstacleClass.h"
using namespace std;

// Default constructor
ObstacleClass::ObstacleClass() {
	objType = obstacle;
	shape = circle;
	size = 5;
	speed = 0;


	// In the future, once linking with GL/glui.h works, we will use the follwing:
//	location[0] = rand() % (getGlut(GLUT_WINDOW_WIDTH) - 2*size) + size;
//	location[1] = rand() % (getGlut(GLUT_WINDOW_WIDTH) - 2*size) + size;
	location[0] = -1;
	location[1] = -1;
	while (location[0] == -1) {
		double rand_X = (double) ((rand() % (800 - 2*size)) + size);
		double rand_Y = (double) ((rand() % (800 - 2*size)) + size);
		setInitLocation(rand_X, rand_Y);
	}

	// Obstacle color always blue
	color = 'B';
	shouldBeDrawn = 1;
	id = -1;
}

ObstacleClass::ObstacleClass(ShapeType shapeIn, int sizeIn) {
	objType = obstacle;
	shape = shapeIn;
	size = sizeIn;

	location[0] = -1;
	location[1] = -1;
	while (location[0] == -1) {
		double rand_X = (double) ((rand() % (800 - 2*size)) + size);
		double rand_Y = (double) ((rand() % (800 - 2*size)) + size);
		setInitLocation(rand_X, rand_Y);
	}
	color = 'B';
	shouldBeDrawn = 1;
	id = -1;
}

ObstacleClass::ObstacleClass(ShapeType shapeIn, int sizeIn, double x, double y) {
	objType = obstacle;
	shape = shapeIn;
    size = sizeIn;

	location[0] = -1;
	location[1] = -1;
	while (location[0] == -1) {
		setInitLocation(x, y);
	}
	
	color = 'B';
	shouldBeDrawn = 1;
	id = -1;
}


// Set the initial position of the obstacle
void ObstacleClass::setInitLocation(double x, double y) {
	double old_X = getXLocation();
	double old_Y = getYLocation();
	setLocation(x, y);
	if (environment.touchSensorReading(this) != -1) {
		setLocation(old_X, old_Y);
	}	
}

// Set the position of the obstacle
void ObstacleClass::setLocation(double x, double y) {
	location[0] = x;
	location[1] = y;
}
