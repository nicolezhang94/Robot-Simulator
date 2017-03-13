/*! \file RenderingWindowClass.h
 * RenderingWindowClass.h
 *
 * \brief Interface between the graphics and EnvironmentClass
 *
 */

class PhysicalObjectClass;

#ifndef RENDERINGWINDOWCLASS_H
#define RENDERINGWINDOWCLASS_H

//#include <GL/glut.h>
//#include <GL/glu.h>
#include <GL/glui.h>

//#include "PhysicalObjectClass.h"
//#include "Simulation.h"
#include "RobotClass.h"
#include "TargetClass.h"
#include "ObstacleClass.h"

//extern EnvironmentClass* environment;

class RenderingWindowClass {

public:

    //! Default constructor for RenderingWindowClass
    /*! This constructor takes in no arguments.   
     */
    RenderingWindowClass();

    //! Default destructor for RenderingWindowClass
    ~RenderingWindowClass();
    
    //!
    // Location renderObject(ObjectType, location, motionVector);
    
    //! Populates an array of obstacles/targets to be drawn in the simulation
	/*! initObject takes in one ObstacleClass type object (an obstacle or a target) as an argument
	 *    and adds its properties (shape, size, location) to the obstacleArray.
	 *    Simulation.cpp accesses these properties through the obstacleArray when displaying
	 *    the objects in the GLUT window. At the beginning of the simulation, the variable int 
	 *    numOfObjects is set to 0. After an object is added to the obstacleArray, this counter 
	 *    is incremented so that the next object will be added to the next slot in the array.
	 *
	 * \param object a robot/target/obstacle added to the environment's physicalObjectVector
	 */
//	void initObject(PhysicalObjectClass* object);
	
	//! Determines how to render the color a PhysicalObjectClass object
	/*! setGraphicsColor takes in a PhysicalObjectClass object as an argument and decides based on
	 *    the object's color attribute which parameters to pass to GLUT's glColor3f function, which
	 *    is called in the drawCircle  method (and any future methods for drawing different shapes).
	 *
	 * \param object a PhysicalObjectClass object within the simulation
	 */
	int* setGraphicsColor(PhysicalObjectClass* object);
	
	//! Determines how to draw a PhysicalObjectClass object
	/*! drawObject takes in a PhysicalObjectClass object as an argument and decides based on
	 *    the object's ObjectType attribute (robot, target, or obstacle) whether to draw the object
	 *    as a robot, target, or obstacle, respectively. If an invalid ObjectType is detected, 
	 *	  the object is not drawn.
	 *
	 * \param object a PhysicalObjectClass object within the simulation
	 */
	void drawObject(PhysicalObjectClass* object);
	
	//! Calculates the outside coordinate of the robot's orientation line
	/*! calcLineCoord takes in the robot's location (robot_X, robot_Y), size, and orientation
	 *    as arguments. The robot's orientation line is anchored to its center at the coordinate
	 *    (robot_X, robot_Y). This method calculates the coordinate of the other end of the line,
	 *    emerging from the robot (by 20 pixels), based on the robot's orientation. It returns the
	 *    pointer to an array containing these coordinates so that they can be passed to drawRobot.
	 *
	 * \param robot_X double x-coordinate of the robot (in pixels)
	 * \param robot_Y double y-coordinate of the robot (in pixels)
	 * \param size double size of the robot (in pixels)
	 * \param orient double orientation of the robot (in degrees; 0 as the positive x-axis)
	 * \return calcLineCoord pointer to double array containing end coordinates of orientation line
	 *
	 */
	double* calcLineCoord(double robot_X, double robot_Y, double size, double orient);

	//! Draws the robot with its orientation line
	/*! drawRobot takes in a RobotClass robot object as an argument. It draws the main body
	 *    of the robot as a circle of radius "size" using 50 triangle fans. Then it draws a line anchored at
	 *    the center of the robot and emerging from its body in the direction of its orientation.
	 *    The default robot body color is green, and the default orientation line color is red.
	 *
	 * \param robot a robot within the simulation
	 */
	void drawRobot(RobotClass* robot);
	
	//! Draws a TargetClass target 
	/*! drawTarget takes in a TargetClass target object as an argument. 
	 *    For Iteration 2, it draws the target as a circle of radius "size" using 50 triangle fans.
	 * 	  The color of the target is determined by the object's color attribute.
	 *
	 * \param target a target within the simulation
	 */
	void drawTarget(TargetClass* target);
	
	//! Draws an ObstacleClass obstacle 
	/*! drawObstacle takes in an ObstacleClass obstacle object as an argument. 
	 *    For Iteration 2, it draws the obstacle as a circle of radius "size" using 50 triangle fans.
	 * 	  The color of the obstacle is determined by the object's color attribute.
	 *
	 * \param obstacle an obstacle within the simulation
	 */
	void drawObstacle(ObstacleClass* obstacle);
			
	//! Draws a circular object
	/*! drawCircle takes in a PhysicalObjectClass object as an argument and draws it as a circle
	 *    of radius "size" using 50 triangle fans. The color of the obstacle is determined 
	 *    by the object's color attribute.
	 *
	 * \param obstacle an obstacle within the simulation
	 */
	void drawCircle(double object_X, double object_Y, double object_size, PhysicalObjectClass* object);
    
};

#endif
