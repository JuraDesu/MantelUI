#include "Progressbar.hpp"

namespace Mantel::UI{
void Progressbar::CalculateProgress(float valueA, float valueB){
        if(valueB <= 0.0f)currentSize = 0.0f;

        maxSize = size.x;
        progress = valueA / valueB;

        if(progress > 1.0f) progress = 1.0f;
        if(progress < 0.0f) progress = 0.0f;

        currentSize = size.x * progress;
        Mantel::Utils::Log::DebugLog("Progress " + std::to_string(progress), LogLevel::INFO);
    }
void Progressbar::Draw() const{
    if(!visible) return;
    int fixedProgress = progress * 100;
    std::string text = std::to_string(fixedProgress) + "\%";

    int textHeight = size.y / 2;
    int textWidth = MeasureTextEx(defaultFont, text.c_str(), textHeight, 0).x;

    DrawRectangle(position.x, position.y, size.x, size.y, style.backgroundColor);
    if(currentSize > 0.0f) {
        DrawRectangle(position.x, position.y, currentSize, size.y, style.foregroundColor);
        DrawRectangleLinesEx({position.x, position.y, currentSize, size.y}, 1, style.borderColor);
    }
    DrawRectangle(position.x, position.y + size.y / 2, size.x,size.y / 2, style.shadowColor);
    DrawRectangleLinesEx({position.x, position.y, size.x, size.y}, style.borderThickness, style.borderColor);
    DrawTextEx( defaultFont, 
                text.c_str(), 
                {(position.x + size.x / 2) - (textWidth / 2), (position.y + size.y / 2) - (textHeight / 2)},
                textHeight,
                0,
                BLACK);
}
void Progressbar::Update(float deltatime) {}
}