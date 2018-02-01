// glutEx1.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <glut.h>

#define BITMAP_ID 0x4D42
#define TEXW 64
#define TEXH 64

float fTranslate;
float fRotate;
float fScale     = 1.0f;	// set inital scale value to 1.0f

bool bPersp = false;
bool bAnim = false;
bool bWire = false;
bool light1 = false;
bool teapot = false;

int wHeight = 0;
int wWidth = 0;
GLuint texture[3];
static  GLubyte tex[TEXH][TEXW][3];





unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader) 
{
	FILE *filePtr;	// �ļ�ָ��
	BITMAPFILEHEADER bitmapFileHeader;	// bitmap�ļ�ͷ
	unsigned char	*bitmapImage;		// bitmapͼ������
	int	imageIdx = 0;		// ͼ��λ������
	unsigned char	tempRGB;	// ��������

	// �ԡ�������+����ģʽ���ļ�filename 
	filePtr = fopen(filename, "rb"); 
	if (filePtr == NULL) return NULL;
	// ����bitmap�ļ�ͼ
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr); 
	// ��֤�Ƿ�Ϊbitmap�ļ�
	if (bitmapFileHeader.bfType != BITMAP_ID) {
		fprintf(stderr, "Error in LoadBitmapFile: the file is not a bitmap file\n");
		return NULL;
	}

	// ����bitmap��Ϣͷ
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr); 
	// ���ļ�ָ������bitmap����
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);
	// Ϊװ��ͼ�����ݴ����㹻���ڴ�
	bitmapImage = new unsigned char[bitmapInfoHeader->biSizeImage]; 
	// ��֤�ڴ��Ƿ񴴽��ɹ�
	if (!bitmapImage) {
		fprintf(stderr, "Error in LoadBitmapFile: memory error\n");
		return NULL;
	}
	// ����bitmapͼ������
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr); 
	// ȷ�϶���ɹ�
	if (bitmapImage == NULL) {
		fprintf(stderr, "Error in LoadBitmapFile: memory error\n");
		return NULL;
	}

	//����bitmap�б���ĸ�ʽ��BGR�����潻��R��B��ֵ���õ�RGB��ʽ
	for (imageIdx = 0; 
	 imageIdx < bitmapInfoHeader->biSizeImage; imageIdx+=3) { 
		tempRGB = bitmapImage[imageIdx]; 
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2]; 
		bitmapImage[imageIdx + 2] = tempRGB; 
	}
	// �ر�bitmapͼ���ļ�
	fclose(filePtr); 
	return bitmapImage; 
}

void texload(int i,char *filename)
{
    BITMAPINFOHEADER bitmapInfoHeader;                                 // bitmap��Ϣͷ
	unsigned char*   bitmapData;                                       // ��������

   bitmapData = LoadBitmapFile(filename, &bitmapInfoHeader);
   glBindTexture(GL_TEXTURE_2D, texture[i]);  
	// ָ����ǰ����ķŴ�/��С���˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB,bitmapInfoHeader.biWidth,bitmapInfoHeader.biHeight,0,GL_RGB,GL_UNSIGNED_BYTE,bitmapData);	
}

void load()//�Զ�����������
{
	int i,j;
	for(i = 0;i < TEXH;i ++)
		for(j = 0;j < TEXW;j ++)
			if((i / 8)% 2 == 0)
			{
				if((j / 8) % 2 == 1)
				{
					tex[i][j][0] = 255;
					tex[i][j][1] = 0;
					tex[i][j][2] = 0;
				}
				else
				{
					tex[i][j][0] = 0;
					tex[i][j][1] = 0;
					tex[i][j][2] = 0;
				}
			}
			else
			{
				if((j / 8) % 2 == 1)
				{
					tex[i][j][0] = 0;
					tex[i][j][1] = 0;
					tex[i][j][2] = 0;
				}
				else
				{
					tex[i][j][0] = 255;
					tex[i][j][1] = 0;
					tex[i][j][2] = 0;
				}
			}
}



void init()
{	 
	glGenTextures(3, texture);                                         // ��һ��������Ҫ���ɱ�ʾ���ĸ���, �ڶ������Ƿ��ر�ʾ��������
	texload(0,"Monet.bmp");
    texload(1,"Crack.bmp");      
	//���������Զ�������
	load();
	glBindTexture(GL_TEXTURE_2D,texture[2]);                             
  	glPixelStorei(GL_UNPACK_ALIGNMENT,1); //�������ش洢ģʽ��������ȡ��ͼ�����ݵ��ж��뷽ʽ.
    glTexImage2D(GL_TEXTURE_2D,0,3,TEXW,TEXH,0,GL_RGB,GL_UNSIGNED_BYTE,tex);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

}

void DrawTexCube(GLfloat width,GLfloat height, GLfloat depth)									//
{
	GLfloat x=width/2,y=height/2,z=depth/2;
	glPushMatrix();
	// Front Face
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);   glVertex3f(-x,-y,z);//������ı��ε�����
	glTexCoord2f(   x, 0.0f);   glVertex3f( x,-y,z);//������ı��ε�����
	glTexCoord2f(   x,    y);	glVertex3f( x, y,z);//������ı��ε�����
	glTexCoord2f(0.0f,    y);	glVertex3f(-x, y,z);//������ı��ε�����
	glEnd();
	// Back Face
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);  glVertex3f(-x, -y, -z);
	glTexCoord2f(0.0f,    y);  glVertex3f(-x,  y, -z);
	glTexCoord2f(   x,    y);  glVertex3f( x,  y, -z);
	glTexCoord2f(   x, 0.0f);  glVertex3f( x, -y, -z);
	glEnd();
	// Top Face
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-x,  y, -z);
	glTexCoord2f(0.0f,    z); glVertex3f(-x,  y,  z);
	glTexCoord2f(   x,    z); glVertex3f( x,  y,  z);
	glTexCoord2f(   x, 0.0f); glVertex3f( x,  y, -z);
	glEnd();
	// Bottom Face
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-x, -y, -z);
	glTexCoord2f(   x, 0.0f); glVertex3f( x, -y, -z);
	glTexCoord2f(   x,    z); glVertex3f( x, -y,  z);
	glTexCoord2f(0.0f,    z); glVertex3f(-x, -y,  z);
	glEnd();
	// Right face
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f( x, -y, -z);
	glTexCoord2f(   y, 0.0f); glVertex3f( x,  y, -z);
	glTexCoord2f(   y,    z); glVertex3f( x,  y,  z);
	glTexCoord2f(0.0f,    z); glVertex3f( x, -y,  z);
	glEnd();
	// Left Face
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-x, -y, -z);
	glTexCoord2f(0.0f,    z); glVertex3f(-x, -y,  z);
	glTexCoord2f(   x,    z); glVertex3f(-x,  y,  z);
	glTexCoord2f(   x, 0.0f); glVertex3f(-x,  y, -z);
	glEnd();
	glPopMatrix();
	//return true;
}

void Draw_Triangle() // This function draws a triangle with RGB colors
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    if(teapot == true)
		glBindTexture(GL_TEXTURE_2D,texture[2]);
	else
		glBindTexture(GL_TEXTURE_2D,texture[0]);
	glPushMatrix();
	glTranslatef(0, 0, 4+1);
	glRotatef(90, 1, 0, 0);
	glutSolidTeapot(1);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(0, 0, 3.5);
	DrawTexCube(5,4,1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 1, 1.5);
    DrawTexCube(1,1,3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 1, 1.5);
	DrawTexCube(1,1,3);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1.5, -1, 1.5);
	DrawTexCube(1,1,3);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-1.5, -1, 1.5);
	DrawTexCube(1,1,3);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

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
	} 
	else {
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
    case 'v':{
		light1 = !light1;
		break;
			 }
    case 'b':{
		teapot = !teapot;
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
		0, 1, 0);				// ������0��0��0�����ӵ����� (0,5,50)��Y������

	if (bWire) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
    GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_pos[] = {5,5,5,1};

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, white);
	glEnable(GL_LIGHT0);

	float spotangle = 4.1;
	float light_ambient[] = {0.0f, 0.6f, 4.0f, 1.0f};
	float light_specular[] = {1.0,1.0,1.0,1.0};
	float position[] = {0, 1, 5, 1};
	float lightDir[] = {0, 0, -1};

	glLightfv(GL_LIGHT1, GL_AMBIENT,light_ambient);             //���û�����ɷ�
    glLightfv(GL_LIGHT1, GL_SPECULAR,light_specular);                    //���þ����ɷ�
	glLightfv(GL_LIGHT1, GL_DIFFUSE,white);                     //���������ɷ�
	glLightfv(GL_LIGHT1, GL_POSITION,position);            //��Դλ��
	glLightf(GL_LIGHT1,  GL_SPOT_CUTOFF,spotangle);             //�ü��Ƕ�
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDir);          //��Դ����
	glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,1.0); 

    if(light1 == true)
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
	init();

	glutDisplayFunc(redraw);
	glutReshapeFunc(reshape);	
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}


