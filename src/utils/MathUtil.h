//
// Created by Jasper on 28-10-2019.
//
#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <spdlog/spdlog.h>
#include "../object/GameObject.h"


namespace MathUtil {

    inline float fov = 90.f;
    inline float nearPlane = 0.1f;
    inline float farPlane = 1000.f;

    inline static glm::mat4 getProjectionMatrix(int WIDTH, int HEIGHT) {
        glm::mat4 projectionMatrix(1.f);
        projectionMatrix = glm::perspective(glm::radians(fov), (float) WIDTH / HEIGHT, nearPlane, farPlane);
        return projectionMatrix;
    }

    inline static glm::mat4 getModelMatrix(GameObject *object) {

        glm::mat4 modelMatrix(1.f);
        glm::vec3 rotation = object->getRotation();
        glm::vec3 pos = object->getPosition();
        float scale = object->getScale();



        modelMatrix = glm::translate(modelMatrix, object->getPosition());
	
        if(rotation.x > 0 || rotation.y > 0 || rotation.z > 0) {
			modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f)); //rot x
			modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f)); //rot y
			modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f)); //rot z
		}
		
		modelMatrix = glm::scale(modelMatrix, glm::vec3(scale));


        return modelMatrix;
    }

}

