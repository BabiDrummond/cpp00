#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <sstream>
#include "Contact.hpp"

class PhoneBook {
	private:
		int			index;
		Contact 	contacts[8];
		std::string formatResult(std::string text);
		std::string toString(int num);
	public:
		PhoneBook();
		void addContact();
		void searchContact();
		void displayContact();
};

#endif