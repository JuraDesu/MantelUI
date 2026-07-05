#pragma once

#include <iostream>

enum class LogLevel{
    INFO,
    WARNING,
    ERROR,
    OBJECT
};

namespace Mantel::Utils{
    struct Log{
        static void DebugLog(const std::string& message, LogLevel level = LogLevel::INFO);
    };
    
}