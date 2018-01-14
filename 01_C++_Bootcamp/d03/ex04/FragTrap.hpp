// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   FragTrap.hpp                                       :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/18 10:15:47 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/18 10:15:48 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{

public:
	FragTrap(void); //Canonical
	~FragTrap(void); //Canonical
	FragTrap(FragTrap const & src); //Canonical
	FragTrap & operator=(FragTrap const & src); // Canonical

	FragTrap(std::string name);
	void vaulthunter_dot_exe(std::string const & target);

private:
	void donutHell(std::string const & target);
	void pingPong(std::string const & target);
	void faRT(std::string const & target);
	void ChuckNorrisRoundHouseKick(std::string const & target);
	void lick(std::string const & target);
	
};

#endif