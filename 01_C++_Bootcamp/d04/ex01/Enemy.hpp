// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Enemy.hpp                                        :+:      :+:
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

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{

private:


protected:
	int _hp;
	std::string _type;	
	Enemy(); //Canonical
	Enemy(Enemy const & src); //Canonical
	Enemy & operator=(Enemy const & src); // Canonical	

public:
	Enemy(int hp, std::string const & type);
	virtual ~Enemy(); //Canonical
	std::string virtual getType() const;
	int getHP() const;
	
	virtual void takeDamage(int);

};

#endif