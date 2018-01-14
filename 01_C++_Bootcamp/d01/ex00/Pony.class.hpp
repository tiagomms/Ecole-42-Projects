// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Pony.class.hpp                                     :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 12:02:17 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 12:02:40 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PONY_CLASS_HPP
# define PONY_CLASS_HPP

# include <iostream>

class Pony {

public:
	Pony();
	Pony(std::string nom, std::string prenom);
	~Pony();

	void	getPonyFullNom( void );
	void	getPonyAmputated( void );
	void	getPonyNewBionicLeg( void );
	void	getnbLegsOfThePony( void );

	static void	getnbPonies( void );
	static void	getnbLegsFromFactory( void );
	static void	setnbLegsFromFactory( int new_nbr );


private:
	int			_nbLegs;
	std::string	_nom;
	std::string	_prenom;
	static int	_nbPonies;
	static int	_nbLegsFromFactory;

}; 

void ponyOnTheHeap ( void );
void ponyOnTheStack ( void );

#endif