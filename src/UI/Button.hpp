#pragma once

#include "UIObject.hpp"

namespace Mantel::UI{
    class Button : public UIObject{
    public:
        Button(Vector2 position, Vector2 size, const std::string& text)
            : UIObject(position, size){
                this->text = text;
            }
        void Draw() const override;
        void Update(float deltaTime) override;

        void OnClick(std::function<void()> callback);

        Vector2 GetPosition() {return position;}
        Vector2 GetSize() {return size;}

        //void GetInputEvents(MouseButton button) override;
        //void GetInputEvents(KeyboardKey key) override;
    private:
        std::function<void()> onClick;;
        std::string text;

        // Transient click handling
        std::string clickMessage = "Button Clicked!";
        float lastClickTime = -10000.0f; // time of last click
        float clickTextDuration = 2.0f; // seconds to show clickMessage
        float cooldown = 0.05f;
        float visualPressTime = 0.2f;

        bool formula = false; // Placeholder for any future calculations
        enum ButtonState{
            NORMAL,
            HOVERED,
            PRESSED
        } state;
        struct ButtonStyle{
            Color normalColor = {255, 255, 255, 255};
            Color hoveredColor = {220, 220, 220, 255};
            Color pressedColor = {180, 180, 180, 255};
            Color borderColor = {0,0,0,255};
            Color textColor = {0,0,0,255};
            Rectangle border;
            int borderThickness = 2;
            int borderRadius;
        } style;
    };
}