#include "GraphObjects.h"

const float fM_PI = 3.14159265358979323846f;

//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Head
//	Function:	INit
//	Inputs:		none
//	Output:		none
//	Purpose:	Initilalize Head
/*

 Author: Nathan Gossett
 code to generate a sphere
 Note that this code is not a complete program
 
 **/

//******************************************************************
void Head::Init()
{
	float step = static_cast<float>((360.0/10.0)*(fM_PI/180.0));

	int totalverts = int(ceil(10.0/2.0)*10.0 * 6.0);

	int k = 0;
	for(float i = -fM_PI/2.0; i<=fM_PI/2.0; i+=step){
		for(float j = -fM_PI; j<=fM_PI; j+=step){
			//triangle 1
			v4AmbientDiffuseColor[k] = vec4(1.0,1.0,1.0,1.0);
			v3Normal[k]=vec3(glfRadius*sin(j)*cos(i),glfRadius*cos(j)*cos(i),glfRadius*sin(i));
			v4Vertices[k]=   vec4(glfRadius*sin(j)*cos(i), glfRadius*cos(j)*cos(i), glfRadius*sin(i), 1.0);
			k++;
	
			v4AmbientDiffuseColor[k] = vec4(1.0,1.0,1.0,1.0);
			v3Normal[k]=vec3(glfRadius*sin(j)*cos(i + step),glfRadius*cos(j)*cos(i + step),glfRadius*sin(i + step));
			v4Vertices[k]=   vec4(glfRadius*sin(j)*cos(i+step), glfRadius*cos(j)*cos(i+step), glfRadius*sin(i+step), 1.0);
			k++;
			
			v4AmbientDiffuseColor[k] = vec4(1.0,1.0,1.0,1.0);
			v3Normal[k]=vec3(glfRadius*sin(j+step)*cos(i + step),glfRadius*cos(j+step)*cos(i + step),glfRadius*sin(i + step));
			v4Vertices[k]=   vec4(glfRadius*sin((j+step))*cos((i+step)), glfRadius*cos(j+step)*cos(i+step), glfRadius*sin(i+step), 1.0);
			k++;

			//triangle 2
			v4AmbientDiffuseColor[k] = vec4(1.0,1.0,1.0,1.0);
			v3Normal[k]=vec3(glfRadius*sin((j+step))*cos((i+step)), glfRadius*cos(j+step)*cos(i+step), glfRadius*sin(i+step));
			v4Vertices[k]=   vec4(glfRadius*sin((j+step))*cos((i+step)), glfRadius*cos(j+step)*cos(i+step), glfRadius*sin(i+step), 1.0);
			k++;

			v4AmbientDiffuseColor[k] = vec4(1.0,1.0,1.0,1.0);
			v3Normal[k]=vec3(glfRadius*sin(j+step)*cos(i), glfRadius*cos(j+step)*cos(i), glfRadius*sin(i));
			v4Vertices[k]=   vec4(glfRadius*sin(j+step)*cos(i), glfRadius*cos(j+step)*cos(i), glfRadius*sin(i), 1.0);
			k++;

			v4AmbientDiffuseColor[k] = vec4(1.0,1.0,1.0,1.0);
			v3Normal[k]=vec3(glfRadius*sin(j)*cos(i), glfRadius*cos(j)*cos(i), glfRadius*sin(i));
			v4Vertices[k]=   vec4(glfRadius*sin(j)*cos(i), glfRadius*cos(j)*cos(i), glfRadius*sin(i), 1.0);
			k++;
		}
	}

	//EYES

	GLfloat glfEyeRadius	= glfRadius / 6;
	vec4 eyearray[37]		= {0};
	vec4 leftEyeCenter		= vec4(GLfloat(-glfRadius/4.0),0,0,1);
	vec4 rightEyeCenter		= vec4(glfRadius/4,0,0,1);

	for (int ii = 0; ii < 37; ii++)
	{
		GLfloat radAngle = GLfloat(10.0 * ii *  fM_PI / 180.0);

		eyearray[ii] = vec4(glfEyeRadius * cos(radAngle),glfEyeRadius * sin(radAngle),glfRadius,1.0);	
	}

	for (int iii = 0; iii < 106; iii+=3)
	{
		int iNum = iii/3;

		v4AmbientDiffuseColor[iii + 396]			= vec4(0.0,0.0,1.0,1.0);
		v4AmbientDiffuseColor[iii + 396 + 1]		= vec4(0.0,0.0,1.0,1.0);
		v4AmbientDiffuseColor[iii + 396 + 2]		= vec4(0.0,0.0,1.0,1.0);

		v4Vertices[iii + 396]			= vec4(leftEyeCenter.x,leftEyeCenter.y,eyearray[iNum].z,1.0);
		v4Vertices[iii + 396 + 1]		= vec4(leftEyeCenter.x + eyearray[iNum].x,leftEyeCenter.y + eyearray[iNum].y,eyearray[iNum].z,1.0);
		v4Vertices[iii + 396 + 2]		= vec4(leftEyeCenter.x + eyearray[iNum + 1].x,leftEyeCenter.y + eyearray[iNum + 1].y,eyearray[iNum + 1].z,1.0);

		v3Normal[iii + 396]							= vec3(0,0,1);
		v3Normal[iii + 396 + 1]						= vec3(0,0,1);
		v3Normal[iii + 396 + 2]						= vec3(0,0,1);

		v4AmbientDiffuseColor[iii + 396 + 108]		= vec4(0.0,0.0,1.0,1.0);
		v4AmbientDiffuseColor[iii + 396 + 108 + 1]	= vec4(0.0,0.0,1.0,1.0);
		v4AmbientDiffuseColor[iii + 396 + 108 + 2]	= vec4(0.0,0.0,1.0,1.0);

		v4Vertices[iii + 396 + 108]		= vec4(rightEyeCenter.x,rightEyeCenter.y,eyearray[iNum].z,1.0);
		v4Vertices[iii + 396 + 108 + 1]	= vec4(rightEyeCenter.x + eyearray[iNum].x,rightEyeCenter.y + eyearray[iNum].y,eyearray[iNum].z,1.0);
		v4Vertices[iii + 396 + 108 + 2]	= vec4(rightEyeCenter.x + eyearray[iNum + 1].x,rightEyeCenter.y + eyearray[iNum + 1].y,eyearray[iNum + 1].z,1.0);

		v3Normal[iii + 396 + 108]					= vec3(0,0,1);
		v3Normal[iii + 396 + 108 + 1]				= vec3(0,0,1);
		v3Normal[iii + 396 + 108 + 2]				= vec3(0,0,1);

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

	glfRotAngle = 0.0;
}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Head
//	Function:	Draw
//	Inputs:		none
//	Output:		none
//	Purpose:	Draw Head
//******************************************************************
void Head::Draw()
{
	if (rx > 360.0)
		rx-= 360.0;

	if (ry > 360.0)
		ry-= 360.0;

	if (rz > 360.0)
		rz-= 360.0;

	mv = mv * Translate(tx,ty,tz);
	mv = mv * RotateX(rx);
	mv = mv * RotateY(ry);
	mv = mv * RotateZ(rz);

	

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
	glDrawArrays(GL_TRIANGLES,0,612);

}
//****************************************************************
//	Date:		03/02/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Head
//	Function:	Rotate
//	Inputs:		none
//	Output:		none
//	Purpose:	Logic handles rotating head +/- 90 degrees
//******************************************************************
void Head::Rotate(double rot)
{
		ry += GLfloat(rot);

	if (ry > 90.0)
		ry = 90.0;
	else if (ry < -90.0)
		ry = -90.0;

	glfRotAngle = ry;
}




