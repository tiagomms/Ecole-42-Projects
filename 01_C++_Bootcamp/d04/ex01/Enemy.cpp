// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Enemy.cpp                                        :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 15:51:29 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 15:51:34 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

Enemy::Enemy() {}

Enemy::Enemy(Enemy const & src) {
	*this = src;
	return;
}

Enemy & Enemy::operator=(Enemy const & src)
{
	this->_type = src.getType();
	this->_hp = src.getHP();
	return *this;
}

Enemy::Enemy(int hp, std::string const & type) :
	_hp(hp), _type(type)
{
	return;
}

int		Enemy::getHP() const
{
	return this->_hp;
}

std::string Enemy::getType() const
{
	return this->_type;
}

void Enemy::takeDamage(int damage)
{
	if (damage >= 0)
		this->_hp -= damage;
}

Enemy::~Enemy()
{
	return;
}