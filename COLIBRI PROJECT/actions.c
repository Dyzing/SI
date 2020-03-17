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

extern GLfloat position_x;
extern GLfloat position_y;
extern GLfloat position_z;

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

float x_vers_zero(float position_x)
{
    if(position_x < 0)
    {
          position_x = position_x +1;
          return position_x;
    }
    if(position_x > 0)
    {
          position_x = position_x - 1;
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
    if(position_y > 0)
    {
          position_y = position_y - 1;
          return position_y;
    }
    else
    {
          return position_y;
    }
}

float z_vers_zero(float position_z)
{
    if(position_z < 0)
    {
          position_z = position_z +1;
          return position_z;
    }
    if(position_z > 0)
    {
          position_z = position_z - 1;
          return position_z;
    }
    else
    {
          return position_z;
    }
}

float avancer_x(float position_x) // Z
{
  position_x =  position_x + cos(angle_triangle * M_PI/180);
  return position_x;
}

float reculer_x(float position_x) // Q
{
  position_x = position_x -  cos(angle_triangle * M_PI/180);
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
    angle = angle + 1;
    return angle;
}


float tourner_droite(float angle) // D
{
    angle = angle - 1;
    return angle;
}


void touche_pressee(unsigned char key, int x, int y)
{
    usleep(100);

    switch (key) {
    case ESCAPE:
        xcamrot = 0;
        zcamrot = -50;
        ycamrot = 0;
        break;

    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      break;

    case TOUCHE_MIN_B:
    case TOUCHE_MAJ_B:
     blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_N:
    case TOUCHE_MAJ_N:
      light = switch_light(light);
      break;

    case TOUCHE_MAJ_A:
                angle2 = moins_angle(angle2);
                break;
    case TOUCHE_MIN_A:
                angle2 = plus_angle(angle2);
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
                angle4 = moins_angle(angle4);
                break;
    case TOUCHE_MIN_E:
                angle4 = plus_angle(angle4);
                break;

    case TOUCHE_MAJ_R:
                angle5 = moins_angle(angle5);
                break;
    case TOUCHE_MIN_R:
                angle5 = plus_angle(angle5);
                break;

    case TOUCHE_MAJ_C:
                position_x = x_vers_zero(position_x);
                position_y = y_vers_zero(position_y);
                position_z = z_vers_zero(position_z);
                break;
    case TOUCHE_MIN_C:
                position_x = x_vers_zero(position_x);
                position_y = y_vers_zero(position_y);
                position_z = z_vers_zero(position_z);
                break;

    case TOUCHE_MAJ_T:
                angle_triangle =  plus_tourner(angle_triangle);
                break;
    case TOUCHE_MIN_T:
                angle_triangle =  plus_tourner(angle_triangle);
                break;

    case TOUCHE_MAJ_O:
                zcamrot += 1;;
                break;
    case TOUCHE_MIN_O:
                zcamrot += 1;;
                break;

    case TOUCHE_MAJ_K:
                xcamrot =  tourner_gauche(xcamrot);
                break;
    case TOUCHE_MIN_K:
                xcamrot =  tourner_gauche(xcamrot);
                break;

    case TOUCHE_MAJ_L:
                zcamrot -= 1;
                break;
    case TOUCHE_MIN_L:
                zcamrot -= 1;
                break;

    case TOUCHE_MAJ_M:
                xcamrot =  tourner_droite(xcamrot);
                break;
    case TOUCHE_MIN_M:
                xcamrot =  tourner_droite(xcamrot);
                break;                                
    }
}

void touche_speciale(int touche, int x, int y)
{
         usleep(100);
    switch (touche) {

                case GLUT_KEY_PAGE_UP:
                  xrot += 5.0f;
                        break;

                case GLUT_KEY_PAGE_DOWN:
                  xrot -= 5.0f;
                        break;

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









