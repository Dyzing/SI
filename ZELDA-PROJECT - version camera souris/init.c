#include "init.h"
#include "actions.h"
#include "ppm.h"

GLvoid Redimensionne(GLsizei Width, GLsizei Height)
{
	glViewport (0, 0, Width, Height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float) Width  /(float) Height, 0.1, 1500);
	glMatrixMode(GL_MODELVIEW);
	
	//Texture
	glClearColor(0,0,0,0);
	TEXTURE_STRUCT * txtstrct = readPpm("Damier.ppm");
	GLuint texture[1];
	glGenTextures(1,texture);
    glBindTexture(GL_TEXTURE_2D,texture[0]);

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_S,
        GL_CLAMP
    );
    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_T,
        GL_MIRRORED_REPEAT
    );
    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MAG_FILTER,
        GL_NEAREST
    );
    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MIN_FILTER,
        GL_NEAREST
    );
    //load texture into buffer
    glTexImage2D(GL_TEXTURE_2D,
        0,GL_RGB,
        txtstrct->width,txtstrct->height,
        0,GL_RGB,GL_UNSIGNED_BYTE, 
        txtstrct->data);
        
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

	glEnable(GL_TEXTURE_2D);
}

int notre_init(int argc, char** argv, void (*DrawGLScene)())
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(720, 480);
	glutInitWindowPosition(600, 250);
	glutCreateWindow("ZELDA PROJECT");
	glutFullScreen();
	glutDisplayFunc(*DrawGLScene);
	glutIdleFunc(*DrawGLScene);
	glutReshapeFunc(Redimensionne);
	glutKeyboardFunc(touche_pressee);
	glutMouseFunc(vMouse);
	glutMotionFunc(vMousemotion_middle);
	glutPassiveMotionFunc(vMousemotion);
	glClearColor(0,0,0,0);
	
	glEnable(GL_DEPTH_TEST);
	
	
	glutMainLoop();
	return 1;
}

