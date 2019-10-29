#version 400 core

in vec3 pass_position;

out vec3 fragColor;


void main(void) {

    fragColor = vec3(pass_position.x+0.5, 1.0, pass_position.y+0.5);

}