#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->index = 0;
    this->is_added_more_than_max = false;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::show_welcome_prompt(void)
{
    std::cout << "░█░█░█▀▀░█░░░█▀▀░█▀█░█▄█░█▀▀░░░▀█▀░█▀█░░░█▄█░█░█" << std::endl;
    std::cout << "░█▄█░█▀▀░█░░░█░░░█░█░█░█░█▀▀░░░░█░░█░█░░░█░█░░█░" << std::endl;
    std::cout << "░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░░░░▀░░▀▀▀░░░▀░▀░░▀░" << std::endl;
    std::cout << "░█▀█░█░█░█▀▀░█▀▀░█▀█░█▄█░█▀▀░░░█▀█░█░█░█▀█░█▀█░█▀▀░█▀▄░█▀█░█▀█░█░█░█░█" << std::endl;
    std::cout << "░█▀█░█▄█░█▀▀░▀▀█░█░█░█░█░█▀▀░░░█▀▀░█▀█░█░█░█░█░█▀▀░█▀▄░█░█░█░█░█▀▄░▀░▀" << std::endl;
    std::cout << "░▀░▀░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░░░▀░░░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀░░▀▀▀░▀▀▀░▀░▀░▀░▀" << std::endl;
    std::cout << std::endl;
}

void PhoneBook::show_exit_prompt(void)
{
    std::cout << std::endl;
    std::cout << "░▀█▀░█░█░█▀█░█▀█░█░█░░░█░█░█▀█░█░█░░░█▀▀░█▀█░█▀▄░░░█░█░█▀▀░▀█▀░█▀█░█▀▀░█░█" << std::endl;
    std::cout << "░░█░░█▀█░█▀█░█░█░█▀▄░░░░█░░█░█░█░█░░░█▀▀░█░█░█▀▄░░░█░█░▀▀█░░█░░█░█░█░█░▀░▀" << std::endl;
    std::cout << "░░▀░░▀░▀░▀░▀░▀░▀░▀░▀░░░░▀░░▀▀▀░▀▀▀░░░▀░░░▀▀▀░▀░▀░░░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀░▀" << std::endl;
    std::cout << "░█▀▀░█▀█░█▀█░█▀▄░░░█▀▄░█░█░█▀▀░█░█" << std::endl;
    std::cout << "░█░█░█░█░█░█░█░█░░░█▀▄░░█░░█▀▀░▀░▀" << std::endl;
    std::cout << "░▀▀▀░▀▀▀░▀▀▀░▀▀░░░░▀▀░░░▀░░▀▀▀░▀░▀" << std::endl;
}

void PhoneBook::show_commands(void)
{
    std::cout << "Please input ADD, SEARCH, or EXIT." << std::endl;
    std::cout << "< ADD >" << std::endl;
    std::cout << "	- You can store a maximum of 8 contacts data." << std::endl;
    std::cout << "	- The contact fields are: first name, last name, nickname, phone number, and darkest secret." << std::endl;
    std::cout << "	- The data can't be empty." << std::endl;
    std::cout << "< SEARCH >" << std::endl;
    std::cout << "	- Display the saved contacts as a list of 4 columns: index, first name, last name and nickname." << std::endl;
    std::cout << "	- Input valid index and then display the contact information, one field per line." << std::endl;
    std::cout << "< EXIT >" << std::endl;
    std::cout << "	- The program quits and the contacts are lost forever!" << std::endl;
    std::cout << std::endl;
}

bool PhoneBook::is_blank_str(std::string str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!isblank(str[i]))
            return (false);
        i++;
    }
    return (true);
}

std::string PhoneBook::get_contact_input(std::string prop)
{
    std::string input;

    while (true)
    {
        std::cout << "Please input " << prop << "." << std::endl;
        std::cout << "$>> ";
        std::getline(std::cin, input);
        if (prop == "phone number")
        {
            if (!is_digit_str(input))
            {
                std::cerr << "\033[31mPlease input NUMBER for phone number.\033[m" << std::endl;
                continue;
            }
        }
        if (!this->is_blank_str(input))
            return (input);
        std::cerr << "\033[31mData cannot be blank, please input something.\033[m" << std::endl;
    }
}

void PhoneBook::add_user(void)
{
    if (this->index == MAX)
    {
        this->index = 0;
        this->is_added_more_than_max = true;
    }
    contacts[this->index].set_first_name(this->get_contact_input("first name"));
    contacts[this->index].set_last_name(this->get_contact_input("last name"));
    contacts[this->index].set_nickname(this->get_contact_input("nickname"));
    contacts[this->index].set_phone_number(this->get_contact_input("phone number"));
    contacts[this->index].set_darkest_secret(this->get_contact_input("darkest secret"));

    this->index++;
    std::cout << "\033[32mNew user is added!\033[m" << std::endl;
    std::cout << std::endl;
}

std::string PhoneBook::proc_output(std::string raw_data)
{
    if (raw_data.length() >= 10)
    {
        raw_data[9] = '.';
        return (raw_data.substr(0, 10));
    }
    return (raw_data);
}

void PhoneBook::show_users(void)
{
    int i;
    int max;
    std::string first_name;
    std::string last_name;
    std::string nick_name;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|";
    std::cout << std::setw(10) << "index";
    std::cout << "|";
    std::cout << std::setw(10) << "first name";
    std::cout << "|";
    std::cout << std::setw(10) << "last name";
    std::cout << "|";
    std::cout << std::setw(10) << "nickname";
    std::cout << "|";
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    i = 0;
    max = this->is_added_more_than_max ? MAX : this->index;
    while (max > i)
    {
        std::cout << "|";
        std::cout << std::setw(10) << i + 1;
        std::cout << "|";
        std::cout << std::setw(10) << proc_output(contacts[i].get_first_name());
        std::cout << "|";
        std::cout << std::setw(10) << proc_output(contacts[i].get_last_name());
        std::cout << "|";
        std::cout << std::setw(10) << proc_output(contacts[i].get_nickname());
        std::cout << "|";
        std::cout << std::endl;
        i++;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

bool PhoneBook::is_digit_str(std::string str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool PhoneBook::is_valid_index(int input)
{
    if (input < 0)
        return (false);
    if (input > this->index)
        return (false);
    return (true);
}

int PhoneBook::get_index_input()
{
    std::string input;
    int index;

    while (true)
    {
        std::cout << "Please input index number you want to see." << std::endl;
        std::cout << "$>> ";
        std::getline(std::cin, input);
        if (is_digit_str(input))
        {
            index = std::stoi(input);
            if (is_valid_index(index))
                return (index);
        }
        std::cerr << "\033[31mPlease input valid index number.\033[m" << std::endl;
    }
}

void PhoneBook::show_user(int index)
{
    std::cout << "first name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "last name: " << contacts[index].get_last_name() << std::endl;
    std::cout << "nickname: " << contacts[index].get_nickname() << std::endl;
    std::cout << "phone number: " << contacts[index].get_phone_number() << std::endl;
    std::cout << "darkest secret: " << contacts[index].get_dakest_secret() << std::endl;
}

void PhoneBook::search_user(void)
{
    int index;

    if (this->index == 0)
    {
        std::cerr << "\033[31mPlease add user first.\033[m" << std::endl;
        std::cout << std::endl;
        return;
    }
    PhoneBook::show_users();
    index = PhoneBook::get_index_input();
    PhoneBook::show_user(index - 1);
}