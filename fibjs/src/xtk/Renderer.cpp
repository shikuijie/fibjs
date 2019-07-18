#include <cstdio>
#include "ifs/console.h"
#include "ifs/coroutine.h"
#include "Renderer.h"

namespace fibjs {

result_t Renderer_base::_new(exlib::string title, obj_ptr<Renderer_base>& retVal, v8::Local<v8::Object> This)
{
    obj_ptr<Renderer> c = new Renderer(title);
    retVal = c;

    return 0;
}

void Renderer::init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void Renderer::terminate()
{
    glfwTerminate();
}

Renderer::Renderer(exlib::string title)
{
    m_title = title;
}

void Renderer::create()
{
    m_win = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
    if (m_win == NULL) {
        outLog(console_base::_ERROR, "glfwCreateWindow failed");
        return;
    }
    glfwMakeContextCurrent(m_win);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        outLog(console_base::_ERROR, "gladLoadGLLoader failed");
        glfwDestroyWindow(m_win);
        return;
    }

    glfwSetWindowUserPointer(m_win, this);

    glfwSetWindowSizeCallback(m_win, [](GLFWwindow* win, int w, int h) {
        Renderer* c = static_cast<Renderer*>(glfwGetWindowUserPointer(win));
        c->m_width = w;
        c->m_height = h;
    });

    glfwGetFramebufferSize(m_win, &m_fbWidth, &m_fbHeight);
    glfwSetFramebufferSizeCallback(m_win, [](GLFWwindow* win, int w, int h) {
        Renderer* c = static_cast<Renderer*>(glfwGetWindowUserPointer(win));
        c->m_fbWidth = w;
        c->m_fbHeight = h;
    });

    glfwSetKeyCallback(m_win, [](GLFWwindow* win, int key, int scancode, int action, int mods) {
        Renderer* c = static_cast<Renderer*>(glfwGetWindowUserPointer(win));
        if (action == GLFW_PRESS) {
            c->m_closed = true;
        }
    });
}

void Renderer::exec()
{
    glViewport(0, 0, m_fbWidth, m_fbHeight);
    glClearColor(m_bgr, m_bgg, m_bgb, m_bga);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glfwSwapBuffers(m_win);
    glfwPollEvents();
}

void Renderer::destroy()
{
    glfwSetWindowUserPointer(m_win, nullptr);
    glfwDestroyWindow(m_win);

    m_win = nullptr;
    m_sem.post();
}

result_t Renderer::render()
{
    asyncCall(Renderer::async_create, obj_ptr<Renderer>(this), CALL_E_GUICALL);

    while (!m_closed) {
        asyncCall(async_exec, obj_ptr<Renderer>(this), CALL_E_GUICALL);
        coroutine_base::ac_sleep(16);
    }

    asyncCall(async_destroy, obj_ptr<Renderer>(this), CALL_E_GUICALL);

    m_sem.wait();
    return 0;
}

result_t Renderer::setClearColor(exlib::string color)
{
    auto clr = CSSColorParser::parse(color.c_str());
    m_bgr = (float)clr.r / 255.0;
    m_bgg = (float)clr.g / 255.0;
    m_bgb = (float)clr.b / 255.0;
    m_bga = clr.a;
}

result_t Renderer::setSize(int32_t width, int32_t height)
{
    m_width = width;
    m_height = height;
}
}