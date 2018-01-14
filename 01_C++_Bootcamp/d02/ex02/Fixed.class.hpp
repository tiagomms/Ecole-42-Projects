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
#include <cmath>

class Fixed {

public:
	Fixed(void); //Canonical
	~Fixed(void); //Canonical
	Fixed(Fixed const & src); //Canonical
	Fixed & operator=(Fixed const & src); // Canonical
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed( int const integer);
	Fixed( float const full_float);

	float toFloat( void ) const;
	int toInt( void ) const;

	float	operator*(Fixed const rhs);
	float	operator/(Fixed const rhs);
	float	operator-(Fixed const rhs);
	float	operator+(Fixed const rhs);

	//prefix
	Fixed & operator++();
	Fixed & operator--();
	//postfix
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed & min(Fixed &a, Fixed &b);
	static Fixed const & min(Fixed const &a, Fixed const &b);
	static Fixed & max(Fixed &a, Fixed &b);
	static Fixed const & max(Fixed const &a, Fixed const &b);


private:
	int 				_value;
	static const int 	_BITS; // <=> FIXED(32, _BITS), 32 from int

};

std::ostream &	operator<<( std::ostream & o, Fixed const &representation);

#endif