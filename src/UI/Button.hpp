#pragma once

#include "UIObject.hpp"

namespace Mantel::UI{
    class Button : public UIObject{
    public:
        Button(Vector2 position, Vector2 size, Color color, const std::string& text)
            : UIObject(position, size, color, true), text(text) {}
        void Draw() const override;
        void Update(float deltaTime) override;

        void OnClick(std::function<void()> callback);

        //void GetInputEvents(MouseButton button) override;
        //void GetInputEvents(KeyboardKey key) override;
    private:
        std::string text;
        std::function<void()> onClick;

        // Transient click handling
        std::string clickMessage = "Button Clicked!";
        float lastClickTime = -10000.0f; // time of last click
        float clickTextDuration = 2.0f; // seconds to show clickMessage
        float clickCooldown = 0.5f; // seconds before next click is accepted

        bool formula = false; // Placeholder for any future calculations
        enum ButtonState{
            NORMAL,
            HOVERED,
            PRESSED
        } state;
    };
}