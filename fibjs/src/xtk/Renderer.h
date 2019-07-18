#include "ifs/Renderer.h"
#include "csscolor/parser.hpp"
#include "glad/glad.h"
#include <GLFW/glfw3.h>

#ifndef RENDERER_H_
#define RENDERER_H_

namespace fibjs {

class Renderer : public Renderer_base {

public:
    static void init();
    static void terminate();

    static result_t async_create(obj_ptr<Renderer> c)
    {
        c->create();
        return 0;
    }
    static result_t async_exec(obj_ptr<Renderer> c)
    {
        c->exec();
        return 0;
    }
    static result_t async_destroy(obj_ptr<Renderer> c)
    {
        c->destroy();
        return 0;
    }

public:
    virtual result_t render();
    virtual result_t setClearColor(exlib::string color);
    virtual result_t setSize(int32_t width, int32_t height);

public:
    Renderer(exlib::string title);
    void create();
    void exec();
    void destroy();

private:
    exlib::Semaphore m_sem;

private:
    bool m_closed = false;
    float m_bgr, m_bgg, m_bgb, m_bga; // background color: r g b a

    exlib::string m_title = "";
    int32_t m_width = 400;
    int32_t m_height = 320;

    int32_t m_fbWidth = 0;
    int32_t m_fbHeight = 0;

    GLFWwindow* m_win = nullptr;
};
}

#endif