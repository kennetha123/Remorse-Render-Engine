#include "rrepch.h"
#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer()
{
    // vertex draw. remove later.
    float vertices[] = {
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//bottom left
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//bottom right
     0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,//top right
    -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f,// top left
    };

    unsigned int indices[] =
    {
        0, 1, 3,
        3, 1, 2
    };

    shader = new OpenGLShader("Shader/triangle.vert", "Shader/triangle.frag");

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // cleaning
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

OpenGLRenderer::~OpenGLRenderer()
{
    delete shader;
}

void OpenGLRenderer::Render()
{

}

void OpenGLRenderer::Draw()
{
    shader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}