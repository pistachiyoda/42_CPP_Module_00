#include "PhoneBook.hpp"
#include <iostream>
#include <fstream>

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout.exceptions(std::ios::badbit | std::ios::eofbit | std::ios::failbit);
    std::cin.exceptions(std::ios::badbit | std::ios::eofbit | std::ios::failbit);

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
                std::cerr << RED << "Only ADD, SEARCH, or EXIT commands are acceptable!!" << RESET << std::endl;
                std::cout << std::endl;
                continue;
            }
        }
    }
    catch (std::ios_base::failure &e)
    {
        std::cerr << RED << "STDIN or STDOUT is closed!!" << RESET << std::endl;
        std::cerr << e.what() << std::endl;
        return (1);
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "This program terminates because an strange value was entered!!" << RESET << std::endl;
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
