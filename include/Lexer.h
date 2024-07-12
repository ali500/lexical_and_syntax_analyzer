#pragma once

#include <uni_algo/conv.h>
#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/xchar.h>
#include <string>
#include "persian_toolkit.h"
#include "Token.h"

class Lexer
{
private:
    int currentState;
    int currentCharIndex;
    std::u32string sourceCode;
public:
    Lexer();
    Lexer(std::u32string sourceCode);
    ~Lexer();
    char32_t moveToNextChar();
    char32_t watchNextChar();
    Token nextToken();
};
