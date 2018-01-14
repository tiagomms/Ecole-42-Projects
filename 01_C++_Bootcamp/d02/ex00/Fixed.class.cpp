// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Fixed.class.cpp                                    :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/17 13:49:28 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/17 13:49:29 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Fixed.Class.hpp"

const int Fixed::_nFractionalBits = 8;

Fixed::Fixed(void) : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
	return;
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
};

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

int		Fixed::getRawBits( void ) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = src.getRawBits();
	return *this;
}
