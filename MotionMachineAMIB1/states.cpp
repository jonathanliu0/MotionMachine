#include "states.h"

static const StateInfo state_infos[3] = {
  {IDLE::setup, IDLE::enter, IDLE::exit, IDLE::loop, IDLE::event},
  {OFF::setup, OFF::enter, OFF::exit, OFF::loop, OFF::event},
  {MOTIONMACHINE::setup, MOTIONMACHINE::enter, MOTIONMACHINE::exit, MOTIONMACHINE::loop, MOTIONMACHINE::event}
};

static const WireValue wire_values[0] = {
  
};

MasterManager<State, 3, 0> manager(0x8e868773, state_infos, wire_values, 0);

namespace IDLE {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}
namespace OFF {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}
namespace MOTIONMACHINE {


void event(uint8_t ev) {
  switch (ev) {
  case 0:
    events::goHome();
    break;
  case 1:
    events::stairsUp();
    break;
  case 2:
    events::stairsStop();
    break;
  case 3:
    events::openDoor();
    break;
  case 4:
    events::closeDoor();
    break;
  case 5:
    events::goUp();
    break;
  case 6:
    events::goUpWithBall();
    break;
  default:
    break;
  }
}


}

