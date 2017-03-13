/*! \file RobotClass.h
 * RobotClass.h 
 * \brief The representation of the robot within the simulation
 * \author Rachel Soble, soble004, Group 5
 *
 * Adapted from class sample 
 *
 */

//class EnvironmentClass;

#ifndef ROBOTCLASS_H
#define ROBOTCLASS_H

#include "PhysicalObjectClass.h"
#include "TargetClass.h"
#include "EnvironmentClass.h"

extern EnvironmentClass environment;

// RobotClass. This provides means to store and alter robot state.  
class RobotClass : public PhysicalObjectClass {

public:

    //! Default constructor for RobotClass
    /*! This constructor takes in no arguments
     *    and sets the circle to a random location
     *    with size 50 and speed 10    
     */
    RobotClass();

    //! Constructor with three arguments, sizeIn, x, and y
    /*! This constructor takes in three integer arguments.
     *    The first, sizeIn, determines the size of the robot.
     *    The other arguments, x and y, determine its location
     *
     * \param sizeIn integer size of the robot
     * \param x x double location of the robot
     * \param y y double location of the robot
     */
    RobotClass(int sizeIn, double x, double y);

    //! default deconstructor for RobotClass
    /*! 
     *
     *
     */
    ~RobotClass();
    
    //! Sets the initial robot location 
    /*! Sets the initial robot location, ensuring that the robot will not overlap
     *    with any other objects
     *
     * \param x x double location of the robot
     * \param y y double location of the robot
     */
    void setInitLocation(double x, double y);
    
    //! Sets the robot location 
    /* 
     * \param x x double location of the robot
     * \param y y double location of the robot
     */
    void setLocation(double x, double y);

    //! Associates target with robot
    /*! \param target integer representation of a target */
    void setTargetPair(int target);
    
    //! Returns the unique signal of the target to which the robot is paired
    /*! \return integer targetPair  */
    int getTargetPair();
    
    //! Returns the target to which the robot is paired
    /*! \return TargetClass target */
    PhysicalObjectClass* getTarget();
    
    
    

//    //! returns true if there is a wall
//    /*! \return true if there's a wall  */
//    bool detectWall();

//    //! returns true if a particular obstacle is close
//    /*! \return true if a particular obstacle is close  */
//    bool detectObstacle(Obstacle obstacle);

//    //! returns true if there is an obstacle
//    /*! \return true if there is an obstacle */
//    bool detectAllObstacles();

    // Future methods
    //! rotates the robot while moving
    /*! This function takes in an integer argument, degrees,
     *    and rotates the object the amount specified. Positive
     *    rotates counter clockwise, the opposite for negative.
     *
     * \param degrees integer argument specifying rotation amount
     */
    void rotate(int degrees);

    //!  moves the robot
    /*!
     *
     *
     */
    void translate(int pixels);

    //! updates robot's position
    /*!
     *
     *
     */
    void updateLocation();

    //! sets the orientation of robot to target
    /*!
     *
     *
     */
    void pointTo(); 

	void updatePosition();

protected:

    int targetPair;

};

#endif

