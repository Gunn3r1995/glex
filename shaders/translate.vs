#version 130

in vec3 position;
in vec3 color;

out vec3 frag_color;

uniform mat4 Camera_Projection;
uniform mat4 Camera_View;
uniform mat4 Camera_Model;


void main() 
{
      gl_Position = (Camera_Projection * Camera_View * Camera_Model) * vec4(position, 1.0f);
      frag_color =  color;
}
