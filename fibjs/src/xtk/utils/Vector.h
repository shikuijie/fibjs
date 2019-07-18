#include "ifs/Vector3.h"
#include "glm/glm.hpp"

#ifndef VECTOR_H_
#define VECTOR_H_

namespace fibjs {

class Vector3 : public Vector3_base {
public:
    Vector3(float x, float y, float z)
        : m_vec(x, y, z)
    {
    }

private:
    glm::vec3 m_vec;
};

result_t Vector3_base::_new(double x, double y, double z, obj_ptr<Vector3_base>& retVal, v8::Local<v8::Object> This)
{
    retVal = obj_ptr<Vector3>(new Vector3((float)x, (float)y, (float)z));
    return 0;
}
}

#endif