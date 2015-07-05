// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Human.hpp                                          :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:17:02 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:17:03 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

//const after the function declaration means that the function is not allowed 
//to change any class members. I.e. everything becomes read-only!!!

class Human {

public:

	Human();
	~Human();
	Brain const	&	getBrain( void ) const;
	std::string	 	identify( void ) const;


//Note to self: const Brain XXXX != Brain const XXXX
//reason is simple: the first one he tries to consider everything in Brain 
//constant! On the second the attribute is constant.
private:	
	Brain const _myBrain;

};

#endif