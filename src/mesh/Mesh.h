//
// Created by Jasper on 28-10-2019.
//

#ifndef MYPROJECT_MESH_H
#define MYPROJECT_MESH_H

#include <vector>
#include <GL/glew.h>

class Mesh {
private:
    GLuint vao, vbo;
    int size;

    std::vector<GLuint> vbos;
public:
    static Mesh *createMesh(std::vector<float> positions, std::vector<int> indices);

    void bind();
    void render();
    void unbind();

    void destroy();
};


#endif //MYPROJECT_MESH_H
