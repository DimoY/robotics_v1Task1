#ifndef ROBO_MINER_GUI_CRYSTAL_H_
#define ROBO_MINER_GUI_CRYSTAL_H_

//System headers
#include <cstdint>
#include <functional>

//Other libraries headers
#include "robo_common/defines/RoboCommonFunctionalDefines.h"
#include "manager_utils/input/ButtonBase.h"
#include "utils/ErrorCode.h"

//Own components headers
#include "robo_miner_gui/defines/RoboMinerGuiFunctionalDefines.h"

//Forward declarations
class InputEvent;

struct CrystalConfig {
  uint64_t rsrcId;
  FieldPos fieldPos;
  Point tileOffset;
  int32_t width = 0;
  int32_t height = 0;
  CrystalType type;
  CrystalClickedCb crystalClickCb;
  GetFieldDescriptionCb getFieldDescriptionCb;
};

class Crystal final : public ButtonBase {
public:
  ErrorCode init(const CrystalConfig& cfg);
  void handleEvent(const InputEvent& e) override;

private:
  void onLeave(const InputEvent& e) override;
  void onReturn(const InputEvent& e) override;

  FieldPos _fieldPos;
  CrystalClickedCb _crystalClickCb;
  GetFieldDescriptionCb _getFieldDescriptionCb;
};

#endif /* ROBO_MINER_GUI_CRYSTAL_H_ */
