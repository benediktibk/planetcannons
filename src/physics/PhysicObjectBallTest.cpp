#include "PhysicObjectBallTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(PhysicObjectBallTest);

void PhysicObjectBallTest::setUp() {
    m_logger = new LoggerMock();
    m_ballNotMoving = new PhysicObjectBall(
        *m_logger, 
        2, 
        0.1, 
        LinearAlgebraVector(5, 10, 3), 
        LinearAlgebraVector(0, 0, 0));
    m_ballMoving = new PhysicObjectBall(
        *m_logger, 
        2, 
        0.1, 
        LinearAlgebraVector(5, 10, 3), 
        LinearAlgebraVector(-1, 2, 0.1));
}

void PhysicObjectBallTest::tearDown() {
    delete m_ballMoving;
    m_ballMoving = 0;
    delete m_ballNotMoving;
    m_ballNotMoving = 0;
    delete m_logger;
    m_logger = 0;
}

void PhysicObjectBallTest::applyForce_notMovingAndNoForce_notMoved() {
    m_ballNotMoving->applyForce(LinearAlgebraVector(0, 0, 0), 0.5);

    auto position = m_ballNotMoving->getPosition();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 10, 3), position, 1e-6));
}

void PhysicObjectBallTest::applyForce_movingAndNoForce_movedDueToInitialVelocity() {
    m_ballMoving->applyForce(LinearAlgebraVector(0, 0, 0), 0.5);

    auto position = m_ballMoving->getPosition();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(4.5, 11, 3.05), position, 1e-6));
}

void PhysicObjectBallTest::applyForce_notMovingAndNoForce_velocityNotChanged() {
    m_ballNotMoving->applyForce(LinearAlgebraVector(0, 0, 0), 0.5);

    auto velocity = m_ballNotMoving->getVelocity();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 0, 0), velocity, 1e-6));
}

void PhysicObjectBallTest::applyForce_movingAndNoForce_velocityNotChanged() {
    m_ballMoving->applyForce(LinearAlgebraVector(0, 0, 0), 0.5);

    auto velocity = m_ballMoving->getVelocity();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(-1, 2, 0.1), velocity, 1e-6));
}

void PhysicObjectBallTest::applyForce_notMovingAndForceButNoTime_notMoved() {
    m_ballNotMoving->applyForce(LinearAlgebraVector(0, 20, 0), 0);

    auto position = m_ballNotMoving->getPosition();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 10, 3), position, 1e-6));
}

void PhysicObjectBallTest::applyForce_movingAndForceButNoTime_notMoved() {
    m_ballMoving->applyForce(LinearAlgebraVector(0, 20, 0), 0);

    auto position = m_ballMoving->getPosition();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 10, 3), position, 1e-6));
}

void PhysicObjectBallTest::applyForce_notMovingAndForceButNoTime_velocityNotChanged() {
    m_ballNotMoving->applyForce(LinearAlgebraVector(0, 20, 0), 0);

    auto velocity = m_ballNotMoving->getVelocity();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 0, 0), velocity, 1e-6));
}

void PhysicObjectBallTest::applyForce_movingAndForceButNoTime_velocityNotChanged() {
    m_ballMoving->applyForce(LinearAlgebraVector(0, 20, 0), 0);

    auto velocity = m_ballMoving->getVelocity();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(-1, 2, 0.1), velocity, 1e-6));
}

void PhysicObjectBallTest::applyForce_notMovingAndForce_moved() {
    m_ballNotMoving->applyForce(LinearAlgebraVector(0, 20, 0), 5);

    auto position = m_ballNotMoving->getPosition();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(5, 135, 3), position, 1e-6));
}

void PhysicObjectBallTest::applyForce_movingAndForce_moved() {

    m_ballMoving->applyForce(LinearAlgebraVector(0, 20, 0), 5);

    auto position = m_ballMoving->getPosition();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 145, 3.5), position, 1e-6));
}

void PhysicObjectBallTest::applyForce_notMovingAndForce_velocityChanged() {
    m_ballNotMoving->applyForce(LinearAlgebraVector(0, 20, 0), 5);

    auto velocity = m_ballNotMoving->getVelocity();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(0, 50, 0), velocity, 1e-6));
}

void PhysicObjectBallTest::applyForce_movingAndForce_velocityChanged() {
    m_ballMoving->applyForce(LinearAlgebraVector(0, 20, 0), 5);

    auto velocity = m_ballMoving->getVelocity();
    CPPUNIT_ASSERT(LinearAlgebraVector::equalsWithEpsilon(LinearAlgebraVector(-1, 52, 0.1), velocity, 1e-6));
}