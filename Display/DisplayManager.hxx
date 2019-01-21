#ifndef DISPLAY_DISPLAYMANAGER_HXX_
#define DISPLAY_DISPLAYMANAGER_HXX_

#include <GLFW/glfw3.h>

class DisplayManager {
	/*
	 * Variables needed
	 */
public:
protected:
	// Window identifier
	GLFWwindow* window;

	/*
	 * Private methods
	 */
private:
	// Function to create the display
	int createDisplay();
	// Set the width and height of our display
	void setWidthAndHeight(int width, int height);
	//
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
protected:
	// Variables to store the width and height of our display
	int width;
	int height;

	/*
	 * Constructor
	 */
public:
	// Constructor
	DisplayManager(int height, int width);
	// Function to update the display on every frame
	void updateDisplay();
	// Function to be called once the display has been closed
	void cleanUp();
	// Function to get the window identifier
	GLFWwindow *getWindow();
};

#endif /* DISPLAY_DISPLAYMANAGER_HXX_ */
