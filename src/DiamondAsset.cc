#include "DiamondAsset.h"
#include "GameWorld.h"

DiamondAsset::DiamondAsset(GLfloat x, GLfloat y, GLfloat z) {

  // model coordinates, origin at centre.
  GLfloat vertex_buffer [] {
     -1    , 0    , 0//0
     ,1    , 0    , 0 //1
     ,0    ,-1    , 0 //2
<<<<<<< HEAD
     ,0   , 1    , 0 //3
     ,0    ,0     ,-1 //4
     ,0    ,0     , 1 //5 = End of Diamond
  };
  
  // Colour Buffer Red
  GLfloat colour_buffer[] = {

     0.0f, 1.0f, 1.0f,
     0.0f, 1.0f, 1.0f,
     0.0f, 1.0f, 1.0f,
     0.0f, 1.0f, 1.0f,
     0.0f, 1.0f, 1.0f,
     0.0f, 1.0f, 1.0f,
     0.0f, 1.0f, 1.0f,
     0.0f, 1.0f, 1.0f

  };
    colour_buffer_length = 24;
=======
     ,0    , 1    , 0 //3
     ,0    ,0     ,-1 //4
     ,0    ,0     , 1 //5 = End of Diamond
  };
>>>>>>> Voxel

  element_buffer_length = 24;
  GLuint element_buffer []  {
      0, 3, 5	
    , 3, 1, 5
    , 0, 5, 2	
    , 5, 1, 2
    , 0, 3, 4
    , 3, 1, 4
    , 0, 4, 2
    , 4, 1, 2

  };

  // Transfer buffers to the GPU
  //

  // create buffer
  glGenBuffers(1, &vertex_buffer_token);

  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 48, vertex_buffer, GL_STATIC_DRAW);

<<<<<<< HEAD
  // Colour buffer 
  glGenBuffers(1, &colour_buffer_token);
  glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, colour_buffer_length, colour_buffer, GL_STATIC_DRAW);

=======
>>>>>>> Voxel
  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * element_buffer_length, element_buffer, GL_STATIC_DRAW);
}

DiamondAsset::~DiamondAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
// define symbol to be nothing
#define checkGLError()
#endif


void DiamondAsset::checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
}

void DiamondAsset::Draw(GLuint program_token) {
  if(!glIsProgram(program_token)) {
    std::cerr << "Drawing Diamond with invalid program" << std::endl;
    return;
  }
  GLint validation_ok;
  glValidateProgram(program_token);
  glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);
  if(!validation_ok) {
    GLint maxLength = 0;
    glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

    //The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

    std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }
    exit(-1);
  }

  GLuint position_attrib = glGetAttribLocation(program_token, "position");
  checkGLError();

  glUseProgram(program_token);
  checkGLError();

  // use the previously transferred buffer as the vertex array.  This way
  // we transfer the buffer once -- at construction -- not on every frame.
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
                        position_attrib,               /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );
  glEnableVertexAttribArray(position_attrib);

  checkGLError();

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glDrawElements(
                 GL_TRIANGLES,
                 element_buffer_length,
                 GL_UNSIGNED_INT,
                 (GLvoid*) 0
                 );

  checkGLError();

  glDisableVertexAttribArray(position_attrib);
}
