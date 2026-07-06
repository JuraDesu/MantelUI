#pragma once

#include <raylib.h>
#include <vector>
#include <memory>
#include <iostream>
#include <functional>

#include "../Utils.hpp"

namespace Mantel::UI{
    class UIObject{
    public:
        UIObject(Vector2 position, Vector2 size)
            : position(position), size(size), color(color), parent(nullptr), id(0), zIndex(0), interactive(interactive) {
                defaultFont = LoadFontEx("assets/fonts/Electrolize-Regular.ttf", size.y/2, nullptr, 0);
            }
        
        virtual ~UIObject() = default;

        virtual void Draw() const;
        virtual void Update(float deltaTime);
        //virtual void GetInputEvents(MouseButton button);
        //virtual void GetInputEvents(KeyboardKey key);

        void AddChild(std::shared_ptr<UIObject> child);
        Vector2 GetAbsolutePosition() const;

    private:
        int id;
        int zIndex;
        bool visible;

        UIObject* parent;
        std::vector<std::shared_ptr<UIObject>> children;
    protected:
        enum UIAnchor{
            TOP_LEFT,TOP_CENTER,TOP_RIGHT,
            CENTER_LEFT,CENTER,CENTER_RIGHT,
            BOTTOM_LEFT,BOTTOM_CENTER,BOTTOM_RIGHT
        } anchor;
        Vector2 position;
        Vector2 size;
        Color color;

        Font defaultFont;

        bool interactive;

        std::vector<std::shared_ptr<UIObject>>& GetChildren() { return children; }
    };
}