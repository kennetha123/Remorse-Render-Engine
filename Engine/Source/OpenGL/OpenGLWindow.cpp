#include "rrepch.h"
#include "OpenGLWindow.h"

void resize_callback(GLFWwindow* window, int width, int height);

OpenGLWindow::OpenGLWindow(unsigned int&& width, unsigned int&& height, std::string&& title) : window(NULL)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

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

	glEnable(GL_DEPTH_TEST);

	imgui.Init(window);
	
	render = new OpenGLRenderer();

	int nrAttrib;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttrib);
	spdlog::info("Maximum number of vertex attributes supported : {0}", nrAttrib);

	spdlog::info("Vendor	: {0}", glGetString(GL_VENDOR));
	spdlog::info("Renderer	: {0}", glGetString(GL_RENDERER));
	spdlog::info("Version	: {0}", glGetString(GL_VERSION));
}

OpenGLWindow::~OpenGLWindow()
{
	delete render;
	imgui.Destroy();
	glfwTerminate();
}


void OpenGLWindow::UpdateWindow()
{
	while (!glfwWindowShouldClose(window))
	{
		OpenGLInput::ProcessInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		// TODO: this is so bad. will fix it later.
		render->camera.Input(window);

		render->Draw();

		glfwPollEvents();
		glfwSwapBuffers(window);

	}
}

void resize_callback(GLFWwindow* window, int width, int height)
{
	glViewport(width, height, width, height);
}
