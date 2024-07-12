#include "lexer.h"
#include "Parser.h"
#include "file_toolkit.h"

int main()
{
    std::u32string code = get_data_of_utf8_file_into_u32string("my-language.txt");
    Lexer lexer(code);

    Parser parser(lexer);
    parser.parse();

    return 0;
}
