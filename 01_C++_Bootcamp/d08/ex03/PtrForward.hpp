// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PtrForward.hpp                                           :+:      :+:
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

#ifndef PTRFORWARD_HPP
# define PTRFORWARD_HPP

#include "IMindOpen.hpp"

class PtrForward : public IMindOpen {

public:
	PtrForward(); //Canonical	
	PtrForward(PtrForward const & src);
	PtrForward & operator=(PtrForward const & src);
	virtual ~PtrForward();

	virtual bool 	execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it);


private:


};

#endif