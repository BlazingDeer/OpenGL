#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
class Shader
{
	friend class ShaderPipeline;
public:
	
	Shader(const char* file=nullptr, unsigned int Type=0);
	std::string Filename();
	std::string FileContents();
	bool CompileShader();
	void DeleteShader();

private:
	std::string m_filename;
	std::string m_contents;
	unsigned int m_shaderType;
	unsigned int m_shaderObject;
	bool m_Compiled = false;
	

};

