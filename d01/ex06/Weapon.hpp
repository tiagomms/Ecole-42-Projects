// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Weapon.hpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:18:57 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:18:58 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

/*
Make a Weapon class, that has a type string, and a getType that returns a const
reference to this string. Also has a setType.
*/

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>
# include <sstream>

class Weapon{

public:
	Weapon( std::string );
	~Weapon();
	std::string const & getType( void ) const;
	void setType( std::string );

private:
	std::string _type;
};

#endif