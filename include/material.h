#ifndef __MATERIAL_H__
#define __MATERIAL_H__
#include "util/color.h"

struct Material {

    double m_ambient, m_diffuse, m_specular, m_shininess;
    Color m_color;

};

#endif // __MATERIAL_H__