
#include "state_machine.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;

class MockSensor : public ISensor {
public:
    MOCK_METHOD(int, read, (), (override));
};

TEST(StateMachineTest, IdleToActiveTransition) {
    MockSensor sensor;
    StateMachine sm;

    EXPECT_CALL(sensor, read())
        .WillOnce(Return(60));

    sm.step(sensor);
    EXPECT_EQ(sm.current, &StateMachine::stateActive);
}

TEST(StateMachineTest, ActiveToErrorTransition) {
    MockSensor sensor;
    StateMachine sm;
    sm.current = &StateMachine::stateActive;

    EXPECT_CALL(sensor, read())
        .WillOnce(Return(10));

    sm.step(sensor);
    EXPECT_EQ(sm.current, &StateMachine::stateError);
}

TEST(StateMachineTest, ErrorToIdleTransition) {
    MockSensor sensor;
    StateMachine sm;
    sm.current = &StateMachine::stateError;

    sm.step(sensor);
    EXPECT_EQ(sm.current, &StateMachine::stateIdle);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
