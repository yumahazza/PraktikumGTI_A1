#include <windows.h>
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ====== TITIK (GL_POINTS) ======
    glColor3f(1,0,0);
    glPointSize(8);   

    glBegin(GL_POINTS);
        glVertex2f(-0.8,0.7);
        glVertex2f(-0.7,0.6);
        glVertex2f(-0.6,0.7);
    glEnd();


    // ====== GARIS (GL_LINES) ======
    glColor3f(0,0,1); 

    glBegin(GL_LINES);
        glVertex2f(-0.4,0.7);
        glVertex2f(-0.2,0.6);

        glVertex2f(-0.2,0.7);
        glVertex2f(0.0,0.6);
        
        glVertex2f(0.2,0.7);
        glVertex2f(0.0,0.8);
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
    glutInitWindowSize(500,500);
    glutCreateWindow("GL_POINTS dan GL_LINES");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}


