#include <glad/glad.h>
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
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    std::cout<<"cheguei!!!\n";
    }

    glfwTerminate();
    return 0;
}
