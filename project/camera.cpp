///////////////////////////////////////////////
// camera.cpp
#ifndef _CAMERA_H
#define _CAMERA_H
#include "gl\glut.h"
#include "gl\glu.h"
#include "camera.h"




Camera::Camera()
{
}

void Camera::Look()
{
	glMatrixMode(GL_MODELVIEW); //模型视模式
	glLoadIdentity();                             // 单位阵
	gluLookAt(m_fPos[0], m_fPos[1], m_fPos[2],
				m_fTarget[0], m_fTarget[1], m_fTarget[2],
				m_fUpDir[0], m_fUpDir[1], m_fUpDir[2]);          // 相机设置
}

CamPeople::CamPeople()
{
	m_fD = -7;
	m_fPos[0] = -5, m_fPos[1] =-94, m_fPos[2] = m_fD;
	m_fTarget[0] = 0, m_fTarget[1] = 0, m_fTarget[2] = 0;
	m_fUpDir[0] = 0, m_fUpDir[1] = 1, m_fUpDir[2] = 0;

	m_fAlpha = m_fTheta = 0;
	m_fDeltaAalpha = m_fDeltaTheta = 0.1;
	m_fDeltaLamda = 0.5;
    m_l=0.5;
	m_r=0.5;
	m_u=0.5;
	m_d=0.5;
}

void CamPeople::Rotate_Left()
{
	m_fAlpha -= m_fDeltaAalpha;
}

void CamPeople::Rotate_Right()
{
	m_fAlpha += m_fDeltaAalpha;
}

void CamPeople::Forward()
{
	m_fPos[2] -= m_l;
	if(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0)))
	{
		if((!((((m_fPos[0])<=0)&&((m_fPos[0])>=-8))&&(((m_fPos[1])<=-90)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-5)&&((m_fPos[2])<=5))))	
		{	
			if(m_fPos[2]>-5)
			{m_fPos[2]=-5;}
			if(m_fPos[2]<-25)
			{m_fPos[2]=-25;}
		}
	}
	if(!(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0))))
	{
    	if((!((((m_fPos[0])<=0)&&((m_fPos[0])>=-8))&&(((m_fPos[1])<=-90)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-5)&&((m_fPos[2])<=5))))	
		{	
			if((m_fPos[2]>-35)&&((m_fPos[0]<16)&&(m_fPos[0]>-24)))
			{
				if(m_fPos[2]<5)
				{m_fPos[2]=5;}
			}
		}
	}
	if(!(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0))))
	{
		if(m_fPos[2]<-95)
		{
			m_fPos[2]=-95;
		}
	}
	
}

void CamPeople::Backward()
{
	m_fPos[2] += m_r;
	if(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0)))
	{
		if((!((((m_fPos[0])<=0)&&((m_fPos[0])>=-8))&&(((m_fPos[1])<=-90)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-5)&&((m_fPos[2])<=5))))	
		{	
			if(m_fPos[2]>-5)
			{m_fPos[2]=-5;}
			if(m_fPos[2]<-25)
			{m_fPos[2]=-25;}
		}
	}
	if(!(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0))))
	{
    	if((!((((m_fPos[0])<=0)&&((m_fPos[0])>=-8))&&(((m_fPos[1])<=-90)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-5)&&((m_fPos[2])<=5))))	
		{	
			if((m_fPos[2]<5)&&(m_fPos[0]<16)&&(m_fPos[0]>-24))
			{
				if(m_fPos[2]>-35)
				{m_fPos[2]=-35;}
			}
		}
	}
	if(!(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0))))
	{
		if(m_fPos[2]>95)
		{
			m_fPos[2]=95;
		}
	}
}

void CamPeople::Up()
{
	m_fPos[1] += m_u;
	if(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0)))
	{
		if((!((((m_fPos[0])<=0)&&((m_fPos[0])>=-8))&&(((m_fPos[1])<=-90)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-5)&&((m_fPos[2])<=5))))	
		{	
			if(m_fPos[1]>-75)
			{m_fPos[1]=-75;}
			if(m_fPos[1]<-95)
			{m_fPos[1]=-95;}
		}
	}
	if(!(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0))))
	{
		if(m_fPos[1]>95)
		{
			m_fPos[1]=95;
		}
	}
}

void CamPeople::Down()
{
	m_fPos[1] -= m_d;
    if(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0)))
	{
		if((!((((m_fPos[0])<=0)&&((m_fPos[0])>=-8))&&(((m_fPos[1])<=-90)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-5)&&((m_fPos[2])<=5))))	
		{	
			if(m_fPos[1]>-65)
			{m_fPos[1]=-65;}
			if(m_fPos[1]<-95)
			{m_fPos[1]=-95;}
		}
	}
	if(!(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0))))
	{
		if(m_fPos[1]<-95)
		{
			m_fPos[1]=-95;
		}
	}
	
}

void CamPeople::Left()
{
	m_fPos[0] -= m_l;
	if(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0)))
	{
		if((!((((m_fPos[0])<=0)&&((m_fPos[0])>=-8))&&(((m_fPos[1])<=-90)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-5)&&((m_fPos[2])<=5))))	
		{	
			if(m_fPos[0]>6)
			{m_fPos[0]=6;}
			if(m_fPos[0]<-14)
			{m_fPos[0]=-14;}
		}
	}
	if(!(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0))))
	{
    	if((!((((m_fPos[0])<=0)&&((m_fPos[0])>=-8))&&(((m_fPos[1])<=-90)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-5)&&((m_fPos[2])<=5))))	
		{	
			if((m_fPos[0]>-24)&&((m_fPos[2]>-35)&&(m_fPos[2]<5)))
			{
				if((m_fPos[0]<16))
				{m_fPos[0]=16;}
			}
		}
	}
	if(!(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0))))
	{
		if(m_fPos[0]<-95)
		{
			m_fPos[0]=-95;
		}
	}
}

void CamPeople::Right()
{
	m_fPos[0] += m_r;
	if(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0)))
	{
		if((!((((m_fPos[0])<=0)&&((m_fPos[0])>=-8))&&(((m_fPos[1])<=-90)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-5)&&((m_fPos[2])<=5))))	
		{	
			if(m_fPos[0]>6)
			{m_fPos[0]=6;}
			if(m_fPos[0]<-14)
			{m_fPos[0]=-14;}
		}
	}
	if(!(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0))))
	{
    	if((!((((m_fPos[0])<=0)&&((m_fPos[0])>=-8))&&(((m_fPos[1])<=-90)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-5)&&((m_fPos[2])<=5))))	
		{	
			if((m_fPos[0]<16)&&((m_fPos[2]>-35)&&(m_fPos[2]<5)))
			{
				if((m_fPos[0]>-24))
				{m_fPos[0]=-24;}
			}
		}
	}
	if(!(((((m_fPos[0])<=11)&&((m_fPos[0])>=-19))&&(((m_fPos[1])<=-70)&&((m_fPos[1])>=-100))&&((m_fPos[2])>=-30)&&((m_fPos[2])<=0))))
	{
		if(m_fPos[0]>95)
		{
			m_fPos[0]=95;
		}
	}
}

void CamPeople::Rotate_Up()
{
	m_fTheta += m_fDeltaTheta;
}

void CamPeople::Rotate_Down()
{
	m_fTheta -= m_fDeltaTheta;
}

void CamPeople::Look()
{
	m_fTarget[0] = m_fPos[0] - m_fD*cos(m_fTheta)*sin(m_fAlpha);
	m_fTarget[1] = m_fPos[1] + m_fD*sin(m_fTheta);
	m_fTarget[2] = m_fPos[2] - m_fD*cos(m_fTheta)*cos(m_fAlpha);

	Camera::Look();
}

#endif
