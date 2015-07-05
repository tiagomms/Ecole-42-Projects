// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAM.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:24:29 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/27 12:24:54 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RAM_HPP
#define RAM_HPP

#include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
public:
	RAM( void );
	RAM( RAM const & );
	RAM& operator=( RAM const & );
	virtual ~RAM( void );

	virtual void				execute( void );
	virtual std::string const & 		getTitle() const;
	long long							getMemUsed() const;
	long long							getMemFree() const;	
	long long							getMemTotal() const;	

private:
	static std::string const 	_title;
	long long _memUsed;
	long long _memFree;
	long long _memTotal;

	
};

#endif
