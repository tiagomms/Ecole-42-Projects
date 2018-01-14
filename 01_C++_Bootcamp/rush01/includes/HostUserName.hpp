// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HostUserName.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:15:46 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/27 12:22:23 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HOSTUSERNAME_HPP
#define HOSTUSERNAME_HPP


#include "IMonitorModule.hpp"

class HostUserName : public IMonitorModule
{
public:
	HostUserName();
	HostUserName(HostUserName const &);
	HostUserName& operator=(HostUserName const &);
	virtual ~HostUserName();

	virtual void		execute( void );
	std::string const & getHostName() const;
	std::string const & getUserName() const;	
	virtual std::string const & getTitle() const;	

private:
	std::string 				_hostname;
	std::string 				_username;	
	static std::string const 	_title;
	
};

#endif
