#include "persian_toolkit.h"

bool is_persian_alphabet(char32_t ch)
{
    switch (ch)
    {
    case U'آ':
    case U'ا':
    case U'ب':
    case U'پ':
    case U'ت':
    case U'ث':
    case U'ج':
    case U'چ':
    case U'ح':
    case U'خ':
    case U'د':
    case U'ذ':
    case U'ر':
    case U'ز':
    case U'ژ':
    case U'س':
    case U'ش':
    case U'ص':
    case U'ض':
    case U'ط':
    case U'ظ':
    case U'ع':
    case U'غ':
    case U'ف':
    case U'ق':
    case U'ک':
    case U'گ':
    case U'ل':
    case U'م':
    case U'ن':
    case U'و':
    case U'ه':
    case U'ی':
        return true;
        break;
    
    default:
        return false;
        break;
    }
}

bool is_persian_number(char32_t ch)
{
    switch (ch)
    {
    case U'۰':
    case U'۱':
    case U'۲':
    case U'۳':
    case U'۴':
    case U'۵':
    case U'۶':
    case U'۷':
    case U'۸':
    case U'۹':
        return true;
        break;
    
    default:
        return false;
        break;
    }
}

bool is_whitespace(char32_t ch)
{
    switch (ch)
    {
    case U' ':
    case U'\n':
    case U'\t':
    case U'\r':
    case U'\v':
        return true;
        break;
    
    default:
        return false;
        break;
    }
}

bool is_operator(char32_t ch)
{
    switch (ch)
    {
    case U'=':
    case U'<':
    case U'>':
        return true;
        break;
    
    default:
        return false;
        break;
    }
}
