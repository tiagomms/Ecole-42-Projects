// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   EndLoop.hpp                                           :+:      :+:
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

#ifndef ENDLOOP_HPP
# define ENDLOOP_HPP

#include "IMindOpen.hpp"

class EndLoop : public IMindOpen {

public:
	EndLoop(); //Canonical	
	EndLoop(EndLoop const & src);
	EndLoop & operator=(EndLoop const & src);
	virtual ~EndLoop();

	virtual bool 	execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it);


private:


};

#endif