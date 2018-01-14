// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Pony.class.cpp                                     :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 12:02:00 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 12:02:40 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.class.hpp"

int Pony::_nbPonies = 0;
int	Pony::_nbLegsFromFactory = 4;

Pony::Pony() : _nom("Bond"), _prenom("Default")
{
	this->_nbLegs = Pony::_nbLegsFromFactory;
	Pony::_nbPonies += 1;
	Pony::getPonyFullNom();
	std::cout << " was created" << std::endl;	
	return;
}

Pony::Pony(std::string nom, std::string prenom) : _nom(nom), _prenom(prenom)
{
	this->_nbLegs = Pony::_nbLegsFromFactory;	
	Pony::_nbPonies += 1;
	Pony::getPonyFullNom();
	std::cout << " was created" << std::endl;
	return;
}

Pony::~Pony()
{
	Pony::getPonyFullNom();
	std::cout << " went to be sold as Bolognaise\n" << std::endl;
	return;
}

void	Pony::getPonyFullNom( void )
{
	std::cout << "My name is " << this->_nom << ",";
	std::cout << this->_prenom << " " << this->_nom;
}

void	Pony::setnbLegsFromFactory( int new_nbr )
{
	Pony::_nbLegsFromFactory = new_nbr;
	std::cout << "Change in production line! Now " << Pony::_nbLegsFromFactory 
	<< " legs!\n";
}

void	Pony::getnbLegsFromFactory( void )
{
	std::cout << "Ponies being printed with " << Pony::_nbLegsFromFactory 
	<< " legs.\n";
}

void	Pony::getnbLegsOfThePony( void )
{
	std::cout << "Pony: " << this->_nom << ", " << this->_prenom 
	<< " - nbLegs: " << this->_nbLegs << std::endl;
}

void	Pony::getPonyAmputated (void)//byRef & byPtr
{
	this->_nbLegs -= 1;
	std::cout << "Less one ham in " << this->_nom << ", " << this->_prenom 
	<< "!\n";
}

void	Pony::getPonyNewBionicLeg (void)//byRef & byPtr
{
	this->_nbLegs += 1;
	std::cout << "More one Bionic ham added in " << this->_nom << ", " 
	<< this->_prenom  << "!\n";
}



void	ponyOnTheHeap ( void )
{
	Pony *manufactured_pony = new Pony("Bond", "Pony");

	manufactured_pony->getPonyNewBionicLeg();
	manufactured_pony->getnbLegsOfThePony();
	delete manufactured_pony;
}

void	ponyOnTheStack ( void )
{
	Pony industrial_pony;

	industrial_pony.getPonyAmputated();
	industrial_pony.getnbLegsOfThePony();	
}

