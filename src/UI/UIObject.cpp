#include "UIObject.hpp"

namespace Mantel::UI{
    void UIObject::Draw() const{
        if(!visible) return;
        
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
            switch(anchor){
                case TOP_LEFT:
                    return {position.x + parentPos.x, position.y + parentPos.y};
                case TOP_CENTER:
                    return {position.x + parentPos.x - size.x / 2, position.y + parentPos.y};
                case TOP_RIGHT:
                    return {position.x + parentPos.x - size.x, position.y + parentPos.y};
                case CENTER_LEFT:
                    return {position.x + parentPos.x, position.y + parentPos.y - size.y / 2};
                case CENTER:
                    return {position.x + parentPos.x - size.x / 2, position.y + parentPos.y - size.y / 2};
                case CENTER_RIGHT:
                    return {position.x + parentPos.x - size.x, position.y + parentPos.y - size.y / 2};
                case BOTTOM_LEFT:
                    return {position.x + parentPos.x, position.y + parentPos.y - size.y};
                case BOTTOM_CENTER:
                    return {position.x + parentPos.x - size.x / 2, position.y + parentPos.y - size.y};
                case BOTTOM_RIGHT:
                    return {position.x + parentPos.x - size.x, position.y + parentPos.y - size.y};
            }
        }
        return position;
    }
}