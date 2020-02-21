// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <math.h>

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 
int blend = 0;
int light = 0;

GLfloat angle2 = 0;
GLfloat angle3 = 0;
GLfloat angle4 = 0;
GLfloat angle5 = 0;
GLfloat angle_triangle = 0;

float ambientLightDefault[] = { 0.1f, 0.1f, 0.1f, 0.1f };
float mipuissance[] = { 0.5f, 0.5f, 0.5f, 0.5f };

GLvoid Modelisation()
{
    VM_init();

    // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.

          glPushMatrix();
          {
                  glRotatef(angle_triangle, 0, 1, 0);
                  angle_triangle = angle_triangle+1;
                  glEnable(GL_LIGHTING);
                  glEnable(GL_COLOR_MATERIAL);
				  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLightDefault);
				  glEnable(GL_LIGHT0);
				  glLightfv(GL_LIGHT0, GL_DIFFUSE, mipuissance);
				  glLightfv(GL_LIGHT0, GL_SPECULAR, mipuissance);
                  glColor3f(1,1,0);
                  glRotatef(xrot, 1,0,0);
				  glRotatef(yrot, 0, 1, 0);
                  glutSolidSphere(0.5, 10, 10);
                  glEnd();

          }
          glPopMatrix();


glClearColor(0.5, 0.5, 1, 0.8);



  axes();
  glutSwapBuffers();
  
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
