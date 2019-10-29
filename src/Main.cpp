// GLTest.cpp : Defines the entry point for the application.
//

#include <spdlog/spdlog.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader/Shader.h"
#include "utils/IOUtils.h"
#include "utils/MathUtil.h"
#include "mesh/Mesh.h"
#include "world/World.h"
#include "camera/Camera.h"

float speed = 0.05f;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}


int main() {

    int WIDTH = 1080;
    int HEIGHT = 720;

    glfwInit();
    spdlog::info("Creating window.");

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Window", nullptr, nullptr);


    glfwMakeContextCurrent(window);
    glfwSwapInterval( 0 );
    glewInit();
    glfwSetKeyCallback(window, key_callback);

    Shader *shader = Shader::create("static");

    glfwShowWindow(window);


    std::vector<float> positions{
            // VO
            -0.5f, 0.5f, 0.5f,
            // V1
            -0.5f, -0.5f, 0.5f,
            // V2
            0.5f, -0.5f, 0.5f,
            // V3
            0.5f, 0.5f, 0.5f,
            // V4
            -0.5f, 0.5f, -0.5f,
            // V5
            0.5f, 0.5f, -0.5f,
            // V6
            -0.5f, -0.5f, -0.5f,
            // V7
            0.5f, -0.5f, -0.5f,
    };
    std::vector<int> indices{
            // Front face
            0, 1, 3, 3, 1, 2,
            // Top Face
            4, 0, 3, 5, 4, 3,
            // Right face
            3, 2, 7, 5, 3, 7,
            // Left face
            6, 1, 0, 6, 0, 4,
            // Bottom face
            2, 1, 6, 2, 6, 7,
            // Back face
            7, 6, 4, 7, 4, 5,
    };

    Mesh *mesh = Mesh::createMesh(positions, indices);

    World* world = new World();
    world->createWorld(200, mesh);




    shader->bind();
    glm::mat4 projectionMatrix(1.f);


    shader->setUniformMatrix4f("projectionMatrix", MathUtil::getProjectionMatrix(WIDTH, HEIGHT));
    shader->unbind();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        shader->bind();

        world->render(shader);




        Camera::handleCamera(window, shader);


        shader->unbind();
        glfwSwapBuffers(window);
        glfwPollEvents();

    }


    world->destroy();

    shader->destroy();
    glfwDestroyWindow(window);
    glfwTerminate();


    return EXIT_SUCCESS;
}
