#include <glut.h>
#include <math.h>

const float pi = 3.1415926535897;
float fovy = 60.0, aspect = 1.0, near_ = 0.1, far_ = 20.0;
float Y = 2.0, Y_look_at = 0.0;  
float alfa = 60.0;
const float delta_alfa2 = 0.5;
float alfa2 = - 5.0;
bool linie = false;
bool skrzydla = false;

void anim()
{
	if((alfa2 <= 145) && skrzydla)
	{
		alfa2 += delta_alfa2;
		glutPostRedisplay();
	}
	if((alfa2 > - 5.0) && !skrzydla)
	{
		alfa2 -= delta_alfa2;
		glutPostRedisplay();
	}
}

void lines()
{
  
	glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0); //zielona oœ X
		glVertex3f(-5.0, 0.0, 0.0);
		glVertex3f(5.0, 0.0, 0.0); 

		glColor3f(0.0, 0.0, 1.0); // niebieska oœ Y
		glVertex3f(0.0, -5.0, 0.0);
		glVertex3f(0.0,  5.0, 0.0);
	
		glColor3f(1.0,  0.0, 0.0); // czerwona oœ Z
		glVertex3f(0.0, 0.0, -5.0);
		glVertex3f(0.0, 0.0,  5.0);  
	glEnd();

}

void rectangle()
{
	glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glArrayElement(0);
		glTexCoord2f(1, 0);
		glArrayElement(1);
		glTexCoord2f(1, 1);
		glArrayElement(2);
		glTexCoord2f(0, 1);
		glArrayElement(3); 
    glEnd();
}

void pentagon()
{
	glBegin(GL_POLYGON);
	    glTexCoord2f(0, 0);
		glArrayElement(0);
		glTexCoord2f(1, 0);
		glArrayElement(1);
		glTexCoord2f(1, 1);
		glArrayElement(2);
		glTexCoord2f(0, 1);
		glArrayElement(3);
		glArrayElement(4);
    glEnd();
}

void rectangle_lines()
{
	glBegin(GL_LINES);
		glArrayElement(0);
		glArrayElement(1);
		glArrayElement(1);
		glArrayElement(2);
		glArrayElement(2);
		glArrayElement(3);     
		glArrayElement(3); 
		glArrayElement(0);       
    glEnd();
}

void pentagon_lines()
{
	glBegin(GL_LINES);
		glArrayElement(0);
		glArrayElement(1);
		glArrayElement(1);
		glArrayElement(2);
		glArrayElement(2);
		glArrayElement(3);
		glArrayElement(3);
		glArrayElement(4);
		glArrayElement(4);
		glArrayElement(0);
    glEnd();
}

void klawiatura(int  kod_klawisza, int x, int y)
{
  switch (kod_klawisza) 
  {

  case GLUT_KEY_LEFT :
		   alfa += 1;
           glutPostRedisplay();
		   break;
		       
  case GLUT_KEY_RIGHT :
		   alfa -= 1;
           glutPostRedisplay();
		   break;
	
  case GLUT_KEY_UP :
	       Y += 0.1;
		   Y_look_at += 0.1;
		   glutPostRedisplay();
		   break;

  case GLUT_KEY_DOWN :
	       Y -= 0.1;
		   Y_look_at -= 0.1;
		   glutPostRedisplay();
		   break;

  case GLUT_KEY_PAGE_UP :
		if(!skrzydla)   
		   skrzydla = true;
		else
		   skrzydla = false;
		   glutPostRedisplay();
		   break;

  case GLUT_KEY_HOME :
		   alfa = 60;
		   Y = 2.0;
		   Y_look_at = 0.0;
		   glutPostRedisplay();
		   break;
  }
}

void odrysuj(int szerokosc, int wysokosc)
{
	float  h = float(wysokosc), w = float(szerokosc);
	glViewport(0, 0, szerokosc, wysokosc);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, aspect, near_, far_);
	glMatrixMode(GL_MODELVIEW);
}

void siatka()
{
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_przod_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_tyl_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_dol_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_prawy_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_lewy_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, kokpit_gora_linie),
	rectangle_lines();
	
	
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_dol_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_gora_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_przod_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_tyl_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_lewy_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusGorny_prawy_linie),
	rectangle_lines();
	
	glInterleavedArrays(GL_C3F_V3F, 0, korpusDolny_gora_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusDolny_dol_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusDolny_przod_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, korpusDolny_tyl_linie),
	rectangle_lines();
	
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_dol_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_gora_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_przod_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_tyl_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_prawy_linie),
	rectangle_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, mocowanie_lewy_linie),
	rectangle_lines();

	glInterleavedArrays(GL_C3F_V3F, 0, gorneSkrzydlo_prawy_linie),
	pentagon_lines();
	glInterleavedArrays(GL_C3F_V3F, 0, gorneSkrzydlo_lewy_linie),
	pentagon_lines();
}
