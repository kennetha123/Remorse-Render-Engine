#include "rrepch.h"
#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer()
{
}

OpenGLRenderer::~OpenGLRenderer()
{
}

void OpenGLRenderer::Render()
{

}

void OpenGLRenderer::Draw()
{
    gameObject.transform = glm::mat4(1.0f);

    gameObject.transform = glm::scale(gameObject.transform, glm::vec3(0.25f));
    gameObject.transform = glm::rotate(gameObject.transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

    gameObject.Draw();
}