// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   NinjaTrap.hpp                                      :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/18 16:43:42 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/18 16:43:43 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class NinjaTrap : public virtual ClapTrap 
{

public:
	NinjaTrap(void); //Canonical
	~NinjaTrap(void); //Canonical
	NinjaTrap(NinjaTrap const & src); //Canonical
	NinjaTrap & operator=(NinjaTrap const & src); // Canonical

	NinjaTrap(std::string name);
	void ninjaShoebox(ClapTrap & target);

private:
	void ninjaBackFlipKick(ClapTrap & target);
	void ninjaSex(ClapTrap & target);
	void ninjaHattori(ClapTrap & target);
	void ninjaTheWayOut(ClapTrap & target);
	void ninjaShuriken(ClapTrap & target);	
};

#endif
