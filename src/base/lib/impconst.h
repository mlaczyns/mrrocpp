/*!
 * @file impconst.h
 * @brief Fundamental types and constants used.
 *
 * @author Piotr Trojanek <piotr.trojanek@gmail.com>
 * @author Tomasz Winiarski <tomrobotics@gmail.com>
 *
 * @ingroup LIB
 */

#if !defined(_IMPCONST_H)
#define _IMPCONST_H

#include <string>
#include <stdint.h>

namespace mrrocpp {

}

using namespace mrrocpp;

namespace mrrocpp {
namespace lib {

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_TEXT 100 // MAC7
#define MAX_PROSODY 20 // MAC7
#define CONNECT_RETRY	200
#define CONNECT_DELAY	50

// ----------------------- PRZYDATNE STALE ---------------------------
typedef double frame_tab[3][4];

#define MP_SECTION "[mp]"
#define UI_SECTION "[ui]"

typedef std::string robot_name_t;
typedef std::string TRANSMITTER_t;

static const robot_name_t ROBOT_UNDEFINED = "ROBOT_UNDEFINED";

static const robot_name_t ROBOT_ELECTRON = "ROBOT_ELECTRON";
static const robot_name_t ROBOT_FESTIVAL = "ROBOT_FESTIVAL";
static const robot_name_t ROBOT_SPEECHRECOGNITION = "ROBOT_SPEECHRECOGNITION";

// Other robots in dedicated robot consts files

enum FORCE_SENSOR_ENUM
{
	FORCE_SENSOR_ATI3084, FORCE_SENSOR_ATI6284
};

#define MAX_SERVOS_NR 8

#define STEP              0.002  // Krok sterowania w [s]
// dla starej wersji sterowania
//#define FORCE_INERTIA 0.96
//#define TORQUE_INERTIA 0.98
//#define FORCE_RECIPROCAL_DAMPING -0.00025
//#define TORQUE_RECIPROCAL_DAMPING -0.005

// wartosci podstawowe dla sterowania silowego
#define FORCE_INERTIA 20
#define TORQUE_INERTIA 0.5
#define FORCE_RECIPROCAL_DAMPING 0.005
#define TORQUE_RECIPROCAL_DAMPING 0.1

#define ROBOT_TEST_MODE "robot_test_mode"

#define MAX_PRIORITY    50

// STALE PULSOW MP, ECP, READER

#define MP_START (_PULSE_CODE_MINAVAIL + 1)
#define MP_STOP (_PULSE_CODE_MINAVAIL + 2)
#define MP_PAUSE (_PULSE_CODE_MINAVAIL + 3)
#define MP_RESUME (_PULSE_CODE_MINAVAIL + 4)
#define MP_TRIGGER (_PULSE_CODE_MINAVAIL + 5)

#define MP_TO_ECP_COMMUNICATION_REQUEST (_PULSE_CODE_MINAVAIL + 6)

#define ECP_TRIGGER (_PULSE_CODE_MINAVAIL + 1)

#define READER_START (_PULSE_CODE_MINAVAIL + 1)
#define READER_STOP (_PULSE_CODE_MINAVAIL + 2)
#define READER_TRIGGER (_PULSE_CODE_MINAVAIL + 3)

#define ECP_WAIT_FOR_START (_PULSE_CODE_MINAVAIL + 2)
#define ECP_WAIT_FOR_STOP (_PULSE_CODE_MINAVAIL + 3)
#define ECP_WAIT_FOR_COMMAND (_PULSE_CODE_MINAVAIL + 4)
#define ECP_WAIT_FOR_NEXT_STATE (_PULSE_CODE_MINAVAIL + 5)

#define MP_2_ECP_NEXT_STATE_STRING_SIZE	100
#define MP_2_ECP_STRING_SIZE	300
#define ECP_2_MP_STRING_SIZE	300

#ifdef __cplusplus
}
#endif

} // namespace lib
} // namespace mrrocpp

#endif /* _IMPCONST_H */
