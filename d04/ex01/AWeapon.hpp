// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   AWeapon.hpp                                        :+:      :+:
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

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{

private:
	AWeapon(AWeapon const & src); //Canonical
	AWeapon & operator=(AWeapon const & src); // Canonical	

protected:
	std::string _name;
	int			_apcost;
	int			_damage;
	AWeapon(); //Canonical

public:
	AWeapon(std::string const & name, int apcost, int damage);
	virtual ~AWeapon(); //Canonical
	std::string virtual getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;

};

#endif