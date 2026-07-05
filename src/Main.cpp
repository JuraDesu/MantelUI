#include "RenderingPipeline.hpp"

int main(){
    Mantel::Utils::Vector2I windowSize(800, 600);
    std::string title = "My Application";

    Mantel::Core::RenderingPipeline pipeline(windowSize, title);

    pipeline.Loop();

    return 0;
}

