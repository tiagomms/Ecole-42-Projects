// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPU.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:24:03 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 15:16:49 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CPU_HPP
#define CPU_HPP

#include "IMonitorModule.hpp"

class CPU : public IMonitorModule
{
public:
	CPU( void );
	CPU( CPU const & );
	CPU& operator=( CPU const & );
	virtual ~CPU( void );
	
	virtual void					execute( void );
	void							getCPULoad( void );
	virtual std::string const & 	getTitle() const;
		int					 		getNbrCores() const;
	std::string const & 			getModel() const;
	float							getPCPUIdle() const;
	float							getPCPUSys() const;
	float							getPCPUUser() const;


private:
	
	void						calculateCPULoad( unsigned long long idleTicks,
								unsigned long long sysTicks ,
								unsigned long long userTicks ,
								unsigned long long totalTicks );

	unsigned long long			_previousTotalTicks;
	unsigned long long			_previousIdleTicks;
	unsigned long long			_previousSysTicks;
	unsigned long long			_previousUserTicks;

	static std::string const 	_title;
	int							_nbrCores;
	std::string					_model;
	float						_pcpuidle;
	float						_pcpusys;
	float						_pcpuuser;

};


#endif
