#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook PhoneBook;
    std::string command;

    PhoneBook.show_prompt();
    while (true)
    {
        PhoneBook.show_commands();
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
            std::cout << "EXIT." << std::endl;
            break;
        }
        else
            continue;
    }
    return (0);
}
