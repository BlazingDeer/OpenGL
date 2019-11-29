#include "ShaderPipeline.h"

ShaderPipeline::ShaderPipeline(const char* Vertex_Shader_File, const char* Fragment_Shader_File, const char* Geometry_Shader_File=nullptr):
	m_VertexShader(Vertex_Shader_File,GL_VERTEX_SHADER),
	m_FragmentShader(Fragment_Shader_File, GL_FRAGMENT_SHADER),
	m_GeometryShader(Geometry_Shader_File)
{

}

bool ShaderPipeline::CompileShaders()
{
	
	if (!m_VertexShader.CompileShader() || !m_FragmentShader.CompileShader()) return false;
	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, m_VertexShader.m_shaderObject);
	glAttachShader(m_ShaderProgram, m_FragmentShader.m_shaderObject);
	if(m_GeometryShader.CompileShader()) glAttachShader(m_ShaderProgram, m_GeometryShader.m_shaderObject);
	glLinkProgram(m_ShaderProgram);
	m_VertexShader.DeleteShader();
	m_FragmentShader.DeleteShader();
	int success;
	char infoLog[512];
	glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(m_ShaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
		return false;
	}

	m_Compiled = true;

	return true;
}

void ShaderPipeline::UseProgram()
{
	if (m_Compiled)
	{
		glUseProgram(m_ShaderProgram);
	}
}
