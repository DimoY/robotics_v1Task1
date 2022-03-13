#ifndef ROBO_CLEANER_GUI_PANELS_PANELHANDLER_H_
#define ROBO_CLEANER_GUI_PANELS_PANELHANDLER_H_

//System headers

//Other libraries headers
#include "robo_common/layout/panels/TimePanel.h"
#include "robo_common/layout/panels/IndicatorPanel.h"
#include "robo_common/layout/panels/NumberCounterPanel.h"

//Own components headers
#include "robo_cleaner_gui/defines/RoboCleanerGuiFunctionalDefines.h"
#include "robo_cleaner_gui/layout/panels/config/PanelHandlerConfig.h"

//Forward declarations

struct PanelHandlerOutInterface {
  StartGameLostAnimCb startGameLostAnimCb;
  StartGameWonAnimCb startGameWonAnimCb;
  StartAchievementWonAnimCb startAchievementWonAnimCb;
  EnergyDepletedCb energyDepletedCb;
};

class PanelHandler {
public:
  ErrorCode init(const PanelHandlerConfig &cfg,
                 const PanelHandlerOutInterface &interface);
  void draw() const;
  void decreaseHealthIndicator(int32_t delta);
  void decreaseEnergyIndicator(int32_t delta);

private:
  NumberCounterPanel _tilePanel;
  NumberCounterPanel _rubbishPanel;
  IndicatorPanel _healthPanel;
  IndicatorPanel _energyPanel;
};

#endif /* ROBO_CLEANER_GUI_PANELS_PANELHANDLER_H_ */
