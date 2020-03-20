// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

//gcc main.c actions.c axes.o init.c lumiere.o switch_blend.o  switch_light.o VM_init.c -lm -lGL -lGLU -no-pie -lglut -o test; ./test

//skybox
#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <math.h>
#include "ppm.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


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
GLfloat angle_oiseau_vertical = 0;
GLfloat angle_aile = 0;

GLfloat angle_queue_principale = 0;
GLfloat angle_queue_secondaire = 0;

int montee0_descente1_oiseaux_secondaire = 0;

int montee0_descente1 = 0;
int montee0_descente1_tete_principal = 0;
int montee0_descente1_tete_secondaire = 0;

int montee0_descente1_queue_principale = 0;
int montee0_descente1_queue_secondaire = 0;


GLfloat position_x = 0;
GLfloat position_y = -3;
GLfloat position_z = 0;

GLfloat position_x_beta = -7;
GLfloat position_y_beta = 7.5;
GLfloat position_z_beta = -17;


GLfloat angle_oiseau_beta = 0;
GLfloat angle_oiseau_vertical_beta = 0;


GLfloat angle_tete_principal = 0;
GLfloat angle_tete_secondaire = 0;


float ambientLightDefault[] = { 0.1f, 0.1f, 0.1f, 0.1f };
float mipuissance[] = { 0.75f, 0.75f, 0.75f, 0.75f };

GLfloat position[] = {0.0, 5.0, -15.0, 1.0};
GLfloat direction[] = {-50.0,40.0, -40.0, 0.0};
GLfloat jaune[4] = { 1.0, 0.84, 0.0, 1.0 };


int lumiere_lampadaire = 0;
int lumiere_spot = 0;

float couleur_ampoule = 0.3;
float couleur_astre_y = 1;
float couleur_astre_z = 1;

float couleur_ciel_x = 0.09;
float couleur_ciel_y = 0.09;
float couleur_ciel_z = 0.43;

int position_nuage = 0;

float augmentation_position_y__oiseau_secondaire = 0.5;



GLvoid Modelisation()
{
  VM_init();     

  glEnable(GL_LIGHTING);
  glEnable(GL_COLOR_MATERIAL);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, mipuissance);


	if(lumiere_lampadaire == 1)
	{
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, position);
  // printf("postion x : %f\n", position[0]);
  // printf("postion y : %f\n", position[1]);
  // printf("postion z : %f\n", position[3]);

  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
 // glLightfv(GL_LIGHT0, GL_DIFFUSE, mipuissance);
  //glLightfv(GL_LIGHT0, GL_SPECULAR, mipuissance);
  glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.0);
	glShadeModel(GL_SMOOTH);

	}
	else if (lumiere_lampadaire == 0)
	{
		glDisable(GL_LIGHT0);
	}




  	glPushMatrix(); // OISEAU ACTEUR
  	{
  		//lumiere




		//float dir_length = sqrt(position_x * position_x + position_y * position_y + position_z * position_z);

		// position_x /=dir_length;
		// position_y /= dir_length;
		// position_z /= dir_length;
  		printf("position_x %f\n", position_x);
  		printf("position_z %f\n", position_z);


	  	//transparence
		glEnable(GL_BLEND); 
	  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	  	//rotation
		glTranslatef(2,2,2);
		glTranslatef(position_x,position_y,position_z);

		// printf("position x : %f\n", position_x);
		// printf("angle_triangle : %f\n", angle_triangle);
		// printf("position z : %f\n", position_z);
		// printf("angle oiseau vertical : %f\n", angle_oiseau_vertical);

		glRotatef(angle_triangle , 0, 1, 0);
		glRotatef(angle_oiseau_vertical, 0, 0, 1);


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
				glRotatef(angle_tete_principal, 0,0,1);
			//	angle_tete += 1;

				glColor3f(0.22,0.3,0.47);
				glScalef(1,0.5,0.5);
				glutSolidSphere(1,25,25);
				glEnd();

				glPushMatrix(); //oeil droite
				{
					glTranslatef(1,0.2,0.2);			  
					glColor3f(1,1,1);
					glScalef(0.5,1,1);
					glutSolidSphere(0.12, 25, 25);
					glEnd();


					glPushMatrix(); //pupille droite
					{
						 glTranslatef(0.15,0,0);			  
						glColor3f(0,0,0);
						glScalef(1,1,0.5);
						glutSolidSphere(0.08, 25, 25);
						glEnd();

					}
					glPopMatrix();
				  
				}
				glPopMatrix();



				  
				  
				glPushMatrix(); //oeil gauche
				{
					glTranslatef(1,0.2,-0.2);			  
					glColor3f(1,1,1);
					glScalef(0.5,1,1);
					glutSolidSphere(0.12, 25, 25);
					glEnd();

				
					glPushMatrix(); //pupille gauche
					{
						 glTranslatef(0.15,0,0);			  
						glColor3f(0,0,0);
						glScalef(1,1,0.5);
						glutSolidSphere(0.08, 25, 25);
						glEnd();

					}
					glPopMatrix();
				}
				glPopMatrix();
				


				glPushMatrix(); //bec
				{
					glTranslatef(3.5,0,0);
					glScalef(5.5,0.2,0.2);
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
		
		
		
		// glPushMatrix(); //oeil droite
		// {
		// 	glTranslatef(2.8,0.2,0.2);			  
		// 	glColor3f(1,1,1);
		// 	glScalef(0.5,1,1);
		// 	glutSolidSphere(0.12, 25, 25);
		// 	glEnd();

		// }
		// glPopMatrix();


		// glPushMatrix(); //pupille droite
		// {
		// 	glTranslatef(2.82,0.2,0.2);			  
		// 	glColor3f(0,0,0);
		// 	glScalef(1,1,0.5);
		// 	glutSolidSphere(0.08, 25, 25);
		// 	glEnd();

		// }
		// glPopMatrix();
		  
		  
		  
		// glPushMatrix(); //oeil gauche
		// {
		// 	glTranslatef(2.8,0.2,-0.2);			  
		// 	glColor3f(1,1,1);
		// 	glScalef(0.5,1,1);
		// 	glutSolidSphere(0.12, 25, 25);
		// 	glEnd();

		// }
		// glPopMatrix();
		
		
		
		// glPushMatrix(); //pupille gauche
		// {
		// 	glTranslatef(2.82,0.2,-0.2);			  
		// 	glColor3f(0,0,0);
		// 	glScalef(1,1,0.5);
		// 	glutSolidSphere(0.08, 25, 25);
		// 	glEnd();

		// }
		// glPopMatrix();
		
		
		
		glPushMatrix(); //aile droite
		{				
			if (montee0_descente1 == 0)
			{
				glRotatef(-angle_aile, 1,0,0);
				angle_aile = angle_aile +2;
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
				angle_aile = angle_aile -2;
				if (angle_aile == -16)
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
				angle_aile = angle_aile +2;
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
				angle_aile = angle_aile -2;
				if (angle_aile == -16)
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
			glRotatef(angle_queue_principale, 0,0,1);
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

		// glPushMatrix(); //bec
		// {
		// 	glTranslatef(3.5,0,0);
		// 	glScalef(5.5,0.2,0.2);
		// 	glColor3f(0.41,0.41,0.41);
		// 	glBegin( GL_TRIANGLES ); 
		// 		glVertex3f( 0.0f, 1.f, 0.0f );
		// 		glVertex3f( -1.0f, -1.0f, 1.0f );
		// 		glVertex3f( 1.0f, -1.0f, 1.0f);

		// 		glVertex3f( 0.0f, 1.0f, 0.0f);
		// 		glVertex3f( -1.0f, -1.0f, 1.0f);
		// 		glVertex3f( 0.0f, -1.0f, -1.0f);

		// 		glVertex3f( 0.0f, 1.0f, 0.0f);
		// 		glVertex3f( 0.0f, -1.0f, -1.0f);
		// 		glVertex3f( 1.0f, -1.0f, 1.0f);

		// 		glVertex3f( -1.0f, -1.0f, 1.0f);
		// 		glVertex3f( 0.0f, -1.0f, -1.0f);
		// 		glVertex3f( 1.0f, -1.0f, 1.0f);
		// 	glEnd();
		// }
		// glPopMatrix();
	}
	glPopMatrix();


	glPushMatrix(); // OISEAU SECONDAIRE
  	{
  		//lumiere

		float dir_length = sqrt(position_x * position_x + position_y * position_y + position_z * position_z);


	  	//transparence
		glEnable(GL_BLEND); 
	  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	  	//rotation
		//glRotatef(angle_oiseau_beta , 0, 1, 0);
		//glRotatef(angle_oiseau_vertical_beta, 0, 0, 1);
		glTranslatef(2,2,2);
	  //	glRotatef(-90, 0,1,0);


	//	printf("position y beta %f\n", position_y_beta);
	//	printf("montee0_descente1_oiseaux_secondaire %i\n", montee0_descente1_oiseaux_secondaire);
		if(montee0_descente1_oiseaux_secondaire == 0) //on monte
		{
			glTranslatef(position_x_beta,position_y_beta,position_z_beta);
			glRotatef(-90,0,1,0);

			position_y_beta += augmentation_position_y__oiseau_secondaire;
			if (position_y_beta >= 25)
			{
				augmentation_position_y__oiseau_secondaire = 0;
				if(angle_oiseau_beta != 360)
				{
					angle_oiseau_beta += 4;
					glRotatef(angle_oiseau_beta, 0,1,0);

				}
				if(angle_oiseau_beta == 360)
				{
					angle_oiseau_beta = 0;
					augmentation_position_y__oiseau_secondaire = 0.5;
					montee0_descente1_oiseaux_secondaire = 1;

				}
			}
		}
		else // on descend
		{
			glTranslatef(position_x_beta,position_y_beta,position_z_beta);
			glRotatef(-90,0,1,0);
			position_y_beta -= 0.5;
			if (position_y_beta == 7.5)
			{
				montee0_descente1_oiseaux_secondaire = 0;
			}
		}



		glPushMatrix(); //corps
		{
			glColor3f(0.2,0.6,0.8);
			glScalef(2,1,1);
			glutSolidSphere(1,25,25);
			glEnd();
		}
		glPopMatrix();
		
		
		
		glPushMatrix(); //tete
		{
			if(montee0_descente1_tete_secondaire == 1)
			{
				glTranslatef(2,0,0);
				glRotatef(angle_tete_secondaire, 0,0,1);
				angle_tete_secondaire += 1;
				if(angle_tete_secondaire == 20)
				{
					montee0_descente1_tete_secondaire = 0;
				}
				glColor3f(0.22,0.3,0.47);
				glScalef(1,0.5,0.5);
				glutSolidSphere(1,25,25);
				glEnd();

				glPushMatrix(); //oeil droite
				{
					glTranslatef(1,0.2,0.2);			  
					glColor3f(1,1,1);
					glScalef(0.5,1,1);
					glutSolidSphere(0.12, 25, 25);
					glEnd();


					glPushMatrix(); //pupille droite
					{
						 glTranslatef(0.15,0,0);			  
						glColor3f(0,0,0);
						glScalef(1,1,0.5);
						glutSolidSphere(0.08, 25, 25);
						glEnd();

					}
					glPopMatrix();
				  
				}
				glPopMatrix();



				  
				  
				glPushMatrix(); //oeil gauche
				{
					glTranslatef(1,0.2,-0.2);			  
					glColor3f(1,1,1);
					glScalef(0.5,1,1);
					glutSolidSphere(0.12, 25, 25);
					glEnd();

				
					glPushMatrix(); //pupille gauche
					{
						 glTranslatef(0.15,0,0);			  
						glColor3f(0,0,0);
						glScalef(1,1,0.5);
						glutSolidSphere(0.08, 25, 25);
						glEnd();

					}
					glPopMatrix();
				}
				glPopMatrix();
				


				glPushMatrix(); //bec
				{
					glTranslatef(3.5,0,0);
					glScalef(5.5,0.2,0.2);
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

			else
			{
				glTranslatef(2,0,0);
				glRotatef(angle_tete_secondaire, 0,0,1);
				angle_tete_secondaire -= 1;
				if(angle_tete_secondaire == -10)
				{
					montee0_descente1_tete_secondaire = 1;
				}
				glColor3f(0.22,0.3,0.47);
				glScalef(1,0.5,0.5);
				glutSolidSphere(1,25,25);
				glEnd();		


				glPushMatrix(); //oeil droite
				{
					glTranslatef(1,0.2,0.2);			  
					glColor3f(1,1,1);
					glScalef(0.5,1,1);
					glutSolidSphere(0.12, 25, 25);
					glEnd();


					glPushMatrix(); //pupille droite
					{
						 glTranslatef(0.15,0,0);			  
						glColor3f(0,0,0);
						glScalef(1,1,0.5);
						glutSolidSphere(0.08, 25, 25);
						glEnd();

					}
					glPopMatrix();
				  
				}
				glPopMatrix();
				  
				  
				glPushMatrix(); //oeil gauche
				{
					glTranslatef(1,0.2,-0.2);			  
					glColor3f(1,1,1);
					glScalef(0.5,1,1);
					glutSolidSphere(0.12, 25, 25);
					glEnd();

				
					glPushMatrix(); //pupille gauche
					{
						glTranslatef(0.15,0,0);			  
						glColor3f(0,0,0);
						glScalef(1,1,0.5);
						glutSolidSphere(0.08, 25, 25);
						glEnd();

					}
					glPopMatrix();
				}
				glPopMatrix();


				glPushMatrix(); //bec
				{
					glTranslatef(3.5,0,0);
					glScalef(5.5,0.2,0.2);
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

		}
		glPopMatrix();
		
		
		
		glPushMatrix(); //aile droite
		{				
			if (montee0_descente1 == 0)
			{
				glRotatef(-angle_aile, 1,0,0);
				angle_aile = angle_aile +2;
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
				angle_aile = angle_aile -2;
				if (angle_aile == -16)
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
				angle_aile = angle_aile +2;
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
				angle_aile = angle_aile -2;
				if (angle_aile == -16)
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
			if(montee0_descente1_queue_secondaire == 1)
			{
				glTranslatef(-2,-0.5,0);
				glRotatef(angle_queue_secondaire, 0, 0, 1);
				angle_queue_secondaire += 1;
				if(angle_queue_secondaire == 20)
				{
					montee0_descente1_queue_secondaire = 0;
				}
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
			else
			{
				glTranslatef(-2,-0.5,0);
				glRotatef(angle_queue_secondaire, 0, 0, 1);
				angle_queue_secondaire -= 1;
				if(angle_queue_secondaire == -15)
				{
					montee0_descente1_queue_secondaire = 1;
				}
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



	glPushMatrix(); //rocher
	{
		glTranslatef(-10,0,-5);
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

	glPushMatrix();	//cascade
	{
		glPushMatrix(); //amont
		{
			  //transparence
			glEnable(GL_BLEND); 
		  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glTranslatef(0,-18,17);
			glScalef(20,1,15);
			glColor4f(0.25,0.41,0.88,0.5);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //descente
		{
			  //transparence
			glEnable(GL_BLEND); 
		  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glTranslatef(0,-39,40);
			glScalef(20,15,1.5);
			glColor4f(0.25,0.41,0.88,0.5);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();
	}
	glPopMatrix();


	glPushMatrix(); //lampadaire
	{
		glPushMatrix(); //poteau
		{
			glTranslatef(-10, -17, -15);
			glScalef(1,50,1);
			glColor3f(0.75,0.75,0.75);
			glutSolidCube(1.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //barre horizontale
		{
			glTranslatef(-5.5, 8, -15);
			glScalef(10,1,1);
			glColor3f(0.75,0.75,0.75);
			glutSolidCube(1.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //baton vertical
		{
			glTranslatef(0, 7, -15);
			glScalef(1,3,1);
			glColor3f(0.75,0.75,0.75);
			glutSolidCube(1.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //ampoule/lumiere
		{

			glTranslatef(0, 4.5, -15);
			glScalef(1,1,1);
			glColor4f(couleur_ampoule,couleur_ampoule,couleur_ampoule, couleur_ampoule);
			glutSolidCube(2.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //lampion
		{
			glTranslatef(0, 5, -15);
			glScalef(1,1,1);
			glColor4f(0.82,0.82,0.82,0.25);
			glutSolidCube(4.0);
			glEnd();
		}
		glPopMatrix();

	}


	glPushMatrix(); //soleil
	{
		if(lumiere_spot == 1)
		{
			  glEnable(GL_LIGHT1);
			 // glLightfv(GL_LIGHT1, GL_AMBIENT, jaune);
			  glLightfv(GL_LIGHT1, GL_DIFFUSE, jaune);
			  glLightfv(GL_LIGHT1, GL_SPECULAR, jaune);
			  glLightfv(GL_LIGHT1, GL_POSITION, direction);
			  // printf("postion x : %f\n", position[0]);
			  // printf("postion y : %f\n", position[1]);
			  // printf("postion z : %f\n", position[3]);

			  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
			 // glLightfv(GL_LIGHT0, GL_DIFFUSE, mipuissance);
			  //glLightfv(GL_LIGHT0, GL_SPECULAR, mipuissance);
			  glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 2.0);
				glShadeModel(GL_SMOOTH);

		}
		else
		{
			glDisable(GL_LIGHT1);
		}


		glEnable(GL_DEPTH_TEST);
		glTranslatef(-50,40,-40);
		glScalef(4,4,4);
		glColor3f(1.0,couleur_astre_y, couleur_astre_z);
		glutSolidSphere(4.0, 200, 200);
	}


	glPopMatrix();

	glPushMatrix(); //cube
	{
		// writePpm("damier.ppm", rgb2rgba(readPpm("Damier.ppm")));

		glTranslatef(0,-10,-12);
		glColor3f(1,1,1);
		glutSolidCube(5.0);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //nuage1
	{
		glTranslatef(position_nuage - 300,33,-20);
		position_nuage = position_nuage%400 + 1;
		glScalef(10,1,5);
		glColor4f(1,1,1,0.5);
		glutSolidCube(5.0);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //nuage2
	{
		glTranslatef(position_nuage -260,30,-30);
		position_nuage = position_nuage%400 + 1;
		glScalef(10,1,5);
		glColor4f(1,1,1, 0.5);
		glutSolidCube(5.0);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //nuage3
	{
		glTranslatef(position_nuage  - 150 ,40,-35);
		position_nuage = position_nuage%400 + 1;
		glScalef(10,1,5);
		glColor4f(1,1,1, 0.5);
		glutSolidCube(5.0);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //nuage4
	{
		glTranslatef(position_nuage - 200,45,-25);
		position_nuage = position_nuage%400 + 1;
		glScalef(10,1,5);
		glColor4f(1,1,1, 0.5);
		glutSolidCube(5.0);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //nuage5
	{
		glTranslatef(position_nuage - 100,40,-30);
		position_nuage = position_nuage%400 + 1;
		glScalef(10,1,5);
		glColor4f(1,1,1, 0.5);
		glutSolidCube(5.0);
		glEnd();
	}
	glPopMatrix();




	glPopMatrix();

glFlush();

glClearColor(couleur_ciel_x,couleur_ciel_y, couleur_ciel_z, 0.8);



  axes();
  glutSwapBuffers();
  
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
