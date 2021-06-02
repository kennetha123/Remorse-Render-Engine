#include "rrepch.h"
#include "OpenGLRenderer.h"

void OpenGLRenderer::Render()
{
    // vertex draw. remove later.
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,//bottom left
     0.5f, -0.5f, 0.0f,//bottom right
     0.5f,  0.5f, 0.0f,//top right
    -0.5f,  0.5f, 0.0f// top left
    };

    unsigned int indices[] =
    {
        0, 1, 3,
        3, 1, 2
    };

    //Shaders
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

    // vertex buffers and binding
    {
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cleaning
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
}

void OpenGLRenderer::Draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void OpenGLRenderer::ShaderAssert(unsigned int shader)
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
