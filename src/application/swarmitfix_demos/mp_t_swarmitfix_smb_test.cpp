/*!
 * @file mp_t_swarmitfix_smb_test.cpp
 *
 * @date Jan 17, 2012
 * @author tkornuta
 */

#include "mp_t_swarmitfix_smb_test.h"

namespace mrrocpp {
namespace mp {
namespace task {

task* return_created_mp_task(lib::configurator &_config)
{
	return new swarmitfix_smb_test(_config);
}

swarmitfix_smb_test::swarmitfix_smb_test(lib::configurator &config_) :
		swarmitfix_demo_base(config_)
{
}

void swarmitfix_smb_test::create_robots()
{
	// Activate SMB robot (depending on the configuration settings).
	ACTIVATE_MP_ROBOT(smb1);
}


void swarmitfix_smb_test::main_task_algorithm(void)
{
	int mode = config.value <int> ("mode");
	int delay = config.value <int> ("delay");
	int rotation = config.value <int> ("rotation");

	// Pull out all legs.
	move_smb_legs(lib::smb::OUT, lib::smb::OUT, lib::smb::OUT);
	// Wait for given time.
	wait_ms(delay);

	// Work depending on the mode.
	switch (mode){
		default:
			// Set mode "all out and in" as default.
		case 0:
			while (true) {
				// Legs in and out.
				move_smb_legs(lib::smb::IN, lib::smb::IN, lib::smb::IN);
				wait_ms(delay);
				move_smb_legs(lib::smb::OUT, lib::smb::OUT, lib::smb::OUT);
				wait_ms(delay);
			}
			break;
		case 1:
			while (true) {
				// One leg in and out after another.
				// Pull in first leg.
				move_smb_legs(lib::smb::IN, lib::smb::OUT, lib::smb::OUT);
				wait_ms(delay);
				move_smb_legs(lib::smb::OUT, lib::smb::OUT, lib::smb::OUT);
				wait_ms(delay);
				// Pull in second leg.
				move_smb_legs(lib::smb::OUT, lib::smb::IN, lib::smb::OUT);
				wait_ms(delay);
				move_smb_legs(lib::smb::OUT, lib::smb::OUT, lib::smb::OUT);
				wait_ms(delay);
				// Pull in third leg.
				move_smb_legs(lib::smb::OUT, lib::smb::OUT, lib::smb::IN);
				wait_ms(delay);
				move_smb_legs(lib::smb::OUT, lib::smb::OUT, lib::smb::OUT);
				wait_ms(delay);
			}
			break;
		case 2:
			while (true) {
				// One leg in and out after another with rotation given by parameter.
				// Rotate around the first leg.
				rotate_smb(1, rotation);
				wait_ms(delay);
				// Rotate around the second leg.
				rotate_smb(2, rotation);
				wait_ms(delay);
				// Rotate around the third leg.
				rotate_smb(3, rotation);
				wait_ms(delay);
			}
			break;
	}

}

} /* namespace task */
} /* namespace mp */
} /* namespace mrrocpp */
