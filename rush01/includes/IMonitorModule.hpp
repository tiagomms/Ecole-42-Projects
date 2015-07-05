// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorModule.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:50:46 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/27 13:04:20 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP

#include <iostream>				//input/output streams and manipulations, casts
#include <iomanip>				//set precision for floats
#include <string>				//string manipulations
#include <stdio.h>				//fgets()
#include <stdlib.h>

#include <unistd.h>				//gethostname and getlogin
#include <time.h>				//date & time
#include <sys/utsname.h>		//get OS Info

#include <sys/sysctl.h>			//CPU, RAM, Network
#include <net/if.h>				//Network --> struct if_msghdr
#include <net/route.h>			//Network --> RTM_IFINFO2

#include <mach/mach.h>			//RAM -> calculate usage
#include <mach/mach_init.h>		//CPU -> calculate usage
#include <mach/mach_error.h> 	//CPU -> calculate usage
#include <mach/mach_host.h>		//CPU -> calculate usage
#include <mach/vm_map.h>		//CPU -> calculate usage

class IMonitorModule
{
public:
	virtual 		~IMonitorModule( void ) {};
	virtual void	execute( void ) = 0;
	virtual std::string const & getTitle() const = 0;

};

#endif
