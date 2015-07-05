// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Increment.hpp                                           :+:      :+:
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

#ifndef INCREMENT_HPP
# define INCREMENT_HPP

#include "IMindOpen.hpp"

class Increment : public IMindOpen {

public:
	Increment(); //Canonical	
	Increment(Increment const & src);
	Increment & operator=(Increment const & src);
	virtual ~Increment();

	virtual bool 	execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it);


private:


};

#endif