#version 400

in vec3 vp;
uniform mat4 transformationMatrix = mat4(1.0);

void main() { 
  gl_Position = transformationMatrix * vec4(vp, 1.0);
}