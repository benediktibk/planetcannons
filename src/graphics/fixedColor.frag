#version 400

out vec4 frag_colour;
uniform vec4 inputColor = vec4(1, 1, 1, 0);

void main() {
  frag_colour = inputColor;
}