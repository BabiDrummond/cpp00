#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"

void    printMenu()
{
	std::cout << "---------------------------" << std::endl;
	std::cout << "-------- PHONEBOOK --------" << std::endl;
	std::cout << "- Choose an option: -------" << std::endl;
	std::cout << "- 1. Add a contact --------" << std::endl;
	std::cout << "- 2. Search a contact -----" << std::endl;
	std::cout << "- 3. Exit -----------------" << std::endl;
	std::cout << "---------------------------" << std::endl;
}

int     getOption()
{
	int option;

	option = 0;
	while (option != 1 && option != 2 && option != 3)
	{
		std::cout << "- Option: ";
		std::cin >> option;
	}
	return (option);
}

void	selectOption(PhoneBook& pb, int option)
{
	if (option == 1)
		pb.addContact();
	else if (option == 2)
	{
		pb.searchContact();
		pb.displayContact();
	}
	else if (option == 3)
		exit(0);
}

int main(void)
{
	PhoneBook	pb;
	int			option;

	while (true)
	{
		printMenu();
		option = getOption();
		selectOption(pb, option);
	}
	return (0);
}
