#ifndef __GRAPH_OBJECTS
#define __GRAPH_OBJECTS

#include <Angel/Angel.h>
#include <vector>
#include "utility.h"
#include "Lightsource.h"

using namespace std;

struct LightStruct
{
	GLuint position;	
	GLuint color;		
	GLuint direction;	
	GLuint cutoffangle;
};

class	GraphObject
{
public:

	GraphObject() { 
	tx=
	ty=
	tz=
	rx=
	ry=
	rz= 0.0;

	}

	virtual void Init() = 0;
	virtual void Draw() = 0;

	void SetMv(mat4 mat) {mv = mat;}
	mat4 GetMv() const {return mv;}

	void SetP(mat4 mat) {p = mat;}
	mat4 GetP() const {return p;}

	void SetTx(GLfloat val) {tx = val;}
	GLfloat GetTx() const {return tx;}

	void SetTy(GLfloat val) {ty = val;}
	GLfloat GetTy() const {return ty;}

	void SetTz(GLfloat val) {tz = val;}
	GLfloat GetTz() const {return tz;}

	void SetRx(GLfloat val) {rx = val;}
	GLfloat GetRx() const {return tx;}

	void SetRy(GLfloat val) {ry = val;}
	GLfloat GetRy() const {return ty;}

	void SetRz(GLfloat val) {rz = val;}
	GLfloat GetRz() const {return tz;}

	vec4	GetSpecularColor() const {return vec4(1.0,1.0,1.0,1.0);}
	GLfloat	GetSpecularExponent() const {return 100;}

	
protected:
	mat4	mv,p;

	GLfloat		tx;
	GLfloat		ty;
	GLfloat		tz;

	GLfloat		rx;
	GLfloat		ry;
	GLfloat		rz;

	GLuint vao[2];
	GLuint vbo[6];

	GLuint vPosition;
	GLuint vAmbientDiffuseColor;
	GLuint vNormal;
	
	GLuint vSpecularColor;
	GLuint vSpecularExponent;
	GLuint model_view;
	GLuint projection;

	GLuint program;

	LightStruct		lightHeadFL;
	LightStruct		lightHeadFR;
	LightStruct		lightCopRed;
	LightStruct		lightCopBlue;


};

class Head : public GraphObject
{
public:
	Head(GLfloat r) : glfRadius(r) {}
	void Init();
	void Draw();
	void Rotate(double);
	GLfloat	GetRotAngle() const {return glfRotAngle;}
private:
	vec4 v4Vertices[612];
	vec4	v4AmbientDiffuseColor[612];
	vec3	v3Normal[612];

	GLfloat		glfRadius;
	GLfloat		glfSubdiv;

	GLfloat		glfRotAngle;
};

class Wheel : public GraphObject
{
public:
	Wheel(GLfloat r, GLfloat w): glfRadius(r),glfWidth(w) {}

	void Init();
	void Draw();
	void Rotate(double rot) {ry = GLfloat(rot);}
	void Spin(double);
private:
	vec4    v4Vertices[432];
	vec4	v4AmbientDiffuseColor[432];
	vec3	v3Normal[432];

	vec4	v4SpecularColor;
	GLfloat glfSpecularExponent;


	GLfloat	glfRadius; 
	GLfloat glfWidth; 
};

class Lightbulb : public GraphObject
{
public:
	enum STATE {OFF = 0, ON = 1};

	Lightbulb(GLfloat r, GLfloat w, vec4 offcolor, vec4 oncolor, vec4 emitcolor,STATE e, bool fulllight, GLfloat angle = 0.0) : glfRadius(r), glfWidth(w),v4OffColor(offcolor),v4OnColor(oncolor),v4EmitColor(emitcolor), eState(e),bFullLight(fulllight),glfAngle(angle) {}

	void Init();
	void Draw();

	void SetState (STATE e) { eState = e;}
	STATE GetState() const {return eState;}
	void SwitchState() { eState == ON ? SetState(OFF) : SetState(ON);}
	
	void	RotateLight(GLfloat step) { if (eState == ON) glfAngle = Utility::Lim360(glfAngle + step);}
	void	SetAngle(GLfloat a) {glfAngle = a;}	
	GLfloat GetAngle() const {return glfAngle + 90.0;}
	vec4	GetColor() const {return (eState == ON) ? v4OnColor : v4OffColor; }
	vec4    GetEmitColor() const {return (eState == ON ? v4EmitColor : vec4(0,0,0,1));}

private:
	vec4		v4Vertices[432];
	vec4	v4AmbientDiffuseColor[432];
	vec3	v3Normal[432];

	vec4	v4SpecularColor;
	GLfloat glfSpecularExponent;

	GLfloat	glfRadius; 
	GLfloat glfWidth; 

	vec4	v4OffColor;
	vec4	v4OnColor;

	vec4	v4EmitColor;

	STATE	eState;
	STATE	ePrevState;

	bool	bFullLight;

	GLfloat glfAngle;
};

class Car : public GraphObject
{
public:
	Car():head(2.0),wheelFL(2.0,1.0),wheelFR(2.0,1.0),wheelRL(2.0,1.0),wheelRR(2.0,1.0),dX(0.0),dY(0.0),dZ(0.0),dTurnAngle(0.0),dVelocityFront(0.0),dVelocityRear(0.0),dDirection(0.0),
					lightbulbFL(1.0,0.5,vec4(0.1,0.1,0.1,1.0),vec4(5.0,5.0,0.0,1.0),vec4(0.7,0.7,0.0,1),Lightbulb::ON,true),
					lightbulbFR(1.0,0.5,vec4(0.1,0.1,0.1,1.0),vec4(5.0,5.0,0.0,1.0),vec4(0.7,0.7,0.0,1),Lightbulb::ON,true),
					lightbulbRL(1.0,1.0,vec4(0.9f,0.6f,0.5f),vec4(5.0f,0.0f,0.0f,1.0f),vec4(1,0,0,1),Lightbulb::ON,true),
					lightbulbRR(1.0,1.0,vec4(0.9f,0.6f,0.5f),vec4(5.0f,0.0f,0.0f,1.0f),vec4(1,0,0,1),Lightbulb::ON,true),
					lightbulbRed(1.0,2.0,vec4(0.64f,0.16f,0.16f,1.0),vec4(5.0f,0.0f,0.0f,1.0f),vec4(0.7,0,0,1),Lightbulb::OFF,false,0),
					lightbulbBlue(1.0,2.0,vec4(0.098f,0.098f,0.44f,1.0),vec4(0.0f,0.0f,5.0f,1.0f),vec4(0,0,0.7,1),Lightbulb::OFF,false,180)
					{
	
					}
	void Init();
	void Draw();

	void RotateHeadRight() { head.Rotate(-5.0);}
	void RotateHeadLeft() {head.Rotate(5.0);}
	GLfloat GetHeadAngle() {return head.GetRotAngle();}
	void RotateWheelsLeft();
	void RotateWheelsRight();
	void SetSpeed(GLfloat dSpeed) {dVelocityFront = dVelocityRear = dSpeed;}
	void IncreaseSpeed(GLfloat dStep) {dVelocityFront = dVelocityRear += dStep;}
	GLfloat GetSpeed() const {return dVelocityFront;}
	GLfloat GetTurnAngle() const {return dTurnAngle;}
	GLfloat	GetPosX() const {return dX;}
	GLfloat GetPosY() const {return dY;}
	GLfloat GetPosZ() const {return dZ;}
	void	LimPosX(GLfloat, GLfloat);
	void	LimPosY(GLfloat, GLfloat);
	void	LimPosZ(GLfloat, GLfloat);
	void Move();
	GLfloat GetDirection() const {return dDirection;}
	void	TurnLightsOn();
	void	TurnLightsOff();
	void	SwitchLights();
	void	SwitchCopsLights();
	void	RotateCopsLights(GLfloat);
	void	UpdateLightSources(bool);

private:
	Head	head;
	Wheel	wheelFL;
	Wheel	wheelFR;
	Wheel	wheelRL;
	Wheel	wheelRR;

	Lightbulb	lightbulbFL;
	Lightbulb	lightbulbFR;
	Lightbulb	lightbulbRL;
	Lightbulb	lightbulbRR;

	Lightbulb	lightbulbRed;
	Lightbulb	lightbulbBlue;

	vec4	v4Vertices[48];
	vec4	v4AmbientDiffuseColor[48];
	vec3	v3Normal[48];

	vec4	v4Vertices2[12];
	vec4	v4AmbientDiffuseColor2[12];
	vec3	v3Normal2[12];

	GLfloat		dX;
	GLfloat		dY;
	GLfloat		dZ;

	GLfloat		dTurnAngle;
	GLfloat		dVelocityFront;
	GLfloat		dVelocityRear;
	GLfloat		dDirection;

	LightSource	lightSource[4];



};

class FieldObject : public GraphObject
{
public:
	void	Init();
	void	Draw();
	GLfloat	getRadius() const {return fRadius;}
	
	void	CheckCollision(GLfloat, GLfloat,GLfloat);
	

	FieldObject(GLfloat r, GLfloat h, GLfloat x, GLfloat z) : fRadius(r),fHeight(h),fX(x),fZ(z) {}
private:
	vec4		v4Vertices[216];
	vec4		v4AmbientDiffuseColor[216];
	vec3		v3Normal[216];

	vec4		v4SpecularColor;
	GLfloat		glfSpecularExponent;

	GLfloat		fRadius;
	GLfloat		fHeight;
	GLfloat		fX;
	GLfloat		fZ;

	bool		bSimpleCollisionDetection;
	bool		bPrevSimpleCollisionDetection;
};


class Field : public GraphObject
{
public:
	Field(GLfloat minx,GLfloat maxx, GLfloat minz, GLfloat maxz) : dMinX(minx),dMaxX(maxx),dMinZ(minz),dMaxZ(maxz) {}
	void Init();
	void Draw();
	GLfloat GetMinX() const {return dMinX;}
	GLfloat GetMaxX() const {return dMaxX;}
	GLfloat GetMinZ() const {return dMinZ;}
	GLfloat GetMaxZ() const {return dMaxZ;}
	void CheckFieldObjectCollision(GLfloat,GLfloat,GLfloat);
private:
	vec4		v4Vertices[6];
	vec4		v4AmbientDiffuseColor[6];
	vec3		v3Normal[6];

	vec4		v4SpecularColor;
	GLfloat		glfSpecularExponent;

	GLfloat		dMinX;
	GLfloat		dMaxX;
	GLfloat		dMinZ;
	GLfloat		dMaxZ;

	vector<FieldObject>	fieldObjects;
};




#endif