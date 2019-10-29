//
// Created by Jasper on 29-10-2019.
//

#ifndef MYPROJECT_WORLD_H
#define MYPROJECT_WORLD_H
#include <vector>
#include "../object/GameObject.h"


class World {
private:
    std::vector<GameObject*> blocks;

public:
    void createWorld(int size,Mesh* mesh);
    void render(Shader* shader);

    void destroy();

};


#endif //MYPROJECT_WORLD_H
