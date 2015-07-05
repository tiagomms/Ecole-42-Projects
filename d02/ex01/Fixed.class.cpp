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

const int Fixed::_BITS = 8;

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
	this->_value = src._value;
	return *this;
}

Fixed::Fixed( int const integer) : _value(integer << Fixed::_BITS)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed( float const full_float)
{
	float	temp;

	temp = full_float;
	for (int i = 0; i < Fixed::_BITS ; i++)
	{
		temp *= 2; 
	}
	this->_value = roundf(temp);
	std::cout << "Float constructor called" << std::endl;
	return;
}

float	Fixed::toFloat (void) const
{
	float 	result;

	result = this->_value;
	for (int i = 0; i < Fixed::_BITS ; i++)
	{
		result /= 2; 
	}
	return result;
}

int		Fixed::toInt (void) const
{
	return (this->_value >> Fixed::_BITS);
}

std::ostream &	operator<<( std::ostream & o, Fixed const &representation)
{
	o << representation.toFloat();
	return (o);
}