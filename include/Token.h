#pragma once

#include <string>
#include <fmt/color.h>
#include <uni_algo/conv.h>

enum Type {
    TOKEN_IDENTIFIER,
    TOKEN_OPERATOR,
    TOKEN_NUMBER,
    TOKEN_END_OF_STATEMENT,
    TOKEN_END_OF_CODE,
};

class Token
{
private:
    std::u32string tokenName;
    Type tokenType;
public:
    Token();
    Token(std::u32string name, Type type);
    ~Token();
    Type getType();
    std::u32string getName();
    void print();
};
