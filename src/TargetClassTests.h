#include <cxxtest/TestSuite.h>
#include "TargetClass.h"
#include "ObstacleClass.h"
//#include "RobotClass.h"

using namespace std;

class TargetClassTests : cxxtest::TestSuite{

void Test_setLocation(void){

	//create TargetClass object
	TargetClass* target = new TargetClass();

	//set Location
	target->setLocation(100, 444);

	//get location
	int x_loc = target->getXLocation();
	int y_loc = target->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 100);
	TS_ASSERT_EQUALS(y_loc, 444);

}

void Test_setLocation_with_objects(void){

	//create obstacles
	ObstacleClass* obj1 = new ObstacleClass(circle, 40, 200, 200);

	//add to environment
	environment.physicalObjectVector.push_back(obj1);

	//create TargetClass object
	TargetClass* target = new TargetClass();
	int old_x = target->getXLocation();
	int old_y = target->getYLocation();

	//set Location
	target->setLocation(178, 200);

	//get location
	TS_ASSERT_EQUALS(old_x, target->getXLocation());
	TS_ASSERT_EQUALS(old_y, target->getYLocation());
}

//out of bounds
void Test_setLocation_invalid_X(void){

	//create TargetClass object
	TargetClass* target = new TargetClass();
	target->setSize(20);

	//set Location
	target->setLocation(976, 100);

	//get location
	int x_loc = target->getXLocation();
	int y_loc = target->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 781);
	TS_ASSERT_EQUALS(y_loc, 100);
}

//out of bounds
void Test_setLocation_invalid_Y(void){

	//create TargetClass object
	TargetClass* target = new TargetClass();
	target->setSize(30);

	//set Location
	target->setLocation(200, 999);

	//get location
	int x_loc = target->getXLocation();
	int y_loc = target->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 200);
	TS_ASSERT_EQUALS(y_loc, 771);
}


};
