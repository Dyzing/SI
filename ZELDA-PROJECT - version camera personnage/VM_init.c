#include "VM_init.h"
#include "actions.h"
#include <stdio.h>

extern float xrot;
extern int yrot;
extern float xcamrot;
extern float ycamrot;
extern float zcamrot;
extern float position_x;
extern float position_y;
extern float position_z;
extern int angle_triangle;

extern GLfloat position_dino_x;
extern GLfloat position_dino_y;
extern GLfloat position_dino_z;

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
		printf("test 0");	
    	position_x = 1990;
        position_y = 2010;
        position_z = 2000;

	}
	else if( ( (position_z <= 206) && ((position_z >= 193)) && ((position_x >= 105)) ) )
	{
		//et_camera_3(2000, 2010, 2000);
		//glTranslatef(0,0 ,60);
		//glRotatef(90, 0,1,0);
		printf("test aquatique");	
    	position_x = 0;
        position_y = -50;
        position_z = 950;
        xrot = 0.0;
        yrot = -180;
        angle_triangle = -90;
	}	else if( ( (position_z <= 152) && ((position_z >= 140)) && ((position_x <= -105)) ) )
	{
		//et_camera_3(2000, 2010, 2000);
		//glTranslatef(0,0 ,60);
		//glRotatef(90, 0,1,0);
		printf("test simon");	
    	position_x = 2940;
        position_y = 3010;
        position_z = 3000;
        xrot = -6.0;
        yrot = -87;
        angle_triangle = -180;
	}
	else if ( (position_z <= 2005) && ((position_z >= 1995)) && ((position_x >= 2000)) )
	{
		printf("test 1");	
		position_x = -104;
		position_y = -10;
		position_z = -4;
	}
	// else if ( (position_z <= 2055) && ((position_z >= 1940)) && ((position_x <= 2045)) && (position_x >= 1950) && !( (position_z <= 2005) && ((position_z >= 1995)) && ((position_x >= 2000)) )) // à changer les bornes pour celle de l'ile et d'ajouter la maison sur l'ile
	// {
	// 	printf("test 2");
	// 	//set_camera_3(2000, 2010 , 2000 );
	//  	//glRotatef(90,0,1,0);

	// }
	else
	{
		// if ( (position_z <= 2055) && ((position_z >= 1940)) && ((position_x <= 2045)) && (position_x >= 1950) )
		// {
		// 	//printf("test 2");
		// 	set_camera_3(position_x, position_y + 10 , position_z ); //glTranslatef(-position_x,-position_y - 10 ,-position_z);
		// }
		//else
		//{
			set_camera_3(position_x,position_y + 10,position_z); //glTranslatef(-position_x,-position_y - 10 ,-position_z);
			//set_camera_3(position_dino_x,position_dino_y + 10 , position_dino_z ); //pour camera sur dino
		//}	
	}
		

}
