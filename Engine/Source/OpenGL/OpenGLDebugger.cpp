#include "rrepch.h"
#include "OpenGLDebugger.h"

GLenum OpenGLDebugger::glCheckError(const char* file, int line)
{
    GLenum errorCode;
    while ((errorCode = glGetError()) != GL_NO_ERROR)
    {
        std::string error;
        switch (errorCode)
        {
        case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
        case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
        case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
            //GLAD issue , fix later

            //case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break; 
            //case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;

        case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
        case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
        }
        spdlog::error("Error at file : {0} line {1} : {2}", file, line, error);
    }
    return errorCode;
}