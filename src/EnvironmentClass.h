/*
 * Environment Class header
 */

class PhysicalObjectClass;
class RobotClass;
class RenderingWindowClass;

#ifndef ENVIRONMENTCLASS_H
#define ENVIRONMENTCLASS_H

#include "RobotClass.h"
#include "ObstacleClass.h"
#include <time.h>
#include <math.h>
#include <vector>

#ifndef __FLAG
#define __FLAG
extern int flag;
#endif

class EnvironmentClass {

	public:
		//! default constructor for EnvironmentClass
		EnvironmentClass();

		//! updates each object by calling move, then setting position
		/*! This function takes an one argument, elapsedTime, and iterates through
		 *    the physicalObjects array, calling move each time. Move then returns
		 *    an double[2] array containing the direction and magnitude of movement.
		 *    Based on which coordinate the object currently is in, it sets the object's
		 *    new position.
		 *
		 * \param elapsedTime the amount of time passed
		 */
		void update(double elapsedTime);

		//! Collision detection
		/*! This function takes in an object and checks if that object is colliding with 
		 *    another object or a wall. It returns -1 if the object is not colliding with
		 *    anything, -2 if it is colliding with a wall, or the index of the object it is
		 *    colliding with.
		 *
		 * \param object whichever object is requesting touch sensor information
		 * \return -1 if the object is not colliding with anything
		 *    -2 if the object is colliding with a wall
		 *    index of the object the input object is colliding with
		 */
		int touchSensorReading(PhysicalObjectClass* object);

		//! Determines robot to target orientation
		/*! This function takes in a robot-target pair and calculates the orientation that
		 *    points to the target, and then it sets the robot's orientation to that.
		 *
		 * \param robot the robot that is trying to home in on target
		 * \param target the target that is being homed in on by robot
		 */
		void homingSensorReading(RobotClass* robot, TargetClass* target);

		//! Determines robot's corresponding target
		/*! This function takes in a robot type object, finds its corresponding target, and
		 *    calls homingSensorReading with these two objects. This essentially makes sure
		 *    that the robot will be homing in on its own target and not different one.
		 *
		 * \param object whichever robot is requesting homing sensor info
		 */
		void resetHoming(PhysicalObjectClass* object);

		//! Draw and displays objects and environment
		/*! This function is constantly called from simulation. It displays and draws all the objects
		 *    and calls the update function and effectively sets up the environment.
		 */
		void display();
		
		//! Moves the input object
		/*! This function resets the location of the input object based on its speed, original
		 *    location, orientation, and elapsed time.
		 *
		 * \param object the object being translating
		 * \param elapsedTime the amount of time passed
		 */
		void translate(PhysicalObjectClass* object, double elapsedTime);

		//! Performs wall collision movement
		/*! This function determines which wall the object is colliding with and which direction
		 *    it is coming from, and then subsequently changes its orientation to be 90 degrees
		 *    away from the wall and translated inwards one pixel to remain in the window.
		 *
		 * \param object the object that is bouncing off the wall
		 */
		void bounceOffWall(PhysicalObjectClass* object);

		//! Object collision management
		/*! This function determines what type of object the currentObject is colliding into
		 *    and then subsequently determines its corresponding behavior.
		 *
		 * \param currentObject the object making the collision
		 * \param hitObject the object being collided into
		 * \param elapsedTime the amount of time passed
		 */
		void objectCollision(PhysicalObjectClass* currentObject, PhysicalObjectClass* hitObject, double elapsedTime);

		//! Performs object collision movement
		/*! This function sets the new orientations of the objects that are colliding
		 *    to be 90 degrees away from each other.
		 *
		 * \param currentObject the object making the collision
		 * \param hitObject the object being collided into
		 */
		void bounceOffObject(PhysicalObjectClass* currentObject, PhysicalObjectClass* hitObject);

		//! Removes the object from the simulation
		/*! This function "removes" the input object from the simulation by setting the
		 *    shouldBeDrawn attribute to 0 and moving the object off screen.
		 *
		 * \param object the object that needs removing
		 */
		void removeObject(PhysicalObjectClass* object);

		std::vector<PhysicalObjectClass*> physicalObjectVector;
		RenderingWindowClass *renderEnv;
		
	private:
		int size[2];
		PhysicalObjectClass* obj;
		RobotClass* bot;
		TargetClass* tar;
		
};

#endif
