#include "LeavesAsset.h"

LeavesAsset::LeavesAsset(glm::vec3 xyzPosition) : GameAsset(xyzPosition) {

  //////////////////////////////////////////////////////////////////////////////////////////
  /// model coordinates, origin at centre.
  /// Sets cordinates to a Cube with the center point 0.0 
  /// but moved to where the x, y, z variables calls them
  /// from the gameworld class through the GLfloat x,y,z variables.
  //////////////////////////////////////////////////////////////////////////////////////////
  GLfloat vertex_buffer [] {
      0.5f + xyzPosition.x  , 0.5f + xyzPosition.y  , -0.5f + xyzPosition.z
    , 0.5f + xyzPosition.x  ,-0.5f + xyzPosition.y  , -0.5f + xyzPosition.z
    ,-0.5f + xyzPosition.x  , 0.5f + xyzPosition.y  , -0.5f + xyzPosition.z
    ,-0.5f + xyzPosition.x  ,-0.5f + xyzPosition.y  , -0.5f + xyzPosition.z
    , 0.5f + xyzPosition.x  , 0.5f + xyzPosition.y  ,  0.5f + xyzPosition.z
    , 0.5f + xyzPosition.x  ,-0.5f + xyzPosition.y  ,  0.5f + xyzPosition.z
    ,-0.5f + xyzPosition.x  , 0.5f + xyzPosition.y  ,  0.5f + xyzPosition.z
    ,-0.5f + xyzPosition.x  ,-0.5f + xyzPosition.y  ,  0.5f + xyzPosition.z
  };
  GLfloat vertex_buffer_length = sizeof(vertex_buffer);
  //////////////////////////////////////////////////////////////////////////////////////////
  ///  Color Buffer.
  ///  Colour of Cube Camerone Green & Lawn Green
  ///  Uses RGB values to set the colour.
  //////////////////////////////////////////////////////////////////////////////////////////
  GLfloat colour_buffer[] = {

     0.000f, 0.090f, 0.004f, 
     0.058f, 0.095f, 0.011f,
     0.000f, 0.090f, 0.004f,
     0.058f, 0.095f, 0.011f,
     0.000f, 0.090f, 0.004f,
     0.058f, 0.095f, 0.011f,
     0.000f, 0.090f, 0.004f,
     0.058f, 0.095f, 0.011f,

  };
 colour_buffer_length = sizeof(colour_buffer);
  
  GLuint element_buffer []  {
      0, 1, 2	
    , 1, 3, 2
    , 0, 4, 1	
    , 1, 5, 4	
    , 5, 7, 4	
    , 7, 6, 4	
    , 3, 7, 6	
    , 2, 3, 6	
    , 1, 5, 7	
    , 1, 3, 7	
    , 0, 4, 6	
    , 0, 2, 6	
  };
  element_buffer_length = sizeof(element_buffer);



  // Transfer buffers to the GPU


  // create buffer
  glGenBuffers(1, &vertex_buffer_token);
  // immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, vertex_buffer_length, vertex_buffer, GL_STATIC_DRAW);

  // Binds the buffer and transfers the data
  glGenBuffers(1, &colour_buffer_token);
  glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, colour_buffer_length, colour_buffer, GL_STATIC_DRAW);


  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_buffer_length, element_buffer, GL_STATIC_DRAW);
}

LeavesAsset::~LeavesAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
// define symbol to be nothing
#define checkGLError()
#endif

void LeavesAsset::checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
}

void LeavesAsset::Draw(GLuint program_token) {
  if(!glIsProgram(program_token)) {
    std::cerr << "Drawing Diamon with invalid program" << std::endl;
    return;
  }
  GLint validation_ok;
  glValidateProgram(program_token);
  glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);
  if(!validation_ok) {
    GLint maxLength = 0;
    glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

    // The maxLength includes the NULL character
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
  ////////////////////////////////////////////////////////////////////////////////////////// 
  /// use the previously transferred buffer as the vertex array.  This way
  /// we transfer the buffer once -- at construction -- not on every frame.
  //////////////////////////////////////////////////////////////////////////////////////////
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
    position_attrib,        /* attribute */
    3,        /* size */
    GL_FLOAT,   /* type */
    GL_FALSE,   /* normalized? */
    0,        /* stride */
    (void*)0    /* array buffer offset */
  );
  glEnableVertexAttribArray(1);
  checkGLError();
  //////////////////////////////////////////////////////////////////////////////////////////
  /// Uses the Previously transferred buffer as the color array. This way
  /// We transfer the buffer once -- at constuction -- not on every frame
  //////////////////////////////////////////////////////////////////////////////////////////
  glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
  glVertexAttribPointer(
    1,        /* attribute */
    3,        /* size */
    GL_FLOAT,   /* type */
    GL_FALSE,   /* normalized? */
    0,        /* stride */
    (void*)0    /* array buffer offset */
  );
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
