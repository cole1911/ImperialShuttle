#include <glut.h> 
#include <math.h>
#include "vertex.h"
#include "methods_and_functions.h"

void display()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluPerspective(fovy, aspect, near_, far_);
    gluLookAt(2*cos(pi*alfa/180.0), Y, 2*sin(pi*alfa/180.0), 0.0, Y_look_at, 0.0, 0.0, 1.0, 0.0);
	lines();
	glTranslatef(-0.2, 0.0, 1.0);

	// kokpit (6 œcian)
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_przod),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_przod_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_tyl),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_tyl_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_dol),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_dol_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_prawy),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_prawy_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_lewy),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_lewy_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_gora),
	rectangle();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_gora_linie),
	rectangle_lines();

	glFlush();
	glutSwapBuffers();
} 

void main(int argc, char** argv)
{
	glutInit(&argc, argv);                          
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Scena testowa");
	glutDisplayFunc(display);
	glutSpecialFunc(klawiatura);
	glutReshapeFunc(odrysuj);
	glutMainLoop();
}
