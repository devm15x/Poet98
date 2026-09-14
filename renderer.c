#include <stdio.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <windows.h>
#include "renderer.h"
float theta;
float camX = 0.0f;
float camY = 0.0f;
float camZ = -3.0f;

void project(){
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     gluPerspective(
                   60.0,          /* field of view */
                   800.0 / 600.0, /* aspect ratio */
                   0.1,           /* near clipping plane */
                   100.0           /* far clipping plane */    
     );

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
}
void init() {
     project();
     glEnable(GL_DEPTH_TEST);
     }
     
void draw(HDC buffer, float x, float y, float z, float pitch, float yaw) {     

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glRotatef(pitch, 1.0f, 0.0f, 0.0f);
            glRotatef(yaw, 0.0f, 1.0f, 0.0f);

            glTranslatef(x, y, z);     
            glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glPushMatrix ();
            glRotatef(theta, 1.0f, 0.0f, 0.0f);
            glRotatef(theta, 0.0f, 1.0f, 0.0f);
            glBegin (GL_TRIANGLES);
            
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (1.0f, 1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (-1.0f, -1.0f, 1.0f);

            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, -1.0f, -1.0f);

            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, 1.0f, 1.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, 1.0f, 1.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, 1.0f);

            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, -1.0f, -1.0f);
            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, -1.0f, -1.0f);
            glColor3f (1.0f, 1.0f, 0.0f);   glVertex3f (-1.0f, 1.0f, -1.0f);

            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (1.0f, 1.0f, 1.0f);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (-1.0f, 1.0f, 1.0f);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (-1.0f, 1.0f, -1.0f);
            glColor3f (0.0f, 1.0f, 1.0f);   glVertex3f (1.0f, 1.0f, -1.0f);

            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (-1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (-1.0f, -1.0f, 1.0f);
            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (-1.0f, -1.0f, -1.0f);
            glColor3f (1.0f, 0.0f, 1.0f);   glVertex3f (1.0f, -1.0f, -1.0f);
            glEnd ();
            glPopMatrix ();

            SwapBuffers (buffer);
            
            theta += 1.0f;
            Sleep (1);
}
