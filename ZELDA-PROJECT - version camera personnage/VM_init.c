#include "VM_init.h"
#include "actions.h"
extern float xrot;
extern int yrot;
extern float xcamrot;
extern float ycamrot;
extern float zcamrot;
extern float position_x;
extern float position_y;
extern float position_z;
extern int angle_triangle;


void VM_init()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glTranslatef(0,0,-60);
	glRotatef(xrot, 1,0,0);
	glRotatef(yrot, 0, 1, 0);
  	if( ( (position_z <= 3) && ((position_z >= -10)) && ((position_x <= -105)) ) )
	{
		//et_camera_3(2000, 2010, 2000);
		//glTranslatef(0,0 ,60);
		//glRotatef(90, 0,1,0);
    	position_x = 1999;
        position_z = 2000;
        position_y = 2000;
	}
	else if ( (position_z <= 2005) && ((position_z >= 1995)) && ((position_x >= 2000)) )
	{
		position_x = -104;
		position_y = -10;
		position_z = -4;
	}
	else if ( (position_z <= 2005) && ((position_z >= 1995)) && ((position_x >= 2000)) ) // à changer les bornes pour celle de l'ile et d'ajouter la maison sur l'ile
	{
		position_x = -104;
		position_y = -10;
		position_z = -4;

		//set_camera_3(2000, 2010 , 2000 );
	 	//glRotatef(90,0,1,0);
	}
	else
	{
		set_camera_3(position_x, position_y + 10 , position_z ); //glTranslatef(-position_x,-position_y - 10 ,-position_z);
	}
		

}
