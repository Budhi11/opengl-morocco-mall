#include <windows.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <vector>
#include <cmath>

// budhi kun
// visi foya misi foya

void init(void);
void tampil(void);
void ukuran(int, int);
void ornamen_pagar(int cx);

// mouse
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

// keyboard
void keyboard(unsigned char, int, int);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,700);
    glutInitWindowPosition(250,80);
    glutCreateWindow("MOROCCO MALL");
    init();

    // transparan
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutMainLoop();
    return 0;
}

void init(void){
    glClearColor(62/255.f,185/255.f,255/255.f,1.0);
    glMatrixMode(GL_PROJECTION);

    // lighting
    // glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);

    glEnable(GL_DEPTH_TEST);
    is_depth=1;

    glMatrixMode(GL_MODELVIEW);

    glPointSize(9.0);
    glLineWidth(6.0f);
}

void tampil(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // mouse
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex3f(-350, -50, -140);
        glVertex3f(350, -50, -140);
        glVertex3f(350, -50, 100);
        glVertex3f(-350, -50, 100);
    glEnd();

    // dinding pele
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(-280, -50, 30);
        glVertex3f(-200, -50, 50);
        glVertex3f(-200, 70, 50);
        glVertex3f(-280, 70, 30);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-180, -50, 55);
        glVertex3f(-50, -50, 55);
        glVertex3f(-50, 70, 55);
        glVertex3f(-180, 70, 55);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(-280, -50, 30);
        glVertex3f(-280, -50, -60);
        glVertex3f(-280, 70, -60);
        glVertex3f(-280, 70, 30);
    glEnd();

    //dinding deva
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(120, -50, 50);
        glVertex3f(220, -50, 25);
        glVertex3f(220, 70, 25);
        glVertex3f(120, 70, 50);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(-30, -50, 50);
        glVertex3f(120, -50, 50);
        glVertex3f(120, 70, 50);
        glVertex3f(-30, 70, 50  );
    glEnd();
        glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(-280, -50, -60);
        glVertex3f(-190, -50, -60);
        glVertex3f(-190, 70, -60);
        glVertex3f(-280, 70, -60);
    glEnd();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
        glVertex3f(-170, -50, -60);
        glVertex3f(-130, -50, -60);
        glVertex3f(-130, 70, -60);
        glVertex3f(-170, 70, -60);
    glEnd();

    // dinding jek
    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);
        glVertex3f(220, -50, -30);
        glVertex3f(120, -50, -50);
        glVertex3f(120, 70, -50);
        glVertex3f(220, 70, -30);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);
        glVertex3f(120, -50, -50);
        glVertex3f(-30, -50, -50);
        glVertex3f(-30, 70, -50);
        glVertex3f(120, 70, -50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.8);
        glVertex3f(-50, -50, -50);
        glVertex3f(-130, -50, -60);
        glVertex3f(-130, 70, -60);
        glVertex3f(-50, 70, -50);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();

    // atap
    glColor3f(0.85,0.85,0.85);
    glBegin(GL_POLYGON);
        glVertex3d(220, 70, 25);
        glVertex3d(120, 70, 50);
        glVertex3d(-30, 70, 50);
        glVertex3d(-50, 70, 55);
        glVertex3d(-180, 70, 55);
        glVertex3d(-200, 70, 50);
        glVertex3d(-280, 70, 40);
        glVertex3d(-280, 70, -60);
        glVertex3d(-130, 70, -60);
        glVertex3d(-50, 70, -50);
        glVertex3d(120, 70, -50);
        glVertex3d(220, 70, -30);
    glEnd();
}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'w':
        case 'W':
            glTranslatef(0.0,0.0,3.0);
            break;
        case 'd':
        case 'D':
            glTranslatef(3.0,0.0,0.0);
            break;
        case 's':
        case 'S':
            glTranslatef(0.0,0.0,-3.0);
            break;
        case 'a':
        case 'A':
            glTranslatef(-3.0,0.0,0.0);
            break;
        case '7':
            glTranslatef(0.0,3.0,0.0);
            break;
        case '9':
            glTranslatef(0.0,-3.0,0.0);
            break;
        case '2':
            glRotatef(2.0,1.0,0.0,0.0);
            break;
        case '8':
            glRotatef(-2.0,1.0,0.0,0.0);
            break;
        case '6':
            glRotatef(2.0,0.0,1.0,0.0);
            break;
        case '4':
            glRotatef(-2.0,0.0,1.0,0.0);
            break;
        case '1':
            glRotatef(2.0,0.0,0.0,1.0);
            break;
        case '3':
            glRotatef(-2.0,0.0,0.0,1.0);
            break;
        case '5':
            if(is_depth){
                is_depth=0;
                glDisable(GL_DEPTH_TEST);
            } else{
                is_depth=1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y + xrot;
    } else{
        mouseDown = false;
    }
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x-xdiff;
        xrot = y+ydiff;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(130.0, lebar/tinggi,5.0,1000.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
