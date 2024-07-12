#include "parser.h"

Parser::Parser(Lexer lexer)
{
    this->lexer = lexer;
}

Parser::~Parser()
{
}

void Parser::parse()
{
    S();
}

void Parser::S()
{
    token = lexer.nextToken();
    token.print();

    if (token.getType() == Type::TOKEN_IDENTIFIER)
    {
        A();
    }
    else
    {
        fmt::print(fmt::fg(fmt::color::light_coral), "the statement must begin with an identifier\n");
        exit(EXIT_FAILURE);
    }
}

void Parser::A()
{
    token = lexer.nextToken();
    token.print();

    if (token.getType() == Type::TOKEN_OPERATOR)
    {
        B();
    }
    else
    {
        fmt::print(fmt::fg(fmt::color::light_coral), "the operator must come after the identifier\n");
        exit(EXIT_FAILURE);
    }
}

void Parser::B()
{
    token = lexer.nextToken();
    token.print();

    if (token.getType() == Type::TOKEN_NUMBER)
    {
        C();
    }
    else
    {
        fmt::print(fmt::fg(fmt::color::light_coral), "the number must come after the operator\n");
        exit(EXIT_FAILURE);
    }
}

void Parser::C()
{
    token = lexer.nextToken();
    token.print();

    if (token.getType() == Type::TOKEN_END_OF_STATEMENT)
    {
        D();
    }
    else
    {
        fmt::print(fmt::fg(fmt::color::light_coral), "a newline character must come after the number\n");
        exit(EXIT_FAILURE);
    }
}

void Parser::D()
{
    token = lexer.nextToken();
    token.print();

    if (token.getType() == Type::TOKEN_IDENTIFIER)
    {
        A();
    }
    else if (token.getType() == Type::TOKEN_END_OF_CODE)
    {
        E();
    }
    else
    {
        fmt::print(fmt::fg(fmt::color::light_coral), "Either your code should end or the identifier should come after it.\n");
        exit(EXIT_FAILURE);
    }
}

void Parser::E()
{
    fmt::print(fmt::fg(fmt::color::light_green), "your code is syntactically correct\n");

    return;
}
