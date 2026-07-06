#pragma once

#include "UIObject.hpp"

namespace Mantel::UI{
    class TextComponent : public UIObject{
        public:
            TextComponent(Vector2 position, Vector2 size, const std::string& text)
            :UIObject(position, size), text(text){}

            void Draw() const override;
            void Update(float deltatime) override;

            struct TextStyle{
                Color color = {0,0,0,255};
            } style;

        private:
            std::string text;
    };
}