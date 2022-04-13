#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX 3 // 8に直す

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <ctype.h>
#include <iomanip>

class PhoneBook
{
private:
    Contact contacts[MAX];
    int index;
    bool is_added_more_than_max;
    std::string get_contact_input(std::string prop);
    bool is_blank_str(std::string str);
    int get_index_input();
    bool is_valid_index(int input);
    void show_users(void);
    void show_user(int index);
    std::string proc_output(std::string raw_data);

public:
    PhoneBook();
    ~PhoneBook();
    void show_welcome_prompt(void);
    void show_exit_prompt(void);
    void show_commands(void);
    void add_user(void);
    void search_user(void);
};

#endif