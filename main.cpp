#include <GL/glut.h>

bool spinI = false;
bool spinU = false;
GLfloat angle = 0.0f;
GLuint uList, iList, logoList;

// Define vertices for the U shape
GLfloat uVertices[] = {
    -0.5f, 0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.5f, 0.1f, 0.0f,
    0.3f, 0.1f, 0.0f,
    0.3f, 0.3f, 0.0f,
    0.5f, 0.3f, 0.0f,
    0.5f, 0.5f, 0.0f,
    -0.5f, 0.5f, 0.0f,
    -0.5f, 0.1f, 0.0f,
    -0.3f, 0.1f, 0.0f,
    -0.3f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.5f, 0.1f, 0.0f
};

// Define vertices for the I shape
GLfloat iVertices[] = {
    -0.1f, 0.5f, 0.0f,
    0.1f, 0.5f, 0.0f,
    0.1f, -0.5f, 0.0f,
    -0.1f, -0.5f, 0.0f,
    -0.1f, 0.5f, 0.0f,
    -0.1f, 0.3f, 0.0f,
    0.1f, 0.3f, 0.0f,
    0.1f, 0.5f, 0.0f
};

// Define display list for the U shape
uList = glGenLists(1);
glNewList(uList, GL_COMPILE);
glColor3f(1.0f, 0.0f, 0.0f); // Set the color to red
glBegin(GL_TRIANGLE_FAN);
for (int i = 0; i < 14; i++) {
    glVertex3f(uVertices[i*3], uVertices[i*3+1], uVertices[i*3+2]);
}
glEnd();
glColor3f(0.5f, 0.0f, 0.0f); // Set the color to a darker shade of red for the lines
glBegin(GL_LINE_STRIP);
for (int i = 1; i < 14; i++) {
    glVertex3f(uVertices[i*3], uVertices[i*3+1], uVertices[i*3+2]);
}
glEnd();
glEndList();

// Define display list for the I shape
iList = glGenLists(1);
glNewList(iList, GL_COMPILE);
glColor3f(1.0f, 0.0f, 0.0f); // Set the color to red
glBegin(GL_TRIANGLE_FAN);
for (int i = 0; i < 8; i++) {
    glVertex3f(iVertices[i*3], iVertices[i*3+1], iVertices[i*3+2]);
}
glEnd();
glColor3f(0.5f, 0.0f, 0.0f); // Set the color to a darker shade of red for the lines
glBegin(GL_LINE_STRIP);
for (int i = 1; i < 8; i++) {
    glVertex3f(iVertices[i*3], iVertices[i*3+1], iVertices[i*3+2]);
}
glEnd();
glEndList();

// Define display list for the combined logo
logoList = glGenLists(1);
glNewList(logoList, GL_COMPILE);
glCallList(uList); // Draw the U shape
glPushMatrix();
glTranslatef(0.25f, -0.75f, 0.0f); // Shift the I shape down and to the right to intersect with the U
glCallList(iList); // Draw the I shape
glPopMatrix();
glEndList();
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   // Draw block UI logo using display lists
   glCallList(logoList);
   // Rotate I letter if spinI is true
   if (spinI) {
      glTranslatef(0.0f, 0.5f, 0.0f);
      glRotatef(angle, 0.0f, 1.0f, 0.0f);
      glTranslatef(0.0f, -0.5f, 0.0f);
   }
   // Rotate U letter if spinU is true
   if (spinU) {
      glTranslatef(0.0f, -0.5f, 0.0f);
      glRotatef(angle, 0.0f, 1.0f, 0.0f);
      glTranslatef(0.0f, 0.5f, 0.0f);
   }
   glutSwapBuffers();
}

void spinISelected() {
   spinI = true;
   spinU = false;
}

void spinUSelected() {
   spinI = false;
   spinU = true;
}

void quitSelected() {
   exit(0);
}

void createMenu() {
   glutCreateMenu(menu);
   glutAddMenuEntry("Spin I", 1);
   glutAddMenuEntry("Spin U", 2);
   glutAddMenuEntry("Quit", 3);
   glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menu(int value) {
   switch(value) {
      case 1:
         spinISelected();
         break;
      case 2:
         spinUSelected();
         break;
      case 3:
         quitSelected();
         break;
   }
}

void update(int value) {
   angle += 1.0f;
   if (angle > 360.0f) {
      angle -= 360.0f;
   }
   glutPostRedisplay();
   glutTimerFunc(25, update, 0);
}


void init() {

// Define display list for the U shape
uList = glGenLists(1);
glNewList(uList, GL_COMPILE);
glColor3f(1.0f, 0.0f, 0.0f); // Set the color to red
glBegin(GL_TRIANGLE_FAN);
for (int i = 0; i < 14; i++) {
glVertex3f(uVertices[i3], uVertices[i3+1], uVertices[i3+2]);
}
glEnd();
glColor3f(0.5f, 0.0f, 0.0f); // Set the color to a darker shade of red for the lines
glBegin(GL_LINE_STRIP);
for (int i = 1; i < 14; i++) {
glVertex3f(uVertices[i3], uVertices[i3+1], uVertices[i3+2]);
}
glEnd();
glEndList();

// Define display list for the I shape
iList = glGenLists(1);
glNewList(iList, GL_COMPILE);
glColor3f(1.0f, 0.0f, 0.0f); // Set the color to red
glBegin(GL_TRIANGLE_FAN);
for (int i = 0; i < 8; i++) {
glVertex3f(iVertices[i3], iVertices[i3+1], iVertices[i3+2]);
}
glEnd();
glColor3f(0.5f, 0.0f, 0.0f); // Set the color to a darker shade of red for the lines
glBegin(GL_LINE_STRIP);
for (int i = 1; i < 8; i++) {
glVertex3f(iVertices[i3], iVertices[i3+1], iVertices[i3+2]);
}
glEnd();
glEndList();

// Create combined logo display list
logoList = glGenLists(1);
glNewList(logoList, GL_COMPILE);
glCallList(uList); // Draw the U shape
glPushMatrix();
glTranslatef(0.25f, -0.75f, 0.0f); // Shift the I shape down and to the right to intersect with the U
glCallList(iList); // Draw the I shape
glPopMatrix();
glEndList();
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(640, 480);
   glutCreateWindow("Block UI Animation");
   glutDisplayFunc(display);
   createMenu();
   glutTimerFunc(25, update, 0);
   init();
   glutMainLoop();
   return 0;
}

