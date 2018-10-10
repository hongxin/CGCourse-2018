/*
 *  single.c
 *
 *  This program animates a square rotating. The square is drawn into the
 *  using "single" buffer mode. As a result the image tears and flickers.
 *
 *  Pat Hanrahan 
 */
#include "glut.h"

static GLfloat spin = 0.0;

void 
tick(int value)
{
    spin = spin + 10.0;
    if (spin > 360.0)
	spin = spin - 360.0;

    // reschedule
    glutTimerFunc(16.0f, tick, 0);
    // redisplay
    glutPostRedisplay();
}

void 
display(void)
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glClear (GL_COLOR_BUFFER_BIT);

    glPushMatrix ();
	glRotatef (spin, 0.0, 0.0, 1.0); // rotate about Z for 2D!
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	    glVertex2f(-0.5, -0.5);
	    glVertex2f(-0.5, 0.5);
	    glVertex2f(0.5, 0.5);
	    glVertex2f(0.5, -0.5);
	glEnd();
    glPopMatrix ();

    glutSwapBuffers();
}

int
main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Spinning Square (Single Buffer)");

    glutDisplayFunc(display);

    // 16 msecs
    glutTimerFunc(16.0f, tick, 0);

    glutMainLoop();
}
