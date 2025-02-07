#pragma once

#include <glad/glad.h>

#include <fstream>
#include <glm/gtc/type_ptr.hpp>
#include <glm/matrix.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

namespace lei3d
{

	class Shader
	{
	private:
		unsigned int m_ShaderID;

		std::unordered_map<std::string, int> m_UniformLocationCache;

	public:
		Shader();
		Shader(const char* vertexShaderPath, const char* fragShaderPath, const char* geomShaderPath = nullptr);

		// compile and link shader, then activate the shader
		void bind() const;
		void unbind() const;

		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const; // set string value in shader to an int
		void setFloat(const std::string& name, float value) const;

		void setVec2(const std::string& name, const glm::vec2& value) const;
		void setVec3(const std::string& name, const glm::vec3& value) const;
		void setVec4(const std::string& name, const glm::vec4& value) const;
		void setUniformMat4(const std::string& name, const glm::mat4& matrix) const;

		unsigned int getShaderID() const { return m_ShaderID; }

	private:
		int getUniformLocation(const std::string& name) const;
	};

} // namespace lei3d