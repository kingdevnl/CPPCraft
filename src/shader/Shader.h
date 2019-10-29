//
// Created by Jasper on 28-10-2019.
//

#ifndef MYPROJECT_SHADER_H
#define MYPROJECT_SHADER_H
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
private:
    unsigned int program, vertex, fragment;
public:
    static Shader* create(const char* name);

    void bind();


    inline unsigned int getUniform(const char* name) {
        return glGetUniformLocation(program, name);

    }

    inline void setUniform1f(const char* name, float vec) {
        glUniform1f(getUniform(name), vec);
    }

    inline void setUniform3f(const char* name, glm::vec3 vec) {
        glUniform3f(getUniform(name), vec.x, vec.y, vec.z);
    }

    inline void setUniformMatrix3f(const char* name, glm::mat3 matrix) {
        glUniformMatrix3fv(getUniform(name), 1, GL_FALSE, glm::value_ptr(matrix));
    }

    inline void setUniformMatrix4f(const char* name, glm::mat4 matrix) {
        glUniformMatrix4fv(getUniform(name), 1, GL_FALSE, glm::value_ptr(matrix));
    }


    void unbind();
    void destroy();
};


#endif //MYPROJECT_SHADER_H
