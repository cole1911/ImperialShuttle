#include <glut.h>

const float pi = 3.1415926535897;
float fovy = 60.0, aspect = 1.0, near_ = 0.1, far_ = 20.0;
float Y = 1.5, Y_look_at = 0.0;  
float alfa = 40.0;

void lines()
{
  
	glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0); //zielona oœ X
		glVertex3f(-5.0, 0.0, 0.0);
		glVertex3f(5.0, 0.0, 0.0); 

		glColor3f(0.0, 0.0, 1.0); // niebieska oœ Y
		glVertex3f(0.0, -5.0, 0.0);
		glVertex3f(0.0,  5.0, 0.0);
	
		glColor3f(0.0,  0.0, 0.0); // czarna oœ Z
		glVertex3f(0.0, 0.0, -5.0);
		glVertex3f(0.0, 0.0,  5.0);  
	glEnd();

}

void rectangle()
{
	glBegin(GL_QUADS);
		glArrayElement(0);
		glArrayElement(1);
		glArrayElement(2);
		glArrayElement(3); 
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

void klawiatura(int  kod_klawisza, int x, int y)
{
  switch (kod_klawisza) {

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
		   glutPostRedisplay();
		   break;

  case GLUT_KEY_PAGE_DOWN :
		   glutPostRedisplay();
		   break;

  case GLUT_KEY_HOME :
		   alfa = 40;
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
	glLoadIdentity();
	gluPerspective(fovy, w/h, near_, far_);
	
}
