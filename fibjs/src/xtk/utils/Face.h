#include "ifs/Face3.h"
#include "glm/glm.hpp"

#ifndef FACE_H_
#define FACE_H_

namespace fibjs {

class Face3 : public Face3_base {
public:
    Face3(int32_t ai, int32_t bi, int32_t ci)
        : m_vec(ai, bi, ci)
    {
    }

private:
    glm::i32vec3 m_vec;
};

result_t Face3_base::_new(int32_t i, int32_t j, int32_t k, obj_ptr<Face3_base>& retVal, v8::Local<v8::Object> This)
{
    retVal = obj_ptr<Face3>(new Face3(i, j, k));
    return 0;
}
}

#endif