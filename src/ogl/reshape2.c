/*
 *  reshape1.c
 *
 *  keep aspect ratio the same, size varies
 *
 */

#include <stdio.h>
#include "glut.h"

void
setup(void)
{
    glClearColor(0.95, 0.95, 0.95, 1.0);
}

void display(void)
{
    printf("Display\n");

    glClear(GL_COLOR_BUFFER_BIT); 

    glColor3f(1.0, 0.25, 0.25);
    glRectf(-0.5, -0.5, 0.5, 0.5);

    glFlush();
}

void reshape(int w, int h)
{
    printf("Reshape %d %d\n", w, h );

    /* keep the aspect ratio fixed */

    glViewport(0,0,w,h);

    // coordinate systems are implemented using matrices
    // we will devote a future lecture to how to do this

    // initialize the current transformation matrix
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    // gluOrtho2D sets the coordinates at the edges of the window
    if( w > h ) {
        float aspect = (float)w / (float)h;
	gluOrtho2D(-aspect, aspect, -1.0, 1.0);
    }
    else {
        float aspect = (float)h / (float)w;
	gluOrtho2D(-1.0, 1.0, -aspect, aspect);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv); 

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(512,512);
    glutInitWindowPosition(50,50);
    glutCreateWindow("reshape"); 

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    setup();

    glutMainLoop();
}
