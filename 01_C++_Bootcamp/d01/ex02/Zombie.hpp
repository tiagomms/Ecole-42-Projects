// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Zombie.hpp                                         :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 14:35:29 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 14:35:53 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {

public:
	std::string _name;
	std::string _type;

	Zombie();//
	Zombie( std::string );
	~Zombie();
	void announce (void) const;

private:

};



#endif