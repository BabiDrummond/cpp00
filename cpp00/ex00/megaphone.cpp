#include <iostream>
#include <string>
#include <cctype>

void    megaphone(int argc, char **argv)
{
    std::string word;

    for (int i = 0; i < argc; i++)
    {
        word = argv[i];
        for (size_t j = 0; j < word.length(); j++)
            word[j] = std::toupper(word[j]);
        std::cout << word;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
        megaphone(argc - 1, argv + 1);
    return (0);
}
