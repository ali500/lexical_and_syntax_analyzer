#include "Token.h"

Token::Token()
{
    tokenName = U"Empty";
    tokenType = Type::TOKEN_END_OF_CODE;
}

Token::Token(std::u32string name, Type type)
{
    tokenName = name;
    tokenType = type;
}

Token::~Token()
{
}

Type Token::getType()
{
    return tokenType;
}

std::u32string Token::getName()
{
    return tokenName;
}

void Token::print()
{
    std::string token_name = una::utf32to8(tokenName);
    std::string token_type;

    switch (tokenType)
    {
    case Type::TOKEN_IDENTIFIER :
        token_type = "id";
        break;
    
    case Type::TOKEN_OPERATOR :
        token_type = "operator";
        break;
    
    case Type::TOKEN_NUMBER :
        token_type = "number";
        break;
    
    case Type::TOKEN_END_OF_STATEMENT :
        token_type = "end_of_statement";
        break;
    
    case Type::TOKEN_END_OF_CODE :
        token_type = "end_of_code";
        break;
    
    default:
        fmt::print(fmt::fg(fmt::color::light_coral), "Token Type is unknown.\n");
        exit(EXIT_FAILURE);
        break;
    }

    fmt::print("{}{:<10}{}{}{:<16}{}\n",
        fmt::styled("< name: ",  fmt::fg(fmt::color::light_green)),
        fmt::styled(token_name,  fmt::fg(fmt::color::blue       )),
        fmt::styled(" , "     ,  fmt::fg(fmt::color::light_green)),
        fmt::styled("type: "  ,  fmt::fg(fmt::color::light_green)),
        fmt::styled(token_type,  fmt::fg(fmt::color::blue       )),
        fmt::styled(" >"      ,  fmt::fg(fmt::color::light_green))
    );
}
