#pragma once

#include <iostream>

namespace Mantel::Utils{
    struct Color{
    int r,g,b,a;

    Color(int r, int g, int b, int a)
        :r(r), g(g), b(b), a(a) {}

        inline std::ostream& operator<<(std::ostream& os){
            os << "Color(" << this->r << ", " << this->g << ", " << this->b << ", " << this->a << ")";
            return os;
        }

        inline Color& operator=(int value){
            this->r = (value >> 24) & 0xff;
            this->g = (value >> 16) & 0xff;
            this->b = (value >> 8)  & 0xff;
            this->a = value         & 0xff;
            return *this;
        }
    };
}

