#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, palm = 0, fingers = 0;

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glShadeModel(GL_FLAT);
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix(); 

    /* --- 1. BAHU & LENGAN ATAS --- */
    glTranslatef(-1.0, 0.0, 0.0); 
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0); 
    glPushMatrix();
        glScalef(2.0, 0.4, 1.0); 
        glutWireCube(1.0); 
    glPopMatrix();

    /* --- 2. SIKU & LENGAN BAWAH --- */
    glTranslatef(1.0, 0.0, 0.0); 
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0); 
    glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCube(1.0);
    glPopMatrix();

    /* --- 3. TELAPAK TANGAN --- */
    glTranslatef(1.0, 0.0, 0.0);             
    glRotatef((GLfloat)palm, 0.0, 0.0, 1.0); 
    
    glPushMatrix();
        glTranslatef(0.4, 0.0, 0.0);         
        glScalef(0.8, 0.4, 0.2);             
        glutWireCube(1.0);                   
    glPopMatrix();

    /* --- 4. LIMA JARI --- */
    float fingerY[] = {0.15, 0.07, 0.0, -0.07, -0.15};

    for(int i = 0; i < 5; i++) {
        glPushMatrix();
            glTranslatef(0.8, fingerY[i], 0.0); 
            glRotatef((GLfloat)fingers, 0.0, 0.0, 1.0); 
            
            glPushMatrix();
                glTranslatef(0.2, 0.0, 0.0); 
                glScalef(0.4, 0.06, 0.1);    
                glutWireCube(1.0);           
            glPopMatrix();
        glPopMatrix();
    }

    glPopMatrix(); 
    glutSwapBuffers(); 
}


void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 
    glTranslatef(0.0, 0.0, -5.0);
}


void keyboard(unsigned char key, int x, int y){
    switch (key){
        // Kontrol Bahu (w/e)
        case 'w': shoulder = (shoulder + 5) % 360; break;
        case 'e': shoulder = (shoulder - 5) % 360; break;
        
        // Kontrol Siku (s/d)
        case 's': elbow = (elbow + 5) % 360; break;
        case 'd': elbow = (elbow - 5) % 360; break;
        
        // Kontrol Telapak (p/o)
        case 'p': palm = (palm + 5) % 90; break;
        case 'o': palm = (palm - 5) % 90; break;
        
        // Kontrol Jari (k/l)
        case 'k': fingers = (fingers + 5) % 90; break;
        case 'l': fingers = (fingers - 5) % 90; break;
		
        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv){
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Tugas Modul 4 - Lengan Lengkap"); 
    init(); 
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 
    glutKeyboardFunc(keyboard);
    glutMainLoop(); 
    return 0;
}



