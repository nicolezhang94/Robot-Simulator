/*! \file EnvironmentClass.cpp
 * 
 * \brief Manages and controls object movement and behavior
 *
 * \author Nicole Zhang
 * \author Rachel Soble
 * \author Nicholas Inman
 *
 */

#include "EnvironmentClass.h"
#include "RenderingWindowClass.h"


#include <cstdlib>
using namespace std;

EnvironmentClass::EnvironmentClass() {
	// Current fixed size of window
	size[0] = 800;
	size[1] = 800;

//	size[0] = glutGet(GLUT_WINDOW_WIDTH);
//	size[1] = glutGet(GLUT_WINDOW_HEIGHT);
}

void EnvironmentClass::update(double elapsedTime) {
	if(flag){
	    return;
	}
	
	int numOfObjects = physicalObjectVector.size();

	glutGet(GLUT_ELAPSED_TIME);

	//need to call the calcMoveVector() function for each object in physicalObjects array
	for(int i = 0; i < numOfObjects; i++) {
		
		PhysicalObjectClass* currentObject = physicalObjectVector.at(i);
		ObjectType currentType = currentObject->getObjectType();
		translate(currentObject, elapsedTime);
		int TSR = touchSensorReading(currentObject);
		
		if (TSR == -1) {
			// Object not colliding after new move
			// If current object is a robot, re-orient it towards its target
			if (currentType == robot) {
				resetHoming(currentObject);			
			}
		} else if (TSR == -2) {
			// Object colided with a wall upon the move and bounces off
			bounceOffWall(currentObject);
		} else {
			// Object colided with another object upon the move; bounce behavior determined within
			PhysicalObjectClass* hitObject = physicalObjectVector.at(TSR);
			objectCollision(currentObject, hitObject, elapsedTime);
		}
	}
}


int EnvironmentClass::touchSensorReading(PhysicalObjectClass* object) {

	int obj_size = object->getSize();
	double obj_X = object->getXLocation();
	double obj_Y = object->getYLocation();

	int numOfObjects = physicalObjectVector.size();

	for (int i = 0; i < numOfObjects; i++) {
		int current_size = physicalObjectVector.at(i)->getSize();
		double current_X = physicalObjectVector.at(i)->getXLocation();
		double current_Y = physicalObjectVector.at(i)->getYLocation();
		double distance = sqrt(pow((obj_X - current_X), 2.0) + pow((obj_Y - current_Y), 2.0));
		// Includes a 5-pixel buffer. Also makes sure it doesn't check collision with itself
		if ((distance <= (obj_size + current_size + 5)) && (physicalObjectVector.at(i)->getID() != object->getID())) {
			return i;
		}
	}

	// Checks if obj runs into a wall
	if (((obj_X + obj_size) > 800) || (obj_X < obj_size) || ((obj_Y + obj_size) > 800) || (obj_Y < obj_size)) {
		return -2;
	}

	return -1;
}

void EnvironmentClass::homingSensorReading(RobotClass* robot, TargetClass* target) {
	vector<double> homingData;

	double bot_X = robot->getXLocation();
	double bot_Y = robot->getYLocation();

	double target_X = target->getXLocation();
	double target_Y = target->getYLocation();

	double opposite = 0;
	double adjacent = 0;
	double degrees = 0;

	if ((target_Y >= bot_Y) && (target_X >= bot_X)) {
		//quadrant I
		opposite = target_Y - bot_Y;
		adjacent = target_X - bot_X;
		degrees = (180/M_PI) * atan(opposite/adjacent);
	} else if ((target_Y >= bot_Y) && (target_X <= bot_X)) {
		//quadrant II
		//adjust x to be positive, then subtract result from 180
		opposite = target_Y - bot_Y;
		adjacent = bot_X - target_X;
		degrees = 180 - (180/M_PI) * (atan(opposite/adjacent));
	} else if ((target_Y <= bot_Y) && (target_X <= bot_X)) {
		//quadrant III
		adjacent = bot_X - target_X;
		opposite = bot_Y - target_Y;
		degrees = 180 + (180/M_PI)*(atan(opposite/adjacent));
	} else if ((target_Y <= bot_Y) && (target_X >= bot_X)) {	
		// if target is in quadrant IV
		opposite = bot_Y - target_Y;
		adjacent = target_X - bot_X;
		degrees = 360 - (180/M_PI)*(atan(opposite/adjacent));
	}
	
	robot->setOrientation(degrees);

}

void EnvironmentClass::resetHoming(PhysicalObjectClass* object) {
	RobotClass* currentRobot = (RobotClass*) object;
	TargetClass* currentTarget = (TargetClass*) physicalObjectVector.at(currentRobot->getID()-2); 
//	TargetClass* currentTarget = (TargetClass*) currentRobot.getTarget(); // in the future, use getTarget() method rather than hardcoding
	homingSensorReading(currentRobot, currentTarget);
}

void EnvironmentClass::display() {
	update(1.0);
	for (int i = 0; i < (int) physicalObjectVector.size(); i++) {
		renderEnv->drawObject(physicalObjectVector.at(i));
	}
}

void EnvironmentClass::translate(PhysicalObjectClass* object, double elapsedTime) {
	double oldOrient = object->getOrientation();
	double old_X = object->getXLocation();
	double old_Y = object->getYLocation();
	
	double moveMagnitude = elapsedTime * object->getSpeed();
	double move_X = cos(oldOrient * (M_PI/180)) * moveMagnitude;
	double move_Y = sin(oldOrient * (M_PI/180)) * moveMagnitude;
	
	double new_X = old_X + move_X;
	double new_Y = old_Y + move_Y;

	object->setLocation(new_X, new_Y);
}

void EnvironmentClass::bounceOffWall(PhysicalObjectClass* object) {

	int size = object->getSize();

	int originalOrientation = object->getOrientation();
	double originalXLocation = object->getXLocation();
	double originalYLocation = object->getYLocation();

	int newOrientation = originalOrientation;
	double newXLocation = originalXLocation;
	double newYLocation = originalYLocation;
	
	if (originalXLocation >= 800 - size) {	// Bounce off right wall
		if (originalOrientation <= 180) {
			newOrientation += 90;
			newXLocation = 800 - size;
		} else if (originalOrientation > 180) {
			newOrientation -= 90;
			newXLocation = 800 - size;
		}
	} else if (originalXLocation <= size) {	// Bounce off left wall
		if (originalOrientation <= 180) {
			newOrientation -= 90;
			newXLocation = size;
		} else if (originalOrientation > 180) {
			newOrientation += 90;
			newXLocation = size;
		}
	} else if (originalYLocation >= 800 - size) {	// Bounce off top wall
		if (originalOrientation <= 90) {
			newOrientation -= 90;
			newYLocation = 800 - size;
		} else if (originalOrientation > 90) {
			newOrientation += 90;
			newYLocation = 800 - size;
		}
	} else if (originalYLocation <= size) {	// Bounce off bottom wall
		if (originalOrientation <= 270) {
			newOrientation -= 90;
			newYLocation = size;
		} else if (originalOrientation > 270) {
			newOrientation += 90;
			newYLocation = size;
		}
	}
	
	object->setOrientation(newOrientation);
	object->setLocation(newXLocation, newYLocation);
}

void EnvironmentClass::objectCollision(PhysicalObjectClass* currentObject, PhysicalObjectClass* hitObject, double elapsedTime) {
	ObjectType currentType = currentObject->getObjectType();
	ObjectType hitType = hitObject->getObjectType();
	if ((currentType == robot) && (hitType == target)) {
		RobotClass* currentRobot = (RobotClass*) currentObject;
		int robotTargetPair = currentRobot->getTargetPair();
		int targetSignal = hitObject->getID();
		if (robotTargetPair == targetSignal) {
			removeObject(currentObject);
			removeObject(hitObject);
		} else {
			bounceOffObject(currentObject, hitObject);
			translate(currentObject, elapsedTime);
			resetHoming(currentObject);
		}
	} else if ((currentType == target) && (hitType == robot)) {
		RobotClass* hitRobot = (RobotClass*) hitObject;
		int robotTargetPair = hitRobot->getTargetPair();
		int targetSignal = currentObject->getID();
		if (robotTargetPair == targetSignal) {
			removeObject(currentObject);
			removeObject(hitObject);
		} else {
			bounceOffObject(currentObject, hitObject);
		}
	} else {
		bounceOffObject(currentObject, hitObject);
		if (currentType == robot) {
			if (hitType == obstacle) {
				char originalColor = currentObject->getColor();
				currentObject->setColor('R');
				translate(currentObject, elapsedTime);
				resetHoming(currentObject);
				currentObject->setColor(originalColor);
			}
			if (hitType == robot) {			
				translate(hitObject, elapsedTime);
				resetHoming(hitObject);
			}
		}
	}
}

void EnvironmentClass::bounceOffObject(PhysicalObjectClass* currentObject, PhysicalObjectClass* hitObject) {
	int scale[2] = {-1, 1};
	int randIndex = rand() % 2;
	int degreeShift = 91 * scale[randIndex];
	
	int currentOldOrient = currentObject->getOrientation();
	int currentNewOrient = currentOldOrient + degreeShift;
	currentObject->setOrientation(currentNewOrient);
	
	int hitOldOrient = hitObject->getOrientation();
	int hitNewOrient = hitOldOrient + degreeShift;
	hitObject->setOrientation(hitNewOrient);
}

void EnvironmentClass::removeObject(PhysicalObjectClass* object) {
	object->setShouldBeDrawn(0);
	object->setLocationOutside();
}






			

