/*! \file PhysicalObjectClass.cpp
 * PhysicalObjectClass.cpp 
 *
 * \brief The physical world containing RobotClass, TargetClass, and ObstacleClass objects
 * \author Rachel Soble
 *
 */

#include "PhysicalObjectClass.h"

#include <cstdlib>
#include <iostream>
using namespace std;

// Default constructor
PhysicalObjectClass::PhysicalObjectClass() {
}


//Constructor for testing purposes
//no error checking
PhysicalObjectClass::PhysicalObjectClass(double x, double y, int sizeIn, double speedIn) {

	location[0] = x;
	location[1] = y;
	size = sizeIn;
	speed = speedIn;
}

PhysicalObjectClass::PhysicalObjectClass(ObjectType objTypeIn, ShapeType objShapeIn, char colorIn, double x, double y, int sizeIn, double speedIn, int orientationIn, int idIn, int sbdIn){

	objType = objTypeIn;
	shape = objShapeIn;
	color = colorIn;
	size = sizeIn;
	location[0] = x;
	location[1] = y;
	speed = speedIn;
	orientation = orientationIn;
	id = idIn;
	shouldBeDrawn = sbdIn;

}

// Destructor
// Deallocates the memory reserved for the object
PhysicalObjectClass::~PhysicalObjectClass() {
//	cout << "Object is being deleted" << endl;
//	if (location) delete[] location;
}

// Set the color of the object
// Character 'R', 'G', or 'B' for now - no check
void PhysicalObjectClass::setColor(char colorIn) {
	color = colorIn;
}

// Set the size of the object
void PhysicalObjectClass::setSize(int sizeIn) {
//	int oldSize = size;
	size = sizeIn;
//	// Update sensesCollision
//	if (sensesCollision) {
//		size = oldSize;
//		cout << "Improper size: causes collision.\n" << endl;
//	}
}


// Set the double (x, y) location of the object
void PhysicalObjectClass::setLocation(double x, double y) {

}

// Set the double (x, y) location of the object outside of the GLUT window
void PhysicalObjectClass::setLocationOutside() {
	location[0] = -100;
	location[1] = -100;
}

// Set the speed of the object (pps, pixels per second)
// Speed cannot be negative, but it has no upper bound. It remains constant once set.
// In the future, the function will loop until the user gives valid input
void PhysicalObjectClass::setSpeed(double pps) {
	if (pps < 0) {
		cout << "Incorrect input: speed cannot be negative.\n" << endl;
	} else {
	speed = pps;
	}
}

// Set the orientation of the object
// 0 degrees = positive x-axis; increases counterclockwise
// If input negative value, turned into positive (degrees % 360 = degrees || 360-degrees)
// In the future, the function will loop until the user gives valid input
void PhysicalObjectClass::setOrientation(int degrees) {
	int mod = degrees;
	if (mod >= 360) {
		while (mod >= 360) {
			mod -= 360;
		}
	} else if (mod < 0) {
		while (mod < 0) {
			mod += 360;
		}
	} else {
		mod += 0;
	}
	orientation = mod;
}

// Set the ID of the object
void PhysicalObjectClass::setID(int idIn) {
	id = idIn;
}

// Set whether the object should be drawn
void PhysicalObjectClass::setShouldBeDrawn(int shouldDraw) {
	shouldBeDrawn = shouldDraw;
}

// Get the ObjectType of the object
ObjectType PhysicalObjectClass::getObjectType() {
	return objType;
}

// Get the ShapeType of the object
ShapeType PhysicalObjectClass::getShapeType() {
	return shape;
}

// Get the color of the object
char PhysicalObjectClass::getColor() {
	return color;
}

// Get the size of the object
int PhysicalObjectClass::getSize() {
	return size;
}

// Get the x position of the object
// Absolute or relative frame?
double PhysicalObjectClass::getXLocation() {
	if (location[0] < (size-1)) {
		location[0] = size-1;
		return location[0];
	}
	if (location[0] > (801-size)) {
		location[0] = 801-size;
		return location[0];
	}
    return location[0];
}

// Get the y position of the object
// Absolute or relative frame?
double PhysicalObjectClass::getYLocation() {
	if (location[1] < (size-1)) {
		location[1] = size-1;
		return location[1];
	}
	if (location[1] > (801-size)) {
		location[1] = 801-size;
		return location[1];
	}
    return location[1];
}

// Get the speed of the object
double PhysicalObjectClass::getSpeed() {
	return speed;
}

// Get the orientation of the object
int PhysicalObjectClass::getOrientation() {
    return orientation;
}

// Get the id of the object
int PhysicalObjectClass::getID() {
	return id; 
}

// Get whether the object should be drawn
int PhysicalObjectClass::getShouldBeDrawn() {
	return shouldBeDrawn;
}

// Get the index of the object in the env PhysicalObject vector
//int PhysicalObjectClass::getIndex() {
//	return index;
//}

//double PhysicalObjectClass::calcMovement(PhysicalObjectClass* object, double elapsedTime) {

//	double movementVector = new double[1];	

//	//get orientation and calculate magnitude of movement
//	if(object->getObjectType() == obstacle){
//		movementVector[0] = 0;
//		movementVector[1] = 0;
//	}
//	else{
//		//assuming Robot and Target inherit getOrientation
//		movementVector[0] = (double) object->getOrientation();
//		double magOfMove = elapsedTime * object->getSpeed();
//		movementVector[1] = magOfMove;
//	}

//	//return back vector containing both
//	return movementVector;

//}

