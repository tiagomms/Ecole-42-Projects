// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   ReadChar.hpp                                           :+:      :+:
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

#ifndef READCHAR_HPP
# define READCHAR_HPP

#include "IMindOpen.hpp"

class ReadChar : public IMindOpen {

public:
	ReadChar(); //Canonical	
	ReadChar(ReadChar const & src);
	ReadChar & operator=(ReadChar const & src);
	virtual ~ReadChar();

	virtual bool 	execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it);


private:


};

#endif