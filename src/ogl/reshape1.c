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

void reshape(int w, int h)
{
    printf("Reshape %d %d\n", w, h );

    // the viewport command selects an area to draw within
    // inside the window. In this case, we select the entire
    // window of width w and height h
    glViewport(0,0,w,h);

    // the Ortho command sets the coordinate system for the
    // viewport.  In this case, we explicitly set the values
    // to the default values
    //
    // There is a 3D version of the same command
    //
    // note that this is a glu function not a gl function
    // (glu stands for gl utility library)
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void display(void)
{
    printf("Display\n");

    glClear(GL_COLOR_BUFFER_BIT); 

    glColor3f(1.0, 0.25, 0.25);
    glRectf(-0.5, -0.5, 0.5, 0.5);

    glFlush();
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
