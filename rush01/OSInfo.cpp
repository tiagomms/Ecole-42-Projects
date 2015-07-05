// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSInfo.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:38:27 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 13:43:15 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OSInfo.hpp"

std::string const OSInfo::_title = "OS Info";

OSInfo::OSInfo( void )
{
	return;
}

OSInfo::OSInfo( OSInfo const &instance )
{
	*this = instance;
}

OSInfo& OSInfo::operator=( OSInfo const &rhs )
{
	(void)rhs;
	return *this;
}

OSInfo::~OSInfo( void )
{
	return;
}

std::string const & OSInfo::getTitle() const
{
  return this->_title;
}

std::string const & OSInfo::getSysname() const
{
	return this->_sysname;
}

std::string const & OSInfo::getRelease() const
{
	return this->_release;
}

std::string const & OSInfo::getMachine() const
{
	return this->_machine;
}


void	OSInfo::execute( void )
{
	struct utsname		system_info;
	
	uname(&system_info);
	
	this->_sysname = std::string(system_info.sysname);
	this->_machine = std::string(system_info.machine);
	this->_release = std::string(system_info.release);
//	std::cout << "Sysname: " << this->_sysname << std::endl;
//	std::cout << "Nodename: " << system_info.nodename << std::endl;
//	std::cout << "Release: " << this->_release << std::endl;
//	std::cout << "Version: " << system_info.version << std::endl;
//	std::cout << "Machine: " << this->_machine << std::endl;
}


/*

char  sysname[]  Name of this implementation of the operating system. 
char  nodename[] Name of this node within the communications 
                 network to which this node is attached, if any. 
char  release[]  Current release level of this implementation. 
char  version[]  Current version level of this release. 
char  machine[]  Name of the hardware type on which the system is running. 

*/
