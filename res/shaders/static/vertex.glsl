#version 400

in vec3 position;

uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;

out vec3 pass_position;

void main() {

    vec4 worldPos = modelMatrix * vec4(position, 1.f);
    gl_Position = projectionMatrix * viewMatrix  * worldPos;
    pass_position = position;

}