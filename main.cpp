
#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<GL/glut.h>
#include<string>
#include<sstream>


using namespace std;

  // ==================================================================================================== //
 // ==================================== Function Prototypes ========================================== //
// ================================================================================================== //
  
  
void myInit (void);
void myDisplay(void);
  
  // ================================================================================================== //
 // ==================================== Global Variables ============================================ //
// ================================================================================================== //


  // ================================================================================================== //
 // ==================================== Main ======================================================== //
// ================================================================================================== //


int main(int argc, char** argv){

    


    return 0;
}

  // ================================================================================================== //
 // ==================================== Functions =================================================== //
// ================================================================================================== //

void myInit (void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glViewport(0, 0, 760, 480);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 760.0, 480.0, 0.0, -1.0, 1.0);

}

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    //Bar
    glBegin(GL_QUADS);
    glColor3ub(255, 204, 102);
    glVertex2f(barX, barY);
    glVertex2f(barX+barWidth, barY);
    glVertex2f(barX+barWidth, barY+barheight);
    glVertex2f(barX, barY+barheight);
    glEnd();
    //Ball
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(ballX, ballY);
    glVertex2f(ballX+ballWH, ballY);
    glVertex2f(ballX+ballWH, ballY+ballWH);
    glVertex2f(ballX, ballY+ballWH);
    glEnd();

    //sidebar
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(480, 0);
    glVertex2f(480, 480);
    glVertex2f(485, 480);
    glVertex2f(485, 0);
    glEnd();

    print(score);
    createBricks();
    message(flag);
    completeMessage(flag2);

    glutSwapBuffers();
}
