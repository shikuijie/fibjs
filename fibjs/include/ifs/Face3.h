/***************************************************************************
 *                                                                         *
 *   This file was automatically generated using idlc.js                   *
 *   PLEASE DO NOT EDIT!!!!                                                *
 *                                                                         *
 ***************************************************************************/

#ifndef _Face3_base_H_
#define _Face3_base_H_

/**
 @author Leo Hoo <lion@9465.net>
 */

#include "../object.h"

namespace fibjs {

class Face3_base : public object_base {
    DECLARE_CLASS(Face3_base);

public:
    // Face3_base
    static result_t _new(int32_t i, int32_t j, int32_t k, obj_ptr<Face3_base>& retVal, v8::Local<v8::Object> This = v8::Local<v8::Object>());

public:
    template <typename T>
    static void __new(const T& args);

public:
    static void s__new(const v8::FunctionCallbackInfo<v8::Value>& args);
};
}

namespace fibjs {
inline ClassInfo& Face3_base::class_info()
{
    static ClassData s_cd = {
        "Face3", false, s__new, NULL,
        0, NULL, 0, NULL, 0, NULL, 0, NULL, NULL, NULL,
        &object_base::class_info()
    };

    static ClassInfo s_ci(s_cd);
    return s_ci;
}

inline void Face3_base::s__new(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    CONSTRUCT_INIT();
    __new(args);
}

template <typename T>
void Face3_base::__new(const T& args)
{
    obj_ptr<Face3_base> vr;

    METHOD_NAME("new Face3()");
    CONSTRUCT_ENTER();

    METHOD_OVER(3, 3);

    ARG(int32_t, 0);
    ARG(int32_t, 1);
    ARG(int32_t, 2);

    hr = _new(v0, v1, v2, vr, args.This());

    CONSTRUCT_RETURN();
}
}

#endif
