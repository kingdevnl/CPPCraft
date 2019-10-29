//
// Created by Jasper on 29-10-2019.
//

#include <spdlog/spdlog.h>
#include "World.h"
#include "../lib/FastNoise.h"
#include "../utils/MathUtil.h"

void World::createWorld(int size, Mesh *mesh) {

    FastNoise noise = FastNoise(rand());

    noise.SetNoiseType(FastNoise::Perlin);


    for (int x = 0; x < size; x++) {
        for (int z = 0; z < size; z++) {
            auto block = new GameObject();
            auto block2 = new GameObject();

            float perlin = noise.GetPerlin(x,z);

            perlin = floor(perlin*100.);

            block->setPosition(x, -2+perlin, z);
            block->setScale(1.f);
            block->addMesh(mesh);
            block->setWorldMatrix(MathUtil::getModelMatrix(block));
            blocks.push_back(block);



            block2->setPosition(x, -3+perlin, z);
            block2->setScale(1.f);
            block2->addMesh(mesh);
            block2->setWorldMatrix(MathUtil::getModelMatrix(block2));

            blocks.push_back(block2);


        }
    }


}

void World::render(Shader *shader) {

    for (GameObject *obj : blocks) {
        obj->render(shader);
    }

}

void World::destroy() {

    if (blocks.size() > 0) {
        blocks[0]->destroy();

    }


}
