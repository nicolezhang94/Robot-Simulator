/*! \file TargetClass.h
 *
 * \brief Holds information about targets
 *
 */

#ifndef TARGETCLASS_H
#define TARGETCLASS_H

#include "PhysicalObjectClass.h"
//#include "EnvironmentClass.h"

#include <cstdlib>
#include <iostream>

//extern EnvironmentClass environment;

class TargetClass : public PhysicalObjectClass {

	public:
		//! default constructor for TargetClass
		TargetClass();

		//! constructor for TargetClass that takes in color
		TargetClass(char colorIn);

		//! Set the target location
    		/*! This function takes in the double arguments (x, y) and sets its location.
    		 *
    		 * \param x double x-coordinate
    		 * \param y double y-coordinate
    		 */
		void setLocation(double x, double y);

};

#endif
