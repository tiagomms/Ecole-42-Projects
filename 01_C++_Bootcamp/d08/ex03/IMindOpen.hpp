// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   IMindOpen.hpp                                           :+:      :+:
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

#ifndef IMINDOPEN_HPP
# define IMINDOPEN_HPP

#include <iostream>
#include <deque>
#include <algorithm>
#include <fstream>      // std::ifstream

class IMindOpen {

public:
	virtual 		~IMindOpen() {};
	virtual bool	execute(bool in_parenthesis, char** p, std::deque<IMindOpen*> * deque, std::deque<IMindOpen*>::iterator * it) = 0;

};

#endif