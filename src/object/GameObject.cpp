//
// Created by Jasper on 29-10-2019.
//

#include "GameObject.h"


GameObject::GameObject() {

    this->setScale(1.f);
    this->setPosition(0,0,-2.f);
    this->setRotation(0,0,0);

}


void GameObject::render(Shader *shader) {


    shader->setUniformMatrix4f("modelMatrix", worldMatrix);

    for(Mesh* mesh : meshes) {
        mesh->render();
    }

}

void GameObject::destroy() {

    for(Mesh* m : meshes) {
        m->destroy();
    }

}

