	glPushMatrix(); // Requin
	{
		GLUquadricObj *obj = gluNewQuadric();
		
		glPushMatrix(); // tronc
		{
			glPushMatrix(); // centre
				glRotatef(90,0,1,0);
				glColor3f(0.305, 0.392, 0.474);
				glScalef(2,0.8,0.9);
				glutSolidSphere(7,32,32);
				
				glTranslatef(0,-0.1,0);
				glColor3f(0.647, 0.701, 0.752);
				glutSolidSphere(7,32,32);
			glPopMatrix();
			
			axes();
			
			glPushMatrix();  // Yeux
			{
				glTranslatef(2,1,-13);
				glColor3f(0,0,0);
				glutSolidSphere(0.5,32,32);
				glTranslatef(-4,0,0);
				glutSolidSphere(0.5,32,32);
			}
			glPopMatrix();
			
			glTranslatef(0,5,0);
			glColor3f(0.305, 0.392, 0.474);
			
			glPushMatrix();  // Machoire
			{
				glTranslatef(0,-5,-18);
				glBegin( GL_TRIANGLES );
				{	//SUPERIEURE
				// dessus centre
					glVertex3f( 0.0f, 0.0f, 0.0f); // A
					glVertex3f( 3.0f, 3.0f, 8.0f); // B
					glVertex3f(-3.0f, 3.0f, 8.0f); // B'
				// dessus gauche 
					glVertex3f( 0.0f, 0.0f, 0.0f); // A
					glVertex3f( 3.0f, 3.0f, 8.0f); // B
					glVertex3f( 4.5f, 0.0f, 8.0f); // C
				// dessus droite 
					glVertex3f( 0.0f, 0.0f, 0.0f); // A
					glVertex3f(-3.0f, 3.0f, 8.0f); // B'
					glVertex3f(-4.5f, 0.0f, 8.0f); // C'
				// dessous centre
					glVertex3f( 0.0f, 0.0f, 0.0f); // A
					glVertex3f( 1.0f,-1.0f, 1.0f); // D
					glVertex3f(-1.0f,-1.0f, 1.0f); // D'
				// dessous gauche
					glVertex3f( 0.0f, 0.0f, 0.0f); // A
					glVertex3f( 1.0f,-1.0f, 1.0f); // D
					glVertex3f( 4.5f, 0.0f, 8.0f); // C
				// dessous gauche exterieure
					glVertex3f( 1.0f,-1.0f, 1.0f); // D
					glVertex3f( 4.5f, 0.0f, 8.0f); // C
					glVertex3f( 4.0f,-2.0f,10.0f); // E
				// dessous droite
					glVertex3f( 0.0f, 0.0f, 0.0f); // A
					glVertex3f(-1.0f,-1.0f, 1.0f); // D'
					glVertex3f(-4.5f, 0.0f, 8.0f); // C'
				// dessous droite exterieure
					glVertex3f(-1.0f,-1.0f, 1.0f); // D'
					glVertex3f(-4.5f, 0.0f, 8.0f); // C'
					glVertex3f(-4.0f,-2.0f,10.0f); // E'
				// dessous
					glVertex3f( 0.0f, 0.0f, 0.0f); // A
					glVertex3f( 4.5f, 0.0f, 8.0f); // C
					glVertex3f(-4.5f, 0.0f, 8.0f); // C'
					
					// INFERIEURE
				// centre
					glVertex3f( 1.0f,-2.0f, 2.0f); // F
					glVertex3f(-1.0f,-2.0f, 2.0f); // F'
					glVertex3f( 0.0f,-3.0f, 3.0f); // G
				// gauche
					glVertex3f( 1.0f,-2.0f, 2.0f); // F
					glVertex3f( 4.0f,-2.0f,10.0f); // E
					glVertex3f( 0.0f,-3.0f, 3.0f); // G
				// droite
					glVertex3f(-1.0f,-2.0f, 2.0f); // F'
					glVertex3f(-4.0f,-2.0f,10.0f); // E'
					glVertex3f( 0.0f,-3.0f, 3.0f); // G
				// dessous
					glVertex3f( 0.0f,-3.0f, 3.0f); // G
					glVertex3f( 4.0f,-2.0f,10.0f); // E
					glVertex3f(-4.0f,-2.0f,10.0f); // E'
				}
				glEnd();
				glTranslatef(1,-1,1);
				glBegin( GL_TRIANGLES ); // DENTS haut
				{
					glColor3f(1,1,1);
					for (float i=0; i<2; i++){
						glVertex3f( dent_x-i, dent_y, dent_z);
						glVertex3f( dent_x-0.5-i, dent_y, dent_z);
						glVertex3f( dent_x-0.25-i, dent_y-0.25, dent_z);
						i = i-0.5;
					}
				}
				glEnd();
				glTranslatef(0,-1,1);
				glBegin( GL_TRIANGLES ); // DENTS bas
				{
					for (float i=0; i<2; i++){
						glVertex3f( dent_x-i, dent_y, dent_z);
						glVertex3f( dent_x-0.5-i, dent_y, dent_z);
						glVertex3f( dent_x-0.25-i, dent_y+0.25, dent_z);
						i = i-0.5;
					}
				}
				glEnd();
			}
			glPopMatrix();
			
			glPushMatrix(); // dorsale
			{
				glColor3f(0.305, 0.392, 0.474);
				glBegin( GL_TRIANGLES );
				{
				//gauche devant
					glVertex3f( 0.0f, 0.0f,-2.0f);
					glVertex3f(-1.0f, 0.0f, 0.0f);
					glVertex3f( 0.0f, 4.0f, 3.0f);
				//gauche derrière
					glVertex3f(-1.0f, 0.0f, 0.0f);
					glVertex3f( 0.0f, 4.0f, 3.0f);
					glVertex3f( 0.0f, 0.0f, 2.0f);
				//droite devant
					glVertex3f( 0.0f, 0.0f,-2.0f);
					glVertex3f( 1.0f, 0.0f, 0.0f);
					glVertex3f( 0.0f, 4.0f, 3.0f);
				//droite derrière
					glVertex3f( 1.0f, 0.0f, 0.0f);
					glVertex3f( 0.0f, 4.0f, 3.0f);
					glVertex3f( 0.0f, 0.0f, 2.0f);
				}
				glEnd();
			}
			glPopMatrix();
			
			glTranslatef(-6,-6,0);
			
			glPushMatrix(); // nageoire gauche
			{
				glBegin( GL_TRIANGLES );
				{
				//gauche dessus devant
					glVertex3f( 0.0f, 0.0f,-1.0f);
					glVertex3f( 0.0f, 1.0f, 0.0f);
					glVertex3f(-10.0f,0.0f, 5.0f);
				//gauche dessus derrière 
					glVertex3f( 0.0f, 1.0f, 0.0f);
					glVertex3f(-10.0f,0.0f, 5.0f);
					glVertex3f( 0.0f, 0.0f, 3.0f);
				//gauche dessous devant
					glVertex3f( 0.0f, 0.0f,-1.0f);
					glVertex3f( 0.0f,-0.5f, 0.0f);
					glVertex3f(-10.0f,0.0f, 5.0f);
				//gauche dessous derrière 
					glVertex3f( 0.0f,-0.5f, 0.0f);
					glVertex3f(-10.0f,0.0f, 5.0f);
					glVertex3f( 0.0f, 0.0f, 3.0f);
				}
				glEnd();
			}
			glPopMatrix();
			
			glTranslatef(12,0,0);
			
			glPushMatrix(); // nageoire droite
			{
				glBegin( GL_TRIANGLES );
				{
				//droite dessus devant
					glVertex3f( 0.0f, 0.0f,-1.0f);
					glVertex3f( 0.0f, 1.0f, 0.0f);
					glVertex3f(10.0f, 0.0f, 5.0f);
				//droite dessus derrière 
					glVertex3f( 0.0f, 1.0f, 0.0f);
					glVertex3f(10.0f, 0.0f, 5.0f);
					glVertex3f( 0.0f, 0.0f, 3.0f);
				//droite dessous devant
					glVertex3f( 0.0f, 0.0f,-1.0f);
					glVertex3f( 0.0f,-0.5f, 0.0f);
					glVertex3f(10.0f, 0.0f, 5.0f);
				//droite dessous derrière 
					glVertex3f( 0.0f,-0.5f, 0.0f);
					glVertex3f(10.0f, 0.0f, 5.0f);
					glVertex3f( 0.0f, 0.0f, 3.0f);
				}
				glEnd();
			}
			glPopMatrix();
		}
		glPopMatrix();
		
		glPushMatrix(); // queue
		{
			glTranslatef(0,0,6);
			glScalef(0.9,0.8,1);
			gluCylinder(obj,6.3,1,15,32,32);
			glTranslatef(0,-0.1,0);
			
			glColor3f(0.647, 0.701, 0.752);
			gluCylinder(obj,6.3,1,15,32,32);
			
			glTranslatef(0,0.1,13);
			
			// aileron
			glColor3f(0.305, 0.392, 0.474);
			glBegin( GL_TRIANGLES );
			{
			//gauche devant haut
				glVertex3f( 0.0f, 0.0f,-1.0f);
				glVertex3f(-1.0f, 0.0f, 2.0f);
				glVertex3f( 0.0f,11.0f, 5.0f);
			//gauche derrière haut
				glVertex3f(-1.0f, 0.0f, 2.0f);
				glVertex3f( 0.0f,11.0f, 5.0f);
				glVertex3f( 0.0f, 0.0f, 3.5f);
			//gauche devant bas
				glVertex3f( 0.0f, 0.0f,-1.0f);
				glVertex3f(-1.0f, 0.0f, 2.0f);
				glVertex3f( 0.0f,-11.0f,5.0f);
			//gauche derrière bas
				glVertex3f(-1.0f, 0.0f, 2.0f);
				glVertex3f( 0.0f,-11.0f,5.0f);
				glVertex3f( 0.0f, 0.0f, 3.5f);
			//droite devant haut
				glVertex3f( 0.0f, 0.0f,-1.0f);
				glVertex3f( 1.0f, 0.0f, 2.0f);
				glVertex3f( 0.0f,11.0f, 5.0f);
			//droite derrière haut
				glVertex3f( 1.0f, 0.0f, 2.0f);
				glVertex3f( 0.0f,11.0f, 5.0f);
				glVertex3f( 0.0f, 0.0f, 3.5f);
			//droite devant bas
				glVertex3f( 0.0f, 0.0f,-1.0f);
				glVertex3f( 1.0f, 0.0f, 2.0f);
				glVertex3f( 0.0f,-11.0f,5.0f);
			//droite derrière bas
				glVertex3f( 1.0f, 0.0f, 2.0f);
				glVertex3f( 0.0f,-11.0f,5.0f);
				glVertex3f( 0.0f, 0.0f, 3.5f);
			}
			glEnd();
			
			axes();
		}
		glPopMatrix();
		
	}
	glPopMatrix();
	
	glPushMatrix(); // Poisson : Turbot
	{
		GLUquadricObj *obj = gluNewQuadric();
		glColor3f(0.282, 0.156, 0.098);
		
		glPushMatrix(); //corps
		{
			glScalef(0.2,1,1);
			glutSolidSphere(3,32,32);
		}
		glPopMatrix();
		
		glPushMatrix(); //tete
		{
			glTranslatef(0,0,-0.5);
			glPushMatrix();
			{
				glScalef(0.3,1,1.5);
				glutSolidSphere(2,32,32);
			}
			glPopMatrix();
			
			glPushMatrix(); //yeux
			{
				glColor3f(0.341, 0.215, 0.160);
				glTranslatef(-0.3,0.5,-2);
				glutSolidSphere(0.15,32,32);
				glTranslatef(0.6,0,0);
				glutSolidSphere(0.15,32,32);
			}
			glPopMatrix();
			
			glPushMatrix(); //machoire
			{
				glTranslatef(0,-1,-2.2); //inf
				glRotatef(33,1,0,0);
				glScalef(0.3,0.1,1.2);
				glutSolidSphere(1,32,32);
				
				glTranslatef(0,-1,-1.5); //sup
				glRotatef(0,1,0,0);
			}
			glPopMatrix();
			
		}
		glPopMatrix();
		
		glPushMatrix(); // nageoires
		{
			gluCylinder(obj,0.6,1,1,32,32);
		}
		glPopMatrix();
		
		glPushMatrix(); // queue
		{
			glTranslatef(0,0,2.9);
			glScalef(0.1,1,1);
			gluCylinder(obj,0.5,1,1,32,32);
			glTranslatef(0,0,1);
			gluDisk(obj,0,1,32,32);
		}
		glPopMatrix();
		
		glPushMatrix(); // ailerons
		{
			glTranslatef(0,1,0.3);
			glScalef(0.05,1.1,1.2);
			glutSolidSphere(2,32,32);
			glTranslatef(0,-2.3,0);
			glutSolidSphere(1.5,32,32);
		}
		glPopMatrix();
		
	}
	glPopMatrix();
	
	glPushMatrix(); // Poisson : Clown
	{
		GLUquadricObj *obj = gluNewQuadric();
	
		glPushMatrix(); // yeux
		{
			glColor3f(0,0,0);
			glTranslatef(-0.3,0.1,-0.75);
			glutSolidSphere(0.05,32,32);
			glTranslatef(0.6,0,0);
			glutSolidSphere(0.05,32,32);
		}
		glPopMatrix();
			
		glColor3f(0.976, 0.443, 0.101);
		glScalef(1,1,2);
		glutSolidSphere(0.5,32,32);
		
		glPushMatrix(); // dorsale
		{
			glTranslatef(0,0.45,0);
			glRotatef(33,1,0,0);
			glScalef(0.1,1,1);
			glutSolidSphere(0.1,32,32);
			glColor3f(0,0,0);
			glScalef(0.8,1,1);
			glTranslatef(0,0.01,0);
			glutSolidSphere(0.1,32,32);
		}
		glPopMatrix();
		
		glPushMatrix(); // ventrale
		{
			glColor3f(0.976, 0.443, 0.101);
			glTranslatef(0,-0.45,0);
			glRotatef(-33,1,0,0);
			glScalef(0.1,1,1);
			glutSolidSphere(0.1,32,32);
			glColor3f(0,0,0);
			glScalef(0.8,1,1);
			glTranslatef(0,-0.01,0);
			glutSolidSphere(0.1,32,32);
		}
		glPopMatrix();
		
		glPushMatrix(); // nageoire g
		{
			glColor3f(0.976, 0.443, 0.101);
			glTranslatef(-0.5,0,0);
			glRotatef(-45,0,1,0);
			glScalef(0.1,1,1);
			glutSolidSphere(0.1,32,32);
			
			glTranslatef(0,0,0.01);
			glColor3f(0,0,0);
			glScalef(0.5,1,1);
			glutSolidSphere(0.1,32,32);
		}
		glPopMatrix();
		
		glPushMatrix(); // nageoire d
		{
			glColor3f(0.976, 0.443, 0.101);
			glTranslatef(0.5,0,0);
			glRotatef(45,0,1,0);
			glScalef(0.1,1,1);
			glutSolidSphere(0.1,32,32);
			
			glTranslatef(0,0,0.01);
			glColor3f(0,0,0);
			glScalef(0.5,1,1);
			glutSolidSphere(0.1,32,32);
		}
		glPopMatrix();
		
		glPushMatrix(); // blanc 1
		{
			glColor3f(1,1,1);
			glTranslatef(0,0,-0.3);
			gluCylinder(obj,0.4,0.47,0.1,32,32);
		}
		glPopMatrix();
		glPushMatrix(); // blanc 2
		{
			glColor3f(1,1,1);
			glTranslatef(0,0,0.2);
			gluCylinder(obj,0.47,0.4,0.1,32,32);
		}
		glPopMatrix();
		
		glScalef(1,1,0.5);
		
		glPushMatrix(); // queue
		{
			glTranslatef(0,0,0.5);
			glColor3f(0.976, 0.443, 0.101);
			gluCylinder(obj,0.45,0.2,0.5,32,32);
			
			glTranslatef(0,0,0.5);
			glColor3f(1,1,1);
			gluCylinder(obj,0.2,0.1,0.2,32,32);
			
			glTranslatef(0,0,0.18);
			glutSolidSphere(0.1,32,32);
			
			glTranslatef(0,0,0.1);
			glColor3f(0.976, 0.443, 0.101);
			glScalef(0.2,1.3,1);
			glutSolidSphere(0.2,32,32);
			
			glTranslatef(0,0,0.01);
			glColor3f(0,0,0);
			glScalef(0.5,1,1);
			glutSolidSphere(0.2,32,32);
			
		}
		glPopMatrix();
	}
	glPopMatrix();
	
	glPushMatrix(); // Poisson : Zancle
	{
		GLUquadricObj *obj = gluNewQuadric();
		glScalef(0.3,1,1);
		
		glColor3f(0,0,0);
		gluDisk(obj,0.01,0.05,32,32);
		gluCylinder(obj,0.05,0.1,0.2,32,32);
		
		glTranslatef(0,0,0.2);
		glColor3f(0.925, 0.921, 0.611);
		gluCylinder(obj,0.1,0.2,0.1,32,32);
		
		glTranslatef(0,0,0.1);
		glColor3f(0,0,0);
		gluCylinder(obj,0.2,0.5,0.2,32,32);
		glPushMatrix(); // yeux
		{
			glColor3f(1,1,1);
			glTranslatef(0.3,0.2,0.1);
			glutSolidSphere(0.05,32,32);
			
			glTranslatef(-0.6,0,0);
			glutSolidSphere(0.05,32,32);
		}
		glPopMatrix();
		
		glTranslatef(0,0,0.2);
		glColor3f(0.925, 0.921, 0.611);
		gluCylinder(obj,0.5,0.51,0.3,32,32);
		
		
		glTranslatef(0,0,0.3);
		glColor3f(0,0,0);
		gluCylinder(obj,0.51,0.3,0.2,32,32);
		
		glTranslatef(0,0,0.2);
		glColor3f(0.925, 0.921, 0.611);
		gluCylinder(obj,0.3,0.1,0.1,32,32);
		
		glTranslatef(0,0,0.1);
		glColor3f(0,0,0);
		gluCylinder(obj,0.1,0.3,0.2,32,32);
		
		glScalef(0.5,1,1);
		glTranslatef(0,0,0.2);
		gluDisk(obj,0,0.3,32,32);
	}
	glPopMatrix();
