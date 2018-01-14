// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Network.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:25:31 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/27 12:25:56 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "IMonitorModule.hpp"

class Network : public IMonitorModule
{
public:
	Network( void );
	Network( Network const & );
	Network& operator=( Network const & );
	virtual ~Network( void );

	virtual void execute( void );
	virtual std::string const & 		getTitle() const;
	u_int64_t 							getTotalIBytes() const;
	u_int64_t 							getTotalOBytes() const;

private:
	u_int64_t _totalibytes;
	u_int64_t _totalobytes;
	static std::string const 	_title;	
};


#endif
