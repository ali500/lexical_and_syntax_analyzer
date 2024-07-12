#include "file_toolkit.h"

std::u32string get_data_of_utf8_file_into_u32string(std::string path)
{
    std::fstream file(path);

    if ( ! file.is_open() )
    {
        fmt::print(fmt::fg(fmt::color::light_coral), "File not found.\n");
        exit(EXIT_FAILURE);
    }
    

    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::u32string data = una::utf8to32u(str);

    file.close();

    return data;
}
