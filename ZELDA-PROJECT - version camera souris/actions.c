#include "actions.h"
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>


extern GLfloat xrot;
extern int yrot;
extern GLfloat xcamrot;
extern GLfloat ycamrot;
extern GLfloat zcamrot;

extern int blend;
extern int light;
extern GLfloat angle2;
extern GLfloat angle3;
extern GLfloat angle4;
extern GLfloat angle5;
extern int angle_triangle;
extern GLfloat angle_oiseau_vertical;

extern GLfloat position_x;
extern GLfloat position_y;
extern GLfloat position_z;

extern GLfloat angle_tete_principal;
extern int montee0_descente1_tete_principal;

extern GLfloat angle_queue_principale;
extern int montee0_descente1_queue_principale;

extern int lumiere_lampadaire;
extern int lumiere_spot;
extern float couleur_ampoule;
extern float couleur_astre_y;
extern float couleur_astre_z;

extern float couleur_ciel_x;
extern float couleur_ciel_y;
extern float couleur_ciel_z;

extern GLfloat position_dino_x;
extern GLfloat position_dino_y;
extern GLfloat position_dino_z;
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

extern float angle_bras_gauche;

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




float plus_angle(float angle)
{
        if ((0 <= angle) && (angle <  90))
                angle += 10;
        return angle;
}

float moins_angle(float angle)
{
        if ((0 < angle) && (angle <= 90))
                angle -=10;
        return angle;
}

float plus_tourner(float angle)
{
    angle = angle + 3;
    return angle;
}


float arreter_tourner(float angle)
{
    angle = 0;
    return angle;
}

float x_vers_fleur(float position_x)
{
    if(position_x <= 16.7)
    {
          position_x = position_x + 0.4;
          return position_x;
    }
    if(position_x >= 17.1)
    {
          position_x = position_x - 0.4;
          return position_x;
    }
    else
    {
          return position_x;
    }
}

float y_vers_zero(float position_y)
{
    if(position_y < 0)
    {
          position_y = position_y +1;
          return position_y;
    }
    else if(position_y > 0)
    {
          position_y = position_y - 1;
          return position_y;
    }
    else
    {
          return position_y;
    }
}

float z_vers_fleur(float position_z)
{
    if(position_z <= -21.4)
    {
          position_z = position_z + 0.4;
          return position_z;
    }
    else if(position_z >= -21.0)
    {
          position_z = position_z - 0.4;
          return position_z;
    }
    else
    {
          return position_z;
    }
}

float angle_vers_fleur (float angle_triangle)
{
    if(angle_triangle <= 34.0)
    {
          angle_triangle = angle_triangle + 2;
          return angle_triangle;
    }
    if(angle_triangle >= 38.0)
    {
          angle_triangle = angle_triangle - 2;
          return angle_triangle;
    }
    else
    {
          return angle_triangle;
    }
}


float angle_oiseau_vertical_vers_fleur (float angle_oiseau_vertical)
{
    if(angle_oiseau_vertical <= 24.9)
    {
          angle_oiseau_vertical = angle_oiseau_vertical + 0.3;
          return angle_oiseau_vertical;
    }
    if(angle_oiseau_vertical >= 25.1)
    {
          angle_oiseau_vertical = angle_oiseau_vertical - 0.3;
          return angle_oiseau_vertical;
    }
    else
    {
          return angle_oiseau_vertical;
    }
}


float position_x_oiseau_dehors_fleur(float position_alpha)
{
    position_alpha -= 0.3;
    return position_alpha;
}

float position_z_oiseau_dehors_fleur(float position_alpha)
{
    position_alpha += 0.3;
    return position_alpha;
}

float angle_oiseau_dehors_fleur(float angle_oiseau_vertical)
{
    angle_oiseau_vertical -= 0.6;
    return angle_oiseau_vertical;
}



float avancer_x(float x) // Z
{
  //printf("yrot : %i\n", -yrot);
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


float x_set_zero(float position_x)
{
  position_x = 0;
  return position_x;
}

float y_set_zero(float position_y)
{
  position_y = 0;
  return position_y;
}

float z_set_zero(float position_z)
{
  position_z = 0;
  return position_z;
}

float tourner_gauche(float angle) // Q
{   
    angle = fmod(angle + 3,360);
    return angle;
}


float tourner_droite(float angle) // D
{
    angle = fmod(angle - 3,360);
    return angle;
}


float monter(float angle) // D
{
    angle = fmod(angle,360) + 1;
    return angle;
}


float descendre(float angle) // D
{
    angle = fmod(angle,360) - 1;
    return angle;
}



float avancer_x_cam(float position_alpha) // Z
{
  position_alpha =  position_alpha + cos(yrot * M_PI/180);
  return position_alpha;
}

float reculer_x_cam(float position_alpha) // Q
{
  position_alpha = position_alpha -  cos(yrot * M_PI/180);
  return position_alpha;
}


float avancer_z_cam(float position_alpha) // Z
{
  position_alpha =  position_alpha - sin(yrot * M_PI/180);
  return position_alpha;
}

float reculer_z_cam(float position_alpha) // Q
{
  position_alpha = position_alpha +  sin(yrot * M_PI/180);
  return position_alpha;
}

void set_camera_3(float x, float y, float z)
{
    glTranslatef(-x,-y,-z);  
}

float set_camera_1(float old_position_camera,float new_position_camera)
{
  old_position_camera = new_position_camera;
}

void prediction_avancer(float x, float z, float sx, float sz)
{
  float prediction_x = x;
  prediction_x =  avancer_x(prediction_x);

  float prediction_z = z;
  prediction_z =  avancer_z(prediction_z);

  res_prediction_avancer = sqrtf(powf(prediction_x - sx, 2) + powf(prediction_z - sz, 2));
  printf("\nres_prediction_avancer %f\n", res_prediction_avancer);


  //return res_prediction; 
}

void prediction_reculer(float x, float z, float sx, float sz)
{
  float prediction_x = x;
  prediction_x =  reculer_x(prediction_x);

  float prediction_z = z;
  prediction_z =  reculer_z(prediction_z);

  res_prediction_reculer = sqrtf(powf(prediction_x - sx, 2) + powf(prediction_z - sz, 2));
  printf("\nres_prediction_reculer %f\n", res_prediction_reculer);


  //return res_prediction; 
}


void touche_pressee(unsigned char key, int x, int y)
{
    //usleep(100);

  switch (key) 
  {
    case ESCAPE:
        exit(1); 
        break;

    case ESPACE:
      //printf("espace, dino_bouge %i\n", dino_bouge);
      dino_bouge = 1;
      dino_monte0_descend1_statique2 = 0;
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
    // blend =  switch_blend(blend);

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
              // printf("position_z %f\n, position_y %f\n", position_z, position_y);
              // printf("angle_jambe : %f\n",angle_jambe );
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
                printf("ne peut plus avancer ocean \n");
              }
              else if(position_y > 1000 && position_y < 1425)
              {
                position_z += 0.5;
                position_y += 0.5;
              }
              else if(position_y > 3000 && position_y < 3200 && position_x <= 2940)
              {
                printf("ne peut plus avancer simon \n");
                //printf("position_x : %f\n, position_y : %f\n, position_z : %f\n",position_x, position_y, position_z);
              }
              else if(position_z == 700 && position_y == 72)
              {
                printf("ne peut plus avancer fin \n");
              }
              // else if (!( ((position_z <= 2005) && (position_z >= 1995)) && ((position_x >= 2000) && (position_x <= 2010)) ) && ( (position_z <= 2055) && ((position_z >= 1940)) && ((position_x <= 2045)) && (position_x >= 1950) ))
              // {
              //   printf("je teste\n");
              //   position_x = avancer_x(position_x);
              //   position_z = avancer_z(position_z);
              //   set_camera_3(2000, 2020 , 2000 ); //glTranslatef(-position_x,-position_y - 10 ,-position_z);  
              // }
              // }
              else
              {
                // if (!( (position_z <= 2055) && ((position_z >= 1940)) && ((position_x <= 2045)) && (position_x >= 1950) )  && position_y >= 1999 && position_y <= 2500) 
                // {
                //     printf("steph");
                //     position_x = avancer_x(position_x);
                //     position_z = avancer_z(position_z);
                // }
                // else
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
                    printf("\nne peut plus AVANCER ghost wall\n");
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
                      printf("ne peut se décaler davantage a gauche\n");
                    }
                    else
                      position_x += 32;
                  }
                }
                else
                {
                  angle_triangle =  tourner_gauche(angle_triangle);
                }
                break;

    case TOUCHE_MAJ_S:
    case TOUCHE_MIN_S:
                //printf("angle_jambe : %f\n",angle_jambe );
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
                // if(position_y > 1000 && position_y <= 1425 && position_z <= 1515)
                // {
                //   printf("ne peut plus reculer terre \n");
                // }
                //else
                 if(position_z == 700 && position_y == 72)
                {
                  printf("ne peut plus avancer fin \n");
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
                    printf("\nne peut plus AVANCER ghost wall\n");
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
                      printf("ne peut se décaler davantage a droite\n");
                    }
                    else
                      position_x -= 32;
                  }
                }
                else
                {
                  angle_triangle = tourner_droite(angle_triangle);
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
      printf("Souris a: %d %d \n",x,y);
      printf("Bouton Gauche\n");
      if (state==GLUT_DOWN) 
      {

        printf("Appui\n");
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
        printf("Relachement\n");
        mouse_state = GLUT_UP;
        break;
      }
      break;
    
    case GLUT_MIDDLE_BUTTON :
      printf("Bouton Milieu\n");
       if (state==GLUT_DOWN)
      {
        printf("Appui middle\n");
        camera_middle = 1;
      } 
      if (state==GLUT_UP) 
      {
        printf("Relachement middle\n");
        camera_middle = 0;
      }
      break;
    case GLUT_RIGHT_BUTTON :
      printf("Bouton Droit\n");
      if (state==GLUT_DOWN)
      {
        printf("Appui\n");
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
            //montee0_descente1_bras_droit = 1:
        }

      } 
      if (state==GLUT_UP) printf("Relachement\n");
      break;

    default :
      printf("Erreur??\n");
      break;
  }
}


void vMousemotion(int x, int y)
{
  //printf("xrot : %f\n ,yrot : %i\n",xrot, yrot);
  if((position_y > 3000 && position_y < 3100) || (position_y < 0) || (position_y > 1000 && position_y < 1425))
  {
    printf("ne tourne pas la camera simon ou ocean ou terre\n");
  }
  else
  {
  //printf("x : %i\n, y : %i\n", x,y);
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


