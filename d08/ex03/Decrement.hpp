// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Decrement.hpp                                           :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/19 14:05:36 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/19 14:06:10 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DECREMENT_HPP
# define DECREMENT_HPP

#include "IMindOpen.hpp"

class Decrement : public IMindOpen {

public:
	Decrement(); //Canonical	
	Decrement(Decrement const & src);
	Decrement & operator=(Decrement const & src);
	virtual ~Decrement();

	virtual bool 	execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it);


private:


};

#endif