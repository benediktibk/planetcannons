#version 400

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
uniform mat4 transformationLocalToWorld = mat4(1.0);
uniform mat4 transformationWorldToView = mat4(1.0);
uniform mat4 transformationViewToPerspective = mat4(1.0);
out vec3 param_normal;
out vec3 param_fragmentPosition;

void main() { 
  gl_Position = transformationViewToPerspective * transformationWorldToView * transformationLocalToWorld * vec4(position, 1.0);
  param_normal = mat3(transpose(inverse(transformationLocalToWorld))) * normal;
  param_fragmentPosition = vec3(transformationLocalToWorld * vec4(position, 1.0));
}