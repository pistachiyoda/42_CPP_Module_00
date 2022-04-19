#include <iostream>

char ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - ('a' - 'A'));
    return (c);
}

int main(int argc, char **argv)
{
    int i = 1;
    int j = 0;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (argc > i)
        {
            j = 0;
            while (argv[i][j])
            {
                std::cout << ft_toupper(argv[i][j]);
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}
