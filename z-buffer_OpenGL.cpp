#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat xRotated, yRotated, zRotated;

void displayTetrahedron(void) {
    glMatrixMode(GL_MODELVIEW);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0, 0.0, -8.0);
    glRotatef(xRotated, 1.0, 0.0, 0.0);
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    glRotatef(zRotated, 0.0, 0.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
    glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
    glColor3f(0, 1, 0); glVertex3f(1, 0, 1);
    glColor3f(0, 0, 1); glVertex3f(0, 0, -1.4);
    glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
    glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
    glEnd();
    
    glFlush();
}

void reshapeTetrahedron(int x, int y) {
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
    glViewport(0, 0, x, y);
}

void idleTetrahedron(void) {
    xRotated += 1.0;
    yRotated += 1.0;
    zRotated += 1.0;
    displayTetrahedron();
}


int main (int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tetrahedron Rotating Animation (Z-Buffer)");
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    xRotated = 33.0;
    yRotated = 40.0;
    zRotated = 30.0;

    glClearColor(255, 255, 255, 255);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glutDisplayFunc(displayTetrahedron);
    glutReshapeFunc(reshapeTetrahedron);
    glutIdleFunc(idleTetrahedron);

    glutMainLoop();
    
    return 0;
}