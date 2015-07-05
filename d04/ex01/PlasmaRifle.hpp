// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PlasmaRifle.hpp                                        :+:      :+:
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

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon 
{

private:


public:
	PlasmaRifle(); //Canonical
	PlasmaRifle(PlasmaRifle const & src); //Canonical
	PlasmaRifle & operator=(PlasmaRifle const & src); // Canonical
	virtual ~PlasmaRifle(); //Canonical
	virtual void attack() const;

};

#endif