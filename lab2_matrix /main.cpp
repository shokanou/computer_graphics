// main.cpp : 定义控制台应用程序的入口点。
//

#include "glut.h"

float fTranslate;
float fRotate;
float fScale = 0.3f;

void Draw_Desk() // This function draws a desk using lines to demonstrate
{
	glBegin(GL_POLYGON);//first draw the top surface of the desk
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertex3f(-0.5f,0.4f, 0.0f);
	glVertex3f(-0.5f,-0.4f,0.0f);
	glVertex3f(0.5f,-0.4f, 0.0f);
	glVertex3f(0.5f,0.4f,0.0f);
	glEnd();

	glBegin(GL_POLYGON);//draw the down surface of the desk
	glVertex3f(-0.5f,0.4f,-0.2f);
	glVertex3f(-0.5f,-0.4f,-0.2f);
	glVertex3f(0.5f,-0.4f,-0.2f);
	glVertex3f(0.5f,0.4f,-0.2f);
	glEnd();

	glBegin(GL_LINES);//line up two drawn surface
	glVertex3f(-0.5f,0.4f, 0.0f);
	glVertex3f(-0.5f,0.4f,-0.2f);
	glEnd();

	glBegin(GL_LINES);//line up two drawn surface
	glVertex3f(0.5f,0.4f, 0.0f);
	glVertex3f(0.5f,0.4f,-0.2f);
	glEnd();

	glBegin(GL_LINES);//line up two drawn surface
	glVertex3f(-0.5f,-0.4f, 0.0f);
	glVertex3f(-0.5f,-0.4f,-0.2f);
	glEnd();

	glBegin(GL_LINES);//line up two drawn surface
	glVertex3f(0.5f,-0.4f, 0.0f);
	glVertex3f(0.5f,-0.4f,-0.2f);
	glEnd();

	glBegin(GL_POLYGON);//draw the first leg of the desk
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertex3f(-0.4f,-0.1f, -0.2f);
	glVertex3f(-0.4f,-0.3f,-0.2f);
	glVertex3f(-0.2f,-0.3f,-0.2f);
	glVertex3f(-0.2f,-0.1f,-0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertex3f(-0.4f,-0.1f, -0.8f);
	glVertex3f(-0.4f,-0.3f,-0.8f);
	glVertex3f(-0.2f,-0.3f,-0.8f);
	glVertex3f(-0.2f,-0.1f,-0.8f);
	glEnd();//first leg

	glBegin(GL_LINES) ;
	glVertex3f(-0.4f,-0.1f, -0.2f);
	glVertex3f(-0.4f,-0.1f, -0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(-0.4f,-0.3f,-0.2f);
	glVertex3f(-0.4f,-0.3f,-0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(-0.2f,-0.3f,-0.2f);
	glVertex3f(-0.2f,-0.3f,-0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(-0.2f,-0.1f,-0.2f);
	glVertex3f(-0.2f,-0.1f,-0.8f);
	glEnd();//1st

	glBegin(GL_POLYGON);//draw the second leg of the desk
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertex3f(-0.4f,0.1f, -0.2f);
	glVertex3f(-0.4f,0.3f,-0.2f);
	glVertex3f(-0.2f,0.3f,-0.2f);
	glVertex3f(-0.2f,0.1f,-0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertex3f(-0.4f,0.1f, -0.8f);
	glVertex3f(-0.4f,0.3f,-0.8f);
	glVertex3f(-0.2f,0.3f,-0.8f);
	glVertex3f(-0.2f,0.1f,-0.8f);
	glEnd();//second leg


	glBegin(GL_LINES) ;
	glVertex3f(-0.4f,0.1f, -0.2f);
	glVertex3f(-0.4f,0.1f, -0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(-0.4f,0.3f,-0.2f);
	glVertex3f(-0.4f,0.3f,-0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(-0.2f,0.3f,-0.2f);
	glVertex3f(-0.2f,0.3f,-0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(-0.2f,0.1f,-0.2f);
	glVertex3f(-0.2f,0.1f,-0.8f);
	glEnd();//2nd



	glBegin(GL_POLYGON);//draw the third leg of the desk
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertex3f(0.4f,0.1f, -0.2f);
	glVertex3f(0.4f,0.3f,-0.2f);
	glVertex3f(0.2f,0.3f,-0.2f);
	glVertex3f(0.2f,0.1f,-0.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertex3f(0.4f,0.1f, -0.8f);
	glVertex3f(0.4f,0.3f,-0.8f);
	glVertex3f(0.2f,0.3f,-0.8f);
	glVertex3f(0.2f,0.1f,-0.8f);
	glEnd();//third leg

	glBegin(GL_LINES) ;
	glVertex3f(0.4f,0.1f, -0.2f);
	glVertex3f(0.4f,0.1f, -0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(0.4f,0.3f,-0.2f);
	glVertex3f(0.4f,0.3f,-0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(0.2f,0.3f,-0.2f);
	glVertex3f(0.2f,0.3f,-0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(0.2f,0.1f,-0.2f);
	glVertex3f(0.2f,0.1f,-0.8f);
	glEnd();//3rd

	glBegin(GL_POLYGON);//draw the fourth leg of the desk
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertex3f(0.4f,-0.1f, -0.2f);
	glVertex3f(0.4f,-0.3f,-0.2f);
	glVertex3f(0.2f,-0.3f,-0.2f);
	glVertex3f(0.2f,-0.1f,-0.2f);
	glEnd();


	glBegin(GL_POLYGON);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertex3f(0.4f,-0.1f, -0.8f);
	glVertex3f(0.4f,-0.3f,-0.8f);
	glVertex3f(0.2f,-0.3f,-0.8f);
	glVertex3f(0.2f,-0.1f,-0.8f);
	glEnd();//fourth leg

		glBegin(GL_LINES) ;
	glVertex3f(0.4f,-0.1f, -0.2f);
	glVertex3f(0.4f,-0.1f, -0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(0.4f,-0.3f,-0.2f);
	glVertex3f(0.4f,-0.3f,-0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(0.2f,-0.3f,-0.2f);
	glVertex3f(0.2f,-0.3f,-0.8f);
	glEnd();

	glBegin(GL_LINES) ;
	glVertex3f(0.2f,-0.1f,-0.2f);
	glVertex3f(0.2f,-0.1f,-0.8f);
	glEnd();//4th




}

void reshape(int width, int height)
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

void idle()
{
	glutPostRedisplay();
}

void redraw()
{
// If want display in wireframe mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();									// Reset The Current Modelview Matrix
	
	glPushMatrix();
		glTranslatef(-2.0f, 0.0f,-6.0f);		// Place the triangle Left
		glTranslatef(0.0f, fTranslate, 0.0f);	// Translate in Y direction
		Draw_Desk();						// Draw the desk					
	glPopMatrix();

    glPushMatrix();
		glTranslatef(0.0f, 0.0f,-6.0f);			// Place the triangle at Center
		glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
		Draw_Desk();						// Draw triangle
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.0f, 0.0f,-6.0f);		// Place the triangle Right
		glScalef(fScale,fScale,fScale);	// scale again and again
		Draw_Desk();						// Draw desk					
	glPopMatrix();

	fTranslate += 0.005f;//control the transformation speed
	fRotate    += 0.5f;
	fScale     += 0.005f;

	if(fTranslate > 0.5f) fTranslate = 0.0f;
	if(fScale > 1.0f) fScale = 0.5f;//controlling 
	glutSwapBuffers();
}

int main (int argc,  char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(640,480);                                                  
	glutCreateWindow("Exercise2");

	glutDisplayFunc(redraw);
	glutReshapeFunc(reshape);		
	glutIdleFunc(idle);					

	glutMainLoop();

	return 0;
}


