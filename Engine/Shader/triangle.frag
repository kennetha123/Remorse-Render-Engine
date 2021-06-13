#version 330 core

out vec4 FragColor;
in vec2 outTexCoord;

uniform sampler2D Texture;
uniform sampler2D Texture1;

void main()
{
	FragColor = mix(texture(Texture, outTexCoord), texture(Texture1, vec2(outTexCoord.x, outTexCoord.y)), 0.2);
}