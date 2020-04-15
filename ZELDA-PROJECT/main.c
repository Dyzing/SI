	// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

//gcc main.c actions.c axes.o init.c lumiere.o switch_blend.o  switch_light.o VM_init.c -lm -lGL -lGLU -no-pie -lglut -o test; ./test

//skybox
#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

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
GLfloat angle_oiseau_vertical_secondaire = 0;
GLfloat angle_aile = 0;

GLfloat angle_queue_principale = 0;
GLfloat angle_queue_secondaire = 0;

int montee0_descente1_oiseaux_secondaire = 0;

int montee0_descente1 = 0;
int montee0_descente1_tete_principal = 0;
int montee0_descente1_tete_secondaire = 0;

int montee0_descente1_queue_principale = 1;
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

int position_nuage = 0.5;

float augmentation_position_y__oiseau_secondaire = 0.5;

GLfloat angle_rocher = 1.0;

GLfloat position_y_rocher = 89.0;
GLfloat position_z_rocher = -130.0;

GLfloat position_y_rocher_gauche = 149.0;
GLfloat position_z_rocher_gauche = -190.0;

GLfloat position_y_rocher_droite = 179.0;
GLfloat position_z_rocher_droite = -220.0;


int aleatoire = 1;
int aleatoire_arbre = 1;

void creer_sakura(int x, int y, int z)
{
		glPushMatrix(); //arbre sakura glColor3f(1,0.71,0.75);
	{
		glPushMatrix();
		{
			glTranslatef(x,y,z);
			glScalef(5,20,5);
			glColor3f(0.24,0.08,0.03);
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

		glPushMatrix();
		{
			glTranslatef(x,y+15,z);
			glScalef(3,3,3);
			glColor3f(1,0.71,0.75);
			glutSolidSphere(5, 8,8);
		}
		glPopMatrix();

	}
	glPopMatrix();
}

void creer_arbre_lambda(int x, int y, int z)
{
		glPushMatrix(); //arbre lambda
	{
			glPushMatrix();
			{
				glTranslatef(x,y,z);
				glScalef(5,20,5);
				glColor3f(0.74,0.38,0.18);
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

			glPushMatrix();
			{
				glTranslatef(x,y+15,z);
				glScalef(3,3,3);
				glColor3f(0.18,0.54,0.34);
				glutSolidSphere(5, 8,8);
			}
			glPopMatrix();

	}
	glPopMatrix();

}


void creer_sapin(int x, int y, int z)
{
		glPushMatrix(); //arbre sapin
	{
		glPushMatrix();
		{
			glTranslatef(x,y,z);
			glScalef(5,20,5);
			glColor3f(0.34,0.16,0.06);
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

		glPushMatrix();
		{
			glTranslatef(x,y+15,z);
			glScalef(9,20,9);
			glColor3f(0,0.39,0);
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
}

//srand(time(NULL));

int i_arbre = -1;
int compteur_arbre_x;
int compteur_arbre_z;

void arbre_partout()
{
	int ligne = 0;
	for(compteur_arbre_x = 0; compteur_arbre_x < 5; compteur_arbre_x++)
	{
		int espace = 40;
		int i = 1;
		for(compteur_arbre_z = 0; compteur_arbre_z < 5; compteur_arbre_z++)
		{
			creer_sakura(150*i + espace*i, 0, -100 + espace + ligne);
			creer_arbre_lambda(150*i + espace*i, 0, 50 + espace + ligne);
			creer_sapin(0*i + espace*i, 0, -500 + espace + ligne);
			creer_sakura(-40*i + espace*i, 0, -400 + espace + ligne);
			creer_arbre_lambda(180*i + espace*i, 0, -250 + espace + ligne);
			creer_sapin(280*i + espace*i, 0, -335 + espace + ligne);
			creer_sakura(253*i + espace*i, 0, 180 + espace + ligne);
			creer_sapin(115*i + espace*i, 0, 190 + espace + ligne);

			i = -i;
			espace += 40;
		}
		ligne += 50;
	}

}


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

  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.0);
	glShadeModel(GL_FLAT);

	}
	else if (lumiere_lampadaire == 0)
	{
		glDisable(GL_LIGHT0);
	}




  	glPushMatrix(); // OISEAU ACTEUR
  	{

	  	//transparence
		glEnable(GL_BLEND); 
	  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	  	//rotation
		glTranslatef(2,2,2);
		glTranslatef(position_x,position_y,position_z);

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
					angle_oiseau_vertical_secondaire += 4;
					glRotatef(angle_oiseau_vertical_secondaire, 0, 0, 1);
					glRotatef(angle_oiseau_beta, 0,1,0);
				}
				if(angle_oiseau_beta == 360)
				{
					angle_oiseau_beta = 0;
					angle_oiseau_vertical_secondaire = 0;
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
		glScalef(500,1,400);
		glColor3f(0.43, 0.57, 0);
		glutSolidCube(3.0);
		glEnd();
	}
	glPopMatrix();



	glPushMatrix(); //plage
	{
		glTranslatef(0,-80,1045);
		glRotatef(7.5, 1,0,0);
		glScalef(500,1,300);
		glColor3f(0.94, 0.90, 0.54);
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
		GLUquadric* cone = gluNewQuadric();
    	gluQuadricTexture(cone,GL_TRUE); 
	    gluCylinder(cone,0.5,0,1.6,20,1); 
        gluDeleteQuadric(cone); 
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

			glTranslatef(0,-18,300);
			glScalef(20,1,200);
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

			glTranslatef(0,-28,674);
			glRotatef(7.5,1,0,0);
			glScalef(20,1,50);
			glColor4f(0.25,0.41,0.88,0.5);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mer
		{
			  //transparence
			glEnable(GL_BLEND); 
		  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glTranslatef(0,-36,950);
			glScalef(500,1,300);
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


	glPushMatrix(); //astres
	{
		if(lumiere_spot == 1)
		{
			  glEnable(GL_LIGHT1);
			  glLightfv(GL_LIGHT1, GL_DIFFUSE, jaune);
			  glLightfv(GL_LIGHT1, GL_SPECULAR, jaune);
			  glLightfv(GL_LIGHT1, GL_POSITION, direction);

			  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
			  glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 2.0);
				glShadeModel(GL_SMOOTH);

		}
		else
		{
			glDisable(GL_LIGHT1);
		}

		glEnable(GL_DEPTH_TEST);
		glTranslatef(-50,200,-40);
		glScalef(6,6,6);
		glColor3f(1.0,couleur_astre_y, couleur_astre_z);
		glutSolidSphere(4.0, 200, 200);
	}
	glPopMatrix();

	glPushMatrix(); // Les nuages
	{
		int compteur;
   		srand(time(NULL));

		for(compteur = 0; compteur < 10; compteur++)
		{
			if(position_nuage >= 1999)
			{
				srand(time(NULL));
				aleatoire = (rand() % 2) +1;

				glTranslatef(-100, 30 + aleatoire, 300 + aleatoire);


			

				glPushMatrix(); //nuage1
				{
					glTranslatef(position_nuage - 300 -( compteur * 50),33,-20);
					position_nuage = position_nuage%2000 + 1;
					glScalef(10,1,5);
					glColor4f(1,1,1,0.5);
					glutSolidCube(5.0);
					glEnd();
				}
				glPopMatrix();



		
				glPushMatrix(); //nuage2
				{
					glTranslatef(position_nuage -260  -( compteur * 50),30,-30);
					position_nuage = position_nuage%2000 + 0.05;
					glScalef(10,1,5);
					glColor4f(1,1,1, 0.5);
					glutSolidCube(5.0);
					glEnd();
				}
				glPopMatrix();
		
		
				glPushMatrix(); //nuage3
				{
					glTranslatef(position_nuage  - 150 -( compteur * 50) ,40,-35);
					position_nuage = position_nuage%2000 + 0.05;
					glScalef(10,1,5);
					glColor4f(1,1,1, 0.5);
					glutSolidCube(5.0);
					glEnd();
				}
				glPopMatrix();
		
		
				glPushMatrix(); //nuage4
				{
					glTranslatef(position_nuage - 200 -( compteur * 50),45,-25);
					position_nuage = position_nuage%2000 + 0.05;
					glScalef(10,1,5);
					glColor4f(1,1,1, 0.5);
					glutSolidCube(5.0);
					glEnd();
				}
				glPopMatrix();


		
				glPushMatrix(); //nuage5
				{
					glTranslatef(position_nuage - 100 -( compteur * 50),40,-30);
					position_nuage = position_nuage%2000 + 0.05;
					glScalef(10,1,5);
					glColor4f(1,1,1, 0.5);
					glutSolidCube(5.0);
					glEnd();
				}
				glPopMatrix();


			}	
			else
			{


				glTranslatef(-100, 15 + aleatoire,  aleatoire* 100);


				glPushMatrix(); //nuage1
				{
					glTranslatef(position_nuage - 300 -( compteur * 50),33,-20);
					position_nuage = position_nuage%2000 + 1;
					glScalef(10,1,5);
					glColor4f(1,1,1,0.5);
					glutSolidCube(5.0);
					glEnd();
				}
				glPopMatrix();

		
				glPushMatrix(); //nuage2
				{
					glTranslatef(position_nuage -260 -( compteur * 50),30,-30);
					position_nuage = position_nuage%2000 + 0.05;
					glScalef(10,1,5);
					glColor4f(1,1,1, 0.5);
					glutSolidCube(5.0);
					glEnd();
				}
				glPopMatrix();
		
		
				glPushMatrix(); //nuage3
				{
					glTranslatef(position_nuage  - 150  -( compteur * 50),40,-35);
					position_nuage = position_nuage%2000 + 0.05;
					glScalef(10,1,5);
					glColor4f(1,1,1, 0.5);
					glutSolidCube(5.0);
					glEnd();
				}
				glPopMatrix();

		
				glPushMatrix(); //nuage4
				{
					glTranslatef(position_nuage - 200 -( compteur * 50),45,-25);
					position_nuage = position_nuage%2000 + 0.05;
					glScalef(10,1,5);
					glColor4f(1,1,1, 0.5);
					glutSolidCube(5.0);
					glEnd();
				}
				glPopMatrix();
		
		
				glPushMatrix(); //nuage5
				{
					glTranslatef(position_nuage - 100 -( compteur * 50),40,-30);
					position_nuage = position_nuage%2000 + 0.05;
					glScalef(10,1,5);
					glColor4f(1,1,1, 0.5);
					glutSolidCube(5.0);
					glEnd();
				}
				glPopMatrix();

			}
		}	
	}
	glPopMatrix();



	glPushMatrix(); //rocher mileux
	{
		glTranslatef(0,position_y_rocher,position_z_rocher);
		glRotatef(angle_rocher, 1,0,0);
		angle_rocher += 5;
		position_y_rocher -= 0.5;
		position_z_rocher += 0.5;
		if ((position_y_rocher <= -20) && (position_z_rocher >= 0))
		{
			position_y_rocher = 89;
			position_z_rocher = -130;
		}
		glColor3f(0.54,0.27,0.07);
		glScalef(1,1,1);
		glutSolidSphere(10,7,7);
		glEnd();
	}
	glPopMatrix();





	glPushMatrix(); //rocher gauche
	{
		glTranslatef(-20,position_y_rocher_gauche,position_z_rocher_gauche);
		glRotatef(angle_rocher, 1,0,0);
		angle_rocher += 5;
		position_y_rocher_gauche -= 0.5;
		position_z_rocher_gauche += 0.5;
		if ((position_y_rocher_gauche <= -20) && (position_z_rocher_gauche  >= 0))
		{
			position_y_rocher_gauche = 149;
			position_z_rocher_gauche = -190;
		}
		glColor3f(0.54,0.27,0.07);
		glScalef(1,1,1);
		glutSolidSphere(10,7,7);
		glEnd();
	}
	glPopMatrix();




	glPushMatrix(); //rocher droite
	{
		glTranslatef(+20,position_y_rocher_droite,position_z_rocher_droite);
		glRotatef(angle_rocher, 1,0,0);
		angle_rocher += 5;
		position_y_rocher_droite -= 0.5;
		position_z_rocher_droite += 0.5;
		if ((position_y_rocher_droite <= -20) && (position_z_rocher_droite  >= 0))
		{
			position_y_rocher_droite = 179;
			position_z_rocher_droite = -220;
		}
		glColor3f(0.54,0.27,0.07);
		glScalef(1,1,1);
		glutSolidSphere(10,7,7);
		glEnd();
	}
	glPopMatrix();




	glPushMatrix(); //Maison droite 1
	{


		glTranslatef(120, 0, -50);
		glRotatef(-90,0,1,0);


		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor4f(0,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //toit gauche
		{		
			glTranslatef(78,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit gauche
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //face arrière toit
		{
			glTranslatef(101,27,-29);
			glRotatef(180,0,1,0);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //sol
		{		
			glTranslatef(101,-19.5,-8);
			glRotatef(90, 1,0,0);
			glScalef(8.5,6.7,0.4);
			glColor4f(1,0.5,0, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //mur de devant gauche
		{		
			glTranslatef(83,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,10,17);
			glScalef(1.9,2.5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


	}
	glPopMatrix();



	glPushMatrix(); //Maison gauche 1
	{

		glTranslatef(-120, 0, 100);
		glRotatef(90,0,1,0);




		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor4f(0,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //toit gauche
		{		
			glTranslatef(78,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit gauche
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //face arrière toit
		{
			glTranslatef(101,27,-29);
			glRotatef(180,0,1,0);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //sol
		{		
			glTranslatef(101,-19.5,-8);
			glRotatef(90, 1,0,0);
			glScalef(8.5,6.7,0.4);
			glColor4f(1,0.5,0, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //mur de devant gauche
		{		
			glTranslatef(83,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,10,17);
			glScalef(1.9,2.5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


	}
	glPopMatrix();



	glPushMatrix(); //Maison gauche 2
	{

		glTranslatef(-120, 0, 250);
		glRotatef(90,0,1,0);




		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor4f(0,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //toit gauche
		{		
			glTranslatef(78,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit gauche
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //face arrière toit
		{
			glTranslatef(101,27,-29);
			glRotatef(180,0,1,0);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //sol
		{		
			glTranslatef(101,-19.5,-8);
			glRotatef(90, 1,0,0);
			glScalef(8.5,6.7,0.4);
			glColor4f(1,0.5,0, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //mur de devant gauche
		{		
			glTranslatef(83,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,10,17);
			glScalef(1.9,2.5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


	}
	glPopMatrix();


	glPushMatrix(); //Maison gauche 3
	{

		glTranslatef(-120, 0, 400);
		glRotatef(90,0,1,0);




		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor4f(0,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //toit gauche
		{		
			glTranslatef(78,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit gauche
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //face arrière toit
		{
			glTranslatef(101,27,-29);
			glRotatef(180,0,1,0);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //sol
		{		
			glTranslatef(101,-19.5,-8);
			glRotatef(90, 1,0,0);
			glScalef(8.5,6.7,0.4);
			glColor4f(1,0.5,0, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //mur de devant gauche
		{		
			glTranslatef(83,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,10,17);
			glScalef(1.9,2.5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


	}
	glPopMatrix();

	glPushMatrix(); //Maison droite 2
	{

		glTranslatef(120, 0, 100);
		glRotatef(-90,0,1,0);




		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor4f(0,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //toit gauche
		{		
			glTranslatef(78,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit gauche
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //face arrière toit
		{
			glTranslatef(101,27,-29);
			glRotatef(180,0,1,0);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //sol
		{		
			glTranslatef(101,-19.5,-8);
			glRotatef(90, 1,0,0);
			glScalef(8.5,6.7,0.4);
			glColor4f(1,0.5,0, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //mur de devant gauche
		{		
			glTranslatef(83,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,10,17);
			glScalef(1.9,2.5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


	}
	glPopMatrix();


	glPushMatrix(); //Maison droite 3
	{

		glTranslatef(120, 0, 250);
		glRotatef(-90,0,1,0);




		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor4f(0,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //toit gauche
		{		
			glTranslatef(78,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit gauche
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor4f(0,1,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //face arrière toit
		{
			glTranslatef(101,27,-29);
			glRotatef(180,0,1,0);
			glScalef(32,8.4,1);
			glColor4f(0,0.41,0.41, 0.8);
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



		glPushMatrix(); //sol
		{		
			glTranslatef(101,-19.5,-8);
			glRotatef(90, 1,0,0);
			glScalef(8.5,6.7,0.4);
			glColor4f(1,0.5,0, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




		glPushMatrix(); //mur de devant gauche
		{		
			glTranslatef(83,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor4f(1,1,1, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,10,17);
			glScalef(1.9,2.5,0.4);
			glColor4f(0.5,0.5,0.5, 0.8);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor4f(0,0,0, 0.9);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


	}
	glPopMatrix();


	glPushMatrix(); //lampadaire maison gauche 1
	{
		glTranslatef(-100, 0, 100);


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
	glPopMatrix();

	glPushMatrix(); //lampadaire maison gauche 2
	{
		glTranslatef(-100, 0, 250);


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
	glPopMatrix();



	glPushMatrix(); //lampadaire maison gauche 3
	{
		glTranslatef(-100, 0, 400);


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
	glPopMatrix();


		glPushMatrix(); //lampadaire maison droite 1
	{
		glTranslatef(100, 0, 100);
		glRotatef(180, 0,1,0);

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
	glPopMatrix();


	glPushMatrix(); //lampadaire maison droite 2
	{
		glTranslatef(100, 0, 250);
		glRotatef(180, 0,1,0);

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
	glPopMatrix();


	glPushMatrix(); //lampadaire maison droite 3
	{
		glTranslatef(100, 0, 400);
		glRotatef(180, 0,1,0);

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
	glPopMatrix();



	glPushMatrix(); //collines de gauche
	{


		glPushMatrix(); //colline 1
		{
			glTranslatef(-600,-50, 200);
			glColor3f(0.54,0.27,0.07);
			glScalef(20,40,10);
			glutSolidSphere(10,5,5);
			glEnd();
		}
		glPopMatrix();
	
	
	
		glPushMatrix(); //colline 2
		{
			glTranslatef(-600,-50, 50);
			glColor3f(0.13,0.54,0.13);
			glScalef(20,30,10);
			glutSolidSphere(10,4,4);
			glEnd();
		}
		glPopMatrix();
	
	
	
		glPushMatrix(); //colline 3
		{
			glTranslatef(-650,-50, 375);
			glColor3f(0.13,0.54,0.13);
			glScalef(25,30,15);
			glutSolidSphere(10,8,8);
			glEnd();
		}
		glPopMatrix();
	
	
		glPushMatrix(); //colline 4
		{
			glTranslatef(-600,-50, -200);
			glColor3f(0.54,0.27,0.07);
			glRotatef(10,0,1,0);
			glScalef(25,35,20);
			glutSolidSphere(10,10,10);
			glEnd();
		}
		glPopMatrix();
	
	
		glPushMatrix(); //colline 5
		{
			glTranslatef(-300,-50, -400);
			glRotatef(30,0,1,0);
			glColor3f(0.7,0.7,0.7);
			glScalef(20,40,10);
			glutSolidSphere(10,8,8);
			glEnd();
		}
		glPopMatrix();
	}
	glPopMatrix();





	glPushMatrix(); //collines de droite
	{
		glTranslatef(1300, 0, 0);
		//glRotatef(180,0,0,1);

		glPushMatrix(); //colline 1
		{
			glTranslatef(-600,-50, 200);
			glColor3f(0.54,0.27,0.07);
			glScalef(20,40,10);
			glutSolidSphere(10,5,5);
			glEnd();
		}
		glPopMatrix();
	
	
	
		glPushMatrix(); //colline 2
		{
			glTranslatef(-600,-50, 50);
			glColor3f(0.13,0.54,0.13);
			glScalef(20,30,10);
			glutSolidSphere(10,4,4);
			glEnd();
		}
		glPopMatrix();
	
	
	
		glPushMatrix(); //colline 3
		{
			glTranslatef(-500,-50, 375);
			glColor3f(0.13,0.54,0.13);
			glScalef(25,30,15);
			glutSolidSphere(10,8,8);
			glEnd();
		}
		glPopMatrix();
	
	
		glPushMatrix(); //colline 4
		{
			glTranslatef(-600,-50, -200);
			glColor3f(0.54,0.27,0.07);
			glRotatef(10,0,1,0);
			glScalef(25,35,20);
			glutSolidSphere(10,10,10);
			glEnd();
		}
		glPopMatrix();
	

	}
	glPopMatrix();


		glPushMatrix(); //colline 5 de droite
		{
			glTranslatef(350,-50, -400);
			glRotatef(-30,0,1,0);
			glColor3f(0.7,0.7,0.7);
			glScalef(20,40,10);
			glutSolidSphere(10,8,8);
			glEnd();
		}
		glPopMatrix();


	glPushMatrix();
	{
		arbre_partout();
	}
	glPopMatrix();



	glPushMatrix(); //LINK
	{
		glPushMatrix(); //tete
		{
			glTranslatef(0,5,10);
			glScalef(1.3,1.2,1);
			glColor3f(0.94,0.90,0.649);
			glutSolidSphere(2.9,50,50);


			glPushMatrix(); //cheveux
			{
				glTranslatef(0,1,0);
				glScalef(1,1,0.8);
				glColor3f(0.98,0.93,0.13);
				glutSolidSphere(3,10,10);
				glEnd();



				glPushMatrix(); //meche gauche grosse
				{
					glTranslatef(-1,1.9,0);
					glScalef(2.5,1,1);
					glColor3f(0.98,0.93,0.13);
					glutSolidSphere(1,8,8);
					glEnd();
				}
				glPopMatrix();



				glPushMatrix(); //meche milieu grosse
				{
					glTranslatef(0,1,2.5);
					glRotatef(30,0,0,1);
					glRotatef(10,0,1,0);
					glScalef(2,1,1);
					glColor3f(0.98,0.93,0.13);
					glutSolidSphere(1,8,8);
					glEnd();
				}
				glPopMatrix();




				glPushMatrix(); //rouflaquette gauche
				{
					glTranslatef(-2.8,-0.6,0.3);
					glRotatef(-30, 1,0,0);
					glScalef(0.5,2.5,1);
					glColor3f(0.98,0.93,0.13);
					glutSolidSphere(0.75,7,7);
					glEnd();
				}
				glPopMatrix();



				glPushMatrix(); //rouflaquette droite
				{
					glTranslatef(2.8,-0.6,0.3);
					glRotatef(-30, 1,0,0);
					glScalef(0.5,2.5,1);
					glColor3f(0.98,0.93,0.13);
					glutSolidSphere(0.75,7,7);
					glEnd();
				}
				glPopMatrix();




			}
			glPopMatrix();



			glPushMatrix(); //oeil gauche
			{
				glTranslatef(-1,0,2.7);
		

				glPushMatrix(); //pupille gauche
				{
					glTranslatef(0,0,0.2);
					glScalef(1,1,0.2);
					glColor3f(0,0,0);
					glutSolidSphere(0.45, 20, 20);	
					glEnd();	
				}
				glPopMatrix();


				glPushMatrix(); //sourcil gauche
				{
						glTranslatef(0,1,-0.1);
						glScalef(0.8,0.1,0.5);
						glRotatef(-20,0,1,0);
						glColor3f(0,0,0);
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
						glEnd();
				}
				glPopMatrix();


				glScalef(2,1,0.5);
				glColor3f(1,1,1);
				glutSolidSphere(0.5, 20, 20);	
				glEnd();

			}
			glPopMatrix();



			glPushMatrix(); //oeil droit
			{
				glTranslatef(1,0,2.7);


				glPushMatrix(); //pupille droit
				{
					glTranslatef(0,0,0.2);
					glScalef(1,1,0.2);
					glColor3f(0,0,0);
					glutSolidSphere(0.45, 20, 20);		
					glEnd();
				}
				glPopMatrix();

				glPushMatrix(); //sourcil droite
				{
						glTranslatef(0,1,-0.1);
						glScalef(0.8,0.1,0.5);
						glRotatef(20,0,1,0);
						glColor3f(0,0,0);
						glBegin( GL_TRIANGLES ); 
							glVertex3f( 0.0f, 1.f, 0.0f );
							glVertex3f( -1.0f, -1.0f, 1.0f);
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
						glEnd();
				}
				glPopMatrix();

				glScalef(2,1,0.5);
				glColor3f(1,1,1);
				glutSolidSphere(0.5, 20, 20);	
				glEnd();

			}
			glPopMatrix();


			glPushMatrix(); // nez
			{
				glTranslatef(0.1,-0.8,2.6);
				glScalef(0.3,0.5,0.5);
				glRotatef(-60,0,1,0);
				glColor3f(0,0,0);
				glBegin( GL_TRIANGLES ); 
					// glVertex3f( 0.0f, 1.f, 0.0f );
					// glVertex3f( -1.0f, -1.0f, 1.0f );
					// glVertex3f( 1.0f, -1.0f, 1.0f);


					// glVertex3f( 0.0f, 1.0f, 0.0f);
					// glVertex3f( -1.0f, -1.0f, 1.0f);
					// glVertex3f( 0.0f, -1.0f, -1.0f);

					glVertex3f( 0.0f, 1.0f, 0.0f);
					glVertex3f( 0.0f, -1.0f, -1.0f);
					glVertex3f( 1.0f, -1.0f, 1.0f);

					glVertex3f( -1.0f, -1.0f, 1.0f);
					glVertex3f( 0.0f, -1.0f, -1.0f);
					glVertex3f( 1.0f, -1.0f, 1.0f);
					glEnd();
				glEnd();
			}
			glPopMatrix();


			glPushMatrix(); //bouche
			{
				glTranslatef(0,-2,2.2);

				glScalef(0.6,0.4,0.3);
				glColor3f(0.97,0.33,0.33);
				glutSolidCube(1.0);

				glPushMatrix(); //dent
				{
					glTranslatef(0,0.35,0.7);
					glScalef(0.7,0.3,0.05);
					glColor3f(1,1,1);

					glutSolidCube(1.0);
				}
				glPopMatrix();

				glEnd();
			}
			glPopMatrix();


			glPushMatrix(); //oreille gauche
			{
				glTranslatef(-3,0,0);
				glRotatef(220,0,1,0);
				glRotatef(45,1,0,0);
				glScalef(1,2.5,1);
				glColor3f(0.94,0.90,0.649);
				glutSolidSphere(0.5,5,5);
				glEnd();
			}
			glPopMatrix();



			glPushMatrix(); //oreille droite
			{
				glTranslatef(3,0,0);
				glRotatef(-220,0,1,0);
				glRotatef(45,1,0,0);
				glScalef(1,2.5,1);
				glColor3f(0.94,0.90,0.649);
				glutSolidSphere(0.5,5,5);
				glEnd();
			}
			glPopMatrix();




			glPushMatrix(); //chapeau
			{
				glEnable(GL_DEPTH_TEST);
				glTranslatef(20,0.5,-20);
				glRotatef(120,0,1,0);
				glRotatef(-20,1,0,0);
				glScalef(5,5,5);
				glColor4f(1,0.71, 0.75, 0.4);
				GLUquadric* cone = gluNewQuadric();
		    	gluQuadricTexture(cone,GL_TRUE); 
			    gluCylinder(cone,0.5,0,1.6,20,1); 
		        gluDeleteQuadric(cone); 
			}
			glPopMatrix();








			glEnd();
		}
		glPopMatrix();

	}
	glPopMatrix();


	glPushMatrix(); //colline
	{
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND); 
		 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glTranslatef(0,32,-92);
		glRotatef(45,1,0,0);
		glScalef(15,1,30);
		glColor4f(0.5,0.5,0, 0.8);
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
