#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "DisplayManager.hxx"

int DisplayManager::createDisplay() {

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->window = glfwCreateWindow(width, height, "C++ port", glfwGetPrimaryMonitor(), NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return(-1);
	}
	glfwMakeContextCurrent(this->window);
	glfwSetFramebufferSizeCallback(window, DisplayManager::framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return(-1);
	}

	return(0);
}
void DisplayManager::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void DisplayManager::setWidthAndHeight(int width, int height) {
	this->width = width;
	this->height = height;
}

DisplayManager::DisplayManager(int width, int height) {
	DisplayManager::setWidthAndHeight(width, height);
	DisplayManager::createDisplay();
}

void DisplayManager::updateDisplay() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void DisplayManager::cleanUp() {
	glfwTerminate();
}

GLFWwindow  *DisplayManager::getWindow() {
	return (this->window);
}

