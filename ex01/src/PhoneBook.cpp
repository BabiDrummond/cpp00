#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::addContact(){
	std::string firstName = "";
    std::string lastName = "";
	std::string nickname = "";
    std::string phoneNumber = "";
    std::string darkestSecret = "";

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
	std::cout << "---------------------------" << std::endl;
	std::cout << "----- Contact added! ------" << std::endl;
}

void PhoneBook::searchContact(){

}

void PhoneBook::displayContact(int index){

}
