// ************************************************************************** //
//                                                                            //
//                                                        :::
//                                                        ::::::::   //
//   Brain.hpp                                          :+:      :+:
//   :+:   //
//                                                    +:+ +:+
//                                                    +:+     //
//   By: tsilva <tsilva@student.42.fr>              +#+  +:+
//   +#+        //
//                                                +#+#+#+#+#+
//                                                +#+           //
//   Created: 2015/06/16 17:16:18 by tsilva            #+#
//   #+#             //
//   Updated: 2015/06/16 17:16:18 by tsilva           ###   ########.fr       //
//   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include <sstream> //for std::stringstream 

class Brain {

public:
	Brain();
	~Brain();
	std::string		identify( void ) const;

};

#endif
