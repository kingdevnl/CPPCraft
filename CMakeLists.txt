cmake_minimum_required (VERSION 3.8)


set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Release mode")
	set(VCPKG_TARGET_TRIPLET "x64-windows-static")
endif()






message(STATUS "Set VCPKG")
project(MyProject)


find_package(OpenGL)
find_package(GLEW REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)



add_executable(main src/Main.cpp src/shader/Shader.cpp src/shader/Shader.h src/utils/IOUtils.h src/utils/MathUtil.h src/mesh/Mesh.cpp src/mesh/Mesh.h src/object/GameObject.cpp src/object/GameObject.h src/lib/FastNoise.h src/lib/FastNoise.cpp src/world/World.cpp src/world/World.h src/camera/Camera.h)

target_link_libraries(main PRIVATE spdlog::spdlog glfw ${OPENGL_gl_LIBRARY} GLEW::GLEW glm)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")

set_property(TARGET main PROPERTY CXX_STANDARD 20)


file(COPY res
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})