#pragma once

#include <iostream>

namespace Mantel::Utils{
    struct Vector2I{
        int x, y;

        Vector2I(int x, int y)
            :x(x), y(y) {}

        inline std::ostream& operator<<(std::ostream& os){
            os << "Vector2I(" << this->x << ", " << this->y << ")";
            return os;
        }
    };
    struct Vector2F{
        float x, y;

        Vector2F(float x, float y)
            :x(x), y(y) {}

        inline std::ostream& operator<<(std::ostream& os){
            os << "Vector2F(" << this->x << ", " << this->y << ")";
            return os;
        }
    };
    struct Vector3I{
        int x, y, z;

        Vector3I(int x, int y, int z)
            :x(x), y(y), z(z) {}

        inline std::ostream& operator<<(std::ostream& os){
            os << "Vector3I(" << this->x << ", " << this->y << ", " << this->z << ")";
            return os;
        }
    };
    struct Vector3F{
        float x, y, z;

        Vector3F(float x, float y, float z)
            :x(x), y(y), z(z) {}

        inline std::ostream& operator<<(std::ostream& os){
            os << "Vector3F(" << this->x << ", " << this->y << ", " << this->z << ")";
            return os;
        }
    };
    
}