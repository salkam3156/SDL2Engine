#include "SDLSetup.h"

bool SDLSetup::InitializeSdl()
{

	bool profileSet = SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES ) == 0;
	bool majorSet = SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 ) == 0;
	bool minorSet = SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 ) == 0;

	bool videoInitialized = SDL_Init(SDL_INIT_VIDEO) == 0;

	return (videoInitialized && majorSet && minorSet && profileSet);
}

SDLSetup::~SDLSetup()
{
	SDL_Quit();
}

bool SDLSetup::InitializeGl()
{
//	//Success flag
//	bool success = true;
//
//	//Generate program
//	auto gProgramID = glCreateProgram();
//
//	//Create vertex shader
//	GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );
//
//	//Get vertex source
//	const GLchar* vertexShaderSource[] =
//	{
//		"#version 140\nin vec2 LVertexPos2D; void main() { gl_Position = vec4( LVertexPos2D.x, LVertexPos2D.y, 0, 1 ); }"
//	};
//
//	//Set vertex source
//	glShaderSource( vertexShader, 1, vertexShaderSource, NULL );
//
//	//Compile vertex source
//	glCompileShader( vertexShader );
//
//	//Check vertex shader for errors
//	GLint vShaderCompiled = GL_FALSE;
//	glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &vShaderCompiled );
//	if( vShaderCompiled != GL_TRUE )
//	{
//		printf( "Unable to compile vertex shader %d!\n", vertexShader );
//		//printShaderLog( vertexShader );
//		success = false;
//	}
//	else
//    {
//        //Attach vertex shader to program
//        glAttachShader( gProgramID, vertexShader );
//
//
//        //Create fragment shader
//        GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
//
//        //Get fragment source
//        const GLchar* fragmentShaderSource[] =
//        {
//            "#version 140\nout vec4 LFragment; void main() { LFragment = vec4( 1.0, 1.0, 1.0, 1.0 ); }"
//        };
//
//        //Set fragment source
//        glShaderSource( fragmentShader, 1, fragmentShaderSource, NULL );
//
//        //Compile fragment source
//        glCompileShader( fragmentShader );
//
//        //Check fragment shader for errors
//        GLint fShaderCompiled = GL_FALSE;
//        glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &fShaderCompiled );
//        if( fShaderCompiled != GL_TRUE )
//        {
//            printf( "Unable to compile fragment shader %d!\n", fragmentShader );
//            //printShaderLog( fragmentShader );
//            success = false;
//        }
//        else
//        {
//            //Attach fragment shader to program
//            glAttachShader( gProgramID, fragmentShader );
//
//
//            //Link program
//            glLinkProgram( gProgramID );
//
//            //Check for errors
//            GLint programSuccess = GL_TRUE;
//            glGetProgramiv( gProgramID, GL_LINK_STATUS, &programSuccess );
//            if( programSuccess != GL_TRUE )
//            {
//                printf( "Error linking program %d!\n", gProgramID );
//                //printProgramLog( gProgramID );
//                success = false;
//            }else
//            {
//                //Get vertex attribute location
//                auto gVertexPos2DLocation = glGetAttribLocation( gProgramID, "LVertexPos2D" );
//                if( gVertexPos2DLocation == -1 )
//                {
//                    printf( "LVertexPos2D is not a valid glsl program variable!\n" );
//                    success = false;
//                }
//                else
//                {
//                    //Initialize clear color
//                    glClearColor( 0.f, 0.f, 0.f, 1.f );
//
//                    //VBO data
//                    GLfloat vertexData[] =
//                    {
//                        -0.5f, -0.5f,
//                         0.5f, -0.5f,
//                         0.5f,  0.5f,
//                        -0.5f,  0.5f
//                    };
//
//                    //IBO data
//                    GLuint indexData[] = { 0, 1, 2, 3 };
//
//                    //Create VBO
//                                        //GLfloat gVBO = 0;
//                                        //GLuint gIBO = 0;
//                                        //glGenBuffers( 1, &gVBO );
//                                        //glBindBuffer( GL_ARRAY_BUFFER, gVBO );
//                                        //glBufferData( GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW );
//
//                                        //Create IBO
//                                        //glGenBuffers( 1, &gIBO );
//                                        //glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
//                                        //glBufferData( GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indexData, GL_STATIC_DRAW );
//
//                }
//            }
//        }
//    }
	return false;
}
