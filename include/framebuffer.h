#ifndef __FRAMEBUFFER_H__
#define __FRAMEBUFFER_H__
#include <vector>
#include "util/color.h"
#include <string>
#include <fstream>

class Framebuffer {
    private:
        int m_width, m_height;
        std::vector<std::vector<Color>> m_buffer;
    

    public:
        Framebuffer(int width, int height);

        void set_color(int x, int y, const Color& color);
        void write_file(const std::string& name);

};

#endif // __FRAMEBUFFER_H__