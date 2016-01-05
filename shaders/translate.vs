#version 130

in vec3 position;

out vec3 frag_color;

uniform mat4 Camera_Projection;
uniform mat4 Camera_View;
uniform mat4 Camera_Model;
uniform mat4 color;


void main() 
{
      gl_Position = (Camera_Projection * Camera_View * Camera_Model) * vec4(position, 1.0f);
      frag_color =  vec3(0.0, 1.0, 0.0); // Green
}
