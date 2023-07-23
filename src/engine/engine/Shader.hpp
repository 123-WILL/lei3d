#pragma once

#include <glad/glad.h>
#include <glm/matrix.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

namespace lei3d 
{
	class Shader {
	private:
		unsigned int m_ShaderID;

		std::unordered_map<std::string, int> m_UniformLocationCache;
	public:
		Shader();
		Shader(const char* vertexShaderPath, const char* fragShaderPath);
		
		// compile and link shader, then activate the shader
		void bind();
		void unbind();
		
		void setUniformMat4(const std::string& name, glm::mat4& matrix);
		void setInt(const std::string &name, int value); // set string value in shader to an int

	private:
		int getUniformLocation(const std::string& name);
	};
}