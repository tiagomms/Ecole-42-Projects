
#include "Contact.class.hpp"

Contact	add_contact()
{
	Contact new_contact;	
	std::string input;

	std::cout << "\nAdding new contact:\n";
	std::cout << "First name: ";
	std::getline (std::cin, input);
	new_contact.setFirstName(input);

	std::cout << "Last name: ";
	std::getline (std::cin, input);
	new_contact.setLastName(input);

	std::cout << "Nickname: ";
	std::getline (std::cin, input);
	new_contact.setNickName(input);

	std::cout << "Login: ";
	std::getline (std::cin, input);
	new_contact.setLogin(input);

	std::cout << "Postal Address: ";
	std::getline (std::cin, input);
	new_contact.setPostalAddress(input);

	std::cout << "Email Address: ";
	std::getline (std::cin, input);
	new_contact.setEmailAddress(input);

	std::cout << "Phone Number: ";
	std::getline (std::cin, input);
	new_contact.setPhoneNumber(input);

	std::cout << "Birthday Date: ";
	std::getline (std::cin, input);
	new_contact.setBirthdayDate(input);

	std::cout << "Favorite Meal: ";
	std::getline (std::cin, input);
	new_contact.setFavoriteMeal(input);

	std::cout << "Underwear Color: ";
	std::getline (std::cin, input);
	new_contact.setUnderwearColor(input);

	std::cout << "Darkest Secret: ";
	std::getline (std::cin, input);
	new_contact.setDarkestSecret(input);

	std::cout << "\nContact finally introduced\n";
	return new_contact;
}

void	printContact(Contact contact)
{
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Login: " << contact.getLogin() << std::endl;
	std::cout << "Postal Address: " << contact.getPostalAddress() << std::endl;
	std::cout << "Email Address: " << contact.getEmailAddress() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Birthday Date: " << contact.getBirthdayDate() << std::endl;
	std::cout << "Favorite Meal: " << contact.getFavoriteMeal() << std::endl;
	std::cout << "Underwear Color: " << contact.getUnderwearColor() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void	printContactDetail(std::string detail)
{
	if (detail.length() > 10)
	{
		detail.resize(9);
		std::cout << detail << ".";
	}
	else
	{
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << detail;
	}
	std::cout << "|";
}

void	search_phonebook(Contact *phonebook, int last_index)
{
	int 		i;
	std::string	input_index;
	char		print_index[2];
	int			atoi_index;

	i = 0;
	if (last_index == 0)
	{
		std::cout << "\nNo contacts in phonebook\n";
		return;
	}
	std::cout << "\nAll contacts in Awesome Phone Book\n\n";
	printContactDetail("Index");
	printContactDetail("First name");
	printContactDetail("Last name");
	printContactDetail("Nickname");
	std::cout << std::endl;
	print_index[1] = '\0';
	while (i < last_index)
	{
		print_index[0] = i + '1';
		printContactDetail(std::string(1, print_index[0]));
		printContactDetail(phonebook[i].getFirstName());
		printContactDetail(phonebook[i].getLastName());
		printContactDetail(phonebook[i].getNickName());
		std::cout << std::endl;
		i++;
	}
	std::cout << "\nInput contact index you wish: ";
	std::getline (std::cin, input_index);
	atoi_index = atoi(input_index.c_str());
	if (atoi_index == 0 || atoi_index > last_index)
		std::cout << "Invalid index. Bye bye\n";
	else
	{
		std::cout << "\nThere you go, all details.";
		printContact(phonebook[atoi_index - 1]);
	}
}

int		main(void)
{
	std::string	input;
	Contact phonebook[8];
	int		index;

	index = 0;
	std::cout << "Welcome to HiTech Phonebook with fixed details and \
only 3 functions!\n";
	while (1)
	{
		std::cout << "\nValid inputs: EXIT | ADD | SEARCH\n";
		std::getline (std::cin, input);
		if (input == "EXIT")
			exit(0);
		else if (input == "ADD")
		{
			if (index < 8)
			{
				phonebook[index] = add_contact();
				index++;
			}
			else
				std::cout << "Awesome phone book has reached its limit of 8 contacts.\nIf you want to introduce more, it is time to lose your precious contacts.\n80's TECHNOLOGY IS THE BEST!\n\n";
		}
		else if (input == "SEARCH")
		{
			search_phonebook(phonebook, index);
		}
		else
			std::cout << "Unknown input. Machine Learning has not been invented yet. Apologies\n";
	}
	return 0;
}