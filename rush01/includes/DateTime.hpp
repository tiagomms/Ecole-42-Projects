// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DateTime.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:23:22 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/27 12:23:44 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DATETIME_HPP
#define DATETIME_HPP

#include "IMonitorModule.hpp"

class DateTime : public IMonitorModule
{
public:
	DateTime( void );
	DateTime( DateTime const & );
	DateTime& operator=( DateTime const & );
	virtual ~DateTime( void );

	virtual void		execute( void );	
	std::string const & getDateTime() const;
	virtual std::string const & getTitle() const;	

private:
	std::string 				_date;
	static std::string const 	_title;

};


#endif
