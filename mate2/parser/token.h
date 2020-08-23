#pragma once
#include <string>

namespace mate
{
    class token
    {
    public:
        token(std::string name,std::string text);

        std::string name;
        std::string text;
    };
}