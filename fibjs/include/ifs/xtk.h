/***************************************************************************
 *                                                                         *
 *   This file was automatically generated using idlc.js                   *
 *   PLEASE DO NOT EDIT!!!!                                                *
 *                                                                         *
 ***************************************************************************/

#ifndef _xtk_base_H_
#define _xtk_base_H_

/**
 @author Leo Hoo <lion@9465.net>
 */

#include "../object.h"

namespace fibjs {

class Renderer_base;
class Vector3_base;
class Face3_base;

class xtk_base : public object_base {
    DECLARE_CLASS(xtk_base);

public:
    static void s__new(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        CONSTRUCT_INIT();

        Isolate* isolate = Isolate::current();

        isolate->m_isolate->ThrowException(
            isolate->NewString("not a constructor"));
    }
};
}

#include "ifs/Renderer.h"
#include "ifs/Vector3.h"
#include "ifs/Face3.h"

namespace fibjs {
inline ClassInfo& xtk_base::class_info()
{
    static ClassData::ClassObject s_object[] = {
        { "Renderer", Renderer_base::class_info },
        { "Vector3", Vector3_base::class_info },
        { "Face3", Face3_base::class_info }
    };

    static ClassData s_cd = {
        "xtk", true, s__new, NULL,
        0, NULL, ARRAYSIZE(s_object), s_object, 0, NULL, 0, NULL, NULL, NULL,
        &object_base::class_info()
    };

    static ClassInfo s_ci(s_cd);
    return s_ci;
}
}

#endif
