/*! \file RenderingWindowClass.cpp
 * RenderingWindowClass.cpp 
 *
 * \brief Interface between the graphics and EnvironmentClass
 *
 */

#include "RenderingWindowClass.h"
#include "RobotClass.h"

#include <cstdlib>
#include <iostream>
using namespace std;

#define PI 3.14f

// Default constructor
RenderingWindowClass::RenderingWindowClass() {

}

// Destructor
// Deallocates the memory reserved for the object
RenderingWindowClass::~RenderingWindowClass() {
//	cout << "Object is being deleted" << endl;
}

// Determines glColor3f parameters based on the object's color attribute
int* RenderingWindowClass::setGraphicsColor(PhysicalObjectClass* object) {
	int* colorArray = new int[3];
	switch (object->getColor()) {
		case 'R':			// Red
			colorArray[0] = 1;
			colorArray[1] = 0;
			colorArray[2] = 0;
			break;
		case 'Y':			// Yellow
			colorArray[0] = 1;
			colorArray[1] = 1;
			colorArray[2] = 0;
			break;
		case 'M':			// Magenta
			colorArray[0] = 1;
			colorArray[1] = 0;
			colorArray[2] = 1;
			break;
		case 'G':			// Green
			colorArray[0] = 0;
			colorArray[1] = 1;
			colorArray[2] = 0;
			break;
		case 'C':			// Cyan
			colorArray[0] = 0;
			colorArray[1] = 1;
			colorArray[2] = 1;
			break;
		case 'B':			// Blue
			colorArray[0] = 0;
			colorArray[1] = 0;
			colorArray[2] = 1;
			break;
		case 'W':			// White
			colorArray[0] = 1;
			colorArray[1] = 1;
			colorArray[2] = 1;
			break;
	}
	return colorArray;
}

// Decides how to draw a PhysicalObjectClass object based on its ObjectType attribute
void RenderingWindowClass::drawObject(PhysicalObjectClass* object) {
	if (object->getShouldBeDrawn() == 1) {
		ObjectType objType = object->getObjectType();
		if (objType == robot) {
			drawRobot((RobotClass*)object);
		}
		else if (objType == target) {
			drawTarget((TargetClass*)object);
		}
		else if (objType == obstacle) {
			drawObstacle((ObstacleClass*)object);
		}
		else {
			cout << "Invalid object type. Object not drawn." << endl;
		}
	} 
//	else {
//		cout << "Object should not be drawn." << endl;
//	}
}

// Draws objects as circles
void RenderingWindowClass::drawCircle(double object_X, double object_Y, double object_size, PhysicalObjectClass* object)
{  
    glBegin(GL_TRIANGLE_FAN);
	int* colorArray = setGraphicsColor(object);
	glColor3f(colorArray[0], colorArray[1], colorArray[2]);
    glVertex2f(object_X, object_Y);
    for (int i = 0; i <= 50; i++) {
		glVertex2f(((object_size * cos(i*2*PI/50)) + object_X),
			((object_size * sin(i*2*PI/50)) + object_Y));
    }
    glEnd();
}

// Calculates the endpoint of the orientation line emerging from the robot
double* RenderingWindowClass::calcLineCoord(double robot_X, double robot_Y, double robot_size, double robot_orient) {
    double line_X = ((robot_size+20)*cos(robot_orient*PI/180)) + robot_X;
    double line_Y = ((robot_size+20)*sin(robot_orient*PI/180)) + robot_Y;

    double* lineCoord = new double[2];
    lineCoord[0] = line_X;
	lineCoord[1] = line_Y;
    return lineCoord;
}

// Draws RobotClass robot as a circle, including an orientation line
void RenderingWindowClass::drawRobot(RobotClass* robot)
{
    double robot_X = (double) robot->getXLocation();
    double robot_Y = (double) robot->getYLocation();
    double robot_size = (double) robot->getSize();
    double robot_orient = (double) robot->getOrientation();

	drawCircle(robot_X, robot_Y, robot_size, robot);

    PhysicalObjectClass* target = robot->getTarget(); 
    glBegin(GL_LINES);
	int* colorArray = setGraphicsColor(target);
	glColor3f(colorArray[0], colorArray[1], colorArray[2]);
    glVertex2f(robot_X, robot_Y);
    double *lineCoord = calcLineCoord(robot_X, robot_Y, robot_size, robot_orient);
    glVertex2f(lineCoord[0], lineCoord[1]);
    glEnd();
}

// Draws TargetClass targets as circles
void RenderingWindowClass::drawTarget(TargetClass* target)
{
    // Get obstacle specs
    double target_X = (double) target->getXLocation();
    double target_Y = (double) target->getYLocation();
    double target_size = (double) target->getSize();
    
    // Draw obstacle as a circle
	drawCircle(target_X, target_Y, target_size, target);
}

// Draws ObstacleClass obstacles as circles
void RenderingWindowClass::drawObstacle(ObstacleClass* obstacle)
{
    // Get obstacle specs
    double obstacle_X = (double) obstacle->getXLocation();
    double obstacle_Y = (double) obstacle->getYLocation();
    double obstacle_size = (double) obstacle->getSize();

    // Draw obstacle as a circle
	drawCircle(obstacle_X, obstacle_Y, obstacle_size, obstacle);
}


