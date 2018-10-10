/*
 *  reshape2.c
 *
 */

#include <stdio.h>
#include "glut.h"

# define SIZE 512

void setup(void)
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

    /* keep the aspect ratio and size fixed */

    glViewport(0,0,w,h);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    // size defined relative to original window size
    float size = SIZE;
    gluOrtho2D(-w/size,w/size,-h/size,h/size);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv); 
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(SIZE,SIZE);
    glutInitWindowPosition(50,50);
    glutCreateWindow("reshape"); 

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    setup();

    glutMainLoop();
}
