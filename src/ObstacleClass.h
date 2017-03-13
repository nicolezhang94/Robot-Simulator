/*! \file ObstacleClass.h
 *
 * \brief Holds information about obstacles
 *
 */
 
#ifndef OBSTACLECLASS_H
#define OBSTACLECLASS_H

#include "PhysicalObjectClass.h"
#include "EnvironmentClass.h"

#include <cstdlib>
#include <iostream>

extern EnvironmentClass environment;

class ObstacleClass : public PhysicalObjectClass {

public:

	//! default Obstacle constructor
	/*! This constructor creates an circle with size
	 *    5 and a random location
	 */
	ObstacleClass();


	//! obstacle constructor with two parameters
	/*! This constructor creates an obstacle of type
	 *    shapeIn with size sizeIn
	 */ 
	ObstacleClass(ShapeType shapeIn, int sizeIn);
	


        //! obstacle constructor with 4 paramters
        /*! This constructor creates an obstacle of type
         *    shapeIn with size sizeIn, x-position x, and
	 *    y position y
	 * \param shapeIn Enum shape
	 * \param sizeIn integer size of shape
	 * \param x integer x coordinate (in pixels)
	 * \param y integer y coordinate (in pixels)
         */
	ObstacleClass(ShapeType shapeIn, int sizeIn, double x, double y);

    //! Sets the initial obstacle location 
    /*! Sets the initial obstacle location, ensuring that the obstacle will not overlap
     *    with any other objects
     *
     * \param x x double location of the obstacle
     * \param y y double location of the obstacle
     */
    void setInitLocation(double x, double y);

	//! sets object Position
	/*! This function sets the obstacle's x- and y-positions
	 *    to the integer input from the user
	 *
	 * \param x, y
	 */
	void setLocation(double x, double y);

};

#endif
