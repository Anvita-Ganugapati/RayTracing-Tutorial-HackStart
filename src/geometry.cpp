#include "geometry.h"

Sphere::Sphere(const Matrix4d& transformation, const Material& material) {
    m_transformation = transformation;
    m_material = material;
}

Tuple4d Sphere::normal(const Tuple4d& hit_point) const {
    Tuple4d transformed_point = m_transformation.inverse() * hit_point;
    Tuple4d object_normal = transformed_point - point(0, 0, 0);
    Tuple4d world_normal = m_transformation.inverse().transpose() * object_normal;
    world_normal(3) = 0;
    return world_normal.normalize();
}

std::vector<double> Sphere::intersect(const Ray& ray) const {

    Ray transformed_ray = ray.transform(m_transformation.inverse());
    Tuple4d o = transformed_ray.origin() - point(0, 0, 0);

    double a = dot(transformed_ray.direction(), transformed_ray.direction());
    double b = 2 * dot(transformed_ray.direction(), o);
    double c = dot (o, o) - 1;

    double discriminant = pow(b, 2) - 4 * a * c;

    std::vector<double> intersections;
    if (discriminant >= 0) {
        intersections.push_back((-b + sqrt(discriminant)) / (2 * a));
        intersections.push_back((-b - sqrt(discriminant)) / (2 * a));
    }
    return intersections;
}