#version 400

out vec4 frag_colour;
uniform vec4 inputColor;

void main() {
  frag_colour = inputColor;
}