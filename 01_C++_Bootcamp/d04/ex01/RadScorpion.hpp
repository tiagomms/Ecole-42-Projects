// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   RadScorpion.hpp                                        :+:      :+:
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

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy 
{

private:


public:
	RadScorpion(); //Canonical
	RadScorpion(RadScorpion const & src); //Canonical
	RadScorpion & operator=(RadScorpion const & src); // Canonical
	virtual ~RadScorpion(); //Canonical
	virtual void takeDamage(int);

};

#endif