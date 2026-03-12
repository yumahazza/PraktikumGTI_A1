#include <windows.h>
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ====== LINE STRIP ======
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.9,0.7);
        glVertex2f(-0.7,0.8);
        glVertex2f(-0.5,0.7);
        glVertex2f(-0.3,0.8);
    glEnd();


    // ====== LINE LOOP ======
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.2,0.7);
        glVertex2f(0.0,0.8);
        glVertex2f(0.2,0.7);
        glVertex2f(0.0,0.6);
    glEnd();


    // ====== TRIANGLE FAN ======
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.6,0.7);
        glVertex2f(0.5,0.6);
        glVertex2f(0.7,0.6);
        glVertex2f(0.8,0.7);
        glVertex2f(0.7,0.8);
        glVertex2f(0.5,0.8);
    glEnd();


    // ====== TRIANGLE STRIP ======
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.9,0.3);
        glVertex2f(-0.8,0.1);
        glVertex2f(-0.7,0.3);
        glVertex2f(-0.6,0.1);
        glVertex2f(-0.5,0.3);
    glEnd();


    // ====== QUADS ======
    glColor3f(1,0,1);
    glBegin(GL_QUADS);
        glVertex2f(0.1,0.3);
        glVertex2f(0.3,0.3);
        glVertex2f(0.3,0.1);
        glVertex2f(0.1,0.1);
    glEnd();


    // ====== QUAD STRIP ======
    glColor3f(0,1,1);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.5,0.3);
        glVertex2f(0.5,0.1);
        glVertex2f(0.7,0.3);
        glVertex2f(0.7,0.1);
        glVertex2f(0.9,0.3);
        glVertex2f(0.9,0.1);
    glEnd();


    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Primitive OpenGL");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}





