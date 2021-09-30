#ifndef BUFFER_RENDERER_H_
#define BUFFER_RENDERER_H_

#include <GL/glew.h>

class BufferRenderer {
    private:
        const char* vertexShaderInstructions;
        const char* fragmentShaderInstructions;
        GLuint vertexArray;
    public:
        enum ERROR_CODE {SUCCESS=0, FAILED_PROGRAM_VALIDATION};

        BufferRenderer();
        const char* createVertexShaderInstructions();
        const char* createFragmentShaderInstructions();
        GLuint createVertexArray();
        void createVertexShader(GLuint shaderID);
        void createFragmentShader(GLuint shaderID);
        ERROR_CODE createGlProgram();
        void validateShader(GLuint shader, const char *file=0);
        bool validateProgram(GLuint program);
};

#endif // BUFFER_RENDERER_H_
