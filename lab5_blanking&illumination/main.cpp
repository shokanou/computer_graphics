// glutEx1.cpp : 定义控制台应用程序的入口点。
//


#include <stdlib.h>
#include "glut.h"

float fTranslate;
float fRotate;
float fScale     = 1.0f;	// set inital scale value to 1.0f

bool bPersp = false;
bool bAnim = false;
bool bWire = false;
bool light = false;
bool color = false;

int wHeight = 0;
int wWidth = 0;
float mat_diffuse[] = {0.85f, 0.65f, 0.2f, 1.0f};//散射光
float mat_specular[] = {0.6f, 0.6f, 0.6f, 1.0f};//镜面光
float table_diffuse[]= {1.0f, 0.0f, 0.0f, 1.0f};
float table_specular[]= {1.0f, 0.0f, 0.0f, 1.0f};
float legf_diffuse[]= {0.0f, 1.0f, 0.0f, 1.0f};
float legf_specular[] = {0.0f, 1.0f, 0.0f, 1.0f};
float legs_diffuse[]= {1.0f, 1.0f, 0.0f, 1.0f};
float legs_specular[]= {1.0f, 1.0f, 0.0f, 1.0f};
float legt_diffuse[]= {0.0f, 1.0f, 1.0f, 1.0f};
float legt_specular[]= {0.0f, 1.0f, 1.0f, 1.0f};
float legfo_diffuse[]= {0.0f, 0.0f, 1.0f, 1.0f};
float legfo_specular[]= {0.0f, 0.0f, 1.0f, 1.0f};

void Draw_Leg();

void Draw_Triangle() // This function draws a triangle with RGB colors
{
	glPushMatrix();
	glTranslatef(0, 0, 4+1);
	glRotatef(90, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,50); 
	glutSolidTeapot(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 3.5);
	glScalef(5, 4, 1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, table_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, table_specular);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,50);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 1, 1.5);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, legf_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, legf_specular);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,50);
	Draw_Leg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 1, 1.5);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, legs_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, legs_specular);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,50);
	Draw_Leg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, -1, 1.5);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, legt_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, legt_specular);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,50);
	Draw_Leg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, -1, 1.5);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, legfo_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, legfo_specular);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,50);
	Draw_Leg();
	glPopMatrix();



}

void Draw_Leg()
{
	glScalef(1, 1, 3);
	glutSolidCube(1.0);
}

void updateView(int width, int height)
{
	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	float whRatio = (GLfloat)width/(GLfloat)height;
	if (bPersp) {
		gluPerspective(45.0f, whRatio,0.1f,100.0f);
		//glFrustum(-3, 3, -3, 3, 3,100);
	} else {
		glOrtho(-3 ,3, -3, 3,-100,100);
	}

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
}

void reshape(int width, int height)
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	wHeight = height;
	wWidth = width;

	updateView(wHeight, wWidth);
}

void idle()
{
	glutPostRedisplay();
}

float eye[] = {0, 0, 8};
float center[] = {0, 0, 0};
float position[] = {0, 1, 5, 1};
float lightDir[] = {0, 0, -1};
float spotangle = 4.1;

void key(unsigned char k, int x, int y)
{
	switch(k)
	{
	case 27:
	case 'q': {exit(0); break; }
	case 'p': {bPersp = !bPersp; break; }

	case ' ': {bAnim = !bAnim; break;}
	case 'o': {bWire = !bWire; break;}

	case 'a': {
		eye[0] += 0.2f;
		center[0] += 0.2f;
		break;
			  }
	case 'd': {
		eye[0] -= 0.2f;
		center[0] -= 0.2f;
		break;
			  }
	case 'w': {
		eye[1] -= 0.2f;
		center[1] -= 0.2f;
		break;
			  }
	case 's': {
		eye[1] += 0.2f;
		center[1] += 0.2f;
		break;
			  }
	case 'z': {
		eye[2] -= 0.2f;
		center[2] -= 0.2f;
		break;
			  }
	case 'c': {
		eye[2] += 0.2f;
		center[2] += 0.2f;
		break;
			  }
	case 'j':{
		position[0] -= 0.1f;
		break;
			 }
	case 'l':{
		position[0] += 0.1f;
		break;
			 }
	case 'i':{
		position[1] -= 0.1f;
		break;
			 }
	case 'k':{
		position[1] += 0.1f;
		break;
			 }
	case 'm':{
		light=!light;
		break;
			 }
	case'x':{
		spotangle+=2;
		break;
		}
	case'v':{
		spotangle-=2;
		break;
		}
	case'1':{
		lightDir[0]+=0.05f;
		break;
		}
	case'2':{
		lightDir[0]-=0.05f;
		break;
		}
	case'3':{
		lightDir[1]+=0.05f;
		break;
		}
	case'4':{
		lightDir[1]-=0.05f;
		break;
		}
	case'5':{
		lightDir[2]+=0.05f;
		break;
		}
	case'6':{
		lightDir[2]-=0.05f;
		break;
		}
	case 'b':{
		color = !color;
		break;
			 }
	}

	updateView(wHeight, wWidth);
}


void redraw()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();									// Reset The Current Modelview Matrix

	gluLookAt(eye[0], eye[1], eye[2],
		center[0], center[1], center[2],
		0, 1, 0);				// 场景（0，0，0）的视点中心 (0,5,50)，Y轴向上

	if (bWire) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
    GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat white1[] = { 1.0, 0.5, 0.5, 1.0 };
	GLfloat light_pos[] = {5,5,5,1};

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	if(!color)
		glLightfv(GL_LIGHT0, GL_AMBIENT, white);
	else
		glLightfv(GL_LIGHT0, GL_AMBIENT,white1);  
	glEnable(GL_LIGHT0);

	
	float light_ambient[] = {0.0f, 0.6f, 4.0f, 1.0f};
	float light_specular[] = {1.0,1.0,1.0,1.0};
	float light_ambient1[] = {0.5f, 0.4f, 2.0f, 1.0f};



	if(!color)
		glLightfv(GL_LIGHT1, GL_AMBIENT,light_ambient);  //设置环境光成分
	else
		glLightfv(GL_LIGHT1, GL_AMBIENT,light_ambient1);
    glLightfv(GL_LIGHT1, GL_SPECULAR,light_specular);                    //设置镜面光成分
	glLightfv(GL_LIGHT1, GL_DIFFUSE,white);                     //设置漫射光成分
	glLightfv(GL_LIGHT1, GL_POSITION,position);            //光源位置
	glLightf(GL_LIGHT1,  GL_SPOT_CUTOFF,spotangle);             //裁减角度
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDir);          //光源方向
	glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,1.0); 
	
    if(light == true)
	{
		glDisable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
	}
	else
	{
		glDisable(GL_LIGHT1);
		glEnable(GL_LIGHT0);
	}


	//	glTranslatef(0.0f, 0.0f,-6.0f);			// Place the triangle at Center
	glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
	glRotatef(-90, 1, 0, 0);
	glScalef(0.2, 0.2, 0.2);
	Draw_Triangle();						// Draw triangle

	if (bAnim) fRotate    += 0.5f;
	glutSwapBuffers();
}

int main (int argc,  char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(480,480);
	int windowHandle = glutCreateWindow("Simple GLUT App");

	glutDisplayFunc(redraw);
	glutReshapeFunc(reshape);	
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}


