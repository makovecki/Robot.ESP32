#pragma once
#include <string>
class Persistance
{
    uint32_t handle;
    public:
        Persistance();
        void SaveString(std::string key, std::string value);
        std::string GetString(std::string key);
};