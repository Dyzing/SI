//**************** touches.h ****************
#define TOUCHE_0 48
#define TOUCHE_1 49
#define TOUCHE_2 50
#define TOUCHE_3 51
#define TOUCHE_4 52
#define TOUCHE_5 53
#define TOUCHE_6 54
#define TOUCHE_7 55
#define TOUCHE_8 56
#define TOUCHE_9 57

//**************** main.c ****************

// Déclarations Tic-Tac-Toe
int victoire = 0;
int ttt_tour = 0;

int ttt_0 = 0;
int ttt_1 = 0;
int ttt_1_color = 0;
int ttt_2 = 0;
int ttt_2_color = 0;
int ttt_3 = 0;
int ttt_3_color = 0;
int ttt_4 = 0;
int ttt_4_color = 0;
int ttt_5 = 0;
int ttt_5_color = 0;
int ttt_6 = 0;
int ttt_6_color = 0;
int ttt_7 = 0;
int ttt_7_color = 0;
int ttt_8 = 0;
int ttt_8_color = 0;
int ttt_9 = 0;
int ttt_9_color = 0;

void tout_a_zero(){
	victoire = 0;
	ttt_tour = 0;
	ttt_0 = 0;
	
	ttt_1 = 0;	ttt_1_color = 0;
	ttt_2 = 0;	ttt_2_color = 0;
	ttt_3 = 0;	ttt_3_color = 0;
	ttt_4 = 0;	ttt_4_color = 0;
	ttt_5 = 0;	ttt_5_color = 0;
	ttt_6 = 0;	ttt_6_color = 0;
	ttt_7 = 0;	ttt_7_color = 0;
	ttt_8 = 0;	ttt_8_color = 0;
	ttt_9 = 0;	ttt_9_color = 0;
}

// DANS LE 'GLvoid Modelisation()'
glPushMatrix(); // Tic-Tac-Toe
{
	glPushMatrix(); // création cadre
	{
		glTranslatef(-0.5,0.5,0); // vers x
		for(int i = 0; i<10; i++){
			glTranslatef(1,0,0);
			glutSolidCube(1);
			if(i==3 || i==6){
				glPushMatrix();
					for(int j = 0; j<9; j++){
							glTranslatef(0,1,0);
							glutSolidCube(1);
					}
				glPopMatrix();
			}
		}
		
		glTranslatef(0,-1,0); // vers y
		for(int i = 0; i<10; i++){
			glTranslatef(0,1,0);
			glutSolidCube(1);
			if(i==3 || i==6){
				glPushMatrix();
					for(int j = 0; j<9; j++){
							glTranslatef(-1,0,0);
							glutSolidCube(1);
					}
				glPopMatrix();
			}
		}
		
		glTranslatef(1,0,0); // vers -x
		for(int i = 0; i<10; i++){
			glTranslatef(-1,0,0);
			glutSolidCube(1);
		}
		
		glTranslatef(0,1,0); // vers -y
		for(int i = 0; i<10; i++){
			glTranslatef(0,-1,0);
			glutSolidCube(1);
		}
	}
	glPopMatrix(); // fin cadre
	
	// Jeu
	{
		if (ttt_0 == 1) tout_a_zero();
		
		// Victoire		
		int gagne(){
		// lignes
			if((ttt_1 + ttt_2 + ttt_3 == 3) && (ttt_1_color == ttt_2_color) && (ttt_1_color == ttt_3_color)){
				if (ttt_tour%2 != 0){ 
					victoire = 1;
					ttt_1_color = ttt_2_color = ttt_3_color = 3;
				}
				if (ttt_tour%2 == 0){
					victoire = 2;
					ttt_1_color = ttt_2_color = ttt_3_color = 4;
				 }
				return victoire;
			}
			if((ttt_4 + ttt_5 + ttt_6 == 3) && (ttt_4_color == ttt_5_color) && (ttt_4_color == ttt_6_color)){
				if (ttt_tour%2 != 0){ 
					victoire = 1;
					ttt_4_color = ttt_5_color = ttt_6_color = 3;
				}
				if (ttt_tour%2 == 0){
					victoire = 2;
					ttt_4_color = ttt_5_color = ttt_6_color = 4;
				 }
				return victoire;
			}
			if((ttt_7 + ttt_8 + ttt_9 == 3) && (ttt_7_color == ttt_8_color) && (ttt_7_color == ttt_9_color)){
				if (ttt_tour%2 != 0){ 
					victoire = 1;
					ttt_7_color = ttt_8_color = ttt_9_color = 3;
				}
				if (ttt_tour%2 == 0){
					victoire = 2;
					ttt_7_color = ttt_8_color = ttt_9_color = 4;
				 }
				return victoire;
			}
			if((ttt_1 + ttt_4 + ttt_7 == 3) && (ttt_1_color == ttt_4_color) && (ttt_1_color == ttt_7_color)){
				if (ttt_tour%2 != 0){ 
					victoire = 1;
					ttt_1_color = ttt_4_color = ttt_7_color = 3;
				}
				if (ttt_tour%2 == 0){
					victoire = 2;
					ttt_1_color = ttt_4_color = ttt_7_color = 4;
				 }
				return victoire;
			}
			if((ttt_2 + ttt_5 + ttt_8 == 3) && (ttt_2_color == ttt_5_color) && (ttt_2_color == ttt_8_color)){
				if (ttt_tour%2 != 0){ 
					victoire = 1;
					ttt_2_color = ttt_5_color = ttt_8_color = 3;
				}
				if (ttt_tour%2 == 0){
					victoire = 2;
					ttt_2_color = ttt_5_color = ttt_8_color = 4;
				 }
				return victoire;
			}
			if((ttt_3 + ttt_6 + ttt_9 == 3) && (ttt_3_color == ttt_6_color) && (ttt_3_color == ttt_9_color)){
				if (ttt_tour%2 != 0){ 
					victoire = 1;
					ttt_3_color = ttt_6_color = ttt_9_color = 3;
				}
				if (ttt_tour%2 == 0){
					victoire = 2;
					ttt_3_color = ttt_6_color = ttt_9_color = 4;
				 }
				return victoire;
			}
		// diagonales
			if((ttt_3 + ttt_5 + ttt_7 == 3) && (ttt_3_color == ttt_5_color) && (ttt_3_color == ttt_7_color)){
				if (ttt_tour%2 != 0){ 
					victoire = 1;
					ttt_3_color = ttt_5_color = ttt_7_color = 3;
				}
				if (ttt_tour%2 == 0){
					victoire = 2;
					ttt_3_color = ttt_5_color = ttt_7_color = 4;
				 }
				return victoire;
			}
			if((ttt_1 + ttt_5 + ttt_9 == 3) && (ttt_1_color == ttt_5_color) && (ttt_1_color == ttt_9_color)){
				if (ttt_tour%2 != 0){ 
					victoire = 1;
					ttt_1_color = ttt_5_color = ttt_9_color = 3;
				}
				if (ttt_tour%2 == 0){
					victoire = 2;
					ttt_1_color = ttt_5_color = ttt_9_color = 4;
				 }
				return victoire;
			}
			return 0;
		}
		gagne();
		// fin Victoire
		
		//IA
		if(victoire == 0){
			int combien_cases_libres(){ // calcul du nombre de cases libres
				int resultat = 0;
				if (ttt_1 == 0) resultat += 1;
				if (ttt_2 == 0) resultat += 1;
				if (ttt_3 == 0) resultat += 1;
				if (ttt_4 == 0) resultat += 1;
				if (ttt_5 == 0) resultat += 1;
				if (ttt_6 == 0) resultat += 1;
				if (ttt_7 == 0) resultat += 1;
				if (ttt_8 == 0) resultat += 1;
				if (ttt_9 == 0) resultat += 1;
				return resultat;
			}
			if((ttt_tour%2 != 0) && (combien_cases_libres() > 0)){ // test tour et si il reste une case libre
		// *** qu'a-t-il été joué ? ***
				int cases_libres[combien_cases_libres()];
				//initialisation
				for(int i=0; i < combien_cases_libres(); i++) cases_libres[i] = 0;
				//remplissage
				for(int i=0; i < combien_cases_libres(); i++){
					if 		((ttt_1 == 0) && cases_libres[i-1] < 1) cases_libres[i] = 1;
					else if ((ttt_2 == 0) && cases_libres[i-1] < 2) cases_libres[i] = 2;
					else if ((ttt_3 == 0) && cases_libres[i-1] < 3) cases_libres[i] = 3;
					else if ((ttt_4 == 0) && cases_libres[i-1] < 4) cases_libres[i] = 4;
					else if ((ttt_5 == 0) && cases_libres[i-1] < 5) cases_libres[i] = 5;
					else if ((ttt_6 == 0) && cases_libres[i-1] < 6) cases_libres[i] = 6;
					else if ((ttt_7 == 0) && cases_libres[i-1] < 7) cases_libres[i] = 7;
					else if ((ttt_8 == 0) && cases_libres[i-1] < 8) cases_libres[i] = 8;
					else if ((ttt_9 == 0) && cases_libres[i-1] < 9) cases_libres[i] = 9;
				}
				
		// *** choix d'une case ***
				int rand_a_b(int a, int b){
					return ( rand()/(double)RAND_MAX ) * (b-a) + a;
				}
				int random = rand_a_b(0,combien_cases_libres());
				int choix =  cases_libres[random];
				if (choix == 1){
					ttt_1 = 1;
					ttt_1_color = 2;
					ttt_tour += 1;
				}
				if (choix == 2){
					ttt_2 = 1;
					ttt_2_color = 2;
					ttt_tour += 1;
				}
				if (choix == 3){
					ttt_3 = 1;
					ttt_3_color = 2;
					ttt_tour += 1;
				}
				if (choix == 4){
					ttt_4 = 1;
					ttt_4_color = 2;
					ttt_tour += 1;
				}
				if (choix == 5){
					ttt_5 = 1;
					ttt_5_color = 2;
					ttt_tour += 1;
				}
				if (choix == 6){
					ttt_6 = 1;
					ttt_6_color = 2;
					ttt_tour += 1;
				}
				if (choix == 7){
					ttt_7 = 1;
					ttt_7_color = 2;
					ttt_tour += 1;
				}
				if (choix == 8){
					ttt_8 = 1;
					ttt_8_color = 2;
					ttt_tour += 1;
				}
				if (choix == 9){
					ttt_9 = 1;
					ttt_9_color = 2;
					ttt_tour += 1;
				}
			}
		}
		//fin IA
			
		//Déroulement des actions
		{
			if (ttt_1 == 1){
				glPushMatrix();
					if(ttt_1_color == 1) glColor3f(0,0,1);
					if(ttt_1_color == 2) glColor3f(1,0,0);
					if(ttt_1_color == 3) glColor3f(0,1,0);
					if(ttt_1_color == 4) glColor3f(1,0,1);
					glTranslatef(2,2,0);
					glutSolidCube(1);
				glPopMatrix();
			}
			if (ttt_2 == 1){
				glPushMatrix();
					if(ttt_2_color == 1) glColor3f(0,0,1);
					if(ttt_2_color == 2) glColor3f(1,0,0);
					if(ttt_2_color == 3) glColor3f(0,1,0);
					if(ttt_2_color == 4) glColor3f(1,0,1);
					glTranslatef(5,2,0);
					glutSolidCube(1);
				glPopMatrix();
			}
			if (ttt_3 == 1){
				glPushMatrix();
					if(ttt_3_color == 1) glColor3f(0,0,1);
					if(ttt_3_color == 2) glColor3f(1,0,0);
					if(ttt_3_color == 3) glColor3f(0,1,0);
					if(ttt_3_color == 4) glColor3f(1,0,1);
					glTranslatef(8,2,0);
					glutSolidCube(1);
				glPopMatrix();
			}
			if (ttt_4 == 1){
				glPushMatrix();
					if(ttt_4_color == 1) glColor3f(0,0,1);
					if(ttt_4_color == 2) glColor3f(1,0,0);
					if(ttt_4_color == 3) glColor3f(0,1,0);
					if(ttt_4_color == 4) glColor3f(1,0,1);
					glTranslatef(2,5,0);
					glutSolidCube(1);
				glPopMatrix();
			}
			if (ttt_5 == 1){
				glPushMatrix();
					if(ttt_5_color == 1) glColor3f(0,0,1);
					if(ttt_5_color == 2) glColor3f(1,0,0);
					if(ttt_5_color == 3) glColor3f(0,1,0);
					if(ttt_5_color == 4) glColor3f(1,0,1);
					glTranslatef(5,5,0);
					glutSolidCube(1);
				glPopMatrix();
			}
			if (ttt_6 == 1){
				glPushMatrix();
					if(ttt_6_color == 1) glColor3f(0,0,1);
					if(ttt_6_color == 2) glColor3f(1,0,0);
					if(ttt_6_color == 3) glColor3f(0,1,0);
					if(ttt_6_color == 4) glColor3f(1,0,1);
					glTranslatef(8,5,0);
					glutSolidCube(1);
				glPopMatrix();
			}
			if (ttt_7 == 1){
				glPushMatrix();
					if(ttt_7_color == 1) glColor3f(0,0,1);
					if(ttt_7_color == 2) glColor3f(1,0,0);
					if(ttt_7_color == 3) glColor3f(0,1,0);
					if(ttt_7_color == 4) glColor3f(1,0,1);
					glTranslatef(2,8,0);
					glutSolidCube(1);
				glPopMatrix();
			}
			if (ttt_8 == 1){
				glPushMatrix();
					if(ttt_8_color == 1) glColor3f(0,0,1);
					if(ttt_8_color == 2) glColor3f(1,0,0);
					if(ttt_8_color == 3) glColor3f(0,1,0);
					if(ttt_8_color == 4) glColor3f(1,0,1);
					glTranslatef(5,8,0);
					glutSolidCube(1);
				glPopMatrix();
			}
			if (ttt_9 == 1){
				glPushMatrix();
					if(ttt_9_color == 1) glColor3f(0,0,1);
					if(ttt_9_color == 2) glColor3f(1,0,0);
					if(ttt_9_color == 3) glColor3f(0,1,0);
					if(ttt_9_color == 4) glColor3f(1,0,1);
					glTranslatef(8,8,0);
					glutSolidCube(1);
				glPopMatrix();
			}
		}
		// fin Déroulement
	}
	//fin Jeu
}
glPopMatrix();


//**************** action.c ****************
//Déclarations Tic-Tac-Toe
extern int victoire;
extern int ttt_0;
extern int ttt_1;
extern int ttt_1_color;
extern int ttt_2;
extern int ttt_2_color;
extern int ttt_3;
extern int ttt_3_color;
extern int ttt_4;
extern int ttt_4_color;
extern int ttt_5;
extern int ttt_5_color;
extern int ttt_6;
extern int ttt_6_color;
extern int ttt_7;
extern int ttt_7_color;
extern int ttt_8;
extern int ttt_8_color;
extern int ttt_9;
extern int ttt_9_color;

extern int ttt_tour;

// DANS LE 'touche-pressee' -> switch
{//tic-tac-toe
	
case TOUCHE_0:
	{
		if (ttt_0 == 0) ttt_0 = 1;
		break;
	}
case TOUCHE_1:					//Je joue...
	{
		if((ttt_tour%2 == 0) && (victoire == 0)){	//...si c'est à mon tour de jouer...
			if(ttt_1 == 0){		//...et si la case est vide
				ttt_1 = 1;
				ttt_1_color = 1;
				ttt_tour += 1;
			}
		}
		break;
	}
case TOUCHE_2:
	{
		if((ttt_tour%2 == 0) && (victoire == 0)){
			if(ttt_2 == 0){
				ttt_2 = 1;
				ttt_2_color = 1;
				ttt_tour += 1;
			}
		}
		break;
	}
case TOUCHE_3:
	{
		if((ttt_tour%2 == 0) && (victoire == 0)){
			if(ttt_3 == 0){
				ttt_3 = 1;
				ttt_3_color = 1;
				ttt_tour += 1;
			}
		}
		break;
	}
case TOUCHE_4:
	{
		if((ttt_tour%2 == 0) && (victoire == 0)){
			if(ttt_4 == 0){
				ttt_4 = 1;
				ttt_4_color = 1;
				ttt_tour += 1;
			}
		}
		break;
	}
case TOUCHE_5:
	{
		if((ttt_tour%2 == 0) && (victoire == 0)){
			if(ttt_5 == 0){
				ttt_5 = 1;
				ttt_5_color = 1;
				ttt_tour += 1;
			}
		}
		break;
	}
case TOUCHE_6:
	{
		if((ttt_tour%2 == 0) && (victoire == 0)){
			if(ttt_6 == 0){
				ttt_6 = 1;
				ttt_6_color = 1;
				ttt_tour += 1;
			}
		}
		break;
	}
case TOUCHE_7:
	{
		if((ttt_tour%2 == 0) && (victoire == 0)){
			if(ttt_7 == 0){
				ttt_7 = 1;
				ttt_7_color = 1;
				ttt_tour += 1;
			}
		}
		break;
	}
case TOUCHE_8:
	{
		if((ttt_tour%2 == 0) && (victoire == 0)){
			if(ttt_8 == 0){
				ttt_8 = 1;
				ttt_8_color = 1;
				ttt_tour += 1;
			}
		}
		break;
	}
case TOUCHE_9:
	{
		if((ttt_tour%2 == 0) && (victoire == 0)){
			if(ttt_9 == 0){
				ttt_9 = 1;
				ttt_9_color = 1;
				ttt_tour += 1;
			}
		}
		break;
	}
}//fin tictactoe
