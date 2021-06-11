#version 330 core
layout(location = 0)in vec3 pos;
layout(location = 1)in vec3 color;
layout(location = 2)in vec2 texCoord;

out vec3 outColor;
out vec2 outTexCoord;

uniform mat4 transform;

void main()
{
	gl_Position = vec4(pos.x, pos.y, pos.z, 1.0) * transform;
	outColor = color;
	outTexCoord = texCoord;
}