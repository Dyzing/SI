glPushMatrix(); //LINK
{
	glPushMatrix(); //tete
	{
		glScalef(1.3,1.2,1);
		glColor3f(0.890, 0.823, 0.572);
		glutSolidSphere(2.9,50,50);

		glPushMatrix(); //cou
		{
			glTranslatef(0,-2.5,0);
			glRotatef(90,1,0,0);
			glColor3f(0.890, 0.823, 0.572);
			GLUquadricObj *obj = gluNewQuadric();
			
			//~ gluCylinder(obj,0.8,1,1,32,32);
			
			//~ glTranslatef(0,0,0.5);
			gluCylinder(obj,0.7,1.3,1,32,32);
		}
		glPopMatrix();
		
		
		glPushMatrix(); //cheveux
		{
			glTranslatef(0,1,0);
			glScalef(1,1,0.8);
			glColor3f(0.98,0.93,0.13);
			glutSolidSphere(3,10,10);
			glEnd();



			glPushMatrix(); //meche gauche grosse
			{
				glTranslatef(-1,1.9,0);
				glScalef(2.5,1,1);
				glColor3f(0.98,0.93,0.13);
				glutSolidSphere(1,8,8);
				glEnd();
			}
			glPopMatrix();



			glPushMatrix(); //meche milieu grosse
			{
				glTranslatef(0,1,2.5);
				glRotatef(30,0,0,1);
				glRotatef(10,0,1,0);
				glScalef(2,1,1);
				glColor3f(0.98,0.93,0.13);
				glutSolidSphere(1,8,8);
				glEnd();
			}
			glPopMatrix();




			glPushMatrix(); //rouflaquette gauche
			{
				glTranslatef(-2.8,-0.6,0.3);
				glRotatef(-30, 1,0,0);
				glScalef(0.5,2.5,1);
				glColor3f(0.98,0.93,0.13);
				glutSolidSphere(0.75,7,7);
				glEnd();
			}
			glPopMatrix();



			glPushMatrix(); //rouflaquette droite
			{
				glTranslatef(2.8,-0.6,0.3);
				glRotatef(-30, 1,0,0);
				glScalef(0.5,2.5,1);
				glColor3f(0.98,0.93,0.13);
				glutSolidSphere(0.75,7,7);
				glEnd();
			}
			glPopMatrix();




		}
		glPopMatrix();



		glPushMatrix(); //oeil gauche
		{
			glTranslatef(-1,0,2.7);
			glRotatef(-5,0,0,1);		

			glPushMatrix(); //pupille gauche
			{
				glTranslatef(0,0,0.2);
				glScalef(0.8,1,0.2);
				glColor3f(0,0,0);
				glutSolidSphere(0.45, 20, 20);	
				glEnd();	
			}
			glPopMatrix();


			glPushMatrix(); //sourcil gauche
			{
					glTranslatef(0,1,-0.1);
					glScalef(0.8,0.1,0.5);
					glRotatef(-20,0,1,0);
					glColor3f(0,0,0);
					glBegin( GL_TRIANGLES ); 
						glVertex3f( 0.0f, 1.f, 0.0f );
						glVertex3f( -1.0f, -1.0f, 1.0f );
						glVertex3f( 1.0f, -1.0f, 1.0f);

						glVertex3f( 0.0f, 1.0f, 0.0f);
						glVertex3f( -1.0f, -1.0f, 1.0f);
						glVertex3f( 0.0f, -1.0f, -1.0f);

						glVertex3f( 0.0f, 1.0f, 0.0f);
						glVertex3f( 0.0f, -1.0f, -1.0f);
						glVertex3f( 1.0f, -1.0f, 1.0f);

						glVertex3f( -1.0f, -1.0f, 1.0f);
						glVertex3f( 0.0f, -1.0f, -1.0f);
						glVertex3f( 1.0f, -1.0f, 1.0f);
						glEnd();
					glEnd();
			}
			glPopMatrix();
			
			glPushMatrix(); // cil gauche
			{
				glRotatef(-8.9,0,1,0);
				glTranslatef(-0.09,0,0.06);
				glScalef(1.75,1.1,0.05);
				glColor3f(0,0,0);
				glutSolidSphere(0.5, 20, 20);	
			}
			glPopMatrix();

			glScalef(2,1,0.5);
			glColor3f(1,1,1);
			glutSolidSphere(0.5, 20, 20);	
			glEnd();

		}
		glPopMatrix();



		glPushMatrix(); //oeil droit
		{
			glTranslatef(1,0,2.7);
			glRotatef(5,0,0,1);

			glPushMatrix(); //pupille droit
			{
				glTranslatef(0,0,0.2);
				glScalef(0.8,1,0.2);
				glColor3f(0,0,0);
				glutSolidSphere(0.45, 20, 20);		
				glEnd();
			}
			glPopMatrix();

			glPushMatrix(); //sourcil droite
			{
					glTranslatef(0,1,-0.1);
					glScalef(0.8,0.1,0.5);
					glRotatef(20,0,1,0);
					glColor3f(0,0,0);
					glBegin( GL_TRIANGLES ); 
						glVertex3f( 0.0f, 1.f, 0.0f );
						glVertex3f( -1.0f, -1.0f, 1.0f);
						glVertex3f( 1.0f, -1.0f, 1.0f);

						glVertex3f( 0.0f, 1.0f, 0.0f);
						glVertex3f( -1.0f, -1.0f, 1.0f);
						glVertex3f( 0.0f, -1.0f, -1.0f);

						glVertex3f( 0.0f, 1.0f, 0.0f);
						glVertex3f( 0.0f, -1.0f, -1.0f);
						glVertex3f( 1.0f, -1.0f, 1.0f);

						glVertex3f( -1.0f, -1.0f, 1.0f);
						glVertex3f( 0.0f, -1.0f, -1.0f);
						glVertex3f( 1.0f, -1.0f, 1.0f);
						glEnd();
					glEnd();
			}
			glPopMatrix();
			
			glPushMatrix(); // cil droit
			{
				glRotatef(8.9,0,1,0);
				glTranslatef(0.09,0,0.06);
				glScalef(1.75,1.1,0.05);
				glColor3f(0,0,0);
				glutSolidSphere(0.5, 20, 20);	
			}
			glPopMatrix();

			glScalef(2,1,0.5);
			glColor3f(1,1,1);
			glutSolidSphere(0.5, 20, 20);	
			glEnd();

		}
		glPopMatrix();


		glPushMatrix(); // nez
		{
			glTranslatef(0.1,-0.8,2.6);
			glScalef(0.3,0.5,0.5);
			glRotatef(-60,0,1,0);
			glColor3f(0,0,0);
			glBegin( GL_TRIANGLES );

				glVertex3f( 0.0f, 1.0f, 0.0f);
				glVertex3f( 0.0f, -1.0f, -1.0f);
				glVertex3f( 1.0f, -1.0f, 1.0f);

				glVertex3f( -1.0f, -1.0f, 1.0f);
				glVertex3f( 0.0f, -1.0f, -1.0f);
				glVertex3f( 1.0f, -1.0f, 1.0f);
				glEnd();
			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //bouche
		{
			glTranslatef(0,-2,2.2);

			glScalef(0.6,0.4,0.3);
			glColor3f(0.97,0.33,0.33);
			glutSolidCube(1.0);

			glPushMatrix(); //dent
			{
				glTranslatef(0,0.35,0.7);
				glScalef(0.7,0.3,0.05);
				glColor3f(1,1,1);

				glutSolidCube(1.0);
			}
			glPopMatrix();

			glEnd();
		}
		glPopMatrix();


		glPushMatrix(); //oreille gauche
		{
			glTranslatef(-3,0,0);
			glRotatef(220,0,1,0);
			glRotatef(45,1,0,0);
			glScalef(1,2.5,1);
			glColor3f(0.890, 0.823, 0.572);
			glutSolidSphere(0.5,5,5);
			glEnd();
		}
		glPopMatrix();



		glPushMatrix(); //oreille droite
		{
			glTranslatef(3,0,0);
			glRotatef(-220,0,1,0);
			glRotatef(45,1,0,0);
			glScalef(1,2.5,1);
			glColor3f(0.890, 0.823, 0.572);
			glutSolidSphere(0.5,5,5);
			glEnd();
		}
		glPopMatrix();

		glPushMatrix(); //bonnet
		{
			GLUquadricObj *obj = gluNewQuadric();
			glColor3f(0.121, 0.427, 0.050);
			glTranslatef(0,1.8,-3);
			glScalef(0.9,1,1);
			glRotatef(20,1,0,0);
			gluCylinder(obj,2,3,2,32,32);
			
			glRotatef(-20,1,0,0);
			glTranslatef(0,-0.45,-0.2);
			gluCylinder(obj,2,2.35,1,32,32);
			
			glTranslatef(0,0,0.6);
			glutSolidSphere(2.1,10,10);
			
			glTranslatef(0,-1.5,-1.6);
			glRotatef(-50,1,0,0);
			gluCylinder(obj,1,1.5,1,32,32);
			
			glRotatef(-16,1,0,0);
			glTranslatef(0,0,-2.5);
			gluCylinder(obj,0.5,1,3,32,32);
			
			glRotatef(-16,1,0,0);
			glTranslatef(0,-0.1,-1.4);
			gluCylinder(obj,0,0.5,1.5,32,32);
		}
		glPopMatrix();

		glEnd();
	}
	glPopMatrix();	
	
	glTranslatef(0,-7.66,0);
	
	glPushMatrix(); //corps
	{			
		GLUquadricObj *obj = gluNewQuadric();
		
		glPushMatrix(); //buste
		{
		glColor3f(0.121, 0.427, 0.050);
		
		glScalef(0.6,0.9,0.4);
		glutSolidSphere(5,32,32);
		
		glTranslatef(0,-2,0);
		glRotatef(90,1,0,0);
		gluCylinder(obj,4.2,4.8,4,32,32);
		
		glTranslatef(0,0,0.3); // ceinture
			glColor3f(0.537,0.207,0.121);
			gluCylinder(obj,4.48,4.4,1.5,32,32);
			
			glPushMatrix(); // bouton
				glColor3f(0.98,0.93,0.13);
				glTranslatef(0,4.7,0.5);
				glScalef(1.5,0.3,1);
				glutSolidSphere(1,32,32);
			glPopMatrix();
		}
		glPopMatrix();
		
		glPushMatrix(); // épaules
		{
			glColor3f(0.545, 0.905, 0.152);
			
			glPushMatrix(); // droite
				glScalef(0.7,0.9,0.5);
				glTranslatef(-3,2,0);
				glutSolidSphere(2,32,32);
			glPopMatrix();
			
			glPushMatrix(); // gauche
				glScalef(0.7,0.9,0.5);
				glTranslatef(3,2,0);
				glutSolidSphere(2,32,32);
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();	
	
	glPushMatrix(); // jambes
	{
		GLUquadricObj *obj = gluNewQuadric();
		glColor3f(0.9,0.9,0.9);
		glTranslatef(0,-6,0);
		
		glPushMatrix(); // droite
		{
			glTranslatef(-1.5,0,0);
			glRotatef(75,1,0,0);
			glRotatef(15,0,-1,1);
			
			
			glPushMatrix(); //hanche + cuisse
				glutSolidSphere(1,32,32);
				gluCylinder(obj,1,1,2.5,32,32);
			glPopMatrix();
			
			glTranslatef(0,0,2.7);
				
			glPushMatrix(); // genoux
				glutSolidSphere(1,32,32);
			glPopMatrix();
			
			glTranslatef(0,0,0.2);
			glRotatef(15,1,0,0);
			
			glPushMatrix(); // jambe
				gluCylinder(obj,1,1,1.5,32,32);
			glPopMatrix();
			
			glTranslatef(0,0,1);
			glColor3f(0.537,0.207,0.121);
			glRotatef(-10,0,0,1);
			glRotatef(5,0,1,0);
			
			glPushMatrix(); // pied
				gluCylinder(obj,1.1,1.1,2,32,32);
				glTranslatef(0,0.5,2);
				glRotatef(-90,1,0,0);
				
				glScalef(0.8,0.3,1.2);
				glutSolidSphere(1.5,32,32);
			glPopMatrix();
		}
		glPopMatrix();
		
		glColor3f(0.9,0.9,0.9);
		
		glPushMatrix(); // gauche
		{
			glTranslatef(1.5,0,0);
			glRotatef(93,1,0,0);
			glRotatef(-15,0,-1,1);
			
			glPushMatrix(); //hanche + cuisse
				glutSolidSphere(1,32,32);
				gluCylinder(obj,1,1,2.5,32,32);
			glPopMatrix();
			
			glTranslatef(0,0,2.7);
				
			glPushMatrix(); // genoux
				glutSolidSphere(1,32,32);
			glPopMatrix();
			
			glTranslatef(0,0,0.2);
			glRotatef(15,1,0,0);
			
			glPushMatrix(); // jambe
				gluCylinder(obj,1,1,1.5,32,32);
			glPopMatrix();
			
			glTranslatef(0,0,1);
			glColor3f(0.537,0.207,0.121);
			glRotatef(-15,1,1,0);
			
			
			//~ glScalef(2,2,2);
				//~ axes();
			//~ glScalef(.5,.5,.5);
			
			glPushMatrix(); // pied
				gluCylinder(obj,1.1,1.1,2,32,32);
				glTranslatef(0,0.5,2);
				glRotatef(-90,1,0,0);
				
				glScalef(0.8,0.2,1.2);
				glutSolidSphere(1.5,32,32);
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
	
	glPushMatrix(); // bras
	{
		GLUquadricObj *obj = gluNewQuadric();
		glColor3f(0.545, 0.905, 0.152);
		glTranslatef(0,2.5,0);
		
		glPushMatrix(); // droit
		{
			glTranslatef(-3,-0.5,0); // épaule
			glutSolidSphere(0.9,32,32);
			
			glRotatef(-110,0,1,0); // bras
			glRotatef(55,1,0,0);
			gluCylinder(obj,0.9,0.8,4,32,32);
			
			glTranslatef(0,0,4); // coude
			glutSolidSphere(0.8,32,32);
			
			glRotatef(45,0,1,0); // avant-bras
			glRotatef(33,1,0,0);
			gluCylinder(obj,0.8,0.7,4,32,32);
			
			glColor3f(0.890, 0.823, 0.572); // main
			glRotatef(-110,0,0,1);
			glTranslatef(0,0,4.1);
			glutSolidSphere(0.8,32,32);
			
			glPushMatrix(); // bouclier
			{
				glColor3f(.7,.7,.7); // poignée 1
				glRotatef(30,0,1,0);
				glPushMatrix();
					glScalef(1,6,1);
					glutSolidCube(0.5);
				glPopMatrix();

				glTranslatef(-0.5,1.75,0); // poignée 2
				glRotatef(90,0,0,1);
				glPushMatrix();
					glScalef(1,3,1);
					glutSolidCube(0.5);
				glPopMatrix();
				
				glRotatef(-90,1,0,0); // carapace
				glRotatef(-90,0,0,1);
				glTranslatef(0,0,1);
				glColor3f(0.494, 0.250, 0.164);
				{
					glPushMatrix(); // partie Gauche
					{
						glTranslatef(0.325,0,0);
						glRotatef(10,0,1,0);
						
						glPushMatrix(); // 1G
							glScalef(3,20,2);
							glutSolidCube(0.25);
						glPopMatrix();
						
						glPushMatrix(); // 1G partie basse
						{
							glTranslatef(0,-2.5,0);
							glBegin( GL_TRIANGLES );
							//devant
								glVertex3f( 0.375f, 0.0f, 0.25f);
								glVertex3f( 0.375f, -1.5f, 0.25f);
								glVertex3f( -0.375f, -2.0f, 0.25f);
								
								glVertex3f( -0.375f, 0.0f, 0.25f);
								glVertex3f( 0.375f, 0.0f, 0.25f);
								glVertex3f( -0.375f, -2.0f, 0.25f);
							//derrière
								glVertex3f( 0.375f, 0.0f, -0.25f);
								glVertex3f( 0.375f, -1.5f, -0.25f);
								glVertex3f( -0.375f, -2.0f, -0.25f);
								
								glVertex3f( -0.375f, 0.0f, -0.25f);
								glVertex3f( 0.375f, 0.0f, -0.25f);
								glVertex3f( -0.375f, -2.0f, -0.25f);
							//dessous1
								glVertex3f( 0.375f, -1.5f, 0.25f);
								glVertex3f( 0.375f, -1.5f, -0.25f);
								glVertex3f( -0.375f, -2.0f, -0.25f);
							//dessous2
								glVertex3f( 0.375f, -1.5f, 0.25f);
								glVertex3f( -0.375f, -2.0f, -0.25f);
								glVertex3f( -0.375f, -2.0f, 0.25f);
							glEnd();
						}
						glPopMatrix();
						
						glTranslatef(1.2,0,-0.17);
						glRotatef(10,0,1,0);
						
						glPushMatrix(); // 2G
							glScalef(7,20,2);
							glutSolidCube(0.25);
						glPopMatrix();
						
						glPushMatrix(); // 2G partie basse
						{
							glTranslatef(0,-2.5,0);
							glBegin( GL_TRIANGLES );
							//devant
								glVertex3f(-0.875f, 0.0f, 0.25f);
								glVertex3f( 0.875f, 0.0f, 0.25f);
								glVertex3f(-0.875f,-1.5f, 0.25f);
							//derrière
								glVertex3f(-0.875f, 0.0f, -0.25f);
								glVertex3f( 0.875f, 0.0f, -0.25f);
								glVertex3f(-0.875f,-1.5f, -0.25f);
							//dessous1
								glVertex3f( 0.875f, 0.0f, 0.25f);
								glVertex3f(-0.875f,-1.5f, 0.25f);
								glVertex3f(-0.875f,-1.5f,-0.25f);
							//dessous2
								glVertex3f( 0.875f, 0.0f, 0.25f);
								glVertex3f( 0.875f, 0.0f,-0.25f);
								glVertex3f(-0.875f,-1.5f,-0.25f);
							glEnd();
						}
						glPopMatrix();
					}
					glPopMatrix();
					
					glPushMatrix(); // partie Droite
					{
						glTranslatef(-0.325,0,0);
						glRotatef(-10,0,1,0);
						
						glPushMatrix(); // 1D
							glScalef(3,20,2);
							glutSolidCube(0.25);
						glPopMatrix();
						
						glPushMatrix(); // 1D partie basse
						{
							glTranslatef(0,-2.5,0);
							glBegin( GL_TRIANGLES );
							//devant
								glVertex3f(-0.375f, 0.0f, 0.25f);
								glVertex3f(-0.375f,-1.5f, 0.25f);
								glVertex3f( 0.375f,-2.0f, 0.25f);
								
								glVertex3f( 0.375f, 0.0f, 0.25f);
								glVertex3f(-0.375f, 0.0f, 0.25f);
								glVertex3f( 0.375f,-2.0f, 0.25f);
							//derrière
								glVertex3f(-0.375f, 0.0f, -0.25f);
								glVertex3f(-0.375f,-1.5f, -0.25f);
								glVertex3f( 0.375f,-2.0f, -0.25f);
								
								glVertex3f( 0.375f, 0.0f, -0.25f);
								glVertex3f(-0.375f, 0.0f, -0.25f);
								glVertex3f( 0.375f,-2.0f, -0.25f);
							//dessous1
								glVertex3f(-0.375f, -1.5f, 0.25f);
								glVertex3f(-0.375f, -1.5f,-0.25f);
								glVertex3f( 0.375f, -2.0f,-0.25f);
							//dessous2
								glVertex3f(-0.375f, -1.5f, 0.25f);
								glVertex3f( 0.375f, -2.0f,-0.25f);
								glVertex3f( 0.375f, -2.0f, 0.25f);
							
							glEnd();
						}
						glPopMatrix();
						
						glTranslatef(-1.2,0,-0.17);
						glRotatef(-10,0,1,0);
						
						glPushMatrix(); // 2D
							glScalef(7,20,2);
							glutSolidCube(0.25);
						glPopMatrix();
						
						glPushMatrix(); // 2D partie basse
						{
							glTranslatef(0,-2.5,0);
							glBegin( GL_TRIANGLES );
							//devant
								glVertex3f( 0.875f, 0.0f, 0.25f);
								glVertex3f(-0.875f, 0.0f, 0.25f);
								glVertex3f( 0.875f,-1.5f, 0.25f);
							//derrière
								glVertex3f( 0.875f, 0.0f, -0.25f);
								glVertex3f(-0.875f, 0.0f, -0.25f);
								glVertex3f( 0.875f,-1.5f, -0.25f);
							//dessous1
								glVertex3f(-0.875f, 0.0f, 0.25f);
								glVertex3f( 0.875f,-1.5f, 0.25f);
								glVertex3f( 0.875f,-1.5f,-0.25f);
							//dessous2
								glVertex3f(-0.875f, 0.0f, 0.25f);
								glVertex3f(-0.875f, 0.0f,-0.25f);
								glVertex3f( 0.875f,-1.5f,-0.25f);
							glEnd();
						}
						glPopMatrix();
					}
					glPopMatrix();
				}
			}
			glPopMatrix();
			
			
		}
		glPopMatrix();
		
		glColor3f(0.545, 0.905, 0.152);
		glPushMatrix(); // gauche
		{
			glTranslatef(3,-0.5,0); // épaule
			glutSolidSphere(.9,32,32);
			
			glRotatef(90,0,1,0); // bras
			glRotatef(50,1,0,0);
			gluCylinder(obj,1,.8,4,32,32);
			
			glTranslatef(0,0,4); // coude
			glutSolidSphere(0.8,32,32);
			
			glRotatef(-15,0,1,0); // avant-bras
			gluCylinder(obj,0.8,0.7,4,32,32);
			
			glColor3f(0.890, 0.823, 0.572); // main
			glRotatef(110,0,0,1);
			glTranslatef(0,0,4.1);
			glutSolidSphere(0.8,32,32);
			
			glRotatef(-33,0,0,1);
			glRotatef( 95,1,0,0);
			
			glPushMatrix(); // épée
			{
				glPushMatrix(); // pommeau
				{
					glColor3f(0.211, 0.168, 0.631);
					glTranslatef(0,0,-1.5);
					
					gluCylinder(obj,0.4,0.4,3,32,32);
					
					glTranslatef(0,0,2);
					
					gluCylinder(obj,0.4,0.6,2,32,32);
					glTranslatef(0,0,2);
					gluDisk(obj,0,0.6,32,32);
				}
				glPopMatrix();
				
				glTranslatef(0,0,-1.5);
				glRotatef(-180,1,0,0);
				
				glPushMatrix(); // garde
				{
					gluCylinder(obj,0.4,0.7,0.1,32,32);
					glTranslatef(0,0,0.1);
					gluCylinder(obj,0.7,0.5,0.3,32,32);
					glTranslatef(0,0,0.3);
					gluCylinder(obj,0.5,0.5,0.4,32,32);
					
					glPushMatrix(); // partie droite
					{
						glTranslatef(0,0.65,0.2);
						glRotatef(-10,1,0,0);
						
						glPushMatrix();
							glScalef(0.7,2,0.7);
							glutSolidCube(0.5);
						glPopMatrix();
						
						glPushMatrix();
							glTranslatef(0,0,0.25);
							glRotatef(-30,1,0,0);
							glTranslatef(0,0.32,0.2);
							glScalef(0.7,0.7,1.5);
							glRotatef(30,1,0,0);
							glutSolidCube(0.5);
						glPopMatrix();
					}
					glPopMatrix();
					
					glPushMatrix(); // partie gauche
					{
						glTranslatef(0,-0.65,0.2);
						glRotatef(10,1,0,0);
						
						glPushMatrix();
							glScalef(0.7,2,0.7);
							glutSolidCube(0.5);
						glPopMatrix();
						
						glPushMatrix();
							glTranslatef(0,0,0.25);
							glRotatef(30,1,0,0);
							glTranslatef(0,-0.32,0.2);
							glScalef(0.7,0.7,1.5);
							glRotatef(-30,1,0,0);
							glutSolidCube(0.5);
						glPopMatrix();
					}
					glPopMatrix();
					
					glTranslatef(0,0,0.4);
					gluCylinder(obj,0.5,0.7,0.4,32,32);
					glTranslatef(0,0,0.4);
					gluDisk(obj,0,0.7,32,32);
					
					glPushMatrix(); // porte-joyau
						glScalef(0.6,1,2);
						glutSolidSphere(0.5,32,32);
					glPopMatrix();
					
					glPushMatrix(); // joyau
						glColor3f(1,1,0);
						glScalef(0.8,0.5,1.5);
						glutSolidSphere(0.5,32,32);
					glPopMatrix();
				}
				glPopMatrix();
					
				glPushMatrix(); // lame
				{
					glTranslatef(0,0,1.2); // base
					glColor3f(.99,.99,.99);
					glScalef(0.2,0.6,1);
					gluCylinder(obj,0.7,0.7,2,32,32);
					
					glTranslatef(0,0,2); // base vers lame
					gluCylinder(obj,0.7,0.9,0.2,32,32);
					
					glTranslatef(0,0,0.2); // lame
					gluCylinder(obj,0.9,0.9,4,32,32);
					
					glTranslatef(0,0,4); // pointe
					gluCylinder(obj,0.9,0.7,0.3,32,32);
					glTranslatef(0,0,0.3);
					gluCylinder(obj,0.7,0.5,0.3,32,32);
					glTranslatef(0,0,0.3);
					gluCylinder(obj,0.5,0.3,0.3,32,32);
					glTranslatef(0,0,0.3);
					gluCylinder(obj,0.3,0,0.3,32,32);
					axes();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();
	}
	glPopMatrix();
}
glPopMatrix();
