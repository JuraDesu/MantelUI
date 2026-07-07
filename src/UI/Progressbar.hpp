#pragma once

#include <raylib.h>
#include "UIObject.hpp"

namespace Mantel::UI{
    class Progressbar : public UIObject{
        public:
            Progressbar(Vector2 position, Vector2 size)
                : UIObject(position, size) {

                }

            void Draw() const override;
            void Update(float deltatime) override;
            void CalculateProgress(float valueA, float valueB);

        private:
            float maxSize;
            float currentSize;
            float progress;

            struct ProgressbarStyle{
                Color backgroundColor = {180, 180, 180, 255};
                Color foregroundColor = {255, 40, 255, 255};
                Color borderColor = {0,0,0,255};
                Color shadowColor = {0,0,0,75};
                int borderThickness = 2;
                bool isTextPresent = true;
                bool hasShadow = true;
                
            } style;
    };
}