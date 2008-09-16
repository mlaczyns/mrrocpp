/*
 * ecp_g_sleep.h
 *
 *Author: Tomasz Bem
 */

#ifndef ECP_G_SLEEP_H_
#define ECP_G_SLEEP_H_

#include <time.h>
#include "ecp/common/ecp_generator.h"

class ecp_sleep_generator : public ecp_generator
{
	private:
		double waittime;		//seconds to wait
		timespec sleeptime;		//structure for nanosleep funciton
		timespec acttime;
		timespec prevtime;
		timespec starttime;

	public:
		ecp_sleep_generator(ecp_task& _ecp_task, double=1);		//constructor
		bool first_step();		//first step generation
		bool next_step();			//next step generation
		int init_time(double=1);	//initialize time
};

#endif /* ECP_G_SLEEP_H_ */
