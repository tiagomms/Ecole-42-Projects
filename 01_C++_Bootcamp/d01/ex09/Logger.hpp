// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Logger.hpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:19:46 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:19:47 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <fstream>
# include <string>

class Logger {

public:
	Logger();
	~Logger();
	void log(std::string const & dest, std::string const & message);

private:
	std::string _filename;
	void					logToConsole(std::string name);
	void					logToFile(std::string name);
	std::string 			makeLogEntry(std::string const & message);

};

#endif