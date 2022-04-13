#include <string>
#include <iostream>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();
    ~Contact();
    void set_first_name(std::string val);
    void set_last_name(std::string val);
    void set_nickname(std::string val);
    void set_phone_number(std::string val);
    void set_darkest_secret(std::string val);
    std::string get_first_name();
    std::string get_last_name();
    std::string get_nickname();
    std::string get_phone_number();
    std::string get_dakest_secret();
};