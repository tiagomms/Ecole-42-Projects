// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   PtrBackward.hpp                                           :+:      :+:
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

#ifndef PTRBACKWARD_HPP
# define PTRBACKWARD_HPP

#include "IMindOpen.hpp"

class PtrBackward : public IMindOpen {

public:
	PtrBackward(); //Canonical	
	PtrBackward(PtrBackward const & src);
	PtrBackward & operator=(PtrBackward const & src);
	virtual ~PtrBackward();

	virtual bool 	execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it);


private:


};

#endif