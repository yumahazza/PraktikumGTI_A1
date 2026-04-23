#include <GL/glut.h>

static int shoulder = 0, elbow = 0, wrist = 0;

static int thumb = 0;
static int indexFinger = 0;
static int middleFinger = 0;
static int ringFinger = 0;
static int pinkyFinger = 0;

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(float x,float y,int angle)
{
    glPushMatrix();

    glTranslatef(x,y,0);
    glRotatef(angle,0,0,1);

    glTranslatef(0.3,0,0);

    glPushMatrix();
    glScalef(0.6,0.1,0.1);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();
}

void drawAxis()
{
    glLineWidth(2);

    glBegin(GL_LINES);

    // X axis (Merah)
    glColor3f(1,0,0);
    glVertex3f(-10,0,0);
    glVertex3f(10,0,0);

    // Y axis (Hijau)
    glColor3f(0,1,0);
    glVertex3f(0,-10,0);
    glVertex3f(0,10,0);

    // Z axis (Biru)
    glColor3f(0,0,1);
    glVertex3f(0,0,-10);
    glVertex3f(0,0,10);

    glEnd();

    glLineWidth(1);
}

void drawGrid()
{
    glColor3f(0.3,0.3,0.3);

    glBegin(GL_LINES);

    for(int i=-10;i<=10;i++)
    {
        // garis sejajar X
        glVertex3f(-10,i,0);
        glVertex3f(10,i,0);

        // garis sejajar Y
        glVertex3f(i,-10,0);
        glVertex3f(i,10,0);
    }

    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    
    drawGrid();
	drawAxis();
	glColor3f(1,1,1);

    // memposisikan ke tengah
    glTranslatef(-2.0,0.0,0.0);

    // ===== SHOULDER =====
    glTranslatef(-1.0,0.0,0.0);
    glRotatef((GLfloat)shoulder,0.0,0.0,1.0);
    glTranslatef(1.0,0.0,0.0);

    glPushMatrix();
    glScalef(2.0,0.4,1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // ===== ELBOW =====
    glTranslatef(1.0,0.0,0.0);
    glRotatef((GLfloat)elbow,0.0,0.0,1.0);
    glTranslatef(1.0,0.0,0.0);

    glPushMatrix();
    glScalef(2.0,0.4,1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // ===== WRIST (SENDI PERGELANGAN) =====
	glTranslatef(1.0,0.0,0.0);
	glRotatef((GLfloat)wrist,0.0,0.0,1.0);
	glTranslatef(0.4,0.0,0.0);

	// ===== PALM =====
	glPushMatrix();
	glScalef(0.8,0.4,0.6);
	glutWireCube(1.0);
	glPopMatrix();

    // ===== FINGERS =====	
    // Pinky finger
	drawFinger(0.50,-0.20,pinkyFinger);
	
	// Ring finger
	drawFinger(0.50,-0.05,ringFinger);
	
	// Middle finger
	drawFinger(0.50,0.10,middleFinger);
	
	// Index finger
	drawFinger(0.50,0.25,indexFinger);

    // ===== THUMB =====
    glPushMatrix();
    glTranslatef(0,0.35,0);
    glRotatef(thumb,0,0,1);
    glScalef(0.6,0.1,0.1);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(65.0,(GLfloat)w/(GLfloat)h,1.0,20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // kamera dimundurkan supaya muat
    glTranslatef(0.0,0.0,-7.0);
}

void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
		// ===== SHOULDER =====		
        case 's':
        shoulder=(shoulder+5)%360;
        break;

        case 'S':
        shoulder=(shoulder-5)%360;
        break;

		// ===== ELBOW =====
        case 'e':
        elbow=(elbow+5)%360;
        break;

        case 'E':
        elbow=(elbow-5)%360;
        break;
        
        // ===== WRIST / PALM =====
		case 'w':
		wrist += 5;
		break;

		case 'W':
		wrist -= 5;
		break;

        // ===== THUMB =====
        case 't':
        thumb+=5;
        break;

        case 'T':
        thumb-=5;
        break;

        // ===== MIDDLE =====
        case 'm':
        middleFinger+=5;
        break;

        case 'M':
        middleFinger-=5;
        break;

        // ===== RING =====
        case 'r':
        ringFinger+=5;
        break;

        case 'R':
        ringFinger-=5;
        break;

        // ===== PINKY =====
        case 'p':
        pinkyFinger+=5;
        break;

        case 'P':
        pinkyFinger-=5;
        break;
        
        // ===== INDEX =====
        case 'i':
        indexFinger+=5;
        break;

        case 'I':
        indexFinger-=5;
        break;

        case 27:
        exit(0);
    }

    glutPostRedisplay();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);

    glutCreateWindow("Tugas Praktikum - Tangan Lengkap");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}



