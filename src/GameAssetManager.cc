#include "GameAssetManager.h"

//////////////////////////////////////////////////////////////////////////////////////////
/// Creates a GameAssetManager to load the correct shaders based on the
/// ApplicationMode.
//////////////////////////////////////////////////////////////////////////////////////////
GameAssetManager::GameAssetManager() {
        std::string vertex_shader("shaders/translate.vs");
        std::string fragment_shader("shaders/fragment.fs");

        program_token = CreateGLProgram(vertex_shader, fragment_shader);
}

void GameAssetManager::UpdateCameraPosition(Control control,  int Mouse_X, int Mouse_Y){
        Camera_View = camera->UpdateCameraPosition(control, Mouse_X, Mouse_Y);
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Deletes a GameAssetManager, in particular it will clean up any modifications
/// to the OpenGL state.
//////////////////////////////////////////////////////////////////////////////////////////
GameAssetManager::~GameAssetManager() {
        glDeleteProgram(program_token);
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Unimplemented copy constructor -- this means that the GameAssetManager
/// may not work as you'd expect when being copied.
//////////////////////////////////////////////////////////////////////////////////////////
GameAssetManager::GameAssetManager(GameAssetManager const& the_manager) {
  // TODO: implement this
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Unimplemented move constructor -- this unimplemented method violates the
/// C++11 move semantics for GameAssetManager.
//////////////////////////////////////////////////////////////////////////////////////////
GameAssetManager::GameAssetManager(GameAssetManager const&& the_manager) {
  // TODO: implement this
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Unimplemented assisgnment operator -- violates the expected semantics for
/// assignment in C++11.
//////////////////////////////////////////////////////////////////////////////////////////
void GameAssetManager::operator=(GameAssetManager) {
  // TODO: implement this
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Adds a GameAsset to the scene graph.
//////////////////////////////////////////////////////////////////////////////////////////
void GameAssetManager::AddAsset(std::shared_ptr<GameAsset> game_asset) {
        draw_list.push_back(game_asset);
}

//////////////////////////////////////////////////////////////////////////////////////////
/// Draws each GameAsset in the scene graph.
//////////////////////////////////////////////////////////////////////////////////////////
void GameAssetManager::Draw() {
	for(auto ga: draw_list)
	{
                //////////////////////////////////////////////////////////////////////////////////////////
                /// Camera/Asset Matrix 
                /// 
                /// This class links the camera matrix to the Draw method as well as the new position
                /// the Game Assets are set.
                ////////////////////////////////////////////////////////////////////////////////////////// 
		glm::mat4 Camera_Model(1.0f);

		GLuint Camera_Projection_Link = glGetUniformLocation(program_token, "Camera_Projection");
		GLuint Camera_View_Link = glGetUniformLocation(program_token, "Camera_View");
		GLuint Camera_Model_Link = glGetUniformLocation(program_token, "Camera_Model");

                Camera_Projection = glm::perspective(45.0f, 16.0f/10.0f, 0.1f, 1000.0f);
                
		glUniformMatrix4fv(Camera_Projection_Link, 1, GL_FALSE, &Camera_Projection[0][0]);
		glUniformMatrix4fv(Camera_View_Link, 1, GL_FALSE, &Camera_View[0][0]);

                Camera_Model = ga->GetModel();
		glUniformMatrix4fv(Camera_Model_Link, 1, GL_FALSE, &Camera_Model[0][0]);
		
		//////////////////////////////////////////////////////////////////////////////////////////
                /// Collision Check
                /// 
                /// Checks whether one block collides with the other Block
                ////////////////////////////////////////////////////////////////////////////////////////// 
                //std::shared_ptr<GameAsset> game_asset = std::make_shared<GameAsset>();
                
                if( ga->GetTranslateBool() == true || ga->GetScaleBool() == true || ga->GetRotateBool() == true ){
                        BB1_Max = ga->GetAABB("Max");
                        BB1_Min = ga->GetAABB("Min");
                        BB1_Pos = ga->GetTranslateTo();
                        
                        for(auto ga2: draw_list) {
                                BB2_Max = ga2->GetAABB("Max");
                                BB2_Min = ga2->GetAABB("Min");
                                BB2_Pos = ga2->GetTranslateTo();
                                camera->CollisionDetection(BB2_Max, BB2_Min);
                                if(BB1_Pos != BB2_Pos) {
                                         ga->CollisionDetection(BB1_Max, BB1_Min, BB1_Pos, BB2_Max, BB2_Min, BB2_Pos);
                                }
                        }
                }
                ga->Draw(program_token);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
/// When given the contents of a vertex shader and fragment shader
/// GameAssetManager::CreateGLProgram will compile and link them.  This
/// implementation will exit with -1 error if an error is detected.
///
/// @return the GL "token" referring to the gl program.
//////////////////////////////////////////////////////////////////////////////////////////
GLuint GameAssetManager::CreateGLProgram(std::string & vertex_shader
                                         , std::string & fragment_shader) {
        auto v_shader_token = CreateGLESShader(GL_VERTEX_SHADER, vertex_shader);
        auto f_shader_token = CreateGLESShader(GL_FRAGMENT_SHADER, fragment_shader);

        GLint program_ok;

        GLuint program = glCreateProgram();

        glAttachShader(program, v_shader_token);
        glAttachShader(program, f_shader_token);
        glLinkProgram(program);

        glGetProgramiv(program, GL_LINK_STATUS, &program_ok);
        if (!program_ok) {
                std::cerr << "Failed to link shader program:" << std::endl;
                glDeleteProgram(program);
                exit(-1);
        }
        return program;
}

//////////////////////////////////////////////////////////////////////////////////////////
/// When given a type of shader to construct and the contents of a shader,
/// GameAssetManager::CreateGLESShader will create the shader or exit with
/// error -1.
///
/// @return the GL "token" for the requested shader.
//////////////////////////////////////////////////////////////////////////////////////////
GLuint GameAssetManager::CreateGLESShader(GLenum type, std::string & shader) {
        GLuint shader_token;
        GLint shader_ok;
        auto source = ReadShader(shader);

        if (!source.first)
                return 0;

        shader_token = glCreateShader(type);
        glShaderSource(shader_token, 1, (const GLchar**)&source.first, &source.second);
        glCompileShader(shader_token);
        delete(source.first);

        glGetShaderiv(shader_token, GL_COMPILE_STATUS, &shader_ok);
        if (!shader_ok) {
                GLint maxLength = 0;
                glGetShaderiv(shader_token, GL_INFO_LOG_LENGTH, &maxLength);

                //The maxLength includes the NULL character
                std::vector<char> errorLog(maxLength);
                glGetShaderInfoLog(shader_token, maxLength, &maxLength, &errorLog[0]);

                //Provide the infolog in whatever manor you deem best.
                std::cerr << "Failed to compile " << shader << " with error code " << shader_ok << std::endl;
                for(auto c: errorLog) {
                        std::cerr << c;
                }

                glDeleteShader(shader_token); //Don't leak the shader.
                exit(-1);
        }
        return shader_token;
}

//////////////////////////////////////////////////////////////////////////////////////////
/// ReadShader reads the contents of a file and packs it into a null termintated
/// GLchar * which is suitable for sending to OpenGL.
///
/// @return a pair consisting of the shader file contents and a holder for the
///         OpenGL "token".
//////////////////////////////////////////////////////////////////////////////////////////
std::pair<GLchar *, GLint> GameAssetManager::ReadShader(std::string & shader) {
        std::ifstream input_file;
        GLint length;
        input_file.open(shader, std::ios::in);

        input_file.seekg(0, std::ios::end);  // go to the end of the file
        length = input_file.tellg();    // get length of the file
        input_file.seekg(0, std::ios::beg);  // go to beginning of the file

        GLchar * buffer = new GLchar[length+1];
        input_file.read(buffer, length);
        buffer[length+1]='\0';  // Ensure null terminated

        input_file.close();
        return std::make_pair(buffer, length);
}
