#ifndef ROBO_CLEANER_GUI_ROBOCLEANERDEFINES_H_
#define ROBO_CLEANER_GUI_ROBOCLEANERDEFINES_H_

//System headers
#include <cstdint>

//Other libraries headers
#include "robo_common/defines/RoboCommonDefines.h"

//Own components headers

//Forward declarations

struct MoveProgress {
  MoveProgress() {
    reset();
  }

  void reset() {
    outcome = MoveOutcome::SUCCESS;
    progress = 0;
    processedFieldMarker = RoboCommonDefines::UNKNOWN_FIELD_MARKER;
    approachingFieldMarker = RoboCommonDefines::UNKNOWN_FIELD_MARKER;
    hasMoveFinished = false;
    hasEnergyForMovement = true;
  }

  MoveOutcome outcome;
  int32_t progress;
  uint8_t processedFieldMarker = RoboCommonDefines::UNKNOWN_FIELD_MARKER;
  uint8_t approachingFieldMarker = RoboCommonDefines::UNKNOWN_FIELD_MARKER;
  bool hasMoveFinished;
  bool hasEnergyForMovement;
};

#endif /* ROBO_CLEANER_GUI_ROBOCLEANERDEFINES_H_ */
