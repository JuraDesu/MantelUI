#include "RenderingPipeline.hpp"

namespace Mantel::Core{

RenderingPipeline::RenderingPipeline(Mantel::Utils::Vector2I& windowSize, const std::string& title){
    InitWindow(windowSize.x, windowSize.y, title.c_str());
    SetTargetFPS(60);
    Mantel::Utils::Log::DebugLog("RenderingPipeline initialized with window size: " + std::to_string(windowSize.x) + "x" + std::to_string(windowSize.y) + " and title: " + title, LogLevel::INFO);
    InitUI();
}

RenderingPipeline::~RenderingPipeline(){
    CloseWindow();
    Mantel::Utils::Log::DebugLog("RenderingPipeline destroyed and window closed.", LogLevel::INFO);
}

void RenderingPipeline::InitUI(){
    auto button = std::make_shared<Mantel::UI::Button>(Vector2{50, 50}, Vector2{100, 40}, RED, "Click Me");
    button->OnClick([](){
        Mantel::Utils::Log::DebugLog("Button was clicked!", LogLevel::INFO);
    });
    canvas.AddElement(button);
}

void RenderingPipeline::OverrideWindowSize(Mantel::Utils::Vector2I& windowSize){
    SetWindowSize(windowSize.x, windowSize.y);
    Mantel::Utils::Log::DebugLog("Window size overridden to: " + std::to_string(windowSize.x) + "x" + std::to_string(windowSize.y), LogLevel::INFO);
}

void RenderingPipeline::SetWindowIcon(const std::string& iconPath){
    SetWindowIcon(iconPath.c_str());
    Mantel::Utils::Log::DebugLog("Window icon set to: " + iconPath, LogLevel::INFO);
}

void RenderingPipeline::Loop(){
    while (!WindowShouldClose()){

        canvas.Update(GetFrameTime()); // Update the canvas and its children

        BeginDrawing();
        ClearBackground((Color){ 27, 12, 45, 255 }); // Clear the screen with a dark color
        canvas.Draw();
        
        EndDrawing();
    }
}

void RenderingPipeline::OverrideWindowTitle(const std::string& title){
    SetWindowTitle(title.c_str());
    Mantel::Utils::Log::DebugLog("Window title overridden to: " + title, LogLevel::INFO);
}


void RenderingPipeline::RenderUIObj(/*UIObject obj*/){
}

} // namespace Mantel::Core
