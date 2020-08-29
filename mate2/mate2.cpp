// mate2.cpp: 定义应用程序的入口点。
//

#include "mate2.h"

#include"parser/regex_tokenizer.h"
#include "parser/char_tokenizer.h"
#include "parser/token.h"

int main()
{

    std::vector<mate::token> ts;

    std::vector<std::unique_ptr<mate::tokenizer>> cts;
    
    cts.push_back(std::unique_ptr<mate::tokenizer>(dynamic_cast<mate::tokenizer*>(new mate::regex_tokenizer("#_lines", R"eee(#([^\n]+\\\n)+[^\n]+\n)eee"))));
    cts.push_back(std::unique_ptr<mate::tokenizer>(dynamic_cast<mate::tokenizer*>(new mate::regex_tokenizer("#_line", R"eee(#[^\n]+[^\\]\n)eee"))));

    cts.push_back(std::unique_ptr<mate::tokenizer>(dynamic_cast<mate::tokenizer*>(new mate::regex_tokenizer("commit_line", R"(//[\S\s]+\n)"))));
    cts.push_back(std::unique_ptr<mate::tokenizer>(dynamic_cast<mate::tokenizer*>(new mate::regex_tokenizer("commit_lines", R"(/\*[\S\s]+\*/)"))));

    cts.push_back(std::unique_ptr<mate::tokenizer>(dynamic_cast<mate::tokenizer*>(new mate::regex_tokenizer("string", R"("[\S\s]+")"))));
    cts.push_back(std::unique_ptr<mate::tokenizer>(dynamic_cast<mate::tokenizer*>(new mate::regex_tokenizer("rawstring", "R\"[\\S\\s]+\""))));

    cts.push_back(std::unique_ptr<mate::tokenizer>(dynamic_cast<mate::tokenizer*>(new mate::regex_tokenizer("{}", R"(\{[\S\s]+\})"))));
    cts.push_back(std::unique_ptr<mate::tokenizer>(dynamic_cast<mate::tokenizer*>(new mate::char_tokenizer("MateTag", "mate"))));
    cts.push_back(std::unique_ptr<mate::tokenizer>(dynamic_cast<mate::tokenizer*>(new mate::char_tokenizer("Block", " "))));
    //cts.push_back(std::unique_ptr<mate::tokenizer>(dynamic_cast<mate::tokenizer*>(new mate::regex_tokenizer("*+", R"({\S+\})"))));

    std::string text = R"eeeee( #include "mate2.h"

#include"parser/regex_tokenizer.h"
#include "parser/char_tokenizer.h"
#define A ++++\
++b

#ifndef bool
#define ture 1
#define false 0
#endif

#include "parser/token.h"
mate ass{ fuckmate};
//一个string
auto s="(heheheh)";
/*一个R"()"的raw string*/
auto ssr=R"(heheheh)";
 )eeeee";

    auto itor_none_begin = text.begin();
    auto itor_none_end = itor_none_begin;
    for (auto itor_text_tm_begin = text.begin(); itor_text_tm_begin < text.end(); )
    {
        bool ifMatch = false;
        auto itor_text_next_begin = itor_text_tm_begin+1;
        
        
        for (auto itor_text_tm_end = itor_text_tm_begin+1; itor_text_tm_end <= text.end(); itor_text_tm_end++)
        {
            
            std::string text_tm(itor_text_tm_begin, itor_text_tm_end);
            ifMatch = false;
            for (auto& ct : cts)
            {
                
                if (ct->tokenize(text_tm))
                {
                    ts.push_back(mate::token(ct->name, text_tm));

                    ifMatch = true;
                    break;
                }
            }

            if (ifMatch)
            {
                itor_text_next_begin = itor_text_tm_end-1;
                break;
            }
            if (itor_text_tm_end == text.end())
            {
                break;
            }

        }

        if (!ifMatch)
        {
            itor_none_end= itor_text_tm_begin+1;
            itor_text_tm_begin++;
        }
        else
        {
            if (itor_none_end - itor_none_begin > 0)
            {
                ts.insert(ts.end() - 1, mate::token("None", std::string(itor_none_begin, itor_none_end)));
            }
            itor_none_begin = itor_text_next_begin+1;
            itor_none_end = itor_none_begin;
            itor_text_tm_begin = itor_text_next_begin+1;
        }
        
    }
    if (itor_none_end - itor_none_begin > 0)
    {
        ts.push_back(mate::token("None", std::string(itor_none_begin, itor_none_end)));
    }

    for (auto t : ts)
    {
        std::cout << t.name << " : " << t.text << "\n";
    }


    return 0;
}
