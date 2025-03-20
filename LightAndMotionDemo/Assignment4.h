#ifndef __ASSIGNMENT_4_H
#define __ASSIGNMENT_4_H

#include "GraphObjects.h"
#include "Camera.h"



class	Scene
{
public:
	enum	CAMERA {STATIC=0,VIEWPOINT,CHASE};


	void Init();
	//against OP, but seems like true according to Stroustrup
	void Draw(GraphObject *object);
	void SetMv(mat4 *m) { if (!m) return; else mv = *m;};
	void SetP(mat4 *p) { if (!p) return; else this->p = *p;};
	mat4 GetMv() const {return mv;}
	mat4 GetP() const {return p;}
	void SetWindowSize(GLfloat w, GLfloat h) {fWindowWidth = w; fWindowHeight = h;}
	CAMERA	GetCamera() const {return eCamera;}
	void	SetCameraStatic() {pCameraCurrent = &cCameraStatic;eCamera=STATIC;}
	void	SetCameraViewpoint() {pCameraCurrent = &cCameraViewpoint;eCamera=VIEWPOINT;}
	void	SetCameraChase() {pCameraCurrent = &cCameraChase;eCamera=CHASE;}
	Camera *	GetCurrentCamera() { return pCameraCurrent;}
	CameraStatic *GetStaticCamera() {return &cCameraStatic;}



	static Scene * SceneInstance() { if (scene) return scene; else return scene = new Scene();}
protected:


private:
		static Scene *scene;

	mat4 mv;
	mat4 p;

	CAMERA	eCamera;
	GLfloat	fFovy;

	GLfloat fWindowWidth;
	GLfloat fWindowHeight;

	CameraStatic	cCameraStatic;
	Camera			cCameraViewpoint;
	Camera			cCameraChase;

	Camera	*pCameraCurrent;
};

class	Assignment4 : public Scene
{
public:
	Assignment4(GLfloat minx, GLfloat maxx, GLfloat minz, GLfloat maxz) : field(minx,maxx,minz,maxz) { Init();}
	static Assignment4* Instance() { if (assignment4) return assignment4; else return assignment4 =  new Assignment4(-50,50,-50,50);}
	static void Create() {  Instance();}
	Car * CarInstance()  {return &car;}
	void	DrawObjects();
	Field * FieldInstance() {return &field;}

	~Assignment4() { if (assignment4) delete assignment4;  assignment4 = 0;}
private:
	void	Init();

	static Assignment4 *assignment4;

	Field field;
	Car car;
};
#endif