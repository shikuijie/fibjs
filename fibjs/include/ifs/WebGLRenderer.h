/***************************************************************************
 *                                                                         *
 *   This file was automatically generated using idlc.js                   *
 *   PLEASE DO NOT EDIT!!!!                                                *
 *                                                                         *
 ***************************************************************************/

#ifndef _WebGLRenderer_base_H_
#define _WebGLRenderer_base_H_

/**
 @author Leo Hoo <lion@9465.net>
 */

#include "../object.h"

namespace fibjs {

class WebGLRenderer_base : public object_base {
    DECLARE_CLASS(WebGLRenderer_base);

public:
    // WebGLRenderer_base
    static result_t _new(exlib::string title, obj_ptr<WebGLRenderer_base>& retVal, v8::Local<v8::Object> This = v8::Local<v8::Object>());
    virtual result_t render() = 0;
    virtual result_t setClearColor(exlib::string color) = 0;
    virtual result_t setSize(int32_t width, int32_t height) = 0;

public:
    template <typename T>
    static void __new(const T& args);

public:
    static void s__new(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void s_render(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void s_setClearColor(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void s_setSize(const v8::FunctionCallbackInfo<v8::Value>& args);
};
}

namespace fibjs {
inline ClassInfo& WebGLRenderer_base::class_info()
{
    static ClassData::ClassMethod s_method[] = {
        { "render", s_render, false },
        { "setClearColor", s_setClearColor, false },
        { "setSize", s_setSize, false }
    };

    static ClassData s_cd = {
        "WebGLRenderer", false, s__new, NULL,
        ARRAYSIZE(s_method), s_method, 0, NULL, 0, NULL, 0, NULL, NULL, NULL,
        &object_base::class_info()
    };

    static ClassInfo s_ci(s_cd);
    return s_ci;
}

inline void WebGLRenderer_base::s__new(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    CONSTRUCT_INIT();
    __new(args);
}

template <typename T>
void WebGLRenderer_base::__new(const T& args)
{
    obj_ptr<WebGLRenderer_base> vr;

    METHOD_NAME("new WebGLRenderer()");
    CONSTRUCT_ENTER();

    METHOD_OVER(1, 1);

    ARG(exlib::string, 0);

    hr = _new(v0, vr, args.This());

    CONSTRUCT_RETURN();
}

inline void WebGLRenderer_base::s_render(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    METHOD_NAME("WebGLRenderer.render");
    METHOD_INSTANCE(WebGLRenderer_base);
    METHOD_ENTER();

    METHOD_OVER(0, 0);

    hr = pInst->render();

    METHOD_VOID();
}

inline void WebGLRenderer_base::s_setClearColor(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    METHOD_NAME("WebGLRenderer.setClearColor");
    METHOD_INSTANCE(WebGLRenderer_base);
    METHOD_ENTER();

    METHOD_OVER(1, 1);

    ARG(exlib::string, 0);

    hr = pInst->setClearColor(v0);

    METHOD_VOID();
}

inline void WebGLRenderer_base::s_setSize(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    METHOD_NAME("WebGLRenderer.setSize");
    METHOD_INSTANCE(WebGLRenderer_base);
    METHOD_ENTER();

    METHOD_OVER(2, 2);

    ARG(int32_t, 0);
    ARG(int32_t, 1);

    hr = pInst->setSize(v0, v1);

    METHOD_VOID();
}
}

#endif
