#include "UIObject.hpp"

namespace Mantel::UI{
    void UIObject::Draw() const{
        Vector2 absPos = GetAbsolutePosition();
        DrawRectangle(absPos.x, absPos.y, size.x, size.y, color);
        for(const auto& child : children){
            child->Draw();
        }
    }

    void UIObject::AddChild(std::shared_ptr<UIObject> child){
        if(!child){
            Mantel::Utils::Log::DebugLog("Attempted to add a null child to UIObject.", LogLevel::WARNING);
            return;
        }
        if(child.get() == this){
            Mantel::Utils::Log::DebugLog("Attempted to add UIObject as its own child.", LogLevel::ERROR);
            return;
        }
        child->parent = this;
        children.push_back(std::move(child));
    }

    void UIObject::Update(float deltaTime){
        for(const auto& child : children){
            child->Update(deltaTime);
        }
    }

    Vector2 UIObject::GetAbsolutePosition() const{
        if(parent){
            Vector2 parentPos = parent->GetAbsolutePosition();
            return {position.x + parentPos.x, position.y + parentPos.y};
        }
        return position;
    }

    /*void UIObject::GetInputEvents(MouseButton button){
        for(auto& child : children){
            if(child->interactive){
                child->GetInputEvents(button);
            }
        }
        if(interactive){
            Vector2 mousePos = GetMousePosition();
            Vector2 absPos = GetAbsolutePosition();
            if(mousePos.x >= absPos.x && mousePos.x <= absPos.x + size.x &&
               mousePos.y >= absPos.y && mousePos.y <= absPos.y + size.y){
                // Handle mouse button event for this UIObject
            }
        }
    }*/
}