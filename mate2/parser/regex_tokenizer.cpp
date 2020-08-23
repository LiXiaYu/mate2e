#include "regex_tokenizer.h"

namespace mate
{
    bool regex_tokenizer::tokenize(std::string text)
    {
        std::regex reg(this->ruletext);
        std::smatch matchResult;

        if (std::regex_match(text, matchResult, reg))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

