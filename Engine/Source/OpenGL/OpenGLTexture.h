#pragma once

class OpenGLTexture
{
public:
	OpenGLTexture();
	~OpenGLTexture();

public:
	std::vector<unsigned int> texture;

private:
	unsigned char* data;
	int width;
	int height;
	int nrChannels;

};