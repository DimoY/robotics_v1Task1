#ifndef ROBO_COLLECTOR_COMMON_ROBOCOLLECTORFUNCTIONALDEFINES_H_
#define ROBO_COLLECTOR_COMMON_ROBOCOLLECTORFUNCTIONALDEFINES_H_

//System headers
#include <functional>

//Other libraries headers
#include "robo_common/defines/RoboCommonDefines.h"
#include "robo_common/layout/field/FieldPos.h"

//Own components headers

//Forward declarations

using MoveButtonClickCb = std::function<void(MoveType)>;
using SettingActivatedCb = std::function<void()>;
using HelpActivatedCb = std::function<void()>;
using EnablePlayerInputCb = std::function<void()>;

#endif /* ROBO_COLLECTOR_COMMON_ROBOCOLLECTORFUNCTIONALDEFINES_H_ */
