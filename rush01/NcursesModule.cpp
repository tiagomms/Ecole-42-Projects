// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NcursesModule.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 19:30:50 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 18:36:09 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NcursesModule.hpp"


NcursesModule::NcursesModule( void )
{

}

NcursesModule::NcursesModule( int width, int height, int startx, int starty,
	IMonitorModule *mod) :
	_width( width ), _height( height ), _startx( startx ), _starty( starty ),
	_mod( mod )
{
/*
	RAM	*R = dynamic_cast<RAM *>(mod);
	if (R != NULL)
	{
		display(R);
		return ;
	}
	OSInfo			*O = dynamic_cast<OSInfo *>(mod);
	if (O != NULL)
	{
		display(O);
		return ;
	}
	Network			*N = dynamic_cast<Network *>(mod);
	if (N != NULL)
	{
		display(N);
		return ;
	}
	DateTime		*D = dynamic_cast<DateTime *>(mod);
	if (D != NULL)
	{
		display(D);
		return ;
	}
	HostUserName	*H = dynamic_cast<HostUserName *>(mod);
	if (H != NULL)
	{
		display(H);
		return ;
	}
	CPU				*C = dynamic_cast<CPU *>(mod);
	if (C != NULL)
	{
		display(C);
		return ;
	}
*/
//	display();
	this->refresh();
}
/*
NcursesModule::NcursesModule( NcursesModule const &instance )
{

}

NcursesModule& NcursesModule::operator=( NcursesModule const &rhs )
{

}
*/
NcursesModule::~NcursesModule( void )
{
	
}

void    NcursesModule::refresh( void )
{
//this->_mod
	RAM	*R = dynamic_cast<RAM *>(this->_mod);
	if (R != NULL)
	{
		display(R);
		return ;
	}
	OSInfo			*O = dynamic_cast<OSInfo *>(this->_mod);
	if (O != NULL)
	{
		display(O);
		return ;
	}
	Network			*N = dynamic_cast<Network *>(this->_mod);
	if (N != NULL)
	{
		display(N);
		return ;
	}
	DateTime		*D = dynamic_cast<DateTime *>(this->_mod);
	if (D != NULL)
	{
		display(D);
		return ;
	}
	HostUserName	*H = dynamic_cast<HostUserName *>(this->_mod);
	if (H != NULL)
	{
		display(H);
		return ;
	}
	CPU				*C = dynamic_cast<CPU *>(this->_mod);
	if (C != NULL)
	{
		display(C);
		return ;
	}
}

// ************************************************************************** //
// *****************************DISPLAY FUNCTIONS**************************** //
// ************************************************************************** //

void	NcursesModule::display( RAM *m )
{
	WINDOW	*local_win;
	float	percentage_mem_free;
	float	percentage_mem_used;

	percentage_mem_free = static_cast<float>(m->getMemFree()) / m->getMemTotal();
	percentage_mem_used = static_cast<float>(m->getMemUsed()) / m->getMemTotal();

	m->execute();
	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 -
			  sizeof(m->getTitle().c_str()), m->getTitle().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 - 1, 3, "Total memory: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 - 1, 17, "%llu", m->getMemTotal() >> 20);

	int		len;
	int		i;

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "Memory used: ");
	wattron(local_win, COLOR_PAIR(3));
	len = (this->_width - 16) * percentage_mem_used;
	for ( i = 0; i < len; ++i )
		mvwprintw(local_win, this->_height / 2, 16 + i, "|");
//	mvwprintw(local_win, this->_height / 2, 16, "%llu", m->getMemUsed());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 1, 3, "Memory free: ");
	wattron(local_win, COLOR_PAIR(3));
	len = (this->_width - 16) * percentage_mem_free;
	for ( i = 0; i < len; ++i )
		mvwprintw(local_win, this->_height / 2 + 1, 16 + i, "|");
//	mvwprintw(local_win, this->_height / 2 + 1, 16, "%llu", m->getMemFree());

	wrefresh(local_win);
}

void	NcursesModule::display( OSInfo *m )
{
	WINDOW	*local_win;

	m->execute();
	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 -
			  sizeof(m->getTitle().c_str()), m->getTitle().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 - 1, 3, "System name: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 - 1, 16, m->getSysname().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "Release: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2, 12, m->getRelease().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 1, 3, "Machine: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 + 1, 12, m->getMachine().c_str());

	wrefresh(local_win);
}

void	NcursesModule::display( Network *m )
{
	WINDOW	*local_win;

	m->execute();
	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 -
			  sizeof(m->getTitle().c_str()), m->getTitle().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "total inbyte: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2, 17, "%Lu", m->getTotalIBytes());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 1, 3, "total outbyte: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 + 1, 18, "%Lu", m->getTotalOBytes());

	wrefresh(local_win);
}

void	NcursesModule::display( DateTime *m )
{
	WINDOW	*local_win;

	m->execute();
	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 -
			  sizeof(m->getTitle().c_str()), m->getTitle().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "Date and time: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2, 18, m->getDateTime().c_str());

	wrefresh(local_win);
}

void	NcursesModule::display( HostUserName *m )
{
	WINDOW	*local_win;

	m->execute();
	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 -
			  sizeof(m->getTitle().c_str()), m->getTitle().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "Host name: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2, 14, m->getHostName().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 1, 3, "User name: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 + 1, 14, m->getUserName().c_str());

	wrefresh(local_win);
}

void	NcursesModule::display( CPU *m )
{
	WINDOW	*local_win;

	m->execute();
	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters
	nodelay(local_win, true);

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 -
			  sizeof(m->getTitle().c_str()), m->getTitle().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 - 2, 3, "Model: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 - 2, 10, m->getModel().c_str());

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 - 1, 3, "Number of cores: ");
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 - 1, 20, "%d", m->getNbrCores());

	int		len;
	int		i;

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "Percentage of CPU idle: ");
	wattron(local_win, COLOR_PAIR(3));
	len = (this->_width - 27) * m->getPCPUIdle();
	for ( i = 0; i < len; ++i )
		mvwprintw(local_win, this->_height / 2, 27 + i, "|");
//	mvwprintw(local_win, this->_height / 2, 27, "%.2f %%", m->getPCPUIdle() * 100);

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 1, 3, "Percentage of CPU system: ");
	wattron(local_win, COLOR_PAIR(3));
	len = (this->_width - 29) * m->getPCPUSys();
	for ( i = 0; i < len; ++i )
		mvwprintw(local_win, this->_height / 2 + 1, 29 + i, "|");
//	mvwprintw(local_win, this->_height / 2 + 1, 29, "%.2f %%", m->getPCPUSys() * 100);

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 2, 3, "Percentage of CPU user: ");
	wattron(local_win, COLOR_PAIR(3));
	len = (this->_width - 27) * m->getPCPUUser();
	for ( i = 0; i < len; ++i )
		mvwprintw(local_win, this->_height / 2 + 2, 27 + i, "|");
//	mvwprintw(local_win, this->_height / 2 + 2, 27, "%.2f %%", m->getPCPUUser() * 100);

	wrefresh(local_win);
}
///*
void	NcursesModule::display( void )
{
	WINDOW	*local_win;
	char	title[] = "title";
	char	data_type1[] = "data_type1";
	char	data1[] = "data1";
	char	data_type2[] = "data_type2";
	char	data2[] = "data2";
	char	data_type3[] = "data_type3";
	char	data3[] = "data3";

	local_win = newwin(this->_height, this->_width, this->_starty, this->_startx);
	box(local_win, 0 , 0);// 0, 0 gives default characters

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(local_win, COLOR_PAIR(1));
	mvwprintw(local_win, 1, this->_width / 2 - sizeof(title) / 2, title);

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 - 1, 3, "%s: ", data_type1);
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 - 1, 3 + sizeof(data_type1) + 1, data1);

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2, 3, "%s: ", data_type2);
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2, 3 + sizeof(data_type2) + 1, data2);

	wattron(local_win, COLOR_PAIR(2));
	mvwprintw(local_win, this->_height / 2 + 1, 3, "%s: ", data_type3);
	wattron(local_win, COLOR_PAIR(3));
	mvwprintw(local_win, this->_height / 2 + 1, 3 + sizeof(data_type3) + 1, data3);

	wrefresh(local_win);
}
//*/
