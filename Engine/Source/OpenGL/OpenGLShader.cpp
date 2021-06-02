#include "rrepch.h"
#include "OpenGLShader.h"

OpenGLShader::OpenGLShader()
{
    // filestream start where project location started.
    std::ifstream vertexShaderFile("Shader/triangle.vert");
    std::ifstream fragmentShaderFile("Shader/triangle.frag");
    std::stringstream vertexStream;
    std::stringstream fragmentStream;
    std::string vertexSource;
    std::string fragmentSource;

    vertexStream << vertexShaderFile.rdbuf();
    fragmentStream << fragmentShaderFile.rdbuf();
    vertexShaderFile.close();
    fragmentShaderFile.close();

    vertexSource = vertexStream.str();
    fragmentSource = fragmentStream.str();

    // need to move to const char ptr since there is no way to send c_str
    // directly to shaderSource.
    const char* vs = vertexSource.c_str();
    const char* fs = fragmentSource.c_str();


    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vs, NULL);
    glCompileShader(vertexShader);
    ShaderAssert(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fs, NULL);
    glCompileShader(fragmentShader);
    ShaderAssert(fragmentShader);

    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // cleaning
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

OpenGLShader::~OpenGLShader()
{
}

void OpenGLShader::ShaderAssert(unsigned int shader)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}
