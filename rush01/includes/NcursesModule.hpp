// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NcursesModule.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 19:21:54 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 14:11:45 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NCURSESMODULE_HPP
#define NCURSESMODULE_HPP

#include "IMonitorDisplay.hpp"
#include "RAM.hpp"
#include "OSInfo.hpp"
#include "Network.hpp"
#include "DateTime.hpp"
#include "HostUserName.hpp"
#include "CPU.hpp"

#include <ncurses.h>

class RAM;
class OSInfo;
class Network;
class DateTime;
class HostUserName;
class CPU;

class NcursesModule : public IMonitorDisplay
{
private:
	int				_width;
	int				_height;
	int				_startx;
	int				_starty;
	IMonitorModule	*_mod;

	NcursesModule( void );
	NcursesModule& operator=( NcursesModule const & );

public:
	virtual ~NcursesModule( void );
	NcursesModule( int width, int height, int startx, int starty,
				   IMonitorModule *mod );
	NcursesModule( NcursesModule const & );

	void	display( void );
	void	display( OSInfo * );
	void	display( RAM * );
	void	display( Network * );
	void	display( DateTime * );
	void	display( HostUserName * );
	void	display( CPU * );
	void	refresh( void );
};


#endif
