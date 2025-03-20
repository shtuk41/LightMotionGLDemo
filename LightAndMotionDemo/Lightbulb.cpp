

#include "GraphObjects.h"
//****************************************************************
//	Date:		03/20/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Lightbulb
//	Function:	Init
//	Inputs:		none
//	Output:		none
//	Purpose:	Initialize Lightbulb
//******************************************************************
void Lightbulb::Init()
{
	vec4 array1[36] = {0};
	vec4 array2[36] = {0};

	vec4 array1center = vec4(0,0,glfWidth /2.0,1);
	vec4 array2center = vec4(0,0,-glfWidth /2.0,1.0);
  
	for         (int ii = 0; ii < 36; ii++)
	{
            double dAngleRad1 = 10.0 * ii * 3.14 / 180.0;
            double dAngleRad2 = (10.0 * ii + 5.0) *  3.14 / 180.0;
 
            array1[ii] = vec4(glfRadius * cos(dAngleRad1),glfRadius * sin(dAngleRad1),glfWidth /2.0,1.0 );
            array2[ii] = vec4(glfRadius * cos(dAngleRad2),glfRadius * sin(dAngleRad2),-glfWidth /2.0,1.0);	
	}
 
	for (int iT = 0; iT < 105; iT+=3)
	{
            int iNum = iT/3;
           
			v4AmbientDiffuseColor[iT]						= !bFullLight && iT < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 1]					= !bFullLight && (iT + 1) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 2]					= !bFullLight && (iT + 2) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;

            v4Vertices[iT]							= array1[iNum];
            v4Vertices[iT + 1]						= array2[iNum];
            v4Vertices[iT + 2]						= array1[iNum + 1];

			v3Normal[iT]							= Utility::vec4_to_vec3(normalize(v4Vertices[iT] - array1center));
			v3Normal[iT + 1]						= Utility::vec4_to_vec3(normalize(v4Vertices[iT + 1] - array2center));
			v3Normal[iT + 2]						= Utility::vec4_to_vec3(normalize(v4Vertices[iT + 2] - array1center)); 

			v4AmbientDiffuseColor[iT + 108]					= !bFullLight && iT < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 1 + 108]				= !bFullLight && (iT + 1) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 2 + 108]				= !bFullLight && (iT + 2) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
 
            v4Vertices[iT + 108]                = array2[iNum];
            v4Vertices[iT + 1 + 108]			= array2[iNum + 1];
            v4Vertices[iT + 2 + 108]			= array1[iNum + 1];

			v3Normal[iT + 108]						= Utility::vec4_to_vec3(normalize(v4Vertices[iT + 108]		- array2center));
			v3Normal[iT + 1 + 108]					= Utility::vec4_to_vec3(normalize(v4Vertices[iT + 1 + 108]	- array2center));
			v3Normal[iT + 2 + 108]					= Utility::vec4_to_vec3(normalize(v4Vertices[iT + 2 + 108]	- array1center)); 

			v4AmbientDiffuseColor[iT + 216]					= !bFullLight && iT < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 1 + 216]				= !bFullLight && (iT + 1) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 2 + 216]				= !bFullLight && (iT + 2) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
 
            v4Vertices[iT + 216]                = vec4(0.0,0.0,glfWidth /2.0,1.0);
            v4Vertices[iT + 1 + 216]			= array1[iNum];
            v4Vertices[iT + 2 + 216]			= array1[iNum + 1];
 
			v3Normal[iT + 216]					= vec3(0,0,1); 
			v3Normal[iT + 1 + 216]				= vec3(0,0,1); 
			v3Normal[iT + 2 + 216]				= vec3(0,0,1); 


			v4AmbientDiffuseColor[iT + 324]					= !bFullLight && iT < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 1 + 324]				= !bFullLight && (iT + 1) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 2 + 324]				= !bFullLight && (iT + 2) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;

            v4Vertices[iT + 324]                = vec4(0.0,0.0,-glfWidth/2.0,1.0);
            v4Vertices[iT + 1 + 324]			= array2[iNum + 1];
            v4Vertices[iT + 2 + 324]			= array2[iNum];
	
			v3Normal[iT + 324]					= vec3(0,0,-1); 
			v3Normal[iT + 1 + 324]				= vec3(0,0,-1); 
			v3Normal[iT + 2 + 324]				= vec3(0,0,-1); 
		
	}

	v4AmbientDiffuseColor[105]				= eState == ON ? v4OnColor : v4OffColor;
	v4AmbientDiffuseColor[106]				= eState == ON ? v4OnColor : v4OffColor;
	v4AmbientDiffuseColor[107]				= eState == ON ? v4OnColor : v4OffColor;


    v4Vertices[105]				= array1[35];
    v4Vertices[106]				= array2[35];
    v4Vertices[107]				= array1[0];

	v3Normal[105]							=  Utility::vec4_to_vec3(normalize( v4Vertices[105] - array1center)); 
	v3Normal[106]							=  Utility::vec4_to_vec3(normalize( v4Vertices[106] - array2center)); 
	v3Normal[107]							=  Utility::vec4_to_vec3(normalize( v4Vertices[107] - array1center)); 

	v4AmbientDiffuseColor[213]				= eState == ON ? v4OnColor : v4OffColor;
	v4AmbientDiffuseColor[214]				= eState == ON ? v4OnColor : v4OffColor;
	v4AmbientDiffuseColor[215]				= eState == ON ? v4OnColor : v4OffColor;
 
	v4Vertices[213]				= array2[35];
    v4Vertices[214]				= array2[0];
    v4Vertices[215]				= array1[0];

	v3Normal[213]							=  Utility::vec4_to_vec3(normalize( v4Vertices[213] - array2center)); 
	v3Normal[214]							=  Utility::vec4_to_vec3(normalize( v4Vertices[214] - array2center)); 
	v3Normal[215]							=  Utility::vec4_to_vec3(normalize( v4Vertices[215] - array1center)); 

	v4AmbientDiffuseColor[321]				= eState == ON ? v4OnColor : v4OffColor;
	v4AmbientDiffuseColor[322]				= eState == ON ? v4OnColor : v4OffColor;
	v4AmbientDiffuseColor[323]				= eState == ON ? v4OnColor : v4OffColor;
 
    v4Vertices[321]           =  vec4(0.0,0.0,glfWidth/2.0,1.0);
    v4Vertices[322]			= array1[35];
    v4Vertices[323]			= array1[0];

	v3Normal[321]							= vec3(0,0,1); 
	v3Normal[322]							= vec3(0,0,1); 
	v3Normal[323]							= vec3(0,0,1); 

	v4AmbientDiffuseColor[429]				= eState == ON ? v4OnColor : v4OffColor;
	v4AmbientDiffuseColor[430]				= eState == ON ? v4OnColor : v4OffColor;
	v4AmbientDiffuseColor[431]				= eState == ON ? v4OnColor : v4OffColor;

	v4Vertices[429]             = vec4(0.0,0.0,-glfWidth/2.0,1.0);
    v4Vertices[430]				= array2[0];
    v4Vertices[431]			= array2[35];

	v3Normal[429]								= vec3(0,0,-1); 
	v3Normal[430]								= vec3(0,0,-1); 
	v3Normal[431]								= vec3(0,0,-1); 



	for (int iColor = 0; iColor < 432; iColor++)
		 v4AmbientDiffuseColor[iColor] = eState == ON ? v4OnColor : v4OffColor;

	program = InitShader("vshader_assignment4.glsl","fshader_assignment4.glsl");

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
}
//****************************************************************
//	Date:		03/20/2012
//	For:		Computer Graphics Programming SEIS 750
//	Class:		Lightbulb
//	Function:	Draw
//	Inputs:		none
//	Output:		none
//	Purpose:	Draw Lightbulb
//******************************************************************
void Lightbulb::Draw()
{

	if (eState != ePrevState)
	{
		for (int iT = 0; iT < 105; iT+=3)
		{
 			v4AmbientDiffuseColor[iT]						= !bFullLight && iT < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 1]					= !bFullLight && (iT + 1) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 2]					= !bFullLight && (iT + 2) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;

 			v4AmbientDiffuseColor[iT + 108]					= !bFullLight && iT < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 1 + 108]				= !bFullLight && (iT + 1) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 2 + 108]				= !bFullLight && (iT + 2) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;

 			v4AmbientDiffuseColor[iT + 216]					= !bFullLight && iT < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 1 + 216]				= !bFullLight && (iT + 1) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 2 + 216]				= !bFullLight && (iT + 2) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
  
			v4AmbientDiffuseColor[iT + 324]					= !bFullLight && iT < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 1 + 324]				= !bFullLight && (iT + 1) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
			v4AmbientDiffuseColor[iT + 2 + 324]				= !bFullLight && (iT + 2) < 58 && eState == ON ||  bFullLight &&  eState == ON ? v4OnColor : v4OffColor;
		}

		v4AmbientDiffuseColor[105]				= eState == ON ? v4OnColor : v4OffColor;
		v4AmbientDiffuseColor[106]				= eState == ON ? v4OnColor : v4OffColor;
		v4AmbientDiffuseColor[107]				= eState == ON ? v4OnColor : v4OffColor;



		v4AmbientDiffuseColor[213]				= eState == ON ? v4OnColor : v4OffColor;
		v4AmbientDiffuseColor[214]				= eState == ON ? v4OnColor : v4OffColor;
		v4AmbientDiffuseColor[215]				= eState == ON ? v4OnColor : v4OffColor;
 


		v4AmbientDiffuseColor[321]				= eState == ON ? v4OnColor : v4OffColor;
		v4AmbientDiffuseColor[322]				= eState == ON ? v4OnColor : v4OffColor;
		v4AmbientDiffuseColor[323]				= eState == ON ? v4OnColor : v4OffColor;


		v4AmbientDiffuseColor[429]				= eState == ON ? v4OnColor : v4OffColor;
		v4AmbientDiffuseColor[430]				= eState == ON ? v4OnColor : v4OffColor;
		v4AmbientDiffuseColor[431]				= eState == ON ? v4OnColor : v4OffColor;
  
		glBindBuffer(GL_ARRAY_BUFFER,vbo[1]);
		glBufferData(GL_ARRAY_BUFFER,sizeof(v4AmbientDiffuseColor),v4AmbientDiffuseColor,GL_DYNAMIC_DRAW);
	}

	ePrevState = eState;

	mv = mv * RotateZ(glfAngle);

	glUniform1f(vSpecularExponent,GetSpecularExponent());
	glUniform4fv(vSpecularColor,1,GetSpecularColor());

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
	glDrawArrays(GL_TRIANGLES,0,432);
 
}
