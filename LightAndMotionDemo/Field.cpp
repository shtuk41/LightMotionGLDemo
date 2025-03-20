
#include <algorithm>
#include "GraphObjects.h"


//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Field
//	Function:	Init
//	Inputs:		none
//	Output:		none
//	Purpose:	INitialize Field
//******************************************************************
void Field::Init()
{
	
	for (int iColor = 0; iColor < 6; iColor++)
		v4AmbientDiffuseColor[iColor] = vec4(0.7f,0.2f,0.7f,1.0f);
	
	
	v4Vertices[0] = vec4(dMinX,0.0,dMinZ,1.0);
	v4Vertices[1] = vec4(dMaxX,0.0,dMaxZ,1.0);
	v4Vertices[2] = vec4(dMaxX,0.0,dMinZ,1.0);
	v4Vertices[3] = vec4(dMinX,0.0,dMinZ,1.0);
	v4Vertices[4] = vec4(dMinX,0.0,dMaxZ,1.0);
	v4Vertices[5] = vec4(dMaxX,0.0,dMaxZ,1.0);

	v3Normal[0]		= vec3(0,1,0);
	v3Normal[1]		= vec3(0,1,0);
	v3Normal[2]		= vec3(0,1,0);
	v3Normal[3]		= vec3(0,1,0);
	v3Normal[4]		= vec3(0,1,0);
	v3Normal[5]		= vec3(0,1,0);

	program = InitShader("vshader_Assignment4.glsl","fshader_Assignment4.glsl");

	glGenVertexArrays(1, &vao[0]);

	glBindVertexArray(vao[0]);
	glGenBuffers(3,&vbo[0]);
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

	//initialize objects
	fieldObjects.push_back(FieldObject(5.0,5.0,20.0,-30.0));
	fieldObjects.push_back(FieldObject(10.0,20.0,-20.0,20.0));
	fieldObjects.push_back(FieldObject(2.5,15.0,-20.0,-10.0));
	fieldObjects.push_back(FieldObject(3.0,15.0,20.0,30.0));
	fieldObjects.push_back(FieldObject(3.0,15.0,0.0,-15.0));

	for (vector<FieldObject>::iterator it = fieldObjects.begin(); it != fieldObjects.end(); it++)
	{
			(*it).Init();
	}

	
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Field
//	Function:	Draw
//	Inputs:		none
//	Output:		none
//	Purpose:	Draw Field
//******************************************************************
void Field::Draw()
{
	glUniformMatrix4fv(model_view,1,GL_TRUE,mv);
	glUniformMatrix4fv(projection,1,GL_TRUE,p);
	glUniform4fv(vSpecularColor,1,GetSpecularColor());
	glUniform1f(vSpecularExponent,GetSpecularExponent());

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
	glDrawArrays(GL_TRIANGLES,0,6);


	for (vector<FieldObject>::iterator it = fieldObjects.begin(); it != fieldObjects.end(); it++)
	{
		(*it).SetMv(mv);
		(*it).SetP(p);
		(*it).Draw();
	}
}
//****************************************************************
//	Date:		03/10/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Field
//	Function:	CheckFieldObjectCollision
//	Inputs:		car position and offset to object's center
//	Output:		none
//	Purpose:	Checks if car is inside the object, not very precise but sufficient for testing...
//******************************************************************
void Field::CheckFieldObjectCollision(GLfloat dCarX, GLfloat dCarZ, GLfloat offset)
{
	for (vector<FieldObject>::iterator it = fieldObjects.begin(); it != fieldObjects.end(); it++)
	{
		(*it).CheckCollision(dCarX,dCarZ,offset);
	}
}