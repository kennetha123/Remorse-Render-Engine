#include "rrepch.h"
#include "OpenGLWindow.h"

void resize_callback(GLFWwindow* window, int width, int height);

OpenGLWindow::OpenGLWindow(unsigned int&& width, unsigned int&& height, std::string&& title) : window(NULL)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Init GLFW
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	if (window == NULL)
	{
		spdlog::error("GLFW not initialize");
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, resize_callback);

	// Init Glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		spdlog::error("GLAD not initialize");
	}

	render = new OpenGLRenderer();

	int nrAttrib;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttrib);
	spdlog::info("Maximum number of vertex attributes supported : {0}", nrAttrib);
}

OpenGLWindow::~OpenGLWindow()
{
	delete render;
	glfwTerminate();
}

void OpenGLWindow::UpdateWindow()
{
	while (!glfwWindowShouldClose(window))
	{
		input.ProcessInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		render->Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(width, height, width, height);
}
