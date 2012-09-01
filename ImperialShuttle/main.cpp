#include <glut.h> 
#include <math.h>
#include "vertex.h"
#include "methods_and_functions.h"

void display()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluPerspective(fovy, aspect, near_, far_);
    gluLookAt(2*cos(pi*alfa/180.0), Y, 2*sin(pi*alfa/180.0), 0.0, Y_look_at, 0.0, 0.0, 1.0, 0.0);
	lines();
	glTranslatef(-0.2, 0.0, 1.0);

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

	glFlush();
	glutSwapBuffers();
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
	glutMainLoop();
}
