// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PowerFist.hpp                                        :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 15:51:20 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 15:51:34 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon 
{

private:


public:
	PowerFist(); //Canonical
	PowerFist(PowerFist const & src); //Canonical
	PowerFist & operator=(PowerFist const & src); // Canonical
	virtual ~PowerFist(); //Canonical
	virtual void attack() const;

};

#endif