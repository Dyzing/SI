#include "init.h"
#include "actions.h"

  GLvoid Redimensionne(GLsizei Width, GLsizei Height)
  {
	  glViewport (0, 0, Width, Height);
	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	  gluPerspective(45, (float) Width  /(float) Height, 0.1, 100);
	  glMatrixMode(GL_MODELVIEW);
  }


int notre_init(int argc, char** argv, void (*DrawGLScene)())
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("ma fenetre");
	glutDisplayFunc(*DrawGLScene);
	glutIdleFunc(*DrawGLScene);
	glutReshapeFunc(Redimensionne);
	glutKeyboardFunc(touche_pressee);
	glutSpecialFunc(touche_speciale);
	glClearColor(0,0,0,0);
	glutMainLoop();
	return 1;
}

