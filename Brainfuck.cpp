#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <fstream>

int main(int argc, std::string argv[])
{
    if (argc != 2) //checks if the compiler got the file argument
    {
        std::cout << "Brainfuck.exe <file_path>" << std::endl;
        return 1;
    }

    std::string program;
    std::ifstream file(argv[1]);

    if(!file.is_open())
    {
        std::cout << "File path not valid" << std::endl;
        return 1;
    }

    std::getline(file, program, '\0');
    
    return 0;
}