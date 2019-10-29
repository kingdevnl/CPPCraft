//
// Created by Jasper on 29-10-2019.
//

#ifndef MYPROJECT_CAMERA_H
#define MYPROJECT_CAMERA_H

#include <glm/glm.hpp>
namespace Camera {
inline glm::vec3 camPos(0.f, 0.0, 2.f);
inline glm::vec3 worldUp(0.f, 1.f, 0.f);
inline glm::vec3 camFront(0.f, 0.f, -1.f);
inline glm::mat4 viewMatrix(1.f);
inline float camMoveSpeed = .1f;
inline float camRotSpeed = glm::degrees(.03f);
inline float camRot = glm::degrees(50.5f);

inline void handleCamera(GLFWwindow* window, Shader* shader) {

    if (glfwGetKey(window, GLFW_KEY_W)) {
        camPos += camMoveSpeed * camFront;

    }
    if (glfwGetKey(window, GLFW_KEY_S)) {
        camPos -= camMoveSpeed * camFront;
    }

    if (glfwGetKey(window, GLFW_KEY_A)) {
        camPos -= camMoveSpeed * glm::normalize(glm::cross(camFront, worldUp));
    }

    if (glfwGetKey(window, GLFW_KEY_D)) {
        camPos += camMoveSpeed * glm::normalize(glm::cross(camFront, worldUp));
    }
    if (glfwGetKey(window, GLFW_KEY_Q)) {

        camRot -= camRotSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_E)) {

        camRot += camRotSpeed;
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)) {

        camPos.y += camMoveSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL)) {

        camPos.y -= camMoveSpeed;
    }

    camFront.x = cos(glm::radians(camRot));
    camFront.z = sin(glm::radians(camRot));
    camFront = glm::normalize(camFront);


    viewMatrix = glm::lookAt(camPos, camPos + camFront, worldUp);


    shader->setUniformMatrix4f("viewMatrix", viewMatrix);

}
}



#endif //MYPROJECT_CAMERA_H
