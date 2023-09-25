#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    if (argc != 2) //checks if the compiler got the file argument
    {
        std::cout << "Deadfish.exe <file_path>" << std::endl;
        return 1;
    }

    std::ifstream file;
    std::string program = "";
    std::string temp = "";
    char num = 0;

    file.open(std::string(argv[1])); 

    if(!file)
    {
        std::cout << "File path not valid" << std::endl;
        return 1;
    }

    while (std::getline(file, temp))
        program += temp;

    file.close();

    for(int i = 0; i < program.size(); i++)
    {
        switch (program[i])
        {
            case 'i':
            {
                num++;
                break;
            }
            case 'd':
            {
                num--;
                break;
            }
            case 's':
            {
                num *= num;
                break;
            }
            case 'o':
            {
                std::cout << num;
                break;
            }
        }
        if(num == -1 || num == 256)
            num = 0;
    }

    return 0;
}