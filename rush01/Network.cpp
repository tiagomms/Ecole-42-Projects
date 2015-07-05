// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Network.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:37:55 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 13:10:41 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Network.hpp"

std::string const Network::_title = "Network";

Network::Network( void ) : _totalibytes(0), _totalobytes(0)
{
  return;
}

Network::Network( Network const &instance )
{
  *this = instance;
}

Network& Network::operator=( Network const &rhs )
{
  (void)rhs;
  return *this;
}

Network::~Network( void )
{
  return;
}

std::string const & Network::getTitle() const
{
  return this->_title;
}

u_int64_t 			Network::getTotalIBytes() const
{
	return this->_totalibytes;
}

u_int64_t 			Network::getTotalOBytes() const
{
	return this->_totalobytes;
}

void	Network::execute( void )
{
	int mib[] =
		{
			CTL_NET,
			PF_ROUTE,
			0,
			0,
			NET_RT_IFLIST2,
			0
		};
	size_t len;
	if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0)
	{
//		std::cerr << "ERROR sysctl" << std::endl;
		exit(1);
	}

	char *buf = new char[ len ];
	if (sysctl(mib, 6, buf, &len, NULL, 0) < 0)
	{
//		std::cerr << "ERROR sysctl" << std::endl;
		exit(1);
	}
	char *lim = buf + len;
	char *next = NULL;

//	u_int64_t totalibytes = 0;
//	u_int64_t totalobytes = 0;
	this->_totalibytes = 0;
	this->_totalobytes = 0;

	for (next = buf; next < lim; )
	{
		struct if_msghdr *ifm = (struct if_msghdr *)next;
		next += ifm->ifm_msglen;
		if (ifm->ifm_type == RTM_IFINFO2) {
			struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;
//			totalibytes += if2m->ifm_data.ifi_ibytes;
//			totalobytes += if2m->ifm_data.ifi_obytes;
			this->_totalibytes += if2m->ifm_data.ifi_ibytes;
			this->_totalobytes += if2m->ifm_data.ifi_obytes;
		}
	}
	delete buf;
//	std::cout << "Total Input (kb): " << (this->_totalibytes >> 10) << std::endl;
//	std::cout << "Total Output (kb): " << (this->_totalobytes >> 10) << std::endl;
}
