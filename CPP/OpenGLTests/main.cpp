#include <glad/glad.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    std::cout<<"cheguei!!!\n";
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    std::cout<<"cheguei!!!\n";

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    std::cout<<"cheguei!!!\n";
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    float positions[6]={

        -0.5,0.5,
        0.0,0.5,
        0.5,-0.5


    };

    unsigned int buffer;
    glGenBuffers(1,&buffer);

    glBindBuffer(GL_ARRAY_BUFFER,buffer);

    glBufferData(GL_ARRAY_BUFFER,6*sizeof(float),positions,GL_STATIC_DRAW);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES,0,3);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    std::cout<<"cheguei!!!\n";
    }

    glfwTerminate();
    return 0;
}
