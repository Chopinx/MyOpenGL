#pragma once
#include <glad/glad.h>
// GLFW
#include <glfw3.h>
// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class Shader
{
public:
	// 程序ID
	unsigned int ID;

	// 构造器读取并构建着色器
	Shader(const char* vertexPath, const char* fragmentPath);
	// 使用/激活程序
	void use();
	// uniform工具函数
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
	void setMat4(const std::string &name, glm::mat4 value) const;
	void setVec3(const std::string &name, glm::vec3 value) const;
	~Shader();

private:
	// utility function for checking shader compilation/linking errors.
	// ------------------------------------------------------------------------
	void checkCompileErrors(unsigned int shader, std::string type);
};

inline void Shader::use()
{
	glUseProgram(ID);
}

inline void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
inline void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
inline void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
inline void Shader::setMat4(const std::string &name, glm::mat4 value) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}
inline void Shader::setVec3(const std::string &name, glm::vec3 value) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(value));
}
