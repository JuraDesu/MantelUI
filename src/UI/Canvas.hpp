#pragma once

#include "UI.hpp"

namespace Mantel::UI{
    class Canvas{
    public:
        Canvas() = default;
        void Draw() const;
        void Update(float deltaTime);

        void AddElement(std::shared_ptr<UIObject> element);
        void InitUI();

    private:
        std::vector<std::shared_ptr<UIObject>> rootElements;
    };
}