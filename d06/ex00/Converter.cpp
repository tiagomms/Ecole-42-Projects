// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Converter.cpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:05:44 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Converter.hpp"

void	Converter::printResults(std::string const & literal)
{
	int point;

	if (literal.find('.') != std::string::npos && literal.length() > 1)
	{
		point = literal.length() - literal.find('.') - 1;
		if (point == 0)
			point = 1;
		else if (point > 1 && literal.find('f') != std::string::npos)
			point--;
	}
	else
		point = 1;
	if (this->isInteger(literal))
	{
		this->_integer = getIntegerFromLiteralString(literal);
		this->convertIntToChar(this->_integer);
		std::cout << "int: "  << this->_integer << std::endl;
		std::cout << std::setprecision(point) << std::fixed;
		this->convertIntToFloat(this->_integer);
		this->convertIntToDouble(this->_integer);				
	}
	else if ((literal.find('.') != std::string::npos && literal.length() > 1 
		&& literal.find('f') == std::string::npos) 
		|| isDouble(literal))
	{
		this->_doubler = getDoubleFromLiteralString(literal);
		this->convertDoubleToChar(this->_doubler);
		this->convertDoubleToInt(this->_doubler);
		std::cout << std::setprecision(point) << std::fixed;
		this->convertDoubleToFloat(this->_doubler);	
		std::cout << "double: " << this->_doubler << std::endl;
	}
	else if (isChar(literal) && !(literal[0] >= 48 && literal[0] <= 57))
	{
		this->_character = getCharacterFromLiteralString(literal);
		std::cout << "char: ";	
		printCharacter(this->_character);
		this->convertCharToInt(this->_character);
		std::cout << std::setprecision(point) << std::fixed;
		this->convertCharToFloat(this->_character);
		this->convertCharToDouble(this->_character);		
	}
	else if (literal.length() > 1 && (literal.find('f') == literal.length() - 1 || 
		isFloat(literal) || !literal.compare("inff") || !literal.compare("-inff")))
	{
		this->_floater = atof(literal.c_str());
		this->convertFloatToChar(this->_floater);
		this->convertFloatToInt(this->_floater);
		std::cout << "float: ";
		std::cout << std::setprecision(point) << std::fixed;
		std::cout << this->_floater << "f" << std::endl; 
		this->convertFloatToDouble(this->_floater);	
	}
	else
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}

}

Converter::~Converter(void)
{
	return;
}




bool			intLimits(float & f)
{
	return (f <= std::numeric_limits<int>::max()
		&& f >= std::numeric_limits<int>::min());
}
bool			intLimits(double & d)
{
	return (d <= std::numeric_limits<int>::max()
		&& d >= std::numeric_limits<int>::min());
}

bool			floatLimits(double & d)
{
	return ((d <= std::numeric_limits<float>::max()
		&& d >= -std::numeric_limits<float>::max()) ||
		 d == std::numeric_limits<double>::infinity() || 
		 -d == std::numeric_limits<double>::infinity() || 
		(d != d));
}

bool			charLimits(int & i)
{
	return (i <= std::numeric_limits<char>::max()
		&& i >= std::numeric_limits<char>::min());
}

bool			charLimits(float & f)
{
	return (f <= std::numeric_limits<char>::max()
		&& f >= std::numeric_limits<char>::min());
}

bool			charLimits(double & d)
{
	return (d <= std::numeric_limits<char>::max()
		&& d >= std::numeric_limits<char>::min());
}

bool			charLimits(char & c)
{
	return (c <= std::numeric_limits<char>::max()
		&& c >= std::numeric_limits<char>::min());
}



void printCharacter(char &c)
{
	if (c < 0)
		std::cout << "impossible" << std::endl;
	else if ((c >= 0 && c <= 31) || c == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << c << "\'" << std::endl;
}

//++++++++++++++++++++++++++++++//
//		Private Functions		//			
//++++++++++++++++++++++++++++++//

Converter::Converter() 
{
	return;
}

Converter::Converter(Converter const & src)
{
	*this = src;
	return;
}

Converter & Converter::operator=(Converter const & src)
{
	this->_doubler = src._doubler;
	this->_floater = src._floater;
	this->_character = src._character;
	this->_integer = src._integer;

	return *this;
}





bool	Converter::isInteger(std::string const& str) {
	std::istringstream ssd(str);
    std::istringstream ssi(str);
    
    double d;
    ssd >> d;
    if (intLimits(d))
    {
    	int i;
    	ssi >> i;
    }
    return (ssi && (ssi >> std::ws).eof());
}

bool	Converter::isDouble(std::string const& str) {
    std::istringstream ss(str);
    {
        double d;
        ss >> d;
    }
    return (ss && (ss >> std::ws).eof());
}

bool	Converter::isFloat(std::string const& str) {
    std::istringstream ss(str);
    {
        float f;
        ss >> f;
    }
    return (ss && (ss >> std::ws).eof());
}

bool	Converter::isChar(std::string const& str) {
    std::istringstream ss(str);
    {
        char c;
        ss >> c;
    }
    return (ss && (ss >> std::ws).eof());
}


char	Converter::getCharacterFromLiteralString(std::string const & literal)
{
	std::istringstream ss(literal);

	char c;
	ss >> c;
	return c;
}

int		Converter::getIntegerFromLiteralString(std::string const & literal)
{
	std::istringstream ss(literal);

	int i;
	ss >> i;
	return i;
}

float	Converter::getFloatFromLiteralString(std::string const & literal)
{
	std::istringstream ss(literal);

	float f;
	ss >> f;
	return f;
}

double	Converter::getDoubleFromLiteralString(std::string const & literal)
{
	std::istringstream ss(literal);

	double d;
	ss >> d;
	return d;
}

//++++++++++++++++++++++++++++++++++//
//	For Exercise					//
//++++++++++++++++++++++++++++++++++//


void	Converter::convertCharToInt(char & c)
{
		this->_integer = static_cast<int>(c);
		std::cout << "int: " << this->_integer << std::endl;
}

void	Converter::convertCharToFloat(char & c)
{
		this->_floater = static_cast<float>(c);
		std::cout << std::showpoint;
		std::cout << "float: " << this->_floater << "f" << std::endl;
}

void	Converter::convertCharToDouble(char & c)
{
		this->_doubler = static_cast<double>(c);
		std::cout << std::showpoint;
		std::cout << "double: " << this->_doubler << std::endl;
}



void	Converter::convertIntToChar(int & i)
{
	std::cout << "char: ";
	if (charLimits(i))
	{
		this->_character = static_cast<char>(i);
		printCharacter(this->_character);
	}
	else
		std::cout << "impossible" << std::endl;
}

void	Converter::convertIntToFloat(int & i)
{
	this->_floater = static_cast<float>(i);
	std::cout << "float: " << this->_floater << "f" << std::endl;
}

void	Converter::convertIntToDouble(int & i)
{
	this->_doubler = static_cast<double>(i);
	std::cout << "double: " << this->_doubler << std::endl;
}



void	Converter::convertFloatToChar(float & f)
{
	std::cout << "char: ";

	if (charLimits(f))
	{
		this->_character = static_cast<char>(f);
		printCharacter(this->_character);
	}
	else
		std::cout << "impossible" << std::endl;
}

void	Converter::convertFloatToInt(float & f)
{
	std::cout << "int: ";
	if (intLimits(f))
	{
		this->_integer = static_cast<int>(f);
		std::cout << this->_integer << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void	Converter::convertFloatToDouble(float & f)
{
	this->_doubler = static_cast<double>(f);
	std::cout << "double: " << this->_doubler << std::endl;
}

void	Converter::convertDoubleToChar(double & d)
{
	std::cout << "char: ";
	if (charLimits(d))
	{
		this->_character = static_cast<double>(d);
		printCharacter(this->_character);
	}
	else
		std::cout << "impossible" << std::endl;
}

void	Converter::convertDoubleToInt(double & d)
{
	std::cout << "int: ";
	if (intLimits(d))
	{ 
		this->_integer = static_cast<double>(d);
		std::cout << this->_integer << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void	Converter::convertDoubleToFloat(double & d)
{
	std::cout << "float: ";
	if (floatLimits(d))
	{
		this->_floater = static_cast<double>(d);
		std::cout << this->_floater << "f" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}
