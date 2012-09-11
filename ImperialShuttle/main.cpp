#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include "vertex.h"
#include "methods_and_functions.h"
#include "tex.h"

//--------------Deklaracja i wartoœci inicjuj¹ce dla œwiate³ i materia³u ---------

//globalna energia ambient   
GLfloat scene_ambient[] = { 1.0, 1.0, 1.0, 1.0 }; 
	
//specyfikacja Ÿród³a œwiat³a nr 0 - Ÿród³o izotropowe

GLfloat light0_position[] = { 1.0, 1.0, 1.0, 1.0 }; //po³o¿enie
GLfloat light0_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; //energia ambient
GLfloat light0_diffuse[] = { 1.0, 1.0, 1.0, 1.0 }; //energia diffuse
GLfloat light0_specular[] = { 1.0, 1.0, 1.0, 1.0 }; //energia specular

//specyfikacja Ÿród³a œwiat³a nr 1 - Ÿród³o kierunkowe

GLfloat light1_position[] = { 1.0, 1.0, 1.0, 1.0 };//po³o¿enie
GLfloat light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 };//energia ambient
GLfloat light1_diffuse[] = { 1.0, 1.0, 0.1, 1.0 };//energia diffuse
GLfloat light1_specular[] = { 0.2, 0.1, 0.0, 1.0 };//energia specular
GLfloat light1_spot_direction[] = { -5, -5, -10, 1.0 };//g³ówny kierunek œwiat³a
GLint light1_spot_cutoff = 14;//zakres odchylenia od kierunk g³ównego
GLint light1_spot_exponent = 29;//szybkoœæ wygaszania wewnatzr sto¿ka	
	
//specyfikacja materia³u

GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };//reakcja na energiê ambient
GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };////reakcja na energiê diffuse
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };////reakcja na energiê specular
GLfloat mat_emmision[] = { 0.0, 0.0, 0.0, 1.0 };//w³asnoœci emisyjne
GLfloat mat_shininess = 10.0 ;//wspó³czynnik potêgowy dla reakcji na œwiat³o specular

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    gluLookAt(2*cos(pi*alfa/180.0), Y, 2*sin(pi*alfa/180.0), 0.0, Y_look_at, 0.0, 0.0, 1.0, 0.0);

	mat_specular[0] = 0.0;
	mat_specular[1] = 0.0;
    mat_specular[2] = 0.0;
	   
	mat_diffuse[0] = 0.6;
	mat_diffuse[1] = 0.6;
    mat_diffuse[2] = 0.6;
	
	mat_shininess = 100.0;

	mat_ambient[0] = 1.0;
	mat_ambient[1] = 1.0;
	mat_ambient[2] = 1.0;
	
	light0_position[0] = 1.0;
	light0_position[1] = 1.0;
	light0_position[2] = 1.0;
	
	light0_specular[0] = 0.728;
	light0_specular[1] = 0.728;
	light0_specular[2] = 0.728;
		
	light0_diffuse[0] = 0.728;
	light0_diffuse[1] = 0.728;
	light0_diffuse[2] = 0.728;
	
    scene_ambient[0] = 0.728;
	scene_ambient[1] = 0.728;
	scene_ambient[2] = 0.728;

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, scene_ambient);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1); //ustawienie œledzenie wektora obserwatora
	
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);	
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess );

	lines();

	glPushMatrix();
	glTranslatef(-0.2, 0.0, 1.0);

	glEnable(GL_TEXTURE_2D);

	// kokpit
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_przod),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_tyl),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_dol),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_prawy),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_lewy),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_gora),
	rectangle();

	// korpus górny
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_dol),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_gora),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_przod),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_tyl),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_lewy),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_prawy),
	rectangle();

	// korpus dolny
	glInterleavedArrays(GL_C3F_V3F, 0, korpusDolny_gora),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusDolny_dol),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusDolny_przod),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusDolny_tyl),
	rectangle();
	glColor3f(0.728, 0.728, 0.728);
	glPushMatrix();
	glTranslatef(-0.25, 0.033, -1.35);
	gluCylinder(gluNewQuadric(), 0.068, 0.068, 0.85, 100, 100);
	glTranslatef(0.92, 0.0, 0.0);
	gluCylinder(gluNewQuadric(), 0.068, 0.068, 0.85, 100, 100);
	glPopMatrix();

	// mocowanie górnego skrzyd³a
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_dol),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_gora),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_przod),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_tyl),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_prawy),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_lewy),
	rectangle();

	// górne skrzyd³o
	glInterleavedArrays(GL_C3F_V3F, 0, gorneSkrzydlo_prawy),
	pentagon();
	glInterleavedArrays(GL_C3F_V3F, 0, gorneSkrzydlo_lewy),
	pentagon();
	glInterleavedArrays(GL_C3F_V3F, 0, gorneSkrzydlo_5),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, gorneSkrzydlo_4),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, gorneSkrzydlo_3),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, gorneSkrzydlo_2),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, gorneSkrzydlo_1),
	rectangle();
	
	if(linie)
		siatka();

	// boczne skrzyd³a

	// lewe
	glPushMatrix();
	glTranslatef(0.707, 0.05, 0);
	glRotatef(-alfa2, 0, 0, 1);
	glTranslatef(-0.707, -0.05, 0);
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_gora),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_dol),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_2),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_1),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_gora),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_dol),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_3),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_2),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_1),
	rectangle();
	if(linie)
	{
		glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_gora_linie),
		rectangle_lines();
		glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_dol_linie),
		rectangle_lines();
		glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_gora_linie),
		rectangle_lines();
		glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_dol_linie),
		rectangle_lines();
	}
	glPopMatrix();
	
	// prawe
	glPushMatrix();
	glTranslatef(-0.29, 0.05, 0);
	glRotatef(alfa2, 0, 0, 1);
	glTranslatef(0.29, -0.05, 0);
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_gora2),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_dol2),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_4),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_3),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_gora2),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_dol2),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_6),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_5),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_4),
	rectangle();
	if(linie)
	{
		glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_gora_linie2),
		rectangle_lines();
		glInterleavedArrays(GL_C3F_V3F, 0, skrzydloDol_dol_linie2),
		rectangle_lines();
		glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_gora_linie2),
		rectangle_lines();
		glInterleavedArrays(GL_C3F_V3F, 0, skrzydloGora_dol_linie2),
		rectangle_lines();
	}
	glPopMatrix();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
} 

void init(void) 
{   
	glClearColor (0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	setTexture("z3.bmp", GL_REPLACE);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);                          
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(1024, 720);
	glutInitWindowPosition(100, 10);
	glutCreateWindow("Scena testowa");
	glutDisplayFunc(display);
	glutIdleFunc(anim);
	glutSpecialFunc(klawiatura);
	glutReshapeFunc(odrysuj);
	init();
	glutMainLoop();
}
