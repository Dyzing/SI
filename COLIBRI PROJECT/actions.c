#include "actions.h"

extern GLfloat xrot;
extern GLfloat yrot;
extern int blend;
extern int light;
extern GLfloat angle2;
extern GLfloat angle3;
extern GLfloat angle4;
extern GLfloat angle5;


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



void touche_pressee(unsigned char key, int x, int y)
{
    usleep(100);

    switch (key) {
    case ESCAPE:
        exit(1);
        break;

    case ESPACE:
      xrot = 0.0f;
      yrot = 0.0f;
      break;

    case TOUCHE_MIN_B:
    case TOUCHE_MAJ_B:
     blend =  switch_blend(blend);
      break;

    case TOUCHE_MIN_L:
    case TOUCHE_MAJ_L:
      light = switch_light(light);
      break;

    case TOUCHE_MAJ_A:
                angle2 = moins_angle(angle2);
                break;
    case TOUCHE_MIN_A:
                angle2 = plus_angle(angle2);
                break;

    case TOUCHE_MAJ_Z:
                angle3 = moins_angle(angle3);
                break;
    case TOUCHE_MIN_Z:
                angle3 = plus_angle(angle3);
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









