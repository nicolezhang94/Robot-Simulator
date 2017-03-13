#include <cxxtest/TestSuite.h>
#include "ObstacleClass.h"

using namespace std;

class ObstacleClassTests : public CxxTest::TestSuite 
{
public:


//Values passed in are assured to be valid
void Test_setInitLocation(void){

	//create ObstacleClass object
	ObstacleClass* obstacle = new ObstacleClass();

	//set Location
	obstacle->setInitLocation(100, 444);

	//get location
	int x_loc = obstacle->getXLocation();
	int y_loc = obstacle->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 100);
	TS_ASSERT_EQUALS(y_loc, 444);
}

void Test_setInitLocation_with_objects(void){

	//create obstacles
	ObstacleClass* obj1 = new ObstacleClass(circle, 40, 200, 200);

	//add to environment
	environment.physicalObjectVector.push_back(obj1);

	//create ObstacleClass object
	ObstacleClass* obstacle = new ObstacleClass();
	int old_x = obstacle->getXLocation();
	int old_y = obstacle->getYLocation();

	//set Location
	obstacle->setInitLocation(178, 200);

	//get location
	TS_ASSERT_EQUALS(old_x, obstacle->getXLocation());
	TS_ASSERT_EQUALS(old_y, obstacle->getYLocation());
}

void Test_setLocation(void){

	//create ObstacleClass object
	ObstacleClass* obstacle = new ObstacleClass();

	//set Location
	obstacle->setLocation(100, 444);

	//get location
	int x_loc = obstacle->getXLocation();
	int y_loc = obstacle->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 100);
	TS_ASSERT_EQUALS(y_loc, 444);

}

void Test_setLocation_with_objects(void){

	//create obstacles
	ObstacleClass* obj1 = new ObstacleClass(circle, 40, 200, 200);

	//add to environment
	environment.physicalObjectVector.push_back(obj1);

	//create ObstacleClass object
	ObstacleClass* obstacle = new ObstacleClass();
	int old_x = obstacle->getXLocation();
	int old_y = obstacle->getYLocation();

	//set Location
	obstacle->setLocation(178, 200);

	//get location
	TS_ASSERT_EQUALS(old_x, obstacle->getXLocation());
	TS_ASSERT_EQUALS(old_y, obstacle->getYLocation());
}

//out of bounds
void Test_setLocation_invalid_X(void){

	//create ObstacleClass object
	ObstacleClass* obstacle = new ObstacleClass();
	obstacle->setSize(20);

	//set Location
	obstacle->setLocation(976, 100);

	//get location
	int x_loc = obstacle->getXLocation();
	int y_loc = obstacle->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 781);
	TS_ASSERT_EQUALS(y_loc, 100);
}

//out of bounds
void Test_setLocation_invalid_Y(void){

	//create ObstacleClass object
	ObstacleClass* obstacle = new ObstacleClass();
	obstacle->setSize(30);

	//set Location
	obstacle->setLocation(200, 999);

	//get location
	int x_loc = obstacle->getXLocation();
	int y_loc = obstacle->getYLocation();

	//check if right
	TS_ASSERT_EQUALS(x_loc, 200);
	TS_ASSERT_EQUALS(y_loc, 771);
}

};
