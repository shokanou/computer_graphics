// glutEx1.cpp : 定义控制台应用程序的入口点。   
//   


#include <stdlib.h>   
#include <stdio.h>   
#include <string.h>   
#include "gl\glut.h"   
#define BUFSIZE 512   
GLuint selectBuf[BUFSIZE];

GLuint select_ob;

float fTranslate;
float fRotate = 156.5f;
float fScale = 1.0f;    // set inital scale value to 1.0f   

bool bPersp = true;
bool bAnim = false;
bool bWire = false;

int wHeight = 0;
int wWidth = 0;

GLint dl = 0;

void Draw_Leg();

int  drawMode = 0;

extern void drawNaive();
extern void drawVA();

extern GLint Gen3DObjectList();

void drawDL() {
	glCallList(dl);
}


void drawBunny()
{
	glRotatef(90, 1, 0, 0);
	glScalef(2, 2, 2);
	if (drawMode == 0)
		drawNaive();
	else if (drawMode == 1)
		drawVA();
	else
		drawDL();
}

void Draw_Desk();

void Draw_Triangle(GLenum mode) // This function draws a triangle with RGB colors   
{
	float theColor[] = { 1.0f, 0.0f, 0.0f };
	float white[] = { 1.0f, 1.0f, 1.0f };
	float noColor[] = { 0.0f, 0.0f, 0.0f };

	if (mode == GL_SELECT) glLoadName(1);
	if (select_ob == 1)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(-1, -1, 5.5);
	drawBunny();
	glPopMatrix();
	//glutSwapBuffers();
	//glDisable(GL_COLOR_MATERIAL);

	if (mode == GL_SELECT) glLoadName(2);
	if (select_ob == 2)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(0, -1, 5.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(3);
	if (select_ob == 3)
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(1, -1, 5.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(4);
	if (select_ob == 4) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(-1, 1, 5.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(5);
	if (select_ob == 5) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(0, 1, 5.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(6);
	if (select_ob == 6) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(1, 1, 5.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(7);
	if (select_ob == 7) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(-1, 0, 5.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(8);
	if (select_ob == 8) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(0, 0, 5.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(9);
	if (select_ob == 9) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(1, 0, 5.5);
	drawBunny();
	glPopMatrix();

	//###################################   

	if (mode == GL_SELECT) glLoadName(10);
	if (select_ob == 10) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(-1, -1, 7.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(11);
	if (select_ob == 11) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(0, -1, 7.5);
	drawBunny();
	glPopMatrix();


	if (mode == GL_SELECT) glLoadName(12);
	if (select_ob == 12) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(1, -1, 7.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(13);
	if (select_ob == 13) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(-1, 1, 7.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(14);
	if (select_ob == 14) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(0, 1, 7.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(15);
	if (select_ob == 15) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(1, 1, 7.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(16);
	if (select_ob == 16) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(-1, 0, 7.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(17);
	if (select_ob == 17) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(0, 0, 7.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(18);
	if (select_ob == 18) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glPushMatrix();
	glTranslatef(1, 0, 7.5);
	drawBunny();
	glPopMatrix();

	if (mode == GL_SELECT) glLoadName(20);
	if (select_ob == 20) 	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, theColor);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
	else
	{
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noColor);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	Draw_Desk();
}

void Draw_Desk()
{
	glPushMatrix();
	glTranslatef(0, 0, 3.5);
	glScalef(5, 4, 1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 1, 1.5);
	Draw_Leg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 1, 1.5);
	Draw_Leg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, -1, 1.5);
	Draw_Leg();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, -1, 1.5);
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
	glViewport(0, 0, width, height);                       // Reset The Current Viewport   

	glMatrixMode(GL_PROJECTION);                        // Select The Projection Matrix   
	glLoadIdentity();                                   // Reset The Projection Matrix   

	float whRatio = (GLfloat)width / (GLfloat)height;
	if (bPersp) {
		gluPerspective(45.0f, whRatio, 0.1f, 100.0f);
		//glFrustum(-3, 3, -3, 3, 3,100);   
	}
	else {
		glOrtho(-3, 3, -3, 3, -100, 100);
	}

	glMatrixMode(GL_MODELVIEW);                         // Select The Modelview Matrix   
}

void reshape(int width, int height)
{
	if (height == 0)                                      // Prevent A Divide By Zero By   
	{
		height = 1;                                       // Making Height Equal One   
	}

	wHeight = height;
	wWidth = width;

	updateView(wHeight, wWidth);
}

void idle()
{
	glutPostRedisplay();
}

float center[] = { 0, -0.8, -6 };
float eye[] = { 0, 1.2, 2 };

void key(unsigned char k, int x, int y)
{
	switch (k)
	{
	case 27:
	case 'q': {exit(0); break; }
	case 'p': {bPersp = !bPersp; break; }

	case ' ': {bAnim = !bAnim; break; }
	case 'o': {bWire = !bWire; break; }
	case '0': {drawMode++; drawMode %= 3; break; }

	case 'a': {
				  eye[0] -= 0.2f;
				  center[0] -= 0.2f;
				  break;
	}
	case 'd': {
				  eye[0] += 0.2f;
				  center[0] += 0.2f;
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
	}

	updateView(wHeight, wWidth);
}

void getFPS()
{
	static int frame = 0, time, timebase = 0;
	static char buffer[256];

	char mode[64];
	if (drawMode == 0)
		strcpy(mode, "naive");
	else if (drawMode == 1)
		strcpy(mode, "display listVA");
	else
		strcpy(mode, "display list");


	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(buffer, "FPS:%4.2f %s",
			frame*1000.0 / (time - timebase),mode);
		timebase = time;
		frame = 0;
	}

	//glutSetWindowTitle(buffer);
	char *c;
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);// 选择投影矩阵
	glPushMatrix();// 保存原矩阵
	glLoadIdentity();// 装入单位矩阵
	glOrtho(0, 480, 0, 480, -1, 1);// 位置正投影
	glMatrixMode(GL_MODELVIEW);// 选择Modelview矩阵
	glPushMatrix();// 保存原矩阵
	glLoadIdentity();// 装入单位矩阵*/
	glRasterPos2f(10, 10);
	for (c = buffer; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
	glMatrixMode(GL_PROJECTION);// 选择投影矩阵
	glPopMatrix();// 重置为原保存矩阵
	glMatrixMode(GL_MODELVIEW);// 选择Modelview矩阵
	glPopMatrix();// 重置为原保存矩阵
	glEnable(GL_DEPTH_TEST);
}

void redraw()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                                   // Reset The Current Modelview Matrix   

	gluLookAt(eye[0], eye[1], eye[2],
		center[0], center[1], center[2],
		0, 1, 0);               // 场景（0，0，0）的视点中心 (0,5,50)，Y轴向上   

	if (bWire) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_pos[] = { 5, 5, 5, 1 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white);
	glEnable(GL_LIGHT0);

	//  glTranslatef(0.0f, 0.0f,-6.0f);         // Place the triangle at Center   
	glRotatef(fRotate, 0, 1.0f, 0);         // Rotate around Y axis   
	glRotatef(-90, 1, 0, 0);
	glScalef(0.2, 0.2, 0.2);
	Draw_Triangle(GL_RENDER);                       // Draw triangle   

	if (bAnim) fRotate += 0.5f;

	getFPS();
	glutSwapBuffers();
}


void startPicking(int button, int state, int x, int y)
{
	GLint viewport[4];
	glSelectBuffer(BUFSIZE, selectBuf);
	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
		return;
	glRenderMode(GL_SELECT);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glGetIntegerv(GL_VIEWPORT, viewport);
	gluPickMatrix(x, viewport[3] - y, 5, 5, viewport);
	gluPerspective(45.0f, (GLfloat)(viewport[2] - viewport[0]) / (GLfloat)(viewport[3] - viewport[1]), 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glInitNames();
	glPushName(0);

}

void processHits(GLint hits, GLuint buffer[])
{
	unsigned int i, j;
	GLuint names, *ptr, minZ, *ptrNames, numberOfNames;

	printf("hits = %d\n", hits);
	ptr = (GLuint *)buffer;
	minZ = 0xffffffff;

	for (i = 0; i<hits; i++) {
		names = *ptr;
		ptr++;

		if (*ptr < minZ) {
			numberOfNames = names;
			minZ = *ptr;
			ptrNames = ptr + 2;
		}

		ptr += names + 2;
	}

	printf("The closest hit names are ");
	ptr = ptrNames;
	for (j = 0; j<numberOfNames; j++, ptr++) {
		printf("%d ", *ptr);
		select_ob = *ptr;
		printf("the select ob %d\n", select_ob);
	}
	printf("\n");

}

void stopPicking()
{
	int hits;
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
	hits = glRenderMode(GL_RENDER);
	if (hits != 0)
		processHits(hits, selectBuf);
	glMatrixMode(GL_MODELVIEW);

}

void picknow(int button, int state, int x, int y)
{
	startPicking(button, state, x, y);
	Draw_Triangle(GL_SELECT);
	stopPicking();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(480, 480);
	int windowHandle = glutCreateWindow("Simple GLUT App");

	glutDisplayFunc(redraw);
	glutMouseFunc(picknow);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	dl = Gen3DObjectList();

	glutMainLoop();
	return 0;
}