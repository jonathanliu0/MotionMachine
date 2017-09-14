
var IDLE = {
  id: 0,
  master: {
    values: {
      
    },
    events: {
      
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_IDLE = 0;
var OFF = {
  id: 1,
  master: {
    values: {
      
    },
    events: {
      
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_OFF = 1;
var MOTIONMACHINE = {
  id: 2,
  master: {
    values: {
      
    },
    events: {
      goHome: function goHome() { manager.sendEvent(0, 2); },
      stairsUp: function stairsUp() { manager.sendEvent(1, 2); },
      stairsStop: function stairsStop() { manager.sendEvent(2, 2); },
      openDoor: function openDoor() { manager.sendEvent(3, 2); },
      closeDoor: function closeDoor() { manager.sendEvent(4, 2); },
      goUp: function goUp() { manager.sendEvent(5, 2); },
      goUpWithBall: function goUpWithBall() { manager.sendEvent(6, 2); }
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_MOTIONMACHINE = 2;

var STATES = {
  IDLE: IDLE,
  OFF: OFF,
  MOTIONMACHINE: MOTIONMACHINE
};
var manager = new Manager([IDLE, OFF, MOTIONMACHINE]);
