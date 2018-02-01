/////////////////////////////////////
// camera.h
#include "math.h"

class Camera{
protected:
	
public:
	Camera();
    float m_fPos[3];
	float m_fTarget[3];
	float m_fUpDir[3];
	void Look();
};

class CamPeople: public Camera
{
protected:
	float m_fAlpha;
	float m_fDeltaAalpha;
	float m_fTheta;
	float m_fDeltaTheta;
	float m_fDeltaLamda;
	float m_fD;
	float m_l;
	float m_r;
	float m_u;
	float m_d;

public:
	CamPeople();

	void Rotate_Left();

	void Rotate_Right();

	void Forward();

	void Backward();

	void Rotate_Up();

	void Rotate_Down();

	void Left();

	void Right();

	void Up();

	void Down();

	void Look();
};
