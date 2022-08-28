#ifndef ROBO_COLLECTOR_GUI_ROBOCOLLECTORGUIROS2PARAMPROVIDER_H_
#define ROBO_COLLECTOR_GUI_ROBOCOLLECTORGUIROS2PARAMPROVIDER_H_

//System headers

//Other libraries headers
#include <rclcpp/node.hpp>
#include "robo_collector_common/layout/controller/config/RoboCollectorUiControllerBaseConfig.h"
#include "ros2_game_engine/communicator/config/Ros2CommunicatorConfig.h"
#include "utils/drawing/Rectangle.h"

//Own components headers

//Forward declarations

struct RoboCollectorGuiRos2Params {
  Rectangle guiWindow;
  Ros2CommunicatorConfig ros2CommunicatorConfig;
  int32_t totalGameSeconds { };
  int32_t targetWinCoins { };
  LocalControllerMode localControrllerMode = LocalControllerMode::DISABLED;

  void print() const;
  void validate();
};

class RoboCollectorGuiRos2ParamProvider : public rclcpp::Node {
public:
  RoboCollectorGuiRos2ParamProvider();

  RoboCollectorGuiRos2Params getParams();

private:
  RoboCollectorGuiRos2Params _params;
};

#endif /* ROBO_COLLECTOR_GUI_ROBOCOLLECTORGUIROS2PARAMPROVIDER_H_ */
