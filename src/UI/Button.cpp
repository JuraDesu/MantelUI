#include "Button.hpp"

namespace Mantel::UI{
    void Button::Draw() const{

        // If recently clicked, slightly fade the button color as visual feedback
        float currentTime = GetTime();
        Color drawColor = style.normalColor;
        if (state == PRESSED) {
            drawColor = style.pressedColor;
        } else if (state == HOVERED) {
            drawColor = style.hoveredColor;
        }


        DrawRectangle(position.x, position.y, size.x, size.y, drawColor);
        DrawRectangle(position.x, position.y + size.y / 2 + 10, size.x, size.y / 2 - 10, style.shadowColor);
        DrawRectangleLinesEx({position.x, position.y, size.x, size.y}, style.borderThickness, style.borderColor);

        // Draw text centered in the button
        int textHeight = size.y / 2; // Adjust text height based on button size
        int textWidth = MeasureTextEx(defaultFont, text.c_str(), textHeight, 0).x;
        if(textWidth > size.x){
            textHeight = (size.x / textWidth) * textHeight; // Scale down text height to fit button width
            textWidth = MeasureTextEx(defaultFont, text.c_str(), textHeight, 0).x; // Recalculate width
        }

        DrawTextEx(defaultFont, text.c_str(), { position.x + size.x / 2 - textWidth / 2, position.y + size.y / 2 - textHeight / 2 }, textHeight, 0, style.textColor);
    }

    void Button::Update(float deltaTime){
        Vector2 mousePos = GetMousePosition();
        Vector2 position = GetAbsolutePosition();
        Color drawColor = color;
        
        bool isHovered = mousePos.x >= position.x && mousePos.x <= position.x + size.x &&
                         mousePos.y >= position.y && mousePos.y <= position.y + size.y;
        float currentTime = GetTime();
        if(isHovered){
            state = HOVERED;
            formula = currentTime - lastClickTime >= cooldown;
            if(currentTime - lastClickTime < visualPressTime)state = ButtonState::PRESSED;
            else state = ButtonState::HOVERED;

            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && onClick){
                state = PRESSED;
                if (formula) {
                    lastClickTime = currentTime;
                    onClick();
                }
            }
        } else {
            if(currentTime - lastClickTime < visualPressTime) state = ButtonState::PRESSED;
            else state = ButtonState(NORMAL);
        }
    }

    void Button::OnClick(std::function<void()> callback){
        onClick = std::move(callback);
    }
}