/*! \file main.cpp
 * 
 * \brief driver file for robot class
 *
 * Creates objects and runs simulation loop
 *
 * \author Nicholas Inman
 * \author Rachel Soble
 * \author Nicole Zhang
 *
 */

#include "Simulation.h"
#include "EnvironmentClass.h"

int flag = 1;
double pastTime = 0;

using namespace std;

EnvironmentClass environment;

int main(int argc, char* argv[])
{

	// Create all physical objects
	// Is location determined here? i.e. if an object is initalized with a location that induces a collision, is the object location randomly reset until there are no collisions?

    srand(time(0));
    
    //create first target
    TargetClass* target1 = new TargetClass('Y');

    //set target ID (signal) to one
    target1->setID(0);

	environment.physicalObjectVector.push_back(target1);

    //create second target
    TargetClass* target2 = new TargetClass('M');

    //set target ID (signal) to two
	target2->setID(1);
	
	environment.physicalObjectVector.push_back(target2);
    
    //create a robot
    RobotClass* robot1 = new RobotClass();

    
//set targetPair to target.id
    robot1->setID(2);
    robot1->setTargetPair(0);
    environment.homingSensorReading(robot1, target1);
    
	environment.physicalObjectVector.push_back(robot1);

    //create second robot
    RobotClass* robot2 = new RobotClass();

    //set targetPair to target.id
    robot2->setID(3);
    robot2->setTargetPair(1);
    environment.homingSensorReading(robot2, target2);
    
	environment.physicalObjectVector.push_back(robot2);
	
	//create all of the obstacles
    int numObstacles = 6;
    for (int i = 0; i < numObstacles; i++)
    {
        ObstacleClass* objectx = new ObstacleClass(circle, 20);
        objectx->setID(i+4);
		environment.physicalObjectVector.push_back(objectx);
		cout << endl;
    }

    Simulation *app = new Simulation(argc, argv,800,800);
    app->runMainLoop();
	exit(0);
}


