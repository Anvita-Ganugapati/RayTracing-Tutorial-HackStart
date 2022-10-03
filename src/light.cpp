#include "light.h"
#include <iostream>

Light::Light(const Tuple4d& position, const Color& color) {

    m_position = position;
    m_color = color;

}

Tuple4d Light::direction(const Tuple4d& hit_point) const {

    return (m_position - hit_point).normalize();

}
Color Light::phong_shading(const Sphere& object, const Tuple4d& position, const Tuple4d& eye, const Tuple4d& normal) const {

    Color ret{ 0, 0, 0};
    Material mat = object.material();
    Color effective_color = hadamard_product(mat.m_color, m_color);

    Tuple4d light_direction = direction(position);
    double light_dot_normal = dot(light_direction, normal);

    if (light_dot_normal >=0) {
        Color diffuse = effective_color * mat.m_diffuse * light_dot_normal;

        Tuple4d reflect_direction = reflect(-light_direction, normal);
            std::cout << "HERE" << std::endl;
        
        double reflect_dot_eye = dot(reflect_direction, eye);

        if (reflect_dot_eye >= 0) {
            Color specular = m_color * mat.m_specular * pow(reflect_dot_eye, mat.m_shininess);
            ret += diffuse + specular;
        } else {
            ret += diffuse;
        }
    }
    ret += effective_color * mat.m_ambient;
    std::cout << ret << + "RET HERE " << std::endl;
    return ret;
    

}
