#include "TextComponent.hpp"

namespace Mantel::UI{
void TextComponent::Draw() const{
        DrawTextEx(defaultFont, text.c_str(), position, size.y, 0, style.color);
    }
void TextComponent::Update(float deltatime){
        //Implementation of text animations in the future its empty right now
    }
}