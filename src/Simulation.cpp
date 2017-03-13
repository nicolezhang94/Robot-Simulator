/*! \file Simulation.cpp
 *
 * \author Nicole Zhang
 * \author Rachel Soble
 * \author Nicholas Inman
 * \brief contains Simulation class definitions
 *
 */

#include "Simulation.h"
#include "EnvironmentClass.h"
using namespace std;

#define PI 3.14
extern int flag;
extern double pastTime;

Simulation::Simulation(int argc, char* argv[], int width, int height) : BaseGfxApp(argc, argv, width, height, 50, 50, GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH, true, 851, 50)
{
	setCaption("Robot Simulation");

    //creates a basic UI panel with quit button
	GLUI_Panel *toolPanel = new GLUI_Panel(m_glui, "Control Panel");

    /*GLUI_Button* start_button = new GLUI_Button(m_glui, "Start", 4, (GLUI_Update_CB)start);
    start_button->set_id(2);

    GLUI_Button* resume_button = new GLUI_Button(m_glui, "Resume", 4, (GLUI_Update_CB)resume);
    start_button->set_id(3);
    
    GLUI_Button* pause_button = new GLUI_Button(m_glui, "Pause", 3, (GLUI_Update_CB)pause);
    pause_button->set_id(4);
    pause_button->disable();*/



    m_glui->add_button_to_panel(toolPanel, "Start", 2, (GLUI_Update_CB)start);
    m_glui->add_button_to_panel(toolPanel, "Resume", 2, (GLUI_Update_CB)resume);
    m_glui->add_button_to_panel(toolPanel, "Pause", 3, (GLUI_Update_CB)pause); 
    new GLUI_Button(m_glui, "Quit", UI_QUIT, (GLUI_Update_CB)exit);

    // Initialize OpenGL
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();
    gluOrtho2D(0, m_width, 0, m_height);
    glViewport(0, 0, m_width, m_height);

}

Simulation::~Simulation()
{
   //DESTRUCT
}

void Simulation::gluiControl(int controlID) {
    // nothing here for now
}

void Simulation::start(int id){
	flag = 0;
}

void Simulation::resume(int id){
	flag = 0;
}

void Simulation::pause(int id){
	flag = 1;
}

void Simulation::display()
{    
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Currently must move mouse over window in order move objects
    environment.display();

    // Debugging messages
    int err;
    if ((err = glGetError()) != GL_NO_ERROR) {
        cerr << "GL is in an error state" << endl;
        cerr << "(GL error code " << err << ")\n";
        assert(0);
    }
    
    // advance
    glutSwapBuffers();
}

void Simulation::leftMouseDown(int x, int y) {
    // nothing here for now
}

void Simulation::leftMouseUp(int x, int y) {
    // nothing here for now
}


