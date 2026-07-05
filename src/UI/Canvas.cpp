#include "Canvas.hpp"

namespace Mantel::UI{
    void Canvas::Draw() const{
        for(const auto& element : rootElements){
            element->Draw();
        }
    }

    void Canvas::Update(float deltaTime){
        for(const auto& element : rootElements){
            element->Update(deltaTime);
        }
    }

    void Canvas::AddElement(std::shared_ptr<UIObject> element){
        if(element)
            rootElements.push_back(std::move(element));
        return;
    }
}