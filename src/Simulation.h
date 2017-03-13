/*! \file  Simulation.h
 * 
 * \brief Main application class for the robot simulation
 *
 * \author Nicole Zhang
 * \author Nicholas Inman
 *
 */


#ifndef SIMULATION_H
#define SIMULATION_H

//#include <vector>

#include "BaseGfxApp.h"
#include "RobotClass.h"
#include "RenderingWindowClass.h"

//0 for unpaused, 1 for paused
#ifndef __FLAG
#define __FLAG

#endif

extern EnvironmentClass environment;

/** The Simulation class.  This sets up the GUI and the drawing environment. */  
class Simulation : public BaseGfxApp {

public: 

    enum UIControlType {
    	UI_QUIT = 0,
    };

    //! Initializes OpenGL window
    /*! Creates OpenGL window and basic UI panel with quit button.
     */
    Simulation(int argc, char* argv[], int width, int height);
    virtual ~Simulation();

    //! Displays objects
    /*! This function takes objects from obstacleArray and displays them in the 
     *    OpenGL window by calling the drawing functions from drawing.cpp. The 
     *    function then checks to make sure that the robot does not overlap the
     *    obstacles or target. The location of the robot is reset with random
     *    coordinates until it doesn't overlap any obstacles or the target. Then
     *    draws and displays robot.
     */
    void display();

    //! Starts simulation
    /*! Starts simulation by toggling flag. This allows the environment to 
     *    run the update function and move the objects.
     * 
     * \param id button identifier to be used in future iterations
     */
    static void start(int id);

    //! Resumes simulation
    /*! Resumes simulation after pausing by toggling flag. This allows the 
     *    environment to resume running the update function.
     * 
     * \param id button identifier to be used in future iterations
     */
    static void resume(int id);

    //! Pauses simulation
    /*! Pauses simulation by toggling flag. This prevents the environment from 
     *    running the update function by returning at the beginning. This prevents 
     *    objects from updating any attributes, effectively "pausing" the simulation.
     * 
     * \param id button identifier to be used in future iterations
     */
    static void pause(int id);

    void gluiControl(int controlID);
    void leftMouseDown(int x, int y);
    void leftMouseUp(int x, int y);
    
private:

};


#endif
