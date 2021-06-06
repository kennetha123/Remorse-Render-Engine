#include "rrepch.h"
#include "OpenGLShader.h"

OpenGLShader::OpenGLShader(const char* vertexPath, const char* fragmentPath)
{
    // filestream start where project location started.
    std::ifstream vertexShaderFile(vertexPath);
    std::ifstream fragmentShaderFile(fragmentPath);

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

void OpenGLShader::use()
{
    glUseProgram(shaderProgram);
}

void OpenGLShader::SetUniformBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), (int)value);
}

void OpenGLShader::SetUniformInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void OpenGLShader::SetUniformFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
}

void OpenGLShader::ShaderAssert(unsigned int shader)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
#ifdef RRE_DEBUG
        spdlog::error("ERROR::SHADER::COMPILATION_FAILED : {0}", infoLog);
#endif
    }
}
