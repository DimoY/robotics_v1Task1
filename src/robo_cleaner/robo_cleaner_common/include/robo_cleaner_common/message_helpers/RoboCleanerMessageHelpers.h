#ifndef ROBO_CLEANER_COMMON_ROBOCLEANERMESSAGEHELPERS_H_
#define ROBO_CLEANER_COMMON_ROBOCLEANERMESSAGEHELPERS_H_

//System headers

//Other libraries headers
#include "robo_common/defines/RoboCommonDefines.h"

//Own components headers

//Forward declarations

int8_t getMoveTypeField(MoveType moveType);
MoveType getMoveType(int8_t moveType);

int32_t getRobotDirectionField(Direction dir);
Direction getRobotDirection(int32_t dir);

#endif /* ROBO_CLEANER_COMMON_ROBOCLEANERMESSAGEHELPERS_H_ */
