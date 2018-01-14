// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMonitorDisplay.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 19:14:07 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 13:19:25 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"

class RAM;
class OSInfo;
class Network;
class DateTime;
class HostUserName;
class CPU;

class IMonitorDisplay
{
public:
	virtual ~IMonitorDisplay() {};
	virtual void	display( void ) = 0;
	virtual void	display( OSInfo * ) = 0;
	virtual void	display( RAM * ) = 0;
	virtual void	display( Network * ) = 0;
	virtual void	display( DateTime * ) = 0;
	virtual void	display( HostUserName * ) = 0;
	virtual void	display( CPU * ) = 0;
	virtual void	refresh( void ) = 0;
//	virtual void	addModule

};

#endif
