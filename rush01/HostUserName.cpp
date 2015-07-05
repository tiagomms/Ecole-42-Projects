// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HostUserName.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:17:14 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 14:02:07 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HostUserName.hpp"

std::string const HostUserName::_title = "Host and User Name";

HostUserName::HostUserName( void )
{
	return;
}

HostUserName::HostUserName( HostUserName const &instance )
{
	*this = instance;
}

HostUserName& HostUserName::operator=( HostUserName const &rhs )
{
	(void)rhs;
	return *this;
}

std::string const & HostUserName::getHostName() const
{
	return this->_hostname;
}

std::string const & HostUserName::getUserName() const
{
	return this->_username;
}

std::string const & HostUserName::getTitle() const
{
	return this->_title;
}

HostUserName::~HostUserName( void )
{
	return;
}

void	HostUserName::execute( void )
{
	char hostname[255];

	gethostname(hostname, sizeof(hostname));
	char * login = getlogin();

	this->_hostname = std::string(hostname);
	this->_username = std::string(login);
	this->_hostname.resize(this->_hostname.find('.'));
//	std::cout << "Hostname: " << this->_hostname << std::endl;
//	std::cout << "UserName: " << this->_username << std::endl;	
}
