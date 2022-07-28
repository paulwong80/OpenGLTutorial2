// This code is to draw a point within the window of tutorial 1. The code is using opengl fixed function 
// pipeline. No shader is used here. This is to show you how the pipeline looks like . If you can 
// see the white point inside black windows with no error, you are on the track.
// Copyright by Rui @njupt.
// 2022.7

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint VAO, VBO;
static void RenderScreen(GLFWwindow *window)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, 1);
	glBindVertexArray(0);
	glfwSwapBuffers(window);
}

static void CreateVertexBuffer()
{
	GLfloat vertices[] = { 0.0f, 0.0f, 0.0f };

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

static void SetViewport(GLFWwindow* window)
{
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
	glViewport(0, 0, screenWidth, screenHeight);
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for mac

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGLTutorial2", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (GLEW_OK != glewInit())
	{
		std::cout << "Failed to init glew" << std::endl;
		glfwTerminate();
		return -1;
	}
	CreateVertexBuffer();

	while (!glfwWindowShouldClose(window))
	{
		SetViewport(window);
		glfwPollEvents();
		RenderScreen(window);
	}
	return 1;
}