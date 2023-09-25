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

    std::string program = "";
    std::string input = "";
    std::string temp = "";
    std::stack<size_t> loop_stack;
    std::unordered_map<size_t, size_t> loop_map;
    size_t ip = 0;
    std::vector<unsigned char> memory = {0};
    size_t im = 0;
    
    while (std::getline(file, temp))
        program += temp;

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

    ip = 0;

    while(ip < program.size())
    {
        switch(program[ip])
        {
            case '+':
            {
                memory[im]++;
                break;
            }
            case '-':
            {
                memory[im]--;
                break;
            }
            case '>':
            {
                im++;
                if (im == memory.size())
                    memory.push_back(0);
                break;
            }
            case '<':
            {
                if(im > 0)
                    im--;
                break;
            }
            case '.':
            {
                std::cout << memory[im];
                break;
            }
            case ',':
            {
                if(!input.empty())
                {
                    std::cin >> input;
                    input.push_back('\n');
                }
                memory[im] = input[0];
                input.erase(0, 1);
                break;
            }
            case '[':
            {
                if (!memory[im])
                    ip = loop_map[ip];
                break;
            }
            case ']':
            {
                if (memory[im])
                    ip = loop_map[ip];
                break;
            }
        }
        ip++;
    }

    return 0;
}