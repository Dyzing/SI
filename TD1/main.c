// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <math.h>

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 

GLvoid Modelisation()
{
  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.

  glPushMatrix();
  {
    // Ceci, qui n'utilise pas les primitives de calcul d'OpenGL
    GLdouble translate[16] = {2.25,0,0,0,
                              0,3.5,0,0,
                              0,0,0.5,0,
                              0,0,0,1};
    glMultMatrixd(translate);
    glutSolidCube(0.5);

    //-------------------------------------------------------------//

    GLdouble translate_5[16] =  {0.2,0,0,0,
                                 0,0.7,0,0,
                                 0,0,0.5,0,
                                 -0.2,0.25,0,1};
    glMultMatrixd(translate_5);
    glutSolidCube(0.5);



  }
  glPopMatrix();







  axes();
  glutSwapBuffers();
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
