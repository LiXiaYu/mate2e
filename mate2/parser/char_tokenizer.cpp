#include "char_tokenizer.h"

namespace mate
{
    bool char_tokenizer::tokenize(std::string text)
    {
        return text.compare(this->ruletext) == 0;
    }
}

