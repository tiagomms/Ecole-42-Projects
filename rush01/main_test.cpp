// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main_test.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:38:50 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 20:28:37 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RAM.hpp"
#include "CPU.hpp"
#include "OSInfo.hpp"
#include "Network.hpp"
#include "DateTime.hpp"
#include "HostUserName.hpp"
#include "IMonitorModule.hpp"
#include "NcursesModule.hpp"
#include "SFMLDisplay.hpp"

#include <list>
#include <algorithm>

int kbhit(void)
{
	int ch = getch();

	if (ch != ERR) {
		ungetch(ch);
		return 1;
    }
	else
	{
		return 0;
	}
}

void	start_sfml()
{
	SFMLDisplay start;
	start.run();
}



void	start_ncurses()
{
	std::list<IMonitorDisplay *> modules;
	initscr();
	cbreak();
	keypad(stdscr, TRUE);

	refresh();
	modules.push_back(new NcursesModule( COLS / 2, LINES / 3, 0, 0, new RAM ) );
	modules.push_back(new NcursesModule( COLS / 2, LINES / 3,
										 COLS / 2, 0, new OSInfo ) );
	modules.push_back(new NcursesModule( COLS / 2, LINES / 3,
										 0, LINES / 3, new Network ) );
	modules.push_back(new NcursesModule( COLS / 2, LINES / 3,
										 COLS / 2, LINES / 3, new DateTime ) );
	modules.push_back(new NcursesModule( COLS / 2, LINES / 3,
										 0, (LINES / 3) * 2, new HostUserName ) );
	modules.push_back(new NcursesModule( COLS / 2, LINES / 3,
										 COLS / 2, (LINES / 3) * 2, new CPU ) );
	refresh();
	std::list<IMonitorDisplay*>::iterator it;
	std::list<IMonitorDisplay*>::iterator ite = modules.end();
	nodelay(stdscr, true);
	while (1)
	{
		if (kbhit() && getch() == 27)
		{
			endwin();
			exit(0);
		}
		for ( it = modules.begin(); it != ite; ++it)
			(*it)->refresh();
		sleep(1);
	}
}

int main()
{
	std::string display_type;
	int         ret;

	while (display_type != "1" && display_type != "2")
	{
		std::cout << "Press 1 to ncurses display, 2 to SFML display: ";
		ret = std::getline(std::cin, display_type);
		if (ret == 0)
			exit(0);
	}
	
	if (display_type == "1")
		start_ncurses();
	else if (display_type == "2")
 		start_sfml();
	else
	{
		//sfml stuff
		exit(0);
	}
	return 0;
}
