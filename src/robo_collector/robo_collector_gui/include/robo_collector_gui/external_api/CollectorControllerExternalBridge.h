#ifndef ROBO_COLLECTOR_GUI_COLLECTORCONTROLLEREXTERNALBRIDGE_H_
#define ROBO_COLLECTOR_GUI_COLLECTORCONTROLLEREXTERNALBRIDGE_H_

//System headers

//Other libraries headers
#include <rclcpp/node.hpp>
#include <std_msgs/msg/empty.hpp>
#include <std_msgs/msg/string.hpp>
#include "robo_collector_interfaces/msg/user_authenticate.hpp"
#include "robo_collector_interfaces/msg/robot_move_type.hpp"
#include "robo_collector_common/defines/RoboCollectorFunctionalDefines.h"
#include "game_engine/defines/ActionEventDefines.h"
#include "utils/ErrorCode.h"

//Own components headers

//Forward declarations

struct CollectorControllerExternalBridgeOutInterface {
  InvokeActionEventCb invokeActionEventCb;
  MoveButtonClickCb moveButtonClickCb;
  ToggleHelpPageCb toggleHelpPageCb;
  ToggleDebugInfoCb toggleDebugInfoCb;
  SetDebugMsgCb setDebugMsgCb;
  SetUserDataCb setUserDataCb;
};

class CollectorControllerExternalBridge: public rclcpp::Node {
public:
  CollectorControllerExternalBridge();

  ErrorCode init(
      const CollectorControllerExternalBridgeOutInterface &interface);

  void publishEnablePlayerInput();

  void publishShutdownController();

private:
  using Empty = std_msgs::msg::Empty;
  using String = std_msgs::msg::String;
  using UserAuthenticate = robo_collector_interfaces::msg::UserAuthenticate;
  using RobotMoveType = robo_collector_interfaces::msg::RobotMoveType;

  enum class ControllerStatus {
    IDLE, ACTIVE, SHUTTING_DOWN
  };

  ErrorCode initOutInterface(
      const CollectorControllerExternalBridgeOutInterface &outInterface);
  ErrorCode initCommunication();

  void onUserAuthenticateMsg(const UserAuthenticate::SharedPtr msg);
  void onMoveMsg(const RobotMoveType::SharedPtr msg);
  void onToggleHelpPageMsg(const Empty::SharedPtr msg);
  void onToggleDebugInfoMsg(const Empty::SharedPtr msg);
  void onDebugMsg(const String::SharedPtr msg);

  CollectorControllerExternalBridgeOutInterface _outInterface;

  rclcpp::Subscription<UserAuthenticate>::SharedPtr _userAuthenticateSubscriber;
  rclcpp::Subscription<RobotMoveType>::SharedPtr _playerActSubscriber;
  rclcpp::Subscription<Empty>::SharedPtr _toggleHelpPageSubscriber;
  rclcpp::Subscription<Empty>::SharedPtr _toggleDebugInfoSubscriber;
  rclcpp::Subscription<String>::SharedPtr _setDebugMsgSubscriber;

  rclcpp::Publisher<Empty>::SharedPtr _playerEnableInputPublisher;
  rclcpp::Publisher<Empty>::SharedPtr _shutdownControllerPublisher;

  //Create different callbacks groups for publishers and subscribers
  //so they can be executed in parallel
  const rclcpp::CallbackGroup::SharedPtr _subscriberCallbackGroup =
      create_callback_group(rclcpp::CallbackGroupType::Reentrant);
  const rclcpp::CallbackGroup::SharedPtr _publishersCallbackGroup =
      create_callback_group(rclcpp::CallbackGroupType::Reentrant);

  ControllerStatus _controllerStatus = ControllerStatus::IDLE;
};

#endif /* ROBO_COLLECTOR_GUI_COLLECTORCONTROLLEREXTERNALBRIDGE_H_ */
