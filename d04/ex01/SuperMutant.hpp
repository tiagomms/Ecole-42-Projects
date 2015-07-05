// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   SuperMutant.hpp                                        :+:      :+:
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

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy 
{

private:


public:
	SuperMutant(); //Canonical
	SuperMutant(SuperMutant const & src); //Canonical
	SuperMutant & operator=(SuperMutant const & src); // Canonical
	virtual ~SuperMutant(); //Canonical
	virtual void takeDamage(int);
};

#endif