#include "rrepch.h"
#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer() :
    fieldOfView(45.0f)
{
    gameObject.reserve(10);

    for (int i = 0; i < 10; i++)
    {
        gameObject.push_back(go);
    }

    for (int i = 0; i < 3; i++)
    {
        viewPosition.push_back(0.0f);
        objectPosition.push_back(0.0f);
    }

    cubePositions = {
    glm::vec3(0.0f,  0.0f,  0.0f),
    glm::vec3(2.0f,  5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3(2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3(1.3f, -2.0f, -2.5f),
    glm::vec3(1.5f,  2.0f, -2.5f),
    glm::vec3(1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    shader = new OpenGLShader("Shader/triangle.vert", "Shader/triangle.frag");
}

OpenGLRenderer::~OpenGLRenderer()
{
    delete shader;
}

void OpenGLRenderer::Draw()
{
    // need to pass to 1 so it reset and won't go crazy (since this is an update)
    view                    = glm::mat4(1.0f);
    projection              = glm::mat4(1.0f);

    view = glm::translate(view, glm::vec3(viewPosition[0], viewPosition[1], viewPosition[2]));
    projection = glm::perspective(glm::radians(fieldOfView), 1280.0f / 720.0f, 0.1f, 100.0f);
    
    shader->SetUniformMat4("view", view);
    shader->SetUniformMat4("projection", projection);

    for (int i = 1; i < 10; i++)
    {
        gameObject[i].Init();
        gameObject[i].SetPosition(cubePositions[i]);
        float angle = 20.0f * i;
        gameObject[i].SetRotation(angle, glm::vec3(0.5f, 1.0f, 0.0f));
        gameObject[i].Draw();
    }
    
    // Don't forget to use Init, or matrix won't reset and cause problem.
    gameObject[0].Init();
    gameObject[0].SetPosition(glm::vec3(objectPosition[0], objectPosition[1], objectPosition[2]));
    gameObject[0].Draw();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("View Matrix");
    
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::InputFloat3("Position", viewPosition.data());

    ImGui::End();

    ImGui::Begin("Projection Matrix");

    ImGui::InputFloat("Field of View", &fieldOfView);

    ImGui::End();

    ImGui::Begin("First Object Matrix");

    ImGui::InputFloat3("Position", objectPosition.data());

    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

}