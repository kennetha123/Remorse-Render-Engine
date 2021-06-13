#include "rrepch.h"
#include "OpenGLShader.h"

#if defined(RRE_DEBUG) || (_DEBUG)
#include "OpenGL/OpenGLDebugger.h"
#define glCheckError() glCheckError(__FILE__, __LINE__)
#endif

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
    ShaderAssert(vertexShader, "VERTEX");

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fs, NULL);
    glCompileShader(fragmentShader);
    ShaderAssert(fragmentShader, "FRAGMENT");

    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    ShaderAssert(shaderProgram, "PROGRAM");

    // cleaning
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
#if (defined(RRE_DEBUG) || (_DEBUG))
    OpenGLDebugger::glCheckError();
#endif

}

OpenGLShader::~OpenGLShader()
{
}

void OpenGLShader::use()
{
    glUseProgram(shaderProgram);
#if (defined(RRE_DEBUG) || (_DEBUG))
    OpenGLDebugger::glCheckError();
#endif

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

void OpenGLShader::SetUniformVec2(const std::string& name, const glm::vec2& value) const
{
    glUniform2fv(glGetUniformLocation(shaderProgram, name.c_str()), 2 * sizeof(float), &value[0]);
}

void OpenGLShader::SetUniformVec2(const std::string& name, float x, float y) const
{
    glUniform2f(glGetUniformLocation(shaderProgram, name.c_str()), x, y);
}

void OpenGLShader::SetUniformVec3(const std::string& name, const glm::vec3& value) const
{
    glUniform3fv(glGetUniformLocation(shaderProgram, name.c_str()), 3 * sizeof(float), &value[0]);
}

void OpenGLShader::SetUniformVec3(const std::string& name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z);
}

void OpenGLShader::SetUniformVec4(const std::string& name, const glm::vec4& value) const
{
    glUniform4fv(glGetUniformLocation(shaderProgram, name.c_str()), 4 * sizeof(float), &value[0]);
}

void OpenGLShader::SetUniformVec4(const std::string& name, float x, float y, float z, float w) const
{
    glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z, w);
}

void OpenGLShader::SetUniformMat2(const std::string& name, const glm::mat2& value) const
{
    glUniformMatrix2fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void OpenGLShader::SetUniformMat3(const std::string& name, const glm::mat3& value) const
{
    glUniformMatrix3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &value[0][0]);
}

void OpenGLShader::SetUniformMat4(const std::string& name, const glm::mat4& value) const
{
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, &value[0][0]);
#if (defined(RRE_DEBUG) || (_DEBUG))
    OpenGLDebugger::glCheckError();
#endif
}

void OpenGLShader::ShaderAssert(GLuint shader, const std::string& type)
{
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            spdlog::error("ERROR::SHADER_COMPILATION_ERROR of type : ", type, infoLog);
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            spdlog::error("ERROR::PROGRAM_LINKING_ERROR of type: {0} {1}" ,type ,infoLog);
        }
    }
}
