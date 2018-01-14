// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Logger.cpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:19:40 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:19:41 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Logger.hpp"

Logger::Logger() : _filename("LogRecords") 
{
	return;
}

Logger::~Logger()
{
	return;
}

void			Logger::logToConsole(std::string name)
{
	std::cout << name;
}

void			Logger::logToFile(std::string name)
{
	std::ofstream outfile;

	outfile.open(this->_filename, std::ios_base::app);
	outfile << name;
}

std::string 	Logger::makeLogEntry(std::string const & message)
{
	time_t		now;
	struct tm	tstruct;
	char		buf[80];
	std::string		log;

	now = time(0);
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &tstruct);
	log = "[" + std::string(buf) + "] " + message + "\n";
	return log;
}

void			Logger::log(std::string const & dest, 
	std::string const & message)
{
	int choosen_action_pos;
	void (Logger::*function_Array[2])(std::string ) = {NULL};
	function_Array[0] = &Logger::logToConsole;
	function_Array[1] = &Logger::logToFile;
	std::string	actions[2] = { "logToConsole", "logToFile" };
	choosen_action_pos = 0;
	while (choosen_action_pos < 3)
	{
		if (dest == actions[choosen_action_pos])
			return (this->*function_Array[choosen_action_pos])(this->makeLogEntry(message));
		choosen_action_pos++;
	}
	std::cout << "ERROR - UNDEFINED DEST: " << dest << " with message... " 
	<< message << std::endl;
}
