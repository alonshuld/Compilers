#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>

int main(int argc, char** argv)
{
    if (argc != 2) //checks if the compiler got the file argument
    {
        std::cout << "Brainfuck.exe <file_path>" << std::endl;
        return 1;
    }

    std::ifstream file;

    file.open(std::string(argv[1])); 

    if(!file)
    {
        std::cout << "File path not valid" << std::endl;
        return 1;
    }

    std::string program;
    std::stack<size_t> loop_stack;
    std::unordered_map<size_t, size_t> loop_map;
    size_t ip;
    std::vector<unsigned char> memory;
    
    while (file.good())
        file >> program;

    file.close();

    for (ip = 0; ip < program.size(); ip++)
    {
        if (program[ip] == '[')
        {
            loop_stack.push(ip);
        }
        else if (program[ip] == ']')
        {
            loop_map[ip] = loop_stack.top();
            loop_map[loop_stack.top()] = ip;
            loop_stack.pop();
        }
    }

    if(!loop_stack.empty())
    {
        std::cout << "Missing brackets in the code" << std::endl;
        return 1;
    }

    return 0;
}