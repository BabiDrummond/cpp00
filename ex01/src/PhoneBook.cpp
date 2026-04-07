#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::addContact(){
	std::string firstName = "";
    std::string lastName = "";
	std::string nickname = "";
    std::string phoneNumber = "";
    std::string darkestSecret = "";

	std::cin.ignore();
	while (firstName.empty())
	{
		std::cout << "- First name: ";
		std::getline(std::cin, firstName);
	}
	while (lastName.empty())
	{
    	std::cout << "- Last name: ";
		std::getline(std::cin, lastName);
	}
	while (nickname.empty())
	{
    	std::cout << "- Nickname: ";
		std::getline(std::cin, nickname);
	}
	while (phoneNumber.empty())
	{
    	std::cout << "- Phone number: ";
		std::getline(std::cin, phoneNumber);
	}
	while (darkestSecret.empty())
	{
    	std::cout << "- Darkest secret: ";
		std::getline(std::cin, darkestSecret);
	}
	contacts[index] = Contact(
							firstName,
							lastName,
							nickname,
							phoneNumber,
							darkestSecret
						);
	PhoneBook::index++;
	std::cout << "---------------------------" << std::endl;
	std::cout << "----- Contact added! ------" << std::endl;
	std::cout << std::endl;
}

void PhoneBook::searchContact(){

	std::cout << "_________________ PHONEBOOK _________________" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|INDEX     |NAME      |LAST NAME |NICKNAME  |" << std::endl;	
	for (int i = 0; i < index; i++)
	{
		std::cout << "|" << formatResult(toString(i)) << "|";
		std::cout << formatResult(contacts[i].getFirstName()) << "|";
		std::cout << formatResult(contacts[i].getLastName()) << "|";
		std::cout << formatResult(contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

void PhoneBook::displayContact(int index){
	std::cout << index;
}

std::string PhoneBook::formatResult(std::string text)
{
	std::string result;
	int length;
	int	max_c;

	max_c = 10;
	length = text.length();
	result = text;
	if (length <= max_c)
		for (int i = 0; i < max_c - length; i++)
			result += " ";
	else
		 result = text.substr(0, 8) + ".";
	return (result);
}

std::string PhoneBook::toString(int num)
{
	std::stringstream ss;
	ss << num;
	return (ss.str());
}
