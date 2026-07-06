#pragma once

#include <iostream>
#include <raylib.h>

#include "Utils.hpp"
#include "UI/UI.hpp"

namespace Mantel::Core{
    class RenderingPipeline{

        Mantel::UI::Canvas canvas = Mantel::UI::Canvas();
        
        public:
        RenderingPipeline(Mantel::Utils::Vector2I& windowSize, const std::string& title);
        ~RenderingPipeline();

        void Loop();
        
        void OverrideWindowSize(Mantel::Utils::Vector2I& windowSize);
        void OverrideWindowTitle(const std::string& title);
        void SetWindowIcon(const std::string& iconPath);
        
        void ClearScreen(Mantel::Utils::Color color);

    };
}
