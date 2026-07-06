#pragma once

#include <raylib.h>
#include "UIObject.hpp"

namespace Mantel::UI{
    class Progressbar : public UIObject{
        public:
            Progressbar(Vector2 position, Vector2 size)
                : UIObject(position, size) {}

            void Draw() const override;
            void Update(float deltatime) override;

        private:
            float maxSize;
            float currentSize;


            struct ProgressbarStyle{
                Color backgroundColor = {180, 180, 180, 255};
                Color foregroundColor = {255, 40, 255, 255};
                bool isTextPresent = true;
                
            };
    };
}