#include "PhysicObjectBallStaticTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PhysicObjectBallStaticTest);

void PhysicObjectBallStaticTest::setUp() {
    m_logger = new LoggerMock();
    m_ball = new PhysicObjectBallStatic(
        *m_logger, 
        2, 
        0.1, 
        LinearAlgebraVector(5, 10, 3));
}

void PhysicObjectBallStaticTest::tearDown() {
    delete m_ball;
    m_ball = 0;
    delete m_logger;
    m_logger = 0;
}

void PhysicObjectBallStaticTest::applyForce_noForce_notMoved() {
    m_ball->applyForce(LinearAlgebraVector(0, 0, 0), 0.5);

    auto position = m_ball->getPosition();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 10, 3), position, 1e-6));
}

void PhysicObjectBallStaticTest::applyForce_noForce_velocityNotChanged() {
    m_ball->applyForce(LinearAlgebraVector(0, 0, 0), 0.5);

    auto velocity = m_ball->getVelocity();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 0, 0), velocity, 1e-6));
}

void PhysicObjectBallStaticTest::applyForce_forceButNoTime_notMoved() {
    m_ball->applyForce(LinearAlgebraVector(0, 20, 0), 0);

    auto position = m_ball->getPosition();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 10, 3), position, 1e-6));
}

void PhysicObjectBallStaticTest::applyForce_forceButNoTime_velocityNotChanged() {
    m_ball->applyForce(LinearAlgebraVector(0, 20, 0), 0);

    auto velocity = m_ball->getVelocity();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 0, 0), velocity, 1e-6));
}

void PhysicObjectBallStaticTest::applyForce_force_notMoved() {
    m_ball->applyForce(LinearAlgebraVector(0, 20, 0), 5);

    auto position = m_ball->getPosition();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 10, 3), position, 1e-6));
}

void PhysicObjectBallStaticTest::applyForce_force_velocityNotChanged() {
    m_ball->applyForce(LinearAlgebraVector(0, 20, 0), 5);

    auto velocity = m_ball->getVelocity();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 0, 0), velocity, 1e-6));
}