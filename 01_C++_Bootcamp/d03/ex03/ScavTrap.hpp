// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/18 13:49:19 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/18 13:49:19 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{

public:
	ScavTrap(void); //Canonical
	~ScavTrap(void); //Canonical
	ScavTrap(ScavTrap const & src); //Canonical
	ScavTrap & operator=(ScavTrap const & src); // Canonical

	ScavTrap(std::string name);
	void challengeNewcomer(std::string const & target);

private:
	void holdingPeaWithTongue(std::string const & target);
	void doTheFour(std::string const & target);
	void drinkingCompetition(std::string const & target);
	void trainKungFuryMoves(std::string const & target);
	void burpingCompetition(std::string const & target);	
};

#endif
