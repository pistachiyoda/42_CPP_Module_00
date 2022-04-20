#include <iostream>
#include <string>

void megaphone(char **str, int argc)
{
    std::string upperStr = "";
    int i = 1;
    int j;

    while (i < argc)
    {
        j = 0;
        while (str[i][j])
        {
            if (str[i][j] >= 'a' && str[i][j] <= 'z')
                upperStr += std::toupper(str[i][j]);
            else
                upperStr += str[i][j];
            j++;
        }
        i++;
    }
    std::cout << upperStr;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        megaphone(argv, argc);
    std::cout << std::endl;
    return (0);
}
