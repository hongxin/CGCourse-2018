/*
 *  rect.c
 *
 *  This program draws a square
 */

#include <stdio.h>

/* glut.h includes gl.h and glu.h */
#include "glut.h"

void
setup(void)
{
    // set the background color 
    glClearColor(0.05f, 0.05f, 0.95f, 1.0f);
}

void 
display(void)
{
    printf("Display\n");

    // clear background - actually draw something
    // this uses the clear color set in setup
    // note that graphics states persists across "frames"
    glClear(GL_COLOR_BUFFER_BIT); 

    // draw unit square

    // set current color using RGB; 3f means 3 "floats"
    glColor3f(1.0f, 0.25f, 0.25f);

    // the default coordinate system is
    //  lower left at (-1,-1)
    //  upper right at (1,1)
    // thus, x and y range from -1 to 1

    // draw rectangle (x1,y1, x2,y2)
    glRectf(-0.5, -0.5, 0.5, 0.5);

    // glFlush — "force execution of GL commands in finite time"
    glFlush();

    // glFinish - "block until all GL execution is complete"
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv); 

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);  
    glutInitWindowSize(512,512);
    glutInitWindowPosition(32,32);
    glutCreateWindow("rect"); 

    setup();

    glutDisplayFunc(display);

    glutMainLoop();
}
