// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTime.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:37:12 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 13:56:37 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "DateTime.hpp"

std::string const DateTime::_title = "Date and Time";

DateTime::DateTime( void )
{
	return;
}

DateTime::DateTime( DateTime const &instance )
{
	*this = instance;
}

DateTime& DateTime::operator=( DateTime const &rhs )
{
	(void)rhs;
	return *this;
}

DateTime::~DateTime( void )
{
	return;
}

std::string const & DateTime::getDateTime() const
{
	return this->_date;
}

std::string const & DateTime::getTitle() const
{
	return this->_title;
}

void	DateTime::execute( void )
{
	time_t now;
	//title of the Module

	now = time(0);
	this->_date = ctime(&now);

//	std::cout << "Date and Time: " << this->_date << std::endl;
}



/*

*/
