// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test


//skybox
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
float mipuissance[] = { 1.0f, 1.0f, 1.0f, 1.0f };
   


GLvoid Modelisation()
{
  VM_init();      
  glPushMatrix();
  {
		glRotatef(angle_triangle, 0, 1, 0);
		angle_triangle = angle_triangle+1;
		glTranslatef(0,0,10);
		
		glPushMatrix(); //corps
		{
			glColor3f(0.09,0.24,0.59);
			glScalef(2,1,1);
			glutSolidSphere(1,25,25);
			glEnd();
		}
		glPopMatrix();
		
		
		
		glPushMatrix(); //tete
		{
			glTranslatef(2,0,0);
			glColor3f(0.22,0.3,0.47);
			glScalef(1,0.5,0.5);
			glutSolidSphere(1,25,25);
			glEnd();
		}
		glPopMatrix();
		
		
		
		glPushMatrix(); //oeil droite
		{
			glTranslatef(2.8,0.2,0.2);			  
			glColor3f(1,1,1);
			glScalef(0.5,1,1);
			glutSolidSphere(0.12, 25, 25);
			glEnd();

		}
		glPopMatrix();


		glPushMatrix(); //pupille droite
		{
			glTranslatef(2.82,0.2,0.2);			  
			glColor3f(0,0,0);
			glScalef(1,1,0.5);
			glutSolidSphere(0.08, 25, 25);
			glEnd();

		}
		glPopMatrix();
		  
		  
		  
		glPushMatrix(); //oeil gauche
		{
			glTranslatef(2.8,0.2,-0.2);			  
			glColor3f(1,1,1);
			glScalef(0.5,1,1);
			glutSolidSphere(0.12, 25, 25);
			glEnd();

		}
		glPopMatrix();
		
		
		
		glPushMatrix(); //pupille gauche
		{
			glTranslatef(2.82,0.2,-0.2);			  
			glColor3f(0,0,0);
			glScalef(1,1,0.5);
			glutSolidSphere(0.08, 25, 25);
			glEnd();

		}
		glPopMatrix();
		
		
		
		glPushMatrix(); //aile droite
		{
			glTranslatef(0,0,1.4);
			glRotatef(75,1,0,0);
			glColor3f(0.09,0.24,0.34);
			glBegin(GL_TRIANGLES);
				glVertex3f(0.0, 2.0, 0.0);
				glVertex3f(1.0, -1.0, 0.0);
				glVertex3f(-1.0, -1.0, 0.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //aile gauche
		{
			glTranslatef(0,0,-1.4);
			glRotatef(-75,1,0,0);
			glColor3f(0.09,0.24,0.34);
			glBegin(GL_TRIANGLES);
				glVertex3f(0.0, 2.0, 0.0);
				glVertex3f(1.0, -1.0, 0.0);
				glVertex3f(-1.0, -1.0, 0.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //queue
		{
			glTranslatef(-2,-0.5,0);
			glRotatef(-90,0,1,0);
			glRotatef(-240,1,0,0);
			glRotatef(-180,0,0,1);
			glColor3f(0.09,0.24,0.34);
			glBegin(GL_TRIANGLES);
				glVertex3f(0.0, 1.0, 0.0);
				glVertex3f(1.0, -1.0, 0.0);
				glVertex3f(-1.0, -1.0, 0.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //bec
		{
			glTranslatef(2.8,0,0);
			glScalef(2.5,0.2,0.2);
			glColor3f(0.41,0.41,0.41);
			glBegin( GL_TRIANGLES ); 
				glVertex3f( 0.0f, 1.f, 0.0f );
				glVertex3f( -1.0f, -1.0f, 1.0f );
				glVertex3f( 1.0f, -1.0f, 1.0f);

				glVertex3f( 0.0f, 1.0f, 0.0f);
				glVertex3f( -1.0f, -1.0f, 1.0f);
				glVertex3f( 0.0f, -1.0f, -1.0f);

				glVertex3f( 0.0f, 1.0f, 0.0f);
				glVertex3f( 0.0f, -1.0f, -1.0f);
				glVertex3f( 1.0f, -1.0f, 1.0f);

				glVertex3f( -1.0f, -1.0f, 1.0f);
				glVertex3f( 0.0f, -1.0f, -1.0f);
				glVertex3f( 1.0f, -1.0f, 1.0f);
			glEnd();
		}
		glPopMatrix();
	}
	glPopMatrix();

glClearColor(0.43, 0.57, 0, 0.8);



  axes();
  glutSwapBuffers();
  
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
