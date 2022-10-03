#ifndef __LIGHT_H__
#define __LIGHT_H__

#include "util/tuple.h"
#include "util/color.h"
#include "geometry.h"


class Light {

    private:
        Tuple4d m_position;
        Color m_color;

    public:
        Light(const Tuple4d& position, const Color& color);

        Tuple4d direction(const Tuple4d& hit_point) const;
        Color phong_shading(const Sphere& object, const Tuple4d& position, const Tuple4d& eye, const Tuple4d& normal) const;

};

#endif // __LIGHT_H__