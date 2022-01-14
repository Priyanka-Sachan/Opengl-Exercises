/* Creating an OpenGl window using Glut */

#include <stdio.h>
#include <GL/glut.h>

int w = 500, h = 500;

void iterate()
{
    // The first two parameters of glViewport set the location of the lower left corner of the window. The third and fourth parameter set the width and height of the rendering window in pixels, which we set equal to GLFW's window size.
    // We could actually set the viewport dimensions at values smaller than GLFW's dimensions; then all the OpenGL rendering would be displayed in a smaller window and we could for example display other elements outside the OpenGL viewport.
    glViewport(0, 0, 500, 500);
    // Setup viewing projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Setup 10x10x2 viewing world
    glOrtho(0.0, 500, 0.0, 500, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void showScreen()
{
    // Set the clear color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // Remove everything from screen (i.e. displays all given clear color)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Start with identity matrix
    glLoadIdentity();
    iterate();
    // ...Add the models
    // glutSwapBuffers will swap the color buffer (a large 2D buffer that contains color values for each pixel in GLFW's window) that is used to render to during this render iteration and show it as output to the screen.
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    // Initialize Glut
    glutInit(&argc, argv);
    // Set the display mode to be colored
    glutInitDisplayMode(GLUT_RGBA);
    // Set the width and height of your window
    glutInitWindowSize(w, h);
    // Set the position at which this windows should appear
    glutInitWindowPosition(0, 0);
    // Set a window title
    glutCreateWindow("OpenGl Window");
    // Open the given screen
    glutDisplayFunc(showScreen);
    // Keeps the window open
    glutIdleFunc(showScreen);
    // Keeps the above created window displaying/running in a loop
    glutMainLoop();
    return 0;
}
