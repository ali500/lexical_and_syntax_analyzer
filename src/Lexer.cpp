#include "Lexer.h"

Lexer::Lexer()
{
}

Lexer::Lexer(std::u32string sourceCode)
{
    this->sourceCode = sourceCode;
    currentCharIndex = -1;
    currentState = 0;
}

Lexer::~Lexer()
{
}

char32_t Lexer::moveToNextChar()
{
    if (currentCharIndex + 1 < sourceCode.length())
    {
        currentCharIndex++;
        return sourceCode.at(currentCharIndex);
    }
    else
    {
        return U'$';
    }
}

char32_t Lexer::watchNextChar()
{
    if (currentCharIndex + 1 < sourceCode.length())
    {
        return sourceCode.at(currentCharIndex + 1);
    }
    else
    {
        return U'$';
    }
}

Token Lexer::nextToken()
{
    currentState = 0;
    char32_t ch = U'\0';
    char32_t next_ch = U'\0';
    std::u32string token_name;

    while (ch != U'$')
    {
        switch (currentState)
        {
        case 0:
            ch = moveToNextChar();
    
            if (is_persian_alphabet(ch))
            {
                currentState = 1;
                token_name.push_back(ch);
            }
            else if (ch == U'_')
            {
                currentState = 4;
                token_name.push_back(ch);
            }
            else if (ch == U'=')
            {
                token_name.push_back(ch);
                currentState = 5;
            }
            else if (is_persian_number(ch))
            {
                currentState = 6;
                token_name.push_back(ch);
            }
            else if (ch == U'$')
            {
                token_name.push_back(ch);
                currentState = 7;
            }
            else if (ch == U'\n')
            {
                token_name = U"<newline>";
                currentState = 8;
            }
            else if (ch == U' ')
            {
                currentState = 0;
            }
            else
            {
                fmt::print(fmt::fg(fmt::color::light_coral), "Error: State {} ch: {}",
                    currentState, una::utf32to8(std::u32string(1, ch)));
                exit(EXIT_FAILURE);
            }
            
            break;

        case 1:
            next_ch = watchNextChar();
            
            if (is_persian_alphabet(next_ch))
            {
                ch = moveToNextChar();
                token_name.push_back(ch);
                currentState = 1;
            }
            else if (next_ch == U'\u200c')
            {
                ch = moveToNextChar();
                token_name.push_back(ch);
                currentState = 2;
            }
            else if (next_ch == U'_')
            {
                ch = moveToNextChar();
                token_name.push_back(ch);
                currentState = 4;
            }
            else
            {
                Token token(token_name, Type::TOKEN_IDENTIFIER);
                return token;
            }
            
            next_ch = U'\0';
            break;
        
        case 2:
            ch = moveToNextChar();
            if (is_persian_alphabet(ch))
            {
                token_name.push_back(ch);
                currentState = 3;
            }
            else
            {
                fmt::print(fmt::fg(fmt::color::light_coral), "Error: State {} ch: {}",
                    currentState, una::utf32to8(std::u32string(1, ch)));
                exit(EXIT_FAILURE);
            }
            
            break;
        
        case 3:
            next_ch = watchNextChar();
            if (is_persian_alphabet(next_ch))
            {
                ch = moveToNextChar();
                token_name.push_back(ch);
                currentState = 3;
            }
            else if (next_ch == U'\u200c')
            {
                ch = moveToNextChar();
                token_name.push_back(ch);
                currentState = 2;
            }
            else if (next_ch == U'_')
            {
                ch = moveToNextChar();
                token_name.push_back(ch);
                currentState = 4;
            }
            else
            {
                Token token(token_name, Type::TOKEN_IDENTIFIER);
                return token;
            }
            
            next_ch = U'\0';
            break;
        
        case 4:
            next_ch = watchNextChar();
            if (is_persian_alphabet(next_ch))
            {
                ch = moveToNextChar();
                token_name.push_back(ch);
                currentState = 1;
            }
            else if (next_ch == U'_')
            {
                ch = moveToNextChar();
                token_name.push_back(ch);
                currentState = 4;
            }
            else
            {
                Token token(token_name, Type::TOKEN_IDENTIFIER);
                return token;
            }
            
            next_ch = U'\0';
            break;
        
        case 5:
        {
            Token token(token_name, Type::TOKEN_OPERATOR);
            return token;
            break;
        }
        
        case 6:
            next_ch = watchNextChar();

            if (is_persian_number(next_ch))
            {
                ch = moveToNextChar();
                token_name.push_back(ch);
                currentState = 6;
            }
            else
            {
                Token token(token_name, Type::TOKEN_NUMBER);
                return token;
            }

            next_ch = U'\0';
            break;
        
        case 7:
        {
            Token token(token_name, Type::TOKEN_END_OF_CODE);
            return token;
            break;
        }
        
        case 8:
            next_ch = watchNextChar();
            if (next_ch == U'\n' || next_ch == U' ')
            {
                ch = moveToNextChar();
                token_name = U"<newline>";
                currentState = 8;
            }
            else
            {
                Token token(token_name, Type::TOKEN_END_OF_STATEMENT);
                return token;
            }
            
            next_ch = U'\0';
            break;
        
        default:
            fmt::print(fmt::fg(fmt::color::light_coral), "Error: State {} ch: {}",
                currentState, una::utf32to8(std::u32string(1, ch)));
            exit(EXIT_FAILURE);
            break;
        }
    }

    Token token(U"$", Type::TOKEN_END_OF_CODE);
    return token;
}
