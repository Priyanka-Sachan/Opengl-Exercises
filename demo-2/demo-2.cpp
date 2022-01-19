/* Creating an colored polygon [2D(in comments) and 3D]*/

#include <stdio.h>
#include <GL/glut.h>

int w = 500, h = 500;

void polygon()
{
    // Drawing is done by specifying a sequence of vertices.
    // The way these vertices are connected (or not connected) depends on the argument to glBegin.
    // GL_POLYGON constructs a filled polygon.
    glBegin(GL_POLYGON);
    // We have to declare the points in this sequence: starting from bottom-left and moving in anti-clockwise manner.
    glColor3f(1, 0, 0);
    glVertex2f(-0.6, -0.75);
    glColor3f(0, 1, 0);
    glVertex2f(0.6, -0.75);
    glColor3f(0, 0, 1);
    glVertex2f(0, 0.75);
    // Mark the end of drawing
    glEnd();
    // Flush drawing command buffer to make drawing happen as soon as possible.
    glFlush();
}

void iterate()
{
    glViewport(0, 0, 500, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

void showScreen()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    iterate();
    polygon();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGl Polygon");
    glutDisplayFunc(showScreen);
    glutMainLoop();
    return 0;
}