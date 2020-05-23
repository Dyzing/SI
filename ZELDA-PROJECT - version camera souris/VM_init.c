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
extern float angle_oiseau_vertical;

extern GLfloat position_dino_x;
extern GLfloat position_dino_y;
extern GLfloat position_dino_z;

extern float transparence_boule_4;

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
	    printf("je suis un rocher\n");
	      position_x = 1000;
	      position_z = 1039;
	      position_y = 1020;
	      // position_z = 1439;
	      // position_y = 1420;
	      xrot = -4.0;
	      yrot = -180;
	}      
	else if ( (position_z >= 1562) && ((position_x <= 1002)) && ((position_x >= 993)) )
	{
		printf("rentrer de terre");	
		position_x = 0;
		position_y = 2;
		position_z = 20;
		transparence_boule_4 = 1;
	}
  	else if( ( (position_z <= 3) && ((position_z >= -10)) && ((position_x <= -105)) )  && position_x >= -110)
	{
		//et_camera_3(2000, 2010, 2000);
		//glTranslatef(0,0 ,60);
		//glRotatef(90, 0,1,0);
		printf("test dino");	
    	position_x = 1990;
        position_y = 2022;
        position_z = 2000;

	}
	else if ( (position_z <= 2005) && ((position_z >= 1995)) && ((position_x >= 2000)) )
	{
		printf("rentrer de dino");	
		position_x = 0;
		position_y = 2;
		position_z = 20;
	}
	else if( ( (position_z <= 206) && ((position_z >= 193)) && ((position_x >= 102))  ) && position_x <= 105)
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
	}
	else if( ( (position_z <= 152) && ((position_z >= 140)) && ((position_x <= -105)) )   && position_x >= -110)
	
{		//et_camera_3(2000, 2010, 2000);
		//glTranslatef(0,0 ,60);
		//glRotatef(90, 0,1,0);
		printf("test simon");	
    	position_x = 2940;
        position_y = 3015;
        position_z = 3000;
        xrot = -6.0;
        yrot = -87;
        angle_triangle = -180;
	}
	
  	else if( ( (position_z <= 303) && ((position_z >= 293)) && ((position_x <= -105)) )   && position_x >= -110)
	{
		//et_camera_3(2000, 2010, 2000);		
		//glTranslatef(0,0 ,60);
		//glRotatef(90, 0,1,0);
		printf("test dark");	
    	position_x = 4250;
        position_y = 5022;
        position_z = 4800;
        yrot -= 90;

	}
	else if ( (position_z <= 5005) && ((position_z >= 4995)) && ((position_x <= 5010) && position_x >= 5000) )
	{
		printf("rentrer de dark");	
		position_x = 0;
		position_y = 2;
		position_z = 20;
	}
	else if( ( (position_z <= 355) && ((position_z >= 346)) && ((position_x >= 102)) )  && position_x <= 105)
	{
		//et_camera_3(2000, 2010, 2000);
		//glTranslatef(0,0 ,60);
		//glRotatef(90, 0,1,0);
		printf("test tictactoe");	
    	position_x = 5940;
        position_y = 6022;
        position_z = 6000;
        yrot -= 180;
	}
	// else if ( (position_z <= 2055) && ((position_z >= 1940)) && ((position_x <= 2045)) && (position_x >= 1950) && !( (position_z <= 2005) && ((position_z >= 1995)) && ((position_x >= 2000)) )) // à changer les bornes pour celle de l'ile et d'ajouter la maison sur l'ile
	// {
	// 	printf("test 2");
	// 	//set_camera_3(2000, 2010 , 2000 );
	//  	//glRotatef(90,0,1,0);

	// }
	else if (position_y > 1000 && position_y < 1425)
	{
		set_camera_3(position_x,position_y + 10,position_z -30);
	}
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