#version 400

out vec4 frag_colour;
uniform vec4 inputColor;
uniform float ambientLight;
uniform vec3 lightPosition;
uniform vec3 cameraPosition;
uniform float specularStrength;
uniform float specularExponent;

void main() {
  frag_colour = ambientLight * inputColor;
}