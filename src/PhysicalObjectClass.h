/*! \file PhysicalObjectClass.h
 * PhysicalObjectClass.h
 *
 * \brief The physical world containing RobotClass, TargetClass, and ObstacleClass objects
 * \author Rachel Soble
 *
 */

// To fix the issue of including PhysicalObjectClass.h and EnvironmentClass.h in each other's headers
class EnvironmentClass;

#ifndef PHYSICALOBJECTCLASS_H
#define PHYSICALOBJECTCLASS_H

//! Different object types of PhysicalOjbects
enum ObjectType {
	robot,
	target,
	obstacle
};

//! Different shape types of PhysicalOjbects
enum ShapeType {
	square, 
	circle,
	triangle
};

// PhysicalObjectClass. This provides the means to store and alter the states of objects 
// (RobotClass, TargetClass, ObstacleClass) within the physical world of the simulation. 
class PhysicalObjectClass {

public:

    //! Default constructor for PhysicalObjectClass
    /*! This constructor takes in no arguments.   
     */
    PhysicalObjectClass();

    PhysicalObjectClass(double x, double y, int sizeIn, double speedIn);

    //only used for testing
    PhysicalObjectClass(ObjectType objTypeIn, ShapeType objShapeIn, char colorIn, double x, double y, int sizeIn, double speedIn, int orientationIn, int idIn, int sbdIn);

    //! Default destructor for PhysicalObjectClass
    ~PhysicalObjectClass();

    //! Set the PhysicalObject color
    /*! This function takes in the char argument color ('R', 'G', 'B' for now)
     *    and sets the object's color to the corresponding color
     *
     * \param colorIn character representing color
     */
	void setColor(char colorIn);
	
	//! Set the PhysicalObject size
    /*! This function takes in the integer argument sizeIn
     *    and sets thusly the object's size
     *
     * \param sizeIn int sizeIn
     */
	void setSize(int sizeIn);
	
	//! Set the PhysicalObject location
    /*! This function takes in the double arguments (x, y).
     *    The object's location is determined for each ObjectType.
     *
     * \param x double x-coordinate
     * \param y double y-coordinate
     */
    virtual void setLocation(double x, double y);
	
    //! Set the PhysicalObject location outside of the GLUT window
    /*! This function sets the object's location to (-100, -100),
     *    outside of the GLUT window.
     */
    void setLocationOutside();

    //! Sets the PhysicalObject speed
    /*! This function takes in the integer argument pps
     *    and sets it as the object's speed in pixels per second
     *
     * \param pps integer speed in pixels per second
     */
    void setSpeed(double pps); 
    
    //! Sets the object orientation
    /*! This function takes in an integer argument degrees
     *    and then orients the robot
     *
     * \param degrees integer argument for orientation
     */ 
    // Set orientation (in degrees; 0 degrees = positive x-axis)
    void setOrientation(int degrees);
    
    //! Sets the object's ID in the env PhysicalObject vector
    /*! \param id integer identifier */
    void setID(int idIn);
    
    //! Sets whether the object should be drawn
    /*! \param shouldBeDrawn boolean */
    void setShouldBeDrawn(int shouldDraw);

    //! Returns the object ObjectType
    /* \return ObjectType objType */
    ObjectType getObjectType();

    //! Returns the object ShapeType
    /* \return ShapeType shape */
    ShapeType getShapeType();

    //! Returns the object color
    /* \return char color */
    char getColor();

    //! Returns the object size
    /* \return integer size  */
    int getSize();

    //! Returns the object's x-position
    /* \return double x-position (in pixels)  */
    double getXLocation();

    //! Returns the object's y-position
    /*! \return double y-position  */
    double getYLocation();

    //! Returns the object's speed
    /*! \return integer speed  */
    double getSpeed();
    
    //! Returns object orientation
    /*! \return integer degrees  */
    int getOrientation();
    
    //! Returns the object's ID in the env PhysicalObject vector
    /*! \return integer ID  */
    int getID();
    
    //! Returns whether the object should be drawn
    /*! \return boolean shouldBeDrawn  */
    int getShouldBeDrawn();
   
protected:

    ObjectType objType;
    ShapeType shape;
    char color;
    int size;
    double location[2];
    double speed;
    int orientation;
    int id;
    int shouldBeDrawn;
    
};

#endif

