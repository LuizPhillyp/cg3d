#include <GLFW/glfw3.h>
#include <stdio.h>
#include <cstdlib>
#include <input.h>

#include <string>
#include <vector>

#include <glm/vec3.hpp>


void init(){
	printf("Hello World\n");

}

void update(){
	if(keyDown(GLFW_KEY_ESCAPE)) exit(0);

}

int main(void) {
    glfwInit();

	GLFWwindow* window = glfwCreateWindow(500, 500, "", nullptr, nullptr); 
    glfwMakeContextCurrent(window);
	
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouseButton);

	glfwSwapInterval(0);

	init();

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		update();
	
        updateInputStates();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
