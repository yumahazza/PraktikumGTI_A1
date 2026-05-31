/*
 * Tugas Praktikum 6 - Depth dan Lighting di OpenGL
 * Membuat Mobil 3D dari Rangka Primitive
 * Author: Yuma Hazza Yuditama (24060124120035)
 */

#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 3.0f, z = 25.0f; // Posisi awal kamera diperjauh agar mobil terlihat utuh
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0, h, w;

void Reshape(int w1, int h1) {
    if (h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f);
}

void orientMe(float ang) {
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i) {
    x = x + i * (lx) * 0.2; // Sedikit dipercepat
    z = z + i * (lz) * 0.2;
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void Grid() {
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 1.5;
    
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for (i = Z_MIN; i < Z_MAX; i += gap) {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for (i = X_MIN; i < X_MAX; i += gap) {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
}

// Fungsi helper untuk membuat rangka balok dari 6 QUADS (Sesuai Syarat Tugas)
void DrawBox(float sx, float sy, float sz) {
    // Depan
    glPushMatrix();
    glTranslatef(0, 0, sz/2);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f); // Normal vector agar cahaya bereaksi
    glVertex3f(-sx/2, -sy/2, 0.0f);
    glVertex3f(sx/2, -sy/2, 0.0f);
    glVertex3f(sx/2, sy/2, 0.0f);
    glVertex3f(-sx/2, sy/2, 0.0f);
    glEnd();
    glPopMatrix();
    
    // Belakang
    glPushMatrix();
    glTranslatef(0, 0, -sz/2);
    glRotated(180, 0, 1, 0);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-sx/2, -sy/2, 0.0f);
    glVertex3f(sx/2, -sy/2, 0.0f);
    glVertex3f(sx/2, sy/2, 0.0f);
    glVertex3f(-sx/2, sy/2, 0.0f);
    glEnd();
    glPopMatrix();
    
    // Kiri
    glPushMatrix();
    glTranslatef(-sx/2, 0, 0);
    glRotated(-90, 0, 1, 0);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-sz/2, -sy/2, 0.0f);
    glVertex3f(sz/2, -sy/2, 0.0f);
    glVertex3f(sz/2, sy/2, 0.0f);
    glVertex3f(-sz/2, sy/2, 0.0f);
    glEnd();
    glPopMatrix();
    
    // Kanan
    glPushMatrix();
    glTranslatef(sx/2, 0, 0);
    glRotated(90, 0, 1, 0);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-sz/2, -sy/2, 0.0f);
    glVertex3f(sz/2, -sy/2, 0.0f);
    glVertex3f(sz/2, sy/2, 0.0f);
    glVertex3f(-sz/2, sy/2, 0.0f);
    glEnd();
    glPopMatrix();
    
    // Atas
    glPushMatrix();
    glTranslatef(0, sy/2, 0);
    glRotated(-90, 1, 0, 0);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-sx/2, -sz/2, 0.0f);
    glVertex3f(sx/2, -sz/2, 0.0f);
    glVertex3f(sx/2, sz/2, 0.0f);
    glVertex3f(-sx/2, sz/2, 0.0f);
    glEnd();
    glPopMatrix();
    
    // Bawah
    glPushMatrix();
    glTranslatef(0, -sy/2, 0);
    glRotated(90, 1, 0, 0);
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-sx/2, -sz/2, 0.0f);
    glVertex3f(sx/2, -sz/2, 0.0f);
    glVertex3f(sx/2, sz/2, 0.0f);
    glVertex3f(-sx/2, sz/2, 0.0f);
    glEnd();
    glPopMatrix();
}

void Mobil3D() {
    // 1. Rangka Badan Mobil (Bawah)
    glPushMatrix();
    glColor3f(0.8f, 0.2f, 0.2f); // Warna Merah
    glTranslatef(0.0f, 2.0f, 0.0f);
    DrawBox(10.0f, 2.0f, 5.0f); // Memanggil fungsi pembuat kotak dari 6 quad
    glPopMatrix();

    // 2. Rangka Kabin Mobil (Atas)
    glPushMatrix();
    glColor3f(0.2f, 0.4f, 0.8f); // Warna Biru
    glTranslatef(-1.0f, 4.0f, 0.0f);
    DrawBox(5.0f, 2.0f, 4.8f);
    glPopMatrix();

    // 3. Roda Mobil (Nilai Tambah)
    glColor3f(0.1f, 0.1f, 0.1f); // Warna Hitam gelap untuk ban
    
    // Roda Depan Kanan
    glPushMatrix();
    glTranslatef(3.0f, 1.0f, 2.6f);
    glutSolidTorus(0.4, 0.8, 15, 30);
    glPopMatrix();
    
    // Roda Depan Kiri
    glPushMatrix();
    glTranslatef(3.0f, 1.0f, -2.6f);
    glutSolidTorus(0.4, 0.8, 15, 30);
    glPopMatrix();
    
    // Roda Belakang Kanan
    glPushMatrix();
    glTranslatef(-3.0f, 1.0f, 2.6f);
    glutSolidTorus(0.4, 0.8, 15, 30);
    glPopMatrix();
    
    // Roda Belakang Kiri
    glPushMatrix();
    glTranslatef(-3.0f, 1.0f, -2.6f);
    glutSolidTorus(0.4, 0.8, 15, 30);
    glPopMatrix();
}

void display() {
    if (deltaMove)
        moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    Grid();
    Mobil3D();
    
    glutSwapBuffers();
    glFlush();
}

void pressKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
        case GLUT_KEY_RIGHT: deltaAngle = 0.01f; break;
        case GLUT_KEY_UP: deltaMove = 1; break;
        case GLUT_KEY_DOWN: deltaMove = -1; break;
    }
}

void releaseKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT: 
        case GLUT_KEY_RIGHT: 
            deltaAngle = 0.0f; break;
        case GLUT_KEY_UP: 
        case GLUT_KEY_DOWN: 
            deltaMove = 0; break;
    }
}

// Pengaturan Cahaya
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 10.0f, 20.0f, 10.0f, 1.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void lighting() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init(void) {
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0.1, 0.1, 0.1, 1.0); // Warna background agak gelap agar shading terlihat
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 3D Rangka Primitive");
    
    glutIgnoreKeyRepeat(1);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);
    
    lighting();
    init();
    
    glutMainLoop();
    return(0);
}
