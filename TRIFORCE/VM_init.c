#include "VM_init.h"
#include "actions.h"
#include <stdio.h>

extern float xrot;
extern int yrot;

extern float position_x;
extern float position_y;
extern float position_z;
extern int angle_triangle;

extern float yrot_middle;
extern int camera_middle;
extern float xrot_middle;

extern float transparence_boule_1;
extern float transparence_boule_2;
extern float transparence_boule_3;
extern float transparence_boule_4;
extern float transparence_boule_5;


void VM_init()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glTranslatef(0,0,-60);

	if(camera_middle == 1)
	{
		glRotatef(-yrot_middle, 0, 1, 1);
		glRotatef(xrot_middle, 0, 1, 1);
	}
	else
	{
		glRotatef(xrot, 1,0,0);
		glRotatef(yrot, 0, 1, 0);
	}
	

	if((position_z <= 55) && (position_z >= 42) && (position_x >= 100) && position_x <= 105)
	{
	      position_x = 1000;
	      position_z = 1039;
	      position_y = 1020;
	      xrot = -4.0;
	      yrot = -180;
	}      
	else if ( (position_z >= 1562) && ((position_x <= 1002)) && ((position_x >= 993)) )
	{
		position_x = 0;
		position_y = 2;
		position_z = 20;
		transparence_boule_4 = 1;
	}
  	else if( ( (position_z <= 3) && ((position_z >= -10)) && ((position_x <= -105)) )  && position_x >= -110)
	{
    	position_x = 1950;
        position_y = 2022;
        position_z = 1960;
	}
	else if ( (position_z <= 2005) && ((position_z >= 1995)) && ((position_x >= 2000)) )
	{
		position_x = 0;
		position_y = 2;
		position_z = 20;
	}
	else if( ( (position_z <= 206) && ((position_z >= 193)) && ((position_x >= 102))  ) && position_x <= 105)
	{
    	position_x = 0;
        position_y = -50;
        position_z = 950;
        xrot = 0.0;
        yrot = -180;
        angle_triangle = -90;
	}
	else if( ( (position_z <= 152) && ((position_z >= 140)) && ((position_x <= -105)) )   && position_x >= -110)
	{		
    	position_x = 2940;
        position_y = 3015;
        position_z = 3000;
        xrot = -6.0;
        yrot = -87;
        angle_triangle = -180;
	}
	
  	else if( ( (position_z <= 303) && ((position_z >= 293)) && ((position_x <= -105)) )   && position_x >= -110)
	{
    	position_x = 4250;
        position_y = 5025;
        position_z = 4800;
        yrot -= 90;

	}
	else if ( (position_z <= 5005) && ((position_z >= 4995)) && ((position_x <= 5010) && position_x >= 5000) )
	{
		position_x = 0;
		position_y = 2;
		position_z = 20;
	}
	else if( ( (position_z <= 355) && ((position_z >= 346)) && ((position_x >= 102)) )  && position_x <= 105)
	{	
    	position_x = 5940;
        position_y = 6022;
        position_z = 6000;
        yrot -= 180;
	}
	else if (position_y > 1000 && position_y < 1425)
	{
		set_camera_3(position_x,position_y + 10,position_z -30);
	}
	else
	{
		set_camera_3(position_x,position_y + 10,position_z);
	}
		

}
