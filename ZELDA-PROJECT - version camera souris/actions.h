#ifndef __ACTIONS
#define __ACTIONS

/* ascii codes for various special keys */

#include "touches.h"
#include "switch_blend.h"
#include "switch_light.h"
#include <stdlib.h>
#include <GL/glut.h>


void touche_pressee(unsigned char key, int x, int y);

void touche_speciale(int touche, int x, int y);

void set_camera_3(float x, float y, float z);

void vMouse(int button, int state, int x, int y);


void vMousemotion(int x, int y);

#endif
