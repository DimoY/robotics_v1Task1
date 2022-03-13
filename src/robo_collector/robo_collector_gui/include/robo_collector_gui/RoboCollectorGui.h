#ifndef ROBO_COLLECTOR_GUI_ROBOCOLLECTORGUI_H_
#define ROBO_COLLECTOR_GUI_ROBOCOLLECTORGUI_H_

//System headers
#include <cstdint>

//Other libraries headers
#include "ros2_game_engine/communicator/Ros2CommunicatorInterface.h"
#include "game_engine/Game.h"
#include "robo_common/helpers/CollisionWatcher.h"

//Own components headers
#include "robo_collector_gui/layout/RoboCollectorLayout.h"
#include "robo_collector_gui/helpers/TurnHelper.h"
#include "robo_collector_gui/external_api/CollectorControllerExternalBridge.h"

//Forward declarations
class InputEvent;

class RoboCollectorGui final : public Game {
public:
  friend class RoboCollectorGuiInitHelper;

  RoboCollectorGui(const Ros2CommunicatorInterface &communicatorOutInterface);

  ErrorCode init(const std::any &cfg) override;
  void deinit() override;

  void draw() const override;
  void handleEvent(const InputEvent &e) override;

  void process() override;

private:
  RoboCollectorLayout _layout;
  TurnHelper _turnHelper;
  CollisionWatcher _collisionWatcher;

  std::shared_ptr<CollectorControllerExternalBridge> _controllerExternalBridge;
  Ros2CommunicatorInterface _communicatorInterface;
};

#endif /* ROBO_COLLECTOR_GUI_ROBOCOLLECTORGUI_H_ */
