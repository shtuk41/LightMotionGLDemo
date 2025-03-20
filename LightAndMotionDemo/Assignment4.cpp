#include "Assignment4.h"
#include "Lightsource.h"

Scene *Scene::scene = 0;
Assignment4 * Assignment4::assignment4 = 0;
LightSourceManager * LightSourceManager::lightSourceManager = 0;

//****************************************************************
//	Date:		03/10/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Scene
//	Function:	Init
//	Inputs:		none
//	Output:		none
//	Purpose:	Initialize Scene, Cameras, Set Current Camera
//******************************************************************
void Scene::Init()
{
	eCamera = STATIC;
	cCameraStatic.Reset();
	cCameraStatic.Init(vec4(0,50.0,100.0,1.0),vec4(0.0,0.0,0.0,1.0),vec4(0.0,1.0,0.0,0.0),60.0,fWindowWidth/fWindowHeight,1.0,105.0);
	cCameraChase.Init(vec4(20,10,0,1.0),vec4(0,10,0.0,1.0),vec4(0.0,1.0,0.0,0.0),60.0,fWindowWidth/fWindowHeight,1.0,105.0);
	cCameraViewpoint.Init(vec4(1,6,0,1.0),vec4(-10.0,6.0,0.0,1.0),vec4(0.0,10.0,0.0,0.0),60.0,fWindowWidth/fWindowHeight,1.0,105.0);


	pCameraCurrent = &cCameraStatic;

}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Scene
//	Function:	Draw
//	Inputs:		none
//	Output:		none
//	Purpose:	Draw Scene	
//******************************************************************
void	Scene::Draw(GraphObject *object)
{
	mv = pCameraCurrent ? pCameraCurrent->GetMv() : mat4();
	p  = pCameraCurrent ? pCameraCurrent->GetP() : mat4();

	if (object)
	{
		object->SetMv(mv);
		object->SetP(p);
		object->Draw();
	}
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Assignment4
//	Function:	Init
//	Inputs:		none
//	Output:		none
//	Purpose:	Initialize class members
//******************************************************************
void	Assignment4::Init()
{
	Assignment4::SceneInstance()->Init();
		field.Init();
		car = Car();
		car.Init();
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Assignment4
//	Function:	DrawObjects
//	Inputs:		none
//	Output:		none
//	Purpose:	Draw Field and Car
//******************************************************************
void	Assignment4::DrawObjects()
{
	SceneInstance()->Draw(&field);
	SceneInstance()->Draw(&car);
}
