/*! \file RobotClass.cpp
 * RobotClass.cpp 
 * \author Rachel Soble
 * \author Nicholas Inman
 * \brief contains Drawing class definitions
 *
 */

#include "RobotClass.h"
using namespace std;

// Default constructor
RobotClass::RobotClass() {

	// ObjectType robot
	objType = robot;

	// Size of robot: radius of circle
	size = 50;
	// Coordinates of center of circle
	// Randomly set so that robot still fits entirely within window; initialized random seed in main
	// Window size defined in main.cpp: 800 x 800
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
	// Robot body color always green
	color = 'G';
	// Orientation of robot randomly set
	// 0 degrees = positive x-axis; increases counterclockwise; no negative values allowed
	orientation = rand() % 360;
	// Speed of robot; arbitrarily set here
	speed = 10;
	shouldBeDrawn = 1;
	id = -1;
}

// Constructor, user defines size and location
// In the future, once linking with GL/glui.h works, we will use glutGet(GLUT_WINDOW_WIDTH) and glutGet(GLUT_WINDOW_HEIGHT) instead of hardcoding window dimensions
// In the future, the function will loop until the user gives valid input
RobotClass::RobotClass(int sizeIn, double x, double y) {
	objType = robot;
	size = sizeIn;
	location[0] = -1;
	location[1] = -1;
	while (location[0] == -1) {
		setInitLocation(x, y);
	}

	color = 'G';
	orientation = rand() % 360;
	speed = 10;
	shouldBeDrawn = 1;
	id = -1;
}

// Destructor
// Deallocates the memory reserved for the robot
RobotClass::~RobotClass() {
/*	cout << "Robot is being deleted" << endl;
//	if (location) delete[] location;*/
}

// Set the initial position of the robot
void RobotClass::setInitLocation(double x, double y) {
	double old_X = getXLocation();
	double old_Y = getYLocation();
	setLocation(x, y);
	if (environment.touchSensorReading(this) != -1) {
		setLocation(old_X, old_Y);
	}	
}

// Set the position of the robot
void RobotClass::setLocation(double x, double y) {
	location[0] = x;
	location[1] = y;
}


// set the integer representation of target to a robot
void RobotClass::setTargetPair(int target){
    targetPair = target;
}

// Get the paired target's signal
int RobotClass::getTargetPair() {
    return targetPair;
}

PhysicalObjectClass* RobotClass::getTarget() {
	int targetID = targetPair;
	for (int i = 0; i < (int) environment.physicalObjectVector.size(); i++) {
		if (environment.physicalObjectVector.at(i)->getObjectType() == target) {
			TargetClass* target = (TargetClass*) environment.physicalObjectVector.at(i);
			if (target->getID() == targetID) {
				return (PhysicalObjectClass*) target;
			}
		}
	}
	PhysicalObjectClass* object = NULL;
	return object;
}


// Empty methods for future functionality

// Rotate the robot by a specified number of degrees
// Default: counterclockwise; could specify direction with additional argument
void RobotClass::rotate(int degrees) {
}

// Translate robot forward by specified number of pixels
// Forward direction determined by .orientation
void RobotClass::translate(int pixels) {
}

// Update robot position based on time between frames and .speed
void RobotClass::updatePosition() {
}

// Orient robot towards target
void RobotClass::pointTo() {
// Determine target center
// Determine vector direction between target center and robot center
// Set robot orientation towards target center
}
