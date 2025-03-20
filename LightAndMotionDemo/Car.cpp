#include "GraphObjects.h"

//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Car
//	Function:	Init
//	Inputs:		none
//	Output:		none
//	Purpose:	Initialize Car Primitives, Object Arrays, Shaders
//******************************************************************

void Car::Init()
{
	//FRONT Z
	for (int iColor = 0; iColor < 6; iColor++)
		v4AmbientDiffuseColor[iColor] = vec4(1.0,0.0,0.0,1.0);

	v4Vertices[0] = vec4(5,	1,	2.5,	1);
	v4Vertices[1] = vec4(-5,	1,	2.5,	1);
	v4Vertices[2] = vec4(-5,	-1,	2.5,	1);
	v4Vertices[3] = vec4(-5,	-1,	2.5,	1);
	v4Vertices[4] = vec4(5,	-1,	2.5,	1);
	v4Vertices[5] = vec4(5,	1,	2.5,	1);

	v3Normal[0] =	
	v3Normal[1] =	
	v3Normal[2] =	
	v3Normal[3] =	
	v3Normal[4] =	
	v3Normal[5] =	vec3(0,0,1);

	//FRONT -X
	for (int iColor = 6; iColor < 12; iColor++)
		v4AmbientDiffuseColor[iColor] = vec4(0.0,1.0,0.0,1.0);

	v4Vertices[6] = vec4(-5,	1,	2.5,	1);
	v4Vertices[7] = vec4(-5,	1,	-2.5,	1);
	v4Vertices[8] = vec4(-5,	-1,	-2.5,	1);
	v4Vertices[9] = vec4(-5,	-1,	-2.5,	1);
	v4Vertices[10] = vec4(-5,	-1,	2.5,	1);
	v4Vertices[11] = vec4(-5,	1,	2.5,	1);

	v3Normal[6] = 
	v3Normal[7] = 
	v3Normal[8] = 
	v3Normal[9] = 
	v3Normal[10] =
	v3Normal[11] =vec3(-1,0,0);

	//FRONT X
	for (int iColor = 12; iColor < 18; iColor++)
		v4AmbientDiffuseColor[iColor] = vec4(0.0,0.0,1.0,1.0);

	v4Vertices[12] = vec4(5,	1,	2.5,	1);
	v4Vertices[13] = vec4(5,	-1,	2.5,	1);
	v4Vertices[14] = vec4(5,	-1,	-2.5,	1);
	v4Vertices[15] = vec4(5,	-1,	-2.5,	1);
	v4Vertices[16] = vec4(5,	1,	-2.5,	1);
	v4Vertices[17] = vec4(5,	1,	2.5,	1);

	v3Normal[12] =
	v3Normal[13] =
	v3Normal[14] =
	v3Normal[15] =
	v3Normal[16] =
	v3Normal[17] = vec3(1,0,0);

	//FRONT -Z
	for (int iColor = 18; iColor < 24; iColor++)
		v4AmbientDiffuseColor[iColor] = vec4(1.0,1.0,0.0,1.0);

	v4Vertices[18] = vec4(5,	1,	-2.5,	1);
	v4Vertices[19] = vec4(-5,	-1,	-2.5,	1);
	v4Vertices[20] = vec4(-5,	1,	-2.5,	1);
	v4Vertices[21] = vec4(-5,	-1,	-2.5,	1);
	v4Vertices[22] = vec4(5,	1,	-2.5,	1);
	v4Vertices[23] = vec4(5,	-1,	-2.5,	1);

	v3Normal[18] = 
	v3Normal[19] = 
	v3Normal[20] = 
	v3Normal[21] = 
	v3Normal[22] = 
	v3Normal[23] = vec3(0,0,-1);


	//FRONT -Y
	for (int iColor = 24; iColor < 30; iColor++)
		v4AmbientDiffuseColor[iColor] = vec4(0.0,1.0,1.0,1.0);

	v4Vertices[24] = vec4(-5,	-1,		2.5,	1);
	v4Vertices[25] = vec4(5,	-1,		-2.5,	1);
	v4Vertices[26] = vec4(5,	-1,		2.5,	1);
	v4Vertices[27] = vec4(-5,	-1,		2.5,	1);
	v4Vertices[28] = vec4(-5,	-1,		-2.5,	1);
	v4Vertices[29] = vec4(5,	-1,		-2.5,	1);

	v3Normal[24] = 
	v3Normal[25] = 
	v3Normal[26] = 
	v3Normal[27] = 
	v3Normal[28] = 
	v3Normal[29] = vec3(0,-1,0);

	//FRONT Y
	for (int iColor = 30; iColor < 36; iColor++)
		v4AmbientDiffuseColor[iColor] = vec4(1.0,0.0,1.0,1.0);

	v4Vertices[30] = vec4(-5,	1,	-2.5,	1);
	v4Vertices[31] = vec4(-5,	1,	2.5,	1);
	v4Vertices[32] = vec4(3,	3,	0,	1);
	v4Vertices[33] = vec4(3,	3,	0,	1);
	v4Vertices[34] = vec4(5,	1,	2.5,	1);
	v4Vertices[35] = vec4(5,	1,	-2.5,	1);

	v3Normal[30] = 
	v3Normal[31] = 
	v3Normal[32] = normalize(cross(v4Vertices[32] - v4Vertices[30],v4Vertices[32] - v4Vertices[31]));
	v3Normal[33] = 
	v3Normal[34] = 
	v3Normal[35] = normalize(cross(v4Vertices[33] - v4Vertices[34],v4Vertices[33] - v4Vertices[35]));

	for (int iColor = 36; iColor < 42; iColor++)
		v4AmbientDiffuseColor[iColor] = vec4(0.5,0.5,1.0,1.0);

	v4Vertices[36] = vec4(-5,	1,	-2.5,	1);
	v4Vertices[37] = vec4(3,	3,	0,	1);
	v4Vertices[38] = vec4(5,	1,	-2.5,	1);
	v4Vertices[39] = vec4(-5,	1,	2.5,	1);
	v4Vertices[40] = vec4(5,	1,	2.5,	1);
	v4Vertices[41] = vec4(3,	3,	0,	1);

	v3Normal[36] = 
	v3Normal[37] = 
	v3Normal[38] = normalize(cross(v4Vertices[37] - v4Vertices[38],v4Vertices[37] - v4Vertices[36]));
	v3Normal[39] = 
	v3Normal[40] = 
	v3Normal[41] = normalize(cross(v4Vertices[41] - v4Vertices[39],v4Vertices[41] - v4Vertices[40]));

	for (int iColor = 42; iColor < 48; iColor++)
		v4AmbientDiffuseColor[iColor] = vec4(0,0,0,1.0);

	v4Vertices[42] = vec4(6,	3,	-3.5,	1);
	v4Vertices[43] = vec4(6,	3,	3.5,	1);
	v4Vertices[44] = vec4(8,	3,	3.5,	1);
	v4Vertices[45] = vec4(8,	3,	3.5,	1);
	v4Vertices[46] = vec4(8,	3,	-3.5,	1);
	v4Vertices[47] = vec4(6,	3,	-3.5,	1);

	v3Normal[42] = 
	v3Normal[43] = 
	v3Normal[44] = 
	v3Normal[45] = 
	v3Normal[46] = 
	v3Normal[47] = vec3(-1,0,0);


	program = InitShader("vshader_Assignment4.glsl","fshader_Assignment4.glsl");

	glGenVertexArrays(1, &vao[0]);

	glBindVertexArray(vao[0]);
	glGenBuffers(2,&vbo[0]);
	glBindBuffer(GL_ARRAY_BUFFER,vbo[0]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(v4Vertices),v4Vertices,GL_STATIC_DRAW);
	vPosition = glGetAttribLocation(program,"vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition,4,GL_FLOAT,GL_FALSE,0,0);

	glBindBuffer(GL_ARRAY_BUFFER,vbo[1]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(v4AmbientDiffuseColor),v4AmbientDiffuseColor,GL_STATIC_DRAW);
	vAmbientDiffuseColor = glGetAttribLocation(program,"vAmbientDiffuseColor");
	glEnableVertexAttribArray(vAmbientDiffuseColor);
	glVertexAttribPointer(vAmbientDiffuseColor,4,GL_FLOAT,GL_FALSE,0,0);


	glBindBuffer(GL_ARRAY_BUFFER,vbo[2]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(v3Normal),v3Normal,GL_STATIC_DRAW);
	vNormal = glGetAttribLocation(program,"vNormal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal,3,GL_FLOAT,GL_FALSE,0,0);



	for (int iLines = 0; iLines < 8; iLines++)
		v4AmbientDiffuseColor2[iLines] =vec4(0.0,0.0,1.0,1.0);

	v4Vertices2[0] = vec4(-4.5,0.0,0.0,1.0);
	v4Vertices2[1] = vec4(-4.5,0.0,5.0,1.0);
	v4Vertices2[2] = vec4(4.0,0.0,0.0,1.0);
	v4Vertices2[3] = vec4(4.0,0.0,5.0,1.0);
	v4Vertices2[4] = vec4(-4.5,0.0,0.0,1.0);
	v4Vertices2[5] = vec4(-4.5,0.0,-5.0,1.0);
	v4Vertices2[6] = vec4(4.0,0.0,0.0,1.0);
	v4Vertices2[7] = vec4(4.0,0.0,-5.0,1.0);

	for (int iLines = 9; iLines < 12; iLines++)
		v4AmbientDiffuseColor2[iLines] =vec4(0.0,0.0,1.0,1.0);
	
	v4Vertices2[8] = vec4(3.0,0.0,0.0,1.0);
	v4Vertices2[9] = vec4(6.5,3.0,-2.0,1.0);
	v4Vertices2[10] = vec4(3.0,0.0,0.0,1.0);
	v4Vertices2[11] = vec4(6.5,3.0,2.0,1.0);




	glGenVertexArrays(1, &vao[1]);

	glBindVertexArray(vao[1]);
	glGenBuffers(2,&vbo[3]);
	glBindBuffer(GL_ARRAY_BUFFER,vbo[3]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(v4Vertices2),v4Vertices2,GL_STATIC_DRAW);
	vPosition = glGetAttribLocation(program,"vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition,4,GL_FLOAT,GL_FALSE,0,0);

	glBindBuffer(GL_ARRAY_BUFFER,vbo[4]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(v4AmbientDiffuseColor2),v4AmbientDiffuseColor2,GL_STATIC_DRAW);
	vAmbientDiffuseColor = glGetAttribLocation(program,"vAmbientDiffuseColor");
	glEnableVertexAttribArray(vAmbientDiffuseColor);
	glVertexAttribPointer(vAmbientDiffuseColor,4,GL_FLOAT,GL_FALSE,0,0);

	glBindBuffer(GL_ARRAY_BUFFER,vbo[5]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(v3Normal),v3Normal,GL_STATIC_DRAW);
	vNormal = glGetAttribLocation(program,"vNormal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal,3,GL_FLOAT,GL_FALSE,0,0);

	vSpecularColor = glGetUniformLocation(program,"vSpecularColor");
	vSpecularExponent = glGetUniformLocation(program,"vSpecularExponent");

	model_view = glGetUniformLocation(program,"model_view");
	projection = glGetUniformLocation(program,"projection");

	lightHeadFL.position			=	 glGetUniformLocation(program,"lightHeadFL.position");
	lightHeadFL.color				=	 glGetUniformLocation(program,"lightHeadFL.color");
	lightHeadFL.direction			=	 glGetUniformLocation(program,"lightHeadFL.direction");
	lightHeadFL.cutoffangle			=	 glGetUniformLocation(program,"lightHeadFL.cutoffangle");

	lightHeadFR.position			=	 glGetUniformLocation(program,"lightHeadFR.position");
	lightHeadFR.color				=	 glGetUniformLocation(program,"lightHeadFR.color");
	lightHeadFR.direction			=	 glGetUniformLocation(program,"lightHeadFR.direction");
	lightHeadFR.cutoffangle			=	 glGetUniformLocation(program,"lightHeadFR.cutoffangle");

	lightCopRed.position			=	 glGetUniformLocation(program,"lightCopRed.position");
	lightCopRed.color				=	 glGetUniformLocation(program,"lightCopRed.color");
	lightCopRed.direction			=	 glGetUniformLocation(program,"lightCopRed.direction");
	lightCopRed.cutoffangle			=	 glGetUniformLocation(program,"lightCopRed.cutoffangle");

	lightCopBlue.position			=	 glGetUniformLocation(program,"lightCopBlue.position");
	lightCopBlue.color				=	 glGetUniformLocation(program,"lightCopBlue.color");
	lightCopBlue.direction			=	 glGetUniformLocation(program,"lightCopBlue.direction");
	lightCopBlue.cutoffangle		=	 glGetUniformLocation(program,"lightCopBlue.cutoffangle");

	head.Init();

	wheelFL.Init();
	wheelFR.Init();
	wheelRL.Init();
	wheelRR.Init();

	lightbulbFL.Init();
	lightbulbFR.Init();
	lightbulbRL.Init();
	lightbulbRR.Init();

	lightbulbRed.Init();
	lightbulbBlue.Init();

	LightSourceManager::GetInstance()->AddLightSource(&lightSource[0]);
	LightSourceManager::GetInstance()->AddLightSource(&lightSource[1]);
	LightSourceManager::GetInstance()->AddLightSource(&lightSource[2]);
	LightSourceManager::GetInstance()->AddLightSource(&lightSource[3]);

}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Car
//	Function:	Draw
//	Inputs:		none
//	Output:		none
//	Purpose:	Draw car including wheels and head
//******************************************************************
void Car::Draw()
{
	mv = mv * Translate(tx,ty + GLfloat(2.0),tz);
	mv = mv * RotateX(rx);
	mv = mv * RotateY(ry);
	mv = mv * RotateZ(rz);

	glUniform4fv(vSpecularColor,1,GetSpecularColor());
	glUniform1f(vSpecularExponent,GetSpecularExponent());
	glUniformMatrix4fv(model_view,1,GL_TRUE,mv);
	glUniformMatrix4fv(projection,1,GL_TRUE,p);


	glUniform4fv(lightHeadFL.position,1,LightSourceManager::GetInstance()->GetLightNumber(0)->GetPosition());		
	glUniform4fv(lightHeadFL.color,1,LightSourceManager::GetInstance()->GetLightNumber(0)->GetColor());		
	glUniform4fv(lightHeadFL.direction,1,LightSourceManager::GetInstance()->GetLightNumber(0)->GetDirection());		
	glUniform1f(lightHeadFL.cutoffangle,LightSourceManager::GetInstance()->GetLightNumber(0)->GetCutoffAngle());		

	glUniform4fv(lightHeadFR.position,1,LightSourceManager::GetInstance()->GetLightNumber(1)->GetPosition());		
	glUniform4fv(lightHeadFR.color,1,LightSourceManager::GetInstance()->GetLightNumber(1)->GetColor());		
	glUniform4fv(lightHeadFR.direction,1,LightSourceManager::GetInstance()->GetLightNumber(1)->GetDirection());		
	glUniform1f(lightHeadFR.cutoffangle,LightSourceManager::GetInstance()->GetLightNumber(1)->GetCutoffAngle());		

	glUniform4fv(lightCopRed.position,1,LightSourceManager::GetInstance()->GetLightNumber(2)->GetPosition());		
	glUniform4fv(lightCopRed.color,1,LightSourceManager::GetInstance()->GetLightNumber(2)->GetColor());		
	glUniform4fv(lightCopRed.direction,1,LightSourceManager::GetInstance()->GetLightNumber(2)->GetDirection());		
	glUniform1f(lightCopRed.cutoffangle,LightSourceManager::GetInstance()->GetLightNumber(2)->GetCutoffAngle());		

	glUniform4fv(lightCopBlue.position,1,LightSourceManager::GetInstance()->GetLightNumber(3)->GetPosition());		
	glUniform4fv(lightCopBlue.color,1,LightSourceManager::GetInstance()->GetLightNumber(3)->GetColor());		
	glUniform4fv(lightCopBlue.direction,1,LightSourceManager::GetInstance()->GetLightNumber(3)->GetDirection());		
	glUniform1f(lightCopBlue.cutoffangle,LightSourceManager::GetInstance()->GetLightNumber(3)->GetCutoffAngle());		

	glBindVertexArray(vao[0]);
	glDrawArrays(GL_TRIANGLES,0,48);

	glBindVertexArray(vao[1]);
	glDrawArrays(GL_LINES,0,12);

	mat4	headmv = mv * Translate(3.0,4.0,0.0) * RotateY(-90.0);
	


	head.SetMv(headmv);
	head.SetP(p);
	head.Draw();

	mat4 wheelFLmv = mv * Translate(-5.0,0.0,5.0);

	wheelFL.SetMv(wheelFLmv);
	wheelFL.SetP(p);
	wheelFL.Draw();
	//
	mat4 wheelFRmv = mv * Translate(-5.0,0.0,-5.0);


	wheelFR.SetMv(wheelFRmv);
	wheelFR.SetP(p);
	wheelFR.Draw();

	mat4 wheelRLmv = mv * Translate(4.0,0.0,5.0);
	
	wheelRL.SetMv(wheelRLmv);
	wheelRL.SetP(p);
	wheelRL.Draw();

	mat4 wheelRRmv = mv * Translate(4.0,0.0,-5.0);

	wheelRR.SetMv(wheelRRmv);
	wheelRR.SetP(p);
	wheelRR.Draw();

	mat4 lightbulbFLMv = mv * Translate(-5.0,0.0,1.5) * RotateY(90.0);

	lightbulbFL.SetMv(lightbulbFLMv);
	lightbulbFL.SetP(p);
	lightbulbFL.Draw();

	mat4 lightbulbFRMv = mv * Translate(-5.0,0.0,-1.5) * RotateY(90.0);

	lightbulbFR.SetMv(lightbulbFRMv);
	lightbulbFR.SetP(p);
	lightbulbFR.Draw();

	mat4 lightbulbRLMv = mv * Translate(5.5,0.0,-1.5) * RotateY(90.0);

	lightbulbRL.SetMv(lightbulbRLMv);
	lightbulbRL.SetP(p);
	lightbulbRL.Draw();

	mat4 lightbulbRRMv = mv * Translate(5.5,0.0,1.5) * RotateY(90.0);

	lightbulbRR.SetMv(lightbulbRRMv);
	lightbulbRR.SetP(p);
	lightbulbRR.Draw();

	mat4 lightbulbRedMv = mv * Translate(7,4.0,-2.0) * RotateX(90.0);

	lightbulbRed.SetMv(lightbulbRedMv);
	lightbulbRed.SetP(p);
	lightbulbRed.Draw();

	mat4 lightbulbBlueMv = mv * Translate(7.0,4.0,2.0)* RotateX(90.0);

	lightbulbBlue.SetMv(lightbulbBlueMv);
	lightbulbBlue.SetP(p);
	lightbulbBlue.Draw();


}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Car
//	Function:	RotateWheelsLeft
//	Inputs:		none
//	Output:		none
//	Purpose:	Logic that handles wheel rotation
//******************************************************************
void Car::RotateWheelsLeft()
{
	dTurnAngle += 5.0;

	if (dTurnAngle > 50.0)
		dTurnAngle = 50.0;

	wheelFL.Rotate(dTurnAngle);
	wheelFR.Rotate(dTurnAngle);

	
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Car
//	Function:	RotateWheelsRight
//	Inputs:		none
//	Output:		none
//	Purpose:	Logic that handles wheel rotation
//******************************************************************
void Car::RotateWheelsRight()
{
	dTurnAngle -= 5.0;

	if (dTurnAngle < -50.0)
		dTurnAngle = -50.0;
	
	wheelFL.Rotate(dTurnAngle);
	wheelFR.Rotate(dTurnAngle);

}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Car
//	Function:	RotateWheelsRight
//	Inputs:		none
//	Output:		none
//	Purpose:	Logic that handles car movement model...

//				********!!!!!!!!!IMPROVE MODEL IF TIME ALLOWS!!!!!!!!!!*********
//******************************************************************
void Car::Move()
{
	wheelFL.Spin(dVelocityFront);
	wheelFR.Spin(dVelocityFront);
	wheelRL.Spin(dVelocityRear);
	wheelRR.Spin(dVelocityRear);

	double dSpeed = GetSpeed();

	dDirection += GLfloat(GetSpeed() * sin (GetTurnAngle() * 3.14 / 180.0) / 2.0);

	dX += -GLfloat(GetSpeed() / 40.0 * cos((GetTurnAngle()  - dDirection) * 3.14 / 180.0));
	dY = 0.0;
	dZ += -GLfloat(GetSpeed() /40.0 * sin((GetTurnAngle() - dDirection) * 3.14 / 180.0));

	tx = dX;
	ty = dY;
	tz = dZ;

	rx = 0.0;
	ry = dDirection;
	rz = 0.0;
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Car
//	Function:	LimPosX
//	Inputs:		min X, max X
//	Output:		none
//	Purpose:	Set Car movement boundaries
//******************************************************************
void	Car::LimPosX(GLfloat min, GLfloat max)
{
	if (dX < min)
		dX = min + 1;
	else if (dX > max)
		dX = max -1;
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Car
//	Function:	LimPosY
//	Inputs:		min Y, max Y
//	Output:		none
//	Purpose:	Set Car movement boundaries
//******************************************************************
void	Car::LimPosY(GLfloat min, GLfloat max)
{
	if (dY < min)
		dY = min + 1;
	else if (dY > max)
		dY = max -1;
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Car
//	Function:	LimPosZ
//	Inputs:		min Z, max Z
//	Output:		none
//	Purpose:	Set Car movement boundaries
//******************************************************************
void	Car::LimPosZ(GLfloat min, GLfloat max)
{
	if (dZ < min)
		dZ = min + 1;
	else if (dZ > max)
		dZ = max -1;
}

void	Car::TurnLightsOn()
{
	lightbulbFL.SetState(Lightbulb::ON);
	lightbulbFR.SetState(Lightbulb::ON);
	lightbulbRL.SetState(Lightbulb::ON);
	lightbulbRR.SetState(Lightbulb::ON);
}

void	Car::TurnLightsOff()
{
	lightbulbFL.SetState(Lightbulb::OFF);
	lightbulbFR.SetState(Lightbulb::OFF);
	lightbulbRL.SetState(Lightbulb::OFF);
	lightbulbRR.SetState(Lightbulb::OFF);
}

void	Car::SwitchLights()
{
	lightbulbFL.SwitchState();
	lightbulbFR.SwitchState();
	lightbulbRL.SwitchState();
	lightbulbRR.SwitchState();
}

void	Car::SwitchCopsLights()
{
	lightbulbRed.SwitchState();
	lightbulbBlue.SwitchState();
}

void	Car::RotateCopsLights(GLfloat step)
{
	lightbulbRed.RotateLight(step);
	lightbulbBlue.RotateLight(step);
}

void	Car::UpdateLightSources(bool bCameraStatic)
{

	//headlight front left

	vec4 pos		= lightbulbFL.GetMv() * vec4(0,0,0,1);
	vec4 color		= lightbulbFL.GetEmitColor();

	float dir		= GetDirection();
	
	float stAngle =Utility::Lim360(GetDirection());

	vec4 direction	= vec4(-cos(stAngle / 180 * 3.14),-0.1,sin(stAngle / 180 * 3.14),0.0);

	lightSource[0].SetPosition(pos);
	lightSource[0].SetColor(color);
	lightSource[0].SetDirection(direction);
	lightSource[0].SetCutoffAngle(20);

	//headlight front right
	pos		= lightbulbFR.GetMv() * vec4(0,0,0,1);
	color		= lightbulbFR.GetEmitColor();


	direction	= vec4(-cos(stAngle / 180 * 3.14),-0.1,sin(stAngle / 180 * 3.14),0.0);

	lightSource[1].SetPosition(pos);
	lightSource[1].SetColor(color);
	lightSource[1].SetDirection(direction);
	lightSource[1].SetCutoffAngle(20);

	//cop red
	pos		= lightbulbRed.GetMv() * vec4(0,0,0,1);
	color		= lightbulbRed.GetEmitColor();
	direction	= vec4(cos((GetDirection() - lightbulbRed.GetAngle()) / 180 * 3.14),0.0,-sin((GetDirection() - lightbulbRed.GetAngle())/ 180 * 3.14),0.0);

	lightSource[2].SetPosition(pos);
	lightSource[2].SetColor(color);
	lightSource[2].SetDirection(direction);
	lightSource[2].SetCutoffAngle(60);

	//cop blue
	pos		= lightbulbBlue.GetMv() * vec4(0,0,0,1);
	color		= lightbulbBlue.GetEmitColor();
	direction	= vec4(cos((GetDirection() - lightbulbBlue.GetAngle())/ 180 * 3.14),0.0,-sin((GetDirection() - lightbulbBlue.GetAngle())/ 180 * 3.14),0.0);


	lightSource[3].SetPosition(pos);
	lightSource[3].SetColor(color);
	lightSource[3].SetDirection(direction);
	lightSource[3].SetCutoffAngle(60);
}