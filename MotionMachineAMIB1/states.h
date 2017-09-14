#pragma once

#include <Manager.h>

namespace IDLE {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {

}
}

namespace OFF {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {

}
}

namespace MOTIONMACHINE {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {
void goHome();
void stairsUp();
void stairsStop();
void openDoor();
void closeDoor();
void goUp();
void goUpWithBall();
}
}



enum State {
  STATE_IDLE,
  STATE_OFF,
  STATE_MOTIONMACHINE
};

extern MasterManager<State, 3, 0> manager;
