//Corresponding header
#include "robo_cleaner_gui/layout/RoboCleanerLayout.h"

//System headers

//Other libraries headers
#include "utils/ErrorCode.h"
#include "utils/Log.h"

//Own components headers
#include "robo_cleaner_gui/layout/helpers/RoboCleanerLayoutInterfaces.h"
#include "robo_cleaner_gui/layout/helpers/RoboCleanerLayoutInitHelper.h"

using namespace std::placeholders;

ErrorCode RoboCleanerLayout::init(
    const RoboCleanerLayoutConfig &cfg,
    const RoboCleanerLayoutOutInterface &outInterface,
    RoboCleanerLayoutInterface &interface) {
  if (ErrorCode::SUCCESS != RoboCleanerLayoutInitHelper::init(cfg, outInterface,
          interface.commonLayoutInterface, *this)) {
    LOGERR("Error, RoboCleanerLayoutInitHelper::init() failed");
    return ErrorCode::FAILURE;
  }

  return ErrorCode::SUCCESS;
}

void RoboCleanerLayout::deinit() {
  _commonLayout.deinit();
}

void RoboCleanerLayout::draw() const {
  _commonLayout.draw();
  _entityHandler.draw();
  _panelHandler.draw();
}

void RoboCleanerLayout::onEnergyDepleted() {
  LOGR("Energy depleted");
}

