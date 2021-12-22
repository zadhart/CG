#include <GL/freeglut.h>

/*
From the moment I understood the weakness of my flesh, it disgusted me.
I craved the strength and certainty of steel.
I aspired to the purity of the Blessed Machine.
Your kind cling to your flesh, as if it will not decay and fail you.
One day the crude biomass that you call a temple will wither, and you will beg my kind to save you.
But I am already saved, for the Machine is immortal...
...even in death I serve the Omnissiah
*/

double xxx = 0; 

double yyy = 0; 

double zzz = 0;

double anY = 0;

int ano = 0;

int dia = 0;

void sozzzinho(){

    glPushMatrix();

    glColor3f(0.6, 0.5, 0.3);

    glRotatef(ano, 1, 0, 0);

    glRotatef(dia, 0, 0, 1);

    glutSolidSphere(0.5, 100, 100); 

    glPopMatrix();
}

void scheduleUpdate(int value){

    glutTimerFunc(10, scheduleUpdate, 1);

    dia++;

    ano++;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){

    switch (key){

        case 'w':

            glutTimerFunc(10, scheduleUpdate, 1);

            break;

        case 27:

            exit(0);

        default:

            break;
    }
}

void reshape(int w, int h){

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    gluPerspective(60, (double) w / h, 1, 20);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}


void planetaLua(){

    glPushMatrix();

    glColor3f(0.0, 0.0, 1.0);

    glRotatef(ano, 0, 1, 0);

    glTranslatef(2, 0, 0);

    glPushMatrix();

    glRotatef(dia, 0, 1, 0);

    glutSolidSphere(0.2, 100, 100); 

    glPopMatrix();

    glPushMatrix();

    glColor3f(0.6, 0.6, 0.6);

    glRotatef(1.5*dia, 0, 1, 0);

    glTranslatef(0.45, 0.1, 0);

    glutSolidSphere(0.05, 100, 100); 

    glPopMatrix();

    glPushMatrix();

    glColor3f(0.8, 0.4, 0.4);

    glRotatef(1.75*dia, 1, 1.2, 0);

    glTranslatef(0.35, 0, 0);

    glutSolidSphere(0.07, 100, 100); 

    glPopMatrix();

    glPopMatrix();
}


void sisteminha()
{
    sozzzinho();

    planetaLua();

    glPushMatrix();

    glColor3f(1.0, 0.9, 0.1);

    glRotatef(2*ano, 0, -1, 0);

    glTranslatef(-1, -0.05, 0);

    glRotatef(2*dia, 0, 1, 0);

    glutSolidSphere(0.1, 100, 80); 

    glPopMatrix();

    glPushMatrix();

    glColor3f(1.0, 0.0, 0.0);

    glRotatef(3*ano, 0, 1, 0);

    glTranslatef(1.1, 0.4, 1);

    glRotatef(2.5*dia, 0, 1, 0);

    glutSolidSphere(0.1, 100, 70);

    glPopMatrix();

    glPushMatrix();

    glColor3f(0.5, 0.1, 0.7);

    glRotatef(4*ano, 0, -1, 0);

    glTranslatef(-2, -0.4, 0);

    glRotatef(3*dia, 0, 1, 0);

    glutSolidSphere(0.2, 100, 90);

    glPopMatrix();

    glPushMatrix();

    glColor3f(0.1, 0.8, 0.1);

    glRotatef(-0.5*ano, 0, -1, 0);

    glTranslatef(-2.5, 0.4, -1);

    glRotatef(-1*dia, 0, 1, 0);

    glutSolidSphere(0.15, 100, 50); 

    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    glPushMatrix();

    glColor3f(255, 255, 255);

    glRotated(anY, 0, 1, 0);

    glTranslated(xxx, yyy, zzz);

    glutSolidSphere(0.05, 100, 100);

    glPopMatrix();

    sisteminha();

    glPopMatrix();

    glutSwapBuffers();
}


int main(int argc, char **argv){

    glClearColor(0.0, 0.0, 0.0, 0.0); 

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_COLOR_MATERIAL);

    glShadeModel(GL_SMOOTH);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(1280, 720);

    glutCreateWindow("Meu sistema");

    glutInitWindowPosition(100, 100);

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
