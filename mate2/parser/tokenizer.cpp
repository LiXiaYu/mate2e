#include "tokenizer.h"

mate::tokenizer::tokenizer()
{
}

mate::tokenizer::tokenizer(std::string rule):ruletext(rule)
{
}

mate::tokenizer::tokenizer(std::string name, std::string rule):ruletext(rule),name(name)
{
}
