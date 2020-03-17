// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

//gcc main.c actions.c axes.o init.c lumiere.o switch_blend.o  switch_light.o VM_init.c -lm -lGL -lGLU -no-pie -lglut -o test; ./test

//skybox
#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <math.h>

GLfloat xrot = 0.0f;   
GLfloat yrot = 0.0f;   
GLfloat xcamrot = 0.0;   
GLfloat ycamrot = 0.0; 
GLfloat zcamrot = 0.0;  
GLfloat z = -5.0f; 
int blend = 0;
int light = 0;

GLfloat angle2 = 0;
GLfloat angle3 = 0;
GLfloat angle4 = 0;
GLfloat angle5 = 0;

GLfloat angle_triangle = 0;
GLfloat angle_aile = 0;

int montee0_descente1 = 0;


GLfloat position_x = 0;
GLfloat position_y = 0;
GLfloat position_z = 0;





GLvoid Modelisation()
{
  VM_init();      


  glPushMatrix();
  {
  		//lumiere


float dir_length = sqrt(position_x * position_x + position_y * position_y + position_z * position_z);

// position_x /=dir_length;
// position_y /= dir_length;
// position_z /= dir_length;


	  //transparence
	glEnable(GL_BLEND); 
  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	  	//rotation
		glTranslatef(2,2,2);
		glTranslatef(position_x,position_y,position_z);
		printf("x : %f\n", position_x);
		printf("z : %f\n", position_z);
		printf("angle : %f\n", angle_triangle);


		glRotatef(angle_triangle , 0, 1, 0);


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
			if (montee0_descente1 == 0)
			{
				glRotatef(-angle_aile, 1,0,0);
				angle_aile = angle_aile +1;
				if (angle_aile == 30)
				{
					montee0_descente1 = 1;
				}

				glTranslatef(0,0,1.4);
				glRotatef(75,1,0,0);
				glColor3f(0.09,0.24,0.34);
				glBegin(GL_TRIANGLES);
					glVertex3f(0.0, 2.0, 0.0);
					glVertex3f(1.0, -1.0, 0.0);
					glVertex3f(-1.0, -1.0, 0.0);
				glEnd();	
			}

			else	
			{
				glRotatef(-angle_aile, 1,0,0);
				angle_aile = angle_aile -1;
				if (angle_aile == -15)
				{
					montee0_descente1 = 0;
				}

				glTranslatef(0,0,1.4);
				glRotatef(75,1,0,0);
				glColor3f(0.09,0.24,0.34);
				glBegin(GL_TRIANGLES);
					glVertex3f(0.0, 2.0, 0.0);
					glVertex3f(1.0, -1.0, 0.0);
					glVertex3f(-1.0, -1.0, 0.0);
				glEnd();	
			}

		}
		glPopMatrix();

		glPushMatrix(); //aile gauche
		{

			if (montee0_descente1 == 0)
			{
				glRotatef(angle_aile, 1,0,0);
				angle_aile = angle_aile +1;
				if (angle_aile == 30)
				{
					montee0_descente1 = 1;
				}

				glTranslatef(0,0,-1.4);
				glRotatef(-75,1,0,0);
				glColor3f(0.09,0.24,0.34);
				glBegin(GL_TRIANGLES);
					glVertex3f(0.0, 2.0, 0.0);
					glVertex3f(1.0, -1.0, 0.0);
					glVertex3f(-1.0, -1.0, 0.0);
				glEnd();	
			}

			else	
			{
				glRotatef(angle_aile, 1,0,0);
				angle_aile = angle_aile -1;
				if (angle_aile == -15)
				{
					montee0_descente1 = 0;
				}

				glTranslatef(0,0,-1.4);
				glRotatef(-75,1,0,0);
				glColor3f(0.09,0.24,0.34);
				glBegin(GL_TRIANGLES);
					glVertex3f(0.0, 2.0, 0.0);
					glVertex3f(1.0, -1.0, 0.0);
					glVertex3f(-1.0, -1.0, 0.0);
				glEnd();	
			}
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


	glPushMatrix(); //sol
	{
		glTranslatef(0,-20,0);
		glScalef(30,1,25);
		glColor3f(0.43, 0.57, 0);
		glutSolidCube(3.0);
		glEnd();
	}
	glPopMatrix();





	glPushMatrix(); //pollen
	{
		glTranslatef(24,2,-22.5);
		glRotatef(-90,0,0,1);
		glColor3f(1,1,0.34);
		glScalef(1,1,1);
		glutSolidSphere(0.5, 25, 25);
		glEnd();
	}
	glPopMatrix();






	glPushMatrix(); //fleur
	{
		glEnable(GL_DEPTH_TEST);
		glTranslatef(20,0.5,-20);
		glRotatef(120,0,1,0);
		glRotatef(-20,1,0,0);
		glScalef(5,5,5);
		glColor4f(1,0.71, 0.75, 0.4);
		GLUquadric* params = gluNewQuadric(); //création du quadrique
    	gluQuadricTexture(params,GL_TRUE); 
	    gluCylinder(params,0.5,0,1.6,20,1); //cône 1
        gluDeleteQuadric(params); //je supprime le quadrique
	}
	glPopMatrix();


	glPushMatrix(); //tige
	{
		glTranslatef(26,-9.5,-23.25);
		glRotatef(90,0,0,1);
		glColor3f(0.19,0.8,0.19);
		glScalef(25,1,1);
		glutSolidSphere(0.5,25,25);
		glEnd();
	}
	glPopMatrix();




	glPushMatrix(); //feuille droite
	{
		glTranslatef(24,-6,-23.25);
		glRotatef(-135,0,0,1);
		glColor3f(0,0.51,0);
		glScalef(1,2,2);
		glutSolidSphere(1, 25, 25);
		glEnd();
	}
	glPopMatrix();



	glPushMatrix(); //feuille gauche
	{
		glTranslatef(28,-12,-23.25);
		glRotatef(135,0,0,1);
		glColor3f(0,0.51,0);
		glScalef(1,2,2);
		glutSolidSphere(1, 25, 25);
		glEnd();
	}
	glPopMatrix();





	glPushMatrix(); //caillou gauche 1
	{
		glTranslatef(-15,-16,-15);
		glRotatef(110,0,0,1);
		glColor3f(0.41,0.41,0.41);
		glScalef(1,2,2);
		glutSolidSphere(3, 10, 10);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //caillou gauche 2
	{
		glTranslatef(-13,-16,-15);
		glRotatef(-110,0,0,1);
		glColor3f(0.41,0.41,0.41);
		glScalef(1,2,2);
		glutSolidSphere(3, 10, 10);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //caillou gauche 3
	{
		glTranslatef(-14,-18,-16);
		glRotatef(-110,0,0,1);
		glRotatef(90,0,0,1);
		glColor3f(0.41,0.41,0.41);
		glScalef(1,2,3);
		glutSolidSphere(3, 10, 10);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //caillou gauche 4
	{
		glTranslatef(-14,-18,-10);
		glRotatef(-110,0,0,1);
		glRotatef(-90,0,1,0);
		glColor3f(0.41,0.41,0.41);
		glScalef(1,2,3);
		glutSolidSphere(2, 10, 10);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //clôture droite
	{
		glPushMatrix(); //barreau droit
		{
			glTranslatef(35,-10,0);
			glScalef(0.5,0.5,25);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 1
		{
			glTranslatef(35,-15,-35);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 2
		{
			glTranslatef(35,-15,-12);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 3
		{
			glTranslatef(35,-15,12);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 4
		{
			glTranslatef(35,-15,35);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();
	}
	glPopMatrix();


	glPushMatrix(); //clôture gauche
	{
		glPushMatrix(); //barreau gauche
		{
			glTranslatef(-35,-10,0);
			glScalef(0.5,0.5,25);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 1
		{
			glTranslatef(-35,-15,-35);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 2
		{
			glTranslatef(-35,-15,-12);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 3
		{
			glTranslatef(-35,-15,12);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 4
		{
			glTranslatef(-35,-15,35);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();
	}
	glPopMatrix();


	glPushMatrix(); //clôture arrière
	{
		glPushMatrix(); //barreau arrière
		{
			glTranslatef(0,-10,-35);
			glRotatef(90,0,1,0);
			glScalef(0.5,0.5,25);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 1
		{
			glTranslatef(0,-15,-35);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 2
		{
			glTranslatef(0,-15,-35);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 3
		{
			glTranslatef(0,-15,-35);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 4
		{
			glTranslatef(0,-15,-35);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();
	}
	glPopMatrix();



	glPushMatrix(); //cascade
	{
		  //transparence
		glEnable(GL_BLEND); 
	  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glTranslatef(0,-18,17);
		glScalef(15,0.5,10);
		glColor4f(0.25,0.41,0.88,0.5);
		glutSolidCube(3.0);
		glEnd();
	}
	glPopMatrix();



glFlush();

glClearColor(0.53, 0.8, 0.92, 0.8);



  axes();
  glutSwapBuffers();
  
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}