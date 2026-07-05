#pragma once

#include "Button.hpp"

namespace Mantel::UI{
    class Canvas{
    public:
        Canvas() = default;
        void Draw() const;
        void Update(float deltaTime);

        void AddElement(std::shared_ptr<UIObject> element);

    private:
        std::vector<std::shared_ptr<UIObject>> rootElements;
        Button button = Button({50, 50}, {100, 40}, RED, "Click Me");
        Vector2 canvasSize;
    };
}