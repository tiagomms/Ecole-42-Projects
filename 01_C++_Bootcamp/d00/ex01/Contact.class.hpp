// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Contact.class.hpp                                  :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/15 15:21:51 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/15 15:44:41 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <stdlib.h>

class Contact {

	public:
		//constructor and destructor
		Contact();
		~Contact();
		
		//accessors
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getLogin();
		std::string	getPostalAddress();
		std::string	getEmailAddress();
		std::string	getPhoneNumber();
		std::string	getBirthdayDate();
		std::string	getFavoriteMeal();
		std::string	getUnderwearColor();
		std::string	getDarkestSecret();

		//mutator
		void	setFirstName( std::string );
		void	setLastName( std::string );
		void	setNickName( std::string );
		void	setLogin( std::string );
		void	setPostalAddress( std::string );
		void	setEmailAddress( std::string );
		void	setPhoneNumber( std::string );
		void	setBirthdayDate( std::string );	
		void	setFavoriteMeal( std::string );
		void	setUnderwearColor( std::string );
		void	setDarkestSecret( std::string );


	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _login;
		std::string _postal_address;
		std::string _email_address;
		std::string _phone_number;
		std::string _birthday_date;
		std::string _favorite_meal;
		std::string _underwear_color;
		std::string _darkest_secret;

};

#endif