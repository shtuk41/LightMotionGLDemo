#include "GraphObjects.h"

//****************************************************************
//	Date:		03/10/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		FieldObject
//	Function:	Init
//	Inputs:		Initialize Object on a our field
//	Output:		none
//	Purpose:	Initilize object parameters vertex arrays, buffers
//*****************************************************************
void FieldObject::Init()
{
	vec4	topVertices[37];
	vec4	btmVertices[37];

	vec4	topCenter = vec4(0,fHeight,0,1);
	vec4	btmCenter = vec4(0,0,0,1);


	for (int ii = 0; ii < 37; ii++)
	{
		GLfloat dX = GLfloat(cos(ii * 10.0 * 3.14 / 180.0)) * fRadius;
		GLfloat dZ = GLfloat(sin (ii * 10.0 * 3.14 / 180.0)) * fRadius;

		topVertices[ii]		= vec4(dX,fHeight,dZ,1.0);
		btmVertices[ii]		= vec4(dX,0.0,dZ,1.0);

	}

	for (int iT = 0; iT < 106; iT+=3)
	{
		 int iNum					= iT/3;

		//top
		v4AmbientDiffuseColor[iT]				= vec4(0.5,1.0,0.0,1.0);
		v4AmbientDiffuseColor[iT + 1]			= vec4(0.5,0.0,1.0,1.0);
		v4AmbientDiffuseColor[iT + 2]			= vec4(0.5,1.0,1.0,1.0);

		v4Vertices[iT]				= vec4(0.0,fHeight,0.0,1.0);
		v4Vertices[iT + 1]			= topVertices[iNum];
		v4Vertices[iT + 2]			= topVertices[iNum + 1];

		v3Normal[iT]				=	vec3(0.0,1.0,0.0); 
		v3Normal[iT + 1]			=	vec3(0.0,1.0,0.0);
		v3Normal[iT + 2]			=	vec3(0.0,1.0,0.0);


		v4AmbientDiffuseColor[iT + 108]			= vec4(0.5,1.0,0.0,1.0);
		v4AmbientDiffuseColor[iT + 108 + 1]		= vec4(0.5,0.0,1.0,1.0);
		v4AmbientDiffuseColor[iT + 108 + 2]		= vec4(0.5,1.0,1.0,1.0);

		v4Vertices[iT + 108]		= topVertices[iNum];
		v4Vertices[iT + 108 + 1]	= btmVertices[iNum];
		v4Vertices[iT + 108 + 2]	= btmVertices[iNum + 1];

		v3Normal[iT + 108]			=	Utility::vec4_to_vec3(normalize(v4Vertices[iT + 108]	 - topCenter)); 
		v3Normal[iT + 108 + 1]		=	Utility::vec4_to_vec3(normalize(v4Vertices[iT + 108 + 1] - btmCenter));
		v3Normal[iT + 108 + 2]		=	Utility::vec4_to_vec3(normalize(v4Vertices[iT + 108 + 2] - btmCenter));
	}
	
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
	glBufferData(GL_ARRAY_BUFFER,sizeof(v4AmbientDiffuseColor),v4AmbientDiffuseColor,GL_DYNAMIC_DRAW);
	vAmbientDiffuseColor = glGetAttribLocation(program,"vAmbientDiffuseColor");
	glEnableVertexAttribArray(vAmbientDiffuseColor);
	glVertexAttribPointer(vAmbientDiffuseColor,4,GL_FLOAT,GL_FALSE,0,0);

	glBindBuffer(GL_ARRAY_BUFFER,vbo[2]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(v3Normal),v3Normal,GL_DYNAMIC_DRAW);
	vNormal = glGetAttribLocation(program,"vNormal");
	glEnableVertexAttribArray(vNormal);
	glVertexAttribPointer(vNormal,3,GL_FLOAT,GL_FALSE,0,0);

	vSpecularColor		= glGetUniformLocation(program,"vSpecularColor");
	vSpecularExponent	= glGetUniformLocation(program,"vSpecularExponent");

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

	model_view = glGetUniformLocation(program,"model_view");
	projection = glGetUniformLocation(program,"projection");
}
//****************************************************************
//	Date:		03/10/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		FieldObject
//	Function:	Draw
//	Inputs:		none
//	Output:		none
//	Purpose:	Draw field object
//*****************************************************************
void FieldObject::Draw()
{

	if (bSimpleCollisionDetection && !bPrevSimpleCollisionDetection)
	{
		for (int ii = 0;ii < 216; ii++)
			v4AmbientDiffuseColor[ii] = vec4(1.0,0.0,0.0,1.0);

		glBindBuffer(GL_ARRAY_BUFFER,vbo[1]);
		glBufferData(GL_ARRAY_BUFFER,sizeof(v4AmbientDiffuseColor),v4AmbientDiffuseColor,GL_DYNAMIC_DRAW);
	}
	else if (!bSimpleCollisionDetection && bPrevSimpleCollisionDetection)
	{
		for (int iT = 0; iT < 106; iT+=3)
		{
			 int iNum					= iT/3;

			//top
			v4AmbientDiffuseColor[iT]				= vec4(0.5,1.0,0.0,1.0);
			v4AmbientDiffuseColor[iT + 1]			= vec4(0.5,0.0,1.0,1.0);
			v4AmbientDiffuseColor[iT + 2]			= vec4(0.5,1.0,1.0,1.0);

			v4AmbientDiffuseColor[iT + 108]			= vec4(0.5,1.0,0.0,1.0);
			v4AmbientDiffuseColor[iT + 108 + 1]		= vec4(0.5,0.0,1.0,1.0);
			v4AmbientDiffuseColor[iT + 108 + 2]		= vec4(0.5,1.0,1.0,1.0);
		}
			
		glBindBuffer(GL_ARRAY_BUFFER,vbo[1]);
		glBufferData(GL_ARRAY_BUFFER,sizeof(v4AmbientDiffuseColor),v4AmbientDiffuseColor,GL_DYNAMIC_DRAW);
	}

	bPrevSimpleCollisionDetection = bSimpleCollisionDetection;

	
	mv = mv * Translate(fX,0.0,fZ);

	glUniformMatrix4fv(model_view,1,GL_TRUE,mv);
	glUniformMatrix4fv(projection,1,GL_TRUE,p);
	glUniform4fv(vSpecularColor,1,GetSpecularColor());
	glUniform1f(vSpecularExponent,GetSpecularExponent());

	vec4	pos	= LightSourceManager::GetInstance()->GetLightNumber(0)->GetPosition();
	vec4	color	= LightSourceManager::GetInstance()->GetLightNumber(0)->GetColor();
	vec4	dir	= LightSourceManager::GetInstance()->GetLightNumber(0)->GetDirection();
	float   angle = LightSourceManager::GetInstance()->GetLightNumber(0)->GetCutoffAngle();

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
	glDrawArrays(GL_TRIANGLES,0,216);
}
//****************************************************************
//	Date:		03/10/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		FieldObject
//	Function:	CheckCollision
//	Inputs:		moving object (car) position and offset
//	Output:		none
//	Purpose:	simple object collision check
//*****************************************************************
void FieldObject::CheckCollision(GLfloat x, GLfloat z, GLfloat offset)
{
	if ((fX - offset - fRadius) < x && x < (fX + fRadius + offset) && 
		(fZ - offset - fRadius) < z && z < (fZ + fRadius + offset))
		bSimpleCollisionDetection = true;
	else
		bSimpleCollisionDetection = false;
}

