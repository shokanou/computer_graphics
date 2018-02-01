#include "math.h"
#include "gl/glut.h"
#define PI 3.141592653589793238462643383279


void fivestar(float x0,float y0,float d)  //draw the fivestar
{
	float d0=d*sin(PI/10)/cos(PI/5); 

	glPolygonMode(GL_FRONT, GL_FILL);

	glColor3f(1.0,1.0,0); //color as yellow

	glEnable(GL_POLYGON_SMOOTH);
	glBegin(GL_POLYGON);

	glVertex2f(x0+d0*cos(3*PI/10),y0+d0*sin(3*PI/10)); //axis of every vertex using a circle to figure out
	glVertex2f(x0-d*cos(PI/10),y0+d*sin(PI/10));
	glVertex2f(x0-d0*cos(PI/10),y0-d0*sin(PI/10));
	glVertex2f(x0-d*sin(PI/5),y0-d*cos(PI/5));
	glVertex2f(x0,y0-d0);
	glVertex2f(x0+d*sin(PI/5),y0-d*cos(PI/5));
	glVertex2f(x0+d0*cos(PI/10),y0-d0*sin(PI/10));
	glVertex2f(x0+d*cos(PI/10),y0+d*sin(PI/10));
	glVertex2f(x0+d0*cos(3*PI/10),y0+d0*sin(3*PI/10));
	glEnd();
 
	glBegin(GL_POLYGON);
 
	glVertex2f(x0,y0+d);
	glVertex2f(x0+d0*cos(3*PI/10),y0+d0*sin(3*PI/10));
	glVertex2f(x0-d0*cos(3*PI/10),y0+d0*sin(3*PI/10));
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);  
	glColor3f(1, 0, 0);  //color as red
	glBegin(GL_QUADS);  //draw the preface of the flag
	glVertex3f(-0.5, 0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glEnd();

	fivestar(-0.3,0.3,0.08);
	float x=-0.3;
	float y=0.3;
	float d=0.1;
	float l=0.20;
	float angle=PI/5;

	for (int i=1; i<5; i++)//use translation,strech and for-loop to draw the last 4 fivestars
	{
		float x0,y0;
		glScalef(0.4f,0.4f,0.0f);//strech
		x0=x+l*sin(angle*i);
		y0=y+l*cos(angle*i);
		fivestar(x0,y0,d);

		glScalef(2.5f,2.5f,0.0f);
		glTranslatef(0.0f,0.12f,0.0f); //translation
	}

	glFlush();
	glutSwapBuffers();
}

int main (int argc,  char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Simple GLUT App");

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}