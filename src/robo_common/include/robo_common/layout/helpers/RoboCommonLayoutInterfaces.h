#ifndef ROBO_COMMON_ROBOCOMMONLAYOUTINTERFACES_H_
#define ROBO_COMMON_ROBOCOMMONLAYOUTINTERFACES_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers
#include "robo_common/defines/RoboCommonFunctionalDefines.h"
#include "robo_common/layout/entities/robot/helpers/RobotActInterface.h"

//Forward declarations
class CollisionWatcher;

struct RoboCommonLayoutInterface {
  SetFieldDataMarkerCb setFieldDataMarkerCb;
  ResetFieldDataMarkerCb resetFieldDataMarkerCb;
  GetFieldDataCb getFieldDataCb;
  RobotActInterface playerRobotActInterface;
  GameLostCb gameLostCb;
  GameWonCb gameWonCb;
};

struct RoboCommonLayoutOutInterface {
  FinishRobotActCb finishRobotActCb;
  PlayerDamageCb playerDamageCb;
  CollisionWatcher *collisionWatcher = nullptr;
};

#endif /* ROBO_COMMON_ROBOCOMMONLAYOUTINTERFACES_H_ */
