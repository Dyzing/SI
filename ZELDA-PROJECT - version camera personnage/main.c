	// gcc main.c actions.o axes.o init.o lumiere.o switch_blend.o  switch_light.o VM_init.o -lm -lGL -lGLU -lglut -o test

//gcc main.c actions.c axes.o init.c lumiere.o switch_blend.o  switch_light.o VM_init.c -lm -lGL -lGLU -no-pie -lglut -o test; ./test

//skybox
#include "init.h"
#include "axes.h"
#include "VM_init.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


GLfloat xrot = 0.0f;   
int yrot = -180;   
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

int angle_triangle = -90;
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

GLfloat position_x_beta = 1400;
GLfloat position_y_beta = 2010;
GLfloat position_z_beta = 2000;


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

GLfloat position_y_rocher = 1200;
GLfloat position_z_rocher = 1232;

GLfloat position_y_rocher_gauche = 1300;
GLfloat position_z_rocher_gauche = 1332;

GLfloat position_y_rocher_droite = 1250;
GLfloat position_z_rocher_droite = 1282;


GLfloat position_dino_x = 1970;
GLfloat position_dino_y = 2020;
GLfloat position_dino_z = 2020;
int dino_bouge = 0;
int dino_monte0_descend1_statique2 = 2;

GLfloat position_cactus_grand_x = 1600;
GLfloat position_cactus_petit_x = 1800;


GLfloat position_requin_x = 0;
GLfloat position_requin_y = -50;
GLfloat position_requin_z = 1600;

GLfloat position_turbot_x = 10;
GLfloat position_turbot_y = -50;
GLfloat position_turbot_z = 1500;

GLfloat position_clown_x = 20;
GLfloat position_clown_y = -50;
GLfloat position_clown_z = 1400;

GLfloat position_zancle_x = -20;
GLfloat position_zancle_y = -50;
GLfloat position_zancle_z = 1300;


int aleatoire = 1;
int aleatoire_arbre = 1;

int aleatoire_oiseau = 1;


struct AABB3D 
{ 
  float x,y,z; 
  float w,h,d; 
};

struct AABB3D box1;
struct AABB3D box2;

struct AABB3D box_rocher_milieu;
struct AABB3D box_rocher_droite;
struct AABB3D box_rocher_gauche;

struct AABB3D box_personnage;
struct AABB3D box_dinosaure;
struct AABB3D box_petit_cactus;
struct AABB3D box_oiseau_dino;
struct AABB3D box_grand_cactus;


float position_box2 = -6;
float couleur_box2 = 0;

int aleatoire_simon = 0;
float transparence_simon_bleu = 0.3;
float transparence_simon_rouge = 0.3;
float transparence_simon_jaune = 0.3;
float transparence_simon_vert = 0.3;
int tour_suivant = 1;

int cube_time = 1;
int cube_attente = 0;

char simon[10];
int max_simon = 3;
int tour_simon = 0;
int nb_click = 0;
int nb_flash_actuel = 0;
int tour_IA0_Link1 = 0;


int mouse_button;
int mouse_state;
int mouse_x;
int mouse_y;
int mouse_motion_x = 0;
int mouse_motion_y = 0;

//variables_christophe

GLfloat dent_x = 0;
GLfloat dent_y = 0;
GLfloat dent_z = 0;

int aleatoire_requin = -25;
int aleatoire_turbot = 25;
int aleatoire_clown = -10;
int aleatoire_zancle = 10;

int positif_ou_negatif_requin = 1;
int positif_ou_negatif_turbot = 1;
int positif_ou_negatif_clown = 1;
int positif_ou_negatif_zancle = 1;

struct AABB3D box_requin;
struct AABB3D box_turbot;
struct AABB3D box_clown;
struct AABB3D box_zancle;

int algue_positif_negatif = 1;
int nb_algue = 1;
float angle_algue = 0.5;

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

float monter_dino(float position_dino_y)
{
  position_dino_y += 1;
  return position_dino_y;
}

float descendre_dino(float position_dino_y)
{
  position_dino_y -= 1;
  return position_dino_y;
}

void creer_petit_cactus(float x, float y, float z, float position_depart) //		glTranslatef(1900,2010,2000);
{

	glPushMatrix(); // petit cactus
	{
		if(x <= 2005)
		{
			x = x + 1;
			glTranslatef(x,y,z);

		}
		else
		{
			x = position_depart;
			glTranslatef(x,y,z);
		}

		glPushMatrix(); //bouboule
		{
			glTranslatef(0,4.25,0);
			glColor3f(0,0,0);
			glScalef(1,1,1);
			glutSolidSphere(0.5,8,8);
			glEnd();		
		}
		glPopMatrix();

		glPushMatrix(); //tronc
		{
			glColor3f(0.06,0.58,0.06);
			glScalef(1,5,1);
			glutSolidSphere(1,6,6);
			glEnd();		
		}
		glPopMatrix();


		glPushMatrix(); // branche gauche
		{
			glTranslatef(-1,1,0);

			glPushMatrix(); //horizontal
			{
				glColor3f(0.06,0.58,0.06);
				glScalef(3,1,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();

			glPushMatrix(); //vertical
			{
				glTranslatef(-1.1,1,0);
				glColor3f(0.06,0.58,0.06);
				glScalef(1,3,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); // branche droite
		{
			glTranslatef(1,-0.5,0);

			glPushMatrix(); //horizontal
			{
				glColor3f(0.06,0.58,0.06);
				glScalef(3,1,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();

			glPushMatrix(); //vertical
			{
				glTranslatef(1.1,1,0);
				glColor3f(0.06,0.58,0.06);
				glScalef(1,3,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();
			glEnd();
		}
		glPopMatrix();
		glEnd();
	}
	glPopMatrix();
}

void creer_grand_cactus(float x, float y, float z, float position_depart)
{
	glPushMatrix(); // grand cactus
	{
		if(x <= 2005)
		{
			x+= 1;
			glTranslatef(x,y,z);
		}
		else
		{
			x = position_depart;
			glTranslatef(x,y,z);
		}

		glTranslatef(x,y,z);

		glScalef(2,2,2);

		glPushMatrix(); //bouboule
		{
			glTranslatef(0,4.25,0);
			glColor3f(0,0,0);
			glScalef(1,1,1);
			glutSolidSphere(0.5,8,8);
			glEnd();		
		}
		glPopMatrix();

		glPushMatrix(); //tronc
		{
			glColor3f(0.06,0.58,0.06);
			glScalef(1,5,1);
			glutSolidSphere(1,6,6);
			glEnd();		
		}
		glPopMatrix();


		glPushMatrix(); // branche gauche
		{
			glTranslatef(-1,1,0);

			glPushMatrix(); //horizontal
			{
				glColor3f(0.06,0.58,0.06);
				glScalef(3,1,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();

			glPushMatrix(); //vertical
			{
				glTranslatef(-1.1,1,0);
				glColor3f(0.06,0.58,0.06);
				glScalef(1,3,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); // branche droite
		{
			glTranslatef(1,-0.5,0);

			glPushMatrix(); //horizontal
			{
				glColor3f(0.06,0.58,0.06);
				glScalef(3,1,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();

			glPushMatrix(); //vertical
			{
				glTranslatef(1.1,1,0);
				glColor3f(0.06,0.58,0.06);
				glScalef(1,3,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();
			glEnd();
		}
		glPopMatrix();
		glEnd();
	}
	glPopMatrix();
}



void creer_algue(float x, float y, float z)
{
	glPushMatrix(); // algue
	{
		glTranslatef(x,y,z);
		glScalef(1.5,2.5,1.5);
		glPushMatrix(); //boule de terre
		{
			glTranslatef(0,5,20);
			glColor3f(0.54,0.27,0.07);
			glScalef(2,1,2);
			glutSolidSphere(2,8,8);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //feuille d'algue gauche
		{

			glPushMatrix(); //petite feuille d'algue gauche
			{
				glTranslatef(-4,18,20);
				glRotatef(-20,0,0,1);
				glColor3f(0,0.51,0);
				glScalef(0.5,2,0.25);
				glutSolidSphere(2,8,8);
				glEnd();
			}
			glPopMatrix();


			glTranslatef(-4,13,20);
			glRotatef(20,0,0,1);
			glColor3f(0,0.51,0);
			glScalef(0.5,5,0.25);
			glutSolidSphere(2,8,8);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //feuille d'algue devant
		{


			glPushMatrix(); //petite feuille d'algue devant
			{
				glTranslatef(0,15,24);
				glRotatef(90,0,1,0);
				glRotatef(-20,0,0,1);
				glColor3f(0,0.51,0);
				glScalef(0.5,1.5,0.25);
				glutSolidSphere(2,8,8);
				glEnd();
			}
			glPopMatrix();


			glTranslatef(0,10,24);
			glRotatef(90,0,1,0);
			glRotatef(20,0,0,1);
			glColor3f(0,0.51,0);
			glScalef(0.5,3,0.25);
			glutSolidSphere(2,8,8);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //feuille d'algue arrière
		{


			glPushMatrix(); //petite feuille d'algue arrière
			{
				glTranslatef(0,10,18);
				glRotatef(-90,0,1,0);
				glRotatef(-20,0,0,1);
				glColor3f(0,0.51,0);
				glScalef(0.25,1,0.125);
				glutSolidSphere(2,8,8);
				glEnd();
			}
			glPopMatrix();


			glTranslatef(0,10,16);
			glRotatef(-90,0,1,0);
			glRotatef(20,0,0,1);
			glColor3f(0,0.51,0);
			glScalef(0.5,3,0.25);
			glutSolidSphere(2,8,8);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //feuille d'algue gauche
		{


			glPushMatrix(); //petite feuille d'algue droite
			{
				glTranslatef(2,14,20);
				glRotatef(20,0,0,1);
				glColor3f(0,0.51,0);
				glScalef(0.5,2,0.25);
				glutSolidSphere(2,8,8);
				glEnd();
			}
			glPopMatrix();



			glTranslatef(4,13,20);
			glRotatef(-20,0,0,1);
			glColor3f(0,0.51,0);
			glScalef(0.5,5,0.25);
			glutSolidSphere(2,8,8);
			glEnd();
		}
		glPopMatrix();

		glEnd();
	}
	glPopMatrix();
}



bool Collision(struct AABB3D box1,struct AABB3D box2) 
{ 
   if((box2.x >= box1.x + box1.w)      // trop à droite 
    || (box2.x + box2.w <= box1.x) // trop à gauche 
    || (box2.y >= box1.y + box1.h) // trop en bas 
    || (box2.y + box2.h <= box1.y)  // trop en haut     
        || (box2.z >= box1.z + box1.d)   // trop derrière 
    || (box2.z + box2.d <= box1.z))  // trop devant 
          return false; 
   else 
          return true; 
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


		box_personnage.x = position_x  + 2;
		box_personnage.y = position_y + 3;
		box_personnage.z = position_z + 6;

		box_personnage.w = 6;
		box_personnage.h = 4;
		box_personnage.d = 14;


	// glPushMatrix(); //box oiseau
	// {
	// 	glTranslatef(position_x  +2,position_y + 3,position_z  +6);
	// 	glScalef(3,2,7);
	// 	glColor4f(1,1,1,0.5);
	// 	glutSolidCube(2.0);
	// 	glEnd();
	// }
	// glPopMatrix();

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

		//float dir_length = sqrt(position_x * position_x + position_y * position_y + position_z * position_z);


	  	//transparence
		glEnable(GL_BLEND); 
	  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);







	  	//rotation
		//glRotatef(angle_oiseau_beta , 0, 1, 0);
		//glRotatef(angle_oiseau_vertical_beta, 0, 0, 1);
		// glTranslatef(2,2,2);
	 //  //	glRotatef(-90, 0,1,0);


		// //	printf("position y beta %f\n", position_y_beta);
		// //	printf("montee0_descente1_oiseaux_secondaire %i\n", montee0_descente1_oiseaux_secondaire);
		// if(montee0_descente1_oiseaux_secondaire == 0) //on monte
		// {
		// 	glTranslatef(position_x_beta,position_y_beta,position_z_beta);
		// 	glRotatef(-90,0,1,0);

		// 	position_y_beta += augmentation_position_y__oiseau_secondaire;
		// 	if (position_y_beta >= 25)
		// 	{
		// 		augmentation_position_y__oiseau_secondaire = 0;
		// 		if(angle_oiseau_beta != 360)
		// 		{
		// 			angle_oiseau_beta += 4;
		// 			angle_oiseau_vertical_secondaire += 4;
		// 			glRotatef(angle_oiseau_vertical_secondaire, 0, 0, 1);
		// 			glRotatef(angle_oiseau_beta, 0,1,0);
		// 		}
		// 		if(angle_oiseau_beta == 360)
		// 		{
		// 			angle_oiseau_beta = 0;
		// 			angle_oiseau_vertical_secondaire = 0;
		// 			augmentation_position_y__oiseau_secondaire = 0.5;
		// 			montee0_descente1_oiseaux_secondaire = 1;

		// 		}
		// 	}
		// }
		// else // on descend
		// {
		// 	glTranslatef(position_x_beta,position_y_beta,position_z_beta);
		// 	glRotatef(-90,0,1,0);
		// 	position_y_beta -= 0.5;
		// 	if (position_y_beta == 7.5)
		// 	{
		// 		montee0_descente1_oiseaux_secondaire = 0;
		// 	}
		// }


		if(position_x_beta <= 2005 && position_y >= 1999 && position_y <= 2500)
		{
			//printf("position_x_beta  : %f\n", position_x_beta);
			position_x_beta = position_x_beta + 1.5;
			position_y_beta = 2010 + (aleatoire_oiseau * aleatoire_oiseau * aleatoire_oiseau) ;
			glTranslatef(position_x_beta, position_y_beta ,position_z_beta);
		}
		else
		{
			srand(time(NULL));
			aleatoire_oiseau = (rand() % 4);
			position_x_beta = 1500;
			position_y_beta = 2010 + (aleatoire_oiseau * aleatoire_oiseau * aleatoire_oiseau);
			glTranslatef(position_x_beta,position_y_beta,position_z_beta);
		}





		box_oiseau_dino.x = position_x_beta  + 2;
		box_oiseau_dino.y = position_y_beta + 2;
		box_oiseau_dino.z = position_z_beta;

		box_oiseau_dino.w = 14;
		box_oiseau_dino.h = 2;
		box_oiseau_dino.d = 6;



		if(Collision(box_dinosaure, box_oiseau_dino) && position_y >= 1999 && position_y <= 2500)
		{	
			position_x = 0;
			position_y = -10;
			position_z = 20;
		}


	// glPushMatrix(); //box oiseau dino
	// {
	// 	glTranslatef(position_x_beta  +2,position_y_beta ,position_z_beta );
	// 	glScalef(7,2,3);
	// 	glColor4f(1,1,1,0.5);
	// 	glutSolidCube(2.0);
	// 	glEnd();
	// }
	// glPopMatrix();


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


	glPushMatrix(); //fond de mer
	{
		glTranslatef(0,-100,1345);
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
		glTranslatef(1000,position_y_rocher,position_z_rocher);

		
		box_rocher_milieu.x = 1000;
		box_rocher_milieu.y = position_y_rocher;
		box_rocher_milieu.z = position_z_rocher;

		box_rocher_milieu.w = 10;
		box_rocher_milieu.h = 10;
		box_rocher_milieu.d = 10;

		if(Collision(box_rocher_milieu, box_personnage))
		{	
			position_x = 0;
			position_y = 10;
			position_z = 20;
		}


		glRotatef(angle_rocher, 1,0,0);
		angle_rocher -= 5;
		position_y_rocher -= 0.5;
		position_z_rocher -= 0.5;
		if ((position_y_rocher <= 950) && (position_z_rocher <= 800))
		{
			position_y_rocher = 1200;
			position_z_rocher = 1232;
		}
		glColor3f(0.54,0.27,0.07);
		glScalef(1,1,1);
		glutSolidSphere(10,7,7);
		glEnd();
	}
	glPopMatrix();





	glPushMatrix(); //rocher gauche
	{
		glTranslatef(1020,position_y_rocher_gauche,position_z_rocher_gauche);

		box_rocher_gauche.x = 1020;
		box_rocher_gauche.y = position_y_rocher_gauche;
		box_rocher_gauche.z = position_z_rocher_gauche;

		box_rocher_gauche.w = 10;
		box_rocher_gauche.h = 10;
		box_rocher_gauche.d = 10;

		if(Collision(box_rocher_gauche, box_personnage))
		{	
			position_x = 0;
			position_y = 10;
			position_z = 20;
		}



		glRotatef(angle_rocher, 1,0,0);
		angle_rocher -= 5;
		position_y_rocher_gauche -= 0.5;
		position_z_rocher_gauche -= 0.5;
		if ((position_y_rocher_gauche <= 950) && (position_z_rocher_gauche  <= 800))
		{
			position_y_rocher_gauche = 1300;
			position_z_rocher_gauche = 1332;
		}
		glColor3f(0.54,0.27,0.07);
		glScalef(1,1,1);
		glutSolidSphere(10,7,7);
		glEnd();
	}
	glPopMatrix();




	glPushMatrix(); //rocher droite
	{
		glTranslatef(980,position_y_rocher_droite,position_z_rocher_droite);

		box_rocher_droite.x = 980;
		box_rocher_droite.y = position_y_rocher_droite;
		box_rocher_droite.z = position_z_rocher_droite;

		box_rocher_droite.w = 10;
		box_rocher_droite.h = 10;
		box_rocher_droite.d = 10;

		if(Collision(box_rocher_droite, box_personnage))
		{	
			position_x = 0;
			position_y = 0;
			position_z = 20;
		}


		glRotatef(angle_rocher, 1,0,0);
		angle_rocher -= 5;
		position_y_rocher_droite -= 0.5;
		position_z_rocher_droite -= 0.5;
		if ((position_y_rocher_droite <= 950) && (position_z_rocher_droite  <= 800))
		{
			position_y_rocher_droite = 1250;
			position_z_rocher_droite = 1282;
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
		glTranslatef(1000,1050,1100);
		glRotatef(-45,1,0,0);
		glScalef(15,1,300);
		glColor4f(0.5,0.5,0, 0.8);
		glutSolidCube(5.0);
		glEnd();
	}
	glPopMatrix();



		glPushMatrix(); //ile 1 
	{
		glTranslatef(1000,1000,1000);
		glScalef(50,1,40);
		glColor3f(0.43, 0.57, 0);
		glutSolidCube(3.0);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //ile 1 dino
	{

		glPushMatrix(); //Maison DINO
		{
			glTranslatef(2020, 2020, 1900);
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

			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //sol ile dino
		{
			glTranslatef(1300,2000,2000);
			glScalef(500,1,40);
			glColor3f(1,1,1);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //dinosaure
	{

		if(dino_bouge == 1)
		{

		      if( (position_dino_y <= 2060) && (dino_monte0_descend1_statique2 == 0) ) 
		      {
		        position_dino_y = monter_dino(position_dino_y);
		        glTranslatef(position_dino_x,position_dino_y,position_dino_z);
		        if (position_dino_y >= 2060)
		        {
		        	dino_monte0_descend1_statique2 = 1;
		        }
		      }
		      else if( (position_dino_y >= 2018) && (dino_monte0_descend1_statique2 == 1) )
		      {
		        position_dino_y = descendre_dino(position_dino_y);
		        glTranslatef(position_dino_x,position_dino_y,position_dino_z);
		        if (position_dino_y <= 2018)
		        {
		        	dino_monte0_descend1_statique2 = 2;
		        	dino_bouge = 0;   	
		        }
		      }		      
		}
		else
		{
			glTranslatef(position_dino_x,position_dino_y,position_dino_z);
		}

		
		box_dinosaure.x = position_dino_x + 6;
		box_dinosaure.y = position_dino_y -4;
		box_dinosaure.z = position_dino_z - 20;

		box_dinosaure.w = 22;
		box_dinosaure.h = 24;
		box_dinosaure.d = 10;

		if(Collision(box_dinosaure, box_petit_cactus) && position_y >= 1999 && position_y <= 2500)
		{	
			position_x = 0;
			position_y = -10;
			position_z = 20;
		}

	// glPushMatrix(); //box dinosaure
	// {
	// 	glTranslatef(position_dino_x + 6 ,position_dino_y -4 ,position_dino_z - 20);
	// 	glScalef(11,12,5);
	// 	glColor4f(1,1,1,0.5);
	// 	glutSolidCube(2.0);
	// 	glEnd();
	// }
	// glPopMatrix();

		glRotatef(180, 0,1,0);


		glPushMatrix(); //tete dino
		{
			glTranslatef(0,4.8,20);


			glPushMatrix(); //oeil
			{
				glTranslatef(-2,1,3);

				glPushMatrix(); //pupille
				{
					glTranslatef(0,0,0.3);
					glColor3f(0.4,0.4,0.4);
					glScalef(0.5,0.5,0.5);
					glutSolidCube(1);
					glEnd();
				}
				glPopMatrix();


				glColor3f(1,1,1);
				glutSolidCube(1);
				glEnd();
			}
			glPopMatrix();

			glColor3f(0.4,0.4,0.4);

			glPushMatrix(); // cou
			{
				glTranslatef(-2.99,-3,0);
				glScalef(1,1,2);
				glutSolidCube(3);
				glEnd();
			}
			glPopMatrix();



			glPushMatrix(); // langue
			{
				glTranslatef(-0.9,-4.5,0);
				glScalef(2.4,0.3,2);
				glutSolidCube(3);
				glEnd();
			}
			glPopMatrix();


			glScalef(3,2,2);
			glutSolidCube(3);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); // cravate
		{
			glTranslatef(-3,-4.5,20);
			glScalef(2,3,2);
			glutSolidCube(3);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); // bra
		{
			glTranslatef(-1,-3.5,20);


			glPushMatrix(); // main
			{
				glTranslatef(2.55,-1,0);
				glScalef(0.3,0.4,2);
				glutSolidCube(3);
				glEnd();
			}
			glPopMatrix();


			glScalef(2,0.3,2);
			glutSolidCube(3);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //dos rond
		{
			glTranslatef(-6,-9,20);
			glScalef(2,2,1.5);
			glutSolidSphere(3,8,8);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); // queue
		{
			glTranslatef(-12.0,-10,20);


			glPushMatrix(); // milieu de queue
			{
				glTranslatef(-1.5,2,0);
				glScalef(1,1,2);
				glutSolidCube(3);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); // fin de queue
			{
				glTranslatef(-2.5,3.5,0);
				glScalef(1,1,2);
				glutSolidCube(3);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //bout de queue devant
			{
				glTranslatef(-2.5,8,0);
				glScalef(1.5,3.5,3);
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


			glPushMatrix(); //bout de queue derrière
			{
				glTranslatef(-2.5,8,0);
				glScalef(1.5,3.5,3);
				glRotatef(180,0,1,0);
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




			glScalef(1,1,2);
			glutSolidCube(3);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); // jambes
		{
			glTranslatef(-7,-14,20);

			glPushMatrix(); //jambe gauche
			{
				glScalef(0.3,1,1.8);
				glutSolidCube(3);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //jambe droite
			{
				glTranslatef(3,0,0);
				glScalef(0.3,1,1.8);
				glutSolidCube(3);
				glEnd();
			}
			glPopMatrix();


			glPushMatrix(); //pied gauche
			{
				glTranslatef(0.5,-1,0);
				glScalef(0.5,0.3,1.8);
				glutSolidCube(3);
				glEnd();
			}
			glPopMatrix();


			glPushMatrix(); //pied droite
			{
				glTranslatef(3.5,-1,0);
				glScalef(0.5,0.3,1.8);
				glutSolidCube(3);
				glEnd();
			}
			glPopMatrix();

		}
		glPopMatrix();

	glEnd();
	}
	glPopMatrix();

	//creer_petit_cactus(0,10,30, 0); //		glTranslatef(1900,2010,2000);



	glPushMatrix(); // petit cactus
	{
		if(position_cactus_petit_x <= 2005 && position_y >= 1999 && position_y <= 2500)
		{
			position_cactus_petit_x = position_cactus_petit_x + 1;
			glTranslatef(position_cactus_petit_x,2010,2000);
		}
		else
		{
			position_cactus_petit_x = 1300;
			glTranslatef(position_cactus_petit_x,2010,2000);
		}

		box_petit_cactus.x = position_cactus_petit_x  + 1;
		box_petit_cactus.y = 2010;
		box_petit_cactus.z = 2000;

		box_petit_cactus.w = 6;
		box_petit_cactus.h = 10;
		box_petit_cactus.d = 2;

	// glPushMatrix(); //box petit_cactus
	// {
	// 	glTranslatef(1,10,30);
	// 	glScalef(3,5,1);
	// 	glColor4f(1,1,1,0.5);
	// 	glutSolidCube(2.0);
	// 	glEnd();
	// }
	// glPopMatrix();


		glPushMatrix(); //bouboule
		{
			glTranslatef(0,4.25,0);
			glColor3f(0,0,0);
			glScalef(1,1,1);
			glutSolidSphere(0.5,8,8);
			glEnd();		
		}
		glPopMatrix();

		glPushMatrix(); //tronc
		{
			glColor3f(0.06,0.58,0.06);
			glScalef(1,5,1);
			glutSolidSphere(1,6,6);
			glEnd();		
		}
		glPopMatrix();


		glPushMatrix(); // branche gauche
		{
			glTranslatef(-1,1,0);

			glPushMatrix(); //horizontal
			{
				glColor3f(0.06,0.58,0.06);
				glScalef(3,1,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();

			glPushMatrix(); //vertical
			{
				glTranslatef(-1.1,1,0);
				glColor3f(0.06,0.58,0.06);
				glScalef(1,3,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); // branche droite
		{
			glTranslatef(1,-0.5,0);

			glPushMatrix(); //horizontal
			{
				glColor3f(0.06,0.58,0.06);
				glScalef(3,1,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();

			glPushMatrix(); //vertical
			{
				glTranslatef(1.1,1,0);
				glColor3f(0.06,0.58,0.06);
				glScalef(1,3,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();
			glEnd();
		}
		glPopMatrix();
		glEnd();
	}
	glPopMatrix();

	//creer_grand_cactus(0,10,0,0);


	glPushMatrix(); // grand cactus
	{
		if(position_cactus_grand_x <= 2005 && position_y >= 1999 && position_y <= 2500)
		{
			position_cactus_grand_x = position_cactus_grand_x + 1;
			glTranslatef(position_cactus_grand_x,2010,2000);
		}
		else
		{
			position_cactus_grand_x = 1100;
			glTranslatef(position_cactus_grand_x,2010,2000);
		}

		//glTranslatef(x,y,z);




		box_grand_cactus.x = position_cactus_grand_x  + 2;
		box_grand_cactus.y = 2010;
		box_grand_cactus.z = 2000;

		box_grand_cactus.w = 12;
		box_grand_cactus.h = 18;
		box_grand_cactus.d = 4;


		if(Collision(box_dinosaure, box_grand_cactus) && position_y >= 1999 && position_y <= 2500)
		{	
			position_x = 0;
			position_y = -10;
			position_z = 20;
		}


	// glPushMatrix(); //box grand_cactus
	// {
	// 	glTranslatef(position_cactus_grand_x  + 2,2010,2000);
	// 	glScalef(6,9,2);
	// 	glColor4f(1,1,1,0.5);
	// 	glutSolidCube(2.0);
	// 	glEnd();
	// }
	// glPopMatrix();


		glScalef(2,2,2);

		glPushMatrix(); //bouboule
		{
			glTranslatef(0,4.25,0);
			glColor3f(0,0,0);
			glScalef(1,1,1);
			glutSolidSphere(0.5,8,8);
			glEnd();		
		}
		glPopMatrix();

		glPushMatrix(); //tronc
		{
			glColor3f(0.06,0.58,0.06);
			glScalef(1,5,1);
			glutSolidSphere(1,6,6);
			glEnd();		
		}
		glPopMatrix();


		glPushMatrix(); // branche gauche
		{
			glTranslatef(-1,1,0);

			glPushMatrix(); //horizontal
			{
				glColor3f(0.06,0.58,0.06);
				glScalef(3,1,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();

			glPushMatrix(); //vertical
			{
				glTranslatef(-1.1,1,0);
				glColor3f(0.06,0.58,0.06);
				glScalef(1,3,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); // branche droite
		{
			glTranslatef(1,-0.5,0);

			glPushMatrix(); //horizontal
			{
				glColor3f(0.06,0.58,0.06);
				glScalef(3,1,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();

			glPushMatrix(); //vertical
			{
				glTranslatef(1.1,1,0);
				glColor3f(0.06,0.58,0.06);
				glScalef(1,3,1);
				glutSolidSphere(0.5,6,6);
				glEnd();		
			}
			glPopMatrix();
			glEnd();
		}
		glPopMatrix();
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //cube 1
	{
		box1.x = 0;
		box1.y = 0;
		box1.z = 0;

		box1.w = 2;
		box1.h = 2;
		box1.d = 2;

		glTranslatef(0,0,0);
		glColor3f(1,1,1);
		glutSolidCube(2.0);
		glEnd();
	}
	glPopMatrix();

	glPushMatrix(); //cube 2
	{
		box2.x = position_box2;
		box2.y = 1;
		box2.z = 0;

		box2.w = 2;
		box2.h = 2;
		box2.d = 2;

		// if(Collision(box1, box2))
		// {	
		// 	couleur_box2 = 0.8;
		// 	position_z = 100;
		// }

		glTranslatef(position_box2,1,0);
		position_box2 = position_box2 + 0.1;
		if(position_box2 >= 10)
		{
			position_box2 = -6;
			couleur_box2 = 0;
		}

		glColor3f(couleur_box2,1,1);
		glutSolidCube(2.0);
		glEnd();
	}
	glPopMatrix();




	glPushMatrix(); //box oiseau dino
	{
		glTranslatef(position_x_beta  +2,position_y_beta ,position_z_beta );
		glScalef(7,2,3);
		glColor4f(1,1,1,0.5);
		glutSolidCube(2.0);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //box dinosaure
	{
		glTranslatef(position_dino_x + 6 ,position_dino_y -4 ,position_dino_z - 20);
		glScalef(11,12,5);
		glColor4f(1,1,1,0.5);
		glutSolidCube(2.0);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //box petit_cactus
	{
		glTranslatef(position_cactus_petit_x,2010,2000);
		glScalef(2.5,5,1);
		glColor4f(1,1,1,0.5);
		glutSolidCube(2.0);
		glEnd();
	}
	glPopMatrix();



	glPushMatrix(); //box grand_cactus
	{
		glTranslatef(position_cactus_grand_x  + 2,2010,2000);
		glScalef(6,9,2);
		glColor4f(1,1,1,0.5);
		glutSolidCube(2.0);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //ile 3 super simon
	{

		glPushMatrix(); //Maison super simon
		{
			glTranslatef(3020, 3020, 2900);
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

			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //sol ile simon
		{
			glTranslatef(2950,3000,3000);
			glScalef(70,1,40);
			glColor3f(1,1,1);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();
		glEnd();

		glPushMatrix(); //cube simon
		{
			glTranslatef(10,-5,0);

			//printf("tour_IA0_Link1 :  %i\n", tour_IA0_Link1);


			if(tour_simon < max_simon && position_y > 2900 && tour_IA0_Link1 == 0) // tour IA
			{

				if(cube_attente < 50 && cube_attente > 0)  // délais d'attente
				{
					cube_attente += 1;
					printf(" attente : %i\n", cube_time);
				}
				else
				{
					cube_attente = 0;
				}

				if(nb_flash_actuel == tour_simon && cube_attente == 0)
				{
					if(position_z < 3010 && position_z > 2990 && position_x < 2945 && position_y > 2900 && tour_suivant == 1)
					{
						srand(time(NULL));
						aleatoire_simon = (rand() % 4) + 1;
					}


					if(aleatoire_simon == 1 && cube_attente == 0) //bleu
					{
						printf("bleu");
						if(cube_time < 100)
						{
							tour_suivant = 0;
							transparence_simon_bleu = 1;
							cube_time += 1;
							printf(" cube time : %i\n", cube_time);
						}
						else
						{
							simon[tour_simon] = 'b';
							tour_suivant = 1;
							cube_time = 0;
							transparence_simon_bleu = 0.3;
							aleatoire_simon = 0;
							cube_attente = 1;
							tour_simon+= 1;
							nb_flash_actuel = 0;
							tour_IA0_Link1 = 1;
							for (int i = 0; i < tour_simon; ++i)
							{
								printf("simon[%i] = %c\n", tour_simon - 1, simon[tour_simon - 1]);
							}
						}
					}
					else if(aleatoire_simon == 2 && cube_attente == 0) //rouge
					{
						printf("vert");
						if(cube_time < 100)
						{
							tour_suivant = 0;
							transparence_simon_rouge = 1;
							cube_time += 1;
							printf(" cube time : %i\n", cube_time);
						}
						else
						{
							simon[tour_simon] = 'r';
							tour_suivant = 1;
							cube_time = 0;
							transparence_simon_rouge = 0.3;
							aleatoire_simon = 0;
							cube_attente = 1;
							tour_simon+= 1;
							nb_flash_actuel = 0;
							tour_IA0_Link1 = 1;
							for (int i = 0; i < tour_simon - 1; ++i)
							{
								printf("simon[%i] = %c\n", tour_simon, simon[tour_simon - 1]);
							}						}
					}
					else if(aleatoire_simon == 3 && cube_attente == 0) //jaune
					{
						printf("jaune");
						if(cube_time < 100)
						{
							tour_suivant = 0;
							transparence_simon_jaune = 1;
							cube_time += 1;
							printf(" cube time : %i\n", cube_time);
						}
						else
						{
							simon[tour_simon] = 'j';
							tour_suivant = 1;
							cube_time = 0;
							transparence_simon_jaune = 0.3;
							aleatoire_simon = 0;
							cube_attente = 1;
							tour_simon+= 1;
							nb_flash_actuel = 0;
							tour_IA0_Link1 = 1;
							for (int i = 0; i < tour_simon - 1; ++i)
							{
								printf("simon[%i] = %c\n", tour_simon - 1, simon[tour_simon - 1]);
							}						}
					}
					else if(aleatoire_simon == 4 && cube_attente == 0) //vert
					{
						printf("vert");
						if(cube_time < 100)
						{
							tour_suivant = 0;
							transparence_simon_vert = 1;
							cube_time += 1;
							printf(" cube time : %i\n", cube_time);
						}
						else
						{
							simon[tour_simon] = 'v';
							tour_suivant = 1;
							cube_time = 0;
							transparence_simon_vert = 0.3;
							aleatoire_simon = 0;
							cube_attente = 1;
							tour_simon+= 1;
							nb_flash_actuel = 0;
							tour_IA0_Link1 = 1;
							for (int i = 0; i < tour_simon - 1; ++i)
							{
								printf("simon[%i] = %c\n", tour_simon - 1, simon[tour_simon - 1]);
							}						
						}
					}

				}

				else if (nb_flash_actuel < tour_simon && cube_attente == 0)
				{
					printf("SECOND IF ****************************** \n");
					printf(" cube time : %i\n", cube_time);

					if(simon[nb_flash_actuel] == 'b') //bleu
					{
						if(cube_time < 100)
						{
							tour_suivant = 0;
							transparence_simon_bleu = 1;
							cube_time += 1;
							printf(" cube time : %i\n", cube_time);
						}
						else
						{
							tour_suivant = 1;
							cube_time = 0;
							transparence_simon_bleu = 0.3;
							aleatoire_simon = 0;
							cube_attente = 1;
							nb_flash_actuel += 1;
						}
					}
					else if(simon[nb_flash_actuel] == 'r') //rouge
					{
						if(cube_time < 100)
						{
							tour_suivant = 0;
							transparence_simon_rouge = 1;
							cube_time += 1;
							printf(" cube time : %i\n", cube_time);
						}
						else
						{
							tour_suivant = 1;
							cube_time = 0;
							transparence_simon_rouge = 0.3;
							aleatoire_simon = 0;
							cube_attente = 1;
							nb_flash_actuel += 1;
						}
					}
					else if(simon[nb_flash_actuel] == 'j') //jaune
					{
						if(cube_time < 100)
						{
							tour_suivant = 0;
							transparence_simon_jaune = 1;
							cube_time += 1;
							printf(" cube time : %i\n", cube_time);
						}
						else
						{
							tour_suivant = 1;
							cube_time = 0;
							transparence_simon_jaune = 0.3;
							aleatoire_simon = 0;
							cube_attente = 1;
							nb_flash_actuel += 1;
						}
					}
					else if(simon[nb_flash_actuel] == 'v') //vert
					{
						if(cube_time < 100)
						{
							tour_suivant = 0;
							transparence_simon_vert = 1;
							cube_time += 1;
							printf(" cube time : %i\n", cube_time);
						}
						else
						{
							tour_suivant = 1;
							cube_time = 0;
							transparence_simon_vert = 0.3;
							aleatoire_simon = 0;
							cube_attente = 1;
							nb_flash_actuel += 1;
						}
					}
				}	

				printf("nb_flash_actuel_apres :  %i\n", nb_flash_actuel);
				printf("tour_simon_apres :  %i\n", tour_simon);
			}
			else if(position_y > 2900 && tour_IA0_Link1 == 1) // tour link
			{



				printf("tour_simon : %i\n", tour_simon);
				printf("nb_click : %i\n", nb_click);
				if(nb_click < tour_simon )
				{

					if(cube_attente < 50 && cube_attente > 0)  // délais d'attente
					{
						cube_attente += 1;
						printf(" attente : %i\n", cube_time);
					}
					else
					{
						cube_attente = 0;
					}

					if(mouse_x > 238 && mouse_x < 332 && mouse_y > 112 && mouse_y < 212 && mouse_state == GLUT_DOWN && mouse_button == GLUT_LEFT_BUTTON)
					{
						printf("bleu \n");
						for (int i = 0; i < nb_click; ++i)
						{
							printf("simon[%i] = %c\n",i, simon[i]);
						}
						if(simon[nb_click] == 'b')
						{
							printf("bleu \n");
							if(cube_attente == 0)
							{
								if(cube_time < 25)
								{
									tour_suivant = 0;
									transparence_simon_bleu = 1;
									cube_time += 1;
									printf(" cube time : %i\n", cube_time);
								}
								else
								{
									tour_suivant = 1;
									cube_time = 0;
									transparence_simon_bleu = 0.3;
									aleatoire_simon = 0;
									cube_attente = 1;
									nb_click += 1;
									printf("nb_click : %i\n, tour_simon : %i\n", nb_click, tour_simon);
									if(nb_click == tour_simon && nb_click < max_simon)
									{
										tour_IA0_Link1 = 0;
										nb_click = 0;
									}
									for (int i = 0; i < nb_click; ++i)
									{
										printf("simon[%i] = %c\n",nb_click, simon[nb_click]);
									}
								}
							}
						}
						else
						{
							// transparence_simon_bleu = 0;
							// transparence_simon_rouge = 0;
							// transparence_simon_jaune = 0;
							// transparence_simon_vert = 0;
							printf("perdu \n");
						}
					}
					else if(mouse_x > 306 && mouse_x < 398 && mouse_y > 179 && mouse_y < 275 && mouse_state == GLUT_DOWN && mouse_button == GLUT_LEFT_BUTTON)
					{
						printf("rouge \n");
						for (int i = 0; i < nb_click; ++i)
						{
							printf("simon[%i] = %c\n",i, simon[i]);
						}
						if(simon[nb_click] == 'r')
						{
							printf("rouge \n");
							if(cube_attente == 0)
							{
								if(cube_time < 25)
								{
									tour_suivant = 0;
									transparence_simon_rouge = 1;
									cube_time += 1;
									printf(" cube time : %i\n", cube_time);
								}
								else
								{
									tour_suivant = 1;
									cube_time = 0;
									transparence_simon_rouge = 0.3;
									aleatoire_simon = 0;
									cube_attente = 1;
									nb_click += 1;
									printf("nb_click : %i\n, tour_simon : %i\n", nb_click, tour_simon);
									if(nb_click == tour_simon && nb_click < max_simon)
									{
										tour_IA0_Link1 = 0;
										nb_click = 0;
									}
									for (int i = 0; i < nb_click; ++i)
									{
										printf("simon[%i] = %c\n",nb_click, simon[nb_click]);
									}
								}
							}
						}
						else
						{
							// transparence_simon_bleu = 0;
							// transparence_simon_rouge = 0;
							// transparence_simon_jaune = 0;
							// transparence_simon_vert = 0;
							printf("perdu \n");
						}
					}
					else if(mouse_x > 306 && mouse_x < 398 && mouse_y > 51 && mouse_y < 158 && mouse_state == GLUT_DOWN && mouse_button == GLUT_LEFT_BUTTON)
					{
						printf("jaune \n");
						for (int i = 0; i < tour_simon; ++i)
						{
							printf("simon[%i] = %c\n",i, simon[i]);
						}
						if(simon[nb_click] == 'j')
						{
							printf("jaune \n");
							if(cube_attente == 0)
							{
								if(cube_time < 25)
								{
									tour_suivant = 0;
									transparence_simon_jaune = 1;
									cube_time += 1;
									printf(" cube time : %i\n", cube_time);
								}
								else
								{
									tour_suivant = 1;
									cube_time = 0;
									transparence_simon_jaune = 0.3;
									aleatoire_simon = 0;
									cube_attente = 1;
									nb_click += 1;
									printf("nb_click : %i\n, tour_simon : %i\n", nb_click, tour_simon);
									if(nb_click == tour_simon && nb_click < max_simon)
									{
										tour_IA0_Link1 = 0;
										nb_click = 0;
									}
									for (int i = 0; i < nb_click; ++i)
									{
										printf("simon[%i] = %c\n",nb_click, simon[nb_click]);
									}
								}
							}
						}
						else
						{
							// transparence_simon_bleu = 0;
							// transparence_simon_rouge = 0;
							// transparence_simon_jaune = 0;
							// transparence_simon_vert = 0;
							printf("perdu \n");
						}					
					}
					else if(mouse_x > 368 && mouse_x < 465 && mouse_y > 112 && mouse_y < 212 && mouse_state == GLUT_DOWN && mouse_button == GLUT_LEFT_BUTTON)
					{
						printf("vert \n");
						for (int i = 0; i < nb_click; ++i)
						{
							printf("simon[%i] = %c\n",i, simon[i]);
						}
						if(simon[nb_click] == 'v')
						{
							printf("vert \n");
							if(cube_attente == 0)
							{
								if(cube_time < 25)
								{
									tour_suivant = 0;
									transparence_simon_vert = 1;
									cube_time += 1;
									printf(" cube time : %i\n", cube_time);
								}
								else
								{
									tour_suivant = 1;
									cube_time = 0;
									transparence_simon_vert = 0.3;
									aleatoire_simon = 0;
									cube_attente = 1;
									nb_click += 1;
									printf("nb_click : %i\n, tour_simon : %i\n", nb_click, tour_simon);
									if(nb_click == tour_simon && nb_click < max_simon)
									{
										tour_IA0_Link1 = 0;
										nb_click = 0;
									}
									for (int i = 0; i < nb_click; ++i)
									{
										printf("simon[%i] = %c\n",nb_click, simon[nb_click]);
									}
								}
							}
						}
						else
						{
							// transparence_simon_bleu = 0;
							// transparence_simon_rouge = 0;
							// transparence_simon_jaune = 0;
							// transparence_simon_vert = 0;
							printf("perdu \n");
						}					
					}
				}
				else
				{
					printf(" attente : %i\n", cube_attente);
					if(cube_attente < 500 && cube_attente > 1)  // délais d'attente
					{
						cube_attente += 1;
						printf(" attente : %i\n", cube_time);
						transparence_simon_bleu = 0;
						transparence_simon_rouge = 0;
						transparence_simon_jaune = 0;
						transparence_simon_vert = 0;
					}
					else
					{
						cube_attente = 0;
					}
					if (cube_attente <= 1)
					{
						transparence_simon_bleu = 1;
						transparence_simon_rouge = 1;
						transparence_simon_jaune = 1;
						transparence_simon_vert = 1;
						cube_attente += 0.1;
					}
					
				}
			}
			else
			{
				//printf("stop");
			}






			glPushMatrix(); //cube bleu gauche super-simon
			{
				glTranslatef(2900,3040,3010);
				glRotatef(45,1,0,0);
				glColor4f(0,0,1,transparence_simon_bleu);
				glutSolidCube(10.0);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //cube vert droite super-simon
			{
				glTranslatef(2900,3040,2990);
				glRotatef(45,1,0,0);
				glColor4f(0,1,0,transparence_simon_vert);
				glutSolidCube(10.0);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //cube jaune haut super-simon
			{
				glTranslatef(2900,3050,3000);
				glRotatef(45,1,0,0);
				glColor4f(1,1,0,transparence_simon_jaune);
				glutSolidCube(10.0);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //cube rouge bas super-simon
			{
				glTranslatef(2900,3030,3000);
				glRotatef(45,1,0,0);
				glColor4f(1,0,0,transparence_simon_rouge);
				glutSolidCube(10.0);
				glEnd();
			}
			glPopMatrix();

			glEnd();
		}
		glPopMatrix();

	}
	glPopMatrix();




// monde aquatique







// CHRISTOPHE

	glPushMatrix(); //animaux marins 
	{

		glPushMatrix(); // Requin
		{
			glTranslatef(aleatoire_requin,position_requin_y,position_requin_z);



			box_requin.x = aleatoire_requin - 10;
			box_requin.y = position_requin_y;
			box_requin.z = position_requin_z + 3;

			box_requin.w = 26;
			box_requin.h = 16;
			box_requin.d = 42;


			if(Collision(box_personnage, box_requin) && position_z > 900 && position_z < 1000)
			{	
				// position_x = 0;
				// position_y = -10;
				// position_z = 20;
				printf(" touche \n");
			}




			// glPushMatrix(); //box requin
			// {
			// 	glTranslatef(aleatoire_requin ,position_requin_y ,position_requin_z + 3);
			// 	glScalef(13,8,21);
			// 	glColor4f(1,1,1,0.5);
			// 	glutSolidCube(2.0);
			// 	glEnd();
			// }
			// glPopMatrix();






			if(position_z > 925 && position_z < 1000)
			{
				position_y = -50;
				position_requin_z -= 5;
				if(position_requin_z < 900)
				{
					srand(time(NULL));
					aleatoire_requin = (rand() % 25) * positif_ou_negatif_requin;
					position_requin_z = 1650;
					positif_ou_negatif_requin = -positif_ou_negatif_requin;

				}
			}
			else
			{
				position_requin_z = 1650;
			}
			GLUquadricObj *obj = gluNewQuadric();
			
			glPushMatrix(); // tronc
			{
				glPushMatrix(); // centre
					glRotatef(90,0,1,0);
					glColor3f(0.305, 0.392, 0.474);
					glScalef(2,0.8,0.9);
					glutSolidSphere(7,32,32);
					
					glTranslatef(0,-0.1,0);
					glColor3f(0.647, 0.701, 0.752);
					glutSolidSphere(7,32,32);
				glPopMatrix();
				
				axes();
				
				glPushMatrix();  // Yeux
				{
					glTranslatef(2,1,-13);
					glColor3f(0,0,0);
					glutSolidSphere(0.5,32,32);
					glTranslatef(-4,0,0);
					glutSolidSphere(0.5,32,32);
				}
				glPopMatrix();
				
				glTranslatef(0,5,0);
				glColor3f(0.305, 0.392, 0.474);
				
				glPushMatrix();  // Machoire
				{
					glTranslatef(0,-5,-18);
					glBegin( GL_TRIANGLES );
					{	//SUPERIEURE
					// dessus centre
						glVertex3f( 0.0f, 0.0f, 0.0f); // A
						glVertex3f( 3.0f, 3.0f, 8.0f); // B
						glVertex3f(-3.0f, 3.0f, 8.0f); // B'
					// dessus gauche 
						glVertex3f( 0.0f, 0.0f, 0.0f); // A
						glVertex3f( 3.0f, 3.0f, 8.0f); // B
						glVertex3f( 4.5f, 0.0f, 8.0f); // C
					// dessus droite 
						glVertex3f( 0.0f, 0.0f, 0.0f); // A
						glVertex3f(-3.0f, 3.0f, 8.0f); // B'
						glVertex3f(-4.5f, 0.0f, 8.0f); // C'
					// dessous centre
						glVertex3f( 0.0f, 0.0f, 0.0f); // A
						glVertex3f( 1.0f,-1.0f, 1.0f); // D
						glVertex3f(-1.0f,-1.0f, 1.0f); // D'
					// dessous gauche
						glVertex3f( 0.0f, 0.0f, 0.0f); // A
						glVertex3f( 1.0f,-1.0f, 1.0f); // D
						glVertex3f( 4.5f, 0.0f, 8.0f); // C
					// dessous gauche exterieure
						glVertex3f( 1.0f,-1.0f, 1.0f); // D
						glVertex3f( 4.5f, 0.0f, 8.0f); // C
						glVertex3f( 4.0f,-2.0f,10.0f); // E
					// dessous droite
						glVertex3f( 0.0f, 0.0f, 0.0f); // A
						glVertex3f(-1.0f,-1.0f, 1.0f); // D'
						glVertex3f(-4.5f, 0.0f, 8.0f); // C'
					// dessous droite exterieure
						glVertex3f(-1.0f,-1.0f, 1.0f); // D'
						glVertex3f(-4.5f, 0.0f, 8.0f); // C'
						glVertex3f(-4.0f,-2.0f,10.0f); // E'
					// dessous
						glVertex3f( 0.0f, 0.0f, 0.0f); // A
						glVertex3f( 4.5f, 0.0f, 8.0f); // C
						glVertex3f(-4.5f, 0.0f, 8.0f); // C'
						
						// INFERIEURE
					// centre
						glVertex3f( 1.0f,-2.0f, 2.0f); // F
						glVertex3f(-1.0f,-2.0f, 2.0f); // F'
						glVertex3f( 0.0f,-3.0f, 3.0f); // G
					// gauche
						glVertex3f( 1.0f,-2.0f, 2.0f); // F
						glVertex3f( 4.0f,-2.0f,10.0f); // E
						glVertex3f( 0.0f,-3.0f, 3.0f); // G
					// droite
						glVertex3f(-1.0f,-2.0f, 2.0f); // F'
						glVertex3f(-4.0f,-2.0f,10.0f); // E'
						glVertex3f( 0.0f,-3.0f, 3.0f); // G
					// dessous
						glVertex3f( 0.0f,-3.0f, 3.0f); // G
						glVertex3f( 4.0f,-2.0f,10.0f); // E
						glVertex3f(-4.0f,-2.0f,10.0f); // E'
					}
					glEnd();
					glTranslatef(1,-1,1);
					glBegin( GL_TRIANGLES ); // DENTS haut
					{
						glColor3f(1,1,1);
						for (float i=0; i<2; i++){
							glVertex3f( dent_x-i, dent_y, dent_z);
							glVertex3f( dent_x-0.5-i, dent_y, dent_z);
							glVertex3f( dent_x-0.25-i, dent_y-0.25, dent_z);
							i = i-0.5;
						}
					}
					glEnd();
					glTranslatef(0,-1,1);
					glBegin( GL_TRIANGLES ); // DENTS bas
					{
						for (float i=0; i<2; i++){
							glVertex3f( dent_x-i, dent_y, dent_z);
							glVertex3f( dent_x-0.5-i, dent_y, dent_z);
							glVertex3f( dent_x-0.25-i, dent_y+0.25, dent_z);
							i = i-0.5;
						}
					}
					glEnd();
				}
				glPopMatrix();
				
				glPushMatrix(); // dorsale
				{
					glColor3f(0.305, 0.392, 0.474);
					glBegin( GL_TRIANGLES );
					{
					//gauche devant
						glVertex3f( 0.0f, 0.0f,-2.0f);
						glVertex3f(-1.0f, 0.0f, 0.0f);
						glVertex3f( 0.0f, 4.0f, 3.0f);
					//gauche derrière
						glVertex3f(-1.0f, 0.0f, 0.0f);
						glVertex3f( 0.0f, 4.0f, 3.0f);
						glVertex3f( 0.0f, 0.0f, 2.0f);
					//droite devant
						glVertex3f( 0.0f, 0.0f,-2.0f);
						glVertex3f( 1.0f, 0.0f, 0.0f);
						glVertex3f( 0.0f, 4.0f, 3.0f);
					//droite derrière
						glVertex3f( 1.0f, 0.0f, 0.0f);
						glVertex3f( 0.0f, 4.0f, 3.0f);
						glVertex3f( 0.0f, 0.0f, 2.0f);
					}
					glEnd();
				}
				glPopMatrix();
				
				glTranslatef(-6,-6,0);
				
				glPushMatrix(); // nageoire gauche
				{
					glBegin( GL_TRIANGLES );
					{
					//gauche dessus devant
						glVertex3f( 0.0f, 0.0f,-1.0f);
						glVertex3f( 0.0f, 1.0f, 0.0f);
						glVertex3f(-10.0f,0.0f, 5.0f);
					//gauche dessus derrière 
						glVertex3f( 0.0f, 1.0f, 0.0f);
						glVertex3f(-10.0f,0.0f, 5.0f);
						glVertex3f( 0.0f, 0.0f, 3.0f);
					//gauche dessous devant
						glVertex3f( 0.0f, 0.0f,-1.0f);
						glVertex3f( 0.0f,-0.5f, 0.0f);
						glVertex3f(-10.0f,0.0f, 5.0f);
					//gauche dessous derrière 
						glVertex3f( 0.0f,-0.5f, 0.0f);
						glVertex3f(-10.0f,0.0f, 5.0f);
						glVertex3f( 0.0f, 0.0f, 3.0f);
					}
					glEnd();
				}
				glPopMatrix();
				
				glTranslatef(12,0,0);
				
				glPushMatrix(); // nageoire droite
				{
					glBegin( GL_TRIANGLES );
					{
					//droite dessus devant
						glVertex3f( 0.0f, 0.0f,-1.0f);
						glVertex3f( 0.0f, 1.0f, 0.0f);
						glVertex3f(10.0f, 0.0f, 5.0f);
					//droite dessus derrière 
						glVertex3f( 0.0f, 1.0f, 0.0f);
						glVertex3f(10.0f, 0.0f, 5.0f);
						glVertex3f( 0.0f, 0.0f, 3.0f);
					//droite dessous devant
						glVertex3f( 0.0f, 0.0f,-1.0f);
						glVertex3f( 0.0f,-0.5f, 0.0f);
						glVertex3f(10.0f, 0.0f, 5.0f);
					//droite dessous derrière 
						glVertex3f( 0.0f,-0.5f, 0.0f);
						glVertex3f(10.0f, 0.0f, 5.0f);
						glVertex3f( 0.0f, 0.0f, 3.0f);
					}
					glEnd();
				}
				glPopMatrix();
			}
			glPopMatrix();
			
			glPushMatrix(); // queue
			{
				glTranslatef(0,0,6);
				glScalef(0.9,0.8,1);
				gluCylinder(obj,6.3,1,15,32,32);
				glTranslatef(0,-0.1,0);
				
				glColor3f(0.647, 0.701, 0.752);
				gluCylinder(obj,6.3,1,15,32,32);
				
				glTranslatef(0,0.1,13);
				
				// aileron
				glColor3f(0.305, 0.392, 0.474);
				glBegin( GL_TRIANGLES );
				{
				//gauche devant haut
					glVertex3f( 0.0f, 0.0f,-1.0f);
					glVertex3f(-1.0f, 0.0f, 2.0f);
					glVertex3f( 0.0f,11.0f, 5.0f);
				//gauche derrière haut
					glVertex3f(-1.0f, 0.0f, 2.0f);
					glVertex3f( 0.0f,11.0f, 5.0f);
					glVertex3f( 0.0f, 0.0f, 3.5f);
				//gauche devant bas
					glVertex3f( 0.0f, 0.0f,-1.0f);
					glVertex3f(-1.0f, 0.0f, 2.0f);
					glVertex3f( 0.0f,-11.0f,5.0f);
				//gauche derrière bas
					glVertex3f(-1.0f, 0.0f, 2.0f);
					glVertex3f( 0.0f,-11.0f,5.0f);
					glVertex3f( 0.0f, 0.0f, 3.5f);
				//droite devant haut
					glVertex3f( 0.0f, 0.0f,-1.0f);
					glVertex3f( 1.0f, 0.0f, 2.0f);
					glVertex3f( 0.0f,11.0f, 5.0f);
				//droite derrière haut
					glVertex3f( 1.0f, 0.0f, 2.0f);
					glVertex3f( 0.0f,11.0f, 5.0f);
					glVertex3f( 0.0f, 0.0f, 3.5f);
				//droite devant bas
					glVertex3f( 0.0f, 0.0f,-1.0f);
					glVertex3f( 1.0f, 0.0f, 2.0f);
					glVertex3f( 0.0f,-11.0f,5.0f);
				//droite derrière bas
					glVertex3f( 1.0f, 0.0f, 2.0f);
					glVertex3f( 0.0f,-11.0f,5.0f);
					glVertex3f( 0.0f, 0.0f, 3.5f);
				}
				glEnd();
				
				axes();
			}
			glPopMatrix();
			
		}
		glPopMatrix();
		
		glPushMatrix(); // Poisson : Turbot
		{
			glTranslatef(aleatoire_turbot,position_turbot_y,position_turbot_z);




			box_turbot.x = aleatoire_turbot;
			box_turbot.y = position_turbot_y;
			box_turbot.z = position_turbot_z;

			box_turbot.w = 4;
			box_turbot.h = 12;
			box_turbot.d = 16;


			if(Collision(box_personnage, box_turbot) && position_z > 900 && position_z < 1000)
			{	
				// position_x = 0;
				// position_y = -10;
				// position_z = 20;
				printf(" touche zancle \n");
			}





			// glPushMatrix(); //box turbot
			// {
			// 	glTranslatef(aleatoire_turbot ,position_turbot_y ,position_turbot_z);
			// 	glScalef(2,6,8);
			// 	glColor4f(1,1,1,0.5);
			// 	glutSolidCube(2.0);
			// 	glEnd();
			// }
			// glPopMatrix();


			glScalef(2,2,2);
			if(position_z > 925 && position_z < 1000)
			{
				position_y = -50;
				position_turbot_z -= 6;
				if(position_turbot_z < 900)
				{
					srand(time(NULL));
					aleatoire_turbot = (rand() % 25) * positif_ou_negatif_turbot;
					position_turbot_z = 1750;
					positif_ou_negatif_turbot = -positif_ou_negatif_turbot;
				}
			}

			GLUquadricObj *obj = gluNewQuadric();
			glColor3f(0.282, 0.156, 0.098);
			
			glPushMatrix(); //corps
			{
				glScalef(0.2,1,1);
				glutSolidSphere(3,32,32);
			}
			glPopMatrix();
			
			glPushMatrix(); //tete
			{
				glTranslatef(0,0,-0.5);
				glPushMatrix();
				{
					glScalef(0.3,1,1.5);
					glutSolidSphere(2,32,32);
				}
				glPopMatrix();
				
				glPushMatrix(); //yeux
				{
					glColor3f(0.341, 0.215, 0.160);
					glTranslatef(-0.3,0.5,-2);
					glutSolidSphere(0.15,32,32);
					glTranslatef(0.6,0,0);
					glutSolidSphere(0.15,32,32);
				}
				glPopMatrix();
				
				glPushMatrix(); //machoire
				{
					glTranslatef(0,-1,-2.2); //inf
					glRotatef(33,1,0,0);
					glScalef(0.3,0.1,1.2);
					glutSolidSphere(1,32,32);
					
					glTranslatef(0,-1,-1.5); //sup
					glRotatef(0,1,0,0);
				}
				glPopMatrix();
				
			}
			glPopMatrix();
			
			glPushMatrix(); // nageoires
			{
				gluCylinder(obj,0.6,1,1,32,32);
			}
			glPopMatrix();
			
			glPushMatrix(); // queue
			{
				glTranslatef(0,0,2.9);
				glScalef(0.1,1,1);
				gluCylinder(obj,0.5,1,1,32,32);
				glTranslatef(0,0,1);
				gluDisk(obj,0,1,32,32);
			}
			glPopMatrix();
			
			glPushMatrix(); // ailerons
			{
				glTranslatef(0,1,0.3);
				glScalef(0.05,1.1,1.2);
				glutSolidSphere(2,32,32);
				glTranslatef(0,-2.3,0);
				glutSolidSphere(1.5,32,32);
			}
			glPopMatrix();
			
		}
		glPopMatrix();
		
		glPushMatrix(); // Poisson : Clown
		{
			glTranslatef(aleatoire_clown,position_clown_y,position_clown_z);
			glScalef(3,3,3);




			box_clown.x = aleatoire_clown;
			box_clown.y = position_clown_y;
			box_clown.z = position_clown_z;

			box_clown.w = 4;
			box_clown.h = 4;
			box_clown.d = 6;


			if(Collision(box_personnage, box_clown) && position_z > 900 && position_z < 1000)
			{	
				// position_x = 0;
				// position_y = -10;
				// position_z = 20;
				printf(" touche clown \n");
			}





			// glPushMatrix(); //box clown
			// {
			// 	glTranslatef(aleatoire_clown ,position_clown_y ,position_clown_z);
			// 	glScalef(2,2,3);
			// 	glColor4f(1,1,1,0.5);
			// 	glutSolidCube(2.0);
			// 	glEnd();
			// }
			// glPopMatrix();





			if(position_z > 925 && position_z < 1000)
			{
				position_y = -50;
				position_clown_z-= 5;
				if(position_clown_z < 900)
				{
					srand(time(NULL));
					aleatoire_clown = (rand() % 25) * positif_ou_negatif_clown;
					position_clown_z = 1700;
					positif_ou_negatif_clown = -positif_ou_negatif_clown;
				}
				
			}


			GLUquadricObj *obj = gluNewQuadric();
		
			glPushMatrix(); // yeux
			{
				glColor3f(0,0,0);
				glTranslatef(-0.3,0.1,-0.75);
				glutSolidSphere(0.05,32,32);
				glTranslatef(0.6,0,0);
				glutSolidSphere(0.05,32,32);
			}
			glPopMatrix();
				
			glColor3f(0.976, 0.443, 0.101);
			glScalef(1,1,2);
			glutSolidSphere(0.5,32,32);
			
			glPushMatrix(); // dorsale
			{
				glTranslatef(0,0.45,0);
				glRotatef(33,1,0,0);
				glScalef(0.1,1,1);
				glutSolidSphere(0.1,32,32);
				glColor3f(0,0,0);
				glScalef(0.8,1,1);
				glTranslatef(0,0.01,0);
				glutSolidSphere(0.1,32,32);
			}
			glPopMatrix();
			
			glPushMatrix(); // ventrale
			{
				glColor3f(0.976, 0.443, 0.101);
				glTranslatef(0,-0.45,0);
				glRotatef(-33,1,0,0);
				glScalef(0.1,1,1);
				glutSolidSphere(0.1,32,32);
				glColor3f(0,0,0);
				glScalef(0.8,1,1);
				glTranslatef(0,-0.01,0);
				glutSolidSphere(0.1,32,32);
			}
			glPopMatrix();
			
			glPushMatrix(); // nageoire g
			{
				glColor3f(0.976, 0.443, 0.101);
				glTranslatef(-0.5,0,0);
				glRotatef(-45,0,1,0);
				glScalef(0.1,1,1);
				glutSolidSphere(0.1,32,32);
				
				glTranslatef(0,0,0.01);
				glColor3f(0,0,0);
				glScalef(0.5,1,1);
				glutSolidSphere(0.1,32,32);
			}
			glPopMatrix();
			
			glPushMatrix(); // nageoire d
			{
				glColor3f(0.976, 0.443, 0.101);
				glTranslatef(0.5,0,0);
				glRotatef(45,0,1,0);
				glScalef(0.1,1,1);
				glutSolidSphere(0.1,32,32);
				
				glTranslatef(0,0,0.01);
				glColor3f(0,0,0);
				glScalef(0.5,1,1);
				glutSolidSphere(0.1,32,32);
			}
			glPopMatrix();
			
			glPushMatrix(); // blanc 1
			{
				glColor3f(1,1,1);
				glTranslatef(0,0,-0.3);
				gluCylinder(obj,0.4,0.47,0.1,32,32);
			}
			glPopMatrix();
			glPushMatrix(); // blanc 2
			{
				glColor3f(1,1,1);
				glTranslatef(0,0,0.2);
				gluCylinder(obj,0.47,0.4,0.1,32,32);
			}
			glPopMatrix();
			
			glScalef(1,1,0.5);
			
			glPushMatrix(); // queue
			{
				glTranslatef(0,0,0.5);
				glColor3f(0.976, 0.443, 0.101);
				gluCylinder(obj,0.45,0.2,0.5,32,32);
				
				glTranslatef(0,0,0.5);
				glColor3f(1,1,1);
				gluCylinder(obj,0.2,0.1,0.2,32,32);
				
				glTranslatef(0,0,0.18);
				glutSolidSphere(0.1,32,32);
				
				glTranslatef(0,0,0.1);
				glColor3f(0.976, 0.443, 0.101);
				glScalef(0.2,1.3,1);
				glutSolidSphere(0.2,32,32);
				
				glTranslatef(0,0,0.01);
				glColor3f(0,0,0);
				glScalef(0.5,1,1);
				glutSolidSphere(0.2,32,32);
				
			}
			glPopMatrix();
		}
		glPopMatrix();
		
		glPushMatrix(); // Poisson : Zancle
		{
			glTranslatef(aleatoire_zancle,position_zancle_y,position_zancle_z);
			glScalef(3,3,3);



			box_zancle.x = aleatoire_zancle;
			box_zancle.y = position_zancle_y;
			box_zancle.z = position_zancle_z + 2;

			box_zancle.w = 2;
			box_zancle.h = 4;
			box_zancle.d = 4;


			if(Collision(box_personnage, box_zancle) && position_z > 900 && position_z < 1000)
			{	
				// position_x = 0;
				// position_y = -10;
				// position_z = 20;
				printf(" touche zancle \n");
			}


			// glPushMatrix(); //box zancle 
			// {
			// 	glTranslatef(0 ,5 ,100 + 2);
			// 	glScalef(1,2,2);
			// 	glColor4f(1,1,1,0.5);
			// 	glutSolidCube(2.0);
			// 	glEnd();
			// }
			// glPopMatrix();	



			if(position_z > 925 && position_z < 1000)
			{
				position_y = -50;
				position_zancle_z -= 4;
				if(position_zancle_z< 900)
				{
					srand(time(NULL));
					aleatoire_zancle = (rand() % 25) * positif_ou_negatif_zancle;
					position_zancle_z = 1800;
					positif_ou_negatif_zancle = -positif_ou_negatif_zancle;
				}
				
			}


			GLUquadricObj *obj = gluNewQuadric();
			glScalef(0.3,1,1);
			
			glColor3f(0,0,0);
			gluDisk(obj,0.01,0.05,32,32);
			gluCylinder(obj,0.05,0.1,0.2,32,32);
			
			glTranslatef(0,0,0.2);
			glColor3f(0.925, 0.921, 0.611);
			gluCylinder(obj,0.1,0.2,0.1,32,32);
			
			glTranslatef(0,0,0.1);
			glColor3f(0,0,0);
			gluCylinder(obj,0.2,0.5,0.2,32,32);
			glPushMatrix(); // yeux
			{
				glColor3f(1,1,1);
				glTranslatef(0.3,0.2,0.1);
				glutSolidSphere(0.05,32,32);
				
				glTranslatef(-0.6,0,0);
				glutSolidSphere(0.05,32,32);
			}
			glPopMatrix();
			
			glTranslatef(0,0,0.2);
			glColor3f(0.925, 0.921, 0.611);
			gluCylinder(obj,0.5,0.51,0.3,32,32);
			
			
			glTranslatef(0,0,0.3);
			glColor3f(0,0,0);
			gluCylinder(obj,0.51,0.3,0.2,32,32);
			
			glTranslatef(0,0,0.2);
			glColor3f(0.925, 0.921, 0.611);
			gluCylinder(obj,0.3,0.1,0.1,32,32);
			
			glTranslatef(0,0,0.1);
			glColor3f(0,0,0);
			gluCylinder(obj,0.1,0.3,0.2,32,32);
			
			glScalef(0.5,1,1);
			glTranslatef(0,0,0.2);
			gluDisk(obj,0,0.3,32,32);
		}
		glPopMatrix();

		glEnd();
	}	
	glPopMatrix();


	glPushMatrix(); // box aquatique
	{

		// glPushMatrix(); // Requin modele box
		// {
		// 	glTranslatef(0,5,10);
		// 	if(position_z > 925 && position_z < 1000)
		// 	{
		// 		position_y = -50;
		// 		position_requin_z -= 3;
		// 		if(position_requin_z < 900)
		// 		{
		// 			position_requin_z = 1650;

		// 		}
		// 	}
		// 	GLUquadricObj *obj = gluNewQuadric();
			
		// 	glPushMatrix(); // tronc
		// 	{
		// 		glPushMatrix(); // centre
		// 			glRotatef(90,0,1,0);
		// 			glColor3f(0.305, 0.392, 0.474);
		// 			glScalef(2,0.8,0.9);
		// 			glutSolidSphere(7,32,32);
					
		// 			glTranslatef(0,-0.1,0);
		// 			glColor3f(0.647, 0.701, 0.752);
		// 			glutSolidSphere(7,32,32);
		// 		glPopMatrix();
				
		// 		axes();
				
		// 		glPushMatrix();  // Yeux
		// 		{
		// 			glTranslatef(2,1,-13);
		// 			glColor3f(0,0,0);
		// 			glutSolidSphere(0.5,32,32);
		// 			glTranslatef(-4,0,0);
		// 			glutSolidSphere(0.5,32,32);
		// 		}
		// 		glPopMatrix();
				
		// 		glTranslatef(0,5,0);
		// 		glColor3f(0.305, 0.392, 0.474);
				
		// 		glPushMatrix();  // Machoire
		// 		{
		// 			glTranslatef(0,-5,-18);
		// 			glBegin( GL_TRIANGLES );
		// 			{	//SUPERIEURE
		// 			// dessus centre
		// 				glVertex3f( 0.0f, 0.0f, 0.0f); // A
		// 				glVertex3f( 3.0f, 3.0f, 8.0f); // B
		// 				glVertex3f(-3.0f, 3.0f, 8.0f); // B'
		// 			// dessus gauche 
		// 				glVertex3f( 0.0f, 0.0f, 0.0f); // A
		// 				glVertex3f( 3.0f, 3.0f, 8.0f); // B
		// 				glVertex3f( 4.5f, 0.0f, 8.0f); // C
		// 			// dessus droite 
		// 				glVertex3f( 0.0f, 0.0f, 0.0f); // A
		// 				glVertex3f(-3.0f, 3.0f, 8.0f); // B'
		// 				glVertex3f(-4.5f, 0.0f, 8.0f); // C'
		// 			// dessous centre
		// 				glVertex3f( 0.0f, 0.0f, 0.0f); // A
		// 				glVertex3f( 1.0f,-1.0f, 1.0f); // D
		// 				glVertex3f(-1.0f,-1.0f, 1.0f); // D'
		// 			// dessous gauche
		// 				glVertex3f( 0.0f, 0.0f, 0.0f); // A
		// 				glVertex3f( 1.0f,-1.0f, 1.0f); // D
		// 				glVertex3f( 4.5f, 0.0f, 8.0f); // C
		// 			// dessous gauche exterieure
		// 				glVertex3f( 1.0f,-1.0f, 1.0f); // D
		// 				glVertex3f( 4.5f, 0.0f, 8.0f); // C
		// 				glVertex3f( 4.0f,-2.0f,10.0f); // E
		// 			// dessous droite
		// 				glVertex3f( 0.0f, 0.0f, 0.0f); // A
		// 				glVertex3f(-1.0f,-1.0f, 1.0f); // D'
		// 				glVertex3f(-4.5f, 0.0f, 8.0f); // C'
		// 			// dessous droite exterieure
		// 				glVertex3f(-1.0f,-1.0f, 1.0f); // D'
		// 				glVertex3f(-4.5f, 0.0f, 8.0f); // C'
		// 				glVertex3f(-4.0f,-2.0f,10.0f); // E'
		// 			// dessous
		// 				glVertex3f( 0.0f, 0.0f, 0.0f); // A
		// 				glVertex3f( 4.5f, 0.0f, 8.0f); // C
		// 				glVertex3f(-4.5f, 0.0f, 8.0f); // C'
						
		// 				// INFERIEURE
		// 			// centre
		// 				glVertex3f( 1.0f,-2.0f, 2.0f); // F
		// 				glVertex3f(-1.0f,-2.0f, 2.0f); // F'
		// 				glVertex3f( 0.0f,-3.0f, 3.0f); // G
		// 			// gauche
		// 				glVertex3f( 1.0f,-2.0f, 2.0f); // F
		// 				glVertex3f( 4.0f,-2.0f,10.0f); // E
		// 				glVertex3f( 0.0f,-3.0f, 3.0f); // G
		// 			// droite
		// 				glVertex3f(-1.0f,-2.0f, 2.0f); // F'
		// 				glVertex3f(-4.0f,-2.0f,10.0f); // E'
		// 				glVertex3f( 0.0f,-3.0f, 3.0f); // G
		// 			// dessous
		// 				glVertex3f( 0.0f,-3.0f, 3.0f); // G
		// 				glVertex3f( 4.0f,-2.0f,10.0f); // E
		// 				glVertex3f(-4.0f,-2.0f,10.0f); // E'
		// 			}
		// 			glEnd();
		// 			glTranslatef(1,-1,1);
		// 			glBegin( GL_TRIANGLES ); // DENTS haut
		// 			{
		// 				glColor3f(1,1,1);
		// 				for (float i=0; i<2; i++){
		// 					glVertex3f( dent_x-i, dent_y, dent_z);
		// 					glVertex3f( dent_x-0.5-i, dent_y, dent_z);
		// 					glVertex3f( dent_x-0.25-i, dent_y-0.25, dent_z);
		// 					i = i-0.5;
		// 				}
		// 			}
		// 			glEnd();
		// 			glTranslatef(0,-1,1);
		// 			glBegin( GL_TRIANGLES ); // DENTS bas
		// 			{
		// 				for (float i=0; i<2; i++){
		// 					glVertex3f( dent_x-i, dent_y, dent_z);
		// 					glVertex3f( dent_x-0.5-i, dent_y, dent_z);
		// 					glVertex3f( dent_x-0.25-i, dent_y+0.25, dent_z);
		// 					i = i-0.5;
		// 				}
		// 			}
		// 			glEnd();
		// 		}
		// 		glPopMatrix();
				
		// 		glPushMatrix(); // dorsale
		// 		{
		// 			glColor3f(0.305, 0.392, 0.474);
		// 			glBegin( GL_TRIANGLES );
		// 			{
		// 			//gauche devant
		// 				glVertex3f( 0.0f, 0.0f,-2.0f);
		// 				glVertex3f(-1.0f, 0.0f, 0.0f);
		// 				glVertex3f( 0.0f, 4.0f, 3.0f);
		// 			//gauche derrière
		// 				glVertex3f(-1.0f, 0.0f, 0.0f);
		// 				glVertex3f( 0.0f, 4.0f, 3.0f);
		// 				glVertex3f( 0.0f, 0.0f, 2.0f);
		// 			//droite devant
		// 				glVertex3f( 0.0f, 0.0f,-2.0f);
		// 				glVertex3f( 1.0f, 0.0f, 0.0f);
		// 				glVertex3f( 0.0f, 4.0f, 3.0f);
		// 			//droite derrière
		// 				glVertex3f( 1.0f, 0.0f, 0.0f);
		// 				glVertex3f( 0.0f, 4.0f, 3.0f);
		// 				glVertex3f( 0.0f, 0.0f, 2.0f);
		// 			}
		// 			glEnd();
		// 		}
		// 		glPopMatrix();
				
		// 		glTranslatef(-6,-6,0);
				
		// 		glPushMatrix(); // nageoire gauche
		// 		{
		// 			glBegin( GL_TRIANGLES );
		// 			{
		// 			//gauche dessus devant
		// 				glVertex3f( 0.0f, 0.0f,-1.0f);
		// 				glVertex3f( 0.0f, 1.0f, 0.0f);
		// 				glVertex3f(-10.0f,0.0f, 5.0f);
		// 			//gauche dessus derrière 
		// 				glVertex3f( 0.0f, 1.0f, 0.0f);
		// 				glVertex3f(-10.0f,0.0f, 5.0f);
		// 				glVertex3f( 0.0f, 0.0f, 3.0f);
		// 			//gauche dessous devant
		// 				glVertex3f( 0.0f, 0.0f,-1.0f);
		// 				glVertex3f( 0.0f,-0.5f, 0.0f);
		// 				glVertex3f(-10.0f,0.0f, 5.0f);
		// 			//gauche dessous derrière 
		// 				glVertex3f( 0.0f,-0.5f, 0.0f);
		// 				glVertex3f(-10.0f,0.0f, 5.0f);
		// 				glVertex3f( 0.0f, 0.0f, 3.0f);
		// 			}
		// 			glEnd();
		// 		}
		// 		glPopMatrix();
				
		// 		glTranslatef(12,0,0);
				
		// 		glPushMatrix(); // nageoire droite
		// 		{
		// 			glBegin( GL_TRIANGLES );
		// 			{
		// 			//droite dessus devant
		// 				glVertex3f( 0.0f, 0.0f,-1.0f);
		// 				glVertex3f( 0.0f, 1.0f, 0.0f);
		// 				glVertex3f(10.0f, 0.0f, 5.0f);
		// 			//droite dessus derrière 
		// 				glVertex3f( 0.0f, 1.0f, 0.0f);
		// 				glVertex3f(10.0f, 0.0f, 5.0f);
		// 				glVertex3f( 0.0f, 0.0f, 3.0f);
		// 			//droite dessous devant
		// 				glVertex3f( 0.0f, 0.0f,-1.0f);
		// 				glVertex3f( 0.0f,-0.5f, 0.0f);
		// 				glVertex3f(10.0f, 0.0f, 5.0f);
		// 			//droite dessous derrière 
		// 				glVertex3f( 0.0f,-0.5f, 0.0f);
		// 				glVertex3f(10.0f, 0.0f, 5.0f);
		// 				glVertex3f( 0.0f, 0.0f, 3.0f);
		// 			}
		// 			glEnd();
		// 		}
		// 		glPopMatrix();
		// 	}
		// 	glPopMatrix();
			
		// 	glPushMatrix(); // queue
		// 	{
		// 		glTranslatef(0,0,6);
		// 		glScalef(0.9,0.8,1);
		// 		gluCylinder(obj,6.3,1,15,32,32);
		// 		glTranslatef(0,-0.1,0);
				
		// 		glColor3f(0.647, 0.701, 0.752);
		// 		gluCylinder(obj,6.3,1,15,32,32);
				
		// 		glTranslatef(0,0.1,13);
				
		// 		// aileron
		// 		glColor3f(0.305, 0.392, 0.474);
		// 		glBegin( GL_TRIANGLES );
		// 		{
		// 		//gauche devant haut
		// 			glVertex3f( 0.0f, 0.0f,-1.0f);
		// 			glVertex3f(-1.0f, 0.0f, 2.0f);
		// 			glVertex3f( 0.0f,11.0f, 5.0f);
		// 		//gauche derrière haut
		// 			glVertex3f(-1.0f, 0.0f, 2.0f);
		// 			glVertex3f( 0.0f,11.0f, 5.0f);
		// 			glVertex3f( 0.0f, 0.0f, 3.5f);
		// 		//gauche devant bas
		// 			glVertex3f( 0.0f, 0.0f,-1.0f);
		// 			glVertex3f(-1.0f, 0.0f, 2.0f);
		// 			glVertex3f( 0.0f,-11.0f,5.0f);
		// 		//gauche derrière bas
		// 			glVertex3f(-1.0f, 0.0f, 2.0f);
		// 			glVertex3f( 0.0f,-11.0f,5.0f);
		// 			glVertex3f( 0.0f, 0.0f, 3.5f);
		// 		//droite devant haut
		// 			glVertex3f( 0.0f, 0.0f,-1.0f);
		// 			glVertex3f( 1.0f, 0.0f, 2.0f);
		// 			glVertex3f( 0.0f,11.0f, 5.0f);
		// 		//droite derrière haut
		// 			glVertex3f( 1.0f, 0.0f, 2.0f);
		// 			glVertex3f( 0.0f,11.0f, 5.0f);
		// 			glVertex3f( 0.0f, 0.0f, 3.5f);
		// 		//droite devant bas
		// 			glVertex3f( 0.0f, 0.0f,-1.0f);
		// 			glVertex3f( 1.0f, 0.0f, 2.0f);
		// 			glVertex3f( 0.0f,-11.0f,5.0f);
		// 		//droite derrière bas
		// 			glVertex3f( 1.0f, 0.0f, 2.0f);
		// 			glVertex3f( 0.0f,-11.0f,5.0f);
		// 			glVertex3f( 0.0f, 0.0f, 3.5f);
		// 		}
		// 		glEnd();
				
		// 		axes();
		// 	}
		// 	glPopMatrix();
			
		// }
		// glPopMatrix();

		glPushMatrix(); //box requin
		{
			glTranslatef(aleatoire_requin ,position_requin_y ,position_requin_z + 3);
			glScalef(13,8,21);
			glColor4f(1,1,1,0.5);
			glutSolidCube(2.0);
			glEnd();
		}
		glPopMatrix();


		// glPushMatrix(); // Poisson : Turbot modele box
		// {
		// 	glTranslatef(0,5,50);
		// 	glScalef(2,2,2);
		// 	if(position_z > 925 && position_z < 1000)
		// 	{
		// 		position_y = -50;
		// 		position_turbot_z -= 4;
		// 		if(position_turbot_z < 900)
		// 		{
		// 			position_turbot_z = 1750;

		// 		}
		// 	}

		// 	GLUquadricObj *obj = gluNewQuadric();
		// 	glColor3f(0.282, 0.156, 0.098);
			
		// 	glPushMatrix(); //corps
		// 	{
		// 		glScalef(0.2,1,1);
		// 		glutSolidSphere(3,32,32);
		// 	}
		// 	glPopMatrix();
			
		// 	glPushMatrix(); //tete
		// 	{
		// 		glTranslatef(0,0,-0.5);
		// 		glPushMatrix();
		// 		{
		// 			glScalef(0.3,1,1.5);
		// 			glutSolidSphere(2,32,32);
		// 		}
		// 		glPopMatrix();
				
		// 		glPushMatrix(); //yeux
		// 		{
		// 			glColor3f(0.341, 0.215, 0.160);
		// 			glTranslatef(-0.3,0.5,-2);
		// 			glutSolidSphere(0.15,32,32);
		// 			glTranslatef(0.6,0,0);
		// 			glutSolidSphere(0.15,32,32);
		// 		}
		// 		glPopMatrix();
				
		// 		glPushMatrix(); //machoire
		// 		{
		// 			glTranslatef(0,-1,-2.2); //inf
		// 			glRotatef(33,1,0,0);
		// 			glScalef(0.3,0.1,1.2);
		// 			glutSolidSphere(1,32,32);
					
		// 			glTranslatef(0,-1,-1.5); //sup
		// 			glRotatef(0,1,0,0);
		// 		}
		// 		glPopMatrix();
				
		// 	}
		// 	glPopMatrix();
			
		// 	glPushMatrix(); // nageoires
		// 	{
		// 		gluCylinder(obj,0.6,1,1,32,32);
		// 	}
		// 	glPopMatrix();
			
		// 	glPushMatrix(); // queue
		// 	{
		// 		glTranslatef(0,0,2.9);
		// 		glScalef(0.1,1,1);
		// 		gluCylinder(obj,0.5,1,1,32,32);
		// 		glTranslatef(0,0,1);
		// 		gluDisk(obj,0,1,32,32);
		// 	}
		// 	glPopMatrix();
			
		// 	glPushMatrix(); // ailerons
		// 	{
		// 		glTranslatef(0,1,0.3);
		// 		glScalef(0.05,1.1,1.2);
		// 		glutSolidSphere(2,32,32);
		// 		glTranslatef(0,-2.3,0);
		// 		glutSolidSphere(1.5,32,32);
		// 	}
		// 	glPopMatrix();
			
		// }
		// glPopMatrix();


		glPushMatrix(); //box turbot
		{
			glTranslatef(aleatoire_turbot ,position_turbot_y ,position_turbot_z);
			glScalef(2,6,8);
			glColor4f(1,1,1,0.5);
			glutSolidCube(2.0);
			glEnd();
		}
		glPopMatrix();
		

		// glPushMatrix(); // Poisson : Clown modele box
		// {
		// 	glTranslatef(0,5,80);
		// 	glScalef(3,3,3);
		// 	if(position_z > 925 && position_z < 1000)
		// 	{
		// 		position_y = -50;
		// 		position_clown_z-= 3;
		// 		if(position_clown_z < 900)
		// 		{
		// 			srand(time(NULL));
		// 			aleatoire_clown = (rand() % 25) * positif_ou_negatif_clown;
		// 			position_clown_z = 1700;
		// 			positif_ou_negatif_clown = -positif_ou_negatif_clown;
		// 		}
				
		// 	}


		// 	GLUquadricObj *obj = gluNewQuadric();
		
		// 	glPushMatrix(); // yeux
		// 	{
		// 		glColor3f(0,0,0);
		// 		glTranslatef(-0.3,0.1,-0.75);
		// 		glutSolidSphere(0.05,32,32);
		// 		glTranslatef(0.6,0,0);
		// 		glutSolidSphere(0.05,32,32);
		// 	}
		// 	glPopMatrix();
				
		// 	glColor3f(0.976, 0.443, 0.101);
		// 	glScalef(1,1,2);
		// 	glutSolidSphere(0.5,32,32);
			
		// 	glPushMatrix(); // dorsale
		// 	{
		// 		glTranslatef(0,0.45,0);
		// 		glRotatef(33,1,0,0);
		// 		glScalef(0.1,1,1);
		// 		glutSolidSphere(0.1,32,32);
		// 		glColor3f(0,0,0);
		// 		glScalef(0.8,1,1);
		// 		glTranslatef(0,0.01,0);
		// 		glutSolidSphere(0.1,32,32);
		// 	}
		// 	glPopMatrix();
			
		// 	glPushMatrix(); // ventrale
		// 	{
		// 		glColor3f(0.976, 0.443, 0.101);
		// 		glTranslatef(0,-0.45,0);
		// 		glRotatef(-33,1,0,0);
		// 		glScalef(0.1,1,1);
		// 		glutSolidSphere(0.1,32,32);
		// 		glColor3f(0,0,0);
		// 		glScalef(0.8,1,1);
		// 		glTranslatef(0,-0.01,0);
		// 		glutSolidSphere(0.1,32,32);
		// 	}
		// 	glPopMatrix();
			
		// 	glPushMatrix(); // nageoire g
		// 	{
		// 		glColor3f(0.976, 0.443, 0.101);
		// 		glTranslatef(-0.5,0,0);
		// 		glRotatef(-45,0,1,0);
		// 		glScalef(0.1,1,1);
		// 		glutSolidSphere(0.1,32,32);
				
		// 		glTranslatef(0,0,0.01);
		// 		glColor3f(0,0,0);
		// 		glScalef(0.5,1,1);
		// 		glutSolidSphere(0.1,32,32);
		// 	}
		// 	glPopMatrix();
			
		// 	glPushMatrix(); // nageoire d
		// 	{
		// 		glColor3f(0.976, 0.443, 0.101);
		// 		glTranslatef(0.5,0,0);
		// 		glRotatef(45,0,1,0);
		// 		glScalef(0.1,1,1);
		// 		glutSolidSphere(0.1,32,32);
				
		// 		glTranslatef(0,0,0.01);
		// 		glColor3f(0,0,0);
		// 		glScalef(0.5,1,1);
		// 		glutSolidSphere(0.1,32,32);
		// 	}
		// 	glPopMatrix();
			
		// 	glPushMatrix(); // blanc 1
		// 	{
		// 		glColor3f(1,1,1);
		// 		glTranslatef(0,0,-0.3);
		// 		gluCylinder(obj,0.4,0.47,0.1,32,32);
		// 	}
		// 	glPopMatrix();
		// 	glPushMatrix(); // blanc 2
		// 	{
		// 		glColor3f(1,1,1);
		// 		glTranslatef(0,0,0.2);
		// 		gluCylinder(obj,0.47,0.4,0.1,32,32);
		// 	}
		// 	glPopMatrix();
			
		// 	glScalef(1,1,0.5);
			
		// 	glPushMatrix(); // queue
		// 	{
		// 		glTranslatef(0,0,0.5);
		// 		glColor3f(0.976, 0.443, 0.101);
		// 		gluCylinder(obj,0.45,0.2,0.5,32,32);
				
		// 		glTranslatef(0,0,0.5);
		// 		glColor3f(1,1,1);
		// 		gluCylinder(obj,0.2,0.1,0.2,32,32);
				
		// 		glTranslatef(0,0,0.18);
		// 		glutSolidSphere(0.1,32,32);
				
		// 		glTranslatef(0,0,0.1);
		// 		glColor3f(0.976, 0.443, 0.101);
		// 		glScalef(0.2,1.3,1);
		// 		glutSolidSphere(0.2,32,32);
				
		// 		glTranslatef(0,0,0.01);
		// 		glColor3f(0,0,0);
		// 		glScalef(0.5,1,1);
		// 		glutSolidSphere(0.2,32,32);
				
		// 	}
		// 	glPopMatrix();
		// }
		// glPopMatrix();


		glPushMatrix(); //box clown
		{
			glTranslatef(aleatoire_clown ,position_clown_y ,position_clown_z);
			glScalef(2,2,3);
			glColor4f(1,1,1,0.5);
			glutSolidCube(2.0);
			glEnd();
		}
		glPopMatrix();



		// glPushMatrix(); // Poisson : Zancle modele box
		// {
		// 	glTranslatef(0,5,100);
		// 	glScalef(3,3,3);
		// 	if(position_z > 925 && position_z < 1000)
		// 	{
		// 		position_y = -50;
		// 		position_zancle_z -= 2;
		// 		if(position_zancle_z< 900)
		// 		{
		// 			srand(time(NULL));
		// 			aleatoire_zancle = (rand() % 25) * positif_ou_negatif_zancle;
		// 			position_zancle_z = 1800;
		// 			positif_ou_negatif_zancle = -positif_ou_negatif_zancle;
		// 		}
				
		// 	}


		// 	GLUquadricObj *obj = gluNewQuadric();
		// 	glScalef(0.3,1,1);
			
		// 	glColor3f(0,0,0);
		// 	gluDisk(obj,0.01,0.05,32,32);
		// 	gluCylinder(obj,0.05,0.1,0.2,32,32);
			
		// 	glTranslatef(0,0,0.2);
		// 	glColor3f(0.925, 0.921, 0.611);
		// 	gluCylinder(obj,0.1,0.2,0.1,32,32);
			
		// 	glTranslatef(0,0,0.1);
		// 	glColor3f(0,0,0);
		// 	gluCylinder(obj,0.2,0.5,0.2,32,32);
		// 	glPushMatrix(); // yeux
		// 	{
		// 		glColor3f(1,1,1);
		// 		glTranslatef(0.3,0.2,0.1);
		// 		glutSolidSphere(0.05,32,32);
				
		// 		glTranslatef(-0.6,0,0);
		// 		glutSolidSphere(0.05,32,32);
		// 	}
		// 	glPopMatrix();
			
		// 	glTranslatef(0,0,0.2);
		// 	glColor3f(0.925, 0.921, 0.611);
		// 	gluCylinder(obj,0.5,0.51,0.3,32,32);
			
			
		// 	glTranslatef(0,0,0.3);
		// 	glColor3f(0,0,0);
		// 	gluCylinder(obj,0.51,0.3,0.2,32,32);
			
		// 	glTranslatef(0,0,0.2);
		// 	glColor3f(0.925, 0.921, 0.611);
		// 	gluCylinder(obj,0.3,0.1,0.1,32,32);
			
		// 	glTranslatef(0,0,0.1);
		// 	glColor3f(0,0,0);
		// 	gluCylinder(obj,0.1,0.3,0.2,32,32);
			
		// 	glScalef(0.5,1,1);
		// 	glTranslatef(0,0,0.2);
		// 	gluDisk(obj,0,0.3,32,32);
		// }
		// glPopMatrix();


		glPushMatrix(); //box zancle 
		{
			glTranslatef(aleatoire_zancle ,position_zancle_y ,position_zancle_z + 2);
			glScalef(1,2,2);
			glColor4f(1,1,1,0.5);
			glutSolidCube(2.0);
			glEnd();
		}
		glPopMatrix();
	}
	glPopMatrix();


	// glPushMatrix(); // algue
	// {
	// 	glPushMatrix(); //boule de terre
	// 	{
	// 		glTranslatef(0,5,20);
	// 		glColor3f(0.54,0.27,0.07);
	// 		glScalef(2,1,2);
	// 		glutSolidSphere(2,8,8);
	// 		glEnd();
	// 	}
	// 	glPopMatrix();

	// 	glPushMatrix(); //feuille d'algue gauche
	// 	{

	// 		glPushMatrix(); //petite feuille d'algue gauche
	// 		{
	// 			glTranslatef(-4,18,20);
	// 			glRotatef(-20,0,0,1);
	// 			glColor3f(0,0.51,0);
	// 			glScalef(0.5,2,0.25);
	// 			glutSolidSphere(2,8,8);
	// 			glEnd();
	// 		}
	// 		glPopMatrix();


	// 		glTranslatef(-4,13,20);
	// 		glRotatef(20,0,0,1);
	// 		glColor3f(0,0.51,0);
	// 		glScalef(0.5,5,0.25);
	// 		glutSolidSphere(2,8,8);
	// 		glEnd();
	// 	}
	// 	glPopMatrix();

	// 	glPushMatrix(); //feuille d'algue devant
	// 	{


	// 		glPushMatrix(); //petite feuille d'algue devant
	// 		{
	// 			glTranslatef(0,15,24);
	// 			glRotatef(90,0,1,0);
	// 			glRotatef(-20,0,0,1);
	// 			glColor3f(0,0.51,0);
	// 			glScalef(0.5,1.5,0.25);
	// 			glutSolidSphere(2,8,8);
	// 			glEnd();
	// 		}
	// 		glPopMatrix();


	// 		glTranslatef(0,10,24);
	// 		glRotatef(90,0,1,0);
	// 		glRotatef(20,0,0,1);
	// 		glColor3f(0,0.51,0);
	// 		glScalef(0.5,3,0.25);
	// 		glutSolidSphere(2,8,8);
	// 		glEnd();
	// 	}
	// 	glPopMatrix();



	// 	glPushMatrix(); //feuille d'algue arrière
	// 	{


	// 		glPushMatrix(); //petite feuille d'algue arrière
	// 		{
	// 			glTranslatef(0,10,18);
	// 			glRotatef(-90,0,1,0);
	// 			glRotatef(-20,0,0,1);
	// 			glColor3f(0,0.51,0);
	// 			glScalef(0.25,1,0.125);
	// 			glutSolidSphere(2,8,8);
	// 			glEnd();
	// 		}
	// 		glPopMatrix();


	// 		glTranslatef(0,10,16);
	// 		glRotatef(-90,0,1,0);
	// 		glRotatef(20,0,0,1);
	// 		glColor3f(0,0.51,0);
	// 		glScalef(0.5,3,0.25);
	// 		glutSolidSphere(2,8,8);
	// 		glEnd();
	// 	}
	// 	glPopMatrix();



	// 	glPushMatrix(); //feuille d'algue gauche
	// 	{


	// 		glPushMatrix(); //petite feuille d'algue droite
	// 		{
	// 			glTranslatef(2,14,20);
	// 			glRotatef(20,0,0,1);
	// 			glColor3f(0,0.51,0);
	// 			glScalef(0.5,2,0.25);
	// 			glutSolidSphere(2,8,8);
	// 			glEnd();
	// 		}
	// 		glPopMatrix();



	// 		glTranslatef(4,13,20);
	// 		glRotatef(-20,0,0,1);
	// 		glColor3f(0,0.51,0);
	// 		glScalef(0.5,5,0.25);
	// 		glutSolidSphere(2,8,8);
	// 		glEnd();
	// 	}
	// 	glPopMatrix();

	// 	glEnd();
	// }
	// glPopMatrix();


	glPushMatrix(); //création d'algue
	{

		for (int i = 1; i < 70; ++i)
		{
			creer_algue(60, -75 - (i+angle_algue), 890 + i*15);
			creer_algue(-60, -75 - (i + angle_algue), 890 + i*15);
			//creer_algue(0 + (5 * -algue_positif_negatif), -70, 925 + i*5);
			//algue_positif_negatif = -algue_positif_negatif;
			// nb_algue += 1;
			if(i == 0)
			{
				angle_algue = 0;
			}
		}
		

		glEnd();
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

		glEnd();
	}
	glPopMatrix();


// FIN DE MODELISATION

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
