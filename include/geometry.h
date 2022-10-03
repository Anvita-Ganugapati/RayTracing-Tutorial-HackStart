#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__
#include "util/matrix.h"
#include <vector>
#include "ray.h"
#include "material.h"

class Sphere {
   
   private: 
   Material m_material;
    Matrix4d m_transformation;

public:
    Sphere(const Matrix4d& transformation, const Material& material);

    const Material& material() const { return m_material; }

    Tuple4d normal(const Tuple4d& hit_point) const;

    std::vector<double> intersect(const Ray& ray) const;

};

#endif // __GEOMETRY_H__