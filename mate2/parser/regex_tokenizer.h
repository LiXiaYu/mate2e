#pragma once
#include "tokenizer.h"

namespace mate
{
    class regex_tokenizer : public tokenizer
    {
        using tokenizer::tokenizer;
    public:
        
        bool tokenize(std::string text);
    };
}