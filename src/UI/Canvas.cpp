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
    void Canvas::InitUI(){
    auto button = std::make_shared<Mantel::UI::Button>(Vector2{25, 25}, Vector2{100, 50}, "Click");
    auto text = std::make_shared<Mantel::UI::TextComponent>(Vector2(button->GetPosition().x, button->GetPosition().y + 50), Vector2(200, 100), "Button was clicked!!");

    button->OnClick([&](){
        Mantel::Utils::Log::DebugLog("Button was clicked", LogLevel::INFO);
    });
    AddElement(button);
    AddElement(text);
}

}