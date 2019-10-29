//
// Created by Jasper on 28-10-2019.
//

#include <spdlog/spdlog.h>
#include "Mesh.h"


Mesh *Mesh::createMesh(std::vector<float> positions, std::vector<int> indices) {

    auto mesh = new Mesh();

    mesh->size = indices.size();

    glGenVertexArrays(1, &mesh->vao);
    glBindVertexArray(mesh->vao);

    glGenBuffers(1, &mesh->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * positions.size(), &positions[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,0);
    mesh->vbos.push_back(mesh->vbo);

    glGenBuffers(1, &mesh->vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->vbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);
    mesh->vbos.push_back(mesh->vbo);

    spdlog::info("here");



    return mesh;
}

void Mesh::bind() {
    glBindVertexArray(vao);

}

void Mesh::render() {

    bind();
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    unbind();
}

void Mesh::unbind() {
    glBindVertexArray(0);
}

void Mesh::destroy() {

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    for(GLuint v : vbos) {
        spdlog::info("Destroy vbo: {}", v);
        glDeleteBuffers(1, &v);

    }

    glDeleteVertexArrays(1, &vao);

}
