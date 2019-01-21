#include "./Display/DisplayManager.hxx"
#include "./Input/InputHandler.hxx"

int main() {
	DisplayManager dspm(1024, 768);

	while (!glfwWindowShouldClose(dspm.getWindow())) { // @suppress("Invalid arguments")
		processInput(dspm.getWindow()); // @suppress("Invalid arguments")


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // @suppress("Function cannot be resolved")
        glClear(GL_COLOR_BUFFER_BIT); // @suppress("Type cannot be resolved")


		dspm.updateDisplay();
	}

	dspm.cleanUp();

	return(0);
}
