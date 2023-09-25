#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <fstream>

int main(int argc, char** argv)
{
    if (argc != 2) //checks if the compiler got the file argument
    {
        std::cout << "Brainfuck.exe <file_path>" << std::endl;
        return 1;
    }

    std::string program;
    std::ifstream file;

    file.open(std::string(argv[1])); 

    if(!file)
    {
        std::cout << "File path not valid" << std::endl;
        return 1;
    }
    
    file >> program;

    file.close();

    std::cout << program << std::endl;

    return 0;
}