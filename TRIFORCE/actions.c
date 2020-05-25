#include "actions.h"
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


extern GLfloat xrot;
extern int yrot;

extern int blend;
extern int light;


extern GLfloat position_x;
extern GLfloat position_y;
extern GLfloat position_z;


extern int lumiere_lampadaire;
extern int lumiere_spot;
extern float couleur_ampoule;
extern float couleur_astre_y;
extern float couleur_astre_z;

extern float couleur_ciel_x;
extern float couleur_ciel_y;
extern float couleur_ciel_z;

extern int dino_bouge;
extern int dino_monte0_descend1_statique2;

extern int mouse_button;
extern int mouse_state;
extern int mouse_x;
extern int mouse_y;
extern int mouse_motion_x;
extern int mouse_motion_y;

extern float angle_jambe;
extern int jambe_avant_arriere;


extern int bras_gauche;
extern int bras_droit;

extern int garde;

extern int montee0_descente1_bras_gauche;
extern int montee0_descente1_bras_droit;

extern int link_bouge;




extern int bras_gauche_dark;
extern int bras_droit_dark;

extern int montee0_descente1_bras_gauche_dark;
extern int montee0_descente1_bras_droit_dark;
extern int garde_dark;

extern float yrot_middle;
extern int camera_middle;
extern int mouse_motion_y_middle;

extern float xrot_middle;
extern int mouse_motion_x_middle;


  extern int victoire;
  extern int ttt_0;
  extern int ttt_1;
  extern int ttt_1_color;
  extern int ttt_2;
  extern int ttt_2_color;
  extern int ttt_3;
  extern int ttt_3_color;
  extern int ttt_4;
  extern int ttt_4_color;
  extern int ttt_5;
  extern int ttt_5_color;
  extern int ttt_6;
  extern int ttt_6_color;
  extern int ttt_7;
  extern int ttt_7_color;
  extern int ttt_8;
  extern int ttt_8_color;
  extern int ttt_9;
  extern int ttt_9_color;

  extern int ttt_tour;

extern float res_prediction_avancer;
extern float res_prediction_reculer;


extern float transparence_boule_1;
extern float transparence_boule_2;
extern float transparence_boule_3;
extern float transparence_boule_4;
extern float transparence_boule_5;
extern float transparence_boule_6;

extern bool peut_avancer_maison_1;
extern bool peut_avancer_maison_2;
extern bool peut_avancer_maison_3;
extern bool peut_avancer_maison_4;
extern bool peut_avancer_maison_5;
extern bool peut_avancer_maison_6;


#include <math.h>




float avancer_x(float x) // Z
{
  x =  x + cos((-yrot%360 + 90) * M_PI/180);
  return x;
}

float reculer_x(float x) // Q
{
  x = x - cos((-yrot%360 + 90) * M_PI/180);
  return x;
}


float avancer_z(float z) // Z
{
  z =  z - sin((-yrot%360 + 90) * M_PI/180);
  return z;
}

float reculer_z(float z) // Q
{
  z = z +  sin((-yrot%360 + 90) * M_PI/180);
  return z;
}



void set_camera_3(float x, float y, float z)
{
    glTranslatef(-x,-y,-z);  
}



void prediction_avancer(float x, float z, float sx, float sz)
{
  float prediction_x = x;
  prediction_x =  avancer_x(prediction_x);

  float prediction_z = z;
  prediction_z =  avancer_z(prediction_z);

  res_prediction_avancer = sqrtf(powf(prediction_x - sx, 2) + powf(prediction_z - sz, 2));


}

void prediction_reculer(float x, float z, float sx, float sz)
{
  float prediction_x = x;
  prediction_x =  reculer_x(prediction_x);

  float prediction_z = z;
  prediction_z =  reculer_z(prediction_z);

  res_prediction_reculer = sqrtf(powf(prediction_x - sx, 2) + powf(prediction_z - sz, 2));

}


void touche_pressee(unsigned char key, int x, int y)
{

  switch (key) 
  {
    case ESCAPE:
        exit(1); 
        break;

    case ESPACE:
      if(dino_bouge == 0)
      {
        dino_bouge = 1;
        dino_monte0_descend1_statique2 = 0;
      }
      break;

    case TOUCHE_MIN_B:
    case TOUCHE_MAJ_B:
      if(lumiere_spot == 0)
      {
        lumiere_spot = 1;
        couleur_astre_y = 0.84;
        couleur_astre_z = 0.0;
        couleur_ciel_x = 0.53;
        couleur_ciel_y = 0.8;
        couleur_ciel_z = 0.92;
        break;
      }
      else
      {
        lumiere_spot = 0;
        couleur_astre_y= 1.0;
        couleur_astre_z = 1.0;
        couleur_ciel_x = 0.09;
        couleur_ciel_y = 0.09;
        couleur_ciel_z = 0.43;
        break;
      }

    case TOUCHE_MIN_N:
    case TOUCHE_MAJ_N:
      if(lumiere_lampadaire == 0)
      {
                lumiere_lampadaire = 1;
                couleur_ampoule = 1.0;
                break;
      } 
      else
      {
                lumiere_lampadaire = 0;
                couleur_ampoule = 0.3;
                break;
      }

    case TOUCHE_MAJ_Z:
    case TOUCHE_MIN_Z:

              if(angle_jambe <= 41 && jambe_avant_arriere == 1)
              {
                link_bouge = 1;
                angle_jambe += 4;
                if(angle_jambe == 41)
                  jambe_avant_arriere = 0;
              }
              else if (angle_jambe >= -43 && jambe_avant_arriere == 0)
              {
                link_bouge = 1;
                angle_jambe -= 4;
                if(angle_jambe == -43)
                  jambe_avant_arriere = 1;
              }
              if(position_z > 975 && position_y < 0)
              {
                
              }
              else if(position_y > 1000 && position_y < 1425)
              {
                position_z += 0.5;
                position_y += 0.5;
              }
              else if(position_y > 3000 && position_y < 3200 && position_x <= 2940)
              {
                
              }
              else if(position_z == 700 && position_y == 72)
              {
                
              }             
              else
              {                
                {
                  if(res_prediction_avancer < 400  && position_y < 100 && position_y > 0 && peut_avancer_maison_1 && peut_avancer_maison_2 && peut_avancer_maison_3 && peut_avancer_maison_4 && peut_avancer_maison_5 && peut_avancer_maison_6) // ghost lobby
                  {
                    position_x = avancer_x(position_x);
                    position_z = avancer_z(position_z);
                    prediction_avancer(position_x, position_z, 0, 325);
                  }
                  else if(res_prediction_avancer < 75 && position_y > 2000 && position_y < 2200) // ghost dino
                  {
                    position_x = avancer_x(position_x);
                    position_z = avancer_z(position_z);  
                    prediction_avancer(position_x, position_z, 1932, 2000); 
                  }
                  else if(res_prediction_avancer < 800 && position_y > 5000 && position_y < 5500) // ghost dark
                  {
                    position_x = avancer_x(position_x);
                    position_z = avancer_z(position_z);  
                    prediction_avancer(position_x, position_z, 4207, 5000); 
                  }
                  else if ((res_prediction_avancer < 70 && position_y > 1000 && position_y <= 1425)) // ghost rocher
                  {
                    position_x = avancer_x(position_x);
                    position_z = avancer_z(position_z);
                    prediction_avancer(position_x, position_z, 1000, 1505); 
                  }
                  else
                  {
                    if(position_y > 0 && position_y < 25  && peut_avancer_maison_1 && peut_avancer_maison_2 && peut_avancer_maison_3 && peut_avancer_maison_4 && peut_avancer_maison_5 && peut_avancer_maison_6) // ghost lobby
                    {
                      prediction_reculer(position_x, position_z, 0, 325);
                      prediction_avancer(position_x, position_z, 0, 325);
                    }
                    else if(position_y > 2000 && position_y < 2200)  // ghost dino
                    {
                      prediction_reculer(position_x, position_z, 1932, 2000);
                      prediction_avancer(position_x, position_z, 1932, 2000);
                    }
                    else if(position_y > 5000 && position_y < 5500) // ghost dark
                    {
                      prediction_reculer(position_x, position_z, 4207, 5000);
                      prediction_avancer(position_x, position_z, 4207, 5000);
                    }
                    else if(position_y > 1000 && position_y <= 1425) // ghost dark
                    {
                      prediction_reculer(position_x, position_z, 1000, 1505); 
                      prediction_avancer(position_x, position_z, 1000, 1505);
                    }
                    
                  }
                }
              } 
              break;

    case TOUCHE_MAJ_Q:
    case TOUCHE_MIN_Q:
                if((position_z >= 900 && position_y < 0) || (position_y > 1000 && position_y < 1425))
                {
                  if(position_x < 44 && position_y < 0)
                    position_x += 4;
                  if(position_y > 1000 && position_y < 1500)
                  {
                    if(position_x >= 1032)
                    {

                    }
                    else
                      position_x += 32;
                  }
                }
                break;

    case TOUCHE_MAJ_S:
    case TOUCHE_MIN_S:
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
                 if(position_z == 700 && position_y == 72)
                {

                }
                else
                {
                  if(res_prediction_reculer < 400 && position_y < 100 && position_y > 0) // ghost lobby
                  {
                    position_x = reculer_x(position_x);
                    position_z = reculer_z(position_z);  
                    prediction_reculer(position_x, position_z, 0, 325);
                  }
                  else if(res_prediction_reculer < 75 && position_y > 2000 && position_y < 2200) // ghost dino
                  {
                    position_x = reculer_x(position_x);
                    position_z = reculer_z(position_z);  
                    prediction_reculer(position_x, position_z, 1932, 2000); 
                  }
                  else if(res_prediction_reculer < 800 && position_y > 5000 && position_y < 5500) // ghost dark
                  {
                    position_x = reculer_x(position_x);
                    position_z = reculer_z(position_z);  
                    prediction_reculer(position_x, position_z, 4207, 5000); 
                  }
                  else if ((res_prediction_reculer < 70 && position_y > 1000 && position_y <= 1425)) // ghost rocher
                  {
                    position_x = reculer_x(position_x);
                    position_z = reculer_z(position_z);
                    prediction_reculer(position_x, position_z, 1000, 1505); 
                  }

                  else
                  {
                    if(position_y > 0 && position_y < 25) // ghost lobby
                    {
                      prediction_reculer(position_x, position_z, 0, 325);
                      prediction_avancer(position_x, position_z, 0, 325);
                    }
                    else if(position_y > 2000 && position_y < 2200) // ghost dino
                    {
                      prediction_reculer(position_x, position_z, 1932, 2000);
                      prediction_avancer(position_x, position_z, 1932, 2000);
                    }
                    else if(position_y > 5000 && position_y < 5500) // ghost dark
                    {
                      prediction_reculer(position_x, position_z, 4207, 5000);
                      prediction_avancer(position_x, position_z, 4207, 5000);
                    }
                    else if(position_y > 1000 && position_y <= 1425) // ghost rocher
                    {
                      prediction_reculer(position_x, position_z, 1000, 1505); 
                      prediction_avancer(position_x, position_z, 1000, 1505);
                    }

                    
                  }
                }

                break;

    case TOUCHE_MAJ_D:
    case TOUCHE_MIN_D:
                if((position_z >= 900 && position_y < 0) || (position_y > 1000 && position_y < 1425))
                {
                  if(position_x > -44 && position_y < 0)
                    position_x-= 4;
                  if(position_y > 1000 && position_y < 1500)
                  {
                    if(position_x<= 968)
                    {

                    }
                    else
                      position_x -= 32;
                  }
                }
                break;



      //Déclarations Tic-Tac-Toe

    case TOUCHE_0:
      {
        if (ttt_0 == 0) ttt_0 = 1;
        break;
      }
    case TOUCHE_1:          //Je joue...
      {
        if((ttt_tour%2 == 0) && (victoire == 0)){ //...si c'est à mon tour de jouer...
          if(ttt_1 == 0){   //...et si la case est vide
            ttt_1 = 1;
            ttt_1_color = 1;
            ttt_tour += 1;
          }
        }
        break;
      }
    case TOUCHE_2:
      {
        if((ttt_tour%2 == 0) && (victoire == 0)){
          if(ttt_2 == 0){
            ttt_2 = 1;
            ttt_2_color = 1;
            ttt_tour += 1;
          }
        }
        break;
      }
    case TOUCHE_3:
      {
        if((ttt_tour%2 == 0) && (victoire == 0)){
          if(ttt_3 == 0){
            ttt_3 = 1;
            ttt_3_color = 1;
            ttt_tour += 1;
          }
        }
        break;
      }
    case TOUCHE_4:
      {
        if((ttt_tour%2 == 0) && (victoire == 0)){
          if(ttt_4 == 0){
            ttt_4 = 1;
            ttt_4_color = 1;
            ttt_tour += 1;
          }
        }
        break;
      }
    case TOUCHE_5:
      {
        if((ttt_tour%2 == 0) && (victoire == 0)){
          if(ttt_5 == 0){
            ttt_5 = 1;
            ttt_5_color = 1;
            ttt_tour += 1;
          }
        }
        break;
      }
    case TOUCHE_6:
      {
        if((ttt_tour%2 == 0) && (victoire == 0)){
          if(ttt_6 == 0){
            ttt_6 = 1;
            ttt_6_color = 1;
            ttt_tour += 1;
          }
        }
        break;
      }
    case TOUCHE_7:
      {
        if((ttt_tour%2 == 0) && (victoire == 0)){
          if(ttt_7 == 0){
            ttt_7 = 1;
            ttt_7_color = 1;
            ttt_tour += 1;
          }
        }
        break;
      }
    case TOUCHE_8:
      {
        if((ttt_tour%2 == 0) && (victoire == 0)){
          if(ttt_8 == 0){
            ttt_8 = 1;
            ttt_8_color = 1;
            ttt_tour += 1;
          }
        }
        break;
      }
    case TOUCHE_9:
      {
        if((ttt_tour%2 == 0) && (victoire == 0)){
          if(ttt_9 == 0){
            ttt_9 = 1;
            ttt_9_color = 1;
            ttt_tour += 1;
          }
        }
        break;
      }
  }//fin tictactoe
   
}


void vMouse(int button, int state, int x, int y)
{
  switch (button)
  {
    case GLUT_LEFT_BUTTON :
      if (state==GLUT_DOWN) 
      {
        if(position_y > 3000 && position_y < 3100)
        {
          mouse_state = GLUT_DOWN;
          mouse_x = x;
          mouse_y = y;
          mouse_button = button;
        }
        else
        {
          if(bras_gauche == 0 && garde == 0)
          {
            bras_gauche = 1;
            montee0_descente1_bras_gauche = 0;
          }
          
        }
        break;
      }
      if (state==GLUT_UP)
      {
        mouse_state = GLUT_UP;
        break;
      }
      break;
    
    case GLUT_MIDDLE_BUTTON :
      if (state==GLUT_DOWN)
      {
        camera_middle = 1;
      } 
      if (state==GLUT_UP) 
      {
        camera_middle = 0;
      }
      break;
    case GLUT_RIGHT_BUTTON :
      if (state==GLUT_DOWN)
      {
        if(bras_droit == 0 && garde == 0)
        {
          bras_droit = 1;
          if(montee0_descente1_bras_droit == 2)
            montee0_descente1_bras_droit= 0;
          else if(montee0_descente1_bras_droit == 1)
          {
            garde = 0;
          }
        }
        else if(bras_droit == 1 && garde == 1)
        {
            garde = 0;    
        }
        break;
      } 

    default :
      break;
  }
}


void vMousemotion(int x, int y)
{
  if((position_y > 3000 && position_y < 3100) || (position_y < 0) || (position_y > 1000 && position_y < 1425))
  {

  }
  else
  {
    if(x < 50) //scroll gauche
    {
        yrot -= 1;
    }
    else if(x > 1550) //scroll droite
    {
        yrot += 1;
    }
    else if(y < 50) //scroll haut
    {
        xrot += 1;
    }
    else if(y > 850) //scroll bas
    {
        xrot -= 1;
    }
    else if(x < mouse_motion_x) //left
    {
        yrot -= 1;
    }
    else if(x > mouse_motion_x) //right
    {
        yrot += 1;
    }
    else if(y > mouse_motion_y) //haut
    {
        xrot -= 1;
    }
      else if(y < mouse_motion_y) //bas
    {
        xrot += 1;
    }

    mouse_motion_x = x;
    mouse_motion_y = y;
  }
}


void vMousemotion_middle(int x, int y)
{
  if(camera_middle == 1)
  {
     if(x < 50) //scroll gauche
        {
            yrot_middle -= 1;
        }
        else if(x > 1550) //scroll droite
        {
            yrot_middle += 1;
        }
        else if(y < 50) //scroll haut
        {
            xrot_middle += 1;
        }
        else if(y > 850) //scroll bas
        {
            xrot_middle -= 1;
        }
        else if(x < mouse_motion_x_middle) //left
        {
            yrot_middle -= 1;
        }
        else if(x > mouse_motion_x_middle) //right
        {
            yrot_middle += 1;
        }
        else if(y > mouse_motion_y_middle) //haut
        {
            xrot_middle -= 1;
        }
          else if(y < mouse_motion_y_middle) //bas
        {
            xrot_middle += 1;
        }
        mouse_motion_y_middle = yrot_middle;
        mouse_motion_x_middle = xrot_middle;
  }
}


