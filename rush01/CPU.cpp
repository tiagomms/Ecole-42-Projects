// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CPU.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: lperrigu <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/27 12:34:19 by lperrigu          #+#    #+#             //
//   Updated: 2015/06/28 15:25:50 by lperrigu         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "CPU.hpp"

std::string const CPU::_title = "CPU";

CPU::CPU( void ) : _previousTotalTicks(0) , 
                  _previousIdleTicks(0) , 
                _previousSysTicks(0) ,
               _previousUserTicks(0) 
{
  return;
}

CPU::CPU( CPU const &instance )
{
  *this = instance;
}

CPU& CPU::operator=( CPU const &rhs )
{
  (void)rhs;
  return *this;
}

CPU::~CPU( void )
{
  return;
}

std::string const & CPU::getTitle() const
{
  return this->_title;
}

void  CPU::execute( void )
{
  char    model_string[1024];
  size_t  len_model = sizeof(model_string);

  size_t  len_cores = sizeof(this->_nbrCores);
//  float   result;  

  //title of the Module 
  sysctlbyname("machdep.cpu.brand_string", &(model_string), &len_model, NULL, 0); //model_info
  sysctlbyname("machdep.cpu.core_count", &(this->_nbrCores), &len_cores, NULL, 0); //nbr of Cores info
  this->_model = std::string(model_string);
//  std::cout << "Model: " << this->_model << std::endl;
//  std::cout << "Number of cores: " << this->_nbrCores << std::endl;  

  getCPULoad();
//  std::cout << "Percentage of CPU usage: ";
//  if ((result = this->getCPULoad()) >= 0.0f)
//      std::cout << std::setprecision(2) << (result * 100) << '%' << std::endl; 

}

int					CPU::getNbrCores() const
{
	return (this->_nbrCores);
}

std::string const	&CPU::getModel() const
{
	return (this->_model);
}

float				CPU::getPCPUIdle() const
{
	return (this->_pcpuidle);
}

float				CPU::getPCPUSys() const
{
	return (this->_pcpusys);
}

float				CPU::getPCPUUser() const
{
	return (this->_pcpuuser);
}

//+++++++++++++++++++++++++++++++++//
//        Private Functions        //
//+++++++++++++++++++++++++++++++++//

// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.

/*

printf("Cumulative CPU load statistics\n");
printf(" User state ticks = %u\n", cpu_load_info.cpu_ticks[CPU_STATE_USER]);
printf(" System state ticks = %u\n", cpu_load_info.cpu_ticks[CPU_STATE_SYSTEM]);
printf(" Nice state ticks = %u\n", cpu_load_info.cpu_ticks[CPU_STATE_NICE]);
printf(" Idle state ticks = %u\n", cpu_load_info.cpu_ticks[CPU_STATE_IDLE]);
printf("\n");



*/


void                   CPU::getCPULoad( void )
{
   host_cpu_load_info_data_t    cpuinfo;
   mach_msg_type_number_t       count = HOST_CPU_LOAD_INFO_COUNT;
   void  *                      ptr_cpuinfo = & cpuinfo;
   unsigned long long           totalTicks;

   if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, 
          static_cast<host_info_t>(ptr_cpuinfo), &count) == KERN_SUCCESS)
   {
      unsigned long long idleTicks = cpuinfo.cpu_ticks[CPU_STATE_IDLE];
      unsigned long long niceTicks = cpuinfo.cpu_ticks[CPU_STATE_NICE];
      unsigned long long sysTicks = cpuinfo.cpu_ticks[CPU_STATE_SYSTEM];
      unsigned long long userTicks = cpuinfo.cpu_ticks[CPU_STATE_USER];
      totalTicks = idleTicks + niceTicks + sysTicks + userTicks;

      calculateCPULoad(idleTicks, sysTicks, userTicks, totalTicks);
    }

}


void CPU::calculateCPULoad( unsigned long long idleTicks, unsigned long long sysTicks, 
  unsigned long long userTicks, unsigned long long totalTicks )
{
  unsigned long long totalTicksSinceLastTime = totalTicks - this->_previousTotalTicks;
  unsigned long long idleTicksSinceLastTime  = idleTicks - this->_previousIdleTicks;
  unsigned long long sysTicksSinceLastTime  = sysTicks - this->_previousSysTicks;
  unsigned long long userTicksSinceLastTime  = userTicks - this->_previousUserTicks;

  float ret;
  //float idleTicksSinceLastTime = static_cast<float>(idleTicksSinceLastTime_long);
//  std::cout << std::fixed << std::setprecision(2);
  ret = static_cast<float>(idleTicksSinceLastTime)/totalTicksSinceLastTime;
  this->_pcpuidle = ret;
//  std::cout << "Percentage of CPU idle: " << (ret * 100) << '%' << std::endl;
  ret = static_cast<float>(sysTicksSinceLastTime)/totalTicksSinceLastTime;
  this->_pcpusys = ret;
//  std::cout << "Percentage of CPU sys: " << (ret * 100) << '%' << std::endl;
  ret = static_cast<float>(userTicksSinceLastTime)/totalTicksSinceLastTime;
  this->_pcpuuser = ret;
//  std::cout << "Percentage of CPU user: " << (ret * 100) << '%' << std::endl;  

  this->_previousTotalTicks = totalTicks;
  this->_previousIdleTicks  = idleTicks;
  this->_previousUserTicks  = userTicks;
  this->_previousSysTicks  = sysTicks;

//  return ret;
}




/*

CPU
Model, clock speed, number of cores, activity, ...

 sysctlbyname(const char *name, void *oldp, size_t *oldlenp, void *newp, 
 size_t newlen);

For example, the following retrieves the maximum number of processes allowed
in the system:

int maxproc;
size_t len = sizeof(maxproc);
sysctlbyname("kern.maxproc", &maxproc, &len, NULL, 0);



A) model: machdep.cpu.brand_string / machdep.cpu.model
B) clock speed: machdep.cpu.brand_string (in here)
C) The number of cores - machdep.cpu.core_count 
D) activity/usage - BELOW

 pass C casts into static/dynamic ones

---------------------------------------------------------------------------

#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.


float GetCPULoad()
{
   host_cpu_load_info_data_t cpuinfo;
   mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
   if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
   {
      unsigned long long totalTicks = 0;
      for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
      sysLoadPercentage = CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
   }
   else return -1.0f;
}

float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
  unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
  unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
  float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
  _previousTotalTicks = totalTicks;
  _previousIdleTicks  = idleTicks;
  return ret;
} 

*/
