# CMakeList.txt: mate2 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 将源代码添加到此项目的可执行文件。
add_executable (mate2 "mate2.cpp" "mate2.h" "parser/parser.h" "parser/parser.cpp" "parser/tokenizer.h" "parser/tokenizer.cpp" "parser/regex_tokenizer.h" "parser/regex_tokenizer.cpp" "parser/char_tokenizer.cpp" "parser/char_tokenizer.h" "parser/token.h" "parser/token.cpp")

# TODO: 如有需要，请添加测试并安装目标。
