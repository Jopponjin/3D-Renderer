#version 460 core

// Outputs colors in RGBA
out vec4 FragColor;

// Imports the current position from the Vertex Shader
in vec3 currentPos;
// Imports the normal from the Vertex Shader
in vec3 Normal;
// Imports the color from the Vertex Shader
in vec3 color;
// Imports the texture coordinates from the Vertex Shader
in vec2 texCoord;

//Selectec the lighting type.
uniform int type = 1;
// Gets the Texture Units from the main function
uniform sampler2D diffuse0;
uniform sampler2D specular0;
// Gets the color of the light from the main function
uniform vec4 lightColor;
// Gets the position of the light from the main function
uniform vec3 lightPos;
// Gets the position of the camera from the main function
uniform vec3 camPos;

float near = 0.1f;
float far = 100.0f;

float ambientStrength = 1.0;
float specularStrength = 0.5;
float Roughness = 32.0;
vec3 customObjectColor;
vec3 lightingColor = vec3(1.0,1.0,1.0);

vec4 directionalLight()
{
	// Diffuse lighting.
	vec3 normal = normalize(Normal);
    vec3 ambient = ambientStrength * lightingColor;
	float diffuse = max(dot(normal, lightPos), 0.0f);

	//Specular lighting
	vec3 viewDirection = normalize(camPos - currentPos);
	vec3 reflectionDirection = reflect(-lightPos, normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), Roughness);
	float specular = specAmount * specularStrength;
	

	return (texture(diffuse0, texCoord) * (diffuse + ambientStrength) + texture(specular0, texCoord).r * specular) * lightColor;
}

vec4 pointLight()
{	
	// used in two variables so I calculate it here to not have to do it twice
	vec3 lightVec = lightPos - currentPos;

	// intensity of light with respect to distance
	float dist = length(lightVec);
	float a = 0.05;
	float b = 0.01;
	float inten = 1.0f / (a * dist * dist + b * dist + 1.0f);

	// ambient lighting
	float ambient = 0.5f;

	// diffuse lighting
	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(lightVec);
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	// specular lighting
	float specularLight = 0.1f;
	vec3 viewDirection = normalize(camPos - currentPos);
	vec3 reflectionDirection = reflect(-lightDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
	float specular = specAmount * specularLight;

	return (texture(diffuse0, texCoord) * (diffuse * inten + ambient) + texture(specular0, texCoord).r * specular * inten) * lightColor;
}

vec4 spotLight()
{
	// controls how big the area that is lit up is
	float outerCone = 0.90f;
	float innerCone = 0.95f;

	// ambient lighting
	float ambient = 0.5f;

	// diffuse lighting
	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(lightPos - currentPos);
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	// specular lighting
	float specularLight = 0.1f;
	vec3 viewDirection = normalize(camPos - currentPos);
	vec3 reflectionDirection = reflect(-lightDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
	float specular = specAmount * specularLight;

	// calculates the intensity of the crntPos based on its angle to the center of the light cone
	float angle = dot(vec3(0.0f, -1.0f, 0.0f), -lightDirection);
	float inten = clamp((angle - outerCone) / (innerCone - outerCone), 0.0f, 1.0f);

	return (texture(diffuse0, texCoord) * (diffuse * inten + ambient) + texture(specular0, texCoord).r * specular * inten) * lightColor;
}

vec4 depthPass()
{
	float linearDepth = (2.0 * near * far) / (far + near - (gl_FragCoord.z * 2.0 - 1.0) * (far - near));

	return vec4(vec3(linearDepth/ far), 1.0f);
}

void main()
{
//Outputs final color
	 if(type == 0)
	 {
		FragColor = directionalLight();
	 }
	 else if(type == 1)
	 {
		FragColor = pointLight();
	 }
	 else if (type == 2)
	 {
		FragColor = spotLight();
	 }	
}