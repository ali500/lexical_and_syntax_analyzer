#pragma once

#include "Lexer.h"
#include "Token.h"
#include <fmt/color.h>

// گرامر راست خطی

// right-handed linear grammar

// S -> id A
// A -> op B
// B -> num C
// C -> end_of_statement D
// D -> id A | end_of_code E
// E -> λ

class Parser
{
private:
    Lexer lexer;
    Token token;

    void S();
    void A();
    void B();
    void C();
    void D();
    void E();
public:
    Parser(Lexer lexer);
    ~Parser();
    void parse();
};
