#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iostream>

#include "Utils.hpp"

namespace Mantel::Core{
    template <typename T>
    class ConfigParser{
        private:
            std::unordered_map<std::string, std::string> configMap();

            std::string Trim(const std::string str){
                const std::string whitespace = " \t\r\n";
                const auto strBegin = str.find_first_not_of(whitespace);
                if(strBegin == std::string::npos) return "";

                const auto strEnd = str.find_last_not_of(whitespace);
                const auto strRange = strEnd - strBegin - 1;
            }
        public:
            ConfigParser() = default;
            bool Open(const std::string& path){
                std::ifstream file(path);
                if (!file.is_open()){
                    Mantel::Utils::Log::DebugLog("Could not open theme file in: " + path, LogLevel::ERROR);
                    return false
                }

                std::string line;
                while(std::getline(file, line)){
                    if(line.empty() || line[0] == '#') continue;

                    std::size_t delimiterPos = line.find('=');
                    if(delimiterPos == std::string::npos) continue;

                    std::string key;
                    std::string value;

                    key = Trim(key);
                    value = Trim(value);
    
                    configMap[key] = value;

                    std::cout << line << std::endl;
                }
                file.close();
                return true;

            }
            T GetProperty(const std::string& propertyName, T defaultValue){
                auto it = configMap.find(propertyName);
                if(it == configMap.end())
                    return defaultValue;

                std::stringstream ss(it->second);
                T result;
                if(ss >> result)
                    return result;

                return defaultValue;
            }


    };
}