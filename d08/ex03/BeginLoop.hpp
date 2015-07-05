// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   BeginLoop.hpp                                           :+:      :+:
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

#ifndef BEGINLOOP_HPP
# define BEGINLOOP_HPP

#include "IMindOpen.hpp"

class BeginLoop : public IMindOpen {

public:
	BeginLoop(); //Canonical	
	BeginLoop(BeginLoop const & src);
	BeginLoop & operator=(BeginLoop const & src);
	virtual ~BeginLoop();

	virtual bool 	execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it);


private:


};

#endif