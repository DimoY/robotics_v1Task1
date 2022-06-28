#ifndef ROBO_COLLECTOR_GUI_ROBOCOLLECTORLAYOUT_H_
#define ROBO_COLLECTOR_GUI_ROBOCOLLECTORLAYOUT_H_

//System headers
#include <cstdint>
#include <array>

//Other libraries headers
#include "robo_common/layout/RoboCommonLayout.h"
#include "robo_collector_common/layout/controller/RoboCollectorUiController.h"

//Own components headers
#include "robo_collector_gui/layout/panels/PanelHandler.h"
#include "robo_collector_gui/layout/entities/coin/CoinHandler.h"

//Forward declarations
class InputEvent;
class RoboCollectorLayoutInitHelper;
struct RoboCollectorLayoutConfig;
struct RoboCollectorLayoutOutInterface;
struct RoboCollectorLayoutInterface;

class RoboCollectorLayout {
public:
  friend class RoboCollectorLayoutInitHelper;

  ErrorCode init(const RoboCollectorLayoutConfig &cfg,
                 const RoboCollectorLayoutOutInterface &outInterface,
                 RoboCollectorLayoutInterface& interface);
  void deinit();
  void draw() const;
  void handleEvent(const InputEvent &e);

  void process();

  void toggleHelpPage();

  void toggleDebugInfo();

private:
  void produceInterface(RoboCollectorLayoutInterface& interface);

  RoboCommonLayout _commonLayout;
  PanelHandler _panelHandler;
  CoinHandler _coinHandler;
  RoboCollectorUiController _controller;
  std::array<Robot, Defines::ENEMIES_CTN> _enemyRobots;
};

#endif /* ROBO_COLLECTOR_GUI_ROBOCOLLECTORLAYOUT_H_ */
