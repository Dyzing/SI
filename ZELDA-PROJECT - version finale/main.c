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
#include <unistd.h>
#include <GL/freeglut.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


GLfloat xrot = 0.0f;   
int yrot = -180;   

GLfloat z = -5.0f; 
int blend = 0;
int light = 0;

GLuint texture[1];


int angle_triangle = -90;
GLfloat angle_oiseau_vertical = 0;
GLfloat angle_aile = 0;

GLfloat angle_queue_secondaire = 0;

int montee0_descente1_oiseaux_secondaire = 0;

int montee0_descente1 = 0;
int montee0_descente1_tete_secondaire = 0;

int montee0_descente1_queue_secondaire = 0;


GLfloat position_x = 0;
GLfloat position_y = 2;
GLfloat position_z = 0;


GLfloat position_dark_x = 4200;
GLfloat position_dark_y = 5022;
GLfloat position_dark_z = 5000;

GLfloat position_x_beta = 1400;
GLfloat position_y_beta = 2010;
GLfloat position_z_beta = 2000;


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

GLfloat angle_rocher = 1.0;

GLfloat position_x_rocher = 1000;
GLfloat position_y_rocher = 1200;
GLfloat position_z_rocher = 1232;

GLfloat position_x_rocher_gauche = 1020;
GLfloat position_y_rocher_gauche = 1300;
GLfloat position_z_rocher_gauche = 1332;

GLfloat position_x_rocher_droite = 980;
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

GLfloat position_bouee_x = -10;
GLfloat position_bouee_y = -48;
GLfloat position_bouee_z = 1300;


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


struct AABB3D box_bouee;

struct AABB3D box_aura;


struct AABB3D box_maison_droite_1;
struct AABB3D box_maison_droite_2;
struct AABB3D box_maison_droite_3;
struct AABB3D box_maison_gauche_1;
struct AABB3D box_maison_gauche_2;
struct AABB3D box_maison_gauche_3;


int aleatoire_simon = 0;
float transparence_simon_bleu = 0.3;
float transparence_simon_rouge = 0.3;
float transparence_simon_jaune = 0.3;
float transparence_simon_vert = 0.3;
int tour_suivant = 1;

int cube_time = 1;
int cube_attente = 0;

char simon[10];
int max_simon = 5;
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

int mouse_motion_y_middle = 0;
int mouse_motion_x_middle = 0;


GLfloat dent_x = 0;
GLfloat dent_y = 0;
GLfloat dent_z = 0;

int aleatoire_requin = 0;
int aleatoire_turbot = 25;
int aleatoire_clown = -25;
int aleatoire_zancle = 10;
int aleatoire_bouee = -10;


int positif_ou_negatif_requin = 1;
int positif_ou_negatif_turbot = 1;
int positif_ou_negatif_clown = 1;
int positif_ou_negatif_zancle = 1;
int positif_ou_negatif_bouee = 1;


struct AABB3D box_requin;
struct AABB3D box_turbot;
struct AABB3D box_clown;
struct AABB3D box_zancle;

int algue_positif_negatif = 1;
int nb_algue = 1;
float angle_algue = 0.5;

float angle_petit_cactus = 0.5;


float angle_jambe = 1;
float angle_jambe_cote = 1;
float angle_jambe_dark = 1;
int jambe_avant_arriere = 1;
int jambe_avant_arriere_dark = 1;
int jambe_cote = 1;

float transparence_boule_1 = 0.1;
float transparence_boule_2 = 0.1;
float transparence_boule_3 = 0.1;
float transparence_boule_4 = 0.1;
float transparence_boule_5 = 0.1;
float transparence_boule_6 = 0.1;

int nb_bouees_rentres = 0;
char nb_bouees_rentres_char[1];

bool touche_requin = true;
bool touche_turbot = true;
bool touche_nemo = true;
bool touche_zancle = true;

float angle_bras_gauche = 1;
float angle_bras_droit = 1;

int bras_gauche = 0;
int bras_droit = 0;

int montee0_descente1_bras_gauche = 2;
int montee0_descente1_bras_droit = 2;
int garde = 0;


int bras_gauche_dark = 0;
int bras_droit_dark = 0;

int montee0_descente1_bras_gauche_dark = 2;
int montee0_descente1_bras_droit_dark = 2;
int garde_dark = 0;

float angle_bras_gauche_dark = 1;
float angle_bras_droitp_dark = 1;



int link_bouge = 0;

struct AABB3D box_epee;
struct AABB3D box_epee_dark;


struct AABB3D box_dark;

float couleur_barre_r = 0;
float couleur_barre_g = 1;
float couleur_barre_b = 0;

float transparence_barre_1 = 1;
float transparence_barre_2 = 1;
float transparence_barre_3 = 1;

float transparence_vie_1 = 1;
float transparence_vie_2 = 1;
float transparence_vie_3 = 1;

int vie_dark_link = 3;
int vie_vrai_link = 3;


bool touche_dark_link = true;
bool touche_vrai_link = true;

int aleatoire_dark_link_epee = 0;
bool bras_gauche_bouge = false;

int aleatoire_dark_link_bouclier = 0;
bool bras_droit_bouge = false;

int aleatoire_temps_bouclier = 0;

int rotation_mort = 0;
float translation_mort = 0;
int rotation_mort_vrai_link = 0;
float translation_mort_vrai_link = 0;

bool dark_link_mort = false; 
bool arreter_animation_dark = false; 

int aleatoire_position_dark_x = 4200;
int aleatoire_position_dark_z = 5000;

int positif_ou_negatif_dark_link_x = 1;
int positif_ou_negatif_dark_link_z = 1;

float couleur_tor = 1;

float yrot_middle = -180;
float xrot_middle = 0;
int camera_middle = 0;

int angle_triforce = 0;


	// Déclarations Tic-Tac-Toe
	int victoire = 0;
	int ttt_tour = 0;

	int ttt_0 = 0;
	int ttt_1 = 0;
	int ttt_1_color = 0;
	int ttt_2 = 0;
	int ttt_2_color = 0;
	int ttt_3 = 0;
	int ttt_3_color = 0;
	int ttt_4 = 0;
	int ttt_4_color = 0;
	int ttt_5 = 0;
	int ttt_5_color = 0;
	int ttt_6 = 0;
	int ttt_6_color = 0;
	int ttt_7 = 0;
	int ttt_7_color = 0;
	int ttt_8 = 0;
	int ttt_8_color = 0;
	int ttt_9 = 0;
	int ttt_9_color = 0;

bool message = false;

float res_prediction_avancer = 0;
float res_prediction_reculer = 0;

bool peut_avancer_maison_1 = true;
bool peut_avancer_maison_2 = true;
bool peut_avancer_maison_3 = true;
bool peut_avancer_maison_4 = true;
bool peut_avancer_maison_5 = true;
bool peut_avancer_maison_6 = true;


int i_arbre = -1;
int compteur_arbre_x;
int compteur_arbre_z;



// variables


void creer_fleur(float x, float y, float z)
{
	
	glPushMatrix(); //fleur intégrale
	{	
		glTranslatef(x,y,z);

		glPushMatrix(); //fleur
		{
			glEnable(GL_DEPTH_TEST);
			glTranslatef(20,0.5,-20);
			glRotatef(120,0,1,0);
			glRotatef(-20,1,0,0);
			glScalef(5,5,5);
			glColor4f(1,0.71, 0.75, 0.4);
			GLUquadric* cone = gluNewQuadric();
	    	
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

		glEnd();
	}
	glPopMatrix();
}


void tout_a_zero(){
	victoire = 0;
	ttt_tour = 0;
	ttt_0 = 0;
	
	ttt_1 = 0;	ttt_1_color = 0;
	ttt_2 = 0;	ttt_2_color = 0;
	ttt_3 = 0;	ttt_3_color = 0;
	ttt_4 = 0;	ttt_4_color = 0;
	ttt_5 = 0;	ttt_5_color = 0;
	ttt_6 = 0;	ttt_6_color = 0;
	ttt_7 = 0;	ttt_7_color = 0;
	ttt_8 = 0;	ttt_8_color = 0;
	ttt_9 = 0;	ttt_9_color = 0;
}



void creer_cloture(float x, float y, float z, float angle)
{
	glPushMatrix(); //clôture 
	{
		glTranslatef(x,y,z);
		glRotatef(angle, 0,1,0);
		glPushMatrix(); //barreau droit
		{
			glTranslatef(0,5,0);
			glScalef(0.5,0.5,5);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 1
		{
			glTranslatef(0,0,-7);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 2
		{
			glTranslatef(0,0,7);
			glScalef(0.3,5.5,0.3);
			glColor3f(0.87, 0.72, 0.52);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glEnd();

	}
	glPopMatrix();
}


void creer_triforce()
{
	glPushMatrix(); //triforce
	{
		
		glScalef(6,6,6);
		glColor3f(1,0.8,0);
		glBegin( GL_TRIANGLES ); 
			 // Front
	      glVertex3f( 0.0f, 1.0f, 0.0f);
	      glVertex3f(-1.0f, -1.0f, 1.0f);
	      glVertex3f(1.0f, -1.0f, 1.0f);
	 
	      // Right
	      glVertex3f(0.0f, 1.0f, 0.0f);
	      glVertex3f(1.0f, -1.0f, 1.0f);
	      glVertex3f(1.0f, -1.0f, -1.0f);
	 
	      // Back
	      glVertex3f(0.0f, 1.0f, 0.0f);
	      glVertex3f(1.0f, -1.0f, -1.0f);
	      glVertex3f(-1.0f, -1.0f, -1.0f);
	 
	      // Left
	      glVertex3f( 0.0f, 1.0f, 0.0f);
	      glVertex3f(-1.0f,-1.0f,-1.0f);
	      glVertex3f(-1.0f,-1.0f, 1.0f);
		glEnd();
	}
	glPopMatrix();
}


void creer_cadre(float x, float y, float z, float angle)
{
	glPushMatrix(); //cadre
	{
		glTranslatef(x,y,z);
		glRotatef(angle, 0,1,0);
		glPushMatrix(); //contour
		{
			glScalef(1,1,0.1);
			glColor3f(1	,0.85,0.59);
			glutSolidCube(5.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //liege
		{
			glTranslatef(0,0,-0.4);
			glScalef(0.8,0.8,0.05);
			glColor3f(0.83,0.64,0.3);
			glutSolidCube(5.0);			
			glEnd();
		}
		glPopMatrix();

		glEnd();
	}
	glPopMatrix();


}

void creer_sphere(int x, float transparence)
{
	glPushMatrix();
	{
		glTranslatef(x ,10,-10);	

		

		glRotatef(-yrot, 0,1,0);
		glColor4f(0,1,0,transparence);
		glutSolidSphere(1,20,20);
		glEnd();
	}
	glPopMatrix();
}



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
			creer_fleur(160*i + espace*i, 0, -100 + espace + ligne);

			creer_sakura(-40*i + espace*i, 0, -400 + espace + ligne);
			creer_arbre_lambda(180*i + espace*i, 0, -250 + espace + ligne);
			creer_sapin(280*i + espace*i, 0, -335 + espace + ligne);
			creer_fleur(-10*i + espace*i, 0, -300 + espace + ligne);

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


void creer_petit_cactus(float x, float y, float z)
{

	glPushMatrix(); // petit cactus
	{

		glTranslatef(x,y,z);


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


void creer_coeur(float x, float y, float z, float transparence_vie)
{
	glPushMatrix(); //coeur
	{
		glTranslatef(x,y,z);
		glScalef(0.5,0.5,0.5);

		glPushMatrix(); //le rouge du coeur devant
		{

			
			glRotatef(180,1,0,0);
			glRotatef(180,0,1,0);
			glColor4f(1,0,0, transparence_vie);

			glPushMatrix();
			{
				glTranslatef(-0.8,-1,0.5);
				glRotatef(-180,1,0,0);
				glRotatef(-210,0,1,0);
				glRotatef(20,0,0,1);
				glScalef(1.5,1,0.5);
				glutSolidSphere(1,8,8);
				glEnd();	
			}
			glPopMatrix();

			glPushMatrix();
			{
				glTranslatef(0.8,-1,0.5);
				glRotatef(-180,1,0,0);
				glRotatef(210,0,1,0);
				glRotatef(-20,0,0,1);
				glScalef(1.5,1,0.5);				
				glutSolidSphere(1,8,8);
				glEnd();	
			}
			glPopMatrix();




			glScalef(2,1,1);
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

		glPushMatrix(); //le rouge du coeur derriere
		{

			glTranslatef(0,0,2);
			glRotatef(180,1,0,0);
			glColor4f(1,0,0, transparence_vie);

			glPushMatrix();
			{
				glTranslatef(-0.8,-1,0.5);
				glRotatef(-180,1,0,0);
				glRotatef(-210,0,1,0);
				glRotatef(20,0,0,1);
				glScalef(1.5,1,0.5);
				
				
				glutSolidSphere(1,8,8);
				glEnd();	
			}
			glPopMatrix();

			glPushMatrix();
			{
				glTranslatef(0.8,-1,0.5);
				glRotatef(-180,1,0,0);
				glRotatef(210,0,1,0);
				glRotatef(-20,0,0,1);
				glScalef(1.5,1,0.5);				
				glutSolidSphere(1,8,8);
				glEnd();	
			}
			glPopMatrix();




			glScalef(2,1,1);
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


		glPushMatrix(); //contour noir
		{
			glTranslatef(0,0,1);
			glRotatef(180,1,0,0);
			glRotatef(180,0,1,0);
			glColor4f(0,0,0, transparence_vie);

			glScalef(1.25,1.23,0.1);

			glPushMatrix();
			{
				glTranslatef(-0.8,-1,0.5);
				glRotatef(-180,1,0,0);
				glRotatef(-210,0,1,0);
				glRotatef(20,0,0,1);
				glScalef(1.5,1,0.5);
				
				glutSolidSphere(1,8,8);
				glEnd();	
			}
			glPopMatrix();

			glPushMatrix();
			{
				glTranslatef(0.8,-1,0.5);
				glRotatef(-180,1,0,0);
				glRotatef(210,0,1,0);
				glRotatef(-20,0,0,1);
				glScalef(1.5,1,0.5);
				
				glutSolidSphere(1,8,8);
				glEnd();	
			}
			glPopMatrix();




			glScalef(2,1,1);
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
	  glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
		glShadeModel(GL_SMOOTH);

	}
	else if (lumiere_lampadaire == 0)
	{
		glDisable(GL_LIGHT0);
	}



	glPushMatrix(); // OISEAU dino
  	{
		glEnable(GL_BLEND); 
	  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



		if(position_x_beta <= 2005 && position_y >= 1999 && position_y <= 2500)
		{
			position_x_beta = position_x_beta + 3;
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
			position_y = 2;
			position_z = 20;
			transparence_boule_3 = 1;
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
		glEnd();

	}
	glPopMatrix();


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






	if(position_y > 1000 && position_y < 1700) // ILE ROCHER TOMBER
	{
		glPushMatrix(); // ILE ROCHER TOMBER
		{

			glPushMatrix(); //ile 1 
			{
				glTranslatef(1000,1000,1000);
				glScalef(50,1,40);
				glColor3f(0.43, 0.57, 0);
				glutSolidCube(3.0);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //lampadaire rocher
			{

				glTranslatef(1050,1039,1030);
				glRotatef(180,0,1,0);

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
				glEnd();

			}
			glPopMatrix();


			glPushMatrix(); //rocher mileux
			{
				glTranslatef(position_x_rocher,position_y_rocher,position_z_rocher);

				
				box_rocher_milieu.x = position_x_rocher;
				box_rocher_milieu.y = position_y_rocher;
				box_rocher_milieu.z = position_z_rocher;

				box_rocher_milieu.w = 10;
				box_rocher_milieu.h = 10;
				box_rocher_milieu.d = 10;

				if(Collision(box_rocher_milieu, box_personnage) && position_y <= 1420)
				{	
					position_x = 0;
					position_y = 2;
					position_z = 20;
				}


				glRotatef(angle_rocher, 1,0,0);
				angle_rocher -= 10;
				position_y_rocher -= 4;
				position_z_rocher -= 4;
				if ((position_y_rocher <= 985) && (position_z_rocher <= 940))
				{
					position_y_rocher = 1500;
					position_z_rocher = 1532;
				}
				glColor3f(0.54,0.27,0.07);
				glScalef(1,1,1);
				glutSolidSphere(10,7,7);
				glEnd();
			}
			glPopMatrix();


			glPushMatrix(); //rocher gauche
			{
				glTranslatef(position_x_rocher_gauche,position_y_rocher_gauche,position_z_rocher_gauche);

				box_rocher_gauche.x = position_x_rocher_gauche;
				box_rocher_gauche.y = position_y_rocher_gauche;
				box_rocher_gauche.z = position_z_rocher_gauche;

				box_rocher_gauche.w = 10;
				box_rocher_gauche.h = 10;
				box_rocher_gauche.d = 10;

				if(Collision(box_rocher_gauche, box_personnage) && position_y <= 1420)
				{	
					position_x = 0;
					position_y = 2;
					position_z = 20;
				}



				glRotatef(angle_rocher, 1,0,0);
				angle_rocher -= 10;
				position_y_rocher_gauche -= 5;
				position_z_rocher_gauche -= 5;
				if ((position_y_rocher_gauche <= 1000) && (position_z_rocher_gauche  <= 970))
				{
					position_y_rocher_gauche = 1500;
					position_z_rocher_gauche = 1532;
				}
				glColor3f(0.54,0.27,0.07);
				glScalef(1,1,1);
				glutSolidSphere(10,7,7);
				glEnd();
			}
			glPopMatrix();


			glPushMatrix(); //rocher droite
			{
				glTranslatef(position_x_rocher_droite,position_y_rocher_droite,position_z_rocher_droite);

				box_rocher_droite.x = position_x_rocher_droite;
				box_rocher_droite.y = position_y_rocher_droite;
				box_rocher_droite.z = position_z_rocher_droite;

				box_rocher_droite.w = 10;
				box_rocher_droite.h = 10;
				box_rocher_droite.d = 10;

				if(Collision(box_rocher_droite, box_personnage) && position_y <= 1420)
				{	
					position_x = 0;
					position_y = 2;
					position_z = 20;
				}


				glRotatef(angle_rocher, 1,0,0);
				angle_rocher -= 10;
				position_y_rocher_droite -= 3;
				position_z_rocher_droite -= 3;
				if ((position_y_rocher_droite <= 970) && (position_z_rocher_droite  <= 950))
				{
					position_y_rocher_droite = 1550;
					position_z_rocher_droite = 1582;
				}
				glColor3f(0.54,0.27,0.07);
				glScalef(1,1,1);
				glutSolidSphere(10,7,7);
				glEnd();
			}
			glPopMatrix();




			glPushMatrix(); //pente
			{
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_BLEND); 
				 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glTranslatef(1000,1050,1100);
				glRotatef(-45,1,0,0);
				glScalef(15,1,200);
				glColor4f(0.5,0.5,0, 0.8);
				glutSolidCube(5.0);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //mur pente gauche
			{
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_BLEND); 
				 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glTranslatef(835,1050,1100);
				glRotatef(-45,1,0,0);
				glRotatef(65,0,0,1);
				glScalef(15,50,200);
				glColor4f(0.6,0.4	,0, 0.8);
				glutSolidCube(5.0);
				glEnd();
			}
			glPopMatrix();



			glPushMatrix(); //mur pente gauche
			{
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_BLEND); 
				 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glTranslatef(1165,1050,1100);
				glRotatef(-45,1,0,0);
				glRotatef(-65,0,0,1);
				glScalef(15,50,200);
				glColor4f(0.6,0.4,0, 0.8);
				glutSolidCube(5.0);
				glEnd();
			}
			glPopMatrix();


			glPushMatrix(); //arrivée
			{
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_BLEND); 
				 glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glTranslatef(1000,1403,1552);
				glRotatef(0,1,0,0);
				glScalef(15,1,40);
				glColor4f(0.5,0.5,0, 0.8);
				glutSolidCube(5.0);
				glEnd();
			}
			glPopMatrix();


			glPushMatrix(); //lampadaire
			{

				glTranslatef(1040,1425,1542);
				glRotatef(90,0,1,0);

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
				glEnd();

			}
			glPopMatrix();


			glPushMatrix(); //Maison rocher
			{

				glTranslatef(1100, 1425, 1580);
				glRotatef(-180,0,1,0);


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
					glTranslatef(101.5,12,17);
					glScalef(1.9,1.5,0.4);
					glColor3f(0.77,0.69,0.49);
					glutSolidCube(7.0);
					glEnd();
				}
				glPopMatrix();

				glPushMatrix(); //mur de devant au mileu en haut texture
				{		
					glTranslatef(94.85,6.75,18.502);
					glBegin(GL_QUADS);
					glColor3f(1,1,1);
						glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
						//set point in 3D and texture space
						glTexCoord2f(0.0f,0.0f);
						glVertex3f(0.0f,0.0f,0.0f);
						
						glTexCoord2f(1.0f,0.0f);
						glVertex3f(13.3f,0.0f,0.0f);
						
						glTexCoord2f(1.0f,1.0f);
						glVertex3f(13.3f,10.5f,0.0f);
						
						glTexCoord2f(0.0f,1.0f);
						glVertex3f(0.0f,10.5f,0.0f);

					glEnd();
				}
				glPopMatrix();


				glPushMatrix(); //fentre en devant gauche
				{		
					glTranslatef(82.5,8,18.5);
					glScalef(2,1.5,0.4);
					glColor3f(1,1,1);
					glutSolidCube(7.0);
					glEnd();
				}
				glPopMatrix();



				glPushMatrix(); //fentre en devant droite
				{		
					glTranslatef(119.5,8,18.5);
					glScalef(2,1.5,0.4);
					glColor3f(1,1,1);
					glutSolidCube(7.0);
					glEnd();
				}
				glPopMatrix();


			}
			glPopMatrix();

			glEnd();
		}
		glPopMatrix();
	}
	


	glPushMatrix(); //Maison droite 1
	{
		glTranslatef(120, 0, -50);


			box_maison_droite_1.x = 120;
			box_maison_droite_1.y = 0;
			box_maison_droite_1.z = 25;


			box_maison_droite_1.w = 50;
			box_maison_droite_1.h = 60;
			box_maison_droite_1.d = 60;

			if(Collision(box_maison_droite_1, box_personnage))
			{	
				peut_avancer_maison_1 = false;
			}
			else
			{
				peut_avancer_maison_1 = true;
			}


		glRotatef(-90,0,1,0);


		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor3f(0.53,0.43,0.27);
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
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit droit
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
			glPopMatrix();


		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,12,17);

			creer_cadre(0,0,2,180);

			glPushMatrix(); //logo rocher 
			{
				glTranslatef(0,0,3);
				glColor3f(0.54,0.27,0.07);
				glScalef(1,1,1);
				glutSolidSphere(1,7,7);
				glEnd();
			}
			glPopMatrix();

			glScalef(1.9,1.5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //mur de devant au mileu en haut texture
		{		
			glTranslatef(94.85,6.75,18.502);
			glBegin(GL_QUADS);
			glColor3f(1,1,1);
				glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
				//set point in 3D and texture space
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(0.0f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,0.0f);
				glVertex3f(13.3f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,1.0f);
				glVertex3f(13.3f,10.5f,0.0f);
				
				glTexCoord2f(0.0f,1.0f);
				glVertex3f(0.0f,10.5f,0.0f);

			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); // carre noir porte
		{
			glTranslatef(101.5,-6,15);
			glScalef(1.9,3.5,0.4);
			glColor3f(0,0,0);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


	}
	glPopMatrix();



	glPushMatrix(); //Maison gauche 1
	{

		glTranslatef(-120, 0, 100);



		box_maison_gauche_1.x = -155;
		box_maison_gauche_1.y = 0;
		box_maison_gauche_1.z = -30;


		box_maison_gauche_1.w = 50;
		box_maison_gauche_1.h = 60;
		box_maison_gauche_1.d = 60;

		if(Collision(box_maison_gauche_1, box_personnage))
		{	
			peut_avancer_maison_4 = false;
		}
		else
		{
			peut_avancer_maison_4 = true;
		}



		glRotatef(90,0,1,0);




		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor3f(0.53,0.43,0.27);
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
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit droit
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
			glPopMatrix();


		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,12,17);

			creer_cadre(0,0,2,-180);


			glPushMatrix(); //dinosaure logo
			{

				glTranslatef(0.5,0.5,1);
				glScalef(0.1,0.1,0.1);

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

			glScalef(1.9,1.5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //mur de devant au mileu en haut texture
		{		
			glTranslatef(94.85,6.75,18.502);
			glBegin(GL_QUADS);
			glColor3f(1,1,1);
				glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
				//set point in 3D and texture space
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(0.0f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,0.0f);
				glVertex3f(13.3f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,1.0f);
				glVertex3f(13.3f,10.5f,0.0f);
				
				glTexCoord2f(0.0f,1.0f);
				glVertex3f(0.0f,10.5f,0.0f);

			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); // carre noir porte
		{
			glTranslatef(101.5,-6,15);
			glScalef(1.9,3.5,0.4);
			glColor3f(0,0,0);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


	}
	glPopMatrix();



	glPushMatrix(); //Maison gauche 2
	{

		glTranslatef(-120, 0, 250);



		box_maison_gauche_2.x = -155;
		box_maison_gauche_2.y = 0;
		box_maison_gauche_2.z = 120;

		box_maison_gauche_2.w = 50;
		box_maison_gauche_2.h = 60;
		box_maison_gauche_2.d = 60;

		if(Collision(box_maison_gauche_2, box_personnage))
		{	
			peut_avancer_maison_5 = false;
		}
		else
		{
			peut_avancer_maison_5 = true;
		}


		glRotatef(90,0,1,0);




		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor3f(0.53,0.43,0.27);
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
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit droit
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
			glPopMatrix();


		
		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,12,17);	

			creer_cadre(0,0,2,-180);

			glPushMatrix(); //logo super simon
			{
				glTranslatef(0,0,2.5);
				glRotatef(90,0,1,0);
				glPushMatrix(); //cube bleu gauche super-simon
				{
					glTranslatef(0,0,1);
					glRotatef(45,1,0,0);
					glColor3f(0,0,1);
					glutSolidCube(1.0);
					glEnd();
				}
				glPopMatrix();

				glPushMatrix(); //cube vert droite super-simon
				{
					glTranslatef(0,0,-1);
					glRotatef(45,1,0,0);
					glColor3f(0,1,0);
					glutSolidCube(1.0);
					glEnd();
				}
				glPopMatrix();

				glPushMatrix(); //cube jaune haut super-simon
				{
					glTranslatef(0,1,0);
					glRotatef(45,1,0,0);
					glColor3f(1,1,0);
					glutSolidCube(1.0);
					glEnd();
				}
				glPopMatrix();

				glPushMatrix(); //cube rouge bas super-simon
				{
					glTranslatef(0,-1,0);
					glRotatef(45,1,0,0);
					glColor3f(1,0,0);
					glutSolidCube(1.0);
					glEnd();
				}
				glPopMatrix();

				glEnd();
			}
			glPopMatrix();


			glScalef(1.9,1.5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //mur de devant au mileu en haut texture
		{		
			glTranslatef(94.85,6.75,18.502);
			glBegin(GL_QUADS);
			glColor3f(1,1,1);
				glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
				//set point in 3D and texture space
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(0.0f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,0.0f);
				glVertex3f(13.3f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,1.0f);
				glVertex3f(13.3f,10.5f,0.0f);
				
				glTexCoord2f(0.0f,1.0f);
				glVertex3f(0.0f,10.5f,0.0f);

			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); // carre noir porte
		{
			glTranslatef(101.5,-6,15);
			glScalef(1.9,3.5,0.4);
			glColor3f(0,0,0);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();




	}
	glPopMatrix();


	glPushMatrix(); //Maison gauche 3
	{

		glTranslatef(-120, 0, 400);


		box_maison_gauche_3.x = -155;
		box_maison_gauche_3.y = 0;
		box_maison_gauche_3.z = 270;

		box_maison_gauche_3.w = 50;
		box_maison_gauche_3.h = 60;
		box_maison_gauche_3.d = 60;

		if(Collision(box_maison_gauche_3, box_personnage))
		{	
			peut_avancer_maison_6 = false;
		}
		else
		{
			peut_avancer_maison_6 = true;
		}


		glRotatef(90,0,1,0);




		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor3f(0.53,0.43,0.27);
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
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit droit
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
			glPopMatrix();


		
		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,12,17);

			creer_cadre(0,0,2,-180);

			glPushMatrix(); //logo épée
			{
				glTranslatef(1,-1,2.7);
				glRotatef(90,0,1,0);
				glRotatef(45,1,0,0);
				glScalef(0.4,0.4,0.4);

				glPushMatrix(); // épée
				{
					GLUquadricObj *obj = gluNewQuadric();
					glPushMatrix(); // pommeau
					{
						glColor3f(0.211, 0.168, 0.631);
						glTranslatef(0,0,-1.5);
						
						gluCylinder(obj,0.4,0.4,3,32,32);
						
						glTranslatef(0,0,2);
						
						gluCylinder(obj,0.4,0.6,2,32,32);
						glTranslatef(0,0,2);
						gluDisk(obj,0,0.6,32,32);
					}
					glPopMatrix();
					
					glTranslatef(0,0,-1.5);
					glRotatef(-180,1,0,0);
					
					glPushMatrix(); // garde
					{
						gluCylinder(obj,0.4,0.7,0.1,32,32);
						glTranslatef(0,0,0.1);
						gluCylinder(obj,0.7,0.5,0.3,32,32);
						glTranslatef(0,0,0.3);
						gluCylinder(obj,0.5,0.5,0.4,32,32);
						
						glPushMatrix(); // partie droite
						{
							glTranslatef(0,0.65,0.2);
							glRotatef(-10,1,0,0);
							
							glPushMatrix();
								glScalef(0.7,2,0.7);
								glutSolidCube(0.5);
							glPopMatrix();
							
							glPushMatrix();
								glTranslatef(0,0,0.25);
								glRotatef(-30,1,0,0);
								glTranslatef(0,0.32,0.2);
								glScalef(0.7,0.7,1.5);
								glRotatef(30,1,0,0);
								glutSolidCube(0.5);
							glPopMatrix();
						}
						glPopMatrix();
						
						glPushMatrix(); // partie gauche
						{
							glTranslatef(0,-0.65,0.2);
							glRotatef(10,1,0,0);
							
							glPushMatrix();
								glScalef(0.7,2,0.7);
								glutSolidCube(0.5);
							glPopMatrix();
							
							glPushMatrix();
								glTranslatef(0,0,0.25);
								glRotatef(30,1,0,0);
								glTranslatef(0,-0.32,0.2);
								glScalef(0.7,0.7,1.5);
								glRotatef(-30,1,0,0);
								glutSolidCube(0.5);
							glPopMatrix();
						}
						glPopMatrix();
						
						glTranslatef(0,0,0.4);
						gluCylinder(obj,0.5,0.7,0.4,32,32);
						glTranslatef(0,0,0.4);
						gluDisk(obj,0,0.7,32,32);
						
						glPushMatrix(); // porte-joyau
							glScalef(0.6,1,2);
							glutSolidSphere(0.5,32,32);
						glPopMatrix();
						
						glPushMatrix(); // joyau
							glColor3f(1,1,0);
							glScalef(0.8,0.5,1.5);
							glutSolidSphere(0.5,32,32);
						glPopMatrix();
					}
					glPopMatrix();
						
					glPushMatrix(); // lame
					{
						glTranslatef(0,0,1.2); // base
						glColor3f(.99,.99,.99);
						glScalef(0.2,0.6,1);
						gluCylinder(obj,0.7,0.7,2,32,32);
						
						glTranslatef(0,0,2); // base vers lame
						gluCylinder(obj,0.7,0.9,0.2,32,32);
						
						glTranslatef(0,0,0.2); // lame
						gluCylinder(obj,0.9,0.9,4,32,32);
						
						glTranslatef(0,0,4); // pointe
						gluCylinder(obj,0.9,0.7,0.3,32,32);
						glTranslatef(0,0,0.3);
						gluCylinder(obj,0.7,0.5,0.3,32,32);
						glTranslatef(0,0,0.3);
						gluCylinder(obj,0.5,0.3,0.3,32,32);
						glTranslatef(0,0,0.3);
						gluCylinder(obj,0.3,0,0.3,32,32);
					}
					glPopMatrix();
				}
				glPopMatrix();			

				glEnd();
			}
			glPopMatrix();

			glScalef(1.9,1.5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //mur de devant au mileu en haut texture
		{		
			glTranslatef(94.85,6.75,18.502);
			glBegin(GL_QUADS);
			glColor3f(1,1,1);
				glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
				//set point in 3D and texture space
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(0.0f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,0.0f);
				glVertex3f(13.3f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,1.0f);
				glVertex3f(13.3f,10.5f,0.0f);
				
				glTexCoord2f(0.0f,1.0f);
				glVertex3f(0.0f,10.5f,0.0f);

			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); // carre noir porte
		{
			glTranslatef(101.5,-6,15);
			glScalef(1.9,3.5,0.4);
			glColor3f(0,0,0);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



	}
	glPopMatrix();

	glPushMatrix(); //Maison droite 2
	{

		glTranslatef(120, 0, 100);



		box_maison_droite_2.x = 120;
		box_maison_droite_2.y = 0;
		box_maison_droite_2.z = 175;


		box_maison_droite_2.w = 50;
		box_maison_droite_2.h = 60;
		box_maison_droite_2.d = 60;

		if(Collision(box_maison_droite_2, box_personnage))
		{	
			peut_avancer_maison_2 = false;
		}
		else
		{
			peut_avancer_maison_2 = true;
		}





		glRotatef(-90,0,1,0);




		

		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor3f(0.53,0.43,0.27);
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
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit droit
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
			glPopMatrix();


		
		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,12,17);

			creer_cadre(0,0,2,180);

			glPushMatrix(); // logo  Clown
			{
				glTranslatef(0,0,3);
				glRotatef(90,0,1,0);

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

			glScalef(1.9,1.5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //mur de devant au mileu en haut texture
		{		
			glTranslatef(94.85,6.75,18.502);
			glBegin(GL_QUADS);
			glColor3f(1,1,1);
				glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
				//set point in 3D and texture space
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(0.0f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,0.0f);
				glVertex3f(13.3f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,1.0f);
				glVertex3f(13.3f,10.5f,0.0f);
				
				glTexCoord2f(0.0f,1.0f);
				glVertex3f(0.0f,10.5f,0.0f);

			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); // carre noir porte
		{
			glTranslatef(101.5,-6,15);
			glScalef(1.9,3.5,0.4);
			glColor3f(0,0,0);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



	}
	glPopMatrix();


	glPushMatrix(); //Maison droite 3
	{

		glTranslatef(120, 0, 250);



		box_maison_droite_3.x = 120;
		box_maison_droite_3.y = 0;
		box_maison_droite_3.z = 325;


		box_maison_droite_3.w = 50;
		box_maison_droite_3.h = 60;
		box_maison_droite_3.d = 60;

		if(Collision(box_maison_droite_3, box_personnage))
		{	
			peut_avancer_maison_3 = false;
		}
		else
		{
			peut_avancer_maison_3 = true;
		}

		glRotatef(-90,0,1,0);



	

		glPushMatrix(); //mur du fond
		{		
			glTranslatef(100,0,-30);
			glScalef(9,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de droite
		{		
			glTranslatef(131,-1,-6);
			glRotatef(90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //mur de gauche
		{		
			glTranslatef(70,-1,-6);
			glRotatef(-90, 0,1,0);
			glScalef(7,5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //plafond
		{		
			glTranslatef(101,18	,-6);
			glRotatef(90, 1,0,0);
			glScalef(9,7,0.4);
			glColor3f(0.53,0.43,0.27);
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
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //toit droit
		{		
			glTranslatef(122,25,-6);
			glRotatef(90, 1,0,0);
			glRotatef(-22.5, 0,1,0);
			glScalef(7,7,0.4);
			glColor3f(0.7,0.6,0.29);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //face avant toit
		{
			glTranslatef(101,27,17);
			glScalef(32,8.4,1);
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.85,0.85,0.85);
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
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mur de devant droite
		{		
			glTranslatef(120,-3,17);
			glScalef(3.5,5.6,0.4);
			glColor3f(0.53,0.43,0.27);
			glutSolidCube(7.0);
			glEnd();
		}
			glPopMatrix();


		
		glPushMatrix(); //mur de devant au mileu en haut
		{		
			glTranslatef(101.5,12,17);

			creer_cadre(0,0,2,180);

			glPushMatrix(); // logo cadre
			{
				glTranslatef(-1.5,-1.5,3);
				glScalef(0.3,0.3,0.3);
				glColor3f(0.2,0.2,0.2);				
				glPushMatrix();
				{
					glTranslatef(-0.5,0.5,0); // vers x
					for(int i = 0; i<10; i++){
						glTranslatef(1,0,0);
						glutSolidCube(1);
						if(i==3 || i==6){
							glPushMatrix();
								for(int j = 0; j<9; j++){
										glTranslatef(0,1,0);
										glutSolidCube(1);
								}
							glPopMatrix();
						}
					}
					
					glTranslatef(0,-1,0); // vers y
					for(int i = 0; i<10; i++){
						glTranslatef(0,1,0);
						glutSolidCube(1);
						if(i==3 || i==6){
							glPushMatrix();
								for(int j = 0; j<9; j++){
										glTranslatef(-1,0,0);
										glutSolidCube(1);
								}
							glPopMatrix();
						}
					}
					
					glTranslatef(1,0,0); // vers -x
					for(int i = 0; i<10; i++){
						glTranslatef(-1,0,0);
						glutSolidCube(1);
					}
					
					glTranslatef(0,1,0); // vers -y
					for(int i = 0; i<10; i++){
						glTranslatef(0,-1,0);
						glutSolidCube(1);
					}

					glEnd();
				}
				glPopMatrix();

				
			}
			glPopMatrix(); // fin cadre

			glScalef(1.9,1.5,0.4);
			glColor3f(0.77,0.69,0.49);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //mur de devant au mileu en haut texture
		{		
			glTranslatef(94.85,6.75,18.502);
			glBegin(GL_QUADS);
			glColor3f(1,1,1);
				glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
				//set point in 3D and texture space
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(0.0f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,0.0f);
				glVertex3f(13.3f,0.0f,0.0f);
				
				glTexCoord2f(1.0f,1.0f);
				glVertex3f(13.3f,10.5f,0.0f);
				
				glTexCoord2f(0.0f,1.0f);
				glVertex3f(0.0f,10.5f,0.0f);

			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); // carre noir porte
		{
			glTranslatef(101.5,-6,15);
			glScalef(1.9,3.5,0.4);
			glColor3f(0,0,0);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //fentre en devant gauche
		{		
			glTranslatef(82.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
			glutSolidCube(7.0);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //fentre en devant droite
		{		
			glTranslatef(119.5,8,18.5);
			glScalef(2,1.5,0.4);
			glColor3f(1,1,1);
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

	glPushMatrix(); //colline 6 du milieu
	{
		glTranslatef(0,-50, -450);
		glRotatef(-30,0,1,0);
		glColor3f(0.13,0.54,0.13);
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



	if(position_y > 2000 && position_y < 2500)
	{
		glPushMatrix(); //ile 2 dino
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
					glTranslatef(101.5,12,17);
					glScalef(1.9,1.5,0.4);
					glColor3f(0.77,0.69,0.49);
					glutSolidCube(7.0);
					glEnd();
				}
				glPopMatrix();

				glPushMatrix(); //mur de devant au mileu en haut texture
				{		
					glTranslatef(94.85,6.75,18.502);
					glBegin(GL_QUADS);
					glColor3f(1,1,1);
						glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
						//set point in 3D and texture space
						glTexCoord2f(0.0f,0.0f);
						glVertex3f(0.0f,0.0f,0.0f);
						
						glTexCoord2f(1.0f,0.0f);
						glVertex3f(13.3f,0.0f,0.0f);
						
						glTexCoord2f(1.0f,1.0f);
						glVertex3f(13.3f,10.5f,0.0f);
						
						glTexCoord2f(0.0f,1.0f);
						glVertex3f(0.0f,10.5f,0.0f);

					glEnd();
				}
				glPopMatrix();


				glPushMatrix(); //fentre en devant gauche
				{		
					glTranslatef(82.5,8,18.5);
					glScalef(2,1.5,0.4);
					glColor3f(1,1,1);
					glutSolidCube(7.0);
					glEnd();
				}
				glPopMatrix();



				glPushMatrix(); //fentre en devant droite
				{		
					glTranslatef(119.5,8,18.5);
					glScalef(2,1.5,0.4);
					glColor3f(1,1,1);
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
				glScalef(500,1,50);
				glColor3f(1,1,1);
				glutSolidCube(3.0);
				glEnd();
			}
			glPopMatrix();


			glPushMatrix(); //lampadaire dino
			{

				glTranslatef(1990,2022,2065);
				glRotatef(180,0,1,0);

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
				position_y = 2;
				position_z = 20;
				transparence_boule_3 = 1;
			}


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


		glPushMatrix(); // petit cactus
		{
			if(position_cactus_petit_x <= 2005 && position_y >= 1999 && position_y <= 2500)
			{
				position_cactus_petit_x = position_cactus_petit_x + 4;
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



		glPushMatrix(); // grand cactus
		{
			if(position_cactus_grand_x <= 2005 && position_y >= 1999 && position_y <= 2500)
			{
				position_cactus_grand_x = position_cactus_grand_x + 4;
				glTranslatef(position_cactus_grand_x,2010,2000);
			}
			else
			{
				position_cactus_grand_x = 1100;
				glTranslatef(position_cactus_grand_x,2010,2000);
			}





			box_grand_cactus.x = position_cactus_grand_x  + 2;
			box_grand_cactus.y = 2010;
			box_grand_cactus.z = 2000;

			box_grand_cactus.w = 12;
			box_grand_cactus.h = 18;
			box_grand_cactus.d = 4;


			if(Collision(box_dinosaure, box_grand_cactus) && position_y >= 1999 && position_y <= 2500)
			{	
				position_x = 0;
				position_y = 2;
				position_z = 20;
				transparence_boule_3 = 1;
			}



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



	if(position_y > 3000 && position_y < 3500)
	{	
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
					glTranslatef(101.5,12,17);
					glScalef(1.9,1.5,0.4);
					glColor3f(0.77,0.69,0.49);
					glutSolidCube(7.0);
					glEnd();
				}
				glPopMatrix();

				glPushMatrix(); //mur de devant au mileu en haut texture
				{		
					glTranslatef(94.85,6.75,18.502);
					glBegin(GL_QUADS);
					glColor3f(1,1,1);
						glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
						//set point in 3D and texture space
						glTexCoord2f(0.0f,0.0f);
						glVertex3f(0.0f,0.0f,0.0f);
						
						glTexCoord2f(1.0f,0.0f);
						glVertex3f(13.3f,0.0f,0.0f);
						
						glTexCoord2f(1.0f,1.0f);
						glVertex3f(13.3f,10.5f,0.0f);
						
						glTexCoord2f(0.0f,1.0f);
						glVertex3f(0.0f,10.5f,0.0f);

					glEnd();
				}
				glPopMatrix();


				glPushMatrix(); //fentre en devant gauche
				{		
					glTranslatef(82.5,8,18.5);
					glScalef(2,1.5,0.4);
					glColor3f(1,1,1);
					glutSolidCube(7.0);
					glEnd();
				}
				glPopMatrix();



				glPushMatrix(); //fentre en devant droite
				{		
					glTranslatef(119.5,8,18.5);
					glScalef(2,1.5,0.4);
					glColor3f(1,1,1);
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

			glPushMatrix(); //lampadaire
			{

				glTranslatef(2900,3015,2970);
				glRotatef(-90,0,1,0);

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
				glEnd();

			}
			glPopMatrix();



			glEnd();

			glPushMatrix(); //cube simon
			{
				glTranslatef(10,-5,0);



				if(tour_simon < max_simon && position_y > 2900 && position_y < 3100 && tour_IA0_Link1 == 0) // tour IA
				{

					if(cube_attente < 50 && cube_attente > 0)  // délais d'attente
					{
						cube_attente += 1;
					}
					else
					{
						cube_attente = 0;
					}

					if(nb_flash_actuel == tour_simon && cube_attente == 0)
					{
						if(position_z < 3010 && position_z > 2990 && position_x < 2945 && position_y > 2900 && position_y < 3100 && tour_suivant == 1)
						{
							srand(time(NULL));
							aleatoire_simon = (rand() % 4) + 1;
						}


						if(aleatoire_simon == 1 && cube_attente == 0) //bleu
						{
							if(cube_time < 100)
							{
								tour_suivant = 0;
								transparence_simon_bleu = 1;
								cube_time += 1;
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
								}
							}
						}
						else if(aleatoire_simon == 2 && cube_attente == 0) //rouge
						{
							if(cube_time < 100)
							{
								tour_suivant = 0;
								transparence_simon_rouge = 1;
								cube_time += 1;
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
								}						}
						}
						else if(aleatoire_simon == 3 && cube_attente == 0) //jaune
						{
							if(cube_time < 100)
							{
								tour_suivant = 0;
								transparence_simon_jaune = 1;
								cube_time += 1;
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
								}						}
						}
						else if(aleatoire_simon == 4 && cube_attente == 0) //vert
						{
							if(cube_time < 100)
							{
								tour_suivant = 0;
								transparence_simon_vert = 1;
								cube_time += 1;
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
							}
						}

					}

					else if (nb_flash_actuel < tour_simon && cube_attente == 0)
					{

						if(simon[nb_flash_actuel] == 'b') //bleu
						{
							if(cube_time < 100)
							{
								tour_suivant = 0;
								transparence_simon_bleu = 1;
								cube_time += 1;
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

				}
				else if(position_y > 2900 && position_y < 3100 && tour_IA0_Link1 == 1) // tour link
				{

					if(nb_click < tour_simon )
					{

						if(cube_attente < 50 && cube_attente > 0)  // délais d'attente
						{
							cube_attente += 1;
						}
						else
						{
							cube_attente = 0;
						}

						if(mouse_x > 568 && mouse_x < 746 && mouse_y > 210 && mouse_y < 401 && mouse_state == GLUT_DOWN && mouse_button == GLUT_LEFT_BUTTON)
						{
							if(simon[nb_click] == 'b')
							{
								if(cube_attente == 0)
								{
									if(cube_time < 25)
									{
										tour_suivant = 0;
										transparence_simon_bleu = 1;
										cube_time += 1;
									}
									else
									{
										tour_suivant = 1;
										cube_time = 0;
										transparence_simon_bleu = 0.3;
										aleatoire_simon = 0;
										cube_attente = 1;
										nb_click += 1;
										if(nb_click == tour_simon && nb_click < max_simon)
										{
											tour_IA0_Link1 = 0;
											nb_click = 0;
										}
										for (int i = 0; i < nb_click; ++i)
										{
										}
									}
								}
							}
						}
						else if(mouse_x > 696 && mouse_x < 873 && mouse_y > 421 && mouse_y < 516 && mouse_state == GLUT_DOWN && mouse_button == GLUT_LEFT_BUTTON)
						{
							if(simon[nb_click] == 'r')
							{
								if(cube_attente == 0)
								{
									if(cube_time < 25)
									{
										tour_suivant = 0;
										transparence_simon_rouge = 1;
										cube_time += 1;
									}
									else
									{
										tour_suivant = 1;
										cube_time = 0;
										transparence_simon_rouge = 0.3;
										aleatoire_simon = 0;
										cube_attente = 1;
										nb_click += 1;
										if(nb_click == tour_simon && nb_click < max_simon)
										{
											tour_IA0_Link1 = 0;
											nb_click = 0;
										}
									}
								}
							}
						}
						else if(mouse_x > 699 && mouse_x < 870 && mouse_y > 93 && mouse_y < 291 && mouse_state == GLUT_DOWN && mouse_button == GLUT_LEFT_BUTTON)
						{
							if(simon[nb_click] == 'j')
							{
								if(cube_attente == 0)
								{
									if(cube_time < 25)
									{
										tour_suivant = 0;
										transparence_simon_jaune = 1;
										cube_time += 1;
									}
									else
									{
										tour_suivant = 1;
										cube_time = 0;
										transparence_simon_jaune = 0.3;
										aleatoire_simon = 0;
										cube_attente = 1;
										nb_click += 1;
										if(nb_click == tour_simon && nb_click < max_simon)
										{
											tour_IA0_Link1 = 0;
											nb_click = 0;
										}
									}
								}
							}				
						}
						else if(mouse_x > 814 && mouse_x < 995 && mouse_y > 214 && mouse_y < 402 && mouse_state == GLUT_DOWN && mouse_button == GLUT_LEFT_BUTTON)
						{
							if(simon[nb_click] == 'v')
							{
								if(cube_attente == 0)
								{
									if(cube_time < 25)
									{
										tour_suivant = 0;
										transparence_simon_vert = 1;
										cube_time += 1;
									}
									else
									{
										tour_suivant = 1;
										cube_time = 0;
										transparence_simon_vert = 0.3;
										aleatoire_simon = 0;
										cube_attente = 1;
										nb_click += 1;
										if(nb_click == tour_simon && nb_click < max_simon)
										{
											tour_IA0_Link1 = 0;
											nb_click = 0;
										}
									}
								}
							}		
						}
					}
					else
					{
						if(cube_attente < 500 && cube_attente > 1)  // délais d'attente
						{
							cube_attente += 1;
							transparence_simon_bleu = 0;
							transparence_simon_rouge = 0;
							transparence_simon_jaune = 0;
							transparence_simon_vert = 0;
						}
						else
						{
							cube_attente = 0;
						}
						if (cube_attente <= 500)
						{
							transparence_simon_bleu = 1;
							transparence_simon_rouge = 1;
							transparence_simon_jaune = 1;
							transparence_simon_vert = 1;
							transparence_boule_2 = 1;
							cube_attente +=1;

						}

						if(cube_attente < 250 && cube_attente > 0)  // délais d'attente
						{
							cube_attente += 1;
						}
						else
						{
							position_x = 0;
							position_y = 2;
							position_z = 20;
						}

						
					}
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
	}




// monde aquatique


// CHRISTOPHE

	glPushMatrix(); //animaux marins 
	{

		if (position_y < 0) //animaux marins 
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


				if(Collision(box_personnage, box_requin) && position_z > 900 && position_z < 1000 && touche_requin == true)
				{	
					touche_requin = false;
					if(nb_bouees_rentres == 0)
						nb_bouees_rentres = 0;
					else
						nb_bouees_rentres -= 1;
					nb_bouees_rentres_char[0] = nb_bouees_rentres  +'0';
				}


				if(position_z > 925 && position_z < 1000 && position_x < 200 )
				{
					position_requin_z -= 5;
					if(position_requin_z < 900)
					{
						srand(time(NULL));
						aleatoire_requin = (rand() % 25) * positif_ou_negatif_requin;
						position_requin_z = 1650;
						positif_ou_negatif_requin = -positif_ou_negatif_requin;
						touche_requin = true;

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


				if(Collision(box_personnage, box_turbot) && position_z > 900 && position_z < 1000 && touche_turbot == true)
				{	
					touche_turbot = false;

					if(nb_bouees_rentres == 0)
						nb_bouees_rentres = 0;
					else
						nb_bouees_rentres -= 1;
					nb_bouees_rentres_char[0] = nb_bouees_rentres  +'0';
				}



				glScalef(2,2,2);
				if(position_z > 925 && position_z < 1000  && position_x < 200)
				{
					position_turbot_z -= 6;
					if(position_turbot_z < 900)
					{
						srand(time(NULL));
						aleatoire_turbot = (rand() % 25) * positif_ou_negatif_turbot;
						position_turbot_z = 1750;
						positif_ou_negatif_turbot = -positif_ou_negatif_turbot;
						touche_turbot = true;
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


				if(Collision(box_personnage, box_clown) && position_z > 900 && position_z < 1000 && touche_nemo == true)
				{	
					touche_nemo = false;				
					if(nb_bouees_rentres == 0)
						nb_bouees_rentres = 0;
					else
						nb_bouees_rentres -= 1;
					nb_bouees_rentres_char[0] = nb_bouees_rentres  +'0';
				}


				if(position_z > 925 && position_z < 1000  && position_x < 200)
				{
					position_clown_z-= 5;
					if(position_clown_z < 900)
					{
						srand(time(NULL));
						aleatoire_clown = (rand() % 25) * positif_ou_negatif_clown;
						position_clown_z = 1700;
						positif_ou_negatif_clown = -positif_ou_negatif_clown;
						touche_nemo = true;
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


				if(Collision(box_personnage, box_zancle) && position_z > 900 && position_z < 1000 && touche_zancle == true)
				{	
					touche_zancle = false;
					if(nb_bouees_rentres == 0)
						nb_bouees_rentres = 0;
					else
						nb_bouees_rentres -= 1;
					nb_bouees_rentres_char[0] = nb_bouees_rentres  +'0';

				}




				if(position_z > 925 && position_z < 1000 && position_x < 200)
				{
					position_zancle_z -= 4;
					if(position_zancle_z< 900)
					{
						srand(time(NULL));
						aleatoire_zancle = (rand() % 25) * positif_ou_negatif_zancle;
						position_zancle_z = 1800;
						positif_ou_negatif_zancle = -positif_ou_negatif_zancle;
						touche_zancle = true;
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

			
			glPushMatrix(); // Bouée
			{
				glTranslatef(aleatoire_bouee,position_bouee_y,position_bouee_z);
				glScalef(2,2,2);


				box_bouee.x = aleatoire_bouee;
				box_bouee.y = position_bouee_y;
				box_bouee.z = position_bouee_z;

				box_bouee.w = 4;
				box_bouee.h = 4;
				box_bouee.d = 2;



				if(Collision(box_personnage, box_bouee) && position_z > 900 && position_z < 1000)
				{	
					couleur_tor = 0;
					nb_bouees_rentres += 1;
					nb_bouees_rentres_char[0] = nb_bouees_rentres  +'0';
					if(nb_bouees_rentres == 6)
					{
						transparence_boule_1 = 1;
						position_x = 0;
						position_y = 2;
						position_z = 20;
					}
				}


				if(position_z > 925 && position_z < 1000 && position_x < 200)
				{
					position_bouee_z -= 8;
					if(position_bouee_z < 900)
					{
						srand(time(NULL));
						aleatoire_bouee = (rand() % 25) * positif_ou_negatif_bouee;
						position_bouee_z = 1800;
						positif_ou_negatif_bouee = -positif_ou_negatif_bouee;
						couleur_tor = 1;
					}
					
				}

				glColor3f(0,1,couleur_tor);
				glutWireTorus(1,6,32,32);
			}
			glPopMatrix();
		}


		glEnd();
	}	
	glPopMatrix();



	glPushMatrix(); //création d'algue
	{
		if(position_y < 0)
		{
			for (int i = 1; i < 70; ++i)
			{
				creer_algue(60, -75 - (i+angle_algue), 890 + i*15);
				creer_algue(-60, -75 - (i + angle_algue), 890 + i*15);

				if(i == 0)
				{
					angle_algue = 0;
				}
			}
		
		}



		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //création petit cactus
	{
		if(position_y > 1000 && position_y < 1600)
		{
			for (int i = 1; i < 60; ++i)
			{
				creer_petit_cactus(1075 - i, 1009 + (i*i+angle_petit_cactus), 1000 + i*15.5);
				creer_petit_cactus(935 + i, 1009 + (i*i + angle_petit_cactus), 1000 + i*15.5);

				creer_petit_cactus(1095 - i/2, 1009 + (i*i+angle_petit_cactus), 1000 + i*15.5);
				creer_petit_cactus(915 + i/2, 1009 + (i*i + angle_petit_cactus), 1000 + i*15.5);

				if(i == 0)
				{
					angle_petit_cactus = 0;
				}
			}
		}
		

		glEnd();
	}
	glPopMatrix();





	glPushMatrix(); //belvedère
	{
		glTranslatef(0,-20,660);
		glScalef(20,1,50);
		glColor3f(0.4,0.2,0.06);
		glutSolidCube(3.0);
		glEnd();
	}
	glPopMatrix();


	glPushMatrix(); //clôture droite belvedere
	{
		glColor3f(0.4,0.2,0.06);
		glTranslatef(-8,0,660);

		glPushMatrix(); //barreau droit
		{
			glTranslatef(35,-10,10);
			glScalef(0.5,0.5,45);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 1
		{
			glTranslatef(35,-15,-35);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 2
		{
			glTranslatef(35,-15,-12);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 3
		{
			glTranslatef(35,-15,12);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 4
		{
			glTranslatef(35,-15,35);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //barrière 5
		{
			glTranslatef(35,-15,50);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //barrière 6
		{
			glTranslatef(35,-15,-50);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //barrière 7
		{	
			glTranslatef(35,-15,65);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix(); //clôture gauche belvedere
	{
		glColor3f(0.4,0.2,0.06);
		glTranslatef(8,0,660);

		glPushMatrix(); //barreau droit
		{
			glTranslatef(-35,-10,10);
			glScalef(0.5,0.5,45);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 1
		{
			glTranslatef(-35,-15,-35);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 2
		{
			glTranslatef(-35,-15,-12);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 3
		{
			glTranslatef(-35,-15,12);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 4
		{
			glTranslatef(-35,-15,35);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //barrière 5
		{
			glTranslatef(-35,-15,50);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //barrière 6
		{
			glTranslatef(-35,-15,-50);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //barrière 7
		{	
			glTranslatef(-35,-15,65);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();
	}
	glPopMatrix();


	glPushMatrix(); //clôture arrière belvedere
	{
		glColor3f(0.4,0.2,0.06);
		glTranslatef(0 ,0,765);

		glPushMatrix(); //barreau arrière
		{
			glTranslatef(0,-10,-35);
			glRotatef(90,0,1,0);
			glScalef(0.5,0.5,20);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 1
		{
			glTranslatef(0,-15,-35);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 2
		{
			glTranslatef(15,-15,-35);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 3
		{
			glTranslatef(-15,-15,-35);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 4
		{
			glTranslatef(27,-15,-35);
			glScalef(0.3,5.5,0.3);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //barrière 5
		{
			glTranslatef(-27,-15,-35);
			glScalef(0.3,5.5,0.3);
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

			glTranslatef(0,-19.5,300);
			glScalef(20,1,200);
			glColor3f(0.8,0.83,0.12);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //mer
		{
			  //transparence
			glEnable(GL_BLEND); 
		  	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glTranslatef(0,-30,950);
			glScalef(500,1,300);
			glColor4f(0.25,0.41,0.88,0.5);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();

		glEnd();
	}
	glPopMatrix();



	glPushMatrix(); //LINK_vrai
	{
		glTranslatef(position_x,position_y,position_z);

		if(position_y > 1000 && position_y < 1425 && position_x > 800 && position_x < 1200)
		{
			angle_oiseau_vertical = -45;
		}

		else
		{
			angle_oiseau_vertical = 0;			
		}

		glRotatef(-yrot + 180 , 0, 1, 0);
		glRotatef(angle_oiseau_vertical, 1, 0, 0);

		if(position_z > 900 && position_z < 980 && position_y < 0)
		{
			glRotatef(90,1,0,0);
			if(angle_jambe <= 41 && jambe_avant_arriere == 1)
              {
                angle_jambe += 4;
                if(angle_jambe == 41)
                  jambe_avant_arriere = 0;
              }
              else if (angle_jambe >= -43 && jambe_avant_arriere == 0)
              {
                angle_jambe -= 4;
                if(angle_jambe == -43)
                  jambe_avant_arriere = 1;
              }
		}

		box_personnage.x = position_x;
		box_personnage.y = position_y - 7;
		box_personnage.z = position_z;

		box_personnage.w = 16;
		box_personnage.h = 24;
		box_personnage.d = 8;


		if (position_y < 0)
		{
			glPushMatrix(); //texte compteur a
			{
				glColor3f(1,1,1);
				glRasterPos3f(2, 10, -15);
				glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, nb_bouees_rentres_char[0]);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //texte compteur /b
			{
				glColor3f(1,1,1);
				glRasterPos3f(0, 10, -15);
				glutBitmapString (GLUT_BITMAP_TIMES_ROMAN_24, "/6");
				glEnd();
			}
			glPopMatrix();
		}

		creer_sphere(10, transparence_boule_1);
		creer_sphere(6, transparence_boule_2);
		creer_sphere(2, transparence_boule_3);
		creer_sphere(-2, transparence_boule_4);
		creer_sphere(-6, transparence_boule_5);
		creer_sphere(-10, transparence_boule_6);

		if(position_y > 5000 && position_y < 5100)
		{
			creer_coeur(15, 6, 0, transparence_vie_1);
			creer_coeur(15, 3, 0, transparence_vie_2);
			creer_coeur(15, 0, 0, transparence_vie_3);
		}
		

		glPushMatrix(); //tete
		{
			glScalef(1.3,1.2,1);
			glColor3f(0.890, 0.823, 0.572);
			glutSolidSphere(2.9,50,50);

			glPushMatrix(); //cou
			{
				glTranslatef(0,-2.5,0);
				glRotatef(90,1,0,0);
				glColor3f(0.890, 0.823, 0.572);
				GLUquadricObj *obj = gluNewQuadric();

				gluCylinder(obj,0.7,1.3,1,32,32);
			}
			glPopMatrix();
			
			
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
				glRotatef(-5,0,0,1);		

				glPushMatrix(); //pupille gauche
				{
					glTranslatef(0,0,0.2);
					glScalef(0.8,1,0.2);
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
				
				glPushMatrix(); // cil gauche
				{
					glRotatef(-8.9,0,1,0);
					glTranslatef(-0.09,0,0.06);
					glScalef(1.75,1.1,0.05);
					glColor3f(0,0,0);
					glutSolidSphere(0.5, 20, 20);	
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
				glRotatef(5,0,0,1);

				glPushMatrix(); //pupille droit
				{
					glTranslatef(0,0,0.2);
					glScalef(0.8,1,0.2);
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
				
				glPushMatrix(); // cil droite
				{
					glRotatef(8.9,0,1,0);
					glTranslatef(0.09,0,0.06);
					glScalef(1.75,1.1,0.05);
					glColor3f(0,0,0);
					glutSolidSphere(0.5, 20, 20);	
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
				glColor3f(0.890, 0.823, 0.572);
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
				glColor3f(0.890, 0.823, 0.572);
				glutSolidSphere(0.5,5,5);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //bonnet
			{
				GLUquadricObj *obj = gluNewQuadric();
				glColor3f(0.121, 0.427, 0.050);
				glTranslatef(0,1.8,-3);
				glScalef(0.9,1,1);
				glRotatef(20,1,0,0);
				gluCylinder(obj,2,3,2,32,32);
				
				glRotatef(-20,1,0,0);
				glTranslatef(0,-0.45,-0.2);
				gluCylinder(obj,2,2.35,1,32,32);
				
				glTranslatef(0,0,0.6);
				glutSolidSphere(2.1,10,10);
				
				glTranslatef(0,-1.5,-1.6);
				glRotatef(-50,1,0,0);
				gluCylinder(obj,1,1.5,1,32,32);
				
				glRotatef(-16,1,0,0);
				glTranslatef(0,0,-2.5);
				gluCylinder(obj,0.5,1,3,32,32);
				
				glRotatef(-16,1,0,0);
				glTranslatef(0,-0.1,-1.4);
				gluCylinder(obj,0,0.5,1.5,32,32);
			}
			glPopMatrix();

			glEnd();
		}
		glPopMatrix();	
		
		glTranslatef(0,-7.66,0);
		
		glPushMatrix(); //corps
		{			
			GLUquadricObj *obj = gluNewQuadric();
			
			glPushMatrix(); //buste
			{
			glColor3f(0.121, 0.427, 0.050);
			
			glScalef(0.6,0.9,0.4);
			glutSolidSphere(5,32,32);
			
			glTranslatef(0,-2,0);
			glRotatef(90,1,0,0);
			gluCylinder(obj,4.2,4.8,4,32,32);
			
			glTranslatef(0,0,0.3); // ceinture
				glColor3f(0.537,0.207,0.121);
				gluCylinder(obj,4.48,4.4,1.5,32,32);
				
				glPushMatrix(); // bouton
					glColor3f(0.98,0.93,0.13);
					glTranslatef(0,4.7,0.5);
					glScalef(1.5,0.3,1);
					glutSolidSphere(1,32,32);
				glPopMatrix();
			}
			glPopMatrix();
			
			glPushMatrix(); // épaules
			{
				glColor3f(0.545, 0.905, 0.152);
				
				glPushMatrix(); // droite
					glScalef(0.7,0.9,0.5);
					glTranslatef(-3,2,0);
					glutSolidSphere(2,32,32);
				glPopMatrix();
				
				glPushMatrix(); // gauche
					glScalef(0.7,0.9,0.5);
					glTranslatef(3,2,0);
					glutSolidSphere(2,32,32);
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();	
		
		glPushMatrix(); // jambes
		{
			GLUquadricObj *obj = gluNewQuadric();
			glColor3f(0.9,0.9,0.9);
			glTranslatef(0,-6,0);
			
			glPushMatrix(); // droite
			{
				glTranslatef(-1.5,0,0);
				glRotatef(75,1,0,0);
				glRotatef(15,0,-1,1);
				
				glRotatef(angle_jambe, 1,0,0);
				glRotatef(angle_jambe_cote, 0,1,0);
				
				glPushMatrix(); //hanche + cuisse
					glutSolidSphere(1,32,32);
					gluCylinder(obj,1,1,2.5,32,32);
				glPopMatrix();
				
				glTranslatef(0,0,2.7);
					
				glPushMatrix(); // genoux
					glutSolidSphere(1,32,32);
				glPopMatrix();
				
				glTranslatef(0,0,0.2);
				glRotatef(15,1,0,0);
				
				glPushMatrix(); // jambe
					gluCylinder(obj,1,1,1.5,32,32);
				glPopMatrix();
				
				glTranslatef(0,0,1);
				glColor3f(0.537,0.207,0.121);
				glRotatef(-10,0,0,1);
				glRotatef(5,0,1,0);
				
				glPushMatrix(); // pied
					gluCylinder(obj,1.1,1.1,2,32,32);
					glTranslatef(0,0.5,2);
					glRotatef(-90,1,0,0);
					
					glScalef(0.8,0.3,1.2);
					glutSolidSphere(1.5,32,32);
				glPopMatrix();
			}
			glPopMatrix();
			
			glColor3f(0.9,0.9,0.9);
			
			glPushMatrix(); // gauche
			{
				glTranslatef(1.5,0,0);
				glRotatef(93,1,0,0);
				glRotatef(-15,0,-1,1);
				
				glRotatef(-angle_jambe, 1,0,0);
				glRotatef(-angle_jambe_cote, 0,1,0);

				glPushMatrix(); //hanche + cuisse
					glutSolidSphere(1,32,32);
					gluCylinder(obj,1,1,2.5,32,32);
				glPopMatrix();
				
				glTranslatef(0,0,2.7);
					
				glPushMatrix(); // genoux
					glutSolidSphere(1,32,32);
				glPopMatrix();
				
				glTranslatef(0,0,0.2);
				glRotatef(15,1,0,0);
				
				glPushMatrix(); // jambe
					gluCylinder(obj,1,1,1.5,32,32);
				glPopMatrix();
				
				glTranslatef(0,0,1);
				glColor3f(0.537,0.207,0.121);
				glRotatef(-15,1,1,0);
				
				
				glPushMatrix(); // pied
					gluCylinder(obj,1.1,1.1,2,32,32);
					glTranslatef(0,0.5,2);
					glRotatef(-90,1,0,0);
					
					glScalef(0.8,0.2,1.2);
					glutSolidSphere(1.5,32,32);
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
		
		glPushMatrix(); // bras
		{
			GLUquadricObj *obj = gluNewQuadric();
			glColor3f(0.545, 0.905, 0.152);
			glTranslatef(0,2.5,0);
			
			glPushMatrix(); // droit
			{
				if(garde == 0)
					glRotatef(-angle_jambe, 1,0,0);

				if (bras_droit == 1)
				{
					if(angle_bras_droit > -45 && montee0_descente1_bras_droit == 0 && garde == 0)
					{
						angle_bras_droit -= 4;
						glRotatef(angle_bras_droit, 1,-1,0);
						if(angle_bras_droit <= -45)
						{
							montee0_descente1_bras_droit = 1;

							 garde = 1;
						}
					}
					else if(angle_bras_droit <= -45 && montee0_descente1_bras_droit == 1 && garde == 1)
					{
						glRotatef(-45, 1,-1,0);
						garde = 1;
					}
					else if (angle_bras_droit < 0 && montee0_descente1_bras_droit == 1  && garde == 0)
					{
						glRotatef(angle_bras_droit, 1,-1,0);
						angle_bras_droit += 4;
						if(angle_bras_droit >= 0)
						{
							montee0_descente1_bras_droit = 2;
							bras_droit = 0;
						}
					}
				}


				glTranslatef(-3,-0.5,0); // épaule
				glutSolidSphere(0.9,32,32);
				
				glRotatef(-110,0,1,0); // bras
				glRotatef(55,1,0,0);
				gluCylinder(obj,0.9,0.8,4,32,32);
				
				glTranslatef(0,0,4); // coude
				glutSolidSphere(0.8,32,32);
				
				glRotatef(45,0,1,0); // avant-bras
				glRotatef(33,1,0,0);
				gluCylinder(obj,0.8,0.7,4,32,32);
				
				glColor3f(0.890, 0.823, 0.572); // main
				glRotatef(-110,0,0,1);
				glTranslatef(0,0,4.1);
				glutSolidSphere(0.8,32,32);
				
				glPushMatrix(); // bouclier
				{
					glColor3f(.7,.7,.7); // poignée 1
					glRotatef(30,0,1,0);
					glPushMatrix();
						glScalef(1,6,1);
						glutSolidCube(0.5);
					glPopMatrix();

					glTranslatef(-0.5,1.75,0); // poignée 2
					glRotatef(90,0,0,1);
					glPushMatrix();
						glScalef(1,3,1);
						glutSolidCube(0.5);
					glPopMatrix();
					
					glRotatef(-90,1,0,0); // carapace
					glRotatef(-90,0,0,1);
					glTranslatef(0,0,1);
					glColor3f(0.494, 0.250, 0.164);
					{
						glPushMatrix(); // partie Gauche
						{
							glTranslatef(0.325,0,0);
							glRotatef(10,0,1,0);
							
							glPushMatrix(); // 1G
								glScalef(3,20,2);
								glutSolidCube(0.25);
							glPopMatrix();
							
							glPushMatrix(); // 1G partie basse
							{
								glTranslatef(0,-2.5,0);
								glBegin( GL_TRIANGLES );
								//devant
									glVertex3f( 0.375f, 0.0f, 0.25f);
									glVertex3f( 0.375f, -1.5f, 0.25f);
									glVertex3f( -0.375f, -2.0f, 0.25f);
									
									glVertex3f( -0.375f, 0.0f, 0.25f);
									glVertex3f( 0.375f, 0.0f, 0.25f);
									glVertex3f( -0.375f, -2.0f, 0.25f);
								//derrière
									glVertex3f( 0.375f, 0.0f, -0.25f);
									glVertex3f( 0.375f, -1.5f, -0.25f);
									glVertex3f( -0.375f, -2.0f, -0.25f);
									
									glVertex3f( -0.375f, 0.0f, -0.25f);
									glVertex3f( 0.375f, 0.0f, -0.25f);
									glVertex3f( -0.375f, -2.0f, -0.25f);
								//dessous1
									glVertex3f( 0.375f, -1.5f, 0.25f);
									glVertex3f( 0.375f, -1.5f, -0.25f);
									glVertex3f( -0.375f, -2.0f, -0.25f);
								//dessous2
									glVertex3f( 0.375f, -1.5f, 0.25f);
									glVertex3f( -0.375f, -2.0f, -0.25f);
									glVertex3f( -0.375f, -2.0f, 0.25f);
								glEnd();
							}
							glPopMatrix();
							
							glTranslatef(1.2,0,-0.17);
							glRotatef(10,0,1,0);
							
							glPushMatrix(); // 2G
								glScalef(7,20,2);
								glutSolidCube(0.25);
							glPopMatrix();
							
							glPushMatrix(); // 2G partie basse
							{
								glTranslatef(0,-2.5,0);
								glBegin( GL_TRIANGLES );
								//devant
									glVertex3f(-0.875f, 0.0f, 0.25f);
									glVertex3f( 0.875f, 0.0f, 0.25f);
									glVertex3f(-0.875f,-1.5f, 0.25f);
								//derrière
									glVertex3f(-0.875f, 0.0f, -0.25f);
									glVertex3f( 0.875f, 0.0f, -0.25f);
									glVertex3f(-0.875f,-1.5f, -0.25f);
								//dessous1
									glVertex3f( 0.875f, 0.0f, 0.25f);
									glVertex3f(-0.875f,-1.5f, 0.25f);
									glVertex3f(-0.875f,-1.5f,-0.25f);
								//dessous2
									glVertex3f( 0.875f, 0.0f, 0.25f);
									glVertex3f( 0.875f, 0.0f,-0.25f);
									glVertex3f(-0.875f,-1.5f,-0.25f);
								glEnd();
							}
							glPopMatrix();
						}
						glPopMatrix();
						
						glPushMatrix(); // partie Droite
						{
							glTranslatef(-0.325,0,0);
							glRotatef(-10,0,1,0);
							
							glPushMatrix(); // 1D
								glScalef(3,20,2);
								glutSolidCube(0.25);
							glPopMatrix();
							
							glPushMatrix(); // 1D partie basse
							{
								glTranslatef(0,-2.5,0);
								glBegin( GL_TRIANGLES );
								//devant
									glVertex3f(-0.375f, 0.0f, 0.25f);
									glVertex3f(-0.375f,-1.5f, 0.25f);
									glVertex3f( 0.375f,-2.0f, 0.25f);
									
									glVertex3f( 0.375f, 0.0f, 0.25f);
									glVertex3f(-0.375f, 0.0f, 0.25f);
									glVertex3f( 0.375f,-2.0f, 0.25f);
								//derrière
									glVertex3f(-0.375f, 0.0f, -0.25f);
									glVertex3f(-0.375f,-1.5f, -0.25f);
									glVertex3f( 0.375f,-2.0f, -0.25f);
									
									glVertex3f( 0.375f, 0.0f, -0.25f);
									glVertex3f(-0.375f, 0.0f, -0.25f);
									glVertex3f( 0.375f,-2.0f, -0.25f);
								//dessous1
									glVertex3f(-0.375f, -1.5f, 0.25f);
									glVertex3f(-0.375f, -1.5f,-0.25f);
									glVertex3f( 0.375f, -2.0f,-0.25f);
								//dessous2
									glVertex3f(-0.375f, -1.5f, 0.25f);
									glVertex3f( 0.375f, -2.0f,-0.25f);
									glVertex3f( 0.375f, -2.0f, 0.25f);
								
								glEnd();
							}
							glPopMatrix();
							
							glTranslatef(-1.2,0,-0.17);
							glRotatef(-10,0,1,0);
							
							glPushMatrix(); // 2D
								glScalef(7,20,2);
								glutSolidCube(0.25);
							glPopMatrix();
							
							glPushMatrix(); // 2D partie basse
							{
								glTranslatef(0,-2.5,0);
								glBegin( GL_TRIANGLES );
								//devant
									glVertex3f( 0.875f, 0.0f, 0.25f);
									glVertex3f(-0.875f, 0.0f, 0.25f);
									glVertex3f( 0.875f,-1.5f, 0.25f);
								//derrière
									glVertex3f( 0.875f, 0.0f, -0.25f);
									glVertex3f(-0.875f, 0.0f, -0.25f);
									glVertex3f( 0.875f,-1.5f, -0.25f);
								//dessous1
									glVertex3f(-0.875f, 0.0f, 0.25f);
									glVertex3f( 0.875f,-1.5f, 0.25f);
									glVertex3f( 0.875f,-1.5f,-0.25f);
								//dessous2
									glVertex3f(-0.875f, 0.0f, 0.25f);
									glVertex3f(-0.875f, 0.0f,-0.25f);
									glVertex3f( 0.875f,-1.5f,-0.25f);
								glEnd();
							}
							glPopMatrix();
						}
						glPopMatrix();
					}
				}
				glPopMatrix();

				glRotatef(angle_jambe, 1,0,0);
				
			}
			glPopMatrix();
			
			glColor3f(0.545, 0.905, 0.152);
			glPushMatrix(); // gauche
			{
				if(bras_gauche == 0)
					glRotatef(angle_jambe, 1,0,0);
				
				if(bras_gauche == 1)
				{

					if(Collision(box_dark, box_epee) && touche_dark_link == true) //collision pour barre de vie
					{	
						touche_dark_link = false;

						if(vie_dark_link == 3 && garde_dark == 0)
						{
							transparence_barre_3 = 0.1;
							couleur_barre_r = 1;
							couleur_barre_g = 0.84;
							couleur_barre_b = 0;
							vie_dark_link -= 1;
						}
						else if(vie_dark_link == 2 && garde_dark == 0)
						{
							transparence_barre_3 = 0.1;
							transparence_barre_2 = 0.1;
							couleur_barre_r = 1;
							couleur_barre_g = 0;
							couleur_barre_b = 0;
							vie_dark_link -= 1;
						}
						else if(vie_dark_link == 1 && garde_dark == 0)
						{
							transparence_barre_3 = 0.1;
							transparence_barre_2 = 0.1;
							transparence_barre_1 = 0.1;
							couleur_barre_r = 0;
							couleur_barre_g = 0;
							couleur_barre_b = 0;
							vie_dark_link -= 1;

						}
					}




					if(angle_bras_gauche > -45 && montee0_descente1_bras_gauche == 0)
					{
						angle_bras_gauche -= 4;
						glRotatef(angle_bras_gauche, 1,1,0);
						if(angle_bras_gauche <= -45)
						{
							montee0_descente1_bras_gauche = 1;
						}
					}
					else if (angle_bras_gauche < 0 && montee0_descente1_bras_gauche == 1 )
					{
						glRotatef(angle_bras_gauche, 1,1,0);
						angle_bras_gauche += 4;
						if(angle_bras_gauche >= 0)
						{
							montee0_descente1_bras_gauche = 2;
							bras_gauche = 0;
							
						}
					}

					box_epee.x = position_x;
					box_epee.y = position_y - 3;
					box_epee.z = position_z + 7;

					box_epee.w = 16;
					box_epee.h = 24;
					box_epee.d = 14;

				}
				else
				{
					touche_dark_link = true;
				}

				glTranslatef(3,-0.5,0); // épaule
				glutSolidSphere(.9,32,32);
				
				glRotatef(90,0,1,0); // bras
				glRotatef(50,1,0,0);
				gluCylinder(obj,1,.8,4,32,32);
				
				glTranslatef(0,0,4); // coude
				glutSolidSphere(0.8,32,32);
				
				glRotatef(-15,0,1,0); // avant-bras
				gluCylinder(obj,0.8,0.7,4,32,32);
				
				glColor3f(0.890, 0.823, 0.572); // main
				glRotatef(110,0,0,1);
				glTranslatef(0,0,4.1);
				glutSolidSphere(0.8,32,32);
				
				glRotatef(-33,0,0,1);
				glRotatef( 95,1,0,0);
				
				glPushMatrix(); // épée
				{

					glPushMatrix(); // pommeau
					{
						glColor3f(0.211, 0.168, 0.631);
						glTranslatef(0,0,-1.5);
						
						gluCylinder(obj,0.4,0.4,3,32,32);
						
						glTranslatef(0,0,2);
						
						gluCylinder(obj,0.4,0.6,2,32,32);
						glTranslatef(0,0,2);
						gluDisk(obj,0,0.6,32,32);
					}
					glPopMatrix();
					
					glTranslatef(0,0,-1.5);
					glRotatef(-180,1,0,0);
					
					glPushMatrix(); // garde
					{
						gluCylinder(obj,0.4,0.7,0.1,32,32);
						glTranslatef(0,0,0.1);
						gluCylinder(obj,0.7,0.5,0.3,32,32);
						glTranslatef(0,0,0.3);
						gluCylinder(obj,0.5,0.5,0.4,32,32);
						
						glPushMatrix(); // partie droite
						{
							glTranslatef(0,0.65,0.2);
							glRotatef(-10,1,0,0);
							
							glPushMatrix();
								glScalef(0.7,2,0.7);
								glutSolidCube(0.5);
							glPopMatrix();
							
							glPushMatrix();
								glTranslatef(0,0,0.25);
								glRotatef(-30,1,0,0);
								glTranslatef(0,0.32,0.2);
								glScalef(0.7,0.7,1.5);
								glRotatef(30,1,0,0);
								glutSolidCube(0.5);
							glPopMatrix();
						}
						glPopMatrix();
						
						glPushMatrix(); // partie gauche
						{
							glTranslatef(0,-0.65,0.2);
							glRotatef(10,1,0,0);
							
							glPushMatrix();
								glScalef(0.7,2,0.7);
								glutSolidCube(0.5);
							glPopMatrix();
							
							glPushMatrix();
								glTranslatef(0,0,0.25);
								glRotatef(30,1,0,0);
								glTranslatef(0,-0.32,0.2);
								glScalef(0.7,0.7,1.5);
								glRotatef(-30,1,0,0);
								glutSolidCube(0.5);
							glPopMatrix();
						}
						glPopMatrix();
						
						glTranslatef(0,0,0.4);
						gluCylinder(obj,0.5,0.7,0.4,32,32);
						glTranslatef(0,0,0.4);
						gluDisk(obj,0,0.7,32,32);
						
						glPushMatrix(); // porte-joyau
							glScalef(0.6,1,2);
							glutSolidSphere(0.5,32,32);
						glPopMatrix();
						
						glPushMatrix(); // joyau
							glColor3f(1,1,0);
							glScalef(0.8,0.5,1.5);
							glutSolidSphere(0.5,32,32);
						glPopMatrix();
					}
					glPopMatrix();
						
					glPushMatrix(); // lame
					{
						glTranslatef(0,0,1.2); // base
						glColor3f(.99,.99,.99);
						glScalef(0.2,0.6,1);
						gluCylinder(obj,0.7,0.7,2,32,32);
						
						glTranslatef(0,0,2); // base vers lame
						gluCylinder(obj,0.7,0.9,0.2,32,32);
						
						glTranslatef(0,0,0.2); // lame
						gluCylinder(obj,0.9,0.9,4,32,32);
						
						glTranslatef(0,0,4); // pointe
						gluCylinder(obj,0.9,0.7,0.3,32,32);
						glTranslatef(0,0,0.3);
						gluCylinder(obj,0.7,0.5,0.3,32,32);
						glTranslatef(0,0,0.3);
						gluCylinder(obj,0.5,0.3,0.3,32,32);
						glTranslatef(0,0,0.3);
						gluCylinder(obj,0.3,0,0.3,32,32);
					}
					glPopMatrix();
				}
				glPopMatrix();


			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();


	if(position_y > 5000 && position_y < 5500)
	{
		glPushMatrix(); //dark link
		{

			if (dark_link_mort == false)
			{
				if(arreter_animation_dark == false)
				{							
					if(position_dark_x < aleatoire_position_dark_x - 1) // pour x
					{
						position_dark_x += 0.25;
					}
					else if(position_dark_x > aleatoire_position_dark_x + 1)
					{
						position_dark_x -= 0.25;
					}
					else 
					{
						positif_ou_negatif_dark_link_x = -positif_ou_negatif_dark_link_x;
						srand(time(NULL));
						aleatoire_position_dark_x = (rand() % 20) * positif_ou_negatif_dark_link_x + 4200;
					}

					if(position_dark_z < aleatoire_position_dark_z - 1) // pour z
					{
						position_dark_z += 0.25;
					}
					else if(position_dark_z > aleatoire_position_dark_z + 1)
					{
						position_dark_z -= 0.25;
					}
					else
					{
						positif_ou_negatif_dark_link_z = -positif_ou_negatif_dark_link_z;	
						srand(time(NULL));
						aleatoire_position_dark_z = (rand() % 20) * positif_ou_negatif_dark_link_z + 5000;
					}


				}





				glTranslatef(position_dark_x,position_dark_y,position_dark_z);
				glRotatef(180, 0,1,0);

				if(vie_dark_link == 0)
				{
					arreter_animation_dark = true;
					if(rotation_mort > -90)
					{
						glRotatef(rotation_mort, 1,0,0);
						rotation_mort -= 1;
					}
					if(rotation_mort == -90 && translation_mort < 40)
					{
						glRotatef(rotation_mort, 1,0,0);
						glTranslatef(0, 0, translation_mort);
						translation_mort += 0.5;
						transparence_barre_3 = 0;
						transparence_barre_2 = 0;
						transparence_barre_1 = 0;
					}
					if(translation_mort >= 40)
					{
						dark_link_mort = true;
						transparence_boule_6 = 1;
						position_x = 0;
						position_y = 2;
						position_z = -4;
					}
				}

				box_dark.x = position_dark_x;
				box_dark.y = position_dark_y - 7;
				box_dark.z = position_dark_z;

				box_dark.w = 16;
				box_dark.h = 24;
				box_dark.d = 8;





				glPushMatrix(); //tete
				{
					glScalef(1.3,1.2,1);
					glColor3f(0.32, 0.29, 0.29);
					glutSolidSphere(2.9,50,50);

					glPushMatrix(); //cou
					{
						glTranslatef(0,-2.5,0);
						glRotatef(90,1,0,0);
						glColor3f(0.5,0.48,0.52);
						GLUquadricObj *obj = gluNewQuadric();
						
						gluCylinder(obj,0.7,1.3,1,32,32);
					}
					glPopMatrix();
					
					
					glPushMatrix(); //cheveux
					{
						glTranslatef(0,1,0);
						glScalef(1,1,0.8);
						glColor3f(0.85,0.85,0.85);
						glutSolidSphere(3,10,10);
						glEnd();



						glPushMatrix(); //meche gauche grosse
						{
							glTranslatef(-1,1.9,0);
							glScalef(2.5,1,1);
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
							glutSolidSphere(1,8,8);
							glEnd();
						}
						glPopMatrix();




						glPushMatrix(); //rouflaquette gauche
						{
							glTranslatef(-2.8,-0.6,0.3);
							glRotatef(-30, 1,0,0);
							glScalef(0.5,2.5,1);
							glutSolidSphere(0.75,7,7);
							glEnd();
						}
						glPopMatrix();



						glPushMatrix(); //rouflaquette droite
						{
							glTranslatef(2.8,-0.6,0.3);
							glRotatef(-30, 1,0,0);
							glScalef(0.5,2.5,1);
							glutSolidSphere(0.75,7,7);
							glEnd();
						}
						glPopMatrix();




					}
					glPopMatrix();



					glPushMatrix(); //oeil gauche
					{
						glTranslatef(-1,0,2.7);
						glRotatef(-5,0,0,1);	


						glPushMatrix(); //pupille gauche
						{
							glTranslatef(0,0,0.2);
							glScalef(0.8,1,0.2);
							glColor3f(1,0.20,0.18);
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
						
						glPushMatrix(); // cil gauche
						{
							glRotatef(-8.9,0,1,0);
							glTranslatef(-0.09,0,0.06);
							glScalef(1.75,1.1,0.05);
							glColor3f(0,0,0);
							glutSolidSphere(0.5, 20, 20);	
						}
						glPopMatrix();

						glScalef(2,1,0.5);
						glColor3f(0,0,0);
						glutSolidSphere(0.5, 20, 20);	
						glEnd();

					}
					glPopMatrix();



					glPushMatrix(); //oeil droit
					{
						glTranslatef(1,0,2.7);
						glRotatef(5,0,0,1);

						glPushMatrix(); //pupille droit
						{
							glTranslatef(0,0,0.2);
							glScalef(0.8,1,0.2);
							glColor3f(1,0.20,0.18);
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
						
						glPushMatrix(); // cil droite
						{
							glRotatef(8.9,0,1,0);
							glTranslatef(0.09,0,0.06);
							glScalef(1.75,1.1,0.05);
							glColor3f(0,0,0);
							glutSolidSphere(0.5, 20, 20);	
						}
						glPopMatrix();

						glScalef(2,1,0.5);
						glColor3f(0,0,0);
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
						glColor3f(0.32, 0.29, 0.29);
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
						glColor3f(0.32, 0.29, 0.29);
						glutSolidSphere(0.5,5,5);
						glEnd();
					}
					glPopMatrix();

					glPushMatrix(); //bonnet
					{
						GLUquadricObj *obj = gluNewQuadric();
						glColor3f(0.32, 0.29, 0.29);
						glTranslatef(0,1.8,-3);
						glScalef(0.9,1,1);
						glRotatef(20,1,0,0);
						gluCylinder(obj,2,3,2,32,32);
						
						glRotatef(-20,1,0,0);
						glTranslatef(0,-0.45,-0.2);
						gluCylinder(obj,2,2.35,1,32,32);
						
						glTranslatef(0,0,0.6);
						glutSolidSphere(2.1,10,10);
						
						glTranslatef(0,-1.5,-1.6);
						glRotatef(-50,1,0,0);
						gluCylinder(obj,1,1.5,1,32,32);
						
						glRotatef(-16,1,0,0);
						glTranslatef(0,0,-2.5);
						gluCylinder(obj,0.5,1,3,32,32);
						
						glRotatef(-16,1,0,0);
						glTranslatef(0,-0.1,-1.4);
						gluCylinder(obj,0,0.5,1.5,32,32);
					}
					glPopMatrix();

					glEnd();
				}
				glPopMatrix();	
				
				glTranslatef(0,-7.66,0);
				
				glPushMatrix(); //corps
				{			
					GLUquadricObj *obj = gluNewQuadric();
					
					glPushMatrix(); //buste
					{
					glColor3f(0.18, 0.16, 0.188);
					
					glScalef(0.6,0.9,0.4);
					glutSolidSphere(5,32,32);
					
					glTranslatef(0,-2,0);
					glRotatef(90,1,0,0);
					gluCylinder(obj,4.2,4.8,4,32,32);
					
					glTranslatef(0,0,0.3); // ceinture
						glColor3f(0.5,0.48,0.52);
						gluCylinder(obj,4.48,4.4,1.5,32,32);
						
						glPushMatrix(); // bouton
							glColor3f(0.98,0.93,0.13);
							glTranslatef(0,4.7,0.5);
							glScalef(1.5,0.3,1);
							glutSolidSphere(1,32,32);
						glPopMatrix();
					}
					glPopMatrix();
					
					glPushMatrix(); // épaules
					{
						glColor3f(0.5,0.48,0.52);
						
						glPushMatrix(); // droite
							glScalef(0.7,0.9,0.5);
							glTranslatef(-3,2,0);
							glutSolidSphere(2,32,32);
						glPopMatrix();
						
						glPushMatrix(); // gauche
							glScalef(0.7,0.9,0.5);
							glTranslatef(3,2,0);
							glutSolidSphere(2,32,32);
						glPopMatrix();
					}
					glPopMatrix();
				}
				glPopMatrix();	
				
				glPushMatrix(); // jambes
				{
					GLUquadricObj *obj = gluNewQuadric();
					glColor3f(0.67,0.67,0.67);
					glTranslatef(0,-6,0);
					
					glPushMatrix(); // droite
					{
						glTranslatef(-1.5,0,0);
						glRotatef(75,1,0,0);
						glRotatef(15,0,-1,1);
						
						glRotatef(angle_jambe_dark, 0,1,0);
						
						glPushMatrix(); //hanche + cuisse
							glutSolidSphere(1,32,32);
							gluCylinder(obj,1,1,2.5,32,32);
						glPopMatrix();
						
						glTranslatef(0,0,2.7);
							
						glPushMatrix(); // genoux
							glutSolidSphere(1,32,32);
						glPopMatrix();
						
						glTranslatef(0,0,0.2);
						glRotatef(15,1,0,0);
						
						glPushMatrix(); // jambe
							gluCylinder(obj,1,1,1.5,32,32);
						glPopMatrix();
						
						glTranslatef(0,0,1);
						glColor3f(0.26,0.17,0.07);
						glRotatef(-10,0,0,1);
						glRotatef(5,0,1,0);
						
						glPushMatrix(); // pied
							gluCylinder(obj,1.1,1.1,2,32,32);
							glTranslatef(0,0.5,2);
							glRotatef(-90,1,0,0);
							
							glScalef(0.8,0.3,1.2);
							glutSolidSphere(1.5,32,32);
						glPopMatrix();
					}
					glPopMatrix();
					
					glColor3f(0.67,0.67,0.67);
					
					glPushMatrix(); // gauche
					{
						glTranslatef(1.5,0,0);
						glRotatef(93,1,0,0);
						glRotatef(-15,0,-1,1);
						
						glRotatef(-angle_jambe_dark, 0,1,0);


						glPushMatrix(); //hanche + cuisse
							glutSolidSphere(1,32,32);
							gluCylinder(obj,1,1,2.5,32,32);
						glPopMatrix();
						
						glTranslatef(0,0,2.7);
							
						glPushMatrix(); // genoux
							glutSolidSphere(1,32,32);
						glPopMatrix();
						
						glTranslatef(0,0,0.2);
						glRotatef(15,1,0,0);
						
						glPushMatrix(); // jambe
							gluCylinder(obj,1,1,1.5,32,32);
						glPopMatrix();
						
						glTranslatef(0,0,1);
						glColor3f(0.26,0.17,0.07);
						glRotatef(-15,1,1,0);
						
						
						glPushMatrix(); // pied
							gluCylinder(obj,1.1,1.1,2,32,32);
							glTranslatef(0,0.5,2);
							glRotatef(-90,1,0,0);
							
							glScalef(0.8,0.2,1.2);
							glutSolidSphere(1.5,32,32);
						glPopMatrix();
					}
					glPopMatrix();
				}
				glPopMatrix();
				
				glPushMatrix(); // bras
				{
					GLUquadricObj *obj = gluNewQuadric();
					glColor3f(0.5,0.48,0.52);
					glTranslatef(0,2.5,0);
					
					glPushMatrix(); // droit
					{	
						if(arreter_animation_dark == false)
						{
							if(angle_jambe_dark <= 21 && jambe_avant_arriere_dark == 1)
				            {
				                angle_jambe_dark += 2;
				                if(angle_jambe_dark == 21)
				                  jambe_avant_arriere_dark = 0;
				            }
				            else if (angle_jambe_dark >= -23 && jambe_avant_arriere_dark == 0)
				            {
				                angle_jambe_dark -= 2;
				                if(angle_jambe_dark == -23)
				                  jambe_avant_arriere_dark = 1;
				            }
				


							if(bras_droit_bouge == false)	
							{
								srand(time(NULL));
								aleatoire_dark_link_bouclier = (rand() % 10	);
								bras_droit_dark = aleatoire_dark_link_bouclier;
								if(bras_droit_dark == 5)
								{
									montee0_descente1_bras_droit_dark= 0;
								}
							}

							if(garde_dark == 0)
							{
								glRotatef(-angle_jambe_dark, 1,0,0);
							}

							if (bras_droit_dark == 5)
							{
								bras_droit_bouge = true;
								if(angle_bras_droitp_dark > -45 && montee0_descente1_bras_droit_dark == 0 && garde_dark == 0)
								{
									angle_bras_droitp_dark -= 4;
									glRotatef(angle_bras_droitp_dark, 1,-1,0);
									if(angle_bras_droitp_dark <= -45)
									{
										montee0_descente1_bras_droit_dark = 1;

										 garde_dark = 1;
									}
								}
								else if(angle_bras_droitp_dark <= -45 && montee0_descente1_bras_droit_dark == 1 && garde_dark == 1)
								{
									glRotatef(-45, 1,-1,0);
									garde_dark = 1;
									srand(time(NULL));
									aleatoire_temps_bouclier = (rand() % 5);

									if(aleatoire_temps_bouclier == 4)
									{
										garde_dark = 0;
									}
								}
								else if (angle_bras_droitp_dark < 0 && montee0_descente1_bras_droit_dark == 1  && garde_dark == 0)
								{
									glRotatef(angle_bras_droitp_dark, 1,-1,0);
									angle_bras_droitp_dark += 4;
									if(angle_bras_droitp_dark >= 0)
									{
										montee0_descente1_bras_droit_dark = 2;
										bras_droit_dark = 0;
										
									}
								}
							}
							else
							{
								bras_droit_bouge = false;
							}
						}

						


						glTranslatef(-3,-0.5,0); // épaule
						glutSolidSphere(0.9,32,32);
						
						glRotatef(-110,0,1,0); // bras
						glRotatef(55,1,0,0);
						gluCylinder(obj,0.9,0.8,4,32,32);
						
						glTranslatef(0,0,4); // coude
						glutSolidSphere(0.8,32,32);
						
						glRotatef(45,0,1,0); // avant-bras
						glRotatef(33,1,0,0);
						gluCylinder(obj,0.8,0.7,4,32,32);
						
						glColor3f(0.890, 0.823, 0.572); // main
						glRotatef(-110,0,0,1);
						glTranslatef(0,0,4.1);
						glutSolidSphere(0.8,32,32);
						
						glPushMatrix(); // bouclier
						{
							glColor3f(.7,.7,.7); // poignée 1
							glRotatef(30,0,1,0);
							glPushMatrix();
								glScalef(1,6,1);
								glutSolidCube(0.5);
							glPopMatrix();

							glTranslatef(-0.5,1.75,0); // poignée 2
							glRotatef(90,0,0,1);
							glPushMatrix();
								glScalef(1,3,1);
								glutSolidCube(0.5);
							glPopMatrix();
							
							glRotatef(-90,1,0,0); // carapace
							glRotatef(-90,0,0,1);
							glTranslatef(0,0,1);
							glColor3f(0.494, 0.250, 0.164);
							{
								glPushMatrix(); // partie Gauche
								{
									glTranslatef(0.325,0,0);
									glRotatef(10,0,1,0);
									
									glPushMatrix(); // 1G
										glScalef(3,20,2);
										glutSolidCube(0.25);
									glPopMatrix();
									
									glPushMatrix(); // 1G partie basse
									{
										glTranslatef(0,-2.5,0);
										glBegin( GL_TRIANGLES );
										//devant
											glVertex3f( 0.375f, 0.0f, 0.25f);
											glVertex3f( 0.375f, -1.5f, 0.25f);
											glVertex3f( -0.375f, -2.0f, 0.25f);
											
											glVertex3f( -0.375f, 0.0f, 0.25f);
											glVertex3f( 0.375f, 0.0f, 0.25f);
											glVertex3f( -0.375f, -2.0f, 0.25f);
										//derrière
											glVertex3f( 0.375f, 0.0f, -0.25f);
											glVertex3f( 0.375f, -1.5f, -0.25f);
											glVertex3f( -0.375f, -2.0f, -0.25f);
											
											glVertex3f( -0.375f, 0.0f, -0.25f);
											glVertex3f( 0.375f, 0.0f, -0.25f);
											glVertex3f( -0.375f, -2.0f, -0.25f);
										//dessous1
											glVertex3f( 0.375f, -1.5f, 0.25f);
											glVertex3f( 0.375f, -1.5f, -0.25f);
											glVertex3f( -0.375f, -2.0f, -0.25f);
										//dessous2
											glVertex3f( 0.375f, -1.5f, 0.25f);
											glVertex3f( -0.375f, -2.0f, -0.25f);
											glVertex3f( -0.375f, -2.0f, 0.25f);
										glEnd();
									}
									glPopMatrix();
									
									glTranslatef(1.2,0,-0.17);
									glRotatef(10,0,1,0);
									
									glPushMatrix(); // 2G
										glScalef(7,20,2);
										glutSolidCube(0.25);
									glPopMatrix();
									
									glPushMatrix(); // 2G partie basse
									{
										glTranslatef(0,-2.5,0);
										glBegin( GL_TRIANGLES );
										//devant
											glVertex3f(-0.875f, 0.0f, 0.25f);
											glVertex3f( 0.875f, 0.0f, 0.25f);
											glVertex3f(-0.875f,-1.5f, 0.25f);
										//derrière
											glVertex3f(-0.875f, 0.0f, -0.25f);
											glVertex3f( 0.875f, 0.0f, -0.25f);
											glVertex3f(-0.875f,-1.5f, -0.25f);
										//dessous1
											glVertex3f( 0.875f, 0.0f, 0.25f);
											glVertex3f(-0.875f,-1.5f, 0.25f);
											glVertex3f(-0.875f,-1.5f,-0.25f);
										//dessous2
											glVertex3f( 0.875f, 0.0f, 0.25f);
											glVertex3f( 0.875f, 0.0f,-0.25f);
											glVertex3f(-0.875f,-1.5f,-0.25f);
										glEnd();
									}
									glPopMatrix();
								}
								glPopMatrix();
								
								glPushMatrix(); // partie Droite
								{
									glTranslatef(-0.325,0,0);
									glRotatef(-10,0,1,0);
									
									glPushMatrix(); // 1D
										glScalef(3,20,2);
										glutSolidCube(0.25);
									glPopMatrix();
									
									glPushMatrix(); // 1D partie basse
									{
										glTranslatef(0,-2.5,0);
										glBegin( GL_TRIANGLES );
										//devant
											glVertex3f(-0.375f, 0.0f, 0.25f);
											glVertex3f(-0.375f,-1.5f, 0.25f);
											glVertex3f( 0.375f,-2.0f, 0.25f);
											
											glVertex3f( 0.375f, 0.0f, 0.25f);
											glVertex3f(-0.375f, 0.0f, 0.25f);
											glVertex3f( 0.375f,-2.0f, 0.25f);
										//derrière
											glVertex3f(-0.375f, 0.0f, -0.25f);
											glVertex3f(-0.375f,-1.5f, -0.25f);
											glVertex3f( 0.375f,-2.0f, -0.25f);
											
											glVertex3f( 0.375f, 0.0f, -0.25f);
											glVertex3f(-0.375f, 0.0f, -0.25f);
											glVertex3f( 0.375f,-2.0f, -0.25f);
										//dessous1
											glVertex3f(-0.375f, -1.5f, 0.25f);
											glVertex3f(-0.375f, -1.5f,-0.25f);
											glVertex3f( 0.375f, -2.0f,-0.25f);
										//dessous2
											glVertex3f(-0.375f, -1.5f, 0.25f);
											glVertex3f( 0.375f, -2.0f,-0.25f);
											glVertex3f( 0.375f, -2.0f, 0.25f);
										
										glEnd();
									}
									glPopMatrix();
									
									glTranslatef(-1.2,0,-0.17);
									glRotatef(-10,0,1,0);
									
									glPushMatrix(); // 2D
										glScalef(7,20,2);
										glutSolidCube(0.25);
									glPopMatrix();
									
									glPushMatrix(); // 2D partie basse
									{
										glTranslatef(0,-2.5,0);
										glBegin( GL_TRIANGLES );
										//devant
											glVertex3f( 0.875f, 0.0f, 0.25f);
											glVertex3f(-0.875f, 0.0f, 0.25f);
											glVertex3f( 0.875f,-1.5f, 0.25f);
										//derrière
											glVertex3f( 0.875f, 0.0f, -0.25f);
											glVertex3f(-0.875f, 0.0f, -0.25f);
											glVertex3f( 0.875f,-1.5f, -0.25f);
										//dessous1
											glVertex3f(-0.875f, 0.0f, 0.25f);
											glVertex3f( 0.875f,-1.5f, 0.25f);
											glVertex3f( 0.875f,-1.5f,-0.25f);
										//dessous2
											glVertex3f(-0.875f, 0.0f, 0.25f);
											glVertex3f(-0.875f, 0.0f,-0.25f);
											glVertex3f( 0.875f,-1.5f,-0.25f);
										glEnd();
									}
									glPopMatrix();
								}
								glPopMatrix();
							}
						}
						glPopMatrix();

						glRotatef(angle_jambe_dark, 1,0,0);
						
					}
					glPopMatrix();
					
					glColor3f(0.5,0.48,0.52);
					glPushMatrix(); // gauche
					{
						if(arreter_animation_dark == false)
						{
							if(bras_gauche_bouge == false && garde_dark == 0)	
							{
								srand(time(NULL));
								aleatoire_dark_link_epee = (rand() % 10	);
								bras_gauche_dark = aleatoire_dark_link_epee;
								if(bras_gauche_dark == 1 || bras_gauche_dark == 8)
								{
									montee0_descente1_bras_gauche_dark = 0;
								}
							}


							if(bras_gauche_dark != 1 && bras_gauche_dark != 8)
							{
								glRotatef(angle_jambe_dark, 1,0,0);
							}

							if(bras_gauche_dark == 1 || bras_gauche_dark == 8)
							{
								bras_gauche_bouge = true;

								if(Collision(box_personnage, box_epee_dark) && touche_vrai_link == true) //collision pour barre de vie
								{	
									touche_vrai_link = false;
									if(vie_vrai_link == 3 && garde == 0)
									{
										transparence_vie_3 = 0.05;
										vie_vrai_link -= 1;
									}
									else if(vie_vrai_link == 2 && garde == 0)
									{
										transparence_vie_3 = 0.05;
										transparence_vie_2 = 0.05;
										vie_vrai_link -= 1;
									}
									else if(vie_vrai_link == 1 && garde == 0)
									{
										transparence_vie_3 = 0.05;
										transparence_vie_2 = 0.05;
										transparence_vie_1 = 0.05;
										vie_vrai_link -= 1;

										position_x = 0;	
										position_y = 2;
										position_z = 20;

										if(vie_vrai_link == 0)
										{
											vie_vrai_link = 3;	
											transparence_vie_3 = 1;
											transparence_vie_2 = 1;
											transparence_vie_1 = 1;
										}
																

									}
			
								}


								if(angle_bras_gauche_dark > -45 && montee0_descente1_bras_gauche_dark == 0)
								{
									angle_bras_gauche_dark -= 4;
									glRotatef(angle_bras_gauche_dark, 1,1,0);
									if(angle_bras_gauche_dark<= -45)
									{
										montee0_descente1_bras_gauche_dark = 1;
									}
								}
								else if (angle_bras_gauche_dark < 0 && montee0_descente1_bras_gauche_dark == 1 )
								{
									glRotatef(angle_bras_gauche_dark, 1,1,0);
									angle_bras_gauche_dark += 4;
									if(angle_bras_gauche_dark >= 0)
									{
										montee0_descente1_bras_gauche_dark = 2;
										bras_gauche_dark = 0;
										bras_gauche_bouge = false;
									}
								}

								box_epee_dark.x = position_dark_x;
								box_epee_dark.y = position_dark_y - 3;
								box_epee_dark.z = position_dark_z - 13;

								box_epee_dark.w = 16;
								box_epee_dark.h = 24;
								box_epee_dark.d = 14;

							}
							else
							{
								touche_vrai_link = true;
							}

						}
						

						glTranslatef(3,-0.5,0); // épaule
						glutSolidSphere(.9,32,32);
						
						glRotatef(90,0,1,0); // bras
						glRotatef(50,1,0,0);
						gluCylinder(obj,1,.8,4,32,32);
						
						glTranslatef(0,0,4); // coude
						glutSolidSphere(0.8,32,32);
						
						glRotatef(-15,0,1,0); // avant-bras
						gluCylinder(obj,0.8,0.7,4,32,32);
						
						glColor3f(0.890, 0.823, 0.572); // main
						glRotatef(110,0,0,1);
						glTranslatef(0,0,4.1);
						glutSolidSphere(0.8,32,32);
						
						glRotatef(-33,0,0,1);
						glRotatef( 95,1,0,0);
						
						glPushMatrix(); // épée
						{


							glPushMatrix(); // pommeau
							{
								glColor3f(0.211, 0.168, 0.631);
								glTranslatef(0,0,-1.5);
								
								gluCylinder(obj,0.4,0.4,3,32,32);
								
								glTranslatef(0,0,2);
								
								gluCylinder(obj,0.4,0.6,2,32,32);
								glTranslatef(0,0,2);
								gluDisk(obj,0,0.6,32,32);
							}
							glPopMatrix();
							
							glTranslatef(0,0,-1.5);
							glRotatef(-180,1,0,0);
							
							glPushMatrix(); // garde
							{
								gluCylinder(obj,0.4,0.7,0.1,32,32);
								glTranslatef(0,0,0.1);
								gluCylinder(obj,0.7,0.5,0.3,32,32);
								glTranslatef(0,0,0.3);
								gluCylinder(obj,0.5,0.5,0.4,32,32);
								
								glPushMatrix(); // partie droite
								{
									glTranslatef(0,0.65,0.2);
									glRotatef(-10,1,0,0);
									
									glPushMatrix();
										glScalef(0.7,2,0.7);
										glutSolidCube(0.5);
									glPopMatrix();
									
									glPushMatrix();
										glTranslatef(0,0,0.25);
										glRotatef(-30,1,0,0);
										glTranslatef(0,0.32,0.2);
										glScalef(0.7,0.7,1.5);
										glRotatef(30,1,0,0);
										glutSolidCube(0.5);
									glPopMatrix();
								}
								glPopMatrix();
								
								glPushMatrix(); // partie gauche
								{
									glTranslatef(0,-0.65,0.2);
									glRotatef(10,1,0,0);
									
									glPushMatrix();
										glScalef(0.7,2,0.7);
										glutSolidCube(0.5);
									glPopMatrix();
									
									glPushMatrix();
										glTranslatef(0,0,0.25);
										glRotatef(30,1,0,0);
										glTranslatef(0,-0.32,0.2);
										glScalef(0.7,0.7,1.5);
										glRotatef(-30,1,0,0);
										glutSolidCube(0.5);
									glPopMatrix();
								}
								glPopMatrix();
								
								glTranslatef(0,0,0.4);
								gluCylinder(obj,0.5,0.7,0.4,32,32);
								glTranslatef(0,0,0.4);
								gluDisk(obj,0,0.7,32,32);
								
								glPushMatrix(); // porte-joyau
									glScalef(0.6,1,2);
									glutSolidSphere(0.5,32,32);
								glPopMatrix();
								
								glPushMatrix(); // joyau
									glColor3f(1,1,0);
									glScalef(0.8,0.5,1.5);
									glutSolidSphere(0.5,32,32);
								glPopMatrix();
							}
							glPopMatrix();
								
							glPushMatrix(); // lame
							{
								glTranslatef(0,0,1.2); // base
								glColor3f(.99,.99,.99);
								glScalef(0.2,0.6,1);
								gluCylinder(obj,0.7,0.7,2,32,32);
								
								glTranslatef(0,0,2); // base vers lame
								gluCylinder(obj,0.7,0.9,0.2,32,32);
								
								glTranslatef(0,0,0.2); // lame
								gluCylinder(obj,0.9,0.9,4,32,32);
								
								glTranslatef(0,0,4); // pointe
								gluCylinder(obj,0.9,0.7,0.3,32,32);
								glTranslatef(0,0,0.3);
								gluCylinder(obj,0.7,0.5,0.3,32,32);
								glTranslatef(0,0,0.3);
								gluCylinder(obj,0.5,0.3,0.3,32,32);
								glTranslatef(0,0,0.3);
								gluCylinder(obj,0.3,0,0.3,32,32);
							}
							glPopMatrix();
						}
						glPopMatrix();


					}
					glPopMatrix();
				}
				glPopMatrix();
			}
		}
		glPopMatrix();
	}



	glPushMatrix(); //barre de vie
	{
		if (vie_dark_link != 0)
		{
			glTranslatef (position_dark_x  + 8, position_dark_y + 8, position_dark_z);
			glPushMatrix(); //barre 1
			{
				glTranslatef(-5,0,-5);
				glScalef(3,0.5,0.5);
				glColor4f(couleur_barre_r,couleur_barre_g,couleur_barre_b,transparence_barre_1);
				glutSolidSphere(1,8,8);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //barre 2
			{
				glTranslatef(-8,0,-5);
				glScalef(3,0.5,0.5);
				glColor4f(couleur_barre_r,couleur_barre_g,couleur_barre_b,transparence_barre_2);
				glutSolidSphere(1,8,8);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //barre 3
			{
				glTranslatef(-11,0,-5);
				glScalef(3,0.5,0.5);
				glColor4f(couleur_barre_r,couleur_barre_g,couleur_barre_b,transparence_barre_3);
				glutSolidSphere(1,8,8);
				glEnd();
			}
			glPopMatrix();


			glEnd();
		}
		
	}
	glPopMatrix();


	glPushMatrix(); //ile 5 dark
	{

		glPushMatrix(); //Maison dark
		{
			glTranslatef(5020, 5020, 4900);
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
				glTranslatef(101.5,12,17);
				glScalef(1.9,1.5,0.4);
				glColor3f(0.77,0.69,0.49);
				glutSolidCube(7.0);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //mur de devant au mileu en haut texture
			{		
				glTranslatef(94.85,6.75,18.502);
				glBegin(GL_QUADS);
				glColor3f(1,1,1);
					glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
					//set point in 3D and texture space
					glTexCoord2f(0.0f,0.0f);
					glVertex3f(0.0f,0.0f,0.0f);
					
					glTexCoord2f(1.0f,0.0f);
					glVertex3f(13.3f,0.0f,0.0f);
					
					glTexCoord2f(1.0f,1.0f);
					glVertex3f(13.3f,10.5f,0.0f);
					
					glTexCoord2f(0.0f,1.0f);
					glVertex3f(0.0f,10.5f,0.0f);

				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //fentre en devant gauche
			{		
				glTranslatef(82.5,8,18.5);
				glScalef(2,1.5,0.4);
				glColor3f(1,1,1);
				glutSolidCube(7.0);
				glEnd();
			}
			glPopMatrix();



			glPushMatrix(); //fentre en devant droite
			{		
				glTranslatef(119.5,8,18.5);
				glScalef(2,1.5,0.4);
				glColor3f(1,1,1);
				glutSolidCube(7.0);
				glEnd();
			}
			glPopMatrix();

			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //sol blanc dark
		{
			glTranslatef(4300,5000,5000);
			glScalef(500,1,500);
			glColor3f(1,1,1);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //lampadaire
		{

			glTranslatef(4100,5022,4920);
			glRotatef(90,0,1,0);

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
			glEnd();

		}
		glPopMatrix();


		glPushMatrix(); //sol eau dark
		{
			glTranslatef(4300,5004,5000);
			glScalef(500,1,500);
			glColor4f(0.25,0.41,0.88,0.5);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glEnd();
	}
	glPopMatrix();




	glPushMatrix(); //triforce au sol
	{
		glTranslatef(0,-14,700);
		glRotatef(80,1,0,0);

		glScalef(0.5,0.5,0.2);
		glPushMatrix();
		{
			glTranslatef(0,25,25);
			creer_triforce();
			glEnd();
		}
		glPopMatrix();

		
		glPushMatrix();
		{
			glTranslatef(5,14,19.5);
			creer_triforce();
			glEnd();
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(-5,14,19.5);
			creer_triforce();
			glEnd();
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(5,14,30.5);
			creer_triforce();
			glEnd();
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(-5,14,30.5);
			creer_triforce();
			glEnd();
		}
		glPopMatrix();


		glEnd();
	}
	glPopMatrix();

	if (transparence_boule_1 == 1 && transparence_boule_3 == 1 && transparence_boule_3 == 1 && transparence_boule_4 == 1 && transparence_boule_5 == 1 && transparence_boule_6 == 1)
	{
		

		glPushMatrix(); //sol fin
		{
			glTranslatef(0,50,700);

			creer_cloture(0,9,9, 90);
			creer_cloture(0,9,-9, -90);
			creer_cloture(8,9,0, 180);
			creer_cloture(-8,9,0, -180);


			glScalef(7,1,7);
			glColor3f(0.43, 0.57, 0);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();

		
		glPushMatrix(); //triforce aura
		{
			glTranslatef(0,-10,710);



			box_aura.x = 0;
			box_aura.y = -10;
			box_aura.z = 710;

			box_aura.w = 8;
			box_aura.h = 8;
			box_aura.d = 8;


			if(Collision(box_aura, box_personnage))
			{	
				position_x = 0;
				position_y = 72;
				position_z = 700;
				message = true;
			}



			if(message == true)
			{
				glPushMatrix(); //triforce
				{
					glTranslatef(0,0,850);

					glScalef(15,15,15);
					glPushMatrix();
					{
						glTranslatef(0,25,25);
						creer_triforce();
						glEnd();
					}
					glPopMatrix();

					
					glPushMatrix();
					{
						glTranslatef(5,14,19.5);
						creer_triforce();
						glEnd();
					}
					glPopMatrix();

					glPushMatrix();
					{
						glTranslatef(-5,14,19.5);
						creer_triforce();
						glEnd();
					}
					glPopMatrix();

					glPushMatrix();
					{
						glTranslatef(5,14,30.5);
						creer_triforce();
						glEnd();
					}
					glPopMatrix();

					glPushMatrix();
					{
						glTranslatef(-5,14,30.5);
						creer_triforce();
						glEnd();
					}
					glPopMatrix();

					glEnd();
				}
				glPopMatrix();

				glPushMatrix(); //message
				{
					glColor3f(1,1,1);
					glRasterPos3f(-5, 10, -715);
					glutBitmapString (GLUT_BITMAP_TIMES_ROMAN_24, "BRAVO");
					glEnd();
				}
				glPopMatrix();


			}



			glRotatef(180,0,1,0);
			glRotatef(angle_triforce, 0,1,0);
			angle_triforce += 1;
			glScalef(15,15,15);
			glColor4f(1,0.8,0.2, 0.75);
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
	



	// TIC TAC TOE


	if(position_y > 6000 && position_y < 6500)
	{
		glPushMatrix(); // Tic-Tac-Toe
		{
			glTranslatef(5848, 6022, 6042);
			glRotatef(90, 0,1,0);
			glScalef(8,8,8);

			glPushMatrix(); // création cadre
			{
				glTranslatef(-0.5,0.5,0); // vers x
				for(int i = 0; i<10; i++){
					glTranslatef(1,0,0);
					glutSolidCube(1);
					if(i==3 || i==6){
						glPushMatrix();
							for(int j = 0; j<9; j++){
									glTranslatef(0,1,0);
									glutSolidCube(1);
							}
						glPopMatrix();
					}
				}
				
				glTranslatef(0,-1,0); // vers y
				for(int i = 0; i<10; i++){
					glTranslatef(0,1,0);
					glutSolidCube(1);
					if(i==3 || i==6){
						glPushMatrix();
							for(int j = 0; j<9; j++){
									glTranslatef(-1,0,0);
									glutSolidCube(1);
							}
						glPopMatrix();
					}
				}
				
				glTranslatef(1,0,0); // vers -x
				for(int i = 0; i<10; i++){
					glTranslatef(-1,0,0);
					glutSolidCube(1);
				}
				
				glTranslatef(0,1,0); // vers -y
				for(int i = 0; i<10; i++){
					glTranslatef(0,-1,0);
					glutSolidCube(1);
				}
			}
			glPopMatrix(); // fin cadre
			
			// Jeu
			{
				if (ttt_0 == 1) tout_a_zero();
				
				// Victoire		
				int gagne(){
				// lignes
					if (victoire == 0)
					{
						if((ttt_1 + ttt_2 + ttt_3 == 3) && (ttt_1_color == ttt_2_color) && (ttt_1_color == ttt_3_color)){
							if (ttt_tour%2 != 0){ 
								victoire = 1;
								ttt_1_color = ttt_2_color = ttt_3_color = 3;
							}
							if (ttt_tour%2 == 0){
								victoire = 2;
								ttt_1_color = ttt_2_color = ttt_3_color = 4;
							 }
							return victoire;
						}
						if((ttt_4 + ttt_5 + ttt_6 == 3) && (ttt_4_color == ttt_5_color) && (ttt_4_color == ttt_6_color)){
							if (ttt_tour%2 != 0){ 
								victoire = 1;
								ttt_4_color = ttt_5_color = ttt_6_color = 3;
							}
							if (ttt_tour%2 == 0){
								victoire = 2;
								ttt_4_color = ttt_5_color = ttt_6_color = 4;
							 }
							return victoire;
						}
						if((ttt_7 + ttt_8 + ttt_9 == 3) && (ttt_7_color == ttt_8_color) && (ttt_7_color == ttt_9_color)){
							if (ttt_tour%2 != 0){ 
								victoire = 1;
								ttt_7_color = ttt_8_color = ttt_9_color = 3;
							}
							if (ttt_tour%2 == 0){
								victoire = 2;
								ttt_7_color = ttt_8_color = ttt_9_color = 4;
							 }
							return victoire;
						}
						if((ttt_1 + ttt_4 + ttt_7 == 3) && (ttt_1_color == ttt_4_color) && (ttt_1_color == ttt_7_color)){
							if (ttt_tour%2 != 0){ 
								victoire = 1;
								ttt_1_color = ttt_4_color = ttt_7_color = 3;
							}
							if (ttt_tour%2 == 0){
								victoire = 2;
								ttt_1_color = ttt_4_color = ttt_7_color = 4;
							 }
							return victoire;
						}
						if((ttt_2 + ttt_5 + ttt_8 == 3) && (ttt_2_color == ttt_5_color) && (ttt_2_color == ttt_8_color)){
							if (ttt_tour%2 != 0){ 
								victoire = 1;
								ttt_2_color = ttt_5_color = ttt_8_color = 3;
							}
							if (ttt_tour%2 == 0){
								victoire = 2;
								ttt_2_color = ttt_5_color = ttt_8_color = 4;
							 }
							return victoire;
						}
						if((ttt_3 + ttt_6 + ttt_9 == 3) && (ttt_3_color == ttt_6_color) && (ttt_3_color == ttt_9_color)){
							if (ttt_tour%2 != 0){ 
								victoire = 1;
								ttt_3_color = ttt_6_color = ttt_9_color = 3;
							}
							if (ttt_tour%2 == 0){
								victoire = 2;
								ttt_3_color = ttt_6_color = ttt_9_color = 4;
							 }
							return victoire;
						}
					// diagonales
						if((ttt_3 + ttt_5 + ttt_7 == 3) && (ttt_3_color == ttt_5_color) && (ttt_3_color == ttt_7_color)){
							if (ttt_tour%2 != 0){ 
								victoire = 1;
								ttt_3_color = ttt_5_color = ttt_7_color = 3;
							}
							if (ttt_tour%2 == 0){
								victoire = 2;
								ttt_3_color = ttt_5_color = ttt_7_color = 4;
							 }
							return victoire;
						}
						if((ttt_1 + ttt_5 + ttt_9 == 3) && (ttt_1_color == ttt_5_color) && (ttt_1_color == ttt_9_color)){
							if (ttt_tour%2 != 0){ 
								victoire = 1;
							}
							if (ttt_tour%2 == 0){
								victoire = 2;
								ttt_1_color = ttt_5_color = ttt_9_color = 4;
							 }
							return victoire;
						}
					}

					return 0;
				}
				gagne();
				// fin Victoire
				
				//IA
				if(victoire == 0){
					int combien_cases_libres(){ // calcul du nombre de cases libres
						int resultat = 0;
						if (ttt_1 == 0) resultat += 1;
						if (ttt_2 == 0) resultat += 1;
						if (ttt_3 == 0) resultat += 1;
						if (ttt_4 == 0) resultat += 1;
						if (ttt_5 == 0) resultat += 1;
						if (ttt_6 == 0) resultat += 1;
						if (ttt_7 == 0) resultat += 1;
						if (ttt_8 == 0) resultat += 1;
						if (ttt_9 == 0) resultat += 1;
						return resultat;
					}
					if((ttt_tour%2 != 0) && (combien_cases_libres() > 0)){ // test tour et si il reste une case libre
				// *** qu'a-t-il été joué ? ***
						int cases_libres[combien_cases_libres()];
						//initialisation
						for(int i=0; i < combien_cases_libres(); i++) cases_libres[i] = 0;
						//remplissage
						for(int i=0; i < combien_cases_libres(); i++){
							if 		((ttt_1 == 0) && cases_libres[i-1] < 1) cases_libres[i] = 1;
							else if ((ttt_2 == 0) && cases_libres[i-1] < 2) cases_libres[i] = 2;
							else if ((ttt_3 == 0) && cases_libres[i-1] < 3) cases_libres[i] = 3;
							else if ((ttt_4 == 0) && cases_libres[i-1] < 4) cases_libres[i] = 4;
							else if ((ttt_5 == 0) && cases_libres[i-1] < 5) cases_libres[i] = 5;
							else if ((ttt_6 == 0) && cases_libres[i-1] < 6) cases_libres[i] = 6;
							else if ((ttt_7 == 0) && cases_libres[i-1] < 7) cases_libres[i] = 7;
							else if ((ttt_8 == 0) && cases_libres[i-1] < 8) cases_libres[i] = 8;
							else if ((ttt_9 == 0) && cases_libres[i-1] < 9) cases_libres[i] = 9;
						}
						
				// *** choix d'une case ***
						int rand_a_b(int a, int b){
							return ( rand()/(double)RAND_MAX ) * (b-a) + a;
						}
						int random = rand_a_b(0,combien_cases_libres());
						int choix =  cases_libres[random];
						if (choix == 1){
							ttt_1 = 1;
							ttt_1_color = 2;
							ttt_tour += 1;
						}
						if (choix == 2){
							ttt_2 = 1;
							ttt_2_color = 2;
							ttt_tour += 1;
						}
						if (choix == 3){
							ttt_3 = 1;
							ttt_3_color = 2;
							ttt_tour += 1;
						}
						if (choix == 4){
							ttt_4 = 1;
							ttt_4_color = 2;
							ttt_tour += 1;
						}
						if (choix == 5){
							ttt_5 = 1;
							ttt_5_color = 2;
							ttt_tour += 1;
						}
						if (choix == 6){
							ttt_6 = 1;
							ttt_6_color = 2;
							ttt_tour += 1;
						}
						if (choix == 7){
							ttt_7 = 1;
							ttt_7_color = 2;
							ttt_tour += 1;
						}
						if (choix == 8){
							ttt_8 = 1;
							ttt_8_color = 2;
							ttt_tour += 1;
						}
						if (choix == 9){
							ttt_9 = 1;
							ttt_9_color = 2;
							ttt_tour += 1;
						}
					}
				}
				if ((victoire == 1 || victoire == 2) && position_y > 6000 && position_y <  6100)
				{
					usleep(500000);
					position_x = 0;
					position_y = 2;
					position_z = 20;
					transparence_boule_5 = 1;
				}
				//fin IA
					
				//Déroulement des actions
				{
					if (ttt_1 == 1){
						glPushMatrix();
							if(ttt_1_color == 1) glColor3f(0,0,1);
							if(ttt_1_color == 2) glColor3f(1,0,0);
							if(ttt_1_color == 3) glColor3f(0,1,0);
							if(ttt_1_color == 4) glColor3f(1,0,1);
							glTranslatef(2,2,0);
							glutSolidCube(1);
						glPopMatrix();
					}
					if (ttt_2 == 1){
						glPushMatrix();
							if(ttt_2_color == 1) glColor3f(0,0,1);
							if(ttt_2_color == 2) glColor3f(1,0,0);
							if(ttt_2_color == 3) glColor3f(0,1,0);
							if(ttt_2_color == 4) glColor3f(1,0,1);
							glTranslatef(5,2,0);
							glutSolidCube(1);
						glPopMatrix();
					}
					if (ttt_3 == 1){
						glPushMatrix();
							if(ttt_3_color == 1) glColor3f(0,0,1);
							if(ttt_3_color == 2) glColor3f(1,0,0);
							if(ttt_3_color == 3) glColor3f(0,1,0);
							if(ttt_3_color == 4) glColor3f(1,0,1);
							glTranslatef(8,2,0);
							glutSolidCube(1);
						glPopMatrix();
					}
					if (ttt_4 == 1){
						glPushMatrix();
							if(ttt_4_color == 1) glColor3f(0,0,1);
							if(ttt_4_color == 2) glColor3f(1,0,0);
							if(ttt_4_color == 3) glColor3f(0,1,0);
							if(ttt_4_color == 4) glColor3f(1,0,1);
							glTranslatef(2,5,0);
							glutSolidCube(1);
						glPopMatrix();
					}
					if (ttt_5 == 1){
						glPushMatrix();
							if(ttt_5_color == 1) glColor3f(0,0,1);
							if(ttt_5_color == 2) glColor3f(1,0,0);
							if(ttt_5_color == 3) glColor3f(0,1,0);
							if(ttt_5_color == 4) glColor3f(1,0,1);
							glTranslatef(5,5,0);
							glutSolidCube(1);
						glPopMatrix();
					}
					if (ttt_6 == 1){
						glPushMatrix();
							if(ttt_6_color == 1) glColor3f(0,0,1);
							if(ttt_6_color == 2) glColor3f(1,0,0);
							if(ttt_6_color == 3) glColor3f(0,1,0);
							if(ttt_6_color == 4) glColor3f(1,0,1);
							glTranslatef(8,5,0);
							glutSolidCube(1);
						glPopMatrix();
					}
					if (ttt_7 == 1){
						glPushMatrix();
							if(ttt_7_color == 1) glColor3f(0,0,1);
							if(ttt_7_color == 2) glColor3f(1,0,0);
							if(ttt_7_color == 3) glColor3f(0,1,0);
							if(ttt_7_color == 4) glColor3f(1,0,1);
							glTranslatef(2,8,0);
							glutSolidCube(1);
						glPopMatrix();
					}
					if (ttt_8 == 1){
						glPushMatrix();
							if(ttt_8_color == 1) glColor3f(0,0,1);
							if(ttt_8_color == 2) glColor3f(1,0,0);
							if(ttt_8_color == 3) glColor3f(0,1,0);
							if(ttt_8_color == 4) glColor3f(1,0,1);
							glTranslatef(5,8,0);
							glutSolidCube(1);
						glPopMatrix();
					}
					if (ttt_9 == 1){
						glPushMatrix();
							if(ttt_9_color == 1) glColor3f(0,0,1);
							if(ttt_9_color == 2) glColor3f(1,0,0);
							if(ttt_9_color == 3) glColor3f(0,1,0);
							if(ttt_9_color == 4) glColor3f(1,0,1);
							glTranslatef(8,8,0);
							glutSolidCube(1);
						glPopMatrix();
					}
				}
				// fin Déroulement
			}
			//fin Jeu
		}
		glPopMatrix();



		glPushMatrix(); //sol ile tictactoe
		{
			glTranslatef(5950,6000,6000);

			glScalef(70,1,40);
			glColor3f(1,1,1);
			glutSolidCube(3.0);
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //lampadaire
		{

			glTranslatef(5890,6022,6040);
			glRotatef(90,0,1,0);

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
			glEnd();

		}
		glPopMatrix();


		glPushMatrix(); //Maison tic tac toe
		{
			glTranslatef(6020, 6020, 5900);
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
				glTranslatef(101.5,12,17);
				glScalef(1.9,1.5,0.4);
				glColor3f(0.77,0.69,0.49);
				glutSolidCube(7.0);
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //mur de devant au mileu en haut texture
			{		
				glTranslatef(94.85,6.75,18.502);
				glBegin(GL_QUADS);
				glColor3f(1,1,1);
					glBindTexture(GL_TEXTURE_2D,texture[0]);//load texture buffer
					//set point in 3D and texture space
					glTexCoord2f(0.0f,0.0f);
					glVertex3f(0.0f,0.0f,0.0f);
					
					glTexCoord2f(1.0f,0.0f);
					glVertex3f(13.3f,0.0f,0.0f);
					
					glTexCoord2f(1.0f,1.0f);
					glVertex3f(13.3f,10.5f,0.0f);
					
					glTexCoord2f(0.0f,1.0f);
					glVertex3f(0.0f,10.5f,0.0f);

				glEnd();
			}
			glPopMatrix();


			glPushMatrix(); //fentre en devant gauche
			{		
				glTranslatef(82.5,8,18.5);
				glScalef(2,1.5,0.4);
				glColor3f(1,1,1);
				glutSolidCube(7.0);
				glEnd();
			}
			glPopMatrix();



			glPushMatrix(); //fentre en devant droite
			{		
				glTranslatef(119.5,8,18.5);
				glScalef(2,1.5,0.4);
				glColor3f(1,1,1);
				glutSolidCube(7.0);
				glEnd();
			}
			glPopMatrix();

			glEnd();
		}
		glPopMatrix();
	}



// FIN DE MODELISATION

glPopMatrix();

glFlush();

glClearColor(couleur_ciel_x,couleur_ciel_y, couleur_ciel_z, 0.8);



  glutSwapBuffers();
  
}

int main(int argc, char **argv) 
{  
  return notre_init(argc, argv, &Modelisation);
}
