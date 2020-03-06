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
float mipuissance[] = { 1.0f, 1.0f, 1.0f, 1.0f };

/*  0 : avant,
 *  1 : arriere,
 *  2 : droit,
 *  3 : gauche,
 *  4 : dessus,
 *  5 : dessous */
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
//    int k = 0;
    glBegin(GL_QUADS);
    
    for (int i = 0; i < 6; i++) //transparence
    {
		if ((i != 1) && (i != 5))
		{	
			for (int j = 0; j < 4; j++)
			{

//					k = i/(j+1);
					glVertex3f(mon_cube.tablo[faces[i][j]][0], mon_cube.tablo[faces[i][j]][1], mon_cube.tablo[faces[i][j]][2]); 
					glColor4f(1,1,1,0.5);
			}
		}
	}
	
	int l = 0;
    while((l < 6)) //opacité
    {
		if ((l == 1) || (l == 5))
		{
			for (int j = 0; j < 4; j++)
			{
//				k = l/(j+1);
				if (l == 1)
					glColor3f(0,1,0);
				else
					glColor3f(0,1,1);
				glVertex3f(mon_cube.tablo[faces[l][j]][0], mon_cube.tablo[faces[l][j]][1], mon_cube.tablo[faces[l][j]][2]); 

			}
			
        }
        l++;        
	}
	glEnd();
}
    


GLvoid Modelisation()
{
  VM_init();
  
  glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLightDefault);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, mipuissance);
  glLightfv(GL_LIGHT0, GL_SPECULAR, mipuissance);
				  
				  
  glPushMatrix();
  {
  	glEnable(GL_DEPTH_TEST);
	
	
	                  glRotatef(angle_triangle, 0, 1, 0);
                  angle_triangle = angle_triangle+1;

                  glColor3f(1,1,0);
                  glRotatef(xrot, 1,0,0);
				  glRotatef(yrot, 0, 1, 0);

	affiche_cube1(creer_cube(1));

  }
  glPopMatrix();
  
//  glBlendEquation((0.25,0.75,0.75);
	glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
  /*PETITE boule droite */
            glPushMatrix();
          {
                  glTranslatef(1,0,0);			  
                  glRotatef(angle_triangle, 0, 1, 0);
                  angle_triangle = angle_triangle+1;

                  glColor3f(1,0,1);
                  glRotatef(xrot, 1,0,0);
				  glRotatef(yrot, 0, 1, 0);
                  glutSolidSphere(0.5, 25, 25);
                  glEnd();

          }
          glPopMatrix();
          
  /*PETITE boule gauche */        
                      glPushMatrix();
          {
                  glTranslatef(-1,0,0);			  
                  glRotatef(angle_triangle, 0, 1, 0);
                  angle_triangle = angle_triangle+1;

                  glColor4f(1,0,0,0.5);
                  glRotatef(xrot, 1,0,0);
				  glRotatef(yrot, 0, 1, 0);
                  glutSolidSphere(0.5, 25, 25);
                  glEnd();

          }
          glPopMatrix();
          
          
            /*GROSSE boule droite */        
                      glPushMatrix();
          {
                  glTranslatef(3,0,0);			  
                  glRotatef(angle_triangle, 0, 1, 0);
                  angle_triangle = angle_triangle+1;

                  glColor3f(1,1,0);
                  glRotatef(xrot, 1,0,0);
				  glRotatef(yrot, 0, 1, 0);
                  glutSolidSphere(1, 25, 25);
                  glEnd();

          }
          glPopMatrix();
          
	            
            /*GROSSE boule gauche */        
                      glPushMatrix();
          {
                  glTranslatef(-3,0,0);			  
                  glRotatef(angle_triangle, 0, 1, 0);
                  angle_triangle = angle_triangle+1;

                  glColor4f(0,0,1,0.5);
                  glRotatef(xrot, 1,0,0);
				  glRotatef(yrot, 0, 1, 0);
                  glutSolidSphere(1, 25, 25);
                  glEnd();

          }
          glPopMatrix();

glClearColor(0, 0, 0, 0.8);



  axes();
  glutSwapBuffers();
  
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
