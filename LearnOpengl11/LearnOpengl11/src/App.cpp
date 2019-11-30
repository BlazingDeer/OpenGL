
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ShaderPipeline.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);


void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int main()
{
	if (!glfwInit())
		return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpengl11", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create window!";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0,0,800,600);

	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);

	

	float vertices[] = {
	-0.5f,-0.1f,0.0f,
	0.5f,-0.1f,0.0f,
	0.0f,-0.5f,0.0f

	};

	


	unsigned int indices[] = {
		0,1,2

	};

	float vertices1[] = {
	-0.3f,-0.5f,0.0f,	// bottom left 1
	-0.15f,0.5f,0.0f,	// top 1
	0.0f,-0.5f,0.0f,	//bottom right 1 and bottom left 2
	0.3f,-0.5f,0.0f,	//bottom right 2
	0.15f,0.5f,0.0f		//top 2 
	};

	unsigned int indices1[] = {
		0,1,2,
		2,3,4

	};
	
		
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	



	



	unsigned int VAO1, VBO1, EBO1;
	glGenVertexArrays(1, &VAO1);
	glGenBuffers(1, &VBO1);
	glGenBuffers(1, &EBO1);


	glBindVertexArray(VAO1);

	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO1);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);




	
	
	ShaderPipeline Pipeline("src\\shaders\\vertex.vert", "src\\shaders\\fragment.frag", nullptr);
	Pipeline.CompileShaders();
	Pipeline.UseProgram();
	ShaderPipeline Pipeline1("src\\shaders\\vertex1.vert", "src\\shaders\\fragment1.frag", nullptr);
	Pipeline1.CompileShaders();
	Pipeline1.UseProgram();


	

	std::cout<< "\n\nOPENGL VERSION: " << glGetString(GL_VERSION)<<std::endl;
	while (!glfwWindowShouldClose(window))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		Pipeline1.UseProgram();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);


		Pipeline.UseProgram();
		glBindVertexArray(VAO1);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}


	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}