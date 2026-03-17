// Nama	: Yuma Hazza Yuditama
// NIM	: 24060124120035
// Lab	: A1

#include <gl/glut.h>
#include <math.h>

#define PI 3.1415926535898 

void drawCircle(float x, float y, float radius, int segments){
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++){
        float angle = 2.0f * PI * i / segments;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    
    glEnd();
}

void RenderLingkungan(void){
    glClear(GL_COLOR_BUFFER_BIT);

    // --- MATAHARI ---
    glPushMatrix(); 
    	glColor3f(1.0f, 0.8f, 0.0f); // Warna kuning
    	drawCircle(0.3f, 0.7f, 0.15f, 100);
    glPopMatrix(); 
    // --- MATAHARI END ---

    // --- AWAN ---
    glPushMatrix();
    	glColor3f(1.0f, 1.0f, 1.0f); // Warna putih
    	drawCircle(-0.6f, 0.65f, 0.1f, 50);
    	drawCircle(-0.5f, 0.67f, 0.12f, 50);
    	drawCircle(-0.4f, 0.65f, 0.1f, 50);
    
    	glColor3f(1.0f, 1.0f, 1.0f); // Warna putih
    	drawCircle(-0.1f, 0.73f, 0.1f, 50);
    	drawCircle(0.0f, 0.75f, 0.12f, 50);
    	drawCircle(0.1f, 0.73f, 0.1f, 50);
    
    	glColor3f(1.0f, 1.0f, 1.0f); // Warna putih
    	drawCircle(0.6f, 0.59f, 0.1f, 50);
    	drawCircle(0.5f, 0.61f, 0.12f, 50);
    	drawCircle(0.4f, 0.59f, 0.1f, 50);
    glPopMatrix();
    // --- AWAN END ---
    
    
	// --- JALAN ASPAL ---
	glPushMatrix();
		glTranslatef(0.0f, -0.3f, 0.0f);
		glColor3f(0.1f, 0.1f, 0.1f);
		glBegin(GL_QUADS);
			glVertex2f(1.0f, -0.4f);
			glVertex2f(1.0f, -0.1f);
			glVertex2f(-1.0f, -0.1f);
			glVertex2f(-1.0f, -0.4f);
		glEnd();
	
    	// --- MARKA JALAN---
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
			glVertex2f(1.0f, -0.27f);
			glVertex2f(1.0f, -0.22f);
			glVertex2f(0.8f, -0.22f);
			glVertex2f(0.8f, -0.27f);
		
			glVertex2f(0.65f, -0.27f);
			glVertex2f(0.65f, -0.22f);
			glVertex2f(0.3f, -0.22f);
			glVertex2f(0.3f, -0.27f);
		
			glVertex2f(0.15f, -0.27f);
			glVertex2f(0.15f, -0.22f);
			glVertex2f(-0.25f, -0.22f);
			glVertex2f(-0.25f, -0.27f);
		
			glVertex2f(-0.85f, -0.27f);
			glVertex2f(-0.85f, -0.22f);
			glVertex2f(-0.47f, -0.22f);
			glVertex2f(-0.47f, -0.27f);
		
			glVertex2f(-0.98f, -0.27f);
			glVertex2f(-0.98f, -0.22f);
			glVertex2f(-1.0f, -0.22f);
			glVertex2f(-1.0f, -0.27f);
		glEnd();
	glPopMatrix();
	// --- JALAN END ---
    
    
    // --- STRUKTUR GEDUNG ---
    glPushMatrix();
    	glTranslatef(-0.6f, -0.4f, 0.0f);

    	// Body Gedung
    	glColor3f(0.82f, 0.75f, 0.65f); 
    	glBegin(GL_QUADS); 
	        glVertex2f(-0.3f, 0.0f);
	        glVertex2f(0.3f, 0.0f);
	        glVertex2f(0.3f, 0.8f);
	        glVertex2f(-0.3f, 0.8f);
    	glEnd(); 

    	// Atap
    	glColor3f(0.35f, 0.25f, 0.2f);
    	glBegin(GL_QUADS);
	        glVertex2f(-0.35f, 0.8f);
	        glVertex2f(0.35f, 0.8f);
	        glVertex2f(0.3f, 0.85f);
	        glVertex2f(-0.3f, 0.85f);
    	glEnd();

    	// Pintu Utama
    	glPushMatrix(); 
    		glColor3f(0.25f, 0.15f, 0.1f);
    		glBegin(GL_QUADS);
			    glVertex2f(-0.06f, 0.0f);
			    glVertex2f(0.06f, 0.0f);
			    glVertex2f(0.06f, 0.2f);
			    glVertex2f(-0.06f, 0.2f);
    		glEnd();
    	glPopMatrix();
    	
    	// Jendela
    	glColor3f(0.6f, 0.7f, 0.75f);
    	for (float y = 0.65f; y >= 0.35f; y -= 0.15f){
        	// Jendela Sisi Kiri
        	glPushMatrix();
        		glTranslatef(-0.15f, y, 0.0f);
        		glBegin(GL_QUADS);
	            	glVertex2f(-0.05f, -0.05f);
	            	glVertex2f(0.05f, -0.05f);
	            	glVertex2f(0.05f, 0.05f);
	            	glVertex2f(-0.05f, 0.05f);
        		glEnd();
        	glPopMatrix();
        	// Jendela Sisi Kanan
        	glPushMatrix();
        		glTranslatef(0.15f, y, 0.0f);
        		glBegin(GL_QUADS);
            		glVertex2f(-0.05f, -0.05f);
            		glVertex2f(0.05f, -0.05f);
            		glVertex2f(0.05f, 0.05f);
            		glVertex2f(-0.05f, 0.05f);
        		glEnd();
        	glPopMatrix();
    	}

	glPopMatrix(); 
	glFlush(); 
	// --- GEDUNG END ---
	
	
	// --- POHON ---
    glPushMatrix();
    	glTranslatef(0.5f, -0.5f, 0.0f);
    	
    	// Batang Pohon 
    	glColor3f(0.45f, 0.3f, 0.2f); 
    	glBegin(GL_QUADS);  
	        glVertex2f(-0.05f, 0.1f);
	        glVertex2f(0.05f, 0.1f);
	        glVertex2f(0.05f, 0.4f);
	        glVertex2f(-0.05f, 0.4f);
    	glEnd();

    	// Daun 
    	glColor3f(0.0f, 0.5f, 0.0f); 
    	drawCircle(0.0f, 0.5f, 0.2f, 50);   
    	drawCircle(-0.12f, 0.4f, 0.15f, 50); 
    	drawCircle(0.12f, 0.4f, 0.15f, 50);  

    glPopMatrix();
    glFlush();
    // --- POHON END ---
	
	
	// --- BODY MOBIL ---
    glPushMatrix();
    	glTranslatef(0.0f, -0.5f, 0.0f);
    	glScalef(0.5f, 0.5f, 1.0f);
    
	    // Body Bawah
	    glColor3f(0.8f, 0.2f, 0.2f);
	    glBegin(GL_QUADS);
	        glVertex2f(-0.5f, 0.0f);
	        glVertex2f(0.5f, 0.0f);
	        glVertex2f(0.6f, 0.25f);
	        glVertex2f(-0.6f, 0.25f);
    	glEnd();

    	// Atap Mobil 
    	glBegin(GL_QUADS);
	        glVertex2f(-0.3f, 0.25f);
	        glVertex2f(0.3f, 0.25f);
	        glVertex2f(0.2f, 0.45f);
	        glVertex2f(-0.2f, 0.45f);
    	glEnd();

    	// Jendela
    	glPushMatrix();
    		glColor3f(0.7f, 0.9f, 1.0f);
    		glBegin(GL_QUADS);
        		glVertex2f(-0.15f, 0.28f);
        		glVertex2f(0.15f, 0.28f);
        		glVertex2f(0.12f, 0.42f);
        		glVertex2f(-0.12f, 0.42f);
    		glEnd();
    	glPopMatrix();

	    // --- RODA ---
	    // Roda Belakang
	    glPushMatrix();
    		glTranslatef(-0.3f, 0.0f, 0.0f); // Translasi roda untuk roda belakang
    		glColor3f(0.2f, 0.2f, 0.2f);
    		drawCircle(0.0f, 0.0f, 0.1f, 50);
    	glPopMatrix();

    	// Roda Depan
    	glPushMatrix();
    		glTranslatef(0.3f, 0.0f, 0.0f); // Translasi roda untuk roda depan
    		glColor3f(0.2f, 0.2f, 0.22f); 
    		drawCircle(0.0f, 0.0f, 0.1f, 50);
    	glPopMatrix();
    	
    glPopMatrix();
    glFlush(); 
    // --- MOBIL END ---
    
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas Mobil dan Sekitarnya 2D - Yuma");
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); 
    glutDisplayFunc(RenderLingkungan);
    glutMainLoop();
    return 0;
}

