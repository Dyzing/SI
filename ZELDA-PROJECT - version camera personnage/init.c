#include "init.h"
#include "actions.h"

  GLvoid Redimensionne(GLsizei Width, GLsizei Height)
  {
	  glViewport (0, 0, Width, Height);
	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	  gluPerspective(45, (float) Width  /(float) Height, 0.1, 1500);
	  glMatrixMode(GL_MODELVIEW);
  }


int notre_init(int argc, char** argv, void (*DrawGLScene)())
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(720, 480);
	glutInitWindowPosition(600, 250);
	glutCreateWindow("COLIBRI PROJECT");
	glutDisplayFunc(*DrawGLScene);
	glutIdleFunc(*DrawGLScene);
	glutReshapeFunc(Redimensionne);
	glutKeyboardFunc(touche_pressee);
	glutSpecialFunc(touche_speciale);
	glClearColor(0,0,0,0);
	
	glEnable(GL_DEPTH_TEST);
	
	
	glutMainLoop();
	return 1;
}

