
#include "state_machine.h"
#include <iostream>

StateMachine::StateMachine() : current(&StateMachine::stateIdle) {}

void StateMachine::step(ISensor& sensor) {
    current(*this, sensor);
}

void StateMachine::stateIdle(StateMachine& sm, ISensor& sensor) {
    std::cout << "State: Idle\n";
    if (sensor.read() > 50) {
        sm.current = &StateMachine::stateActive;
    }
}

void StateMachine::stateActive(StateMachine& sm, ISensor& sensor) {
    std::cout << "State: Active\n";
    if (sensor.read() < 20) {
        sm.current = &StateMachine::stateError;
    }
}

void StateMachine::stateError(StateMachine& sm, ISensor&) {
    std::cout << "State: Error!\n";
    sm.current = &StateMachine::stateIdle;
}
