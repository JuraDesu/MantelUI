#include "Log.hpp"

void Mantel::Utils::Log::DebugLog(const std::string& message, LogLevel level){
    std::string levelStr;
    switch(level){
        case LogLevel::INFO:
            levelStr = "[INFO]";
            break;
        case LogLevel::WARNING:
            levelStr = "[WARNING]";
            break;
        case LogLevel::ERROR:
            levelStr = "[ERROR]";
            break;
        case LogLevel::OBJECT:
            levelStr = "[OBJECT]";
            break;
    }
    std::cout << levelStr << " " << message << std::endl;
}