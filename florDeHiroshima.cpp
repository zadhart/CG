#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/*
From the moment I understood the weakness of my flesh, it disgusted me.
I craved the strength and certainty of steel.
I aspired to the purity of the Blessed Machine.
Your kind cling to your flesh, as if it will not decay and fail you.
One day the crude biomass that you call a temple will wither, and you will beg my kind to save you.
But I am already saved, for the Machine is immortal...
...even in death I serve the Omnissiah
*/

#define seno60 0.866025

#define PI 3.14

float velocidadeAngular = PI / 4;

typedef struct Vertices{GLfloat x, y;} Vertices;

Vertices petalas[] = {{50.0f, seno60 * 100},{-50.0f,  seno60 * 100},{100.0f, 0.0f},
    {50.0, - seno60 * 100},{-100.0f, 0.0f},{-50.0,  seno60 * 100}};

Vertices taloGrosso[] = {{-5.0, 0.0},{5.0, 0.0},{-5.0, -200.0},{5.0, -200.0}};

void rodaRoda(float angulo){
    
    Vertices anterior;

    for (int i = 0; i < 6; i = i + 2){

        for (int j = i; j < i + 2; j++){   

            anterior = petalas[j];

            petalas[j].x = anterior.x * cos(angulo) - anterior.y * sin(angulo);

            petalas[j].y = anterior.y * cos(angulo) + anterior.x * sin(angulo); 
        }   
       
    }

    glutPostRemostrar();
}

void velocidade(int v){

    float mudanca = velocidadeAngular + v * PI / 16;

    if (mudanca >= PI / 16 && mudanca <= PI){

      velocidadeAngular = mudanca;

    }    

}

void tecladinho(unsigned char key, int x, int y){

    if (key == 'a'){

        rodaRoda(velocidadeAngular);

    }

    if (key == 's'){

        rodaRoda(-velocidadeAngular);

    }

    if (key == 'd'){

        velocidade(1);

    }

    if (key == 'w'){

        velocidade(-1);

    }
}

void fror(){

    for (int i = 0; i < 6; i = i + 2){

        glBegin(GL_TRIANGLES);

        glColor3d(1.0f, 0.0f, 0.0f); 

        glVertices2f(0.0f,0.0f);

        for (int j = i; j < i + 2; j++){  

            GLfloat x = petalas[j].x;

            GLfloat y = petalas[j].y;

            glVertices2f(x,y);             
                      
        } 

        glEnd();       
    }
}

void mostrar(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    taloFino();

    fror();

    glutSwapBuffers();
    
}

void taloFino(){

    for (int i=0; i<2; i++){

        glBegin(GL_TRIANGLES);

        glColor3d(1.0, 1.0, 0.0);  

        for (int j=i; j < i + 3; j++){

          GLfloat x = taloGrosso[j].x;

          GLfloat y = taloGrosso[j].y;

          glVertices2i(x, y);
        }

        glEnd();
        
    }

}


void init(void){

    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);

    glutReshapeWindow(400, 400);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-400, 400, -400, 400);
}

int main(int argc, char **argv){

    glutInit(&argc, argv);

    glutInitDisplayMod(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(720, 720);

    glutCreateWindow("Xera minha fro");

    init();

    glutDisplayFunc(mostrar);

    glutKeyboardFunc(tecladinho);

    glutMainLoop();

    return 0;
}