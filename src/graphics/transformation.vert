#version 400

in vec3 vp;
uniform mat4 transformationLocalToWorld = mat4(1.0);
uniform mat4 transformationWorldToView = mat4(1.0);
uniform mat4 transformationViewToPerspective = mat4(1.0);

void main() { 
  gl_Position = transformationViewToPerspective * transformationWorldToView * transformationLocalToWorld * vec4(vp, 1.0);
}