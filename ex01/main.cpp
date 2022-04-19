#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook phoneBook;
    std::string command;

    try
    {
        phoneBook.show_welcome_prompt();
        phoneBook.show_commands();
        while (true)
        {
            std::cout << "$>> ";
            std::getline(std::cin, command);
            if (command == "ADD")
            {
                phoneBook.add_user();
            }
            else if (command == "SEARCH")
            {
                phoneBook.search_user();
            }
            else if (command == "EXIT")
            {
                phoneBook.show_exit_prompt();
                break;
            }
            else if (std::cin.good() == 0)
                return (0);
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
