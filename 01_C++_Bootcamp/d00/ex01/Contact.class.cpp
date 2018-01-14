// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Contact.class.cpp                                  :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/15 15:22:02 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/15 15:47:39 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Contact.class.hpp"

//constructor
Contact::Contact() {
	return;
}

//destructor
Contact::~Contact() {
	return;
}

//accessors
std::string	Contact::getFirstName()
{
	return this->_first_name;
}

std::string	Contact::getLastName()
{
	return this->_last_name;
}

std::string	Contact::getNickName()
{
	return this->_nickname;
}

std::string	Contact::getLogin()
{
	return this->_login;
}

std::string	Contact::getPostalAddress()
{
	return this->_postal_address;
}

std::string	Contact::getEmailAddress()
{
	return this->_email_address;
}

std::string	Contact::getPhoneNumber()
{
	return this->_phone_number;
}

std::string	Contact::getBirthdayDate()
{
	return this->_birthday_date;
}

std::string	Contact::getFavoriteMeal()
{
	return this->_favorite_meal;
}

std::string	Contact::getUnderwearColor()
{
	return this->_underwear_color;
}

std::string	Contact::getDarkestSecret()
{
	return this->_darkest_secret;
}


//mutators
void	Contact::setFirstName( std::string input)
{
	this->_first_name = input;
	return;
}

void	Contact::setLastName( std::string input)
{
	this->_last_name = input;
	return;
}

void	Contact::setNickName( std::string input)
{
	this->_nickname = input;
	return;
}

void	Contact::setLogin( std::string input)
{
	this->_login = input;
	return;
}

void	Contact::setPostalAddress( std::string input)
{
	this->_postal_address = input;
	return;
}

void	Contact::setEmailAddress( std::string input)
{
	this->_email_address = input;
	return;
}

void	Contact::setPhoneNumber( std::string input)
{
	this->_phone_number = input;
	return;
}

void	Contact::setBirthdayDate( std::string input)
{
	this->_birthday_date = input;
	return;
}

void	Contact::setFavoriteMeal( std::string input)
{
	this->_favorite_meal = input;
	return;
}

void	Contact::setUnderwearColor( std::string input)
{
	this->_underwear_color = input;
	return;
}

void	Contact::setDarkestSecret( std::string input)
{
	this->_darkest_secret= input;
	return;
}
