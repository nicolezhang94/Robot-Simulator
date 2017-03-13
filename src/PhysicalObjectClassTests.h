#include <cxxtest/TestSuite.h>
#include "PhysicalObjectClass.h"
using namespace std

class PhysicalObjectClassTests : public cxxTest::TestSuite{

public:

//assumes that getColor works
void Test_setColor(void){
	
	PhysicalObjectClass object;
	object.setColor("r");
	TS_ASSERT_EQUALS("r", object.getColor());
	
	TS_FAIL("Not Yet Implemented");
}

//assumes that getSpeed works
void Test_setSpeed(void) {
	// This test tests functionality of void RobotClass::setSpeed()
  	
	// Create a robot object to test
  	PhysicalObjectClass object;
  	
  	// Reset its orientation with valid input, get its new orientation
  	object.setSpeed(10);
  	int speed = object.getSpeed();

  	// Test to ensure that the robot's orientation reset
  	TS_ASSERT_EQUALS(speed, 10);
}

//assumes getSpeed works
void Test_setSpeed_negative(void) {
    	// This test tests functionality of void RobotClass::setSpeed()
  	
  	// Create a robot object to test
  	PhysicalObjectClass object;
  	
  	// Reset its orientation with valid input, get its new orientation
  	object.setSpeed(10);
	object.setSpeed(-15);
  	int speed = object.getSpeed();

  	// Test to ensure that the robot's orientation reset
  	TS_ASSERT_EQUALS(speed, 10);
}

//assumes getSpeed works
void Test_setSpeed_zero(void) {
    	// This test tests functionality of void RobotClass::setSpeed()
  	
  	// Create a robot object to test
  	PhysicalObjectClass object;
  	
  	// Reset its orientation with valid input, get its new orientation
	object.setSpeed(0);
  	int speed = object.getSpeed();

  	// Test to ensure that the robot's orientation reset
  	TS_ASSERT_EQUALS(speed, 0);
}

//assumes getOrientation works
void Test_setOrientation(void){

    	PhysicalObjectClass* obj = new PhysicalObjectClass(obstacle, circle, 'R', 200, 200, 50, 10, 25, 7, 1);
   	obj->setOrientation(77);
	int orient = obj->getOrientation();
   	TS_ASSERT_EQUALS(orient, 77);

}

//assumes getID works
void Test_setID(void){

    	PhysicalObjectClass* obj = new PhysicalObjectClass(obstacle, circle, 'R', 200, 200, 50, 10, 25, 7, 1);
   	obj->setID(8);
	int id = obj->getID();
   	TS_ASSERT_EQUALS(id, 8);

}

//assumes getShouldBeDrawn works
void Test_setShouldBeDrawn(void){

    	PhysicalObjectClass* obj = new PhysicalObjectClass(obstacle, circle, 'R', 200, 200, 50, 10, 25, 7, 0);
   	obj->setShouldBeDrawn(1);
	int sbd = obj->getShouldBeDrawn();
   	TS_ASSERT_EQUALS(sbd, 1);

}

void Test_getShapeType(void){
	
	PhysicalObjectClass* obj = new PhysicalObjectClass(obstacle, circle, 'R', 200, 200, 50, 10, 25, 7, 0);
	ShapeType stype = obj->getShapeType();
   	TS_ASSERT_EQUALS(stype, obstacle);
}

void Test_getColor(void){
	
	PhysicalObjectClass* obj = new PhysicalObjectClass(obstacle, circle, 'R', 200, 200, 50, 10, 25, 7, 0);
	char stype = obj->getShapeType();
   	TS_ASSERT_EQUALS(stype, obstacle);
}

void Test_getSize(void) {

    	PhysicalObjectClass* obj = new PhysicalObjectClass(obstacle, circle, 'R', 200, 200, 50, 10, 25, 7, 1);
   	int size = obj->getSize();
   	TS_ASSERT_EQUALS(size, 50);
	
}

void Test_getXLocation(void) {

    	PhysicalObjectClass* obj = new PhysicalObjectClass(obstacle, circle, 'R', 200, 170, 50, 10, 25, 7, 1);
   	int loc = obj->getXLocation();
   	TS_ASSERT_EQUALS(loc, 200);
}

void Test_getYLocation(void) {

    	PhysicalObjectClass* obj = new PhysicalObjectClass(obstacle, circle, 'R', 200, 170, 50, 10, 25, 7, 1);
   	int loc = obj->getYLocation();
   	TS_ASSERT_EQUALS(loc, 170);
}

void Test_getSpeed(void) {

    	PhysicalObjectClass* obj = new PhysicalObjectClass(obstacle, circle, 'R', 200, 200, 45, 10, 25, 7, 1);
   	int loc = obj->getSpeed();
   	TS_ASSERT_EQUALS(loc, 45);
}


void Test_move(void){
	TS_FAIL("Not Yet Implemented");
}



};
