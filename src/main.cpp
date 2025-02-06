#include <GLFW/glfw3.h>

#include <cstdlib>
#include <cstdio>

#include <input.h>



#include<unordered_set>
#include<string>

struct GameElement;


void start(){


}

int main(void) {
    glfwInit();

	GLFWwindow* window = glfwCreateWindow(500, 500, "", nullptr, nullptr); 
    glfwMakeContextCurrent(window);
	
    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouseButton);

	glfwSwapInterval(0);

	start();

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
        updateInputStates();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
