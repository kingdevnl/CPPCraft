//
// Created by Jasper on 28-10-2019.
//

#include "Shader.h"

#include <string>
#include "../utils/IOUtils.h"
#include <filesystem>

const char* getShaderError(int shader) {
    int size;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);
    char* msg = new char[size];
    glGetShaderInfoLog(shader, size, &size, msg);
    return msg;

}

void compileShader(GLuint shader, GLenum type) {

    glCompileShader(shader);
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE) {
        spdlog::error("Failed to compile shader {}", getShaderError(shader));
        std::cin.get();
        exit(1);
    }
    spdlog::info("Compiled shader {}", shader);
}

Shader *Shader::create(const char *name) {
    auto shader = new Shader();

    shader->program = glCreateProgram();
    shader->bind();



    std::vector<char> vertexSrc = IOUtils::readFile(
            std::string("./res/shaders/")
            .append(name)
            .append("/vertex.glsl")
            .c_str()
    );
    std::vector<char> fragmentSrc = IOUtils::readFile(
            std::string("./res/shaders/")
                    .append(name)
                    .append("/fragment.glsl")
                    .c_str()
    );


    shader->vertex = glCreateShader(GL_VERTEX_SHADER);
    shader->fragment = glCreateShader(GL_FRAGMENT_SHADER);

    const char* v = vertexSrc.data();
    const char* f = fragmentSrc.data();
    glShaderSource(shader->vertex, 1, &v, NULL);
    glShaderSource(shader->fragment, 1, &f, NULL);

    compileShader(shader->vertex, GL_VERTEX_SHADER);
    compileShader(shader->fragment, GL_FRAGMENT_SHADER);

    glAttachShader(shader->program, shader->vertex);
    glAttachShader(shader->program, shader->fragment);

    glLinkProgram(shader->program);
    glValidateProgram(shader->program);


    spdlog::info("Created shader {0} vertex: {1} fragment: {2}", shader->program, shader->vertex, shader->fragment);
    shader->unbind();


    return shader;
}

void Shader::bind() {
    glUseProgram(this->program);
}

void Shader::unbind() {
    glUseProgram(0);
}

void Shader::destroy() {
    glDetachShader(program, vertex);
    glDetachShader(program, fragment);
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    glDeleteProgram(program);
    spdlog::info("Destroyed shader {0}", program);
}
