/*
 *  primitives.c
 *
 *  redbook Figure 2-7 defines the interpretation of vertices
 */

#include <stdio.h>
#include "glut.h"

// enumerate all the opengl primitives 
int prims[] = {
    GL_POINTS,

    GL_LINES,
    GL_LINE_LOOP,
    GL_LINE_STRIP,

    GL_POLYGON,

    GL_TRIANGLES,
    GL_TRIANGLE_STRIP,
    GL_TRIANGLE_FAN,

    GL_QUADS,
    GL_QUAD_STRIP

};
char *sprims[] = {
    "points",

    "lines",
    "line loop",
    "line strip",

    "polygon",

    "triangles",
    "triangle strip",
    "triangle fan",

    "quads",
    "quad strip"
};
const NPRIMS = sizeof(prims)/sizeof(int);
int prim = 0;

void setup()
{
    gluOrtho2D(-4.0, 4.0, -4.0, 4.0);

    glClearColor(0.95f, 0.95f, 0.95f, 1.0f);
}

void display(void) 
{
    glClear(GL_COLOR_BUFFER_BIT); 

    // Set graphics attributes
    int p = prims[prim];

    // Point attributes
    if( p == GL_POINTS )
        glPointSize(4.0f);
    // Line attributes
    if( p == GL_LINES || p == GL_LINE_STRIP || p == GL_LINE_LOOP )
        glLineWidth(4.0f);
    // Polygon attributes

    // Draw the verticies 
    glColor3f(1.0f, 0.25, 0.25f);
    glBegin(prims[prim]);
	glVertex2f(-2.0, 2.0);
	glVertex2f(2.0, 2.0);
	glVertex2f(3.0, 0.0);
	glVertex2f(2.0, -2.0);
	glVertex2f(-2.0, -2.0);
    glEnd();

    glFlush();
}

void key(unsigned char k,int x,int y)
{
    prim = (prim + 1) % NPRIMS;
    printf("%s\n",sprims[prim]);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv); 

    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Primitives"); 

    prim = 0;
    printf("%s\n",sprims[prim]);

    setup();

    glutKeyboardFunc(key);
    glutDisplayFunc(display);

    glutMainLoop();
}
