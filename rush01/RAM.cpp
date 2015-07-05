// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RAM.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:38:50 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 13:38:29 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RAM.hpp"

std::string const RAM::_title = "RAM";

std::string const & RAM::getTitle() const
{
  return this->_title;
}

RAM::RAM( void )
{
  return;
}

RAM::RAM( RAM const &instance )
{
  *this = instance;
}

RAM& RAM::operator=( RAM const &rhs )
{
  (void)rhs;
  return *this;
}

RAM::~RAM( void )
{
  return;
}

long long RAM::getMemUsed() const
{
  return this->_memUsed;
}

long long RAM::getMemFree() const
{
  return this->_memFree;
}

long long RAM::getMemTotal() const
{
  return this->_memTotal;
}

// Returns the RAM currently in use, free, and total and then the percentage of them. 

//This execute it to GetSystemMemoryUsagePercentage()

/*
http://venom630.free.fr/pdf/OSXInternals.pdf
Chapter 6 - pages 14-16 (377-379), pages 19-21 (382-384)
*/

void RAM::execute()
{
   mach_port_t             host_port;
   mach_msg_type_number_t  host_size;  
   vm_size_t               pagesize;
   vm_statistics_data_t    vm_stat;

   float                   percentage_mem_used;
   float                   percentage_mem_free;   

   void   *                ptr_vm_stat = &vm_stat;   
   host_port = mach_host_self();
   host_size = sizeof(vm_stat) / sizeof(integer_t);  

   if (host_page_size(host_port, &pagesize) == KERN_SUCCESS &&
         host_statistics(host_port, HOST_VM_INFO, static_cast<host_info_t>(ptr_vm_stat), 
                        &host_size) == KERN_SUCCESS)
   {
      this->_memUsed = static_cast<long long>(vm_stat.active_count + vm_stat.inactive_count +  
                           vm_stat.wire_count) * static_cast<long long>(pagesize);
      this->_memFree = static_cast<long long>(vm_stat.free_count) * static_cast<long long>(pagesize);  
      this->_memTotal = this->_memUsed + this->_memFree;
      percentage_mem_free = static_cast<float>(this->_memFree) / this->_memTotal;
      percentage_mem_used = static_cast<float>(this->_memUsed) / this->_memTotal;
//      std::cout << "Total Memory (MB): " << (this->_memTotal >> 20) << std::endl;
//      std::cout << "Used Memory (MB): " << (this->_memUsed >> 20) << std::endl;
//      std::cout << "Free Memory (MB): " << (this->_memFree >> 20) << std::endl;
      //to GB (1024^3) = 2^30 <=> >> 30;
      //to MB (1024^2) = 2^20 <=> >> 20;
//	  std::cout << std::fixed << std::setprecision(2);
//      std::cout << "Percentage used Memory: " << percentage_mem_used * 100 << '%' << std::endl;      
//      std::cout << "Percentage Free Memory: " << percentage_mem_free * 100 << '%' << std::endl;
      //what do I want from here? --> GRAPH
   }
}
