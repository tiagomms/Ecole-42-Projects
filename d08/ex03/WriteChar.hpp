// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   WriteChar.hpp                                           :+:      :+:
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

#ifndef WRITECHAR_HPP
# define WRITECHAR_HPP

#include "IMindOpen.hpp"

class WriteChar : public IMindOpen {

public:
	WriteChar(); //Canonical	
	WriteChar(WriteChar const & src);
	WriteChar & operator=(WriteChar const & src);
	virtual ~WriteChar();

	virtual bool 	execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it);


private:


};

#endif