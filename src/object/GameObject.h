//
// Created by Jasper on 29-10-2019.
//

#ifndef MYPROJECT_GAMEOBJECT_H
#define MYPROJECT_GAMEOBJECT_H

#include "../mesh/Mesh.h"
#include "../shader/Shader.h"
#include <vector>
#include <glm/glm.hpp>

class GameObject {


private:
    glm::mat4 worldMatrix = glm::mat4();

    std::vector<Mesh *> meshes;
    glm::vec3 position;
    glm::vec3 rotation;


    float scale;

public:
    GameObject();

    void render(Shader *shader);

    inline const glm::vec3 &getPosition() const {
        return position;
    }

    inline void setPosition(const glm::vec3 &position) {
        GameObject::position = position;
    }

    inline const glm::vec3 &getRotation() const {
        return rotation;
    }

    inline void setRotation(const glm::vec3 &rotation) {
        GameObject::rotation = rotation;
    }

    inline float getScale() const {
        return scale;
    }

    inline void setScale(float scale) {
        GameObject::scale = scale;
    }


    inline void setPosition(float x, float y, float z) {
        setPosition(glm::vec3(x, y, z));
    }

    inline void setRotation(float x, float y, float z) {
        setRotation(glm::vec3(x, y, z));
    }

    inline void addMesh(Mesh *mesh) {
        this->meshes.push_back(mesh);
    }
    inline void setWorldMatrix(glm::mat4 matrix) {
        this->worldMatrix = matrix;
    }


    void destroy();
};


#endif //MYPROJECT_GAMEOBJECT_H
