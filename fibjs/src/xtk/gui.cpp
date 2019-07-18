#include "object.h"
#include "ifs/xtk.h"
#include "utils/Vector.h"
#include "utils/Face.h"
#include "Renderer.h"

namespace fibjs {

DECLARE_MODULE(xtk);

static exlib::LockedList<AsyncEvent> s_uiPool;

void putGuiPool(AsyncEvent* ac)
{
    s_uiPool.putTail(ac);
}

class gui_thread : public exlib::OSThread {
public:
    virtual void Run()
    {
        Runtime rt(NULL);

        while (true) {
            AsyncEvent* p = s_uiPool.getHead();
            if (p) {
                p->invoke();
            }
        }
    }

    gui_thread()
    {
        Renderer::init();
    }
    ~gui_thread()
    {
        Renderer::terminate();
    }
};

void run_gui()
{
    gui_thread* _thGUI = new gui_thread();
    _thGUI->bindCurrent();
    _thGUI->Run();
}
}