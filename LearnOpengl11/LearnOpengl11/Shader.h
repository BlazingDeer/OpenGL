#pragma once
#include <fstream>
#include <string>
class Shader
{
public:
	
	Shader(const char* file, unsigned int Type);

private:
	const std::string filename;
	std::string contents;
	unsigned int shader_Type;
	unsigned int shader_Object;
	

};

