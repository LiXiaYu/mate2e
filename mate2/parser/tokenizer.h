#pragma once
#include <string>
#include <regex>

namespace mate
{
    class tokenizer
    {
    public:
        tokenizer();
        tokenizer(std::string rule);
        tokenizer(std::string name, std::string rule);

        virtual bool tokenize(std::string text)=0;

        std::string name;
        std::string ruletext;
    };
}