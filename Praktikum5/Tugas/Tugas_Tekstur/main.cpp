/*
 * Tugas Praktikum 7 - Tekstur dengan Gambar
 * Membuat Kubus dengan 1 Gambar Tekstur untuk 6 Sisi
 * Author: Yuma Hazza Yuditama (24060124120035)
 */

#include <iostream>
#include <stdlib.h>

// Cheat code linker
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/glut.h> 

#include "Imageloader.h"
#include "Imageloader.cpp"

using namespace std;

const float BOX_SIZE = 7.0f; 
float _angle = 0;         

// Kembali jadi 1 variabel
GLuint _textureId;       

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: // Tekan Escape untuk keluar
		    exit(0);
	}
}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 
	             0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return textureId;
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
 
	Image* image = loadBMP("yey.bmp");
	_textureId = loadTexture(image);
	delete image;
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
 
	glTranslatef(0.0f, 0.0f, -20.0f);
  
	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
 
	GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
 	GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	 
 	glRotatef(-_angle, -1.0f, -1.0f, -1.0f);
 	
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0f, 1.0f, 1.0f); // Set warna dasar putih agar warna asli gambar keluar
 
    // Bind tekstur cukup SATU KALI di sini untuk semua sisi kubus
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
    // Mulai gambar 6 sisi
	glBegin(GL_QUADS);
	
	// --- Sisi Atas ---
	glNormal3f(0.0, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	 
	// --- Sisi Bawah ---
	glNormal3f(0.0, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	 
	// --- Sisi Kiri ---
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	 
	// --- Sisi Kanan ---
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);

	// --- Sisi Depan ---
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	
	// --- Sisi Belakang ---
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	 
	glEnd();
	glDisable(GL_TEXTURE_2D);
	 
	glutSwapBuffers();
}

void update(int value) {
	_angle += 1.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
 	glutTimerFunc(10, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Kubus 1 Tekstur Semua Sisi");
	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;
}
