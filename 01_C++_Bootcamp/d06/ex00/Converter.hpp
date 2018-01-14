// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Detector.hpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:05:36 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DETECTOR_HPP
# define DETECTOR_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <iomanip>
#include <math.h>

class Converter {

public:	
	virtual ~Converter(); //Canonical
	Converter(); //Canonical
	void	printResults(std::string const & literal);


private:
	Converter(Converter const & src); //Canonical		
	Converter & operator=(Converter const & src); // Canonical



	bool	isInteger(std::string const & literal);
	bool	isDouble(std::string const & literal);
	bool	isFloat(std::string const & literal);
	bool	isChar(std::string const & literal);

	char	getCharacterFromLiteralString(std::string const & literal);
	int		getIntegerFromLiteralString(std::string const & literal);
	float	getFloatFromLiteralString(std::string const & literal);
	double	getDoubleFromLiteralString(std::string const & literal);

	void	convertCharToInt(char & c);
	void	convertCharToFloat(char & c);
	void	convertCharToDouble(char & c);

	void	convertIntToChar(int & i);
	void	convertIntToFloat(int & i);
	void	convertIntToDouble(int & i);

	void	convertFloatToChar(float & f);
	void	convertFloatToInt(float & f);
	void	convertFloatToDouble(float & f);

	void	convertDoubleToChar(double & d);
	void	convertDoubleToInt(double & d);
	void	convertDoubleToFloat(double & d);

	char	_character;
	int		_integer;
	float	_floater;
	double	_doubler;

};

bool			charLimits(char &f);
bool			charLimits(int & i);
bool			charLimits(float & f);
bool			charLimits(double & d);
bool			intLimits(float & f);
bool			intLimits(double & d);
bool			floatLimits(double & d);


void			printCharacter(char &c);

#endif
