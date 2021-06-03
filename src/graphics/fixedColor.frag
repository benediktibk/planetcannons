#version 400

out vec4 frag_colour;
in vec3 param_normal;
in vec3 param_fragmentPosition;
uniform vec4 inputColor = vec4(1, 1, 1, 0);
uniform float ambientLight = 1;
uniform vec3 lightPosition = vec3(0, 0, 0);
uniform vec3 cameraPosition = vec3(0, 0, 0);
uniform float specularStrength = 0;
uniform float specularExponent = 1;

void main() {
  vec3 lightDirection = normalize(lightPosition - param_fragmentPosition);
  float diffuseFactor = max(dot(param_normal, lightDirection), 0.0);
  frag_colour = (diffuseFactor + ambientLight) * inputColor;
}