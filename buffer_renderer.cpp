#include "buffer_renderer.hpp"
#include <GLFW/glfw3.h>
#include <cstdio>

BufferRenderer::BufferRenderer() {
    vertexShaderInstructions = createVertexShaderInstructions();
    fragmentShaderInstructions = createFragmentShaderInstructions();
    vertexArray = createVertexArray();
}

const char* BufferRenderer::createVertexShaderInstructions() {
    return
    "\n"
    "#version 330\n"
    "\n"
    "noperspective out vec2 TexCoord;\n"
    "\n"
    "void main(void){\n"
    "\n"
    "    TexCoord.x = (gl_VertexID == 2)? 2.0: 0.0;\n"
    "    TexCoord.y = (gl_VertexID == 1)? 2.0: 0.0;\n"
    "    \n"
    "    gl_Position = vec4(2.0 * TexCoord - 1.0, 0.0, 1.0);\n"
    "}\n";

}

const char* BufferRenderer::createFragmentShaderInstructions() {
    return
    "\n"
    "#version 330\n"
    "\n"
    "uniform sampler2D buffer;\n"
    "noperspective in vec2 TexCoord;\n"
    "\n"
    "out vec3 outColor;\n"
    "\n"
    "void main(void){\n"
    "    outColor = texture(buffer, TexCoord).rgb;\n"
    "}\n";
}

GLuint BufferRenderer::createVertexArray() {
    GLuint vertexArray;
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    return vertexArray;
}

BufferRenderer::ERROR_CODE BufferRenderer::createGlProgram() {
    GLuint shaderID = glCreateProgram();
    createVertexShader(shaderID);
    createFragmentShader(shaderID);

    glLinkProgram(shaderID);
    if(!validateProgram(shaderID)) {
        fprintf(stderr, "Error while validating shader.\n");
        glfwTerminate();
        glDeleteVertexArrays(1, &vertexArray);
        return FAILED_PROGRAM_VALIDATION;
    }

    return SUCCESS;

}
void BufferRenderer::createVertexShader(GLuint shaderID) {
    GLuint shaderVP = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shaderVP, 1, &vertexShaderInstructions, 0);
    glCompileShader(shaderVP);
    validateShader(shaderVP, vertexShaderInstructions);
    glAttachShader(shaderID, shaderVP);
    glDeleteShader(shaderVP);
}

void BufferRenderer::createFragmentShader(GLuint shaderID) {
    GLuint shaderFP = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shaderFP, 1, &fragmentShaderInstructions, 0);
    glCompileShader(shaderFP);
    validateShader(shaderFP, fragmentShaderInstructions);
    glAttachShader(shaderID, shaderFP);
    glDeleteShader(shaderFP);
}

void BufferRenderer::validateShader(GLuint shader, const char* file) {
    static const unsigned int BUFFER_SIZE = 512;
    char buffer[BUFFER_SIZE];
    GLsizei length = 0;

    glGetShaderInfoLog(shader, BUFFER_SIZE, &length, buffer);
    if(length > 0){
        printf("Shader %d(%s) compile error: %s\n", shader, (file ? file: ""), buffer);
    }
}

bool BufferRenderer::validateProgram(GLuint program) {
    static const GLsizei BUFFER_SIZE = 512;
    GLchar buffer[BUFFER_SIZE];
    GLsizei length = 0;

    glGetProgramInfoLog(program, BUFFER_SIZE, &length, buffer);
    if(length > 0) {
        printf("Program %d link error: %s\n", program, buffer);
        return false;
    }

    return true;
}
