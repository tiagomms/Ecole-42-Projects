// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Fixed.class.hpp                                    :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/17 13:49:36 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/17 13:49:36 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {

public:
	Fixed(void); //Canonical
	~Fixed(void); //Canonical
	Fixed(Fixed const & src); //Canonical
	Fixed & operator=(Fixed const & src); // Canonical
	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int 				_value;
	static const int 	_nFractionalBits;

};

#endif