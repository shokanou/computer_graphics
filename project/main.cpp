#include <windows.h>
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "camera.h"
#include <time.h>
#include <windef.h>

//#include <mmsystem.h>
#include <iostream>
#include <vector>
#include "gl/glut.h"
#include "gl/glaux.h"
#pragma comment(lib, "WINMM.LIB")
#pragma comment(lib, "glaux.LIB")
#pragma comment( linker,"/subsystem:/"windows/" /entry:/"mainCRTStartup/"" )  

using namespace std;

#define WIN32_LEAN_AND_MEAN
#define TEX_NUM 19
#define BITMAP_ID 0x4D42
#define TEXW 64
#define TEXH 64 
#define PI 3.14159f
#define RADIUS 1.5f
AUX_RGBImageRec *img[TEX_NUM];
GLuint texID[TEX_NUM];
CamPeople cam;
GLUquadricObj* qObj=gluNewQuadric();
 

float a = 1;//台灯
float k = 1;
float b = 1;//大灯
float ngt = 1.0;//茶壶大小
bool ske = false;//茶壶旋转
float fRotate    = 0.0f;
float tRotate = 0.0f;
bool snh = false;//地球仪旋转
bool hkt = false;//绘制方式
bool akb = false;//绘制曲面
float tea_axis[]={-6,-93.7,-84};
int color = 15;//茶壶纹理
bool nmb = false;//墙壁纹理
float lamp_axis[3]={ -9.0, -90, -15.0};
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
GLUnurbsObj *theNurb1;
GLfloat ctrlpoints[5][5][3] =
{
 {{-3,0.5,0},{-1,1.5,0},{-2,2,0},{1,-1,0},{-5,0,0}},
 {{-3,0.5,-1},{-1,1.5,-1},{-2,2,-1},{1,-1,-1},{-5,0,-1}},
 {{-3,0.5,-2},{-1,1.5,-2},{-2,2,-2},{1,-1,-2},{-5,0,-2}},
 {{-3,0.5,-3},{-1,1.5,-3},{-2,2,-3},{1,-1,-3},{-5,0,-3}},
 {{-3,0.5,-4},{-1,1.5,-4},{-2,2,-4},{1,-1,-4},{-5,0,-4}}
};//控制点

GLfloat mat_diffuse[] = {1.0,0.5,0.1,1.0};
GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
GLfloat mat_shininess[] = {100.0};
GLfloat light_position1[] = {1};
 
void SaveScreenShot();
void myMenu( int value ) ;



void tex_init()//纹理初始化
{
	char* file_name[19]; 
	file_name[0] = "wood.bmp";
	file_name[1] = "tianhuaban.bmp";
	file_name[2] = "qiangbi2.bmp";	

	file_name[3] = "back.bmp";
	file_name[4] = "left.bmp";
	file_name[5] = "front.bmp";
	file_name[6] = "right.bmp";
	file_name[7] = "top.bmp";
	file_name[8] = "grass.bmp";

	file_name[9] = "outside.bmp";
	file_name[10] = "pictureframe.bmp";
	file_name[11] = "pic.bmp";
	file_name[12] = "desk.bmp";
    file_name[13] = "door.bmp";
	file_name[14] = "qiangbi3.bmp";
	file_name[15] = "Monet.bmp";
	file_name[16] = "wood2.bmp";
	file_name[17] = "wall2.bmp";
	file_name[18] = "earth.bmp";
	for (int i = 0; i < TEX_NUM; i++)
	{
		img[i] = auxDIBImageLoad(file_name[i]);
		glGenTextures(1, &texID[i]);

		glBindTexture(GL_TEXTURE_2D, texID[i]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 
			img[i]->sizeX, img[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, 
			img[i]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
}

void init()                                 //初始化
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT); 
	glDepthFunc(GL_LEQUAL);  
    glEnable(GL_DEPTH_TEST); 
	tex_init();

}


void light0_int()//光源0，天花板上的灯
{
	if(a==1)//当鼠标右键被按下，使光源0开启
	{		
	glEnable(GL_LIGHT1);
	GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };    //光源0参数 白色环境光
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };   
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };  	
	GLfloat light_position[] = { -4.0, -72.0, -15.0, 1.0 };
	   
	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient); 
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse); 
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular); 
	glLightfv(GL_LIGHT0,GL_POSITION, light_position);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glShadeModel(GL_SMOOTH); 
	glEnable(GL_LIGHTING);   
	glEnable(GL_LIGHT0); 
	}
	if(a==0)
	{
		glDisable(GL_LIGHT0); 
	}
}


void light1_int()//光源1，台灯的光
{
	if(b==1)
	{ 		
	GLfloat light_ambient1[] = { 1.0, 1.0, 0.0, 1.0 };   //光源1的参数  即台灯的参数 黄色光
	GLfloat light_diffuse1[] = { 1.0, 1.0, 0.0, 1.0 };   
	GLfloat light_specular1[] = { 1.0, 0.0, 0.0, 1.0 };  
	GLfloat spot_direction1[]={-9.0, -130.0, -15.0};
	GLfloat light_position1[] = { lamp_axis[1], lamp_axis[2], lamp_axis[3], 1.0 };

	glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient1); 
	glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse1); 
	glLightfv(GL_LIGHT1,GL_SPECULAR,light_specular1); 
	glLightfv(GL_LIGHT1,GL_POSITION, light_position1);
	glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,70);
	glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,spot_direction1);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glShadeModel(GL_SMOOTH); 
	glEnable(GL_LIGHTING);   
	glEnable(GL_LIGHT1);
	}
	if(b==0)
	{
		glDisable(GL_LIGHT1); 
	}
}

void light2_int()//室外方向光源
{
	if((((cam.m_fPos[0])<=100)&&((cam.m_fPos[0])>=-100))&&(((cam.m_fPos[1])<=100)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-100)&&((cam.m_fPos[2])<=100))
	{
		if(!((((cam.m_fPos[0])<=11)&&((cam.m_fPos[0])>=-19))&&(((cam.m_fPos[1])<=-70)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-30)&&((cam.m_fPos[2])<=5)))
		{		
			GLfloat light_ambient2[] = { 1.0, 1.0, 1.0, 1.0 };   
			GLfloat light_diffuse2[] = { 1.0, 1.0, 1.0, 1.0 };   
			GLfloat light_specular2[] = { 1.0, 1.0, 1.0, 1.0 };  	
			GLfloat light_position2[] = { -4.0, -72.0, -15.0, 0.0 };
			   
			glLightfv(GL_LIGHT2,GL_AMBIENT,light_ambient2); 
			glLightfv(GL_LIGHT2,GL_DIFFUSE,light_diffuse2); 
			glLightfv(GL_LIGHT2,GL_SPECULAR,light_specular2); 
			glLightfv(GL_LIGHT2,GL_POSITION, light_position2);
			glShadeModel(GL_SMOOTH); 
			glEnable(GL_LIGHTING);   
			glEnable(GL_LIGHT2); 
		}
	}
	if(((((cam.m_fPos[0])<=11)&&((cam.m_fPos[0])>=-19))&&(((cam.m_fPos[1])<=-70)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-30)&&((cam.m_fPos[2])<=5)))
	{
		glDisable(GL_LIGHT2); 
	}
}

void light3_int()//微弱全局环境光
{
	if(((((cam.m_fPos[0])<=11)&&((cam.m_fPos[0])>=-19))&&(((cam.m_fPos[1])<=-70)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-30)&&((cam.m_fPos[2])<=5)))
	{
		GLfloat lmodel_ambient[]={0.3,0.3,0.3,1.0};
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);
	}
}


void draw_door()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,texID[13]);
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);	    glVertex3f(-4.1,-101,-70); 
	glTexCoord2f(1,0);	    glVertex3f(-4.1,-89.9,-70);  
	glTexCoord2f(1,1);	    glVertex3f(4.1,-89.9,-70);
	glTexCoord2f(0,1);	    glVertex3f(4.1,-101,-70);
	glEnd();
	glPopMatrix();
}

void display_door()//门的自动开关
{
	if((((cam.m_fPos[0])<=0)&&((cam.m_fPos[0])>=-8))&&(((cam.m_fPos[1])<=-90)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-5)&&((cam.m_fPos[2])<=5))
		{//房里开门
			if(k<95)
			{k+=0.5;}
			glPushMatrix();
			glRotatef(k,0,1,0);
			glTranslatef(-4,0,70);
			draw_door();
	
			glPopMatrix();	
		}
	if((((cam.m_fPos[0])<=11)&&((cam.m_fPos[0])>=-19))&&(((cam.m_fPos[1])<=-70)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-30)&&((cam.m_fPos[2])<=0))
	{//房里关门
		if((k!=0))
		{k-=0.5;}
		glPushMatrix();
		glRotatef(k,0,1,0);
		glTranslatef(-4,0,70);
		draw_door();
	
		glPopMatrix();
	
	}
	if((((cam.m_fPos[0])<=100)&&((cam.m_fPos[0])>=-100))&&(((cam.m_fPos[1])<=100)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-100)&&((cam.m_fPos[2])<=100))
	{//外面关门
		if(!((((cam.m_fPos[0])<=11)&&((cam.m_fPos[0])>=-19))&&(((cam.m_fPos[1])<=-70)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-30)&&((cam.m_fPos[2])<=5)))
		{	
		if((k<=96)&&(k>=0))
		{k-=0.5;}
		glPushMatrix();
		glRotatef(k,0,1,0);
		glTranslatef(-4,0,70);
		draw_door();
	
		glPopMatrix();
		}
	
	//外面开门
		if((((cam.m_fPos[0])<=0)&&((cam.m_fPos[0])>=-8))&&(((cam.m_fPos[1])<=-90)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-5)&&((cam.m_fPos[2])<=5))
				{	if((k>=0)&&(k<96))
					{k+=0.5;}
					glPushMatrix();
					glRotatef(k,0,1,0);
					glTranslatef(-4,0,70);
					draw_door();
					//cout<<t<<"  ";
					glPopMatrix();
				}
		
	}
}
void desk()
{
	glBindTexture(GL_TEXTURE_2D,texID[12]);//桌子
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);		glVertex3f(-9, -95,-88);
	glTexCoord2f(1,0);		glVertex3f(-9, -95,-82);
	glTexCoord2f(1,1);		glVertex3f(-3,  -95,-82);
	glTexCoord2f(0,1);		glVertex3f(-3,  -95,-88);
	glEnd();	
	glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,texID[12]);
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);		glVertex3f(-9, -94.5,-88);
	glTexCoord2f(1,0);		glVertex3f(-9, -94.5,-82);
	glTexCoord2f(1,1);		glVertex3f(-3,  -94.5,-82);
	glTexCoord2f(0,1);		glVertex3f(-3,  -94.5,-88);
	glEnd();	
	glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,texID[12]);
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);		glVertex3f(-3, -95,-88);
	glTexCoord2f(1,0);		glVertex3f(-3, -94.5,-82);
	glTexCoord2f(1,1);		glVertex3f(-3, -94.5,-82);
	glTexCoord2f(0,1);		glVertex3f(-3, -95,-88);
	glEnd();	
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[12]);
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);		glVertex3f(-9, -95,-88);
	glTexCoord2f(1,0);		glVertex3f(-9, -94.5,-82);
	glTexCoord2f(1,1);		glVertex3f(-9, -94.5,-82);
	glTexCoord2f(0,1);		glVertex3f(-9, -95,-88);
	glEnd();	
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[12]);
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);		glVertex3f(-9, -95,-88);
	glTexCoord2f(1,0);		glVertex3f(-9, -94.5,-88);
	glTexCoord2f(1,1);		glVertex3f(-3, -94.5,-88);
	glTexCoord2f(0,1);		glVertex3f(-3, -95,-88);
	glEnd();	
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[12]);
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);		glVertex3f(-9, -95,-82);
	glTexCoord2f(1,0);		glVertex3f(-9, -94.5,-82);
	glTexCoord2f(1,1);		glVertex3f(-3, -94.5,-82);
	glTexCoord2f(0,1);		glVertex3f(-3, -95,-82);
	glEnd();	
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[12]);
    glPushMatrix();//桌子脚
	glTranslatef(-8,-100, -83);	
	glRotatef(-90, 1, 0, 0);
	gluCylinder(qObj, 0.2, 0.2,5, 20,10);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[12]);
	glPushMatrix();//桌子脚
	glTranslatef(-4,-100, -83);	
	glRotatef(-90, 1, 0, 0);
	gluCylinder(qObj, 0.2, 0.2,5, 20,10);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[12]);
	glPushMatrix();//桌子脚
	glTranslatef(-4,-100, -87);	
	glRotatef(-90, 1, 0, 0);
	gluCylinder(qObj, 0.2, 0.2,5, 20,10);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[12]);
	glPushMatrix();//桌子脚
	glTranslatef(-8,-100, -87);	
	glRotatef(-90, 1, 0, 0);
	gluCylinder(qObj, 0.2, 0.2,5, 20,10);
	glPopMatrix();

}
void tea_pot()
{
	//glEnable(GL_TEXTURE_2D);
	//glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D,texID[color]);
	glPushMatrix();
	glTranslatef(tea_axis[0], tea_axis[1], tea_axis[2]);	
	if(ske)
	{
		glRotatef(fRotate, 0, 1.0, 0);
	}
	//glRotatef(90, 1, 0, 0); 
	glutSolidTeapot(ngt);	
	glPopMatrix();
	//glDisable(GL_TEXTURE_2D);
}

void house()//绘制房子及房子里的桌子、相片、相框
{
	GLfloat house[][3] = {
		{-20, -70, -70},      // 1#
		{-20, -70, -100},     // 2#
		{20, -70, -100},      // 3#
		{20, -70, -70},       // 4#
		{-20, -100, -70},    // 5#
		{-20, -100, -100},   // 6#
		{20, -100, -100},     // 7#
		{20, -100, -70}       // 8#
	};

	GLfloat houseoutside[][3] = {
		{-20.015, -70.015, -70.015},      // 1#
		{-20.015, -70.015, -100.015},     // 2#
		{20.015, -70.015, -100.015},      // 3#
		{20.015, -70.015, -70.015},       // 4#
		{-20.015, -100.015, -70.015},    // 5#
		{-20.015, -100.015, -100.015},   // 6#
		{20.015, -100.015, -100.015},     // 7#
		{20.015, -100.015, -70.015}       // 8#
	};		
	
	glEnable(GL_NORMALIZE);	
	glBindTexture(GL_TEXTURE_2D,texID[0]);
 //房子里面
   	glPushMatrix();	
	glBegin(GL_QUADS);
	glNormal3f(0,-1,0);
	glTexCoord2f(0,0);		glVertex3f(-20, -99.99, -70);
	glTexCoord2f(0,1);		glVertex3f(-20, -99.99, -100);
	glTexCoord2f(1,1);		glVertex3f(20, -99.99, -100);
	glTexCoord2f(1,0);		glVertex3f(20, -99.99, -70);
	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[1]);
	glPushMatrix();
	glBegin(GL_QUADS);	
	glNormal3f(0,1,0);
	glTexCoord2f(0,0);		glVertex3fv(house[0]);
	glTexCoord2f(0,1);		glVertex3fv(house[1]);
	glTexCoord2f(1,1);		glVertex3fv(house[2]);
	glTexCoord2f(1,0);		glVertex3fv(house[3]);
	glEnd();
	glPopMatrix();

	if (nmb)
		glBindTexture(GL_TEXTURE_2D,texID[17]);
	else
		glBindTexture(GL_TEXTURE_2D,texID[2]);//左
	glPushMatrix();	
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glTexCoord2f(0,0);  	glVertex3fv(house[4]);
	glTexCoord2f(1,0);		glVertex3fv(house[0]);
	glTexCoord2f(1,1);		glVertex3fv(house[1]);
	glTexCoord2f(0,1);		glVertex3fv(house[5]);
	glEnd();
	glPopMatrix();

	if (nmb)
		glBindTexture(GL_TEXTURE_2D,texID[17]);
	else
		glBindTexture(GL_TEXTURE_2D,texID[2]);
	//glBindTexture(GL_TEXTURE_2D,texID[2]);//背
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);		glVertex3f(-20, -100, -99.9975);
	glTexCoord2f(1,0);		glVertex3f(-20, -70, -99.9975);
	glTexCoord2f(1,1);		glVertex3f(20, -70, -99.9975);
	glTexCoord2f(0,1);		glVertex3f(20, -100, -99.9975);
	glEnd();
	glPopMatrix();
	
	
	if (nmb)
		glBindTexture(GL_TEXTURE_2D,texID[17]);
	else
		glBindTexture(GL_TEXTURE_2D,texID[2]);
	//glBindTexture(GL_TEXTURE_2D,texID[2]);//右
	glPushMatrix();
	glBegin(GL_QUADS);	
	glNormal3f(1,0,0);
    glTexCoord2f(0,0);	 glVertex3fv(house[6]);
	glTexCoord2f(1,0);	 glVertex3fv(house[2]);
	glTexCoord2f(1,1);	 glVertex3fv(house[3]);
	glTexCoord2f(0,1);	 glVertex3fv(house[7]);
	glEnd();
	glPopMatrix();
	
	glBindTexture(GL_TEXTURE_2D,texID[14]);//前
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);	    glVertex3f(-20,-90,-70);
	glTexCoord2f(1,0);	    glVertex3fv(house[0]);
	glTexCoord2f(1,1);	    glVertex3fv(house[3]);
	glTexCoord2f(0,1);	    glVertex3f(20,-90,-70);
	glEnd();
		

	glBindTexture(GL_TEXTURE_2D,texID[14]);//前
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);	    glVertex3fv(house[4]); 
	glTexCoord2f(1,0);	    glVertex3f(-20,-90,-70);  
	glTexCoord2f(1,1);	    glVertex3f(-4,-90,-70);
	glTexCoord2f(0,1);	    glVertex3f(-4,-100,-70);
	glEnd();
		
    glBindTexture(GL_TEXTURE_2D,texID[14]);//front
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);	    glVertex3f(4,-100,-70); 
	glTexCoord2f(1,0);	    glVertex3f(4,-90,-70);  
	glTexCoord2f(1,1);	    glVertex3f(20,-90,-70);
	glTexCoord2f(0,1);	    glVertex3fv(house[7]);
	glEnd();
	glPopMatrix();

	

//房子外面


	glBindTexture(GL_TEXTURE_2D,texID[9]);
	glPushMatrix();	
	glBegin(GL_QUADS);
	glNormal3f(-1,0,0);
	glTexCoord2f(0,0);  	glVertex3fv(houseoutside[4]);
	glTexCoord2f(1,0);		glVertex3fv(houseoutside[0]);
	glTexCoord2f(1,1);		glVertex3fv(houseoutside[1]);
	glTexCoord2f(0,1);		glVertex3fv(houseoutside[5]);
	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[9]);
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);		glVertex3fv(houseoutside[5]);
	glTexCoord2f(1,0);		glVertex3fv(houseoutside[1]);
	glTexCoord2f(1,1);		glVertex3fv(houseoutside[2]);
	glTexCoord2f(0,1);		glVertex3fv(houseoutside[6]);
	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[9]);
	glPushMatrix();
	glBegin(GL_QUADS);	
	glNormal3f(1,0,0);
    glTexCoord2f(0,0);	 glVertex3fv(houseoutside[6]);
	glTexCoord2f(1,0);	 glVertex3fv(houseoutside[2]);
	glTexCoord2f(1,1);	 glVertex3fv(houseoutside[3]);
	glTexCoord2f(0,1);	 glVertex3fv(houseoutside[7]);
	glEnd();
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D,texID[9]);//前
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);	  glVertex3f(-20.005, -90.005, -69.995);
	glTexCoord2f(1,0);	  glVertex3f(-20.005, -70.005,  -69.995);
	glTexCoord2f(1,1);	  glVertex3f(20.005, -70.005,  -69.995);
	glTexCoord2f(0,1);	  glVertex3f(20.005, -90.005, -69.995);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,texID[9]);
    glBegin(GL_QUADS);//前
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);	  glVertex3f(-20.005, -100.005, -69.995);
	glTexCoord2f(1,0);	  glVertex3f(-20.005, -90.005,  -69.995);
	glTexCoord2f(1,1);	  glVertex3f(-4.005, -90.005,  -69.995);
	glTexCoord2f(0,1);	  glVertex3f(-4.005, -100.005, -69.995);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,texID[9]);
    glBegin(GL_QUADS);//前
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);	  glVertex3f(4.005, -100.005, -69.995);
	glTexCoord2f(1,0);	  glVertex3f(4.005, -90.005,  -69.995);
	glTexCoord2f(1,1);	  glVertex3f(20.005, -90.005,  -69.995);
	glTexCoord2f(0,1);	  glVertex3f(20.005, -100.005, -69.995);
	glEnd();

	glPopMatrix();

//照片
	glBindTexture(GL_TEXTURE_2D,texID[10]);//相框
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);		glVertex3f(-3, -89, -99.997);
	glTexCoord2f(1,0);		glVertex3f(-3, -83, -99.997);
	glTexCoord2f(1,1);		glVertex3f(3, -83, -99.997);
	glTexCoord2f(0,1);		glVertex3f(3, -89, -99.997);
	glEnd();
	glPopMatrix();
	
	glBindTexture(GL_TEXTURE_2D,texID[11]);//照片
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0,0,-1);
	glTexCoord2f(0,0);		glVertex3f(-2, -88.5, -99.9960);
	glTexCoord2f(1,0);		glVertex3f(-2, -83.5, -99.9960);
	glTexCoord2f(1,1);		glVertex3f(2, -83.5, -99.9960);
	glTexCoord2f(0,1);		glVertex3f(2, -88.5, -99.9960);
	glEnd();
	glPopMatrix();

	glPopMatrix();


}

void lamp()//天花板灯的位置
{
	glPushMatrix();//灯柱
	glTranslatef(-4,-72,-15);

	glRotatef (-90, 1,0,0);
	gluCylinder(qObj, 0.3, 0.3, 2,100,100);
	glPopMatrix();
	
	glPushMatrix();//球形灯	
	glTranslatef(-4,-72,-15);
	auxSolidSphere(0.7);
	glPopMatrix();
}

void skybox()//室外天空盒
{
    int  w = 100;
	GLfloat skybox[][3] = {
		{w, w, w},      // 1#
		{w, w, -w},     // 2#
		{-w, w, -w},      // 3#
		{-w, w, w},       // 4#
		{w, -w, w},    // 5#
		{w, -w, -w},   // 6#
		{-w, -w, -w},     // 7#
		{-w, -w, w}       // 8#
	};

	glBindTexture(GL_TEXTURE_2D, texID[3]);
	glBegin(GL_QUADS);
		glTexCoord2f(0,1); glVertex3fv(skybox[1]);
		glTexCoord2f(1,1); glVertex3fv(skybox[0]);
		glTexCoord2f(1,0); glVertex3fv(skybox[4]);
		glTexCoord2f(0,0); glVertex3fv(skybox[5]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texID[4]);
	glBegin(GL_QUADS);
		glTexCoord2f(0,1); glVertex3fv(skybox[2]);
		glTexCoord2f(1,1); glVertex3fv(skybox[1]);
		glTexCoord2f(1,0); glVertex3fv(skybox[5]);
		glTexCoord2f(0,0); glVertex3fv(skybox[6]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texID[5]);
	glBegin(GL_QUADS);
		glTexCoord2f(0,1); glVertex3fv(skybox[3]);
		glTexCoord2f(1,1); glVertex3fv(skybox[2]);
		glTexCoord2f(1,0); glVertex3fv(skybox[6]);
		glTexCoord2f(0,0); glVertex3fv(skybox[7]);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, texID[6]);
	glBegin(GL_QUADS);
		glTexCoord2f(0,1); glVertex3fv(skybox[0]);
		glTexCoord2f(1,1); glVertex3fv(skybox[3]);
		glTexCoord2f(1,0); glVertex3fv(skybox[7]);
		glTexCoord2f(0,0); glVertex3fv(skybox[4]);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, texID[7]);
	glBegin(GL_QUADS);
		glTexCoord2f(0,1); glVertex3fv(skybox[1]);
		glTexCoord2f(1,1); glVertex3fv(skybox[2]);
		glTexCoord2f(1,0); glVertex3fv(skybox[3]);
		glTexCoord2f(0,0); glVertex3fv(skybox[0]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texID[8]);
	glBegin(GL_QUADS);
		glTexCoord2f(0,1); glVertex3fv(skybox[6]);
		glTexCoord2f(1,1); glVertex3fv(skybox[5]);
		glTexCoord2f(1,0); glVertex3fv(skybox[4]);
		glTexCoord2f(0,0); glVertex3fv(skybox[7]);
	glEnd();
}
void furn()
{
	glPushMatrix();
	glTranslatef(8,-95,-80);
	if(snh)
	{
		glRotatef(tRotate, 0, 1.0, 0);
	}
	GLUquadricObj *quadObj = gluNewQuadric();//创建一个二次曲面物体
    gluQuadricTexture(quadObj,GL_TRUE);        //启用该二次曲面的纹理
    glBindTexture(GL_TEXTURE_2D, texID[18]);//绑定纹理
    gluSphere(quadObj,1,50,50);                    //绘制一个球体
    gluDeleteQuadric(quadObj);                    //删除二次曲面对象
	glPopMatrix();
	//glDisable(GL_TEXTURE_2D);

}
void nurbs()
{
	//glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	//glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	//glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	//glLightfv(GL_FRONT,GL_POSITION,light_position1);//设置光源参数
	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);//设置光照模型参数
	GLfloat knots[10] = {0.0,0.0,0.0,0.0,0.0,1.0,1.0,1.0,1.0,1.0};
 
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_AUTO_NORMAL);
	//glEnable(GL_NORMALIZE);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT,GL_DONT_CARE);
	glEnable(GL_BLEND);
	glFrontFace(GL_CW);
	glShadeModel(GL_SMOOTH);
	//glEnable(GL_LINE_SMOOTH);
	theNurb1 = gluNewNurbsRenderer();//创建NURBS对象theNurb1
	gluNurbsProperty(theNurb1,GLU_SAMPLING_TOLERANCE,25.0);
	gluNurbsProperty(theNurb1,GLU_DISPLAY_MODE,GLU_OUTLINE_POLYGON);

	//glRotatef(50.0,1.0,1.0,0.0);
	glPushMatrix();
	glTranslatef(10,-99,-85);
	gluBeginSurface(theNurb1);
 
	gluNurbsSurface(theNurb1,10,knots,10,knots,5*3,3,&ctrlpoints[0][0][0],5,5,GL_MAP2_VERTEX_3);
	gluEndSurface(theNurb1);
	glPopMatrix();
}


void Cone()
{
	float texLeft;					// left texture coordinate for quads
	float texBottom;				// bottom texture coordinate for quads
	float texTop;					// top texture coordinate for quads
	float texRight;					// right texture coordinate for quads

	GLfloat x = 0, y = 0, angle = 0;
	glPushMatrix();
	glTranslatef(8,-99,-80);
	//绕XY轴旋转
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glColor3f(0.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, texID[16]);
	//绘制三角扇形
	for(angle=0;angle<=2.0f*PI;angle+=0.1f)
	{
		// calculate texture coordinates
		texLeft = angle/2.0f*PI;			// left texture coordinate
		texBottom =0;		// bottom texture coordinate
		texRight =(angle+0.2)/2.0f*PI;		// right texture coordinate
		texTop =5;			// top texture coordinate
		glBegin(GL_TRIANGLES);
		glTexCoord2f(texRight,texTop);
		glTexCoord2f(texLeft,texTop);
		glVertex3f(0.0f,3.0f,0.0f);//圆锥的锥顶点是三角扇形的公共顶点，沿z轴移动，产生一个圆锥而不是圆
		x = RADIUS * sin( angle );
		y = RADIUS * cos( angle );
		glTexCoord2f(texLeft,texBottom);
		glVertex3f( x, 0,y);
		x = RADIUS * sin( angle+0.1);
		y = RADIUS * cos( angle+0.1);
		glTexCoord2f(texRight,texBottom);
		glVertex3f( x, 0,y);
	}
	glEnd();
	//绘制圆锥底面，即绘制一个新的三角扇形
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f( 0.0f, 0.0f );//三角形扇的中心在(0,0)坐标原点处

	for ( angle=0; angle <= 2.0f * PI; angle += 0.1f )
	{
		x = RADIUS * sin( angle );
		y = RADIUS * cos( angle );
		glVertex3f( x, 0,y );
	}
	//最后一个扇形	
	x = RADIUS * sin( 0.0f );
	y = RADIUS * cos( 0.0f );
	glVertex2f( x, y );
	glEnd();
	//恢复转换
	glPopMatrix();

}
/*void prism()
{
	 glPopMatrix();
	 glPushMatrix();
	 glTranslatef(8,-95,-75);
     glRotatef(aa/15,1.0f,-0.5f,-0.3f);//对变量aa进行改变，实现三棱柱的旋转
	 glScalef(1.0f, 0.6f, 1.0f);
     glBegin(GL_QUADS);
	    for(int i=0; i<3; ++i)      // 有三个面，循环三次
          for(int j=0; j<4; ++j)     // 每个面有四个顶点，循环四次
	 {if(i==0)
		glColor3f(1.0f,0.0f,0.0f);	
            if(i==1)
			 glColor3f(0.0f,1.0f,0.0f);
			    if(i==2)
			      glColor3f(0.0f,0.0f,1.0f);	
                     glVertex3fv(vertex3_list[index3_list[i][j]]);}
      glEnd(); 

    glBegin(GL_TRIANGLES);  
	{ glColor3f(1.0f,0.0f,0.0f);
         glVertex3fv(vertex3_list[0]);
       glColor3f(0.0f,1.0f,0.0f);
         glVertex3fv(vertex3_list[2]);
		   glColor3f(0.0f,0.0f,1.0f);
		   glVertex3fv(vertex3_list[1]);}
      glEnd();
      
	  glBegin(GL_TRIANGLES);  
	{     
		glColor3f(1.0f,0.0f,0.0f);
         glVertex3fv(vertex3_list[3]);
       glColor3f(0.0f,1.0f,0.0f);
         glVertex3fv(vertex3_list[5]);
		   glColor3f(0.0f,0.0f,1.0f);
		   glVertex3fv(vertex3_list[4]);
	}
      glEnd();
     glPopMatrix();
}*/


void _lamp()//室内台灯位置
{
	
	glPushMatrix();//灯柱
	glTranslatef(-9,-94.5,-15);
	glRotatef (-90, 1,0,0);
	gluCylinder(qObj, 0.1, 0.1, 2,100,100);
	glPopMatrix();
	
	glPushMatrix();//球形灯	
	glTranslatef(-9,-92.5, -15);
	auxSolidSphere(0.4);
	glPopMatrix();

	glPushMatrix();//灯罩
	glTranslatef(-9,-92.5,-15);
	glRotatef (-90, 1,0,0);
	gluCylinder(qObj, 0.7, 0.5, 0.5,100,100);
	glPopMatrix();
	
}
void myMenu( int value )  
{  
	if(value == 0)
	{
		SaveScreenShot();
	}
    if ( value == 1 )  
    {  
        exit( 0 );  
    }  
} 
void myMenu2( int x )  
{  
    if ( x == 0)  
    {  
          b=((int)b+1)%2;
    }  
	if(x==1)
	{
		a = ((int)a+1)%2;
	}
	if(x==2)
	{
		ske = !ske;
	}
	if(x==3)
	{
		snh = !snh;
	}
} 

//WriteBitmapFile
//根据bitmapData的（RGB）数据，保存bitmap
//filename是要保存到物理硬盘的文件名（包括路径）
BOOL WriteBitmapFile(char * filename,int width,int height,unsigned char * bitmapData)
{
  //填充BITMAPFILEHEADER
  BITMAPFILEHEADER bitmapFileHeader;
  memset(&bitmapFileHeader,0,sizeof(BITMAPFILEHEADER));
  bitmapFileHeader.bfSize = sizeof(BITMAPFILEHEADER);
  bitmapFileHeader.bfType = 0x4d42;	//BM
  bitmapFileHeader.bfOffBits =sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

  //填充BITMAPINFOHEADER
  BITMAPINFOHEADER bitmapInfoHeader;
  memset(&bitmapInfoHeader,0,sizeof(BITMAPINFOHEADER));
  bitmapInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
  bitmapInfoHeader.biWidth = width;
  bitmapInfoHeader.biHeight = height;
  bitmapInfoHeader.biPlanes = 1;
  bitmapInfoHeader.biBitCount = 24;
  bitmapInfoHeader.biCompression = BI_RGB;
  bitmapInfoHeader.biSizeImage = width * abs(height) * 3;

  //////////////////////////////////////////////////////////////////////////
  FILE * filePtr;			//连接要保存的bitmap文件用
  unsigned char tempRGB;	//临时色素
  int imageIdx;

  //交换R、B的像素位置,bitmap的文件放置的是BGR,内存的是RGB
  for (imageIdx = 0;imageIdx < bitmapInfoHeader.biSizeImage;imageIdx +=3)
  {
    tempRGB = bitmapData[imageIdx];
    bitmapData[imageIdx] = bitmapData[imageIdx + 2];
    bitmapData[imageIdx + 2] = tempRGB;
  }

  filePtr = fopen(filename,"wb");
  if (NULL == filePtr)
  {
    return FALSE;
  }

  fwrite(&bitmapFileHeader,sizeof(BITMAPFILEHEADER),1,filePtr);

  fwrite(&bitmapInfoHeader,sizeof(BITMAPINFOHEADER),1,filePtr);

  fwrite(bitmapData,bitmapInfoHeader.biSizeImage,1,filePtr);

  fclose(filePtr);
  return TRUE;
}

void SaveScreenShot()
{
//  int clnWidth,clnHeight;	//client width and height
  static void * screenData;
  //RECT rc;
  int len = 800 * 600 * 3;
  screenData = malloc(len);
  memset(screenData,0,len);
  glReadPixels(0, 0, 800, 600, GL_RGB, GL_UNSIGNED_BYTE, screenData);

  //生成文件名字符串，以时间命名
  time_t tm = 0;
  tm = time(NULL);
  char lpstrFilename[256] = {0};
  sprintf_s(lpstrFilename,sizeof(lpstrFilename),"%d.bmp",tm);

  WriteBitmapFile(lpstrFilename,800,600,(unsigned char*)screenData);
  //释放内存
  free(screenData);

}



void display()
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (hkt) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	light0_int();//天花板灯
	light1_int(); //台灯
	light2_int();//室外方向光源
	light3_int();//全局微弱环境光
	lamp();//天花板灯位置
	_lamp();//室内台灯位置
	
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslatef(-4,0,70);
    desk();
	tea_pot();
	furn();
	Cone();
	if(akb)
		nurbs();
	//prism();
	house();//房子及里面的桌子、相片
	//glTranslatef(-5,-90,70);
	glPopMatrix();
	skybox();//室外天空盒
	display_door();//门的自动开关
    cam.Look();	//相机设置，包括了漫游时的不能穿透
	if(ske)
		fRotate+=1.0f;
	if(snh)
		tRotate+=1.0f;
	glutSwapBuffers();
}


void reshape(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,float(w)/float(h), 0.1, 9999);
}

void special_keyboard(int key, int x, int y)//前后左右键控制前后左右方向，F1、F2、F3、F4分别控制方向的旋转
{
	switch(key)
	{
	case GLUT_KEY_LEFT:
		cam.Left();
		break;
	case GLUT_KEY_RIGHT:
		cam.Right();
		break;
	case GLUT_KEY_UP:
		cam.Forward();
		break;
	case GLUT_KEY_DOWN:
		cam.Backward();
		break;
	case GLUT_KEY_F1:
		cam.Up();
		break;
	case GLUT_KEY_F2:
		cam.Down();
		break;
	case GLUT_KEY_F3:
		cam.Rotate_Down();
		break;
	case GLUT_KEY_F4:
		cam.Rotate_Up();
		break;
	case GLUT_KEY_F5:
		cam.Rotate_Left();
		break;
	case GLUT_KEY_F6:
		cam.Rotate_Right();
		break;
	}
		glutPostRedisplay();
}


void Keyboard(unsigned char Key, int x, int y)//退出
{
	switch(Key)
	{
		case 27:                                                //按下ESC键退出
		{
			exit(0);
			break;
		}
		case ' ':
			{
				ske = !ske;
				break;
			}
		case 'r':
			{
				hkt = !hkt;
				break;
			}
		case 'c':
			{
				if(color==17)
					color = 0;
				else
					color += 1;
					
				break;
			}
	case 'z':
		{
			if((((cam.m_fPos[0])<=11)&&((cam.m_fPos[0])>=-19))&&(((cam.m_fPos[1])<=-70)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-30)&&((cam.m_fPos[2])<=5))
				{
					if(b==1)
					{
						b=0;
						glutPostRedisplay();
		    			break;
					}
					if(b==0)
					{
						b=1;
						glutPostRedisplay();
						break;
					}
				}
				if(!(((cam.m_fPos[0])<=11)&&((cam.m_fPos[0])>=-19))&&(((cam.m_fPos[1])<=-70)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-30)&&((cam.m_fPos[2])<=5))
				{
	                b=0;
				    glutPostRedisplay();
		    		break;
				}		
			}
	case 'x':
		{
			if(a==1)
				{
					a=0;
					glutPostRedisplay();
		    		break;
				}
				if(a==0)
				{
					a=1;
					glutPostRedisplay();
					break;
				}
	case 'v':
		{
			nmb=!nmb;
			break;
		}
			case 'j': {//todo, hint:use the ARRAY that you defined, and notice the teapot can NOT be moved out the range of the table.
		if(tea_axis[0]<=-4.0f){
		tea_axis[0]+=0.2f;
		}
		break;
			  }
	case 'l': {//todo
		if(tea_axis[0]>=-8.0f){
		tea_axis[0]-=0.2f;
		}
		break;
			  }
	case 'i': {//todo
		if(tea_axis[2]<=-83.0f){
			tea_axis[2]+=0.2f;
		}
		break;
			  }
	case 'k': {//todo
		if(tea_axis[2]>=-87.0f){
		tea_axis[2]-=0.2f;
		}
		break;
			  }
	case 'y':{
		if(ngt<=1.2)
		{
			ngt += 0.05;
			tea_axis[1]+=0.05;
		}

		break;
			 }
	case 't':{
		if(ngt>=0.8)
		{
			ngt -= 0.05;
			tea_axis[1]-=0.05;
		}

		break;
			 }
	case 'b':
		{
			SaveScreenShot();
			break;
		}
	case'w':
		{
			lamp_axis[2]-=0.2f;
			break;
		}
	case 'a':
		{
			lamp_axis[0]-=0.2f;
			break;
		}
	case 's':
		{
			lamp_axis[2]+=0.2f;
			break;
		}
	case 'd':
		{
			lamp_axis[0]-=0.2f;
			break;
		}
	case 'q':
		{
			lamp_axis[1]-=0.2f;
			break;
		}
	case 'e':
		{
			lamp_axis[1]+=0.2f;
			break;
		}
	case 'f':
		{
			snh = !snh;
			break;
		}
	case 'h':
		{
			akb = !akb;
			break;
		}
		}
	}

}
void idle()
{
	glutPostRedisplay();
}

void myMouse(int button,int state,int x,int y)//室内天花板灯及台灯的控制
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if (state==GLUT_DOWN)
		{
			{
				if((((cam.m_fPos[0])<=11)&&((cam.m_fPos[0])>=-19))&&(((cam.m_fPos[1])<=-70)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-30)&&((cam.m_fPos[2])<=5))
				{
					if(b==1)
					{
						b=0;
						glutPostRedisplay();
		    			break;
					}
					if(b==0)
					{
						b=1;
						glutPostRedisplay();
						break;
					}
				}
				if(!(((cam.m_fPos[0])<=11)&&((cam.m_fPos[0])>=-19))&&(((cam.m_fPos[1])<=-70)&&((cam.m_fPos[1])>=-100))&&((cam.m_fPos[2])>=-30)&&((cam.m_fPos[2])<=5))
				{
	                b=0;
				    glutPostRedisplay();
		    		break;
				}
			}
		}
	case GLUT_RIGHT_BUTTON:
		if (state==GLUT_DOWN)
		{
			{
				if(a==1)
				{
					a=0;
					glutPostRedisplay();
		    		break;
				}
				if(a==0)
				{
					a=1;
					glutPostRedisplay();
					break;
				}		
			}
		}
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);   
	glutInitWindowSize(800, 800);     
	glutInitWindowPosition(100, 100);   
	glutCreateWindow("场景");
	init();
	glutDisplayFunc(display);  
	glutReshapeFunc(reshape);
	glutKeyboardFunc(Keyboard); 
    glutSpecialFunc(special_keyboard);
	glutCreateMenu( myMenu );
	glutAddMenuEntry( "截图", 0 );  
    glutAddMenuEntry( "退出", 1 );  
	 
	glutAttachMenu( GLUT_RIGHT_BUTTON );
	glutCreateMenu( myMenu2 ); 
	glutAddMenuEntry( "开/关台灯", 0 ); 
	glutAddMenuEntry( "开/关大灯", 1 ); 
	glutAddMenuEntry( "旋转/停止茶壶", 2); 
	glutAddMenuEntry( "旋转/停止地球仪", 3 ); 
	glutAttachMenu( GLUT_LEFT_BUTTON );
	glutIdleFunc(idle);
	//glutFullScreen();
	glutMainLoop(); 
	return 0;
}

