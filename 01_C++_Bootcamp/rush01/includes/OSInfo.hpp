// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OSInfo.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:22:38 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/27 12:23:00 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OSINFO_H
#define OSINFO_H

#include "IMonitorModule.hpp"

class OSInfo : public IMonitorModule
{
public:
	OSInfo( void );
	OSInfo( OSInfo const & );
	OSInfo& operator=( OSInfo const & );
	virtual ~OSInfo( void );

	virtual void				execute( void );	
	virtual std::string const & 		getTitle() const;
	std::string const & 		getSysname() const;
	std::string const & 		getRelease() const;
	std::string const & 		getMachine() const;
	


private:
	
	static std::string const 	_title;
	std::string 				_sysname;
	std::string 				_release;
	std::string 				_machine;

	
};


#endif
