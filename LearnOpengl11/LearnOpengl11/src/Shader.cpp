#include "Shader.h"

Shader::Shader(const char* file, unsigned int Type):
	m_shaderType(Type),
	m_shaderObject(0)
{
	if (file)
	{

		m_filename = file;
		std::ifstream in;
		in.open(file, std::ios::in | std::ios::binary | std::ios::ate);
		if(in.is_open())
		{

			std::streampos size = in.tellg();
			m_contents.resize(size);
			in.seekg(std::ios::beg);
			in.read(&m_contents[0], size);
			in.close();

		}
		else
		{
			std::cout << "\n\nFailed to open the FILE!\n" << file << std::endl;
		}
		
	}

}



std::string Shader::Filename()
{
	return m_filename;
}

std::string Shader::FileContents()
{
	return m_contents;
}

bool Shader::CompileShader()
{
	if (!m_contents.empty())
	{
		m_shaderObject = glCreateShader(m_shaderType);
		const char* shaderSource = m_contents.c_str();
		glShaderSource(m_shaderObject, 1, &shaderSource, NULL);
		glCompileShader(m_shaderObject);

		int success;
		char infoLog[512];
		glGetShaderiv(m_shaderObject, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(m_shaderObject, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

			return false;
		}

		m_Compiled = true;
		return true;
	}

	return false;
}

void Shader::DeleteShader()
{
	if (m_Compiled)
	{
		glDeleteShader(m_shaderObject);
	}
	m_Compiled = false;
}
