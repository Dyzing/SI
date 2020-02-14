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
// 0 : avant, 1 : arriere, 2 : droit, 3 : gauche, 4 : dessus, 5 : dessous
static int faces[6][4] = {{0, 1, 2, 3},
						 {4, 5, 6, 7},
						 {1, 4, 7, 2},
						 {0, 3, 6, 5},
						 {2, 7, 6, 3},
						 {1, 0, 5, 4}};
						 
static int sommets[8][3] = {{0, 3, 5},
						   {0, 2, 5},
						   {0, 2, 4},
						   {0, 3, 4},
						   {1, 2, 5}, 
						   {1, 3, 5}, 
						   {1, 3, 4},
						   {1, 2, 4}};


struct cube1 {
	int tablo[8][3];						 
};

struct cube1 creer_cube(float taille)
{
	struct cube1 c;
	
	c.tablo[0][0] = -taille; //0
	c.tablo[0][1] = -taille;
	c.tablo[0][2] =  taille;
	
	c.tablo[1][0] = taille;  //1
	c.tablo[1][1] = -taille;
	c.tablo[1][2] =  taille;
	
	c.tablo[2][0] = taille;  //2
	c.tablo[2][1] = taille;
	c.tablo[2][2] = taille;
	
	c.tablo[3][0] = -taille; //3
	c.tablo[3][1] = taille;
	c.tablo[3][2] = taille;
	
	c.tablo[4][0] = taille;  //4
	c.tablo[4][1] = -taille;
	c.tablo[4][2] = -taille;
	
	c.tablo[5][0] = -taille; //5
	c.tablo[5][1] = -taille;
	c.tablo[5][2] = -taille;
	
	c.tablo[6][0] = -taille; //6
	c.tablo[6][1] = taille;
	c.tablo[6][2] = -taille;
	
	c.tablo[7][0] = taille;  //7
	c.tablo[7][1] = taille;
	c.tablo[7][2] = -taille;
	
	return c;	
}

void affiche_cube1(struct cube1 mon_cube)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    gluLookAt(3,4,2,0,0,0,0,0,1);

    glBegin(GL_QUADS);
    
    for (int i = 0; i < 6; i++) 
    {
		for (int j = 0; j < 4; j++)
		{
			glVertex3f(mon_cube.tablo[faces[i][j]][0], mon_cube.tablo[faces[i][j]][1], mon_cube.tablo[faces[i][j]][2]); 
		}
	}
	glEnd();
}
    
    	
	/*
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );

    gluLookAt(3,4,2,0,0,0,0,0,1);

    glBegin(GL_QUADS);

    glColor3ub(255,0,0); //face rouge
    glVertex3d(1,1,1);
    glVertex3d(1,1,-1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,1,1);

	glColor3ub(0,255,0); //face verte
    glVertex3d(1,-1,1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,1,-1);
    glVertex3d(1,1,1);
    
	glColor3ub(0,0,255); //face bleue
    glVertex3d(-1,-1,1);
    glVertex3d(-1,-1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,-1,1);

    glColor3ub(255,255,0); //face jaune
    glVertex3d(-1,1,1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,-1,1);

    glColor3ub(0,255,255); //face cyan
    glVertex3d(1,1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,1,-1);

    glColor3ub(255,0,255); //face magenta
    glVertex3d(1,-1,1);
    glVertex3d(1,1,1);
    glVertex3d(-1,1,1);
    glVertex3d(-1,-1,1);
    
    glEnd();
    
    glFlush();
    glutSwapBuffers();
    
    */

	


GLvoid Modelisation()
{
  VM_init();
  	glEnable(GL_DEPTH_TEST);
	
  // Entre glPushMatrix et glPopMatrix s'écrit la description de la scène.
/*
	glPushMatrix();
	{
		glRotatef(angle_triangle, 0, 1, 0);
		angle_triangle = angle_triangle+1;
		glBegin(GL_TRIANGLES);
			glVertex3f(0.0, 2.0, 0.0);
			glVertex3f(1.0, -1.0, 0.0);
			glVertex3f(-1.0, -1.0, 0.0);
		glEnd();
	
	}
	glPopMatrix();

	printf ("%f \n",GLUT_ELAPSED_TIME) ;
	* */
/*
 

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

*/
	affiche_cube1(creer_cube(1));

	
glClearColor(0.5, 0.5, 1, 0.8);



  axes();
  glutSwapBuffers();
  
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
