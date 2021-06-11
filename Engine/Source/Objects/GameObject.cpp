#include "rrepch.h"
#include "GameObject.h"

GameObject::GameObject() :
transform(1.0f)

{
    // vertex draw. remove later.
    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    vertexBuffer.SetData(vertices, sizeof(vertices));
    indexBuffer.SetData(indices, sizeof(indices));
    vertexBuffer.Bind();
    indexBuffer.Bind();

    shader = new OpenGLShader("Shader/triangle.vert", "Shader/triangle.frag");
    texture = new OpenGLTexture();
    
    shader->use();
    shader->SetUniformInt("Texture1", 1);
}

GameObject::~GameObject()
{
    delete shader;
    delete texture;
}

void GameObject::Draw()
{
    shader->use();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture->texture[0]);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture->texture[1]);

    shader->SetUniformMat4("transform", transform);

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
