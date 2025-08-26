
#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

class ISensor {
public:
    virtual int read() = 0;
    virtual ~ISensor() {}
};

class StateMachine {
public:
    using StateFn = void (*)(StateMachine&, ISensor&);
    StateFn current;

    StateMachine();

    void step(ISensor& sensor);

    static void stateIdle(StateMachine& sm, ISensor& sensor);
    static void stateActive(StateMachine& sm, ISensor& sensor);
    static void stateError(StateMachine& sm, ISensor& sensor);
};

#endif
