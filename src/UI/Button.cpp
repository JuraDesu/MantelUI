#include "Button.hpp"

namespace Mantel::UI{
    void Button::Draw() const{

        Vector2 absPos = GetAbsolutePosition();

        // If recently clicked, slightly fade the button color as visual feedback
        float currentTime = GetTime();
        Color drawColor = color;
        if (state == PRESSED) {
            drawColor = Fade(color, 0.5f);
        } else if (state == HOVERED) {
            drawColor = Fade(color, 0.75f);
        }

        DrawRectangle(absPos.x, absPos.y, size.x, size.y, drawColor);

        // Draw text centered in the button
        int textWidth = MeasureText(text.c_str(), 20);
        int textHeight = 20; // Assuming a fixed height for simplicity
        DrawText(text.c_str(), absPos.x + (size.x - textWidth) / 2, absPos.y + (size.y - textHeight) / 2, 20, WHITE);
    }

    void Button::Update(float deltaTime){
        Vector2 mousePos = GetMousePosition();
        Vector2 absPos = GetAbsolutePosition();
        Color drawColor = color;
        
        bool isHovered = mousePos.x >= absPos.x && mousePos.x <= absPos.x + size.x &&
                         mousePos.y >= absPos.y && mousePos.y <= absPos.y + size.y;

        if(isHovered){
            state = HOVERED;
            float currentTime = GetTime();
            formula = currentTime - lastClickTime >= clickCooldown;
            if(IsMouseButtonDown(MOUSE_LEFT_BUTTON) && onClick){
                state = PRESSED;
                if (formula) {
                    lastClickTime = currentTime;
                    onClick();
                }
            }
        } else {
            state = NORMAL;
        }
    }

    void Button::OnClick(std::function<void()> callback){
        onClick = std::move(callback);
    }
}