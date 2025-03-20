#version 150

struct Light
{
	vec4	position;
	vec4	color;
	vec4	direction;
	float	cutoffangle;
};

in vec3 position;
in vec3 vN;

in vec4 AmbientDiffuseColor;
in vec4 SpecularColor;
in float SpecularExponent;

uniform Light lightHeadFL;
uniform Light lightHeadFR;
uniform Light lightCopRed;
uniform Light lightCopBlue;
uniform mat4 model_view;
uniform mat4 projection;

out vec4  fColor;

vec3 CalcLVector(vec4 source_position, vec3 pos)
{
	return normalize(source_position.xyz - pos.xyz);
}

vec3 HalfAngle(vec3 l, vec3 e)
{
	return normalize(l + e);
}

vec4 Diffuse(vec3 l, vec3 n, vec4 clr, vec4 direction, float cutoff)
{
	vec3 d = normalize(direction).xyz;
	float co = cos(cutoff * 3.14 / 180.0);

	if (dot(-l,d) >  co) 
		return max(dot(l,n),0.0) * AmbientDiffuseColor * clr;
	else
		return vec4(0,0,0,1);
}

vec4 Specular(vec3 n, vec3 h, vec4 clr,vec3 l, vec4 direction, float cutoff)
{
	vec3 d = normalize(direction).xyz;
	float co = cos(cutoff * 3.14 / 180.0);

	if (dot(-l,d) >  co) 
		return pow(max(dot(n,h),0.0),100) * SpecularColor * clr;
	else
		return vec4(0,0,0,1);	
}

void
main()
{

	vec4 ambient_light = vec4(0.6,0.6,0.6,1.0);

	vec3 N = normalize(vN.xyz);
	vec3 E = -normalize(position.xyz);

	vec3 L1 = CalcLVector(lightHeadFL.position, position);
	vec3 L2 = CalcLVector(lightHeadFR.position, position);

	vec3 L3 = CalcLVector(lightCopRed.position, position);
	vec3 L4 = CalcLVector(lightCopBlue.position, position);

	vec3 H1 = HalfAngle(L1,E);
	vec3 H2 = HalfAngle(L2,E);

	vec3 H3 = HalfAngle(L3,E);
	vec3 H4 = HalfAngle(L4,E);

	vec4 amb = AmbientDiffuseColor * ambient_light;
	
	vec4 diff1 = Diffuse(L1,N,lightHeadFL.color,model_view * lightHeadFL.direction,lightHeadFL.cutoffangle );
	vec4 spec1 = Specular(N,H1,lightHeadFL.color,L1,model_view * lightHeadFL.direction,lightHeadFL.cutoffangle);

	vec4 diff2 = Diffuse(L2,N,lightHeadFR.color,model_view * lightHeadFR.direction,lightHeadFR.cutoffangle);
	vec4 spec2 = Specular(N,H2,lightHeadFR.color,L2,model_view * lightHeadFR.direction,lightHeadFR.cutoffangle);

	vec4 diff3 = Diffuse(L3,N,lightCopRed.color,model_view * lightCopRed.direction,lightCopRed.cutoffangle);
	vec4 spec3 = Specular(N,H3,lightCopRed.color,L3,model_view * lightCopRed.direction,lightCopRed.cutoffangle);

	vec4 diff4 = Diffuse(L4,N,lightCopBlue.color,model_view * lightCopBlue.direction,lightCopBlue.cutoffangle);
	vec4 spec4 = Specular(N,H4,lightCopBlue.color,L4,model_view * lightCopBlue.direction,lightCopBlue.cutoffangle);


	if (dot(L1,N) < 0.0)
	{
		spec1 = vec4(0,0,0,1);
	}

	if (dot(L2,N) < 0.0)
	{
		spec2 = vec4(0,0,0,1);
	}

	if (dot(L3,N) < 0.0)
	{
		spec3 = vec4(0,0,0,1);
	}

	if (dot(L4,N) < 0.0)
	{
		spec4 = vec4(0,0,0,1);
	}


    fColor = amb + diff1 + diff2 + diff3 + diff4 + spec1 + spec2 + spec3 + spec4;

}
