
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <Angel/Angel.h>



#include "Assignment4.h"


#pragma comment(lib, "glew32.lib")


void init();
void myDisplay();
void myIdle();
void myReshape(int width, int height);
void myMouseEvent(int,int,int,int);
void myMouseMotion(int, int);
void myMousePassiveMotion(int,int);
void myMouseEntryEvent(int);
void myKeyboard(unsigned char,int,int);
void mySpecial(int,int,int);

//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		none
//	Function:	main
//	Inputs:		none
//	Output:		none
//	Purpose:	main function
//******************************************************************
int main(int argc, char** argv)
{
	//init
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1200,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Assignment4 Aleksander Shtuk");
	glewInit();
	init();

	//display
	glutDisplayFunc(myDisplay);

	//idle
	glutIdleFunc(myIdle);

	//input
	glutMouseFunc(myMouseEvent);
	glutMotionFunc(myMouseMotion);
	glutPassiveMotionFunc(myMousePassiveMotion);
	glutEntryFunc(myMouseEntryEvent);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecial);

	//reshape
	glutReshapeFunc(myReshape);	

	glutMainLoop();

	return 0;
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		none
//	Function:	Init
//	Inputs:		none
//	Output:		none
//	Purpose:	all objects must be initilialized here
//******************************************************************
void init()
{
	//testing

	Assignment4::Create();

	glClearColor(0.0,0.0,0.0,0.0);

	glMatrixMode(GL_PROJECTION);

	glEnable(GL_DEPTH_TEST);

}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		none
//	Function:	myDisplay
//	Inputs:		none
//	Output:		none
//	Purpose:	Callback that handles display
//******************************************************************
void myDisplay()
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Assignment4::Instance()->DrawObjects();

	glFlush();
	glutSwapBuffers();
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		none
//	Function:	myIdle
//	Inputs:		none
//	Output:		none
//	Purpose:	check if car is inside field boundaries
//******************************************************************
void myIdle()
{
	Assignment4::Instance()->CarInstance()->Move();


	if (Assignment4::Instance()->CarInstance()->GetPosX() - 5 < Assignment4::Instance()->FieldInstance()->GetMinX() ||
		Assignment4::Instance()->CarInstance()->GetPosX() + 5 > Assignment4::Instance()->FieldInstance()->GetMaxX() ||
		Assignment4::Instance()->CarInstance()->GetPosZ() - 5< Assignment4::Instance()->FieldInstance()->GetMinZ() ||
		Assignment4::Instance()->CarInstance()->GetPosZ()  + 5> Assignment4::Instance()->FieldInstance()->GetMaxZ() )
	{
		Assignment4::Instance()->CarInstance()->SetSpeed(0.0);

		Assignment4::Instance()->CarInstance()->LimPosX(-44.0,44.0);
		Assignment4::Instance()->CarInstance()->LimPosZ(-44.0,44.0);

	}

	Assignment4::Instance()->FieldInstance()->CheckFieldObjectCollision(Assignment4::Instance()->CarInstance()->GetPosX(),
																		Assignment4::Instance()->CarInstance()->GetPosZ(),
																		5.0);

	if (Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::STATIC)
	{
		if (Assignment4::Instance()->SceneInstance()->GetStaticCamera()->GetFocus() == CameraStatic::CAR)
		{
			Assignment4::Instance()->SceneInstance()->GetStaticCamera()->SetAt(vec4(Assignment4::Instance()->CarInstance()->GetPosX(),
																						Assignment4::Instance()->CarInstance()->GetPosY(),
																						Assignment4::Instance()->CarInstance()->GetPosZ(),1.0));
		}
		else
		{
			Assignment4::Instance()->SceneInstance()->GetStaticCamera()->SetAt(vec4(0.0,0.0,0.0,1.0));
		}
	}
	else if (Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::CHASE)
	{
		Assignment4::Instance()->SceneInstance()->GetCurrentCamera()->SetEye(vec4((GLfloat)(Assignment4::Instance()->CarInstance()->GetPosX() + 20 * cos(Assignment4::Instance()->CarInstance()->GetDirection() * 3.14 /180.0)),
																						(GLfloat)(Assignment4::Instance()->CarInstance()->GetPosY() + 10.0),
																						(GLfloat)(Assignment4::Instance()->CarInstance()->GetPosZ() - (GLfloat)20.0 * sin(Assignment4::Instance()->CarInstance()->GetDirection() * 3.14 /180.0)),GLfloat(1.0)));
			Assignment4::Instance()->SceneInstance()->GetCurrentCamera()->SetAt(vec4((GLfloat)(Assignment4::Instance()->CarInstance()->GetPosX()),
																						(GLfloat)(Assignment4::Instance()->CarInstance()->GetPosY() + 10.0),
																						(GLfloat)(Assignment4::Instance()->CarInstance()->GetPosZ()),1.0));
	}
	else if (Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::VIEWPOINT)
	{
		double dCarAngle  = Assignment4::Instance()->CarInstance()->GetDirection();
		double dHead = Assignment4::Instance()->CarInstance()->GetHeadAngle();
		double dHeadAngle = Assignment4::Instance()->CarInstance()->GetHeadAngle() + Assignment4::Instance()->CarInstance()->GetDirection();

		GLfloat dX = (GLfloat)(Assignment4::Instance()->CarInstance()->GetPosX() + 3.0 *  cos(dCarAngle * 3.14 /180.0) - 3.0 * cos(dHeadAngle * 3.14 /180.0));
		GLfloat dZ = (GLfloat)(Assignment4::Instance()->CarInstance()->GetPosZ() - 3.0 *  sin(dCarAngle * 3.14 /180.0) + 3.0 * sin(dHeadAngle * 3.14 /180.0));

		GLfloat dXAt =  (GLfloat)(Assignment4::Instance()->CarInstance()->GetPosX() + 3.0 *  cos(dCarAngle * 3.14 /180.0) - 10.0 * cos(dHeadAngle * 3.14 /180.0));
		GLfloat dZAt = (GLfloat)(Assignment4::Instance()->CarInstance()->GetPosZ() - 3.0 *  sin(dCarAngle * 3.14 /180.0) + 10.0 * sin(dHeadAngle * 3.14 /180.0));
		
		Assignment4::Instance()->SceneInstance()->GetCurrentCamera()->SetEye(vec4(dX,GLfloat(Assignment4::Instance()->CarInstance()->GetPosY() + 6.0),dZ,1.0));
		Assignment4::Instance()->SceneInstance()->GetCurrentCamera()->SetAt(vec4(dXAt,6.0,dZAt,1.0));
	
	}

	Assignment4::Instance()->CarInstance()->RotateCopsLights(1.0);


	Assignment4::Instance()->CarInstance()->UpdateLightSources(Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::STATIC);

	glutPostRedisplay();
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		none
//	Function:	myReshape
//	Inputs:		none
//	Output:		none
//	Purpose:	Callback that handles window reshaping			
//******************************************************************

void myReshape(int width, int height)
{

	Assignment4::Instance()->SceneInstance()->SetWindowSize(GLfloat(width),GLfloat(height));
	Assignment4::Instance()->SceneInstance()->GetCurrentCamera()->SetAspect(GLfloat(width)/GLfloat(height));

	static bool ii = true;

	if (ii)
	{
		Assignment4::Instance()->SceneInstance()->Init();
		ii = false;
	}

	glViewport(0,0,width,height);
	glutPostRedisplay();
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		none
//	Function:	myReshape
//	Inputs:		none
//	Output:		none
//	Purpose:	Callback that handles processing special keys	
//				Left, Right - turn car
//				Up, Down - move forward, backward
//******************************************************************
void mySpecial(int key,int x,int z)
{
	if (key == GLUT_KEY_LEFT)
	{
		Assignment4::Instance()->CarInstance()->RotateWheelsLeft();
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		Assignment4::Instance()->CarInstance()->RotateWheelsRight();
	}
	else if (key == GLUT_KEY_UP)
	{
		Assignment4::Instance()->CarInstance()->SetSpeed(6.0);
	}
	else if (key == GLUT_KEY_DOWN)
	{
		Assignment4::Instance()->CarInstance()->SetSpeed(-6.0);
	}

}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		none
//	Function:	SetSpeed
//	Inputs:		none
//	Output:		none
//	Purpose:	Set desired movement speed	
//******************************************************************
void SetSpeed(int key)
{
	double dNewSpeed = (key - 48) * (Assignment4::Instance()->CarInstance()->GetSpeed() > 0.0 ? 0.5 : Assignment4::Instance()->CarInstance()->GetSpeed() < 0.0 ? -0.5 : 0.0);

	Assignment4::Instance()->CarInstance()->SetSpeed((GLfloat)dNewSpeed);

}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		none
//	Function:	myKeyboard
//	Inputs:		none
//	Output:		none
//	Purpose:	keyboard handling
//				x,z - rotate head
//				1-9 - set speed
//******************************************************************
void myKeyboard(unsigned char key,int x,int y)
{
	if (key == 'x')
	{
		Assignment4::Instance()->CarInstance()->RotateHeadRight();
	}
	else if (key == 'z')
	{
		Assignment4::Instance()->CarInstance()->RotateHeadLeft();
	}
	else if (key == ' ')
	{
		Assignment4::Instance()->CarInstance()->SetSpeed(0.0);
	}
	else if (key >= 49 && key<=57)
	{
		SetSpeed(key);
	}
	else if (key == 'c' && Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::STATIC)
	{
		Assignment4::Instance()->SceneInstance()->SetCameraViewpoint();
	}
	else if (key == 'c' && Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::VIEWPOINT)
	{
		Assignment4::Instance()->SceneInstance()->SetCameraChase();
	}
	else if (key == 'c' && Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::CHASE)
	{
		Assignment4::Instance()->SceneInstance()->SetCameraStatic();
	}
	else if (key == 'r')
	{
		 Assignment4::Instance()->SceneInstance()->Init();
	}
	else if (key == 'a' && Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::STATIC)
	{
		Assignment4::Instance()->SceneInstance()->GetStaticCamera()->ZoomInLens();
	}
	else if (key == 's' && Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::STATIC)
	{
		Assignment4::Instance()->SceneInstance()->GetStaticCamera()->ZoomOutLens();
	}
	else if (key == 'q' && Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::STATIC)
	{
		Assignment4::Instance()->SceneInstance()->GetStaticCamera()->ZoomInPosition();
	}
	else if (key == 'w' && Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::STATIC)
	{
		Assignment4::Instance()->SceneInstance()->GetStaticCamera()->ZoomOutPosition();
	}
	else if (key == 'f' && Assignment4::Instance()->SceneInstance()->GetCamera() == Scene::STATIC)
	{
		if (Assignment4::Instance()->SceneInstance()->GetStaticCamera()->GetFocus() == CameraStatic::CENTER)
			Assignment4::Instance()->SceneInstance()->GetStaticCamera()->SetFocus(CameraStatic::CAR);	
		else
			Assignment4::Instance()->SceneInstance()->GetStaticCamera()->SetFocus(CameraStatic::CENTER);		
	}
	else if (key == 'h')
	{
		Assignment4::Instance()->CarInstance()->SwitchLights();
	}
	else if (key == 'l' || key == 'L')
	{
		Assignment4::Instance()->CarInstance()->SwitchCopsLights();
	}



	
	
}

void myMouseEntryEvent(int)
{

}

void myMousePassiveMotion(int,int)
{

}

void myMouseMotion(int,int)
{

}

void myMouseEvent(int,int,int,int)
{

}