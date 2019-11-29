#include "Shader.h"

Shader::Shader(const char* file, unsigned int Type): filename(file), shader_Type(Type)
{
	std::ifstream in(file, std::ios::in | std::ios::binary);
	in.seekg(std::ios::end);
	contents.resize(in.tellg());
	in.seekg(std::ios::beg);
	in.read(&contents[0], contents.size());
	in.close();
}