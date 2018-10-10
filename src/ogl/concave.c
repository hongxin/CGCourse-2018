/*
 *  concave.c
 */

#include "glut.h"

int convex = 0;

void setup()
{
    gluOrtho2D(-4.0, 4.0, -4.0, 4.0);
}

void display(void) 
{
    glClearColor(0.95f, 0.95f, 0.95f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT); 

    glColor3f(1.0f, 0.25, 0.25f);
    glBegin(GL_POLYGON);
	glVertex2f(-2.0, 2.0);
	glVertex2f(2.0, 2.0);
        // polygon is basically triangle fan ...
        if( convex )
	    glVertex2f(3.0, 0.0);
        else
	    glVertex2f(0.0, 3.0);
	glVertex2f(2.0, -2.0);
	glVertex2f(-2.0, -2.0);
    glEnd();

    glFlush();
}

void key(unsigned char k,int x,int y)
{
    convex = !convex;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv); 
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Convex vs. Concave"); 

    setup();

    glutKeyboardFunc(key);
    glutDisplayFunc(display);

    glutMainLoop();
}
