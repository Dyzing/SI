#include "actions.h"

extern GLfloat xrot;
extern GLfloat yrot;
extern GLfloat xcamrot;
extern GLfloat ycamrot;
extern GLfloat zcamrot;

extern int blend;
extern int light;
extern GLfloat angle2;
extern GLfloat angle3;
extern GLfloat angle4;
extern GLfloat angle5;
extern GLfloat angle_triangle;
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



float avancer_x(float position_x) // Z
{
  position_x =  position_x + cos(angle_triangle * M_PI/180);
  return position_x;
}

float reculer_x(float position_x) // Q
{
  position_x = position_x - cos(angle_triangle * M_PI/180);
  return position_x;
}


float avancer_z(float position_x) // Z
{
  position_z =  position_z - sin(angle_triangle * M_PI/180);
  return position_z;
}

float reculer_z(float position_x) // Q
{
  position_z = position_z +  sin(angle_triangle * M_PI/180);
  return position_z;
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
    angle = fmod(angle,360) + 3;
    return angle;
}


float tourner_droite(float angle) // D
{
    angle = fmod(angle,360) - 3;
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

void touche_pressee(unsigned char key, int x, int y)
{
    usleep(100);

    switch (key) 
  {
    case ESCAPE:
        exit(1); 
        break;

    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      xcamrot = 0.0f;
      zcamrot = 0.0f;
      ycamrot = 0.0f;
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

    case TOUCHE_MAJ_A:
                angle_oiseau_vertical = monter(angle_oiseau_vertical);
                break;
    case TOUCHE_MIN_A:
                angle_oiseau_vertical = monter(angle_oiseau_vertical);
                break;

    case TOUCHE_MAJ_Z:
              position_x = avancer_x(position_x);
              position_z = avancer_z(position_z);
              break;
    case TOUCHE_MIN_Z:
              position_x = avancer_x(position_x);
              position_z = avancer_z(position_z);
              break;

    case TOUCHE_MAJ_Q:
                angle_triangle = tourner_gauche(angle_triangle);
                break;
    case TOUCHE_MIN_Q:  
                angle_triangle =  tourner_gauche(angle_triangle);
                break;

    case TOUCHE_MAJ_S:
              position_x = reculer_x(position_x);
              position_z = reculer_z(position_z);
                break;
    case TOUCHE_MIN_S:
                position_x = reculer_x(position_x);
                position_z = reculer_z(position_z);  
                break;

    case TOUCHE_MAJ_D:
                angle_triangle = tourner_droite(angle_triangle);
                break;
    case TOUCHE_MIN_D:
                angle_triangle = tourner_droite(angle_triangle);
                break;

    case TOUCHE_MAJ_E:
                angle_oiseau_vertical = descendre(angle_oiseau_vertical);
                break;
    case TOUCHE_MIN_E:
                angle_oiseau_vertical = descendre(angle_oiseau_vertical);
                break;

    case TOUCHE_MAJ_R:
                if(montee0_descente1_tete_principal == 1)
                {
                  angle_tete_principal += 1;
                  if (angle_tete_principal == 20)
                  {
                    montee0_descente1_tete_principal = 0;
                  }
                }
                break;
    case TOUCHE_MIN_R:
                if(montee0_descente1_tete_principal == 0)
                {
                  angle_tete_principal -= 1;
                  if (angle_tete_principal == -15)
                  {
                    montee0_descente1_tete_principal = 1;
                  }
                }         
                break;

    case TOUCHE_MAJ_C:
                if(position_x > 6)
                {
                  position_x = position_x_oiseau_dehors_fleur(position_x);
                }
                if(position_z < -10)
                {
                  position_z = position_z_oiseau_dehors_fleur(position_z);
                }
                if(angle_oiseau_vertical > 0)
                {
                  angle_oiseau_vertical = angle_oiseau_dehors_fleur(angle_oiseau_vertical);
                }
                break;
    case TOUCHE_MIN_C:
                position_x = x_vers_fleur(position_x);
                //position_y = y_vers_zero(position_y);
                position_z = z_vers_fleur(position_z);
                angle_triangle = angle_vers_fleur(angle_triangle);
                angle_oiseau_vertical = angle_oiseau_vertical_vers_fleur(angle_oiseau_vertical);
                break;

    case TOUCHE_MAJ_T:
                  if(angle_queue_principale <20)
                  {
                     montee0_descente1_queue_principale = 1;
                  }
                  angle_queue_principale += montee0_descente1_queue_principale;
                  if (angle_queue_principale== 20)
                  {
                    montee0_descente1_queue_principale = 0;
                  }               
                  break;
    case TOUCHE_MIN_T:
                  if(angle_queue_principale > -30)
                  {
                     montee0_descente1_queue_principale = 1;
                  }
                  angle_queue_principale -= montee0_descente1_queue_principale;
                  if (angle_queue_principale == -30)
                  {
                    montee0_descente1_queue_principale = 0;
                  }
                         
                break;

    case TOUCHE_MAJ_O:
                zcamrot = avancer_x_cam(zcamrot);
                xcamrot = avancer_z_cam(xcamrot);
                break;
    case TOUCHE_MIN_O:
                zcamrot = avancer_x_cam(zcamrot);
                xcamrot = avancer_z_cam(xcamrot);       
                break;

    case TOUCHE_MAJ_K:
                yrot =  tourner_gauche(yrot);
                break;
    case TOUCHE_MIN_K:
                yrot =  tourner_gauche(yrot);
                break;

    case TOUCHE_MAJ_L:
                zcamrot = reculer_x_cam(zcamrot);
                xcamrot = reculer_z_cam(xcamrot);
                break;
    case TOUCHE_MIN_L:
                zcamrot = reculer_x_cam(zcamrot);
                xcamrot = reculer_z_cam(xcamrot);
                break;

    case TOUCHE_MAJ_M:
                yrot =  tourner_droite(yrot);
                break;
    case TOUCHE_MIN_M:
                yrot =  tourner_droite(yrot);
                break; 


    case TOUCHE_MAJ_I:
    case TOUCHE_MIN_I:
                ycamrot += 1;
                break;


    case TOUCHE_MAJ_P:
    case TOUCHE_MIN_P:
                ycamrot -= 1;
                break;  
  } 


}

void touche_speciale(int touche, int x, int y)
{
         usleep(100);
    switch (touche) {
                case GLUT_KEY_UP:
                  xrot += 1.0f;
                        break;

                case GLUT_KEY_DOWN:
                  xrot -= 1.0f;
                        break;

                case GLUT_KEY_LEFT:
                  yrot += 1.0f;
                        break;

                case GLUT_KEY_RIGHT:
                  yrot -= 1.0f;
                        break;
        }

}









