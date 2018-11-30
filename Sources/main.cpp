#ifdef _WIN32
#include <freeglut.h>
#endif
#ifdef _linux_
#include <GL/freeglut.h>
#endif

#include <iostream>
#include "../SOIL/SOIL.h"
#include <GL/glu.h>

using namespace std;

GLfloat eye[3];// Откуда мы смотрим
GLfloat center[3];// Куда мы смотрим

void initWithCoder() {
    eye[0] = 0.001f;
    eye[1] = 0.7f;
    eye[2] = 0.001f;

    center[0] = 0.0f;
    center[1] = 0.0f;
    center[2] = 0.0f;
}


void LoadTextures() {
    GLuint tex_2d = SOIL_load_OGL_texture("field.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                          SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB |
                                          SOIL_FLAG_COMPRESS_TO_DXT);


    if (0 == tex_2d) {
        printf("SOIL loading error: '%s'\n", SOIL_last_result());
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void Initialize() {
    glEnable(GL_TEXTURE_2D);
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(110, 1366.0f / 768.0f, 50.0f, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], 0.0, 1.0, 0.0);
    glRotated(-45, 0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);//фронт1 | левая
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(1.0, -0.0, 1.0);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3d(1.0, -0.0, -1.0);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3d(-1.0, -0.0, -1.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3d(-1.0, -0.0, 1.0);
    glEnd();
    glFlush();

    glutSwapBuffers();
}

void key(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
        default:
            break;
    }
}


int main(int argc, char *argv[]) {
    initWithCoder();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1376, 768);
    glutCreateWindow("Monopoly");
    glutFullScreen();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    Initialize();
    LoadTextures();
    glutMainLoop();
    return 0;
}
