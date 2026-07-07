#include "Canvas.hpp"

namespace Mantel::UI{
    void Canvas::Draw() const{
        for(const auto& element : rootElements){
            if( element && element->IsVisible()) element->Draw();
            else return;
        }
    }

    void Canvas::Update(float deltaTime){
        for(const auto& element : rootElements){
            if(element && element->IsVisible()) element->Update(deltaTime);
            else return;
        }
    }

    void Canvas::AddElement(std::shared_ptr<UIObject> element){
        if(element)
            rootElements.push_back(std::move(element));
        return;
    }
    void Canvas::InitUI(){
    auto button = std::make_shared<Mantel::UI::Button>(Vector2{25, 25}, Vector2{100, 50}, "Click");
    auto text = std::make_shared<Mantel::UI::TextComponent>(Vector2(button->GetPosition().x, button->GetPosition().y + 50), Vector2(100, 50), "Button was clicked!!");
    auto progressbar = std::make_shared<Mantel::UI::Progressbar>(Vector2(400, 200), Vector2(200, 25));

    text->SetVisible(false);
    progressbar->CalculateProgress(200, 841);

    AddElement(button);
    AddElement(progressbar);

    button->OnClick([text](){
        Mantel::Utils::Log::DebugLog("Button was clicked", LogLevel::INFO);
        text->SetVisible(true);
    });
    AddElement(text);

}

}