#include <cxxtest/TestSuite.h>
#include "RobotClass.h"
#include "ObstacleClass.h"

using namespace std;

class RobotClassTests : public CxxTest::TestSuite 
{
public:

//Values passed in are assured to be valid
void Test_setInitLocation(void){

	//create RobotClass object
	RobotClass* robot = new RobotClass();

	//set Location
	robot->setInitLocation(100, 444);

	//get location
	int x_loc = robot->getXLocation();
	int y_loc = robot->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 100);
	TS_ASSERT_EQUALS(y_loc, 444);
}

void Test_setInitLocation_with_objects(void){

	//create obstacles
	ObstacleClass* obj1 = new ObstacleClass(circle, 40, 200, 200);

	//add to environment
	environment.physicalObjectVector.push_back(obj1);

	//create RobotClass object
	RobotClass* robot = new RobotClass();
	int old_x = robot->getXLocation();
	int old_y = robot->getYLocation();

	//set Location
	robot->setInitLocation(178, 200);

	//get location
	TS_ASSERT_EQUALS(old_x, robot->getXLocation());
	TS_ASSERT_EQUALS(old_y, robot->getYLocation());
}

void Test_setLocation(void){

	//create RobotClass object
	RobotClass* robot = new RobotClass();

	//set Location
	robot->setLocation(100, 444);

	//get location
	int x_loc = robot->getXLocation();
	int y_loc = robot->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 100);
	TS_ASSERT_EQUALS(y_loc, 444);

}

void Test_setLocation_with_objects(void){

	//create obstacles
	ObstacleClass* obj1 = new ObstacleClass(circle, 40, 200, 200);

	//add to environment
	environment.physicalObjectVector.push_back(obj1);

	//create RobotClass object
	RobotClass* robot = new RobotClass();
	int old_x = robot->getXLocation();
	int old_y = robot->getYLocation();

	//set Location
	robot->setLocation(178, 200);

	//get location
	TS_ASSERT_EQUALS(old_x, robot->getXLocation());
	TS_ASSERT_EQUALS(old_y, robot->getYLocation());
}

//out of bounds
void Test_setLocation_invalid_X(void){

	//create RobotClass object
	RobotClass* robot = new RobotClass();
	robot->setSize(20);

	//set Location
	robot->setLocation(976, 100);

	//get location
	int x_loc = robot->getXLocation();
	int y_loc = robot->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 781);
	TS_ASSERT_EQUALS(y_loc, 100);
}

//out of bounds
void Test_setLocation_invalid_Y(void){

	//create RobotClass object
	RobotClass* robot = new RobotClass();
	robot->setSize(30);

	//set Location
	robot->setLocation(200, 999);

	//get location
	int x_loc = robot->getXLocation();
	int y_loc = robot->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 200);
	TS_ASSERT_EQUALS(y_loc, 771);
}

//can't test setTargetPair without getTargetPair, this tests both at once essentially
//assumes target functions work
void Test_getTargetPair(void){/*
	//create target
	TargetClass* target = new TargetClass();
	target->setID(0);

	//add to environment
	environment.physicalObjectVector.push_back(target);

	//create RobotClass object
	RobotClass* robot = new RobotClass();
	robot->setTargetPair(0);
	environment.physicalObjectVector.push_back(robot);

	//get id, and make sure it's the same as target
	int targPair = robot->getTargetPair();

	TS_ASSERT_EQUALS(0, targPair);*/
}

//can't test setTargetPair without getTargetPair, this tests both at once essentially
//assumes target functions work
void Test_getTargetPair_with_obstacles(void){/*
	//add obstacles and target/robot pair at random indices

	//create a few obstacles
	ObstacleClass* obstacle1 = new ObstacleClass();
	ObstacleClass* obstacle2 = new ObstacleClass();
	ObstacleClass* obstacle3 = new ObstacleClass();

	environment.physicalObjectVector.push_back(obstacle1);

	//create target
	TargetClass* target = new TargetClass();
	target->setID(1);

	//add to environment
	environment.physicalObjectVector.push_back(target);
	environment.physicalObjectVector.push_back(obstacle2);
	environment.physicalObjectVector.push_back(obstacle3);

	//create RobotClass object
	RobotClass* robot = new RobotClass();
	robot->setTargetPair(1);
	environment.physicalObjectVector.push_back(robot);

	//get id, and make sure it's the same as target
	int targPair = robot->getTargetPair();

	TS_ASSERT_EQUALS(1, targPair);*/
}

//can't test setTargetPair without getTargetPair, this tests both at once essentially
//assumes target functions work
void Test_getTargetPair_with_obstacles_and_targets(void){/*
	//add obstacles and target/robot pair at random indices

	//create a few obstacles
	ObstacleClass* obstacle1 = new ObstacleClass();
	ObstacleClass* obstacle2 = new ObstacleClass();
	ObstacleClass* obstacle3 = new ObstacleClass();

	environment.physicalObjectVector.push_back(obstacle1);

	//create targets
	TargetClass* target1 = new TargetClass();
	target1->setID(1);

	TargetClass* target2 = new TargetClass();
	target2->setID(3);

	//add to environment
	environment.physicalObjectVector.push_back(target1);
	environment.physicalObjectVector.push_back(obstacle2);
	environment.physicalObjectVector.push_back(target2);
	environment.physicalObjectVector.push_back(obstacle3);

	//create RobotClass object
	RobotClass* robot = new RobotClass();
	robot->setTargetPair(3);
	environment.physicalObjectVector.push_back(robot);

	//get id, and make sure it's the same as target
	int targPair = robot->getTargetPair();

	TS_ASSERT_EQUALS(3, targPair);*/
}

//can't test setTargetPair without getTargetPair, this tests both at once essentially
//assumes target functions work
void Test_getTargetPair_with_multiple_targets(void){/*

	//create targets
	TargetClass* target1 = new TargetClass();
	target1->setID(1);

	TargetClass* target2 = new TargetClass();
	target2->setID(2);

	TargetClass* target3 = new TargetClass();
	target3->setID(3);

	//add to environment
	environment.physicalObjectVector.push_back(target1);
	environment.physicalObjectVector.push_back(target2);
	environment.physicalObjectVector.push_back(target3);

	//create RobotClass object
	RobotClass* robot = new RobotClass();
	robot->setTargetPair(2);
	environment.physicalObjectVector.push_back(robot);

	//get id, and make sure it's the same as target
	int targPair = robot->getTargetPair();

	TS_ASSERT_EQUALS(2, targPair);*/
}

void Test_getTarget(void){
/*
	TargetClass* targ = new TargetClass();
	targ->setID(0);

	//get all attributes, then check later
	char targColor = targ->getColor();
	int targSize = targ->getSize();
	double targLocation[2];
	targLocation[0] = targ->getXLocation();
	targLocation[1] = targ->getYLocation();
	double targSpeed = targ->getSpeed();
	int targOrientation = targ->getOrientation();
	int targId = targ->getID();

	environment.physicalObjectVector.push_back(targ);

	RobotClass* robot = new RobotClass();
	robot->setTargetPair(0);

	environment.physicalObjectVector.push_back(robot);

	PhysicalObjectClass* oldTarg = (PhysicalObjectClass*)robot->getTarget();

	//check to make sure it's the right one
	TS_ASSERT_EQUALS(targColor, oldTarg->getColor());
	TS_ASSERT_EQUALS(targSize, oldTarg->getSize());
	TS_ASSERT_EQUALS(targLocation[0], oldTarg->getXLocation());
	TS_ASSERT_EQUALS(targLocation[1], oldTarg->getYLocation());
	TS_ASSERT_EQUALS(targSpeed, oldTarg->getSpeed());
	TS_ASSERT_EQUALS(targOrientation, oldTarg->getOrientation());
	TS_ASSERT_EQUALS(targId, oldTarg->getID());*/
	

}

void Test_getTarget_other_objects(void){/*

	//add obstacles and target/robot pair at random indices

	//create a few obstacles
	ObstacleClass* obstacle1 = new ObstacleClass();
	ObstacleClass* obstacle2 = new ObstacleClass();
	ObstacleClass* obstacle3 = new ObstacleClass();

	environment.physicalObjectVector.push_back(obstacle1);

	//create targets
	TargetClass* target1 = new TargetClass();
	target1->setID(1);

	TargetClass* target2 = new TargetClass();
	target2->setID(3);

	//store target attributes
	char targColor = target2->getColor();
	int targSize = target2->getSize();
	double targLocation[2];
	targLocation[0] = target2->getXLocation();
	targLocation[1] = target2->getYLocation();
	double targSpeed = target2->getSpeed();
	int targOrientation = target2->getOrientation();
	int targId = target2->getID();

	//add to environment
	environment.physicalObjectVector.push_back(target1);
	environment.physicalObjectVector.push_back(obstacle2);
	environment.physicalObjectVector.push_back(target2);
	environment.physicalObjectVector.push_back(obstacle3);

	//create RobotClass object
	RobotClass* robot = new RobotClass();
	robot->setTargetPair(3);
	environment.physicalObjectVector.push_back(robot);

	//get id, and make sure it's the same as target
	PhysicalObjectClass* oldTarg = (PhysicalObjectClass*)robot->getTarget();

	//check to make sure it's the right one
	TS_ASSERT_EQUALS(targColor, oldTarg->getColor());
	TS_ASSERT_EQUALS(targSize, oldTarg->getSize());
	TS_ASSERT_EQUALS(targLocation[0], oldTarg->getXLocation());
	TS_ASSERT_EQUALS(targLocation[1], oldTarg->getYLocation());
	TS_ASSERT_EQUALS(targSpeed, oldTarg->getSpeed());
	TS_ASSERT_EQUALS(targOrientation, oldTarg->getOrientation());
	TS_ASSERT_EQUALS(targId, oldTarg->getID());*/

}

//make sure inheritance works?
void Test_setSpeed(void) {
	// This test tests functionality of void RobotClass::setSpeed()
  	
	// Create a robot object to test
	RobotClass* robot = new RobotClass();
  	
	// Reset its orientation with valid input, get its new orientation
	robot->setSpeed(10);
	int speed = robot->getSpeed();

	// Test to ensure that the robot's orientation reset
	TS_ASSERT_EQUALS(speed, 10);
}

//future tests... not sure if needed anymore
void Test_rotate_valid(void) { 
	TS_FAIL("Not Yet Implemented");
}

void Test_rotate_negative(void) {
	TS_FAIL("Not Yet Implemented");
}

void Test_rotate_zeroDegrees(void) {
	TS_FAIL("Not Yet Implemented");
}

void Test_rotate_tooMuch(void) {
	TS_FAIL("Not Yet Implemented");
}

void Test_translate_valid(void) { 
	TS_FAIL("Not Yet Implemented");
}

void Test_translate_smallDistance(void) {
	TS_FAIL("Not Yet Implemented");
}

void Test_translate_mediumDistance(void) {
	TS_FAIL("Not Yet Implemented");
}

void Test_translate_largeDistance(void) {
	TS_FAIL("Not Yet Implemented");
}

void Test_translate_tooLargeDistance(void) {
	TS_FAIL("Not Yet Implemented");
}

void Test_translate_negativeDistance(void) {
	TS_FAIL("Not Yet Implemented");
}

void Test_translate_zeroDistance(void) {
	TS_FAIL("Not Yet Implemented");
}

void Test_updatePosition(void) { 
	TS_FAIL("Not Yet Implemented");
}

void Test_updateNoChange(void) { 
	TS_FAIL("Not Yet Implemented");
}

void Test_pointTo_Target(void) {
	TS_FAIL("Not Yet Implemented");
}

void Test_pointTo_noTarget(void) {
	TS_FAIL("Not Yet Implemented");
}

};


