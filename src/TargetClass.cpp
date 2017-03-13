/*! \file TargetClass.cpp
 *
 * \brief contains Target class definitions
 *
 */

#include "TargetClass.h"
using namespace std;

TargetClass::TargetClass() {
	objType = target;
	shape = circle;
	size = 15;
	speed = 9;
	orientation = rand() % 360;
	
	// Coordinates of center of circle
	// Randomly set so that target still fits entirely within window; initialized random seed in main
	// Window size defined in main.cpp: 800 x 800
	// In the future, once linking with GL/glui.h works, we will use the follwing:
//	location[0] = rand() % (getGlut(GLUT_WINDOW_WIDTH) - 2*size) + size;
//	location[1] = rand() % (getGlut(GLUT_WINDOW_WIDTH) - 2*size) + size;
//	location[0] = -1;
//	location[1] = -1;
//	do {
		double rand_X = (double) ((rand() % (800 - 2*size)) + size);
		double rand_Y = (double) ((rand() % (800 - 2*size)) + size);
		setLocation(rand_X, rand_Y);
//	} while (location[0] == -1);

	color = 'Y';
	shouldBeDrawn = 1;
	id = -1;
}

TargetClass::TargetClass(char colorIn) {
	objType = target;
	shape = circle;
	size = 15;
	speed = 9;
	orientation = rand() % 360;
	// Coordinates of center of circle
	// Randomly set so that target still fits entirely within window; initialized random seed in main
	// Window size defined in main.cpp: 800 x 800
	// In the future, once linking with GL/glui.h works, we will use the follwing:
//	location[0] = rand() % (getGlut(GLUT_WINDOW_WIDTH) - 2*size) + size;
//	location[1] = rand() % (getGlut(GLUT_WINDOW_WIDTH) - 2*size) + size;
//	location[0] = -1;
//	location[1] = -1;
//	do {
		double rand_X = (double) ((rand() % (800 - 2*size)) + size);
		double rand_Y = (double) ((rand() % (800 - 2*size)) + size);
		setLocation(rand_X, rand_Y);
//	} while (location[0] == -1);

	color = colorIn;
	shouldBeDrawn = 1;
	id = -1;
}

void TargetClass::setLocation(double x, double y) {
	if ((x < size) || ((x + size) > 800) || (y < size) || ((y + size) > 800)) {
//		cout << "Incorrect input: off screen.\n" << endl;
	}
	
//	double old_X = location[0];
//	double old_Y = location[1];
	location[0] = x;
	location[1] = y;

//	if (environment.touchSensorReading(this) != -1) {
//		cout << "Target collides with object. Location not updated.\n" << endl;
//		location[0] = old_X;
//		location[1] = old_Y;
//	}	
}

// replaced by ID
//void TargetClass::setSignal(int robot) {
//	signal = robot;
//}

// replaced by ID
//int TargetClass::getSignal() {
//	return signal;
//}
