/* Creating an OpenGl window using Glut */

#include <stdio.h>
#include <GL/glut.h>

int w = 500, h = 500;

void iterate()
{
    // The first two parameters of glViewport set the location of the lower left corner of the window. The third and fourth parameter set the width and height of the rendering window in pixels, which we set equal to GLFW's window size.
    // We could actually set the viewport dimensions at values smaller than GLFW's dimensions; then all the OpenGL rendering would be displayed in a smaller window and we could for example display other elements outside the OpenGL viewport.
    // If we don't set viewport, whole whole would be taken and objects defined relative/absolute to that.
    glViewport(0, 0, 500, 500);

    // Define a world window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

void showScreen()
{
    // Set the clear color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    // Set every pixel in the frame buffer to the current clear color.
    glClear(GL_COLOR_BUFFER_BIT);
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
    // Specify the display Mode – RGB or color Index, single or double Buffer
    glutInitDisplayMode(GLUT_RGBA);
    // Set the width and height of your window
    glutInitWindowSize(w, h);
    // Set the position at which this windows should appear
    glutInitWindowPosition(0, 0);
    // Set a window title
    glutCreateWindow("OpenGl Window");
    // Tell GLUT that whenever the main window needs to be repainted that it should call the function showScreen().
    glutDisplayFunc(showScreen);
    // Register the callback that will be called when a key is pressed will be called when a key is pressed
    // glutKeyboardFunc(demoFunc)
    // Register the callback that will be ca ed e a ouse butto s p essed called when a mouse button is pressed
    // glutMouseFunc(demoFunc)
    // Register the callback that will be called when the mouse is in motion while a buton is pressed
    // glutMotionFunc(demoFunc)
    // Register the callback that will be called hen nothing i going on (no e ent)
    // glutIdleFunc(demoFunc)
    // The program goes into a infinite loop waiting for events
    glutMainLoop();
    return 0;
}
