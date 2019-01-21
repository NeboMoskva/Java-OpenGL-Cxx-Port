#include "./Display/DisplayManager.hxx"
#include "./Input/InputHandler.hxx"

int main() {
	DisplayManager dspm(1024, 768);

	while (!glfwWindowShouldClose(dspm.getWindow())) {
		processInput(dspm.getWindow());


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


		dspm.updateDisplay();
	}

	dspm.cleanUp();

	return(0);
}
