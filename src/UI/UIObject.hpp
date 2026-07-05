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
        UIObject(Vector2 position, Vector2 size, Color color, bool interactive = false)
            : position(position), size(size), color(color), parent(nullptr), id(0), zIndex(0), interactive(interactive) {}
        
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

        bool interactive;

        void SetAnchor(UIAnchor anchor) { this->anchor = anchor; };
        std::vector<std::shared_ptr<UIObject>>& GetChildren() { return children; }
    };
}