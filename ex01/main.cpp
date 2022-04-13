#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook PhoneBook; // インスタンスは小文字
    std::string command;

    try
    {
        PhoneBook.show_welcome_prompt();
        while (true)
        {
            PhoneBook.show_commands();
            std::cout << "$>> ";
            std::getline(std::cin, command);
            if (command == "ADD")
            {
                PhoneBook.add_user();
            }
            else if (command == "SEARCH")
            {
                PhoneBook.search_user();
            }
            else if (command == "EXIT")
            {
                PhoneBook.show_exit_prompt();
                break;
            }
            else if (std::cin.eof())
            {
                return (0);
            }
            else
            {
                std::cerr << "\033[31mOnly ADD, SEARCH, or EXIT commands are acceptable!!\033[m" << std::endl;
                std::cout << std::endl;
                continue;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "\033[31mThis program terminates because an strange value was entered!!\033[m" << std::endl;
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
