// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <math.h>

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat z = -5.0f; 

GLfloat angle2 = 0;
GLfloat angle3 = 0;
GLfloat angle4 = 0;
GLfloat angle5 = 0;


GLvoid Modelisation()
{
  VM_init();

  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.

  glPushMatrix();
  {
    // Ceci, qui n'utilise pas les primitives de calcul d'OpenGL
    GLdouble translate[16] = {2.25,0,0,0, //paume
                              0,3.5,0,0,
                              0,0,0.5,0,
                              0,0,0,1};
    glMultMatrixd(translate);
    glutSolidCube(0.5);
}
	glPopMatrix();
	

    //------------------------doigt 5-------------------------------------//
	glPushMatrix();
	{
	glTranslatef(0,0.85,0);
	glRotatef(angle5,1,0,0);
	glTranslatef(0,-0.85,0);
	
    glColor3f(1, 0, 0);

    glTranslatef(-0.45, 1.1, 0); //phalange 1
		glScalef(0.5, 0.8, 0.2);
		glutSolidCube(0.5);
    
    glColor3f(0.8, 0.2, 0);
    		
    glTranslatef(0, 0.5, 0); //phalange 2
		glScalef(1, 0.7, 1);
		glutSolidCube(0.5);
    
    glColor3f(0.6, 0.4, 0);
    		
    glTranslatef(0, 0.5, 0); //phalange 3
		glScalef(1, 0.7, 1);
		glutSolidCube(0.5);
    
}
	glPopMatrix();
	


// ---------------------------doigt 4--------------------------------------//
	glPushMatrix();
	{
	glTranslatef(0,0.85,0);
	glRotatef(angle4,1,0,0);
	glTranslatef(0,-0.85,0);
	
    glColor3f(0, 1, 0);


    glTranslatef(-0.15, 1.1, 0); //phalange 1
		glScalef(0.5, 1, 0.2);
		glutSolidCube(0.5);

    glColor3f(0, 1.4, 0.5);


    glTranslatef(0, 0.5, 0); //phalange 1
		glScalef(1, 0.7, 1);
		glutSolidCube(0.5);
		
    glColor3f(0, 0.2, 0.4);


    glTranslatef(0, 0.5, 0); //phalange 1
		glScalef(1, 0.7, 1);
		glutSolidCube(0.5);



}

	glPopMatrix();
	

// ---------------------------doigt 3--------------------------------------//
	
	glPushMatrix();
	{
	glTranslatef(0,0.85,0);
	glRotatef(angle3,1,0,0);
	glTranslatef(0,-0.85,0);
			
    glColor3f(0.2, 0.2, 1.2);
		

    glTranslatef(0.15, 1.1, 0); //phalange 1
		glScalef(0.5, 1.3, 0.2);
		glutSolidCube(0.5);
		
    glColor3f(0.2, 0.4, 1.6);

		
    glTranslatef(0, 0.48, 0); //phalange 1
		glScalef(1, 0.7, 1);
		glutSolidCube(0.5);
		
		
    glColor3f(1, 0.2, 0.1);


    glTranslatef(0, 0.48, 0); //phalange 1
		glScalef(1, 0.7, 1);
		glutSolidCube(0.5);
		

	}

	glPopMatrix();
		
// ---------------------------doigt 2--------------------------------------//
	glPushMatrix();
	{
	glTranslatef(0,0.85,0);
	glRotatef(angle2,1,0,0);
	glTranslatef(0,-0.85,0);
			
    glColor3f(1.4, 1, 0);


    glTranslatef(0.45, 1.1, 0); //phalange 1
		glScalef(0.5, 1, 0.2);
		glutSolidCube(0.5);
		
		
    glColor3f(1.2, 1.4, 1.4);


    glTranslatef(0, 0.5, 0); //phalange 1
		glScalef(1, 0.7, 1);
		glutSolidCube(0.5);

    glColor3f(1.2, 0.2, 1.8);

		
    glTranslatef(0, 0.5, 0); //phalange 1
		glScalef(1, 0.7, 1);
		glutSolidCube(0.5);
		
    
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
