#pragma once
#include "Shader.h"

class ShaderPipeline
{
	
public:

	ShaderPipeline(const char* Vertex_Shader_File, const char* Fragment_Shader_File, const char* Geometry_Shader_File);
	bool CompileShaders();
	void UseProgram();

private:
	Shader m_VertexShader;
	Shader m_FragmentShader;
	Shader m_GeometryShader;
	bool m_Compiled=false;
	unsigned int m_ShaderProgram;


};

