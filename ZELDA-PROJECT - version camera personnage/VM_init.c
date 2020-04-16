#include "VM_init.h"
extern float xrot;
extern int yrot;
extern float xcamrot;
extern float ycamrot;
extern float zcamrot;
extern float position_x;
extern float position_y;
extern float position_z;
extern float angle_triangle;
void VM_init()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glTranslatef(0,0,-60);
	glRotatef(xrot, 1,0,0);
	glRotatef(yrot, 0, 1, 0);
	glTranslatef(-position_x,position_y  ,-position_z);	


}
